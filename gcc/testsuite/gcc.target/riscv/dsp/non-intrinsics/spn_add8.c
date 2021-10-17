
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

#if (__riscv_xlen==64)
#define VT int8x8_t
#define UVT uint8x8_t
#else
#define VT int8x4_t
#define UVT uint8x4_t
#endif

unsigned long test_sadd8 (unsigned long a, unsigned long b) {
return (unsigned long) ((VT)a + (VT)b);
}

/* { dg-final { scan-assembler "add8\t" } }*/

unsigned long test_uadd8 (unsigned long a, unsigned long b) {
return (unsigned long) ((UVT)a + (UVT)b);
}

/* { dg-final { scan-assembler "add8\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

