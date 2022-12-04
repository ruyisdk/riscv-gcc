
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smbb32(uint64_t a, uint64_t b) {
    return __rv__smbb32 (a, b);
}

/* { dg-final { scan-assembler "\tsmbb32" } }*/

/* { dg-final { cleanup-saved-temps } } */
