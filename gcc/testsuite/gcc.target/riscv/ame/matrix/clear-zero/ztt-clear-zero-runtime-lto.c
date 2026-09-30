/* Experimental single-M clear/zero names from intrinsic draft v0.2.4.  */
/* { dg-do link } */
/* { dg-options "-O2 -flto=1 -nostdlib -Wl,-e,clear_zero_lto -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -flto=1 -nostdlib -Wl,-e,clear_zero_lto -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include "ztt-clear-zero-lto.h"
