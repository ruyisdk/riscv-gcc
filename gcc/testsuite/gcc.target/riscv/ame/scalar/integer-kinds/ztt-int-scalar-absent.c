/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
void absent (void)
{
  (void) &__riscv_ztt_madd_ew_x_i8_sat_1x1_i4; /* { dg-error "(undeclared|not declared)" } */
  (void) &__riscv_ztt_mand_ew_x_i8_sat_1x1_u4_sat; /* { dg-error "(undeclared|not declared)" } */
  (void) &__riscv_ztt_msub_ew_x_i4_sat_1x1_i8; /* { dg-error "(undeclared|not declared)" } */
  /* A complete i64 1x4 value exceeds this profile's M16 bank.  */
  (void) &__riscv_ztt_mmuladd_ew_x_i64_sat_1x4_i8; /* { dg-error "(undeclared|not declared)" } */
}
