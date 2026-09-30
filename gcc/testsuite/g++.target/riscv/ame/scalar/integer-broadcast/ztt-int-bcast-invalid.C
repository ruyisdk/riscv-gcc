/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (uint64_t wide, int *ptr)
{
  __riscv_ztt_mbcast_m_x_i4_sat_1x2_i128 ( __riscv_ztt_scalar_from_bits_i128_rnu (1.5)); /* { dg-error "Scalar constructor requires an integer carrier" } */
  __riscv_ztt_mbcast_m_x_u8_1x1_u128_sat ( __riscv_ztt_scalar_from_bits_u128_rnu_sat (ptr)); /* { dg-error "Scalar constructor requires an integer carrier" } */
#if __riscv_xlen == 32
  __riscv_ztt_mbcast_m_x_i4_sat_1x2_i64_sat ( __riscv_ztt_scalar_from_bits_i64_rnu_sat (wide)); /* { dg-error "XLEN-bit carrier" "" { target rv32 } } */
  __riscv_ztt_mbcast_m_x_i8_sat_1x1_u128 ( __riscv_ztt_scalar_from_bits_u128_rnu (UINT64_C(1))); /* { dg-error "XLEN-bit carrier" "" { target rv32 } } */
#else
  unsigned __int128 full = wide;
  __riscv_ztt_mbcast_m_x_i4_sat_1x2_i128_sat ( __riscv_ztt_scalar_from_bits_i128_rnu_sat (full)); /* { dg-error "XLEN-bit carrier" "" { target rv64 } } */
#endif
}
