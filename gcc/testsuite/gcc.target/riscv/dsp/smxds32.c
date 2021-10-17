
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smxds32(uintXLEN_t a, uintXLEN_t b) {
    return __rv__smxds32 (a, b);
}

/* { dg-final { scan-assembler "\tsmxds32" } }*/

/* { dg-final { cleanup-saved-temps } } */
