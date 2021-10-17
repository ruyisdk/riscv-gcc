
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_kabs16(int16x4_t a) {
    return __rv__v_kabs16 (a);
}

/* { dg-final { scan-assembler "\tkabs16" } }*/

/* { dg-final { cleanup-saved-temps } } */
