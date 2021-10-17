
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x8_t test_v_sll8(uint8x8_t a, const uint32_t b) {
    return __rv__v_sll8 (a, 1);
}

/* { dg-final { scan-assembler "\tslli8" } }*/

/* { dg-final { cleanup-saved-temps } } */
