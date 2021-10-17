
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_ursub64(uint64_t a, uint64_t b) {
    return __rv__ursub64 (a, b);
}

/* { dg-final { scan-assembler "\tursub64" } }*/

/* { dg-final { cleanup-saved-temps } } */
