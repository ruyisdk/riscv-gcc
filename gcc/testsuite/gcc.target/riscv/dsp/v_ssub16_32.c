
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int16x2_t test_v_ssub16(int16x2_t a, int16x2_t b) {
    return __rv__v_ssub16 (a, b);
}

/* { dg-final { scan-assembler "\tsub16" } }*/

/* { dg-final { cleanup-saved-temps } } */
