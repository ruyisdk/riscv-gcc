#include <riscv_ztt.h>
typedef __SIZE_TYPE__ usize;
typedef __riscv_ztt_f32_rne_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_f32_rne_1x1
#define STORE __riscv_ztt_mss_rm

#ifdef __cplusplus
extern "C" {
#endif

void old_self_matrix (float *out, const float *in, const float *other,
		      const float *initial, usize count, usize step)
{
  matrix d = LOAD (initial), b = LOAD (other);
  for (usize i = 0; i < count; ++i)
    {
      d = __riscv_ztt_mmulacc_ew_f32_rne_1x1 (d, LOAD (in), b);
      in += step;
    }
  STORE (out, d);
}

void old_self_scalar (float *out, const float *in, const float *initial,
		      usize bits, usize count, usize step)
{
  matrix d = LOAD (initial);
  for (usize i = 0; i < count; ++i)
    {
      d = __riscv_ztt_mmuladd_ew_x_f32_rne_1x1_f32_rne
	(d, LOAD (in), __riscv_ztt_scalar_from_bits_f32_rne (bits));
      in += step;
    }
  STORE (out, d);
}

void old_self_scatter (__UINT32_TYPE__ *out, const __UINT32_TYPE__ *in,
		       const __UINT32_TYPE__ *initial,
		       const __UINT32_TYPE__ *index, usize count, usize step)
{
  __riscv_ztt_u32_1x1_t d = __riscv_ztt_mls_rm_u32_1x1 (initial);
  __riscv_ztt_u32_1x1_t ix = __riscv_ztt_mls_rm_u32_1x1 (index);
  for (usize i = 0; i < count; ++i)
    {
      d = __riscv_ztt_mcolscatadd_ew_u32_1x1
	(d, __riscv_ztt_mls_rm_u32_1x1 (in), ix);
      in += step;
    }
  STORE (out, d);
}

#ifdef __cplusplus
}
#endif
