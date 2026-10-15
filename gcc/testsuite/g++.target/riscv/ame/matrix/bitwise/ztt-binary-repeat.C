/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
#include "../../../../../gcc.target/riscv/ame/matrix/bitwise/ztt-binary-repeat.h"

/* { dg-final { scan-assembler-times {mmin\.ew\t} 18 } } */
/* { dg-final { scan-assembler-times {mmax\.ew\t} 3 } } */
/* { dg-final { scan-assembler-times {mand\.ew\t} 2 } } */
/* { dg-final { scan-assembler-times {mor\.ew\t} 3 } } */
/* { dg-final { scan-assembler-times {madd\.ew\t} 1 } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcopy_m2m_i32_rnu_1x1 \(} 17 "optimized" } } */
