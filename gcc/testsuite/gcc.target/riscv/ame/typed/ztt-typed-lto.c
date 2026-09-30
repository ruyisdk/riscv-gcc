/* { dg-do link { target rv64 } } */
/* { dg-options "-O2 -flto=1 -nostdlib -Wl,-e,main -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" } */

#include <riscv_ztt.h>

static signed char input[16384];
static signed char output[16384];

int
main (void)
{
  __riscv_ztt_i8_rne_1x1_t lhs
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input);
  __riscv_ztt_i8_rne_1x1_t rhs
    = __riscv_ztt_mzero_2d_m_i8_rne_1x1 ();
  lhs = __riscv_ztt_madd_ew_i8_rne_1x1 (lhs, rhs);
  __riscv_ztt_mss_rm (output, lhs);
  return 0;
}
