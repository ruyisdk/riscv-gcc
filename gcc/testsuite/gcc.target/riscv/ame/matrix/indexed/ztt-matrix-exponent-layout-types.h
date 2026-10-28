#include <riscv_ztt.h>
#define MX_T_(T) __riscv_ztt_##T##_1x1_t
#define MX_T(T) MX_T_(T)
#define MX_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define MX_F(F,T) MX_F_(F,T)
#define MX_CASE(NAME,T,E,ET,EE,EXPR) \
void NAME (const E *input, const EE *exponents, const __INT32_TYPE__ *index, \
           E *out, __INT32_TYPE__ *saved) \
{ \
  MX_T(T) a = MX_F(mls_rm,T)(input); \
  MX_T(ET) e = MX_F(mls_rm,ET)(exponents); \
  __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  a = MX_F(mrowbcast_ew_x,T)(a,0); \
  e = MX_F(mrowbcast_ew_x,ET)(e,0); \
  a = EXPR; \
  a = MX_F(mrowgather_ew,T)(a,i); \
  __riscv_ztt_mss_rm(out,a); \
  __riscv_ztt_mss_rm(saved,i); \
}
MX_CASE(mixed_float,f32_rne,float,i32_rnu,__INT32_TYPE__,
        MX_F(mldexp_ew,f32_rne)(a,e))
MX_CASE(mixed_rm,i32_rnu,__INT32_TYPE__,i32_rne,__INT32_TYPE__,
        MX_F(mrdexp_ew,i32_rnu)(a,e))
MX_CASE(wide_exponent,i32_rnu,__INT32_TYPE__,i64_rnu,__INT64_TYPE__,
        MX_F(mldexp_ew,i32_rnu)(a,e))
MX_CASE(nested,i32_rnu,__INT32_TYPE__,i32_rnu,__INT32_TYPE__,
        MX_F(mldexp_ew,i32_rnu)(MX_F(mldexp_ew,i32_rnu)(a,e),e))
