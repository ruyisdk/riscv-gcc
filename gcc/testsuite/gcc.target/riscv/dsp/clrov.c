
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

void test_clrov(void) {
    return __rv__clrov ();
}

/* { dg-final { scan-assembler "\tclrov" } }*/

/* { dg-final { cleanup-saved-temps } } */
