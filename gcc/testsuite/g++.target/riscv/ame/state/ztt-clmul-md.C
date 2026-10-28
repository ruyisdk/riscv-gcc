/* { dg-do compile } */
/* { dg-options "-O2 -fno-strict-aliasing -march=rv64ima_zicsr_zbc_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fdump-rtl-ztt_md_reuse" { target { rv64 } } } */
/* { dg-options "-O2 -fno-strict-aliasing -march=rv32ima_zicsr_zbc_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fdump-rtl-ztt_md_reuse" { target { rv32 } } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-clmul-md.h"
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 3} 7 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 2} 1 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler "clmulh" } } */
/* { dg-final { scan-assembler "clmulr" } } */
