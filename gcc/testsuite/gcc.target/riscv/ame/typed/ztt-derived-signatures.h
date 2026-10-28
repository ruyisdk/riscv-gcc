#include <riscv_ztt.h>

#ifdef __cplusplus
#define CHECK(A, B) static_assert (__is_same (__typeof__ (A), B), #A)
#else
#define CHECK(A, B) _Static_assert (__builtin_types_compatible_p \
  (__typeof__ (A), B), #A)
#endif

#define SIGNATURES(T) \
typedef __riscv_ztt_##T##_1x1_t T##_m; \
typedef __riscv_ztt_##T##_1x2_t T##_row; \
typedef __riscv_ztt_##T##_2x1_t T##_col; \
typedef __riscv_ztt_##T##_accx2_t T##_acc; \
typedef T##_m T##_exponent (T##_m, long); \
typedef T##_m T##_acc_exponent (T##_m, T##_m, long); \
typedef T##_row T##_to_row (T##_acc); \
typedef T##_col T##_to_col (T##_acc); \
CHECK (__riscv_ztt_mldexp_ew_x_##T##_1x1, T##_exponent); \
CHECK (__riscv_ztt_mldexpacc_ew_x_##T##_1x1, T##_acc_exponent); \
CHECK (__riscv_ztt_mcopy_a2m_##T##_1x2, T##_to_row); \
CHECK (__riscv_ztt_mcopy_a2m_##T##_2x1, T##_to_col)

SIGNATURES (i32_rnu);
SIGNATURES (u16_rdn);
SIGNATURES (f64_rne);

void
signature_use (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  i32_rnu_m a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  i32_rnu_m b = __riscv_ztt_mls_rm_i32_rnu_1x1 (in + 64);
  a = __riscv_ztt_mldexp_ew_x_i32_rnu_1x1 (a, -1L);
  b = __riscv_ztt_mldexpacc_ew_x_i32_rnu_1x1 (b, a, 2L);
  i32_rnu_row row = __riscv_ztt_mconcat_m_i32_rnu_1x2 (a, b);
  i32_rnu_acc acc = __riscv_ztt_mcopy_m2a_i32_rnu_accx2 (row);
  row = __riscv_ztt_mcopy_a2m_i32_rnu_1x2 (acc);
  i32_rnu_col col = __riscv_ztt_mcopy_a2m_i32_rnu_2x1 (acc);
  __riscv_ztt_mss_rm (out, row);
  __riscv_ztt_mss_rm (out + 128, col);
}
