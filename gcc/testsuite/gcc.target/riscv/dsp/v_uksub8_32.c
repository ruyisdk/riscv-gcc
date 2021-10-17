
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x4_t test_v_uksub8(uint8x4_t a, uint8x4_t b) {
    return __rv__v_uksub8 (a, b);
}

/* { dg-final { scan-assembler "\tuksub8" } }*/

/* { dg-final { cleanup-saved-temps } } */
