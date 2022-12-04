
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_kmaxds32(int64_t t, uint64_t a, uint64_t b) {
    return __rv__kmaxds32 (t, a, b);
}

/* { dg-final { scan-assembler "\tkmaxds32" } }*/

/* { dg-final { cleanup-saved-temps } } */
