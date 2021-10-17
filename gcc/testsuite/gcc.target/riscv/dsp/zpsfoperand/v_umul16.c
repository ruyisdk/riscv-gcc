
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint32x2_t test_v_umul16(uint16x2_t a, uint16x2_t b) {
    return __rv__v_umul16 (a, b);
}

/* { dg-final { scan-assembler "\tumul16" } }*/

/* { dg-final { cleanup-saved-temps } } */
