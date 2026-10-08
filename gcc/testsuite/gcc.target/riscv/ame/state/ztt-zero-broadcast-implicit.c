/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "ztt-zero-broadcast-implicit.h"
/* { dg-final { scan-rtl-dump-times "Reuse integer broadcast clear at insn" 1 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump "Explicit Md state: 0" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-not {mbcast\.m\.x\t} } } */
/* { dg-final { scan-assembler-times {msettyp\t} 2 } } */
