
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_v_khmtt(int16x2_t a, int16x2_t b) {
    return __rv__v_khmtt (a, b);
}

/* { dg-final { scan-assembler "\tkhmtt" } }*/

/* { dg-final { cleanup-saved-temps } } */
