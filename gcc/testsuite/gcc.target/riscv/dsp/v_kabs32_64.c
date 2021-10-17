
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_kabs32(int32x2_t a) {
    return __rv__v_kabs32 (a);
}

/* { dg-final { scan-assembler "\tkabs32" } }*/

/* { dg-final { cleanup-saved-temps } } */
