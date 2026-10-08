#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef __INT32_TYPE__ unary_element;
extern void binary_callee (void);
extern volatile int binary_condition;
#if __riscv_ztt_uds <= 32
#define UNARY_COUNT 1
#elif __riscv_ztt_uds == 64
#define UNARY_COUNT 2
#else
#define UNARY_COUNT 4
#endif
#define UNARY_(NAME, OP, RM, COUNT, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const unary_element *a, const unary_element *b, \
           unary_element *out, unary_element *left, unary_element *right) \
{ \
  __riscv_ztt_i32_rnu_1x##COUNT##_t x \
    = __riscv_ztt_mls_rm_i32_rnu_1x##COUNT (a); \
  __riscv_ztt_i32_rnu_1x##COUNT##_t y \
    = __riscv_ztt_mls_rm_i32_rnu_1x##COUNT (b); \
  __riscv_ztt_i32_##RM##_1x##COUNT##_t z \
    = __riscv_ztt_##OP##_i32_##RM##_1x##COUNT (x); \
  BARRIER; \
  __riscv_ztt_mss_rm (out, z); \
  __riscv_ztt_mss_rm (left, x); \
  __riscv_ztt_mss_rm (right, y); \
}
#define UNARY(...) UNARY_ (__VA_ARGS__)
UNARY (unary_convert_rnu, mconv_ew, rnu, UNARY_COUNT, (void) 0)
UNARY (unary_convert_rne, mconv_ew, rne, UNARY_COUNT, (void) 0)
UNARY (unary_convert_rdn, mconv_ew, rdn, UNARY_COUNT, (void) 0)
UNARY (unary_convert_rod, mconv_ew, rod, UNARY_COUNT, (void) 0)
UNARY (unary_abs, mabs_ew, rnu, UNARY_COUNT, (void) 0)
UNARY (unary_reduce, mreduceadd_row, rnu, UNARY_COUNT, (void) 0)
UNARY (unary_prefix, mprefixadd_col, rnu, UNARY_COUNT, (void) 0)
UNARY (unary_asm, mabs_ew, rnu, UNARY_COUNT,
       __asm__ volatile ("" ::: "memory"))
UNARY (unary_call, mabs_ew, rnu, UNARY_COUNT, binary_callee ())
UNARY (unary_join, mabs_ew, rnu, UNARY_COUNT,
       if (binary_condition) __asm__ volatile ("" ::: "memory"))
#if __riscv_ztt_uds <= 32
UNARY (unary_packets, mabs_ew, rnu, 2, (void) 0)
#endif
#undef UNARY
#undef UNARY_
#undef UNARY_COUNT
#ifdef __cplusplus
}
#endif
