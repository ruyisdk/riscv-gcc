
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_add32(uintXLEN_t a, uintXLEN_t b) {
    return __rv__add32 (a, b);
}

/* { dg-final { scan-assembler "\tadd32" } }*/

/* { dg-final { cleanup-saved-temps } } */
