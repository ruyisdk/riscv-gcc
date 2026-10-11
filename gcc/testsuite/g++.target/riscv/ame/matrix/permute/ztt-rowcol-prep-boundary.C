/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u16-m32-a16 -fdump-rtl-ztt_md_reuse" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */

#include "../../../../../gcc.target/riscv/ame/matrix/permute/ztt-rowcol-prep-boundary.h"

/* { dg-final { scan-rtl-dump-not "Reuse Md for rowcol" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {m(row|col)(bcast|shift)\.ew\.x} 3 } } */
