/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p19 -mabi=lp64 -Wno-riscv-implicit-extension-version" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-flto" } } */

#include <stdint-gcc.h>

// RV64 vector types
typedef int8_t int8x8_t __attribute__((vector_size(8)));
typedef uint8_t uint8x8_t __attribute__((vector_size(8)));
typedef int16_t int16x4_t __attribute__((vector_size(8)));
typedef uint16_t uint16x4_t __attribute__((vector_size(8)));

int16x4_t test_rev_2byte_pv4hi(int16x4_t a) {
    return __builtin_shufflevector(a, a, 3, 2, 1, 0);
}

uint16x4_t test_rev_2byte_pv4hi_unsigned(uint16x4_t a) {
    return __builtin_shufflevector(a, a, 3, 2, 1, 0);
}

// Consolidated scan-assembler-times for all instructions
/* { dg-final { scan-assembler-times "\\mrev16\\M" 2 } } */
