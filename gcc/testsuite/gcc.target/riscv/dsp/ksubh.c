
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_ksubh(int32_t a, int32_t b) {
    return __rv__ksubh (a, b);
}

/* { dg-final { scan-assembler "\tksubh" } }*/

/* { dg-final { cleanup-saved-temps } } */
