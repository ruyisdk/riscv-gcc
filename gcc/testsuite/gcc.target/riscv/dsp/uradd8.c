
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_uradd8(uintXLEN_t a, uintXLEN_t b) {
    return __rv__uradd8 (a, b);
}

/* { dg-final { scan-assembler "\turadd8" } }*/

/* { dg-final { cleanup-saved-temps } } */
