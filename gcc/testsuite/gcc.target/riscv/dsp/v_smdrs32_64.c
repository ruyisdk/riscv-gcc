
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_v_smdrs32(int32x2_t a, int32x2_t b) {
    return __rv__v_smdrs32 (a, b);
}

/* { dg-final { scan-assembler "\tsmdrs32" } }*/

/* { dg-final { cleanup-saved-temps } } */
