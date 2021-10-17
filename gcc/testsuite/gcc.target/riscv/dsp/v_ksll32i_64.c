
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_ksll32(int32x2_t a, const uint32_t b) {
    return __rv__v_ksll32 (a, 1);
}

/* { dg-final { scan-assembler "\tkslli32" } }*/

/* { dg-final { cleanup-saved-temps } } */
