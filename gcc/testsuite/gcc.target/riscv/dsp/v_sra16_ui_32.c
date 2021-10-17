
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int16x2_t test_v_sra16_u(int16x2_t a, const uint32_t b) {
    return __rv__v_sra16_u (a, 1);
}

/* { dg-final { scan-assembler "\tsrai16.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
