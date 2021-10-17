
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_kdmabb16(uintXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__kdmabb16 (t, a, b);
}

/* { dg-final { scan-assembler "\tkdmabb16" } }*/

/* { dg-final { cleanup-saved-temps } } */
