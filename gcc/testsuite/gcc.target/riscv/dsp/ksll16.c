
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ksll16(uintXLEN_t a, uint32_t b) {
    return __rv__ksll16 (a, b);
}

/* { dg-final { scan-assembler "\tksll16" } }*/

/* { dg-final { cleanup-saved-temps } } */
