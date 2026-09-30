/* row/column controls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++17 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++17 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/permute/ztt-rowcol-control-body.h"
/* { dg-final { scan-assembler-times {\tmcolbcast\.ew\.x\t} 1 { target rv32 } } } */
/* { dg-final { scan-assembler-times {\tmcolbcast\.ew\.x\t} 2 { target rv64 } } } */
/* { dg-final { scan-assembler-times {\tmrowbcast\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmcolshift\.ew\.x\t} 2 } } */
/* { dg-final { scan-assembler-times {\tmrowshift\.ew\.x\t} 2 } } */
/* { dg-final { scan-assembler-not {amestype|\t(call|tail)\t__riscv_ztt_} } } */
