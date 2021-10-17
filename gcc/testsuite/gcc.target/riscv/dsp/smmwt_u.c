
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smmwt_u(intXLEN_t a, uintXLEN_t b) {
    return __rv__smmwt_u (a, b);
}

/* { dg-final { scan-assembler "\tsmmwt.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
