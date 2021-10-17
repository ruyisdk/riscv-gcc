
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_add16(uintXLEN_t a, uintXLEN_t b) {
    return __rv__add16 (a, b);
}

/* { dg-final { scan-assembler "\tadd16" } }*/

/* { dg-final { cleanup-saved-temps } } */
