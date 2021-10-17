
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int8x4_t test_v_sclip8(int8x4_t a, const uint32_t b) {
    return __rv__v_sclip8 (a, 1);
}

/* { dg-final { scan-assembler "\tsclip8" } }*/

/* { dg-final { cleanup-saved-temps } } */
