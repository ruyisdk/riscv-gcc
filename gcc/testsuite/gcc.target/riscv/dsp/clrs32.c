
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_clrs32(intXLEN_t a) {
    return __rv__clrs32 (a);
}

/* { dg-final { scan-assembler "\tclrs32" } }*/

/* { dg-final { cleanup-saved-temps } } */
