#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define REPEAT(TC) \
__attribute__((noinline, used, externally_visible)) \
void repeat_##TC (__INT32_TYPE__ *out, __UINTPTR_TYPE__ x, __UINTPTR_TYPE__ y) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mbcast_m_x_i32_1x1 \
    (__riscv_ztt_scalar_from_bits_##TC (x)); \
  __riscv_ztt_i32_1x1_t b = __riscv_ztt_mbcast_m_x_i32_1x1 \
    (__riscv_ztt_scalar_from_bits_##TC (y)); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_i32_1x1 (a, b)); \
}

REPEAT (i8_rnu)
REPEAT (i32_rne)
REPEAT (u32_rod_sat)
REPEAT (u128_rnu)
REPEAT (f32_rne)
REPEAT (bf16_rtz)
#undef REPEAT

#ifdef __cplusplus
}
#endif
