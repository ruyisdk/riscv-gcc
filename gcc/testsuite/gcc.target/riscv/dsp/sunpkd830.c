
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sunpkd830(uintXLEN_t a) {
    return __rv__sunpkd830 (a);
}

/* { dg-final { scan-assembler "\tsunpkd830" } }*/

/* { dg-final { cleanup-saved-temps } } */
