
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint32_t test_v_pbsad(uint8x4_t a, uint8x4_t b) {
    return __rv__v_pbsad (a, b);
}

/* { dg-final { scan-assembler "\tpbsad" } }*/

/* { dg-final { cleanup-saved-temps } } */
