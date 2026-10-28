#include <riscv_ztt.h>
#define LS_OP(NAME,T,E) \
void ls_##NAME(const E *input, unsigned long bits, const __INT32_TYPE__ *index, E *out, __INT32_TYPE__ *saved) \
{ \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  __riscv_ztt_##T##_1x1_t a=__riscv_ztt_mls_rm_##T##_1x1(input); \
  a=__riscv_ztt_mrowbcast_ew_x_##T##_1x1(a,0); \
  a=__riscv_ztt_##NAME##_##T##_1x1(a,__riscv_ztt_scalar_from_bits_##T(bits)); \
  __riscv_ztt_mss_rm(out,__riscv_ztt_mrowgather_ew_##T##_1x1(a,i)); \
  __riscv_ztt_mss_rm(saved,i); \
}
LS_OP(madd_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(msub_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mmul_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mabsdiff_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mhdiff_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mmean_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mmulneg_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mmin_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mmax_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mand_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mandnot_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mor_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mornot_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mxor_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mcmpge_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mcmplt_ew_x,i32_rnu,__INT32_TYPE__)
LS_OP(mlog2sub_ew_x,f32_rne,float)
LS_OP(msublog2_ew_x,f32_rne,float)
#define LS_MIXED(NAME,A,D,E) \
void ls_##NAME(const E *input, unsigned long bits, const __INT32_TYPE__ *index, E *out, __INT32_TYPE__ *saved) \
{ \
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index); \
  __riscv_ztt_##A##_1x1_t a=__riscv_ztt_mls_rm_##A##_1x1(input); \
  a=__riscv_ztt_mrowbcast_ew_x_##A##_1x1(a,0); \
  __riscv_ztt_##D##_1x1_t v=__riscv_ztt_madd_ew_x_##D##_1x1(a,__riscv_ztt_scalar_from_bits_##D(bits)); \
  __riscv_ztt_mss_rm(out,__riscv_ztt_mrowgather_ew_##D##_1x1(v,i)); \
  __riscv_ztt_mss_rm(saved,i); \
}
LS_MIXED(mixed_sat,i32_rnu,i32_rnu_sat,__INT32_TYPE__)
LS_MIXED(mixed_rm,f32_rdn,f32_rne,float)
void ls_old(const __INT32_TYPE__ *input, const __INT32_TYPE__ *old, unsigned long bits,
            const __INT32_TYPE__ *index, __INT32_TYPE__ *out, __INT32_TYPE__ *saved)
{
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index);
  __riscv_ztt_i32_rnu_1x1_t a=__riscv_ztt_mls_rm_i32_rnu_1x1(input);
  __riscv_ztt_i32_rnu_1x1_t d=__riscv_ztt_mls_rm_i32_rnu_1x1(old);
  a=__riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1(a,0);
  d=__riscv_ztt_mmulacc_ew_x_i32_rnu_1x1(d,a,__riscv_ztt_scalar_from_bits_i32_rnu(bits));
  __riscv_ztt_mss_rm(out,__riscv_ztt_mrowgather_ew_i32_rnu_1x1(d,i));
  __riscv_ztt_mss_rm(saved,i);
}
void ls_load(const __INT32_TYPE__ *input, const volatile __UINT32_TYPE__ *bits,
            const __INT32_TYPE__ *index, __INT32_TYPE__ *out, __INT32_TYPE__ *saved)
{
  __riscv_ztt_i32_rnu_1x1_t i=__riscv_ztt_mls_rm_i32_rnu_1x1(index);
  __riscv_ztt_i32_rnu_1x1_t a=__riscv_ztt_mls_rm_i32_rnu_1x1(input);
  a=__riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1(a,0);
  a=__riscv_ztt_madd_ew_x_i32_rnu_1x1(a,__riscv_ztt_scalar_from_bits_i32_rnu(*bits));
  __riscv_ztt_mss_rm(out,__riscv_ztt_mrowgather_ew_i32_rnu_1x1(a,i));
  __riscv_ztt_mss_rm(saved,i);
}
