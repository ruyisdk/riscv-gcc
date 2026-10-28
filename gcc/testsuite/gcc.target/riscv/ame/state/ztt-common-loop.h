#include <riscv_ztt.h>
typedef __SIZE_TYPE__ usize;
typedef __riscv_ztt_f32_rne_1x1_t matrix;
#define load __riscv_ztt_mls_rm_f32_rne_1x1
#define add __riscv_ztt_madd_ew_f32_rne_1x1
#define mul __riscv_ztt_mmul_ew_f32_rne_1x1
#define store __riscv_ztt_mss_rm

#ifdef __cplusplus
extern "C" {
#endif

void bias (float *out, const float *in, const float *expanded_bias)
{
  store (out, add (load (in), load (expanded_bias)));
}

void row_bias (float *out, const float *in, const float *bias_tile)
{
  matrix b = __riscv_ztt_mrowbcast_ew_x_f32_rne_1x1 (load (bias_tile), 0);
  store (out, add (load (in), b));
}

void affine (float *out, const float *in, const float *scale, const float *bias)
{
  matrix x = load (in), s = load (scale), b = load (bias);
  store (out, add (mul (x, s), b));
}

void bias_tiles (float *out, const float *in, const float *bias,
		 usize tiles, usize step)
{
  matrix b = load (bias);
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, add (load (in), b));
      out += step;
      in += step;
    }
}

void affine_tiles (float *out, const float *in, const float *scale,
		   const float *bias, usize tiles, usize step)
{
  matrix b = load (bias), s = load (scale);
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, add (mul (load (in), s), b));
      out += step;
      in += step;
    }
}

extern void loop_callee (void);
#define CONTROL(NAME, BARRIER) \
void NAME (float *out, const float *in, const float *scale, const float *bias, \
	   usize tiles, usize step) \
{ \
  matrix b = load (bias), s = load (scale); \
  for (usize i = 0; i < tiles; ++i) \
    { \
      BARRIER; \
      store (out, add (mul (load (in), s), b)); \
      out += step; in += step; \
    } \
}
CONTROL (affine_call, loop_callee ())
CONTROL (affine_asm, asm volatile ("# Md boundary" ::: "memory"))
CONTROL (affine_branch, if (i & 1) asm volatile ("# conditional boundary" ::: "memory"))
CONTROL (affine_volatile, *(volatile float *)out = 0)

void bias_mixed (float *out, const float *in, const float *bias,
		 usize tiles, usize step)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mls_rm_f32_rtz_1x1 (bias);
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, add (load (in), b));
      out += step;
      in += step;
    }
}

#ifdef __cplusplus
}
#endif
