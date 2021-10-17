
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_rdov(void) {
    return __rv__rdov ();
}

/* { dg-final { scan-assembler "\trdov" } }*/

/* { dg-final { cleanup-saved-temps } } */
