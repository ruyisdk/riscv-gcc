
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_v_kmatt32(int64_t t, int32x2_t a, int32x2_t b) {
    return __rv__v_kmatt32 (t, a, b);
}

/* { dg-final { scan-assembler "\tkmatt32" } }*/

/* { dg-final { cleanup-saved-temps } } */
