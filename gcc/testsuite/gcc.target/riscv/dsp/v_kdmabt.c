
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_kdmabt(int32_t t, int16x2_t a, int16x2_t b) {
    return __rv__v_kdmabt (t, a, b);
}

/* { dg-final { scan-assembler "\tkdmabt" } }*/

/* { dg-final { cleanup-saved-temps } } */
