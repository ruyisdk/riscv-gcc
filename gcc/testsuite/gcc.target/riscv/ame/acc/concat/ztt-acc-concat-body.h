/* Same-type source concatenation.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_acc_matmul_concat != 63
#error six concatenated accumulation forms required
#endif
#define TYPES(M, D, C, U, Q, K) \
  M (i##D##_rnu, C, Q, K, 0) M (i##D##_rne, C, Q, K, 1) \
  M (i##D##_rdn, C, Q, K, 2) M (i##D##_rod, C, Q, K, 3) \
  M (u##D##_rnu, U, Q, K, 4) M (u##D##_rne, U, Q, K, 5) \
  M (u##D##_rdn, U, Q, K, 6) M (u##D##_rod, U, Q, K, 7)
#define COUNT 8
#ifdef SINGLE_I8
#undef TYPES
#undef COUNT
#define TYPES(M, D, C, U, Q, K) M (i8_rnu, int8_t, Q, K, 0)
#define COUNT 1
#endif
#define INIT(T, C, Q, K, I) \
  __riscv_ztt_##T##_accx##K##_t a##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx##K ( \
      __riscv_ztt_mls_rm_##T##_1x##K ((const C *) in[I])); \
  __riscv_ztt_##T##_1x##Q##_t lr##I \
    = __riscv_ztt_mls_rm_##T##_1x##Q ((const C *) in[COUNT + I]); \
  __riscv_ztt_##T##_##Q##x1_t lc##I \
    = __riscv_ztt_mls_rm_##T##_##Q##x1 ((const C *) in[COUNT + I]); \
  __riscv_ztt_##T##_1x##Q##_t rr##I \
    = __riscv_ztt_mls_rm_##T##_1x##Q ((const C *) in[2 * COUNT + I]); \
  __riscv_ztt_##T##_##Q##x1_t rc##I \
    = __riscv_ztt_mls_rm_##T##_##Q##x1 ((const C *) in[2 * COUNT + I]); \
  __riscv_ztt_##T##_accx1_t one##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx1 ( \
      __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[COUNT + I]));
#define OP(T, C, K, I, NAME, J, L, R) \
  __riscv_ztt_mss_rm ((C *) out[COUNT * J + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K ( \
      __riscv_ztt_##NAME##_2d_##T##_accx##K (a##I, L, R)));
#define RUN(T, C, Q, K, I) \
  OP (T, C, K, I, mmulacc, 0, branch ? rr##I : lr##I, branch ? lc##I : rc##I) \
  OP (T, C, K, I, mmulaccneg, 1, branch ? rr##I : lr##I, branch ? lc##I : rc##I) \
  OP (T, C, K, I, mmulatacc, 2, branch ? rr##I : lr##I, branch ? lr##I : rr##I) \
  OP (T, C, K, I, mmulataccneg, 3, branch ? rr##I : lr##I, branch ? lr##I : rr##I) \
  OP (T, C, K, I, mmulatacc, 4, branch ? rc##I : lc##I, branch ? lc##I : rc##I) \
  OP (T, C, K, I, mmulataccneg, 5, branch ? rc##I : lc##I, branch ? lc##I : rc##I) \
  OP (T, C, K, I, mmulbtacc, 6, branch ? rr##I : lr##I, branch ? lr##I : rr##I) \
  OP (T, C, K, I, mmulbtaccneg, 7, branch ? rr##I : lr##I, branch ? lr##I : rr##I) \
  OP (T, C, K, I, mmulbtacc, 8, branch ? rc##I : lc##I, branch ? lc##I : rc##I) \
  OP (T, C, K, I, mmulbtaccneg, 9, branch ? rc##I : lc##I, branch ? lc##I : rc##I)
#define OLD(T, C, Q, K, I) \
  __riscv_ztt_mss_rm ((C *) out[10 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K (a##I)); \
  __riscv_ztt_mss_rm ((C *) out[11 * COUNT + I], lr##I); \
  __riscv_ztt_mss_rm ((C *) out[12 * COUNT + I], lc##I); \
  __riscv_ztt_mss_rm ((C *) out[13 * COUNT + I], rr##I); \
  __riscv_ztt_mss_rm ((C *) out[14 * COUNT + I], rc##I); \
  __riscv_ztt_mss_rm ((C *) out[15 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x1 (one##I));
#ifdef TEST_NO_BRANCH
#define FIX_BRANCH branch = 0;
#else
#define FIX_BRANCH
#endif
#define FUNCTION(F, D, C, U, Q, K) \
  void F (const void **in, void **out, int branch) \
  { FIX_BRANCH TYPES (INIT, D, C, U, Q, K) \
    TYPES (RUN, D, C, U, Q, K) \
    TYPES (OLD, D, C, U, Q, K) }
#if __riscv_ztt_uds == 8
#define PRIMARY(F, Q, K) FUNCTION (F, 8, int8_t, uint8_t, Q, K)
#define SECONDARY(F, Q, K) FUNCTION (F, 16, int16_t, uint16_t, Q, K)
#elif __riscv_ztt_uds == 16
#define PRIMARY(F, Q, K) FUNCTION (F, 16, int16_t, uint16_t, Q, K)
#define SECONDARY(F, Q, K) FUNCTION (F, 32, int32_t, uint32_t, Q, K)
#else
#define PRIMARY(F, Q, K) FUNCTION (F, 32, int32_t, uint32_t, Q, K)
#endif
#ifdef __cplusplus
extern "C" {
#endif
#ifdef TEST_Q
#if TEST_FACTOR == 1
PRIMARY (acc_concat_kernel, TEST_Q, TEST_K)
#else
SECONDARY (acc_concat_kernel, TEST_Q, TEST_K)
#endif
#else
PRIMARY (acc_concat_d1_q2_k1, 2, 1)
PRIMARY (acc_concat_d1_q4_k1, 4, 1)
#if __riscv_ztt_accregs >= 2
PRIMARY (acc_concat_d1_q2_k2, 2, 2)
PRIMARY (acc_concat_d1_q4_k2, 4, 2)
#endif
#if __riscv_ztt_accregs >= 4
PRIMARY (acc_concat_d1_q2_k4, 2, 4)
PRIMARY (acc_concat_d1_q4_k4, 4, 4)
#endif
#if __riscv_ztt_uds < 32
SECONDARY (acc_concat_d2_q2_k1, 2, 1)
#if __riscv_ztt_accregs >= 2
SECONDARY (acc_concat_d2_q2_k2, 2, 2)
#endif
#endif
#endif
#ifdef __cplusplus
}
#endif
#undef SECONDARY
#undef PRIMARY
#undef FUNCTION
#undef FIX_BRANCH
#undef OLD
#undef RUN
#undef OP
#undef INIT
#undef COUNT
#undef TYPES
