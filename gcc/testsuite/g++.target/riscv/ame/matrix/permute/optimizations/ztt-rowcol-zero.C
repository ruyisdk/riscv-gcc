/* { dg-do compile } */
/* { dg-options "-g -fcompare-debug -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#include "../../../../../../gcc.target/riscv/ame/matrix/permute/ztt-rowcol-zero.h"
/* { dg-final { scan-assembler-times {m(row|col)bcast\.ew\.x\tm[0-9]+,zero,m[0-9]+} 15 { target rv32 } } } */
/* { dg-final { scan-assembler-times {m(row|col)bcast\.ew\.x\tm[0-9]+,zero,m[0-9]+} 15 { target { rv64 && { any-opts "-O0" } } } } } */
/* { dg-final { scan-assembler-times {m(row|col)bcast\.ew\.x\tm[0-9]+,zero,m[0-9]+} 18 { target { rv64 && { no-opts "-O0" } } } } } */
/* { dg-final { scan-assembler-times {m(row|col)shift\.ew\.x\tm[0-9]+,zero,m[0-9]+} 6 { target { any-opts "-O0" } } } } */
/* { dg-final { scan-assembler-not {m(row|col)shift\.ew\.x\tm[0-9]+,zero,m[0-9]+} { target { no-opts "-O0" } } } } */
/* { dg-final { scan-assembler-not {amestype|\t(call|tail)\t__riscv_ztt_} } } */
