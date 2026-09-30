/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
int scalar_only (int x) { return x + 1; }
/* { dg-final { scan-assembler-not {amenlen|amestype|msettyp|s11} } } */
