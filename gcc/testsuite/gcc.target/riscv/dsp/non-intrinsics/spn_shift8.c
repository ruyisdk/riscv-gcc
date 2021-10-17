
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

unsigned long test_sra8 (unsigned long a, unsigned long b) {
return (unsigned long) ((VT)a >> b);
}

/* { dg-final { scan-assembler "sra8\t" } }*/

unsigned long test_srai8 (unsigned long a) {
return (unsigned long) ((VT)a >> 5);
}

/* { dg-final { scan-assembler "srai8\t" } }*/

unsigned long test_srl8 (unsigned long a, unsigned long b) {
return (unsigned long) ((UVT)a >> b);
}

/* { dg-final { scan-assembler "srl8\t" } }*/

unsigned long test_srli8 (unsigned long a) {
return (unsigned long) ((UVT)a >> 5);
}

/* { dg-final { scan-assembler "srli8\t" } }*/

unsigned long test_sll8 (unsigned long a, unsigned long b) {
return (unsigned long) ((VT)a << b);
}

/* { dg-final { scan-assembler "sll8\t" } }*/

unsigned long test_slli8 (unsigned long a) {
return (unsigned long) ((VT)a << 5);
}

/* { dg-final { scan-assembler "slli8\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

