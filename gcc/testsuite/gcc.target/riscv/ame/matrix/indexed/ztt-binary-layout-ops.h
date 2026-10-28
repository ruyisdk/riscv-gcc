#include <riscv_ztt.h>
#define BL_OP(F) \
void bl_##F (const __INT32_TYPE__ *a, const __INT32_TYPE__ *b, \
            const __INT32_TYPE__ *idx, __INT32_TYPE__ *out, __INT32_TYPE__ *saved) \
{ \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(idx); \
  __riscv_ztt_i32_rnu_1x1_t x=__riscv_ztt_mls_rm_i32_rnu_1x1(a); \
  __riscv_ztt_i32_rnu_1x1_t y=__riscv_ztt_mls_rm_i32_rnu_1x1(b); \
  x=__riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1(x,0); \
  y=__riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1(y,0); \
  x=__riscv_ztt_##F##_i32_rnu_1x1(x,y); \
  __riscv_ztt_mss_rm(out,__riscv_ztt_mrowgather_ew_i32_rnu_1x1(x,i)); \
  __riscv_ztt_mss_rm(saved,i); \
}
BL_OP(mmax_ew)
BL_OP(mand_ew)
BL_OP(mor_ew)
BL_OP(mandnot_ew)
BL_OP(mmulneg_ew)
#define BL_TYPED(NAME,T,E) \
void bl_##NAME (const E *a, const E *b, const __INT32_TYPE__ *idx, E *out, __INT32_TYPE__ *saved) \
{ \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(idx); \
  __riscv_ztt_##T##_1x1_t x=__riscv_ztt_mls_rm_##T##_1x1(a); \
  __riscv_ztt_##T##_1x1_t y=__riscv_ztt_mls_rm_##T##_1x1(b); \
  x=__riscv_ztt_mrowbcast_ew_x_##T##_1x1(x,0); \
  y=__riscv_ztt_mrowbcast_ew_x_##T##_1x1(y,0); \
  x=__riscv_ztt_madd_ew_##T##_1x1(x,y); \
  __riscv_ztt_mss_rm(out,__riscv_ztt_mrowgather_ew_##T##_1x1(x,i)); \
  __riscv_ztt_mss_rm(saved,i); \
}
BL_TYPED(saturating,i32_rnu_sat,__INT32_TYPE__)
BL_TYPED(floating,f32_rne,float)
