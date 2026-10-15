#include "ztt-spill-address.h"

#ifdef __cplusplus
extern "C" {
#endif
#define TAIL_CASE(NAME, AFTER) \
void __attribute__((noipa)) \
NAME (const element_t *old, const element_t *input, \
      element_t *out, element_t *saved) \
{ \
  matrix_t d = LOAD (old); \
  matrix_t result = SCAT (d, d, d); \
  __riscv_ztt_mss_rm (out, result); \
  AFTER; \
  __riscv_ztt_mss_rm (saved, d); \
}
TAIL_CASE (sa_tail_call, sa_callee ())
TAIL_CASE (sa_tail_asm, __asm__ volatile ("" ::: "memory"))
#ifdef __cplusplus
}
#endif
