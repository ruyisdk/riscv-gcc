
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_ukadd64(uint64_t a, uint64_t b) {
    return __rv__ukadd64 (a, b);
}

/* { dg-final { scan-assembler "\tukadd64" } }*/

/* { dg-final { cleanup-saved-temps } } */
