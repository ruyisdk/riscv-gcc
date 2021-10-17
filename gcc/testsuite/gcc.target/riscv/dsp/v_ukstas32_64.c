
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint32x2_t test_v_ukstas32(uint32x2_t a, uint32x2_t b) {
    return __rv__v_ukstas32 (a, b);
}

/* { dg-final { scan-assembler "\tukstas32" } }*/

/* { dg-final { cleanup-saved-temps } } */
