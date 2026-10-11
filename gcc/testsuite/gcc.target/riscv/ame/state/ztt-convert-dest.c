/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-convert-dest.h"
/* { dg-final { scan-assembler-times {\tmconv\.ew\t} 11 } } */
/* { dg-final { scan-assembler-times {l=4\] +ztt_state_unary_prepared_convert_zttmr2_[sd]i} 1 } } */
