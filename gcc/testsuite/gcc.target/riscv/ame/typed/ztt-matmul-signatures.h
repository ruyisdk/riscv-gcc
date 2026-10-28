#include <riscv_ztt.h>

#ifdef __cplusplus
#define CHECK(A, B) static_assert (__is_same (__typeof__ (A), B), #A)
#else
#define CHECK(A, B) _Static_assert (__builtin_types_compatible_p \
  (__typeof__ (A), B), #A)
#endif

#define SIGNATURES(T, Q) \
typedef __riscv_ztt_##T##_accx1_t T##_##Q##_acc; \
typedef __riscv_ztt_##T##_1x##Q##_t T##_##Q##_row; \
typedef __riscv_ztt_##T##_##Q##x1_t T##_##Q##_col; \
typedef T##_##Q##_acc T##_##Q##_rc \
  (T##_##Q##_acc, T##_##Q##_row, T##_##Q##_col); \
typedef T##_##Q##_acc T##_##Q##_rr \
  (T##_##Q##_acc, T##_##Q##_row, T##_##Q##_row); \
typedef T##_##Q##_acc T##_##Q##_cc \
  (T##_##Q##_acc, T##_##Q##_col, T##_##Q##_col); \
CHECK (__builtin_riscv_ztt_mmulacc_2d_##T##_accx1_q##Q##_RC, T##_##Q##_rc); \
CHECK (__builtin_riscv_ztt_mmulatacc_2d_##T##_accx1_q##Q##_RR, T##_##Q##_rr); \
CHECK (__builtin_riscv_ztt_mmulatacc_2d_##T##_accx1_q##Q##_CC, T##_##Q##_cc)

SIGNATURES (i32_rnu, 2);
SIGNATURES (i32_rnu, 4);
SIGNATURES (i16_rdn, 2);

void signature_use (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  __riscv_ztt_i32_rnu_1x2_t r = __riscv_ztt_mls_rm_i32_rnu_1x2 (in);
  __riscv_ztt_i32_rnu_2x1_t c = __riscv_ztt_mls_rm_i32_rnu_2x1 (in + 16);
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mzero_acc_i32_rnu_accx1 ();
  a = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (a, r, c);
  a = __riscv_ztt_mmulatacc_2d_i32_rnu_accx1 (a, r, r);
  a = __riscv_ztt_mmulbtacc_2d_i32_rnu_accx1 (a, c, c);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a));
}
