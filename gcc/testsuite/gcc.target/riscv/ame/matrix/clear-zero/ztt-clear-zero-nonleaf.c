/* Experimental single-M clear/zero names from intrinsic draft v0.2.4.  */
/* { dg-do compile } */
/* { dg-additional-options "-ffat-lto-objects" } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

extern void external_call (void);

void
clear_nonleaf (signed char *out)
{
  __riscv_ztt_i8_rne_1x1_t value = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  external_call ();
  __riscv_ztt_mss_rm (out, value);
}
/* { dg-final { scan-assembler {mss\.1r(.|\n)*call\s+external_call(.|\n)*mls\.1r} } } */
