
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_khmbt(uint32_t a, uint32_t b) {
    return __rv__khmbt (a, b);
}

/* { dg-final { scan-assembler "\tkhmbt" } }*/

/* { dg-final { cleanup-saved-temps } } */
