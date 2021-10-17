
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int8x4_t test_v_ksll8(int8x4_t a, uint32_t b) {
    return __rv__v_ksll8 (a, b);
}

/* { dg-final { scan-assembler "\tksll8" } }*/

/* { dg-final { cleanup-saved-temps } } */
