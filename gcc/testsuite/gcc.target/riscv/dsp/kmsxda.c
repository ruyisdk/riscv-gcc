
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmsxda(intXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__kmsxda (t, a, b);
}

/* { dg-final { scan-assembler "\tkmsxda" } }*/

/* { dg-final { cleanup-saved-temps } } */
