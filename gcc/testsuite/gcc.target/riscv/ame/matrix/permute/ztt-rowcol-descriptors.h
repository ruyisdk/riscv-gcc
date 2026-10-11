#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void rowcol_callee (void);
extern volatile int rowcol_condition;

#define CHAIN(NAME, T, C, OP, BARRIER) \
void NAME (const C *in, C *out, int index, int other) \
{ \
  __riscv_ztt_##T##_1x1_t a = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  a = __riscv_ztt_##OP##_##T##_1x1 (a, index); \
  BARRIER; \
  a = __riscv_ztt_madd_ew_##T##_1x1 (a, a); \
  a = __riscv_ztt_##OP##_##T##_1x1 (a, other); \
  __riscv_ztt_mss_rm (out, a); \
}
#define TEST(NAME, T, C, OP) CHAIN (NAME, T, C, OP, (void) 0)
TEST (row, i32_rnu, __INT32_TYPE__, mrowbcast_ew_x)
TEST (column, i32_rnu, __INT32_TYPE__, mcolbcast_ew_x)
TEST (shift_row, i32_rnu, __INT32_TYPE__, mrowshift_ew_x)
TEST (shift_column, i32_rnu, __INT32_TYPE__, mcolshift_ew_x)
TEST (fp_row, f32_rne, float, mrowbcast_ew_x)
TEST (fp_column, f32_rne, float, mcolbcast_ew_x)
TEST (fp_shift_row, f32_rne, float, mrowshift_ew_x)
TEST (fp_shift_column, f32_rne, float, mcolshift_ew_x)
TEST (integer_rne, i32_rne, __INT32_TYPE__, mrowbcast_ew_x)
TEST (integer_rdn, i32_rdn, __INT32_TYPE__, mrowbcast_ew_x)
TEST (integer_rod, i32_rod, __INT32_TYPE__, mrowbcast_ew_x)
CHAIN (call_boundary, i32_rnu, __INT32_TYPE__, mrowbcast_ew_x,
       rowcol_callee ())
CHAIN (asm_boundary, i32_rnu, __INT32_TYPE__, mrowbcast_ew_x,
       __asm__ volatile ("" ::: "memory"))
CHAIN (join_boundary, i32_rnu, __INT32_TYPE__, mrowbcast_ew_x,
       if (rowcol_condition) rowcol_callee ())

void simple (const __INT32_TYPE__ *in, __INT32_TYPE__ *out, int index)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  a = __riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1 (a, index);
  __riscv_ztt_mss_rm (out, a);
}
#undef TEST
#undef CHAIN
#ifdef __cplusplus
}
#endif
