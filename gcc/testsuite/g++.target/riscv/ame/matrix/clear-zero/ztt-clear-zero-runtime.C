/* Experimental single-M clear/zero names from intrinsic draft v0.2.4.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -fdump-rtl-expand -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -fdump-rtl-expand -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#define ZTT_TEST_RUNTIME 1
#include "../../../../../gcc.target/riscv/ame/matrix/clear-zero/ztt-clear-zero-body.h"

/* Expand precedes prologue insertion: these are the eight intrinsic calls,
   not entry-only datatype setup.  */
/* { dg-final { scan-rtl-dump-times "UNSPECV_ZTT_SETTYP_P0" 8 "expand" } } */
/* { dg-final { scan-assembler-times "mzero\\.2d\\.m" 2 } } */
/* { dg-final { scan-assembler-not {\tm[a-z0-9.]+\t[^\n]*\mm(1[6-9]|2[0-9]|3[01])\M} } } */
/* { dg-final { scan-assembler-not {\tm[a-z0-9.]+\t[^\n]*\macc[0-9]+\M} } } */
