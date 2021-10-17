
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_clz16(uintXLEN_t a) {
    return __rv__clz16 (a);
}

/* { dg-final { scan-assembler "\tclz16" } }*/

/* { dg-final { cleanup-saved-temps } } */
