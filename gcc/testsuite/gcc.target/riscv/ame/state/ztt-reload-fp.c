/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fno-pic -mcmodel=medany -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32imafd_zicsr_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64imafd_zicsr_ztt0p6 -mabi=lp64d" { target rv64 } } */
#include "ztt-reload-fp.h"
/* { dg-final { scan-rtl-dump-times "Prepare Md before private reload" 8 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\.x\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmldexpacc\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tfdiv\.d\t} 32 } } */
