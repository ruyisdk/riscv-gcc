
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int8x8_t test_v_ksll8(int8x8_t a, const uint32_t b) {
    return __rv__v_ksll8 (a, 1);
}

/* { dg-final { scan-assembler "\tkslli8" } }*/

/* { dg-final { cleanup-saved-temps } } */
