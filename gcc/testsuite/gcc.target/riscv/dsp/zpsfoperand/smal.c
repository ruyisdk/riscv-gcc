
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smal(int64_t a, uintXLEN_t b) {
    return __rv__smal (a, b);
}

/* { dg-final { scan-assembler "\tsmal" } }*/

/* { dg-final { cleanup-saved-temps } } */
