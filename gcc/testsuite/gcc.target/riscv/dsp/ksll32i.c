
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ksll32(uintXLEN_t a, const uint32_t b) {
    return __rv__ksll32 (a, 1);
}

/* { dg-final { scan-assembler "\tkslli32" } }*/

/* { dg-final { cleanup-saved-temps } } */
