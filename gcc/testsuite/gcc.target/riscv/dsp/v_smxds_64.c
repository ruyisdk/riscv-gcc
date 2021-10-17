
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_smxds(int16x4_t a, int16x4_t b) {
    return __rv__v_smxds (a, b);
}

/* { dg-final { scan-assembler "\tsmxds" } }*/

/* { dg-final { cleanup-saved-temps } } */
