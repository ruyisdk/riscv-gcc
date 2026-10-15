#include "ztt-spill-address.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OBSERVER(NAME, AFTER) \
void __attribute__((noipa)) \
NAME (const element_t *old, const element_t *input, element_t *out, element_t *saved) \
{ \
  matrix_t d = LOAD (old); \
  matrix_t result = SCAT (d, d, d); \
  __riscv_ztt_mss_rm (out, result); \
  AFTER; \
  __riscv_ztt_mss_rm (saved, d); \
}
OBSERVER (sa_flags, (void) __riscv_ztt_get_amefflags ())
OBSERVER (sa_nlen, (void) __riscv_ztt_get_amenlen ())
OBSERVER (sa_seq, __atomic_thread_fence (__ATOMIC_SEQ_CST))
OBSERVER (sa_signal, __atomic_signal_fence (__ATOMIC_SEQ_CST))
OBSERVER (sa_empty, __asm__ volatile ("" ::: "memory"))
OBSERVER (sa_unknown, __asm__ volatile ("# AME state boundary" ::: "memory"))
OBSERVER (sa_external, sa_callee ())
#undef OBSERVER
#ifdef __cplusplus
}
#endif
