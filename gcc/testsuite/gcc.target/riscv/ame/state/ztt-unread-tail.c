/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define SG_TYPE u128_rnu_sat
#define SG_CARRIER __riscv_ztt_u128_storage_t
#include "../matrix/indexed/ztt-scatter-live-copy.h"
/* { dg-final { scan-rtl-dump-times "unread tail" 96 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times "Remove unused AME workspace" 3 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmcolscatadd\.ew\t} 6 } } */
/* { dg-final { scan-assembler-times {\tmrowscatadd\.ew\t} 3 } } */
