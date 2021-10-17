
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_bitrev(uintXLEN_t a, uint32_t msb) {
    return __rv__bitrev (a, msb);
}

/* { dg-final { scan-assembler "\tbitrev" } }*/

/* { dg-final { cleanup-saved-temps } } */
