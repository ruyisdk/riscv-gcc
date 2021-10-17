
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmads(intXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__kmads (t, a, b);
}

/* { dg-final { scan-assembler "\tkmads" } }*/

/* { dg-final { cleanup-saved-temps } } */
