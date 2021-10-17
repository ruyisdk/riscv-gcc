
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_kdmtt(uint32_t a, uint32_t b) {
    return __rv__kdmtt (a, b);
}

/* { dg-final { scan-assembler "\tkdmtt" } }*/

/* { dg-final { cleanup-saved-temps } } */
