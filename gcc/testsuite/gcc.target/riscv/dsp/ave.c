
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_ave(intXLEN_t a, intXLEN_t b) {
    return __rv__ave (a, b);
}

/* { dg-final { scan-assembler "\tave" } }*/

/* { dg-final { cleanup-saved-temps } } */
