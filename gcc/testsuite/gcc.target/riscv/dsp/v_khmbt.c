
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_v_khmbt(int16x2_t a, int16x2_t b) {
    return __rv__v_khmbt (a, b);
}

/* { dg-final { scan-assembler "\tkhmbt" } }*/

/* { dg-final { cleanup-saved-temps } } */
