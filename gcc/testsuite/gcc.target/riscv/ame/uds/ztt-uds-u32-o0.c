/* multi-UDS.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-uds-body.h"
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 168 } } */
/* { dg-final { scan-assembler "mss.1r" } } */
/* { dg-final { scan-assembler "mls.1r" } } */
