
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_zunpkd832(uintXLEN_t a) {
    return __rv__zunpkd832 (a);
}

/* { dg-final { scan-assembler "\tzunpkd832" } }*/

/* { dg-final { cleanup-saved-temps } } */
