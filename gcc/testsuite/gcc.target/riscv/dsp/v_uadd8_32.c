
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x4_t test_v_uadd8(uint8x4_t a, uint8x4_t b) {
    return __rv__v_uadd8 (a, b);
}

/* { dg-final { scan-assembler "\tadd8" } }*/

/* { dg-final { cleanup-saved-temps } } */
