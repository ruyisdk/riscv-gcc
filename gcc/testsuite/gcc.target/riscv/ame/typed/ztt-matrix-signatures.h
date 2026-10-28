#include <riscv_ztt.h>

#ifdef __cplusplus
#define CHECK(A, B) static_assert (__is_same (__typeof__ (A), B), #A)
#else
#define CHECK(A, B) _Static_assert (__builtin_types_compatible_p \
  (__typeof__ (A), B), #A)
#endif

#define SIGNATURES(T, Q) \
typedef __riscv_ztt_##T##_##Q##_t T##_##Q##_m; \
typedef T##_##Q##_m T##_##Q##_unary (T##_##Q##_m); \
typedef T##_##Q##_m T##_##Q##_binary (T##_##Q##_m, T##_##Q##_m); \
typedef T##_##Q##_m T##_##Q##_ternary \
  (T##_##Q##_m, T##_##Q##_m, T##_##Q##_m); \
CHECK (__riscv_ztt_mcopy_m2m_##T##_##Q, T##_##Q##_unary); \
CHECK (__riscv_ztt_madd_ew_##T##_##Q, T##_##Q##_binary); \
CHECK (__riscv_ztt_mmulacc_ew_##T##_##Q, T##_##Q##_ternary)

SIGNATURES (i8_rnu, 1x1);
SIGNATURES (i16_rdn, 1x1);
SIGNATURES (u32_rod, 1x1);
SIGNATURES (i32_rnu, 1x1);
#ifdef MATRIX_RUNTIME
SIGNATURES (i16_rnu_sat, 2x1);
SIGNATURES (f32_rtz, 1x1);
#endif

void signature_use (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  i32_rnu_1x1_m a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  i32_rnu_1x1_m b = __riscv_ztt_mls_rm_i32_rnu_1x1 (in + 4);
  a = __riscv_ztt_mcopy_m2m_i32_rnu_1x1 (a);
  b = __riscv_ztt_madd_ew_i32_rnu_1x1 (a, b);
  a = __riscv_ztt_mmulacc_ew_i32_rnu_1x1 (a, a, b);
  __riscv_ztt_mss_rm (out, a);
}
