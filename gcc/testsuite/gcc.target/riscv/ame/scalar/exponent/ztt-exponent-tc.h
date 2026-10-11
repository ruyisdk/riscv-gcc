#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TEST_EXP(T, C) \
void exp_ready_##T (const C *a, C *out, long e) \
{ \
  __riscv_ztt_##T##_t x = __riscv_ztt_mls_rm_##T (a); \
  x = __riscv_ztt_mldexpacc_ew_x_##T (x, x, e); \
  __riscv_ztt_mss_rm (out, x); \
} \
void exp_unknown_##T (const C *a, C *out, volatile long *e) \
{ \
  __riscv_ztt_##T##_t x = __riscv_ztt_mls_rm_##T (a); \
  __asm__ volatile ("" ::: "memory"); \
  x = __riscv_ztt_mldexpacc_ew_x_##T (x, x, *e); \
  __riscv_ztt_mss_rm (out, x); \
}

TEST_EXP (i32_rnu_1x1, __INT32_TYPE__)
TEST_EXP (i32_rnu_sat_1x1, __INT32_TYPE__)
TEST_EXP (i64_rnu_1x1, __INT64_TYPE__)
TEST_EXP (i128_rnu_1x1, __riscv_ztt_i128_storage_t)
TEST_EXP (bf16_rne_1x2, __bf16)
TEST_EXP (f32_rne_1x1, float)
TEST_EXP (f64_rne_1x1, double)
#undef TEST_EXP

#define TEST_DATA(OP, T, C) \
void data_##OP##_##T (const __UINT32_TYPE__ *a, const __UINT32_TYPE__ *b, \
                     __UINT32_TYPE__ *out, C scalar) \
{ \
  __riscv_ztt_u32_rnu_1x1_t x = __riscv_ztt_mls_rm_u32_rnu_1x1 (a); \
  __riscv_ztt_u32_rnu_1x1_t y = __riscv_ztt_mls_rm_u32_rnu_1x1 (b); \
  x = __riscv_ztt_##OP##_ew_x_u32_rnu_1x1_##T \
    (x, y, __riscv_ztt_scalar_make_##T (scalar)); \
  __riscv_ztt_mss_rm (out, x); \
}
#define TEST_DATA_TYPES(OP) \
  TEST_DATA (OP, i32_rnu, __INT32_TYPE__) \
  TEST_DATA (OP, f32_rne, float)
TEST_DATA_TYPES (mmulacc)
TEST_DATA_TYPES (mmulaccneg)
TEST_DATA_TYPES (mmuladd)
TEST_DATA_TYPES (mmulsub)
#undef TEST_DATA_TYPES
#undef TEST_DATA

#ifdef __cplusplus
}
#endif
