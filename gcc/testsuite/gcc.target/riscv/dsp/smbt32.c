
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smbt32(uint64_t a, uint64_t b) {
    return __rv__smbt32 (a, b);
}

/* { dg-final { scan-assembler "\tsmbt32" } }*/

/* { dg-final { cleanup-saved-temps } } */
