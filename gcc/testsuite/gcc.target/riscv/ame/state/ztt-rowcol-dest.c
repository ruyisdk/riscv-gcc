/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-rowcol-dest.h"
/* { dg-final { scan-assembler-times {\tm(col|row)(bcast|shift)\.ew\.x\t} 15 } } */
/* { dg-final { scan-assembler-times {l=4\] +ztt_state_rowcol_prepared_zttmr1_[sd]i} 4 } } */
