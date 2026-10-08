/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-std=gnu++17 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
/* Native code is needed for assembly scans in LTO torture runs.  */
/* { dg-additional-options "-ffat-lto-objects" } */
#include "../../../../../gcc.target/riscv/ame/matrix/copy/ztt-assignment.h"
/* { dg-final { scan-assembler {\tmls\.1r\t} } } */
/* { dg-final { scan-assembler {\tmss\.1r\t} } } */
/* { dg-final { scan-assembler-not {\t(call|tail)\t__riscv_ztt_} } } */
