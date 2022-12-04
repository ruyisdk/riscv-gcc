
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_kmsda32(int64_t t, uint64_t a, uint64_t b) {
    return __rv__kmsda32 (t, a, b);
}

/* { dg-final { scan-assembler "\tkmsda32" } }*/

/* { dg-final { cleanup-saved-temps } } */
