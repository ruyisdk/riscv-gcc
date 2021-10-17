
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_pbsad(uintXLEN_t a, uintXLEN_t b) {
    return __rv__pbsad (a, b);
}

/* { dg-final { scan-assembler "\tpbsad" } }*/

/* { dg-final { cleanup-saved-temps } } */
