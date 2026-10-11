/* { dg-do compile } */
/* { dg-options "-O2 -fexceptions -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-rtl-ztt_regions -fdump-rtl-ztt_verify_regions" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
#define ZTT_SHIFT_CASE 5
#define ZTT_SHIFT_FLOAT 1
#include "../../../../../gcc.target/riscv/ame/matrix/permute/ztt-zero-shift-ownership.h"
/* { dg-final { scan-rtl-dump {Ztt owned edge:} "ztt_regions" } } */
/* { dg-final { scan-rtl-dump-not {Unproved Ztt access:} "ztt_verify_regions" } } */
/* { dg-final { scan-assembler-not {\tmrowshift\.ew\.x\t} } } */
