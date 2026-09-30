/* 128-bit storage elements, not ordinary C integer arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
#ifndef __riscv_ztt_memory128
#error missing memory128 capability
#endif
typedef __riscv_ztt_i128_storage_t I;
typedef __riscv_ztt_u128_storage_t U;
_Static_assert (sizeof (I) == 16 && sizeof (U) == 16, "element size");
_Static_assert (__alignof__ (I) == 16 && __alignof__ (U) == 16, "element alignment");
_Static_assert (sizeof (I[3]) == 48, "array stride");
struct container { char prefix; I item; U tail; };
_Static_assert (offsetof (struct container, item) == 16, "field alignment");
_Static_assert (offsetof (struct container, tail) == 32, "next field");
I initialized = {{ 1,2,3,4,5,6,7,8,129,130,131,132,133,134,135,255 }};
void copy_element (I *out, const I *in) { *out = *in; }
I *next (I *p) { return p + 1; }
unsigned int high (const I *p) { return p->__bytes[15]; }
void alias (I *out, const I *in)
{
  __riscv_ztt_i128_1x1_t value = __riscv_ztt_mls_rm_i128_1x1 (in);
  __riscv_ztt_mss_rm_i128_1x1 (out, value);
}
_Static_assert (!__builtin_types_compatible_p (I, U), "distinct types");
