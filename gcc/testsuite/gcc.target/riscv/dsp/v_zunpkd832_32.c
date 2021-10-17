
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x2_t test_v_zunpkd832(uint8x4_t a) {
    return __rv__v_zunpkd832 (a);
}

/* { dg-final { scan-assembler "\tzunpkd832" } }*/

/* { dg-final { cleanup-saved-temps } } */
