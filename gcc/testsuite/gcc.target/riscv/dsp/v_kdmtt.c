
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_kdmtt(int16x2_t a, int16x2_t b) {
    return __rv__v_kdmtt (a, b);
}

/* { dg-final { scan-assembler "\tkdmtt" } }*/

/* { dg-final { cleanup-saved-temps } } */
