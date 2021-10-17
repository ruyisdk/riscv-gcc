
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmawb_u(intXLEN_t t, intXLEN_t a, uintXLEN_t b) {
    return __rv__kmmawb_u (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmawb.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
