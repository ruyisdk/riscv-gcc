
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_ukstas16(uint16x4_t a, uint16x4_t b) {
    return __rv__v_ukstas16 (a, b);
}

/* { dg-final { scan-assembler "\tukstas16" } }*/

/* { dg-final { cleanup-saved-temps } } */
