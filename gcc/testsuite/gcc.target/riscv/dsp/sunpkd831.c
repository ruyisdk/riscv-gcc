
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sunpkd831(uintXLEN_t a) {
    return __rv__sunpkd831 (a);
}

/* { dg-final { scan-assembler "\tsunpkd831" } }*/

/* { dg-final { cleanup-saved-temps } } */
