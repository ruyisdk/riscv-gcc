
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ukstsa32(uintXLEN_t a, uintXLEN_t b) {
    return __rv__ukstsa32 (a, b);
}

/* { dg-final { scan-assembler "\tukstsa32" } }*/

/* { dg-final { cleanup-saved-temps } } */
