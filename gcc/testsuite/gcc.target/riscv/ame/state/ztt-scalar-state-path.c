/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -DSTATE_WIDE=1 -fdump-rtl-ztt_state -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -fno-ipa-icf -DSTATE_WIDE=1 -fdump-rtl-ztt_state -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-scalar-state-path.h"
/* { dg-final { scan-rtl-dump-times "Skip Ztt state lowering without typed operands" 4 "ztt_state" } } */
/* { dg-final { scan-assembler-times {madd\.ew\t} 2 } } */
