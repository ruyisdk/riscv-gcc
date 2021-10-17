
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_sra_u(intXLEN_t a, uint32_t b) {
    return __rv__sra_u (a, b);
}

/* { dg-final { scan-assembler "\tsra.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
