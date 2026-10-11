/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_state -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_state -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-call-lowering.h"
/* { dg-final { scan-rtl-dump-times "Ztt call clobbers at insn" 5 "ztt_state" } } */
/* { dg-final { scan-rtl-dump-times "Skip Ztt state lowering without typed operands" 1 "ztt_state" } } */
/* { dg-final { scan-assembler {mss\.1r\s} } } */
/* { dg-final { scan-assembler {agettyp\s} } } */
