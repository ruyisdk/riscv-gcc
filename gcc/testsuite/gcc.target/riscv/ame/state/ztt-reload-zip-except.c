/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fnon-call-exceptions -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "ztt-reload-zip.h"
/* { dg-final { scan-rtl-dump-not "Prepare Md before zip reload" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler-times {\tmcolzip\.ew\t} 8 } } */
/* { dg-final { scan-assembler-times {\tmrowzip\.ew\t} 8 } } */
/* { dg-final { scan-assembler-times {\tmcolunzip\.ew\t} 8 } } */
/* { dg-final { scan-assembler-times {\tmrowunzip\.ew\t} 8 } } */
