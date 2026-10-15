/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#define WC_TYPE f64_rne
#define WC_CARRIER double
#include "ztt-wide-exponent-copy.h"
/* { dg-final { scan-rtl-dump-times {ztt_state_scalar_shared_zttmr8} 4 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmldexpacc\.ew\.x\t} 6 } } */
