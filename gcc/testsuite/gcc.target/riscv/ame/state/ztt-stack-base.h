#include <stdint.h>
#include <riscv_ztt.h>

extern void stack_observe (volatile long *);

#define STACK_BODY \
  local[0] = control; \
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mls_rm_i32_rnu_1x1 (in); \
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m); \
  if (control) local[1] = local[0]+1; \
  else local[1] = local[0]-1; \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a))

#ifdef __cplusplus
extern "C" {
#endif
long stack_base (const int32_t *in, int32_t *out, long control)
{
  volatile long local[4];
  STACK_BODY;
  return local[1];
}
long stack_call (const int32_t *in, int32_t *out, long control)
{
  volatile long local[4];
  STACK_BODY;
  stack_observe (local);
  return local[1];
}
long stack_alloca (const int32_t *in, int32_t *out, long control,
                   unsigned int bytes)
{
  volatile long *local = (volatile long *) __builtin_alloca (bytes);
  STACK_BODY;
  __asm__ volatile ("" : : "r" (local) : "memory");
  return local[1];
}
__attribute__((optimize("O0")))
long stack_o0 (const int32_t *in, int32_t *out, long control)
{
  volatile long local[4];
  STACK_BODY;
  return local[1];
}
#ifdef __cplusplus
}
#endif
#undef STACK_BODY
