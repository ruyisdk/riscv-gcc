/* { dg-do compile } */
/* { dg-options "-O2 -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -ffat-lto-objects -fdump-rtl-ztt_md_reuse -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "ztt-reload-transfer.h"
/* { dg-final { scan-rtl-dump-times {Forward private reload from M} 4 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmmov\.m\.m\t} 4 } } */
/* { dg-final { scan-assembler-not {\tm[ls]s\.1r\t} } } */
/* { dg-final { scan-assembler-times {\tmconv\.ew\t} 1 } } */
