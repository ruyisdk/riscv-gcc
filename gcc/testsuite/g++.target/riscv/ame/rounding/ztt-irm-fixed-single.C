/* single-M
   i8 integer rounding-mode subset.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -fdump-rtl-expand -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -fdump-rtl-expand -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include "../../../../gcc.target/riscv/ame/rounding/ztt-irm-single.h"

/* The four full descriptors survive expansion without new modes.  */
/* { dg-final { scan-rtl-dump "0x40000008" "expand" } } */
/* { dg-final { scan-rtl-dump "0x48000008" "expand" } } */
/* { dg-final { scan-rtl-dump "0x50000008" "expand" } } */
/* { dg-final { scan-rtl-dump "0x58000008" "expand" } } */
/* { dg-final { scan-assembler-not {\tm[a-z0-9.]+\t[^\n]*\mm(1[6-9]|2[0-9]|3[01])\M} } } */
