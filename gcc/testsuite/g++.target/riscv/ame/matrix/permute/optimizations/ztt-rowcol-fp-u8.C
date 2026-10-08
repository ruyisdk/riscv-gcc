/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-std=gnu++17 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include "../../../../../../gcc.target/riscv/ame/matrix/permute/ztt-rowcol-fp.h"
/* { dg-final { scan-assembler-times {\tmcolbcast\.ew\.x\t} 28 } } */
/* { dg-final { scan-assembler-times {\tmrowbcast\.ew\.x\t} 28 } } */
/* { dg-final { scan-assembler-times {\tmcolshift\.ew\.x\t} 28 } } */
/* { dg-final { scan-assembler-times {\tmrowshift\.ew\.x\t} 28 } } */
/* { dg-final { scan-assembler-not {amestype|\t(call|tail)\t__riscv_ztt_} } } */
