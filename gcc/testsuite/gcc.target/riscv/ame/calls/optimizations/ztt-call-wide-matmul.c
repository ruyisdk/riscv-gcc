/* { dg-do compile } */
/* { dg-options "-g -std=gnu99 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-g -std=gnu99 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
#include "../ztt-call-wide-matmul.h"
/* { dg-final { scan-assembler-times {mmulaccneg\.2d\s+} 1 } } */
/* { dg-final { scan-assembler-times {mmulatacc\.2d\s+} 1 } } */
/* { dg-final { scan-assembler-times {mmulataccneg\.2d\s+} 1 } } */
/* { dg-final { scan-assembler-times {mmulbtacc\.2d\s+} 1 } } */
/* { dg-final { scan-assembler-times {mmulbtaccneg\.2d\s+} 1 } } */
/* { dg-final { check-function-bodies "**" "" } } */
/*
** wide_after_call:
** ...
** agettyp\s+.*
** ...
** mss\.1r\s+.*
** ...
** call\s+call_boundary
** ...
** mls\.1r\s+.*
** ...
** mmulacc\.2d\s+.*
** ...
** mss\.rm\s+.*
** ...
*/
