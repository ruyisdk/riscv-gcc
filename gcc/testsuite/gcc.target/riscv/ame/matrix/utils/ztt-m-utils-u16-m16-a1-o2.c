/* M utilities.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv64 } } */
#include "ztt-m-utils-body.h"
