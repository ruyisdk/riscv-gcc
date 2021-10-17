
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ursub8(uintXLEN_t a, uintXLEN_t b) {
    return __rv__ursub8 (a, b);
}

/* { dg-final { scan-assembler "\tursub8" } }*/

/* { dg-final { cleanup-saved-temps } } */
