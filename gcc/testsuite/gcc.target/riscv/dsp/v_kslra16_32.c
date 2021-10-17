
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int16x2_t test_v_kslra16(int16x2_t a, int32_t b) {
    return __rv__v_kslra16 (a, b);
}

/* { dg-final { scan-assembler "\tkslra16" } }*/

/* { dg-final { cleanup-saved-temps } } */
