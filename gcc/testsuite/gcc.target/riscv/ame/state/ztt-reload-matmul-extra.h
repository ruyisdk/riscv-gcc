#include <riscv_ztt.h>
typedef __INT32_TYPE__ mx_element;
#define MX_ARGS const mx_element *left, const mx_element *right, const mx_element *old, mx_element *out
#define MX_CASE(NAME,OP,LATE) \
__attribute__((noipa)) void mx_##NAME (MX_ARGS) \
{ \
  __riscv_ztt_i32_rne_1x1_t a; \
  __riscv_ztt_i32_rdn_1x1_t b; \
  if ((LATE) != 1) a = __riscv_ztt_mls_rm_i32_rne_1x1 (left); \
  if ((LATE) != 2) b = __riscv_ztt_mls_rm_i32_rdn_1x1 (right); \
  __riscv_ztt_i32_rnu_accx2_t d = __riscv_ztt_mcopy_m2a_i32_rnu_accx2 ( \
    __riscv_ztt_mls_rm_i32_rnu_1x2 (old)); \
  mr_callee (); \
  if ((LATE) == 1) a = __riscv_ztt_mls_rm_i32_rne_1x1 (left); \
  if ((LATE) == 2) b = __riscv_ztt_mls_rm_i32_rdn_1x1 (right); \
  d = __riscv_ztt_##OP##_i32_rnu_accx2 (d, a, b); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x2 (d)); \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void mr_callee (void);
MX_CASE(mul, mmulacc_2d, 0)
MX_CASE(neg, mmulaccneg_2d, 0)
MX_CASE(at, mmulatacc_2d, 0)
MX_CASE(atneg, mmulataccneg_2d, 0)
MX_CASE(bt, mmulbtacc_2d, 0)
MX_CASE(btneg, mmulbtaccneg_2d, 0)
MX_CASE(left, mmulacc_2d, 1)
MX_CASE(right, mmulacc_2d, 2)
#ifdef __cplusplus
}
#endif
