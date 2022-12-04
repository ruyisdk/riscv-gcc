
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

/* When rv32, smmul is identical to mulh. */

#include <riscv-dsp.h>

intXLEN_t test_smmul(intXLEN_t a, intXLEN_t b) {
    return __rv__smmul (a, b);
}

/* { dg-final { scan-assembler "\tsmmul" } }*/

/* { dg-final { cleanup-saved-temps } } */
