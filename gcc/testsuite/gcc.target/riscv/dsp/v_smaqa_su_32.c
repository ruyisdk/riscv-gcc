
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_smaqa_su(int32_t t, int8x4_t a, uint8x4_t b) {
    return __rv__v_smaqa_su (t, a, b);
}

/* { dg-final { scan-assembler "\tsmaqa.su" } }*/

/* { dg-final { cleanup-saved-temps } } */
