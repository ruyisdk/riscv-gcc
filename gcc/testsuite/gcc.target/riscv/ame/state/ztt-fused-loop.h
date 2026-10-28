#include <riscv_ztt.h>
typedef __SIZE_TYPE__ usize;
typedef __riscv_ztt_f32_rne_1x1_t matrix;
#define load __riscv_ztt_mls_rm_f32_rne_1x1
#define madd __riscv_ztt_mmuladd_ew_f32_rne_1x1
#define macc __riscv_ztt_mmulacc_ew_f32_rne_1x1
#define madd_x __riscv_ztt_mmuladd_ew_x_f32_rne_1x1_f32_rne
#define scalar __riscv_ztt_scalar_from_bits_f32_rne
#define store __riscv_ztt_mss_rm

#ifdef __cplusplus
extern "C" {
#endif

void fused_affine (float *out, const float *in, const float *scale, const float *bias)
{
  store (out, madd (load (in), load (bias), load (scale)));
}

void fused_affine_tiles (float *out, const float *in, const float *scale,
			 const float *bias, usize tiles, usize step)
{
  matrix s = load (scale), b = load (bias);
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, madd (load (in), b, s));
      in += step; out += step;
    }
}

void fused_scalar_tiles (float *out, const float *in, const float *scale,
			 usize beta, usize tiles, usize step)
{
  matrix s = load (scale);
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, madd_x (load (in), s, scalar (beta)));
      in += step; out += step;
    }
}

void fused_accumulate (float *out, const float *in, const float *scale,
		       const float *initial, usize tiles, usize step)
{
  matrix s = load (scale), d = load (initial);
  for (usize i = 0; i < tiles; ++i)
    {
      d = macc (d, load (in), s);
      in += step;
    }
  store (out, d);
}

void fused_row_tiles (float *out, const float *in, const float *scale,
		      const float *bias, usize tiles, usize step)
{
  matrix s = load (scale);
  matrix b = __riscv_ztt_mrowbcast_ew_x_f32_rne_1x1 (load (bias), 0);
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, madd (load (in), b, s));
      in += step; out += step;
    }
}

extern void loop_callee (void);
#define CONTROL(NAME, BARRIER) \
void NAME (float *out, const float *in, const float *scale, const float *bias, \
	   usize tiles, usize step) \
{ \
  matrix s = load (scale), b = load (bias); \
  for (usize i = 0; i < tiles; ++i) \
    { \
      BARRIER; \
      store (out, madd (load (in), b, s)); \
      in += step; out += step; \
    } \
}
CONTROL (fused_call, loop_callee ())
CONTROL (fused_asm, asm volatile ("# Md boundary" ::: "memory"))

void fused_mixed (float *out, const float *in, const float *scale,
		  const float *bias, usize tiles, usize step)
{
  __riscv_ztt_f32_rtz_1x1_t s = __riscv_ztt_mls_rm_f32_rtz_1x1 (scale);
  matrix b = load (bias);
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, madd (load (in), b, s));
      in += step; out += step;
    }
}

void fused_scalar_call (float *out, const float *in, const float *scale,
			usize beta, usize tiles, usize step)
{
  matrix s = load (scale);
  for (usize i = 0; i < tiles; ++i)
    {
      loop_callee ();
      store (out, madd_x (load (in), s, scalar (beta)));
      in += step; out += step;
    }
}

#ifdef __cplusplus
}
#endif
