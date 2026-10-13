/* { dg-do compile } */
/* { dg-options "-O0 -ffat-lto-objects -fno-ipa-icf -mztt-profile=gcc-runtime-u8-m16-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#define WC_TYPE u128_rnu
#define WC_CARRIER __riscv_ztt_u128_storage_t
#define WC_TC u128_rnu
#define WC_BITS
#include "ztt-scalar-input.h"
/* { dg-final { scan-assembler-times {mmulacc\.ew\.x} 4 } } */
/* { dg-final { scan-assembler-times {mmulaccneg\.ew\.x} 1 } } */
/* { dg-final { scan-assembler-times {mmuladd\.ew\.x} 1 } } */
/* { dg-final { scan-assembler-times {mmulsub\.ew\.x} 1 } } */
