
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_rsub64(int64_t a, int64_t b) {
    return __rv__rsub64 (a, b);
}

/* { dg-final { scan-assembler "\trsub64" } }*/

/* { dg-final { cleanup-saved-temps } } */
