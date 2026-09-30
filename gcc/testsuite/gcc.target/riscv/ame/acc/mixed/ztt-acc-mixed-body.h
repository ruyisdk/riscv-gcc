/* Independent integer operands.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_acc_matmul_mixed != 63 && __riscv_ztt_acc_matmul_packed != 63
#error six mixed integer accumulation forms required
#endif
#define COUNT 8
#define TYPES(M, L, R, D, Q, K) \
  M (i##D##_rnu, int##D##_t, i##L##_rne, int##L##_t, u##R##_rdn, uint##R##_t, Q, K, 0) \
  M (i##D##_rne, int##D##_t, u##L##_rdn, uint##L##_t, i##R##_rod, int##R##_t, Q, K, 1) \
  M (i##D##_rdn, int##D##_t, i##L##_rod, int##L##_t, u##R##_rnu, uint##R##_t, Q, K, 2) \
  M (i##D##_rod, int##D##_t, u##L##_rnu, uint##L##_t, i##R##_rne, int##R##_t, Q, K, 3) \
  M (u##D##_rnu, uint##D##_t, u##L##_rne, uint##L##_t, i##R##_rdn, int##R##_t, Q, K, 4) \
  M (u##D##_rne, uint##D##_t, i##L##_rdn, int##L##_t, u##R##_rod, uint##R##_t, Q, K, 5) \
  M (u##D##_rdn, uint##D##_t, u##L##_rod, uint##L##_t, i##R##_rnu, int##R##_t, Q, K, 6) \
  M (u##D##_rod, uint##D##_t, i##L##_rnu, int##L##_t, u##R##_rne, uint##R##_t, Q, K, 7)
#define INIT(T, C, L, LC, R, RC, Q, K, I) \
  __riscv_ztt_##T##_accx##K##_t a##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx##K ( \
      __riscv_ztt_mls_rm_##T##_1x##K ((const C *) in[I])); \
  const LC *lp##I = (const LC *) in[(branch ? 3 : 1) * COUNT + I]; \
  const RC *rp##I = (const RC *) in[(branch ? 4 : 2) * COUNT + I]; \
  __riscv_ztt_##L##_1x##Q##_t lr##I \
    = __riscv_ztt_mls_rm_##L##_1x##Q (lp##I); \
  __riscv_ztt_##L##_##Q##x1_t lc##I \
    = __riscv_ztt_mls_rm_##L##_##Q##x1 (lp##I); \
  __riscv_ztt_##R##_1x##Q##_t rr##I \
    = __riscv_ztt_mls_rm_##R##_1x##Q (rp##I); \
  __riscv_ztt_##R##_##Q##x1_t rc##I \
    = __riscv_ztt_mls_rm_##R##_##Q##x1 (rp##I);
#define OP(T, C, K, I, NAME, J, L, R) \
  __riscv_ztt_mss_rm ((C *) out[COUNT * J + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K ( \
      __riscv_ztt_##NAME##_2d_##T##_accx##K (a##I, L, R)));
#define RUN(T, C, L, LC, R, RC, Q, K, I) \
  OP (T, C, K, I, mmulacc, 0, lr##I, rc##I) \
  OP (T, C, K, I, mmulaccneg, 1, lr##I, rc##I) \
  OP (T, C, K, I, mmulatacc, 2, lr##I, rr##I) \
  OP (T, C, K, I, mmulataccneg, 3, lr##I, rr##I) \
  OP (T, C, K, I, mmulatacc, 4, lc##I, rc##I) \
  OP (T, C, K, I, mmulataccneg, 5, lc##I, rc##I) \
  OP (T, C, K, I, mmulbtacc, 6, lr##I, rr##I) \
  OP (T, C, K, I, mmulbtaccneg, 7, lr##I, rr##I) \
  OP (T, C, K, I, mmulbtacc, 8, lc##I, rc##I) \
  OP (T, C, K, I, mmulbtaccneg, 9, lc##I, rc##I)
#define OLD(T, C, L, LC, R, RC, Q, K, I) \
  __riscv_ztt_mss_rm ((C *) out[10 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K (a##I)); \
  __riscv_ztt_mss_rm ((LC *) out[11 * COUNT + I], lr##I); \
  __riscv_ztt_mss_rm ((LC *) out[12 * COUNT + I], lc##I); \
  __riscv_ztt_mss_rm ((RC *) out[13 * COUNT + I], rr##I); \
  __riscv_ztt_mss_rm ((RC *) out[14 * COUNT + I], rc##I);
#define FUNCTION(F, L, R, D, Q, K) \
  void F (const void **in, void **out, int branch) \
  { TYPES (INIT, L, R, D, Q, K) \
    TYPES (RUN, L, R, D, Q, K) \
    TYPES (OLD, L, R, D, Q, K) }
#ifdef __cplusplus
extern "C" {
#endif
#ifdef TEST_LHS
FUNCTION (acc_mixed_kernel, TEST_LHS, TEST_RHS, TEST_DEST, TEST_Q, TEST_K)
#else
#include "ztt-acc-mixed-instances.h"
#endif
#ifdef __cplusplus
}
#endif
#undef FUNCTION
#undef OLD
#undef RUN
#undef OP
#undef INIT
#undef TYPES
#undef COUNT
