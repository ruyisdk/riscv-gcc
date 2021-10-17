
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_sadd64(int64_t a, int64_t b) {
    return __rv__sadd64 (a, b);
}

/* { dg-final { scan-assembler "\tadd64" } }*/

/* { dg-final { cleanup-saved-temps } } */
