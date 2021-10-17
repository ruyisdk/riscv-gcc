
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint32x2_t test_v_clo32(uint32x2_t a) {
    return __rv__v_clo32 (a);
}

/* { dg-final { scan-assembler "\tclo32" } }*/

/* { dg-final { cleanup-saved-temps } } */
