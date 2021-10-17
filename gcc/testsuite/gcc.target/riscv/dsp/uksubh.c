
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_uksubh(uint32_t a, uint32_t b) {
    return __rv__uksubh (a, b);
}

/* { dg-final { scan-assembler "\tuksubh" } }*/

/* { dg-final { cleanup-saved-temps } } */
