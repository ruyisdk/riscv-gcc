/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "ztt-integer-zero-body.h"
/* { dg-final { scan-rtl-dump-times "Reuse integer clear at insn" 8 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {mzero\.2d\.m\t} 2 } } */
/* { dg-final { scan-rtl-dump-times "Reuse integer ACC clear at insn" 1 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-not {mzero\.2d\.acc\t} } } */
/* { dg-final { scan-assembler-times {msettyp\t} 10 } } */
