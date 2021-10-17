
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

unsigned long test_srli32 (unsigned long a, unsigned int b) {
return (unsigned long) ((uint32x2_t)a >> 1);
}

/* { dg-final { scan-assembler "srli32\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

