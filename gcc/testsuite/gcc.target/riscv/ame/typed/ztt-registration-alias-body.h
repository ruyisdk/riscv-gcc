#include <riscv_ztt.h>
#include <riscv_ztt.h>

#ifndef __riscv_ztt_profile
#error missing profile capability
#endif
#ifdef __riscv_ztt_mzero_m_i32_1x1
#error typed aliases must be compiler declarations
#endif

#ifdef __cplusplus
#define SAME(A, B) static_assert (__is_same (decltype (A), decltype (B)), #A)
#else
#define SAME(A, B) _Static_assert (__builtin_types_compatible_p \
  (__typeof__ (A), __typeof__ (B)), #A)
#endif

SAME (__riscv_ztt_mclear_m_i32_1x1, __riscv_ztt_mclear_m_i32_rnu_1x1);
SAME (__riscv_ztt_mzero_m_i32_1x1, __riscv_ztt_mzero_m_i32_rnu_1x1);
SAME (__riscv_ztt_mls_rm_i32_1x1, __riscv_ztt_mls_rm_i32_rnu_1x1);
SAME (__riscv_ztt_madd_ew_i32_1x1, __riscv_ztt_madd_ew_i32_rnu_1x1);
SAME (__riscv_ztt_madd_ew_i32_sat_1x1, __riscv_ztt_madd_ew_i32_rnu_sat_1x1);
SAME (__riscv_ztt_madd_ew_x_i32_1x1_i32,
      __riscv_ztt_madd_ew_x_i32_rnu_1x1_i32_rnu);
SAME (__riscv_ztt_mzero_m_f32_1x1, __riscv_ztt_mzero_m_f32_rne_1x1);
SAME (__riscv_ztt_mmul_ew_f32_1x1, __riscv_ztt_mmul_ew_f32_rne_1x1);
SAME (__riscv_ztt_mclear_acc_i32_accx1, __riscv_ztt_mclear_acc_i32_rnu_accx1);
SAME (__riscv_ztt_mclear_acc_i32_accx8, __riscv_ztt_mclear_acc_i32_rnu_accx8);
SAME (__riscv_ztt_mclear_acc_i32_accx16, __riscv_ztt_mclear_acc_i32_rnu_accx16);
SAME (__riscv_ztt_mclear_acc_i8_accx8, __riscv_ztt_mclear_acc_i8_rnu_accx8);
SAME (__riscv_ztt_mclear_acc_i8_accx16, __riscv_ztt_mclear_acc_i8_rnu_accx16);
SAME (__riscv_ztt_mrowzip_ew_i32_1x2, __riscv_ztt_mrowzip_ew_i32_rnu_1x2);

void
alias_integer (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mls_rm_i32_1x1 (in);
  m = __riscv_ztt_madd_ew_x_i32_1x1_i32
    (m, __riscv_ztt_scalar_make_i32_rnu (3));
  __riscv_ztt_mss_rm (out, m);
}

void
alias_floating (float *out)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mzero_m_f32_1x1 ();
  __riscv_ztt_mss_rm (out, m);
}
