/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u32-m32-a16 -fdump-rtl-ztt_md_reuse" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
/* { dg-additional-options "-ffat-lto-objects" } */
#include "../../../../gcc.target/riscv/ame/state/ztt-zip-descriptors.h"
/* { dg-final { scan-rtl-dump "Reuse descriptors after workspace cleanup" "ztt_md_reuse" } } */
