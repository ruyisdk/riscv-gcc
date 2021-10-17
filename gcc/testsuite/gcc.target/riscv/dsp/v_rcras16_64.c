
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_rcras16(int16x4_t a, int16x4_t b) {
    return __rv__v_rcras16 (a, b);
}

/* { dg-final { scan-assembler "\trcras16" } }*/

/* { dg-final { cleanup-saved-temps } } */
