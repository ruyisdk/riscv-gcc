#include "ztt-fence-md.h"
#ifdef __cplusplus
extern "C" {
#endif
#define BARRIER_TEST(NAME, CODE) \
void barrier_##NAME (const element *in, element *out, unsigned flag) \
{ \
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  CODE; \
  a = __riscv_ztt_madd_ew_i32_1x1 (a, a); \
  __riscv_ztt_mss_rm (out, a); \
}
BARRIER_TEST (empty, asm volatile ("" ::: "memory"))
BARRIER_TEST (input, asm volatile ("" :: "r" (flag) : "memory"))
BARRIER_TEST (output, asm volatile ("" : "+r" (flag) :: "memory"))
BARRIER_TEST (clobber, asm volatile ("" ::: "memory", "m4"))
BARRIER_TEST (opaque, asm volatile ("# boundary" ::: "memory"))
BARRIER_TEST (go, asm goto ("" ::: "memory" : done); done: (void) flag)
#undef BARRIER_TEST
#ifdef __cplusplus
}
#endif
