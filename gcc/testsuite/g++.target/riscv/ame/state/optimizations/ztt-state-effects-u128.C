/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a16 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a16 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" { target rv64 } } */
#define LARGE_BANKS
#include "../../../../../gcc.target/riscv/ame/state/ztt-state-effects.h"
/* { dg-final { scan-rtl-dump-times {Ztt resource effect: insn [0-9]+, M32, ACC16} 2 "ztt_regions" } } */
/* { dg-final { scan-rtl-dump-times {UNSPECV_ZTT_ACQUIRE} 1 "ztt_regions" } } */
/* { dg-final { scan-rtl-dump-times {UNSPECV_ZTT_RELEASE} 1 "ztt_regions" } } */
/* { dg-final { scan-rtl-dump-times {UNSPECV_ZTT_OWNED} 1 "ztt_regions" } } */
/* { dg-final { scan-rtl-dump-not {Unproved Ztt access:} "ztt_verify_regions" } } */
