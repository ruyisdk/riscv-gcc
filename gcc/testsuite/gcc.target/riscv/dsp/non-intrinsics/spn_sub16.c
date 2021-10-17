
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

unsigned long test_ssub16 (unsigned long a, unsigned long b) {
return (unsigned long) ((VT)a - (VT)b);
}

/* { dg-final { scan-assembler "sub16\t" } }*/

unsigned long test_usub16 (unsigned long a, unsigned long b) {
return (unsigned long) ((UVT)a - (UVT)b);
}

/* { dg-final { scan-assembler "sub16\t" } }*/

unsigned long test_neg16 (unsigned long a) {
return (unsigned long) (-(VT)a);
}

/* { dg-final { scan-assembler "sub16\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

