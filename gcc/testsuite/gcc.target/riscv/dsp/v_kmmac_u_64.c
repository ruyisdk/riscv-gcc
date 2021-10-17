
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_kmmac_u(int32x2_t t, int32x2_t a, int32x2_t b) {
    return __rv__v_kmmac_u (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmac.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
