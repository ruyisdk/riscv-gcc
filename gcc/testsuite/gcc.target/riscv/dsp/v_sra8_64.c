
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int8x8_t test_v_sra8(int8x8_t a, uint32_t b) {
    return __rv__v_sra8 (a, b);
}

/* { dg-final { scan-assembler "\tsra8" } }*/

/* { dg-final { cleanup-saved-temps } } */
