
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_maddr32(int32_t t, int32_t a, int32_t b) {
    return __rv__maddr32 (t, a, b);
}

/* { dg-final { scan-assembler "\tmaddr32" } }*/

/* { dg-final { cleanup-saved-temps } } */
