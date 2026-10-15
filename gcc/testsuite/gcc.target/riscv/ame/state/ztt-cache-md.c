/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -fno-strict-aliasing -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32ima_zicsr_zicbom_zicboz_zicbop_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64ima_zicsr_zicbom_zicboz_zicbop_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-cache-md.h"
/* { dg-final { scan-assembler-times {\tcbo\.clean\t} 3 } } */
/* { dg-final { scan-assembler-times {\tcbo\.flush\t} 1 } } */
/* { dg-final { scan-assembler-times {\tcbo\.inval\t} 1 } } */
/* { dg-final { scan-assembler-times {\tcbo\.zero\t} 1 } } */
/* { dg-final { scan-assembler-times {\tprefetch\.[rw]\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 9 } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 3} 7 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 2} 2 "ztt_md_reuse" } } */
