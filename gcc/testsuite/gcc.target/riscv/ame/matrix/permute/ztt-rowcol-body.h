/* basic squares.  */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_mcolbcast_ew_x_int != 1 \
    || __riscv_ztt_mrowbcast_ew_x_int != 1 \
    || __riscv_ztt_mcolshift_ew_x_int != 1 \
    || __riscv_ztt_mrowshift_ew_x_int != 1
#error missing row/column capabilities
#endif

#define TEST(OP, CONTROL, T, C, RM) \
  void OP##_##T##_##RM (C *out, C *saved, const C *in, CONTROL control) \
  { \
    __riscv_ztt_##T##_##RM##_1x1_t a \
      = __riscv_ztt_mls_rm_##T##_##RM##_1x1 (in); \
    __riscv_ztt_##T##_##RM##_1x1_t b \
      = __riscv_ztt_##OP##_ew_x_##T##_##RM##_1x1 (a, control); \
    __riscv_ztt_mss_rm (out, b); \
    __riscv_ztt_mss_rm (saved, a); \
  }
#define RMS(OP, CONTROL, T, C) \
  TEST (OP, CONTROL, T, C, rnu) \
  TEST (OP, CONTROL, T, C, rne) \
  TEST (OP, CONTROL, T, C, rdn) \
  TEST (OP, CONTROL, T, C, rod)
#define TYPE(T, C) \
  RMS (mcolbcast, size_t, T, C) \
  RMS (mrowbcast, size_t, T, C) \
  RMS (mcolshift, int, T, C) \
  RMS (mrowshift, int, T, C)
#if __riscv_ztt_uds <= 8
TYPE (i8, int8_t)
TYPE (u8, uint8_t)
#endif
#if __riscv_ztt_uds <= 16
TYPE (i16, int16_t)
TYPE (u16, uint16_t)
#endif
TYPE (i32, int32_t)
TYPE (u32, uint32_t)

#define DEFAULT(OP, CONTROL) \
  void OP##_default (int32_t *out, const int32_t *in, CONTROL control) \
  { \
    __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in); \
    __riscv_ztt_i32_1x1_t b = __riscv_ztt_##OP##_ew_x_i32_1x1 (a, control); \
    __riscv_ztt_mss_rm (out, b); \
  }
DEFAULT (mcolbcast, size_t)
DEFAULT (mrowbcast, size_t)
DEFAULT (mcolshift, int)
DEFAULT (mrowshift, int)

#ifdef __cplusplus
#define SAME(A, B) __is_same (__typeof__ (A), __typeof__ (B))
#define CHECK(C) static_assert (C, "row/column signature")
#else
#define SAME(A, B) __builtin_types_compatible_p (__typeof__ (A), __typeof__ (B))
#define CHECK(C) _Static_assert (C, "row/column signature")
#endif
CHECK (SAME (__riscv_ztt_mcolbcast_ew_x_i32_1x1,
             __riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1));
CHECK (SAME (__riscv_ztt_mcolshift_ew_x_i32_1x1,
             __riscv_ztt_mrowshift_ew_x_i32_rnu_1x1));
CHECK (!SAME (__riscv_ztt_mcolbcast_ew_x_i32_1x1,
              __riscv_ztt_mcolshift_ew_x_i32_1x1));
CHECK (!SAME (__riscv_ztt_mcolbcast_ew_x_i32_rnu_1x1,
              __riscv_ztt_mcolbcast_ew_x_i32_rne_1x1));
