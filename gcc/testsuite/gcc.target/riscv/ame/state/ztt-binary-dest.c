/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-binary-dest.h"
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 14 } } */
/* { dg-final { scan-assembler-times {\tmsub\.ew\t} 7 } } */
/* { dg-final { scan-assembler-times {l=4\] +ztt_state_sub_prepared_zttmr1_[sd]i} 4 } } */
/* { dg-final { scan-assembler-times {\tm(min|max|and|andnot|or|ornot|xor)\.ew\t} 7 } } */
