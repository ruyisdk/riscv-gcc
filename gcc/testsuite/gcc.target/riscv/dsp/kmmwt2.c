
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmwt2(intXLEN_t a, uintXLEN_t b) {
    return __rv__kmmwt2 (a, b);
}

/* { dg-final { scan-assembler "\tkmmwt2" } }*/

/* { dg-final { cleanup-saved-temps } } */
