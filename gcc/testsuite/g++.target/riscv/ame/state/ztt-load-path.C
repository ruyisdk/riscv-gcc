/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m16-a4" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-load-path.h"
#include "../../../../gcc.target/riscv/ame/state/ztt-load-path-once.h"
/* { dg-final { scan-rtl-dump "Reuse load Md across paths" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {mmulacc\.2d} } } */
