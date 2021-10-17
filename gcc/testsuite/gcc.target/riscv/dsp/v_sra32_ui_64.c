
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_sra32_u(int32x2_t a, const uint32_t b) {
    return __rv__v_sra32_u (a, 1);
}

/* { dg-final { scan-assembler "\tsrai32.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
