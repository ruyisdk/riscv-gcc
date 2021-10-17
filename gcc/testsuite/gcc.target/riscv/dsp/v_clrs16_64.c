
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_clrs16(int16x4_t a) {
    return __rv__v_clrs16 (a);
}

/* { dg-final { scan-assembler "\tclrs16" } }*/

/* { dg-final { cleanup-saved-temps } } */
