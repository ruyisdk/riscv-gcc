/* { dg-do compile } */
/* { dg-options "-O2 -dp -fdump-rtl-ztt_state -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -dp -fdump-rtl-ztt_state -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/acc/state/ztt-acc-join-descriptor.h"
/* { dg-final { scan-rtl-dump-times "UNSPEC_ZTT_DESCRIPTOR" 2 "ztt_state" } } */
/* { dg-final { scan-assembler-not "ztt_descriptor_" } } */
