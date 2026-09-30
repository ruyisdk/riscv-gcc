/* Nonpacked ACC tuples.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -fstack-clash-protection -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a2" { target rv32 } } */
/* { dg-options "-O0 -fstack-clash-protection -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a2" { target rv64 } } */
#include "ztt-acc-tuple-body.h"
