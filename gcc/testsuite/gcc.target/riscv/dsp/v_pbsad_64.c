
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_v_pbsad(uint8x8_t a, uint8x8_t b) {
    return __rv__v_pbsad (a, b);
}

/* { dg-final { scan-assembler "\tpbsad" } }*/

/* { dg-final { cleanup-saved-temps } } */
