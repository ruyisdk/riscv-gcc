/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
#include "ztt-ternary-x-overlap-body.h"
/* { dg-final { scan-assembler-times {mldexpacc\.ew\.x\t} 4 } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for common preparation at insn [0-9]+: 3} 4 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump "Reuse Md for typed store" "ztt_md_reuse" } } */
