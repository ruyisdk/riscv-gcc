#include <stdint.h>
#include <riscv_ztt.h>

#define TEST(OP, T, C) \
  void OP##_##T (C *out, const C *in, uint32_t index) \
  { \
    __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
    a = __riscv_ztt_##OP##_ew_x_##T##_1x1 (a, index); \
    __riscv_ztt_mss_rm (out, a); \
  }
TEST (mrowbcast, i32_rnu, int32_t)
TEST (mcolbcast, i32_rnu, int32_t)
TEST (mrowbcast, f32_rne, float)
TEST (mcolbcast, f32_rne, float)
