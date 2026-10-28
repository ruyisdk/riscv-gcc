#include <riscv_ztt.h>
#define LG_MIXED(NAME,P,D,PE,DE) \
void lg_##NAME (const PE *pred, const DE *data, const DE *old, \
               const __INT32_TYPE__ *index, DE *out, __INT32_TYPE__ *saved) \
{ \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  __riscv_ztt_##P##_1x1_t x=__riscv_ztt_mls_rm_##P##_1x1(pred); \
  __riscv_ztt_##D##_1x1_t y=__riscv_ztt_mls_rm_##D##_1x1(data); \
  __riscv_ztt_##D##_1x1_t z=__riscv_ztt_mls_rm_##D##_1x1(old); \
  x=__riscv_ztt_mrowbcast_ew_x_##P##_1x1(x,0); \
  y=__riscv_ztt_mrowbcast_ew_x_##D##_1x1(y,0); \
  z=__riscv_ztt_mrowbcast_ew_x_##D##_1x1(z,0); \
  z=__riscv_ztt_mcmovge_ew_##D##_1x1(z,x,y); \
  __riscv_ztt_mss_rm(out,__riscv_ztt_mrowgather_ew_##D##_1x1(z,i)); \
  __riscv_ztt_mss_rm(saved,i); \
}
LG_MIXED(wide_predicate,i64_rnu,i32_rnu,__INT64_TYPE__,__INT32_TYPE__)
LG_MIXED(mixed_rm,f32_rdn,f32_rne,float,float)
