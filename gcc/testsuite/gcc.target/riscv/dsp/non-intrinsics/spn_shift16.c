
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

unsigned long test_sra16 (unsigned long a, unsigned long b) {
return (unsigned long) ((VT)a >> b);
}

/* { dg-final { scan-assembler "sra16\t" } }*/

unsigned long test_srai16 (unsigned long a) {
return (unsigned long) ((VT)a >> 10);
}

/* { dg-final { scan-assembler "srai16\t" } }*/

unsigned long test_srl16 (unsigned long a, unsigned long b) {
return (unsigned long) ((UVT)a >> b);
}

/* { dg-final { scan-assembler "srl16\t" } }*/

unsigned long test_srli16 (unsigned long a) {
return (unsigned long) ((UVT)a >>10);
}

/* { dg-final { scan-assembler "srli16\t" } }*/

unsigned long test_sll16 (unsigned long a, unsigned long b) {
return (unsigned long) ((VT)a << b);
}

/* { dg-final { scan-assembler "sll16\t" } }*/

unsigned long test_slli16 (unsigned long a) {
return (unsigned long) ((VT)a << 10);
}

/* { dg-final { scan-assembler "slli16\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

