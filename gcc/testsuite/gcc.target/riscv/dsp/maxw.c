
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_maxw(int32_t a, int32_t b) {
    return __rv__maxw (a, b);
}

/* { dg-final { scan-assembler "\tmaxw" } }*/

/* { dg-final { cleanup-saved-temps } } */
