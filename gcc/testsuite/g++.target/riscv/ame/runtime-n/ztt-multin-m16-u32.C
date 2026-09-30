/* runtime-N boundary tests.  */
/* { dg-do compile } */
/* { dg-options "-O2 -g -fasynchronous-unwind-tables -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -g -fasynchronous-unwind-tables -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
#define TEST_WIDTH 32
#include "../../../../gcc.target/riscv/ame/runtime-n/ztt-multin-body.h"
/* { dg-final { scan-assembler {csrr\s+s11,amenlen} } } */
/* { dg-final { scan-assembler {srli\s+[a-z][0-9]+,s11,2} } } */
/* { dg-final { scan-assembler {addi\s+t0,s11,-1} } } */
/* { dg-final { scan-assembler {and\s+[a-z][0-9]+,[a-z][0-9]+,s11} } } */
/* { dg-final { scan-assembler {mul\s+s11,s11,s11} } } */
/* { dg-final { scan-assembler {mss\.1r} } } */
/* { dg-final { scan-assembler {mls\.1r} } } */
/* { dg-final { scan-assembler {\.cfi_def_cfa} } } */
