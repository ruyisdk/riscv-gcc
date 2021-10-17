
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_kslra32(int32x2_t a, int32_t b) {
    return __rv__v_kslra32 (a, b);
}

/* { dg-final { scan-assembler "\tkslra32" } }*/

/* { dg-final { cleanup-saved-temps } } */
