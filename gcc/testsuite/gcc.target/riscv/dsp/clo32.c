
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_clo32(uintXLEN_t a) {
    return __rv__clo32 (a);
}

/* { dg-final { scan-assembler "\tclo32" } }*/

/* { dg-final { cleanup-saved-temps } } */
