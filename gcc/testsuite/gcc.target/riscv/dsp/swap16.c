
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_swap16(uintXLEN_t a) {
    return __rv__swap16 (a);
}

/* { dg-final { scan-assembler "\tswap16" } }*/

/* { dg-final { cleanup-saved-temps } } */
