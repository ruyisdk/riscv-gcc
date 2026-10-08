/* { dg-do assemble } */
/* { dg-options "-march=rv32gc_ztt -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-march=rv64gc_ztt -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */

#include "ztt-builtins-formats.h"
