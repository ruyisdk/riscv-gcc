#include <riscv_ztt.h>

#ifdef __cplusplus
#define CHECK(A, B) static_assert (__is_same (__typeof__ (A), B), #A)
#else
#define CHECK(A, B) _Static_assert (__builtin_types_compatible_p \
  (__typeof__ (A), B), #A)
#endif

#define SIGNATURES(T, C) \
typedef __riscv_ztt_##T##_1x1_t T##_m; \
typedef __riscv_ztt_##T##_1x2_t T##_row; \
typedef __riscv_ztt_##T##_2x1_t T##_col; \
typedef T##_m T##_load (const C *, __SIZE_TYPE__); \
typedef T##_m T##_index (T##_m, __SIZE_TYPE__); \
typedef T##_m T##_offset (T##_m, int); \
typedef T##_m T##_exponent (T##_m, long); \
typedef T##_m T##_acc_exponent (T##_m, T##_m, long); \
typedef T##_m T##_extract_r (T##_row, __SIZE_TYPE__); \
typedef T##_m T##_extract_c (T##_col, __SIZE_TYPE__); \
CHECK (__riscv_ztt_mls_st_##T##_1x1, T##_load); \
CHECK (__riscv_ztt_mls_tst_##T##_1x1, T##_load); \
CHECK (__riscv_ztt_mrowbcast_ew_x_##T##_1x1, T##_index); \
CHECK (__riscv_ztt_mcolbcast_ew_x_##T##_1x1, T##_index); \
CHECK (__riscv_ztt_mrowshift_ew_x_##T##_1x1, T##_offset); \
CHECK (__riscv_ztt_mcolshift_ew_x_##T##_1x1, T##_offset); \
CHECK (__riscv_ztt_mldexp_ew_x_##T##_1x1, T##_exponent); \
CHECK (__riscv_ztt_mldexpacc_ew_x_##T##_1x1, T##_acc_exponent); \
CHECK (__riscv_ztt_mextract_##T##_1x1, T##_extract_r); \
CHECK (__builtin_riscv_ztt_mextract_column_##T##_1x1, T##_extract_c)

SIGNATURES (i32_rnu, __INT32_TYPE__);
SIGNATURES (u16_rdn, __UINT16_TYPE__);
SIGNATURES (f32_rtz, float);
SIGNATURES (f64_rne, double);

void
control_use (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
             __SIZE_TYPE__ stride, __SIZE_TYPE__ index, int offset, long exponent)
{
  i32_rnu_m a = __riscv_ztt_mls_st_i32_rnu_1x1 (in, stride);
  i32_rnu_m b = __riscv_ztt_mls_tst_i32_rnu_1x1 (in + 64, stride);
  i32_rnu_row row = __riscv_ztt_mconcat_m_i32_rnu_1x2 (a, b);
  i32_rnu_col col = __riscv_ztt_mconcat_m_i32_rnu_2x1 (a, b);
  a = __riscv_ztt_mextract_i32_rnu_1x1 (row, 0);
  b = __builtin_riscv_ztt_mextract_column_i32_rnu_1x1 (col, 1);
  a = __riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1 (a, index);
  b = __riscv_ztt_mcolshift_ew_x_i32_rnu_1x1 (b, offset);
  a = __riscv_ztt_mldexp_ew_x_i32_rnu_1x1 (a, exponent);
  b = __riscv_ztt_mldexpacc_ew_x_i32_rnu_1x1 (b, a, exponent);
  __riscv_ztt_mss_rm (out, b);
}

void signature_use (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  control_use (out, in, 32, 1, -1, 2);
}
