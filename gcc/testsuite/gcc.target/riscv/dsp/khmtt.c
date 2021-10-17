
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_khmtt(uint32_t a, uint32_t b) {
    return __rv__khmtt (a, b);
}

/* { dg-final { scan-assembler "\tkhmtt" } }*/

/* { dg-final { cleanup-saved-temps } } */
