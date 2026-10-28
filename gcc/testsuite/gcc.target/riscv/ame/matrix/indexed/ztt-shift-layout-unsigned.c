/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define SL_TYPE u32_rnu
#define SL_ELEMENT __UINT32_TYPE__
#define SL_SRA msrl_ew
#include "ztt-shift-layout.h"
/* { dg-final { scan-assembler-times {m(?:row|col)gather\.ew\s} 8 } } */
/* { dg-final { scan-assembler-times {m(?:row|col)bcast\.ew\.x\s} 31 } } */
/* { dg-final { scan-assembler-times {msll\.ew\s} 13 } } */
/* { dg-final { scan-assembler-times {msrl\.ew\s} 2 } } */
/* { dg-final { scan-assembler-times {msra\.ew\s} 0 } } */
/* { dg-final { scan-assembler-times {mornot\.ew\s} 1 } } */
