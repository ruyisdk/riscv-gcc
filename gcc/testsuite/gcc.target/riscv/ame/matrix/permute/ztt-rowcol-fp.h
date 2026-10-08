#include <stddef.h>
#include <riscv_ztt.h>

#if __riscv_ztt_mcolbcast_ew_x_fp != 1 \
    || __riscv_ztt_mrowbcast_ew_x_fp != 1 \
    || __riscv_ztt_mcolshift_ew_x_fp != 1 \
    || __riscv_ztt_mrowshift_ew_x_fp != 1
#error missing floating row/column capabilities
#endif

#define TEST(OP, CONTROL, T, C) \
void OP##_##T (C *out, C *saved, const C *in, CONTROL control) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  __riscv_ztt_##T##_1x1_t b = __riscv_ztt_##OP##_ew_x_##T##_1x1 (a, control); \
  __riscv_ztt_mss_rm (out, b); \
  __riscv_ztt_mss_rm (saved, a); \
}
#define TYPE(T, C) \
  TEST (mcolbcast, size_t, T, C) \
  TEST (mrowbcast, size_t, T, C) \
  TEST (mcolshift, int, T, C) \
  TEST (mrowshift, int, T, C)
#define RMS(T, C) \
  TYPE (T##_rne, C) \
  TYPE (T##_rtz, C) \
  TYPE (T##_rdn, C) \
  TYPE (T##_rup, C) \
  TYPE (T##_rmm, C) \
  TYPE (T##_rno, C) \
  TYPE (T, C)

#if __riscv_ztt_uds <= 16
RMS (f16, _Float16)
RMS (bf16, __bf16)
#endif
#if __riscv_ztt_uds <= 32
RMS (f32, float)
#endif
RMS (f64, double)
