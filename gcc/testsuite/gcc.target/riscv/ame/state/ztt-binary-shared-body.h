#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void binary_callee (void);
extern volatile int binary_condition;
typedef __INT32_TYPE__ shared_element;
#if __riscv_ztt_uds <= 32
#define SHARED_COUNT 1
#define SHARED_PAIR 2
#elif __riscv_ztt_uds == 64
#define SHARED_COUNT 2
#define SHARED_PAIR 4
#else
#define SHARED_COUNT 4
#define SHARED_PAIR 8
#endif
#define SHARED_(NAME, OP, RM, COUNT, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const shared_element *a, const shared_element *b, \
           shared_element *out, shared_element *left, shared_element *right) \
{ \
  __riscv_ztt_i32_##RM##_1x##COUNT##_t x \
    = __riscv_ztt_mls_rm_i32_##RM##_1x##COUNT (a); \
  BARRIER; \
  __riscv_ztt_i32_##RM##_1x##COUNT##_t z \
    = __riscv_ztt_m##OP##_ew_i32_##RM##_1x##COUNT (x, x); \
  __riscv_ztt_mss_rm (out, z); \
  __riscv_ztt_mss_rm (left, x); \
  __riscv_ztt_mss_rm (right, x); \
}
#define SHARED(...) SHARED_ (__VA_ARGS__)
#define SHARED_OP(OP) \
  SHARED (shared_##OP, OP, rnu, SHARED_COUNT, \
          __asm__ volatile ("" ::: "memory"))
SHARED_OP (add)
SHARED_OP (sub)
SHARED_OP (min)
SHARED_OP (max)
SHARED_OP (and)
SHARED_OP (andnot)
SHARED_OP (or)
SHARED_OP (ornot)
SHARED_OP (xor)
SHARED (shared_call, add, rnu, SHARED_COUNT, binary_callee ())
SHARED (shared_join, add, rnu, SHARED_COUNT,
        if (binary_condition) __asm__ volatile ("" ::: "memory"))
SHARED (shared_rne, add, rne, SHARED_COUNT,
        __asm__ volatile ("" ::: "memory"))
SHARED (shared_rdn, add, rdn, SHARED_COUNT,
        __asm__ volatile ("" ::: "memory"))
SHARED (shared_rod, add, rod, SHARED_COUNT,
        __asm__ volatile ("" ::: "memory"))
SHARED (shared_pair, add, rnu, SHARED_PAIR,
        __asm__ volatile ("" ::: "memory"))
#undef SHARED_OP
#undef SHARED
#undef SHARED_
#undef SHARED_COUNT
#undef SHARED_PAIR
#ifdef __cplusplus
}
#endif
