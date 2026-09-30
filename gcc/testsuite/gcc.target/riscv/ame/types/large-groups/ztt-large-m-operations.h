/* Supplemental signatures for all eight domains, with observable results.  */
#include <stdint.h>
#include <riscv_ztt.h>
#include "../../fixtures/ztt-scalar-construct.h"
#define KEEP(X) __asm__ volatile ("" : : "Wmr" (X))
void integer_matrix (uint64_t *out, const uint64_t *in)
{
  __riscv_ztt_u64_rne_sat_1x1_t a = __riscv_ztt_mls_rm_u64_rne_sat_1x1 (in);
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  a = __riscv_ztt_madd_ew_u64_rne_sat_1x1 (a, b);
  a = __riscv_ztt_msll_ew_x_u64_rne_sat_1x1 (a, 3);
  __riscv_ztt_mss_rm (out, a);
}
void floating_matrix (double *out, const double *in)
{
  __riscv_ztt_f64_rne_1x1_t a = __riscv_ztt_mls_rm_f64_rne_1x1 (in);
  __riscv_ztt_f64_rne_1x1_t b = __riscv_ztt_madd_ew_f64_rne_1x1 (a, a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (out + 1, a);
}
void matrix_math (double *out, const double *in)
{
  __riscv_ztt_f64_rne_1x1_t a = __riscv_ztt_mls_rm_f64_rne_1x1 (in);
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  a = __riscv_ztt_mldexp_ew_f64_rne_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
}
void floating_unary (double *out, const double *in)
{
  __riscv_ztt_f64_rne_1x1_t a = __riscv_ztt_mls_rm_f64_rne_1x1 (in);
  __riscv_ztt_f64_rdn_1x1_t b = __riscv_ztt_mabs_ew_f64_rdn_1x1 (a);
  __riscv_ztt_mss_rm (out, b);
}
void integer_scalar (uint64_t *out, const uint64_t *in, __UINTPTR_TYPE__ x)
{
  __riscv_ztt_u64_rne_sat_1x1_t a = __riscv_ztt_mls_rm_u64_rne_sat_1x1 (in);
  a = __riscv_ztt_madd_ew_x_u64_rne_sat_1x1_u128_rnu (a, __riscv_ztt_scalar_from_bits_u128_rnu (x));
  __riscv_ztt_mss_rm (out, a);
}
#if __riscv_xlen == 64
typedef double floating_carrier;
#else
typedef __UINTPTR_TYPE__ floating_carrier;
#endif
void floating_scalar (double *out, const double *in, floating_carrier bits)
{
  __riscv_ztt_f64_rne_1x1_t a = __riscv_ztt_mls_rm_f64_rne_1x1 (in);
  a = __riscv_ztt_madd_ew_x_f64_rne_1x1_f64_rne (a, ZTT_TEST_F64(rne, bits));
  __riscv_ztt_mss_rm (out, a);
}
void integer_matmul (void)
{
  __riscv_ztt_i32_rne_accx1_t old = __riscv_ztt_mzero_acc_i32_rne_accx1 ();
  __riscv_ztt_i64_rdn_1x1_t a = __riscv_ztt_mzero_m_i64_rdn_1x1 ();
  __riscv_ztt_u128_rod_1x1_t b = __riscv_ztt_mzero_m_u128_rod_1x1 ();
  old = __riscv_ztt_mmulacc_2d_i32_rne_accx1 (old, a, b);
  __asm__ volatile ("" : : "War" (old));
}
void extended_integer_matmul (void)
{
  __riscv_ztt_i32_rne_sat_accx1_t old = __riscv_ztt_mzero_acc_i32_rne_sat_accx1 ();
  __riscv_ztt_i64_rdn_1x1_t a = __riscv_ztt_mzero_m_i64_rdn_1x1 ();
  __riscv_ztt_u128_rod_1x1_t b = __riscv_ztt_mzero_m_u128_rod_1x1 ();
  old = __riscv_ztt_mmulacc_2d_i32_rne_sat_accx1 (old, a, b);
  __asm__ volatile ("" : : "War" (old));
}
void floating_matmul (void)
{
  __riscv_ztt_f32_rne_accx1_t old = __riscv_ztt_mzero_acc_f32_rne_accx1 ();
  __riscv_ztt_f64_rdn_1x1_t a = __riscv_ztt_mzero_m_f64_rdn_1x1 ();
  __riscv_ztt_f64_rup_1x1_t b = __riscv_ztt_mzero_m_f64_rup_1x1 ();
  old = __riscv_ztt_mmulacc_2d_f32_rne_accx1 (old, a, b);
  __asm__ volatile ("" : : "War" (old));
}
