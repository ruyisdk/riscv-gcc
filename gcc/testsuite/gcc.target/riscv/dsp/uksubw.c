
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_uksubw(uint32_t a, uint32_t b) {
    return __rv__uksubw (a, b);
}

/* { dg-final { scan-assembler "\tuksubw" } }*/

/* { dg-final { cleanup-saved-temps } } */
