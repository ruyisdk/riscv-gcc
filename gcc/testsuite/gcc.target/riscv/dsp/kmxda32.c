
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_kmxda32(uint64_t a, uint64_t b) {
    return __rv__kmxda32 (a, b);
}

/* { dg-final { scan-assembler "\tkmxda32" } }*/

/* { dg-final { cleanup-saved-temps } } */
