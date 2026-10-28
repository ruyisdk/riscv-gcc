/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv32ima_zicsr_zbkb_zbkx_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv64ima_zicsr_zbkb_zbkx_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-spill-bitperm.h"
/* { dg-final { scan-rtl-dump-times {Drop dead private spill} 40 "ztt_md_reuse" { target rv32 } } } */
/* { dg-final { scan-rtl-dump-times {Drop dead private spill} 24 "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-assembler-times {\tbrev8\t} 3 } } */
/* { dg-final { scan-assembler-times {\txperm4\t} 1 } } */
/* { dg-final { scan-assembler-times {\txperm8\t} 1 } } */
/* { dg-final { scan-assembler-times {\tzip\t} 1 { target rv32 } } } */
/* { dg-final { scan-assembler-times {\tunzip\t} 1 { target rv32 } } } */
/* { dg-final { scan-assembler-times {\tmrowscatadd\.ew\t} 7 { target rv32 } } } */
/* { dg-final { scan-assembler-times {\tmrowscatadd\.ew\t} 5 { target rv64 } } } */
