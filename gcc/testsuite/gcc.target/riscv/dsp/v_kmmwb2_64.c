
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_kmmwb2(int32x2_t a, int16x4_t b) {
    return __rv__v_kmmwb2 (a, b);
}

/* { dg-final { scan-assembler "\tkmmwb2" } }*/

/* { dg-final { cleanup-saved-temps } } */
