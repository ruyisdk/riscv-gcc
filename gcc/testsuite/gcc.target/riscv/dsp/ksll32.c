
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_ksll32(uint64_t a, uint32_t b) {
    return __rv__ksll32 (a, b);
}

/* { dg-final { scan-assembler "\tksll32" } }*/

/* { dg-final { cleanup-saved-temps } } */
