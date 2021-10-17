
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int8x8_t test_v_kabs8(int8x8_t a) {
    return __rv__v_kabs8 (a);
}

/* { dg-final { scan-assembler "\tkabs8" } }*/

/* { dg-final { cleanup-saved-temps } } */
