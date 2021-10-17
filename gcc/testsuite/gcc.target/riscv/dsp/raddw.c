
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_raddw(int32_t a, int32_t b) {
    return __rv__raddw (a, b);
}

/* { dg-final { scan-assembler "\traddw" } }*/

/* { dg-final { cleanup-saved-temps } } */
