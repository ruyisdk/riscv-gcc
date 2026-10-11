#include <riscv_ztt.h>

extern void shift_effect (void);

#define TEST(NAME, T, C, EXPR) \
void NAME##_##T (C *out, C *saved, const C *in, int offset, \
                volatile unsigned *effects) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  __riscv_ztt_##T##_1x1_t b = (EXPR); \
  __riscv_ztt_mss_rm (out, b); \
  __riscv_ztt_mss_rm (saved, a); \
}
#define TYPE(T, C) \
TEST (col_zero, T, C, __riscv_ztt_mcolshift_ew_x_##T##_1x1 (a, 0)) \
TEST (row_zero, T, C, __riscv_ztt_mrowshift_ew_x_##T##_1x1 (a, 0)) \
TEST (col_nonzero, T, C, __riscv_ztt_mcolshift_ew_x_##T##_1x1 (a, -1)) \
TEST (row_dynamic, T, C, __riscv_ztt_mrowshift_ew_x_##T##_1x1 (a, offset)) \
TEST (col_broadcast, T, C, __riscv_ztt_mcolbcast_ew_x_##T##_1x1 (a, 0)) \
TEST (row_broadcast, T, C, __riscv_ztt_mrowbcast_ew_x_##T##_1x1 (a, 0)) \
TEST (col_call, T, C, __riscv_ztt_mcolshift_ew_x_##T##_1x1 \
      (a, (shift_effect (), 0))) \
TEST (row_volatile, T, C, __riscv_ztt_mrowshift_ew_x_##T##_1x1 \
      (a, ((void) (*effects = *effects + 1), 0)))
#define RMS(T, C) \
TYPE (T##_rne, C) TYPE (T##_rtz, C) TYPE (T##_rdn, C) \
TYPE (T##_rup, C) TYPE (T##_rmm, C) TYPE (T##_rno, C) TYPE (T, C)
RMS (f16, _Float16)
RMS (bf16, __bf16)
RMS (f32, float)
RMS (f64, double)
#undef RMS
#undef TYPE
#undef TEST
