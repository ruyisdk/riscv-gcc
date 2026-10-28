/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define TC_TYPE i128_rnu
#define TC_CARRIER __riscv_ztt_i128_storage_t
#include "../../../../../gcc.target/riscv/ame/matrix/scalar-ternary/ztt-scalar-live-copy.h"
/* { dg-final { scan-assembler-times {\tmmov\.m\.m\t} 6 } } */
/* { dg-final { scan-assembler-times {\tmmulacc\.ew\.x\t} 9 } } */
/* { dg-final { scan-assembler-times {\tmmulaccneg\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmmuladd\.ew\.x\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmmulsub\.ew\.x\t} 1 } } */
