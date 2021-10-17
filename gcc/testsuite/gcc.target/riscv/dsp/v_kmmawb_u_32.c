
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_kmmawb_u(int32_t t, int32_t a, int16x2_t b) {
    return __rv__v_kmmawb_u (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmawb.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
