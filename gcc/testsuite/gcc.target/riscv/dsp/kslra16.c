
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_kslra16(uintXLEN_t a, int32_t b) {
    return __rv__kslra16 (a, b);
}

/* { dg-final { scan-assembler "\tkslra16" } }*/

/* { dg-final { cleanup-saved-temps } } */
