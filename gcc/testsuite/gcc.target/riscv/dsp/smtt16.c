
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smtt16(uintXLEN_t a, uintXLEN_t b) {
    return __rv__smtt16 (a, b);
}

/* { dg-final { scan-assembler "\tsmtt16" } }*/

/* { dg-final { cleanup-saved-temps } } */
