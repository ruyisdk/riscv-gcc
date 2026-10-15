/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16 -fdump-rtl-ztt_md_reuse" { target rv64 } } */
/* { dg-options "-O2 -g -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16 -fdump-rtl-ztt_md_reuse" { target rv32 } } */

#include "../../../../gcc.target/riscv/ame/state/ztt-acc-move-md.h"

/* { dg-final { scan-rtl-dump-times {Reuse Md at insn [0-9]+: sources 3} 2 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.2d\t} 4 } } */
/* { dg-final { scan-assembler-times {\tagettyp\t} 5 } } */
