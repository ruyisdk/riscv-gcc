
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

unsigned long test_sadd32 (unsigned long a, unsigned long b) {
return (unsigned long) ((int32x2_t)a + (int32x2_t)b);
}

/* { dg-final { scan-assembler "add32\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

