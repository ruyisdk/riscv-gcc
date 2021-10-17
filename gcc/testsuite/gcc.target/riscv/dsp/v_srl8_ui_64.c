
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x8_t test_v_srl8_u(uint8x8_t a, const uint32_t b) {
    return __rv__v_srl8_u (a, 1);
}

/* { dg-final { scan-assembler "\tsrli8.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
