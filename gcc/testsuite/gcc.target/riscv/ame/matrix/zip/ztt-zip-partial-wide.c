/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-zip-partial.h"
/* { dg-final { scan-rtl-dump-times {Reuse Md for zip at insn [0-9]+: packets 1} 4 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for zip at insn [0-9]+: packets 2} 4 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {l=72\] +ztt_state_zip_value_zttmr8_[sd]i} 8 } } */
