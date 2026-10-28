/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16 -fnon-call-exceptions" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-reload-binary.h"
/* { dg-final { scan-rtl-dump-not "Prepare Md before binary reload" "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {\tmadd\.ew\t} } } */
/* { dg-final { scan-assembler {\tmsub\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmin\.ew\t} } } */
/* { dg-final { scan-assembler {\tmmax\.ew\t} } } */
/* { dg-final { scan-assembler {\tmand\.ew\t} } } */
/* { dg-final { scan-assembler {\tmandnot\.ew\t} } } */
/* { dg-final { scan-assembler {\tmor\.ew\t} } } */
/* { dg-final { scan-assembler {\tmornot\.ew\t} } } */
/* { dg-final { scan-assembler {\tmxor\.ew\t} } } */
