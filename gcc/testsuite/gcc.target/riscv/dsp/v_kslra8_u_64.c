
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int8x8_t test_v_kslra8_u(int8x8_t a, int32_t b) {
    return __rv__v_kslra8_u (a, b);
}

/* { dg-final { scan-assembler "\tkslra8.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
