/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (uint64_t wide)
{
  __riscv_ztt_i64_rnu_1x1_t b = __riscv_ztt_mzero_m_i64_rnu_1x1 ();
  __riscv_ztt_u64_rnu_1x1_t u = __riscv_ztt_mzero_m_u64_rnu_1x1 ();
  __riscv_ztt_i64_rne_1x1_t rm = __riscv_ztt_mzero_m_i64_rne_1x1 ();
  __riscv_ztt_i64_rnu_1x2_t shape = __riscv_ztt_mzero_m_i64_rnu_1x2 ();
  __riscv_ztt_madd_ew_x_i64_1x1_i128 (b, __riscv_ztt_scalar_from_bits_i128_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  __riscv_ztt_mbcast_m_x_i64_1x1_u128 ( __riscv_ztt_scalar_from_bits_u128_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  __riscv_ztt_madd_ew_x_i64_1x1_i128 (shape, __riscv_ztt_scalar_from_bits_i128_rnu (1)); /* { dg-error "compatible types, shapes" } */
  __riscv_ztt_mmin_ew_x_i64_1x1_i128 (u, __riscv_ztt_scalar_from_bits_i128_rnu (1)); /* { dg-error "exact result datatype" } */
  __riscv_ztt_mand_ew_x_i64_1x1_i128 (rm, __riscv_ztt_scalar_from_bits_i128_rnu (1)); /* { dg-error "exact result datatype" } */
  __riscv_ztt_mmulacc_ew_x_i64_1x1_i128 (rm, b, __riscv_ztt_scalar_from_bits_i128_rnu (1)); /* { dg-error "requires old_d" } */
#if __riscv_xlen == 32
  __riscv_ztt_madd_ew_x_i64_1x1_i128 (b, __riscv_ztt_scalar_from_bits_i128_rnu (wide)); /* { dg-error "XLEN-bit carrier" "" { target rv32 } } */
  __riscv_ztt_mbcast_m_x_i64_1x1_u128 ( __riscv_ztt_scalar_from_bits_u128_rnu (wide)); /* { dg-error "XLEN-bit carrier" "" { target rv32 } } */
  __riscv_ztt_madd_ew_x_i64_1x1_u64 (b, __riscv_ztt_scalar_from_bits_u64_rnu (UINT64_C(1))); /* { dg-error "XLEN-bit carrier" "" { target rv32 } } */
#else
  unsigned __int128 full = wide;
  __riscv_ztt_madd_ew_x_i64_1x1_i128 (b, __riscv_ztt_scalar_from_bits_i128_rnu (full)); /* { dg-error "XLEN-bit carrier" "" { target rv64 } } */
  __riscv_ztt_mbcast_m_x_i64_1x1_u128 ( __riscv_ztt_scalar_from_bits_u128_rnu (full)); /* { dg-error "XLEN-bit carrier" "" { target rv64 } } */
#endif
}
