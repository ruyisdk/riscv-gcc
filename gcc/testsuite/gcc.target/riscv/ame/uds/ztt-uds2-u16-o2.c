/* multi-UDS.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#include "ztt-uds2-body.h"
/* { dg-final { scan-assembler-times {\tmadd\.ew\t} 64 } } */
/* { dg-final { scan-assembler-times {\tmls\.rm\t} 64 } } */
/* { dg-final { scan-assembler-times {\tmss\.rm\t} 128 } } */
/* { dg-final { scan-assembler-not {\tm[ls]s\.1r\t} } } */
