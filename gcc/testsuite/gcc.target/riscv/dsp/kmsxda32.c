
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_kmsxda32(int64_t t, uint64_t a, uint64_t b) {
    return __rv__kmsxda32 (t, a, b);
}

/* { dg-final { scan-assembler "\tkmsxda32" } }*/

/* { dg-final { cleanup-saved-temps } } */
