
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmwb2(intXLEN_t a, uintXLEN_t b) {
    return __rv__kmmwb2 (a, b);
}

/* { dg-final { scan-assembler "\tkmmwb2" } }*/

/* { dg-final { cleanup-saved-temps } } */
