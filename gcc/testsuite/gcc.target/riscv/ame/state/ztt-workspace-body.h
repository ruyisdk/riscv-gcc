#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef __INT32_TYPE__ elem;
#define FN __attribute__((noinline,noclone))
#define LOAD(P) __riscv_ztt_mls_rm_i32_1x1 (P)
#define STORE(P, V) __riscv_ztt_mss_rm (P, V)

#ifndef WORKSPACE_BOUNDARIES
FN void workspace_copy (elem *out, const elem *in)
{
  STORE (out, LOAD (in));
}

FN void workspace_pair (elem *out0, elem *out1,
                        const elem *in0, const elem *in1)
{
  __riscv_ztt_i32_1x1_t a = LOAD (in0);
  __riscv_ztt_i32_1x1_t b = LOAD (in1);
  STORE (out0, a);
  STORE (out1, b);
}
#else
extern void workspace_callee (elem *);

FN void workspace_call (elem *out, const elem *in)
{
  __riscv_ztt_i32_1x1_t a = LOAD (in);
  workspace_callee (out);
  STORE (out, a);
}

FN void workspace_asm (elem *out, const elem *in)
{
  __riscv_ztt_i32_1x1_t a = LOAD (in);
  __asm__ volatile ("" ::: "memory");
  STORE (out, a);
}

FN void workspace_local (elem *out, const elem *in, elem n)
{
  volatile elem local[4];
  local[0] = n;
  STORE (out, LOAD (in));
  out[0] ^= local[0];
}

FN void workspace_loop (elem *out, const elem *in, unsigned long count)
{
  for (unsigned long i = 0; i < count; ++i)
    STORE (out + i, LOAD (in + i));
}

FN void workspace_stack_arg (elem *out, const elem *in,
                            elem a, elem b, elem c, elem d,
                            elem e, elem f, const elem *extra)
{
  STORE (out, LOAD (in));
  out[0] ^= *extra + a + b + c + d + e + f;
}

FN void workspace_alloca (elem *out, const elem *in, unsigned long count)
{
  elem *local = (elem *) __builtin_alloca (count * sizeof (elem));
  local[0] = *in;
  workspace_callee (local);
  STORE (out, LOAD (in));
  out[0] ^= local[0];
}
#endif

#ifdef __cplusplus
}
#endif
