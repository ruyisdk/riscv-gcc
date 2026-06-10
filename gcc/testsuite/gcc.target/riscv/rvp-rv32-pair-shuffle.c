/* { dg-do compile } */
/* { dg-require-effective-target rv32 } */
/* { dg-options "-march=rv32gcp0p21 -mabi=ilp32 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Oz" "-Og" "-flto" "-g" } } */

/* Test RV32 register-pair shuffle patterns for P-extension.

   On RV32, 8-byte vector shuffles use double-wide suffixes (.DB/.DH) instead
   of the single-register suffixes (.B/.H) used on RV64. This distinction is
   necessary because RV32 uses register pairs for 8-byte vectors.

   This test verifies __builtin_shufflevector generates correct instructions:
   - PV8QI: ppaire.db, ppaireo.db, ppairoe.db, ppairo.db
   - PV4HI: ppaire.dh, ppaireo.dh, ppairoe.dh, ppairo.dh
*/

#include <stdint-gcc.h>

typedef int8_t int8x8_t __attribute__((vector_size(8)));
typedef uint8_t uint8x8_t __attribute__((vector_size(8)));
typedef int16_t int16x4_t __attribute__((vector_size(8)));
typedef uint16_t uint16x4_t __attribute__((vector_size(8)));

// --- PV4HI (4-element halfword vector) tests ---

// PPAIRE.DH: pair even halfwords {a[0], b[0], a[2], b[2]}
int16x4_t test_ppaire_dh(int16x4_t a, int16x4_t b) {
    return __builtin_shufflevector(a, b, 0, 4, 2, 6);
}

uint16x4_t test_ppaire_dh_unsigned(uint16x4_t a, uint16x4_t b) {
    return __builtin_shufflevector(a, b, 0, 4, 2, 6);
}

// PPAIREO.DH: even from a, odd from b {a[0], b[1], a[2], b[3]}
int16x4_t test_ppaireo_dh(int16x4_t a, int16x4_t b) {
    return __builtin_shufflevector(a, b, 0, 5, 2, 7);
}

// PPAIROE.DH: odd from a, even from b {a[1], b[0], a[3], b[2]}
int16x4_t test_ppairoe_dh(int16x4_t a, int16x4_t b) {
    return __builtin_shufflevector(a, b, 1, 4, 3, 6);
}

// PPAIRO.DH: pair odd halfwords {a[1], b[1], a[3], b[3]}
int16x4_t test_ppairo_dh(int16x4_t a, int16x4_t b) {
    return __builtin_shufflevector(a, b, 1, 5, 3, 7);
}

// --- PV8QI (8-element byte vector) tests ---

// PPAIRE.DB: pair even bytes {a[0], b[0], a[2], b[2], a[4], b[4], a[6], b[6]}
int8x8_t test_ppaire_db(int8x8_t a, int8x8_t b) {
    return __builtin_shufflevector(a, b, 0, 8, 2, 10, 4, 12, 6, 14);
}

uint8x8_t test_ppaire_db_unsigned(uint8x8_t a, uint8x8_t b) {
    return __builtin_shufflevector(a, b, 0, 8, 2, 10, 4, 12, 6, 14);
}

// PPAIREO.DB: even from a, odd from b
int8x8_t test_ppaireo_db(int8x8_t a, int8x8_t b) {
    return __builtin_shufflevector(a, b, 0, 9, 2, 11, 4, 13, 6, 15);
}

// PPAIROE.DB: odd from a, even from b
int8x8_t test_ppairoe_db(int8x8_t a, int8x8_t b) {
    return __builtin_shufflevector(a, b, 1, 8, 3, 10, 5, 12, 7, 14);
}

// PPAIRO.DB: pair odd bytes {a[1], b[1], a[3], b[3], a[5], b[5], a[7], b[7]}
int8x8_t test_ppairo_db(int8x8_t a, int8x8_t b) {
    return __builtin_shufflevector(a, b, 1, 9, 3, 11, 5, 13, 7, 15);
}

// --- Additional test cases ---

// Test with complex expressions
int8x8_t test_ppaireo_db_expr(int8x8_t a, int8x8_t b, int8x8_t c) {
    int8x8_t sum = a + c;
    return __builtin_shufflevector(sum, b, 0, 9, 2, 11, 4, 13, 6, 15);
}

/* Check for .DH suffix on PV4HI shuffle operations (4 patterns × 1-2 occurrences each) */
/* { dg-final { scan-assembler-times "\\mppaire\\.dh\\M" 2 } } */
/* { dg-final { scan-assembler-times "\\mppaireo\\.dh\\M" 1 } } */
/* { dg-final { scan-assembler-times "\\mppairoe\\.dh\\M" 1 } } */
/* { dg-final { scan-assembler-times "\\mppairo\\.dh\\M" 1 } } */

/* Check for .DB suffix on PV8QI shuffle operations (4 patterns × 1-2 occurrences each) */
/* { dg-final { scan-assembler-times "\\mppaire\\.db\\M" 2 } } */
/* { dg-final { scan-assembler-times "\\mppaireo\\.db\\M" 2 } } */
/* { dg-final { scan-assembler-times "\\mppairoe\\.db\\M" 1 } } */
/* { dg-final { scan-assembler-times "\\mppairo\\.db\\M" 1 } } */

/* Verify no RV64-style instructions are generated (.h or .b without .d prefix) */
/* { dg-final { scan-assembler-not "\\mppaire\\.h\\M" } } */
/* { dg-final { scan-assembler-not "\\mppaire\\.b\\M" } } */
/* { dg-final { scan-assembler-not "\\mppaireo\\.h\\M" } } */
/* { dg-final { scan-assembler-not "\\mppaireo\\.b\\M" } } */
/* { dg-final { scan-assembler-not "\\mppairoe\\.h\\M" } } */
/* { dg-final { scan-assembler-not "\\mppairoe\\.b\\M" } } */
/* { dg-final { scan-assembler-not "\\mppairo\\.h\\M" } } */
/* { dg-final { scan-assembler-not "\\mppairo\\.b\\M" } } */
