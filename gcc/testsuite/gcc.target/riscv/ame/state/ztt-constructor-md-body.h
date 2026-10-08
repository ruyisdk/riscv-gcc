#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef __INT32_TYPE__ ctor_element;
extern void binary_callee (void);
extern volatile int binary_condition;
#if __riscv_ztt_uds <= 32
#define CTOR_SHAPE 1
#define CTOR_PAIR 2
#elif __riscv_ztt_uds == 64
#define CTOR_SHAPE 2
#define CTOR_PAIR 4
#else
#define CTOR_SHAPE 4
#define CTOR_PAIR 8
#endif
#define BCAST_(NAME, RM, COUNT, BARRIER, RESULT) \
__attribute__((noinline, noclone)) \
void NAME (const ctor_element *a, const ctor_element *b, \
           ctor_element *out, ctor_element *left, ctor_element *right) \
{ \
  __riscv_ztt_i32_##RM##_1x##COUNT##_t y \
    = __riscv_ztt_mls_rm_i32_##RM##_1x##COUNT (b); \
  __riscv_ztt_i32_##RM##_1x##COUNT##_t x \
    = __riscv_ztt_mbcast_m_x_i32_##RM##_1x##COUNT##_i8_rdn \
      (__riscv_ztt_scalar_from_bits_i8_rdn ((unsigned long) a[0])); \
  BARRIER; \
  __riscv_ztt_i32_##RM##_1x##COUNT##_t z = RESULT; \
  __riscv_ztt_mss_rm (out, z); \
  __riscv_ztt_mss_rm (left, x); \
  __riscv_ztt_mss_rm (right, y); \
}
#define BCAST(...) BCAST_ (__VA_ARGS__)
#define SUM_(RM, COUNT) __riscv_ztt_madd_ew_i32_##RM##_1x##COUNT (x, y)
#define SUM(RM, COUNT) SUM_ (RM, COUNT)
BCAST (ctor_store, rnu, CTOR_SHAPE, (void) 0, x)
BCAST (ctor_binary, rnu, CTOR_SHAPE, (void) 0, SUM (rnu, CTOR_SHAPE))
BCAST (ctor_rne, rne, CTOR_SHAPE, (void) 0, SUM (rne, CTOR_SHAPE))
BCAST (ctor_rdn, rdn, CTOR_SHAPE, (void) 0, SUM (rdn, CTOR_SHAPE))
BCAST (ctor_rod, rod, CTOR_SHAPE, (void) 0, SUM (rod, CTOR_SHAPE))
BCAST (ctor_pair, rnu, CTOR_PAIR, (void) 0, SUM (rnu, CTOR_PAIR))
BCAST (ctor_asm, rnu, CTOR_SHAPE,
       __asm__ volatile ("" ::: "memory"), SUM (rnu, CTOR_SHAPE))
BCAST (ctor_call, rnu, CTOR_SHAPE, binary_callee (), SUM (rnu, CTOR_SHAPE))
BCAST (ctor_join, rnu, CTOR_SHAPE,
       if (binary_condition) __asm__ volatile ("" ::: "memory"),
       SUM (rnu, CTOR_SHAPE))
#if __riscv_ztt_uds <= 32
BCAST (ctor_acc, rnu, 1, (void) 0,
       __riscv_ztt_mcopy_a2m_i32_1x1 (__riscv_ztt_mcopy_m2a_i32_accx1 (x)))
#define INDICES(RM) \
__attribute__((noinline, noclone)) \
void ctor_indices_##RM (const ctor_element *a, const ctor_element *b, \
                       ctor_element *out, ctor_element *left, ctor_element *right) \
{ \
  __riscv_ztt_i32_##RM##_1x1_t x = __riscv_ztt_mrowid_ew_i32_##RM##_1x1 (); \
  __riscv_ztt_i32_##RM##_1x1_t y = __riscv_ztt_mcolid_ew_i32_##RM##_1x1 (); \
  __riscv_ztt_i32_##RM##_1x1_t z = __riscv_ztt_madd_ew_i32_##RM##_1x1 (x, y); \
  __riscv_ztt_mss_rm (out, z); \
  __riscv_ztt_mss_rm (left, x); \
  __riscv_ztt_mss_rm (right, y); \
}
INDICES(rnu)
INDICES(rne)
INDICES(rdn)
INDICES(rod)
#undef INDICES
#endif
#undef SUM
#undef SUM_
#undef BCAST
#undef BCAST_
#undef CTOR_SHAPE
#undef CTOR_PAIR
#ifdef __cplusplus
}
#endif
