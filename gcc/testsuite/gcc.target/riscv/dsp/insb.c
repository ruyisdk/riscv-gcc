
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_insb(uintXLEN_t t, uintXLEN_t a, const uint32_t bpos) {
    return __rv__insb (t, a, 1);
}

/* { dg-final { scan-assembler "\tinsb" } }*/

/* { dg-final { cleanup-saved-temps } } */
