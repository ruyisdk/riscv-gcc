/* { dg-do compile } */
/* { dg-options "-O2 -fno-strict-aliasing -march=rv64ima_zicsr_zbkb_zbkx_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fdump-rtl-ztt_md_reuse" { target { rv64 } } } */
/* { dg-options "-O2 -fno-strict-aliasing -march=rv32ima_zicsr_zbkb_zbkx_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fdump-rtl-ztt_md_reuse" { target { rv32 } } } */
#include "ztt-bitperm-md.h"
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 3} 7 "ztt_md_reuse" { target rv32 } } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 3} 5 "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 2} 1 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {\tbrev8\t} } } */
/* { dg-final { scan-assembler {\txperm4\t} } } */
/* { dg-final { scan-assembler {\txperm8\t} } } */
/* { dg-final { scan-assembler {\tzip\t} { target rv32 } } } */
/* { dg-final { scan-assembler {\tunzip\t} { target rv32 } } } */
