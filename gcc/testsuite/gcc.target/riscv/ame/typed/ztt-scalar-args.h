#include <riscv_ztt.h>

static inline __UINTPTR_TYPE__
scalar_args_next (volatile __UINTPTR_TYPE__ *bits)
{
  __UINTPTR_TYPE__ value = *bits;
  *bits = value + 1;
  return value;
}

#define SCALAR_ARGS(D, C, TC) \
__attribute__((noinline, noclone)) \
void scalar_args_##D (const C *in, C *sum, C *acc, \
		     volatile __UINTPTR_TYPE__ *bits) \
{ \
  const __riscv_ztt_##TC##_scalar_t s \
    = __riscv_ztt_scalar_from_bits_##TC (scalar_args_next (bits)); \
  __riscv_ztt_##D##_1x1_t a = __riscv_ztt_mls_rm_##D##_1x1 (in); \
  __riscv_ztt_##D##_1x1_t b = __riscv_ztt_madd_ew_x_##D##_1x1 (a, s); \
  __riscv_ztt_##D##_1x1_t c = __riscv_ztt_mmulacc_ew_x_##D##_1x1 \
    (a, b, __riscv_ztt_scalar_from_bits_##TC (scalar_args_next (bits))); \
  __riscv_ztt_##D##_1x1_t d = __riscv_ztt_madd_ew_x_##D##_1x1_##TC (c, s); \
  __riscv_ztt_##D##_1x1_t e \
    = __riscv_ztt_mmulacc_ew_x_##D##_1x1_##TC (c, d, s); \
  __riscv_ztt_mss_rm (sum, b); \
  __riscv_ztt_mss_rm (acc, e); \
}

#ifdef __cplusplus
extern "C" {
#endif
SCALAR_ARGS (i32_rnu, __INT32_TYPE__, i8_rne)
SCALAR_ARGS (u32_rod_sat, __UINT32_TYPE__, u16_rod_sat)
SCALAR_ARGS (f32_rne, float, bf16_rtz)
#ifdef __cplusplus
}
#endif

#undef SCALAR_ARGS
