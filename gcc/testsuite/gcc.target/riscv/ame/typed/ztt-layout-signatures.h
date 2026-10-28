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
typedef __riscv_ztt_##T##_accx1_t T##_acc; \
typedef void T##_store (C *, T##_m); \
typedef void T##_stride (C *, __SIZE_TYPE__, T##_m); \
typedef T##_row T##_concat_r (T##_m, T##_m); \
typedef T##_col T##_concat_c (T##_m, T##_m); \
typedef T##_acc T##_to_acc (T##_m); \
typedef T##_m T##_from_acc (T##_acc); \
CHECK (__riscv_ztt_mss_rm_##T##_1x1, T##_store); \
CHECK (__riscv_ztt_mss_cm_##T##_1x1, T##_store); \
CHECK (__riscv_ztt_mss_st_##T##_1x1, T##_stride); \
CHECK (__riscv_ztt_mss_tst_##T##_1x1, T##_stride); \
CHECK (__riscv_ztt_mconcat_m_##T##_1x2, T##_concat_r); \
CHECK (__riscv_ztt_mconcat_m_##T##_2x1, T##_concat_c); \
CHECK (__riscv_ztt_mcopy_m2a_##T##_accx1, T##_to_acc); \
CHECK (__riscv_ztt_mcopy_a2m_##T##_1x1, T##_from_acc)

SIGNATURES (i32_rnu, __INT32_TYPE__);
SIGNATURES (u16_rdn, __UINT16_TYPE__);
SIGNATURES (f32_rtz, float);

void signature_use (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  i32_rnu_m a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  i32_rnu_m b = __riscv_ztt_mls_rm_i32_rnu_1x1 (in + 64);
  i32_rnu_row r = __riscv_ztt_mconcat_m_i32_rnu_1x2 (a, b);
  i32_rnu_col c = __riscv_ztt_mconcat_m_i32_rnu_2x1 (b, a);
  __riscv_ztt_mss_rm (out, r);
  __riscv_ztt_mss_cm (out + 128, c);
  i32_rnu_acc acc = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (a);
  a = __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (acc);
  __riscv_ztt_mss_st_i32_rnu_1x1 (out + 256, 32, a);
  __riscv_ztt_mss_tst_i32_rnu_1x1 (out + 384, 32, b);
}
