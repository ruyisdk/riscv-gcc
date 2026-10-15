#include <riscv_ztt.h>
#include <riscv_ztt.h>

#ifdef __cplusplus
#define CHECK(A, B) static_assert (__is_same (__typeof__ (A), B), #A)
#else
#define CHECK(A, B) _Static_assert (__builtin_types_compatible_p \
  (__typeof__ (A), B), #A)
#endif

#define SIGNATURES(T, C) \
typedef __riscv_ztt_##T##_1x1_t T##_m; \
typedef T##_m T##_zero (void); \
typedef T##_m T##_load (const C *); \
typedef T##_m T##_unary (T##_m); \
typedef T##_m T##_binary (T##_m, T##_m); \
typedef T##_m T##_index (T##_m, __SIZE_TYPE__); \
typedef T##_m T##_offset (T##_m, int); \
typedef T##_m T##_exponent (T##_m, long); \
CHECK (__riscv_ztt_mzero_m_##T##_1x1, T##_zero); \
CHECK (__riscv_ztt_mls_rm_##T##_1x1, T##_load); \
CHECK (__riscv_ztt_mcopy_m2m_##T##_1x1, T##_unary); \
CHECK (__riscv_ztt_madd_ew_##T##_1x1, T##_binary); \
CHECK (__riscv_ztt_mrowbcast_ew_x_##T##_1x1, T##_index); \
CHECK (__riscv_ztt_mrowshift_ew_x_##T##_1x1, T##_offset); \
CHECK (__riscv_ztt_mldexp_ew_x_##T##_1x1, T##_exponent)

SIGNATURES (i32_rnu, __INT32_TYPE__);
SIGNATURES (u32_rod, __UINT32_TYPE__);
SIGNATURES (f32_rtz, float);

typedef __riscv_ztt_i32_rnu_1x2_t pair_t;
typedef pair_t concat_t (i32_rnu_m, i32_rnu_m);
typedef i32_rnu_m extract_t (pair_t, __SIZE_TYPE__);
typedef __riscv_ztt_i32_rnu_accx1_t acc_t;
typedef acc_t acc_zero_t (void);
typedef acc_t from_m_t (i32_rnu_m);
typedef i32_rnu_m from_acc_t (acc_t);
CHECK (__riscv_ztt_mconcat_m_i32_rnu_1x2, concat_t);
CHECK (__riscv_ztt_mextract_i32_rnu_1x1, extract_t);
CHECK (__riscv_ztt_mzero_acc_i32_rnu_accx1, acc_zero_t);
CHECK (__riscv_ztt_mcopy_m2a_i32_rnu_accx1, from_m_t);
CHECK (__riscv_ztt_mcopy_a2m_i32_rnu_1x1, from_acc_t);

void signature_use (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  i32_rnu_m a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  a = __riscv_ztt_madd_ew_i32_rnu_1x1 (a, a);
  __riscv_ztt_mss_rm (out, a);
}
