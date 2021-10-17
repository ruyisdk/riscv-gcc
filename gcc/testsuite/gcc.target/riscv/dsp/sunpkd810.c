
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sunpkd810(uintXLEN_t a) {
    return __rv__sunpkd810 (a);
}

/* { dg-final { scan-assembler "\tsunpkd810" } }*/

/* { dg-final { cleanup-saved-temps } } */
