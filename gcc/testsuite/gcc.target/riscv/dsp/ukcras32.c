
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_ukcras32(uint64_t a, uint64_t b) {
    return __rv__ukcras32 (a, b);
}

/* { dg-final { scan-assembler "\tukcras32" } }*/

/* { dg-final { cleanup-saved-temps } } */
