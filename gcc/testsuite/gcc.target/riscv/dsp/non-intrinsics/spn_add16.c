
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

#if (__riscv_xlen==64)
#define VT int16x4_t
#define UVT uint16x4_t
#else
#define VT int16x2_t
#define UVT uint16x2_t
#endif

unsigned long test_sadd16 (unsigned long a, unsigned long b) {
return (unsigned long) ((VT)a + (VT)b);
}

/* { dg-final { scan-assembler "add16\t" } }*/

unsigned long test_uadd16 (unsigned long a, unsigned long b) {
return (unsigned long) ((UVT)a + (UVT)b);
}

/* { dg-final { scan-assembler "add16\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

