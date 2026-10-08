/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m16-a4" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-md-function-state-body.h"
/* { dg-final { scan-rtl-dump-times "Explicit Md state: 0" 5 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times "Explicit Md state: 1" 3 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {ztt_typed_madd_ew_zttmr1} 4 } } */
