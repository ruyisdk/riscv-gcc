/* integer maximum.  */
#include <stdint.h>
#include <riscv_ztt.h>
#ifndef TEST_TYPE
#define TEST_TYPE i32_rdn
#define TEST_CARRIER int32_t
#if __riscv_ztt_uds == 8
#define TEST_SHAPE 1x1
#elif __riscv_ztt_uds == 16
#define TEST_SHAPE 1x2
#elif __riscv_ztt_uds == 32
#define TEST_SHAPE 1x4
#elif __riscv_ztt_uds == 64
#define TEST_SHAPE 1x8
#else
#define TEST_SHAPE 1x16
#endif
#endif
#define MAX_TYPE0(T, S) __riscv_ztt_##T##_##S##_t
#define MAX_TYPE(T, S) MAX_TYPE0(T, S)
#define MAX_OP0(OP, T, S) __riscv_ztt_##OP##_##T##_##S
#define MAX_OP1(OP, T, S) MAX_OP0(OP, T, S)
#define MAX_OP(OP) MAX_OP1(OP, TEST_TYPE, TEST_SHAPE)
#define LOAD_PAIR(I) \
  MAX_TYPE(TEST_TYPE, TEST_SHAPE) a##I = MAX_OP(mls_rm) (src[2 * I]); \
  MAX_TYPE(TEST_TYPE, TEST_SHAPE) b##I = MAX_OP(mls_rm) (src[2 * I + 1]);
#define MAX_PAIR(I) \
  MAX_TYPE(TEST_TYPE, TEST_SHAPE) r##I = MAX_OP(mmax_ew) (a##I, b##I);
#define ZERO_PAIR(I) a##I = MAX_OP(mzero_m) ();
#define STORE_PAIR(I) \
  __riscv_ztt_mss_rm (dst[3 * I], r##I); \
  __riscv_ztt_mss_rm (dst[3 * I + 1], a##I); \
  __riscv_ztt_mss_rm (dst[3 * I + 2], b##I);
#define ALL_PAIRS(OP) \
  OP(0) OP(1) OP(2) OP(3) OP(4) OP(5) OP(6) OP(7) OP(8) \
  OP(9) OP(10) OP(11) OP(12) OP(13) OP(14) OP(15) OP(16)
#ifdef __cplusplus
extern "C"
#endif
void max_kernel (const TEST_CARRIER *const *src, TEST_CARRIER *const *dst, int branch)
{
  ALL_PAIRS(LOAD_PAIR)
  ALL_PAIRS(MAX_PAIR)
  asm volatile ("" ::: "memory");
  if (branch)
    {
      ALL_PAIRS(ZERO_PAIR)
    }
  asm volatile ("" ::: "memory");
  ALL_PAIRS(STORE_PAIR)
}
#undef ALL_PAIRS
#undef STORE_PAIR
#undef ZERO_PAIR
#undef MAX_PAIR
#undef LOAD_PAIR
#undef MAX_OP
#undef MAX_OP1
#undef MAX_OP0
#undef MAX_TYPE
#undef MAX_TYPE0
