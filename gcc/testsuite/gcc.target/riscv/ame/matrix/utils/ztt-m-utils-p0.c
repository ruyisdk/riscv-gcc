/* M utilities.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#if defined(__riscv_ztt_mconcat_m) || defined(__riscv_ztt_mextract)
#error "runtime utility capability must not appear in fixed P0"
#endif
void unavailable (void)
{
  (void) &__riscv_ztt_mconcat_m_i8_rnu_1x2; /* { dg-error "(undeclared|not declared)" } */
  (void) &__riscv_ztt_mextract_i8_rnu_1x1; /* { dg-error "(undeclared|not declared)" } */
}
