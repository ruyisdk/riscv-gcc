#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void redefs_callee (void);
extern volatile int redefs_condition;

#define CHAIN(NAME, OP, RM, BARRIER) \
void NAME (const __INT32_TYPE__ *a, const __INT32_TYPE__ *b, \
           __INT32_TYPE__ *out) \
{ \
  __riscv_ztt_i32_##RM##_1x1_t x = __riscv_ztt_mls_rm_i32_##RM##_1x1 (a); \
  __riscv_ztt_i32_##RM##_1x1_t y = __riscv_ztt_mls_rm_i32_##RM##_1x1 (b); \
  x = __riscv_ztt_m##OP##_ew_i32_##RM##_1x1 (x, y); \
  BARRIER; \
  x = __riscv_ztt_m##OP##_ew_i32_##RM##_1x1 (x, y); \
  x = __riscv_ztt_m##OP##_ew_i32_##RM##_1x1 (x, y); \
  __riscv_ztt_mss_rm (out, x); \
}
#define OP(NAME) CHAIN (chain_##NAME, NAME, rnu, (void) 0)
OP (add)
OP (sub)
OP (min)
OP (max)
OP (and)
OP (andnot)
OP (or)
OP (ornot)
OP (xor)
CHAIN (chain_rne, add, rne, (void) 0)
CHAIN (chain_rdn, add, rdn, (void) 0)
CHAIN (chain_rod, add, rod, (void) 0)
CHAIN (chain_call, add, rnu, redefs_callee ())
CHAIN (chain_asm, add, rnu, __asm__ volatile ("" ::: "memory"))
CHAIN (chain_join, add, rnu, if (redefs_condition) redefs_callee ())
#undef OP
#undef CHAIN
#ifdef __cplusplus
}
#endif
