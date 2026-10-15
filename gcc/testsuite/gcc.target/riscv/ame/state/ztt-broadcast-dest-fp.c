/* { dg-do compile } */
/* { dg-options "-O2 -g -dp -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define BC_TYPE f32_rne
#define BC_ALT f32_rtz
#define BC_SCALAR f32_rne
#define BC_CARRIER float
#include "ztt-broadcast-dest.h"
/* { dg-final { scan-assembler-times {l=4\] +ztt_typed_broadcast_zttmr1_[sd]i} 2 } } */
/* { dg-final { scan-assembler-times {l=4\] +ztt_typed_msettyp_p0_zttmr1_[sd]i} 2 } } */
