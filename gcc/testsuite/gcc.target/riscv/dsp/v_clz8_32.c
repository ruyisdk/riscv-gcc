
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x4_t test_v_clz8(uint8x4_t a) {
    return __rv__v_clz8 (a);
}

/* { dg-final { scan-assembler "\tclz8" } }*/

/* { dg-final { cleanup-saved-temps } } */
