/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
void invalid (signed char *p)
{
  __riscv_ztt_i4_rnu_1x2_t nib = __riscv_ztt_mzero_m_i4_1x2 ();
  __riscv_ztt_i8_rnu_1x2_t old = __riscv_ztt_mzero_m_i8_1x2 ();
  __riscv_ztt_i8_rnu_sat_1x2_t sat = __riscv_ztt_mconv_ew_i8_sat_1x2 (nib);
  __riscv_ztt_mss_rm (p, nib); /* { dg-error "i4/u4 memory interfaces are not supported" } */
  __riscv_ztt_madd_ew_i8_1x2 (old, sat); /* Supported by integer matrix lowering.  */
  __riscv_ztt_mconv_ew_i8_sat_1x1 (nib); /* { dg-error "with the result shape" } */
  __riscv_ztt_i4_rnu_1x1_t fraction; /* { dg-error "unknown type name|not declared|does not name" } */
}
