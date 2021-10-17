
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_v_smalda(int64_t t, int16x4_t a, int16x4_t b) {
    return __rv__v_smalda (t, a, b);
}

/* { dg-final { scan-assembler "\tsmalda" } }*/

/* { dg-final { cleanup-saved-temps } } */
