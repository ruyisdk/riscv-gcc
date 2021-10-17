
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smsr64(int64_t t, intXLEN_t a, intXLEN_t b) {
    return __rv__smsr64 (t, a, b);
}

/* { dg-final { scan-assembler "\tsmsr64" } }*/

/* { dg-final { cleanup-saved-temps } } */
