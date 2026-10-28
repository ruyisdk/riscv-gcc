/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fnon-call-exceptions -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define CR_TYPE i32_rnu
#define CR_ELEMENT __INT32_TYPE__
#include "../../../../gcc.target/riscv/ame/state/ztt-copy-reload.h"
/* { dg-final { scan-rtl-dump-not "Prepare Md before copy reload" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {mmulacc\.ew\s} 6 } } */
