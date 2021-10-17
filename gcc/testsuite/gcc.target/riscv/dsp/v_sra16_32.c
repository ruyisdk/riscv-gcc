
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int16x2_t test_v_sra16(int16x2_t a, uint32_t b) {
    return __rv__v_sra16 (a, b);
}

/* { dg-final { scan-assembler "\tsra16" } }*/

/* { dg-final { cleanup-saved-temps } } */
