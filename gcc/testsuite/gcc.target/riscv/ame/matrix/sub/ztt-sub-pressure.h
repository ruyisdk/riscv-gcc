/* integer subtraction.  */
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
#define SUB_TYPE0(T, S) __riscv_ztt_##T##_##S##_t
#define SUB_TYPE(T, S) SUB_TYPE0(T, S)
#define SUB_OP0(OP, T, S) __riscv_ztt_##OP##_##T##_##S
#define SUB_OP1(OP, T, S) SUB_OP0(OP, T, S)
#define SUB_OP(OP) SUB_OP1(OP, TEST_TYPE, TEST_SHAPE)
#define LOAD_PAIR(I) \
  SUB_TYPE(TEST_TYPE, TEST_SHAPE) a##I = SUB_OP(mls_rm) (src[2 * I]); \
  SUB_TYPE(TEST_TYPE, TEST_SHAPE) b##I = SUB_OP(mls_rm) (src[2 * I + 1]);
#define SUB_PAIR(I) \
  SUB_TYPE(TEST_TYPE, TEST_SHAPE) r##I = SUB_OP(msub_ew) (a##I, b##I);
#define ZERO_PAIR(I) a##I = SUB_OP(mzero_m) ();
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
void sub_kernel (const TEST_CARRIER *const *src, TEST_CARRIER *const *dst, int branch)
{
  ALL_PAIRS(LOAD_PAIR)
  ALL_PAIRS(SUB_PAIR)
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
#undef SUB_PAIR
#undef LOAD_PAIR
#undef SUB_OP
#undef SUB_OP1
#undef SUB_OP0
#undef SUB_TYPE
#undef SUB_TYPE0
