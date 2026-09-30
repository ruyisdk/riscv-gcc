/* UDS32, i32/RNU only.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/base/ztt-acc-pressure.h"
/* { dg-final { scan-assembler "mss.1r" } } */
/* { dg-final { scan-assembler "mls.1r" } } */
/* { dg-final { scan-assembler "mmulacc.2d" } } */
