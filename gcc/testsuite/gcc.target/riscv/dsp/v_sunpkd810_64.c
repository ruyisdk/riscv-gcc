
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_sunpkd810(int8x8_t a) {
    return __rv__v_sunpkd810 (a);
}

/* { dg-final { scan-assembler "\tsunpkd810" } }*/

/* { dg-final { cleanup-saved-temps } } */
