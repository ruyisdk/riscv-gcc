
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x8_t test_v_clrs8(int8x8_t a) {
    return __rv__v_clrs8 (a);
}

/* { dg-final { scan-assembler "\tclrs8" } }*/

/* { dg-final { cleanup-saved-temps } } */
