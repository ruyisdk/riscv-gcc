/* { dg-do compile } */
/* { dg-options "-g -std=gnu99 -march=rv32gcv_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-g -std=gnu99 -march=rv64gcv_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "../ztt-call-vector-frame.h"
/* { dg-final { check-function-bodies "**" "" } } */
/*
** vector_frame_call:
** ...
** agettyp\s+.*
** ...
** mss\.1r\s+.*
** ...
** call\s+use_buffer
** ...
** mls\.1r\s+.*
** ...
** asettyp\s+.*
** ...
*/
/* { dg-final { scan-assembler {csrr\s+s11,amenlen} } } */
/* { dg-final { scan-assembler {vs1r\.v\s+v1,} } } */
/* { dg-final { scan-assembler {\.cfi_restore 97} } } */
/* { dg-final { scan-assembler {\.cfi_offset 1,} } } */
/* { dg-final { scan-assembler "\\.cfi_restore 8\n\[ \t\]*\\.cfi_def_cfa 2, \[0-9\]+" } } */
