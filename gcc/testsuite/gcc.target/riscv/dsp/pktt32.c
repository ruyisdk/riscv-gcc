
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_pktt32(uint64_t a, uint64_t b) {
    return __rv__pktt32 (a, b);
}

/* { dg-final { scan-assembler "\tpktt32" } }*/

/* { dg-final { cleanup-saved-temps } } */
