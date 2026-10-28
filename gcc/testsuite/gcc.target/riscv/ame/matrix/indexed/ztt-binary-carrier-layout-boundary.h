#include <riscv_ztt.h>
#define LC_MIXED(NAME,A,D,E) \
void lc_##NAME (const E *a, const E *b, const __INT32_TYPE__ *index, E *out, __INT32_TYPE__ *saved) \
{ \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  __riscv_ztt_##A##_1x1_t x=__riscv_ztt_mls_rm_##A##_1x1(a); \
  __riscv_ztt_##D##_1x1_t y=__riscv_ztt_mls_rm_##D##_1x1(b); \
  x=__riscv_ztt_mrowbcast_ew_x_##A##_1x1(x,0); \
  y=__riscv_ztt_mrowbcast_ew_x_##D##_1x1(y,0); \
  y=__riscv_ztt_madd_ew_##D##_1x1(x,y); \
  __riscv_ztt_mss_rm(out,__riscv_ztt_mrowgather_ew_##D##_1x1(y,i)); \
  __riscv_ztt_mss_rm(saved,i); \
}
LC_MIXED(mixed_sat,i32_rnu,i32_rnu_sat,__INT32_TYPE__)
LC_MIXED(mixed_rm,f32_rdn,f32_rne,float)
