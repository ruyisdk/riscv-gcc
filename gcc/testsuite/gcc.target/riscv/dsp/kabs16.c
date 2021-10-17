
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_kabs16(uintXLEN_t a) {
    return __rv__kabs16 (a);
}

/* { dg-final { scan-assembler "\tkabs16" } }*/

/* { dg-final { cleanup-saved-temps } } */
