
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_wext(uint64_t a, const uint32_t b) {
    return __rv__wext (a, 1);
}

/* { dg-final { scan-assembler "\twexti" } }*/

/* { dg-final { cleanup-saved-temps } } */
