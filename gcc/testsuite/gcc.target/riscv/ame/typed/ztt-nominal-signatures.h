#include <riscv_ztt.h>
#include <riscv_ztt.h>

#ifdef __cplusplus
#define CHECK(A, B) static_assert (__is_same (__typeof__ (A), B), #A)
#else
#define CHECK(A, B) _Static_assert (__builtin_types_compatible_p \
  (__typeof__ (A), B), #A)
#endif

#define SIGNATURES(D, Q, C) \
typedef __riscv_ztt_##D##_##Q##_t D##_##Q##_##C##_m; \
typedef __riscv_ztt_##C##_scalar_t D##_##Q##_##C##_s; \
typedef D##_##Q##_##C##_m D##_##Q##_##C##_bcast (D##_##Q##_##C##_s); \
typedef D##_##Q##_##C##_m D##_##Q##_##C##_binary \
  (D##_##Q##_##C##_m, D##_##Q##_##C##_s); \
typedef D##_##Q##_##C##_m D##_##Q##_##C##_ternary \
  (D##_##Q##_##C##_m, D##_##Q##_##C##_m, D##_##Q##_##C##_s); \
CHECK (__riscv_ztt_mbcast_m_x_##D##_##Q##_##C, D##_##Q##_##C##_bcast); \
CHECK (__riscv_ztt_madd_ew_x_##D##_##Q##_##C, D##_##Q##_##C##_binary); \
CHECK (__riscv_ztt_mmulacc_ew_x_##D##_##Q##_##C, D##_##Q##_##C##_ternary)

SIGNATURES (i32_rnu, 1x1, i8_rnu);
SIGNATURES (i32_rnu, 1x1, i8_rne);
SIGNATURES (i32_rnu, 1x2, i8_rnu);
SIGNATURES (u128_rod, 1x1, u128_rod);
SIGNATURES (f32_rtz, 1x1, bf16_rne);
SIGNATURES (f64_rmm, 1x1, f64_rne);

void nominal_signature_use (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
                            __INT8_TYPE__ input)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i8_rne_scalar_t s = __riscv_ztt_scalar_make_i8_rne (input);
  a = __riscv_ztt_madd_ew_x_i32_rnu_1x1_i8_rne (a, s);
  __riscv_ztt_mss_rm (out, a);
}
