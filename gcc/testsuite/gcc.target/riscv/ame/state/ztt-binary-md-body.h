#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef __INT32_TYPE__ binary_element;
extern void binary_callee (void);
extern volatile int binary_condition;
#if __riscv_ztt_uds == 128
#define BINARY_COUNT 4
#define BINARY_PAIR 8
#elif __riscv_ztt_uds == 64
#define BINARY_COUNT 2
#define BINARY_PAIR 4
#else
#define BINARY_COUNT 1
#define BINARY_PAIR 2
#endif

#define BINARY_(NAME, OP, RM, COUNT, SAME, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const binary_element *a, const binary_element *b, \
           binary_element *out, binary_element *left, binary_element *right) \
{ \
  __riscv_ztt_i32_##RM##_1x##COUNT##_t x \
    = __riscv_ztt_mls_rm_i32_##RM##_1x##COUNT (a); \
  __riscv_ztt_i32_##RM##_1x##COUNT##_t y \
    = SAME ? x : __riscv_ztt_mls_rm_i32_##RM##_1x##COUNT (b); \
  __riscv_ztt_i32_##RM##_1x##COUNT##_t z \
    = __riscv_ztt_m##OP##_ew_i32_##RM##_1x##COUNT (x, y); \
  BARRIER; \
  __riscv_ztt_mss_rm (out, z); \
  __riscv_ztt_mss_rm (left, x); \
  __riscv_ztt_mss_rm (right, y); \
}
#define BINARY(...) BINARY_ (__VA_ARGS__)
#define BINARY_OP(OP) \
  BINARY (binary_##OP, OP, rnu, BINARY_COUNT, 0, (void) 0)
BINARY_OP (add)
BINARY_OP (sub)
BINARY_OP (min)
BINARY_OP (max)
BINARY_OP (and)
BINARY_OP (andnot)
BINARY_OP (or)
BINARY_OP (ornot)
BINARY_OP (xor)
BINARY (binary_pair, add, rnu, BINARY_PAIR, 0, (void) 0)
BINARY (binary_same, add, rnu, BINARY_COUNT, 1, (void) 0)
BINARY (binary_rne, add, rne, BINARY_COUNT, 0, (void) 0)
BINARY (binary_rdn, add, rdn, BINARY_COUNT, 0, (void) 0)
BINARY (binary_rod, add, rod, BINARY_COUNT, 0, (void) 0)
BINARY (binary_asm, add, rnu, BINARY_COUNT, 0,
        __asm__ volatile ("" ::: "memory"))
BINARY (binary_call, add, rnu, BINARY_COUNT, 0, binary_callee ())
BINARY (binary_join, add, rnu, BINARY_COUNT, 0,
        if (binary_condition) __asm__ volatile ("" ::: "memory"))

#define BINARY_ACC_(COUNT) \
void binary_acc (const binary_element *a, const binary_element *b, \
                 binary_element *out, binary_element *left, binary_element *right) \
{ \
  __riscv_ztt_i32_1x##COUNT##_t x = __riscv_ztt_mls_rm_i32_1x##COUNT (a); \
  __riscv_ztt_i32_1x##COUNT##_t y = __riscv_ztt_mls_rm_i32_1x##COUNT (b); \
  __riscv_ztt_i32_accx##COUNT##_t z \
    = __riscv_ztt_mcopy_m2a_i32_accx##COUNT \
        (__riscv_ztt_madd_ew_i32_1x##COUNT (x, y)); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x##COUNT (z)); \
  __riscv_ztt_mss_rm (left, x); \
  __riscv_ztt_mss_rm (right, y); \
}
#define BINARY_ACC(COUNT) BINARY_ACC_ (COUNT)
BINARY_ACC (BINARY_COUNT)
#undef BINARY_ACC
#undef BINARY_ACC_
#undef BINARY_OP
#undef BINARY
#undef BINARY_
#undef BINARY_COUNT
#undef BINARY_PAIR
#ifdef __cplusplus
}
#endif
