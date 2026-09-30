/* { dg-do compile } */
/* { dg-options "-O0 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

void
ztt_typed_o0_spill (const signed char *input, signed char *output)
{
  __riscv_ztt_i8_rne_1x1_t lhs
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input);
  __riscv_ztt_i8_rne_1x1_t rhs
    = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t result
    = __riscv_ztt_madd_ew_i8_rne_1x1 (lhs, rhs);
  __riscv_ztt_mss_rm (output, result);
}

/* .1r is compiler-only spill/reload machinery, not a public typed API.  */
/* { dg-final { scan-assembler "mss\\.1r\tm\[0-9\]+," } } */
/* { dg-final { scan-assembler "mls\\.1r\tm\[0-9\]+," } } */
