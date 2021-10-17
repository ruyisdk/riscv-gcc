
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_v_umar64(uint64_t t, uint32x2_t a, uint32x2_t b) {
    return __rv__v_umar64 (t, a, b);
}

/* { dg-final { scan-assembler "\tumar64" } }*/

/* { dg-final { cleanup-saved-temps } } */
