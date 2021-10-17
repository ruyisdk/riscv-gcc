
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmawt(intXLEN_t t, intXLEN_t a, uintXLEN_t b) {
    return __rv__kmmawt (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmawt" } }*/

/* { dg-final { cleanup-saved-temps } } */
