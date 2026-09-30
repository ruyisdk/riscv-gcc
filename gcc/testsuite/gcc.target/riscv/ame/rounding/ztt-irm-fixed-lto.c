/* single-M
   i8 integer rounding-mode subset.  */
/* { dg-do link } */
/* { dg-options "-O2 -flto=1 -nostdlib -Wl,-e,mixed -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -flto=1 -nostdlib -Wl,-e,mixed -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include "ztt-irm-mixed.h"
