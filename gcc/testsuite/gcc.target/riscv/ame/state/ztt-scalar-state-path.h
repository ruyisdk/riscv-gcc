#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned scalar_path_callee (unsigned);

unsigned
scalar_path_plain (unsigned x)
{
  return (x * 7) ^ (x >> 3);
}

unsigned
scalar_path_call (unsigned x)
{
  return scalar_path_callee (x) + 1;
}

unsigned
scalar_path_asm (unsigned x)
{
  __asm__ volatile ("" : "+r" (x));
  return x + 2;
}

__SIZE_TYPE__
scalar_path_query (void)
{
  return __riscv_ztt_get_ameown ();
}

#ifdef STATE_WIDE
#define ELEMENT __INT32_TYPE__
#define MATRIX __riscv_ztt_i32_1x1_t
#define LOAD __riscv_ztt_mls_rm_i32_1x1
#define ADD __riscv_ztt_madd_ew_i32_1x1
#else
#define ELEMENT __INT8_TYPE__
#define MATRIX __riscv_ztt_i8_1x1_t
#define LOAD __riscv_ztt_mls_rm_i8_1x1
#define ADD __riscv_ztt_madd_ew_i8_1x1
#endif

void
typed_path_plain (const ELEMENT *in, ELEMENT *out)
{
  MATRIX a = LOAD (in);
  a = ADD (a, a);
  __riscv_ztt_mss_rm (out, a);
}

void
typed_path_call (const ELEMENT *in, ELEMENT *out, unsigned n)
{
  MATRIX a = LOAD (in);
  scalar_path_callee (n);
  a = ADD (a, a);
  __riscv_ztt_mss_rm (out, a);
}

#undef ELEMENT
#undef MATRIX
#undef LOAD
#undef ADD
#ifdef __cplusplus
}
#endif
