/* row/column controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
#include "ztt-rowcol-body.h"
/* { dg-final { scan-assembler-times {\tmcolbcast\.ew\.x\t} 25 } } */
/* { dg-final { scan-assembler-times {\tmrowbcast\.ew\.x\t} 25 } } */
/* { dg-final { scan-assembler-times {\tmcolshift\.ew\.x\t} 25 } } */
/* { dg-final { scan-assembler-times {\tmrowshift\.ew\.x\t} 25 } } */
