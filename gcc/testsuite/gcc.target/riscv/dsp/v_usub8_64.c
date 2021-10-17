
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x8_t test_v_usub8(uint8x8_t a, uint8x8_t b) {
    return __rv__v_usub8 (a, b);
}

/* { dg-final { scan-assembler "\tsub8" } }*/

/* { dg-final { cleanup-saved-temps } } */
