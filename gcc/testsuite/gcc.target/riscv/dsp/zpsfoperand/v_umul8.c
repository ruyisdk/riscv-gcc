
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_umul8(uint8x4_t a, uint8x4_t b) {
    return __rv__v_umul8 (a, b);
}

/* { dg-final { scan-assembler "\tumul8" } }*/

/* { dg-final { cleanup-saved-temps } } */
