/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_state -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define MT_TYPE i32_rnu
#define MT_CARRIER __INT32_TYPE__
#include "../../../../../gcc.target/riscv/ame/matrix/ternary/ztt-ternary-shared.h"
/* { dg-final { scan-rtl-dump-not {UNSPECV_ZTT_STATE_TERNARY_REUSE_LEFT} "ztt_state" } } */
