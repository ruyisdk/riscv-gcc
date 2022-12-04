
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_kdmabt16(uint64_t t, uint64_t a, uint64_t b) {
    return __rv__kdmabt16 (t, a, b);
}

/* { dg-final { scan-assembler "\tkdmabt16" } }*/

/* { dg-final { cleanup-saved-temps } } */
