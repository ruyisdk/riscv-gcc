#include <riscv_ztt.h>
typedef __SIZE_TYPE__ usize;
typedef __riscv_ztt_f32_rne_1x1_t matrix;
#define load __riscv_ztt_mls_rm_f32_rne_1x1
#define add __riscv_ztt_madd_ew_f32_rne_1x1
#define scale __riscv_ztt_mmul_ew_x_f32_rne_1x1_f32_rne
#define bias_x __riscv_ztt_madd_ew_x_f32_rne_1x1_f32_rne
#define scalar __riscv_ztt_scalar_from_bits_f32_rne
#define row __riscv_ztt_mrowbcast_ew_x_f32_rne_1x1
#define store __riscv_ztt_mss_rm

#ifdef __cplusplus
extern "C" {
#endif

void row_bias_tiles (float *out, const float *in, const float *bias,
		     usize tiles, usize step)
{
  matrix b = row (load (bias), 0);
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, add (load (in), b));
      in += step; out += step;
    }
}

#define ROW_LOOP(NAME, BARRIER) \
void NAME (float *out, const float *in, const float *bias, \
	   usize tiles, usize step, usize index) \
{ \
  matrix b = load (bias); \
  for (usize i = 0; i < tiles; ++i) \
    { \
      BARRIER; \
      store (out, add (load (in), row (b, index))); \
      in += step; out += step; \
    } \
}
ROW_LOOP (row_bias_inner, (void)0)
ROW_LOOP (row_bias_asm, asm volatile ("# Md boundary" ::: "memory"))

extern void loop_callee (void);
#define SCALE_LOOP(NAME, BARRIER) \
void NAME (float *out, const float *in, const float *bias, \
	   usize alpha, usize tiles, usize step) \
{ \
  matrix b = load (bias); \
  for (usize i = 0; i < tiles; ++i) \
    { \
      BARRIER; \
      store (out, add (scale (load (in), scalar (alpha)), b)); \
      in += step; out += step; \
    } \
}
SCALE_LOOP (scalar_scale_bias, (void)0)
SCALE_LOOP (scalar_scale_call, loop_callee ())
SCALE_LOOP (scalar_scale_asm, asm volatile ("# Md boundary" ::: "memory"))

void scalar_scale_mixed (float *out, const float *in, const float *bias,
			 usize alpha, usize tiles, usize step)
{
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mls_rm_f32_rtz_1x1 (bias);
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, add (scale (load (in), scalar (alpha)), b));
      in += step; out += step;
    }
}

void scalar_affine (float *out, const float *in, usize alpha, usize beta,
		    usize tiles, usize step)
{
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, bias_x (scale (load (in), scalar (alpha)), scalar (beta)));
      in += step; out += step;
    }
}

void scalar_scale (float *out, const float *in, usize alpha,
		   usize tiles, usize step)
{
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, scale (load (in), scalar (alpha)));
      in += step; out += step;
    }
}

#ifdef __cplusplus
}
#endif
