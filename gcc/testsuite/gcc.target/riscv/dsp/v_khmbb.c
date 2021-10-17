
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_v_khmbb(int16x2_t a, int16x2_t b) {
    return __rv__v_khmbb (a, b);
}

/* { dg-final { scan-assembler "\tkhmbb" } }*/

/* { dg-final { cleanup-saved-temps } } */
