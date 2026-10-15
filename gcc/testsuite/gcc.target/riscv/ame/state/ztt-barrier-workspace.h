#include "ztt-empty-barrier.h"
#ifdef __cplusplus
extern "C" {
#endif
void workspace_stack (const element *in, element *out, unsigned flag)
{
  volatile element local[2];
  local[0] = flag;
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __atomic_thread_fence (__ATOMIC_SEQ_CST);
  a = __riscv_ztt_madd_ew_i32_1x1 (a, a);
  __riscv_ztt_mss_rm (out, a);
  out[0] ^= local[0];
}
void workspace_pressure (const element *in, element *out, unsigned flag)
{
#define LOAD(I) matrix a##I = __riscv_ztt_mls_rm_i32_1x1 (in + 64 * I)
  LOAD (0); LOAD (1); LOAD (2); LOAD (3); LOAD (4);
  LOAD (5); LOAD (6); LOAD (7); LOAD (8);
#undef LOAD
  asm volatile ("" ::: "memory");
#define STORE(I) __riscv_ztt_mss_rm (out + 64 * I, a##I)
  STORE (0); STORE (1); STORE (2); STORE (3); STORE (4);
  STORE (5); STORE (6); STORE (7); STORE (8);
#undef STORE
}
#ifdef __cplusplus
}
#endif
