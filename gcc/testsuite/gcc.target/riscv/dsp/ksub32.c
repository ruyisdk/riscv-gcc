
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ksub32(uintXLEN_t a, uintXLEN_t b) {
    return __rv__ksub32 (a, b);
}

/* { dg-final { scan-assembler "\tksub32" } }*/

/* { dg-final { cleanup-saved-temps } } */
