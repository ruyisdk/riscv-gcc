/* { dg-do compile } */
/* { dg-options "-march=rv32gcp0p21 -mabi=ilp32 -Wno-riscv-implicit-extension-version" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-flto" } } */

#include <stdint-gcc.h>

// RV32 vector types
typedef int8_t int8x4_t __attribute__((vector_size(4)));
typedef uint8_t uint8x4_t __attribute__((vector_size(4)));

int8x4_t test_rev_2byte_pv4qi(int8x4_t a) {
    return __builtin_shufflevector(a, a, 2, 3, 0, 1);
}

uint8x4_t test_rev_2byte_pv4qi_unsigned(uint8x4_t a) {
    return __builtin_shufflevector(a, a, 2, 3, 0, 1);
}


// Consolidated scan-assembler-times for all instructions
/* { dg-final { scan-assembler-times "\\mrev16\\M" 2 } } */
