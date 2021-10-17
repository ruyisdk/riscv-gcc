
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_smaqa(int32_t t, int8x4_t a, int8x4_t b) {
    return __rv__v_smaqa (t, a, b);
}

/* { dg-final { scan-assembler "\tsmaqa" } }*/

/* { dg-final { cleanup-saved-temps } } */
