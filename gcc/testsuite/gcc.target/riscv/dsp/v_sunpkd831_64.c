
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_sunpkd831(int8x8_t a) {
    return __rv__v_sunpkd831 (a);
}

/* { dg-final { scan-assembler "\tsunpkd831" } }*/

/* { dg-final { cleanup-saved-temps } } */
