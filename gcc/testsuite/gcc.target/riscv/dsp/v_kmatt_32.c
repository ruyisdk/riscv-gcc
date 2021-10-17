
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_kmatt(int32_t t, int16x2_t a, int16x2_t b) {
    return __rv__v_kmatt (t, a, b);
}

/* { dg-final { scan-assembler "\tkmatt" } }*/

/* { dg-final { cleanup-saved-temps } } */
