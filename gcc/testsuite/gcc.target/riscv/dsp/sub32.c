
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sub32(uintXLEN_t a, uintXLEN_t b) {
    return __rv__sub32 (a, b);
}

/* { dg-final { scan-assembler "\tsub32" } }*/

/* { dg-final { cleanup-saved-temps } } */
