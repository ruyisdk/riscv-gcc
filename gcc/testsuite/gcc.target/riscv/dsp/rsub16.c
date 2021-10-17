
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_rsub16(uintXLEN_t a, uintXLEN_t b) {
    return __rv__rsub16 (a, b);
}

/* { dg-final { scan-assembler "\trsub16" } }*/

/* { dg-final { cleanup-saved-temps } } */
