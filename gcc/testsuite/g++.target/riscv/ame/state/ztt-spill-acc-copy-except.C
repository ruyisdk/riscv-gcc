/* { dg-do compile } */
/* { dg-options "-O2 -g -fnon-call-exceptions -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-spill-acc-copy.h"
/* { dg-final { scan-rtl-dump-not "Drop dead private spill" "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-not "Drop dead scalar private spill" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {\tmss\.1r\t} } } */
