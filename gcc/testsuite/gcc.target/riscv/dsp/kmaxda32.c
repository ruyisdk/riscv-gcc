
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmaxda32(intXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__kmaxda32 (t, a, b);
}

/* { dg-final { scan-assembler "\tkmaxda32" } }*/

/* { dg-final { cleanup-saved-temps } } */
