/* { dg-do compile } */
/* { dg-require-effective-target rv32 } */
/* { dg-options "-march=rv32gcp0p21 -mabi=ilp32 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Oz" "-Og" "-flto" "-g" } } */

/* Test RV32 register-pair support for P-extension 8-byte vectors.

   On RV32, 8-byte packed vectors (PV8QI, PV4HI, PV2SI) use register pairs
   with the R constraint (even-odd register pairs). This test verifies that
   basic arithmetic operations generate the correct double-wide suffixes:
   - .DB for byte operations (PV8QI)
   - .DH for halfword operations (PV4HI)
   - .DW for word operations (PV2SI)
*/

#include <stdint-gcc.h>

typedef int8_t int8x8_t __attribute__((vector_size(8)));
typedef uint8_t uint8x8_t __attribute__((vector_size(8)));
typedef int16_t int16x4_t __attribute__((vector_size(8)));
typedef uint16_t uint16x4_t __attribute__((vector_size(8)));
typedef int32_t int32x2_t __attribute__((vector_size(8)));
typedef uint32_t uint32x2_t __attribute__((vector_size(8)));

// Test PV8QI (8-byte byte vector) - should use .DB suffix
int8x8_t test_padd_db(int8x8_t a, int8x8_t b) {
    return a + b;
}

int8x8_t test_psub_db(int8x8_t a, int8x8_t b) {
    return a - b;
}

uint8x8_t test_padd_db_unsigned(uint8x8_t a, uint8x8_t b) {
    return a + b;
}

// Test PV4HI (8-byte halfword vector) - should use .DH suffix
int16x4_t test_padd_dh(int16x4_t a, int16x4_t b) {
    return a + b;
}

int16x4_t test_psub_dh(int16x4_t a, int16x4_t b) {
    return a - b;
}

uint16x4_t test_padd_dh_unsigned(uint16x4_t a, uint16x4_t b) {
    return a + b;
}

// Test PV2SI (8-byte word vector) - should use .DW suffix
int32x2_t test_padd_dw(int32x2_t a, int32x2_t b) {
    return a + b;
}

int32x2_t test_psub_dw(int32x2_t a, int32x2_t b) {
    return a - b;
}

uint32x2_t test_padd_dw_unsigned(uint32x2_t a, uint32x2_t b) {
    return a + b;
}

// Test PMV.DxS (register-pair to register-pair move).
// Two int32 args push the vector argument to a2/a3 (even pair); the
// return value lands in a0/a1 (even pair), forcing a pmv.d?s copy.
int8x8_t test_pmv_dbs(int32_t a, int32_t b, int8x8_t vec) {
    return vec;
}

int16x4_t test_pmv_dhs(int32_t a, int32_t b, int16x4_t vec) {
    return vec;
}

int32x2_t test_pmv_dws(int32_t a, int32_t b, int32x2_t vec) {
    return vec;
}

// Test that register pairs are used correctly in function calls
int8x8_t test_register_pair_argument(int8x8_t vec) {
    // Identity function - verifies ABI handling of register pairs
    return vec;
}

int16x4_t test_register_pair_return(int16_t a, int16_t b, int16_t c, int16_t d) {
    // Return 8-byte vector via register pair
    return (int16x4_t){a, b, c, d};
}

/* Check for .DB suffix on byte operations */
/* { dg-final { scan-assembler-times "\\mpadd\\.db\\M" 2 } } */
/* { dg-final { scan-assembler-times "\\mpsub\\.db\\M" 1 } } */

/* Check for .DH suffix on halfword operations */
/* { dg-final { scan-assembler-times "\\mpadd\\.dh\\M" 2 } } */
/* { dg-final { scan-assembler-times "\\mpsub\\.dh\\M" 1 } } */

/* Check for .DW suffix on word operations */
/* { dg-final { scan-assembler-times "\\mpadd\\.dw\\M" 2 } } */
/* { dg-final { scan-assembler-times "\\mpsub\\.dw\\M" 1 } } */

/* Check for PMV.DBS, PMV.DHS and PMV.DWS instructions */
/* { dg-final { scan-assembler "\\mpmv\\.dbs\\M" } } */
/* { dg-final { scan-assembler "\\mpmv\\.dhs\\M" } } */
/* { dg-final { scan-assembler "\\mpmv\\.dws\\M" } } */
