
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smalds(int64_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__smalds (t, a, b);
}

/* { dg-final { scan-assembler "\tsmalds" } }*/

/* { dg-final { cleanup-saved-temps } } */
