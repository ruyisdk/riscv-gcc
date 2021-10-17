
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smmwb_u(intXLEN_t a, uintXLEN_t b) {
    return __rv__smmwb_u (a, b);
}

/* { dg-final { scan-assembler "\tsmmwb.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
