
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int8x4_t test_v_rsub8(int8x4_t a, int8x4_t b) {
    return __rv__v_rsub8 (a, b);
}

/* { dg-final { scan-assembler "\trsub8" } }*/

/* { dg-final { cleanup-saved-temps } } */
