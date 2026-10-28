/* { dg-do compile } */
/* { dg-options "-O2 -fno-strict-aliasing -march=rv64ima_zicsr_zknd_zkne_zksed_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fdump-rtl-ztt_md_reuse" { target rv64 } } */
/* { dg-options "-O2 -fno-strict-aliasing -march=rv32ima_zicsr_zknd_zkne_zksed_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fdump-rtl-ztt_md_reuse" { target rv32 } } */
#include "ztt-cipher-md.h"
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 3} 8 "ztt_md_reuse" { target rv32 } } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 3} 11 "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 2} 1 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {\taes32esi\t} { target rv32 } } } */
/* { dg-final { scan-assembler {\taes64ks2\t} { target rv64 } } } */
/* { dg-final { scan-assembler {\tsm4ed\t} } } */
/* { dg-final { scan-assembler {\tsm4ks\t} } } */
