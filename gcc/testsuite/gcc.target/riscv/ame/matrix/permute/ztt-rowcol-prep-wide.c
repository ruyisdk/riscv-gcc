/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u8-m32-a16 -fdump-rtl-ztt_md_reuse" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */

#define ZTT_ROWCOL_TYPE f64_rne
#define ZTT_ROWCOL_CTYPE double
#include "ztt-rowcol-prep.h"

/* { dg-final { scan-rtl-dump-times "Reuse Md for rowcol" 5 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {m(row|col)(bcast|shift)\.ew\.x} 5 } } */
/* { dg-final { scan-assembler-not {m(ss|ls)\.1r} } } */
