#include <riscv_ztt.h>

#define PLACEHOLDERS(D,C,TC) \
void placeholder_##D (const C *in, C *broadcast, C *sum, C *acc, \
		     __UINTPTR_TYPE__ bits) \
{ \
  __riscv_ztt_##TC##_scalar_t s = __riscv_ztt_scalar_from_bits_##TC (bits); \
  __riscv_ztt_##D##_1x1_t a = __riscv_ztt_mls_rm_##D##_1x1 (in); \
  __riscv_ztt_##D##_1x1_t b = __riscv_ztt_mbcast_m_x_##D##_1x1 (s); \
  __riscv_ztt_##D##_1x1_t c = __riscv_ztt_madd_ew_x_##D##_1x1 (a,s); \
  __riscv_ztt_##D##_1x1_t d = __riscv_ztt_mmulacc_ew_x_##D##_1x1 (a,c,s); \
  __riscv_ztt_mss_rm (broadcast,b); \
  __riscv_ztt_mss_rm (sum,c); \
  __riscv_ztt_mss_rm (acc,d); \
}

#ifdef __cplusplus
extern "C" {
#endif
PLACEHOLDERS (i32_rnu,__INT32_TYPE__,i8_rne)
PLACEHOLDERS (u32_rod_sat,__UINT32_TYPE__,u16_rod_sat)
PLACEHOLDERS (f32_rne,float,bf16_rtz)
#ifdef __cplusplus
}
#endif
