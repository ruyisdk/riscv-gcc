
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_usub64(uint64_t a, uint64_t b) {
    return __rv__usub64 (a, b);
}

/* { dg-final { scan-assembler "\tsub64" } }*/

/* { dg-final { cleanup-saved-temps } } */
