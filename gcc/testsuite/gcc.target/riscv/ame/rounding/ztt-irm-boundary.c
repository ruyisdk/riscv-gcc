/* single-M
   i8 integer rounding-mode subset.  */
/* { dg-do compile } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
extern void external_call (void);

void
nonleaf (signed char *out0, signed char *out1)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mclear_m_i8_rod_1x1 ();
  external_call ();
  __riscv_ztt_mss_rm (out0, a);
  __riscv_ztt_mss_rm (out1, b);
}
