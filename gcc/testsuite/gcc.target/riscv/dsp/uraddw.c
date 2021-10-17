
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_uraddw(uint32_t a, uint32_t b) {
    return __rv__uraddw (a, b);
}

/* { dg-final { scan-assembler "\turaddw" } }*/

/* { dg-final { cleanup-saved-temps } } */
