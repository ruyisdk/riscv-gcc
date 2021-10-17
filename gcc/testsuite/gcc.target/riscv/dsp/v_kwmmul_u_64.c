
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_kwmmul_u(int32x2_t a, int32x2_t b) {
    return __rv__v_kwmmul_u (a, b);
}

/* { dg-final { scan-assembler "\tkwmmul.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
