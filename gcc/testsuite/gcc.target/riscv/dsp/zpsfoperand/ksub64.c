
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_ksub64(int64_t a, int64_t b) {
    return __rv__ksub64 (a, b);
}

/* { dg-final { scan-assembler "\tksub64" } }*/

/* { dg-final { cleanup-saved-temps } } */
