
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_ksllw(int32_t a, const uint32_t b) {
    return __rv__ksllw (a, 1);
}

/* { dg-final { scan-assembler "\tkslliw" } }*/

/* { dg-final { cleanup-saved-temps } } */
