/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fdump-tree-optimized -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include "ztt-zero-broadcast-body.h"
/* { dg-final { scan-rtl-dump-times "Reuse integer broadcast clear at insn" 9 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {mbcast\.m\.x\t} 6 } } */
/* { dg-final { scan-assembler-times {msettyp\t} 15 } } */
/* { dg-final { scan-tree-dump-times { =\{v\} \*counter} 1 "optimized" } } */
/* { dg-final { scan-tree-dump-times {\*counter[^;]* =\{v\}} 1 "optimized" } } */
