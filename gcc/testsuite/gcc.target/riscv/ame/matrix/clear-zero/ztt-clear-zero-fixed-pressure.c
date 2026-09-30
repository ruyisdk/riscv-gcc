/* Experimental single-M clear/zero names from intrinsic draft v0.2.4.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-expand -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fdump-rtl-expand -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include "ztt-clear-zero-pressure.h"

/* Seventeen independently defined values cannot fit in sixteen M registers.  */
/* { dg-final { scan-rtl-dump-times "UNSPECV_ZTT_SETTYP_P0" 17 "expand" } } */
/* { dg-final { scan-assembler "mss\\.1r" } } */
/* { dg-final { scan-assembler "mls\\.1r" } } */
/* { dg-final { scan-assembler-times "madd\\.ew" 16 } } */
/* { dg-final { scan-assembler-not {\tm[a-z0-9.]+\t[^\n]*\mm(1[6-9]|2[0-9]|3[01])\M} } } */
