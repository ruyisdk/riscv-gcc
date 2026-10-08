#include "ztt-binary-md-body.h"
#ifdef __cplusplus
extern "C" {
#endif
#if __riscv_ztt_uds <= 32
#define PREP_COUNT 1
#elif __riscv_ztt_uds == 64
#define PREP_COUNT 2
#else
#define PREP_COUNT 4
#endif
#define PREP_(NAME, COUNT, SIDE, BARRIER, CHAIN, SAME) \
__attribute__((noinline, noclone)) \
void NAME (const binary_element *a, const binary_element *b, \
           binary_element *out, binary_element *left, binary_element *right) \
{ \
  __riscv_ztt_i32_1x##COUNT##_t x, y; \
  if (SIDE != 1) x = __riscv_ztt_mls_rm_i32_1x##COUNT (a); \
  if (SIDE != 2 && !SAME) y = __riscv_ztt_mls_rm_i32_1x##COUNT (b); \
  BARRIER; \
  if (SIDE == 1) x = __riscv_ztt_mls_rm_i32_1x##COUNT (a); \
  if (SIDE == 2 && !SAME) y = __riscv_ztt_mls_rm_i32_1x##COUNT (b); \
  if (SAME) y = x; \
  __riscv_ztt_i32_1x##COUNT##_t z \
    = __riscv_ztt_msub_ew_i32_1x##COUNT (x, y); \
  if (CHAIN) z = __riscv_ztt_madd_ew_i32_1x##COUNT (z, x); \
  __riscv_ztt_mss_rm (out, z); \
  __riscv_ztt_mss_rm (left, x); \
  __riscv_ztt_mss_rm (right, y); \
}
#define EXPAND_PREP(...) PREP_ (__VA_ARGS__)
#define PREP(NAME, SIDE, BARRIER, CHAIN, SAME) \
  EXPAND_PREP (NAME, PREP_COUNT, SIDE, BARRIER, CHAIN, SAME)
PREP (binary_left, 1, __asm__ volatile ("" ::: "memory"), 0, 0)
PREP (binary_right, 2, __asm__ volatile ("" ::: "memory"), 0, 0)
PREP (binary_unknown, 0, __asm__ volatile ("" ::: "memory"), 0, 0)
PREP (binary_call_before, 0, binary_callee (), 0, 0)
PREP (binary_join_before, 0,
      if (binary_condition) __asm__ volatile ("" ::: "memory"), 0, 0)
PREP (binary_chain, 1, __asm__ volatile ("" ::: "memory"), 1, 0)
PREP (binary_same_unknown, 0, __asm__ volatile ("" ::: "memory"), 0, 1)
#undef PREP
#undef EXPAND_PREP
#undef PREP_
#undef PREP_COUNT
#ifdef __cplusplus
}
#endif
