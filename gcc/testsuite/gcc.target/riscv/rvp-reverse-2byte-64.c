/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p21 -mabi=lp64 -Wno-riscv-implicit-extension-version" } */
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

int8x8_t test_rev_2byte_pv8qi(int8x8_t a) {
    return __builtin_shufflevector(a, a, 6, 7, 4, 5, 2, 3, 0, 1);
}

uint8x8_t test_rev_2byte_pv8qi_unsigned(uint8x8_t a) {
    return __builtin_shufflevector(a, a, 6, 7, 4, 5, 2, 3, 0, 1);
}

/* Test case for RV32 pattern */
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
/* { dg-final { scan-assembler-times "\\mrev16\\M" 6 } } */
