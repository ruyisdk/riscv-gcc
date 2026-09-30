/* Compile/assemble checks, not numerical execution evidence.  */
#include <riscv_ztt.h>
#if __riscv_ztt_wide_matmul_int != 63
#error missing wide integer matmul variants
#endif
#define TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define TYPE(T, S) TYPE_(T, S)
#define ZERO_M_(T, S) __riscv_ztt_mzero_m_##T##_##S ()
#define ZERO_M(T, S) ZERO_M_(T, S)
#define ZERO_A_(T, K) __riscv_ztt_mzero_acc_##T##_accx##K ()
#define ZERO_A(T, K) ZERO_A_(T, K)
#define MUL_(OP, D, K) __riscv_ztt_##OP##_2d_##D##_accx##K
#define MUL(OP, D, K) MUL_(OP, D, K)
#define KEEP_A(X) __asm__ volatile ("" : : "War" (X))
#define KEEP_M(X) __asm__ volatile ("" : : "Wmr" (X))
#define RUN(NAME, D, K, A, B, Q) \
void NAME (void) \
{ \
  TYPE(D, accx##K) old = ZERO_A(D, K); \
  TYPE(A, 1x##Q) ar = ZERO_M(A, 1x##Q); \
  TYPE(A, Q##x1) ac = ZERO_M(A, Q##x1); \
  TYPE(B, 1x##Q) br = ZERO_M(B, 1x##Q); \
  TYPE(B, Q##x1) bc = ZERO_M(B, Q##x1); \
  TYPE(D, accx##K) d = MUL(mmulacc, D, K) (old, ar, bc); \
  d = MUL(mmulaccneg, D, K) (d, ar, bc); \
  d = MUL(mmulatacc, D, K) (d, ar, br); \
  d = MUL(mmulataccneg, D, K) (d, ar, br); \
  d = MUL(mmulbtacc, D, K) (d, ar, br); \
  d = MUL(mmulbtaccneg, D, K) (d, ar, br); \
  d = MUL(mmulatacc, D, K) (d, ac, bc); \
  d = MUL(mmulataccneg, D, K) (d, ac, bc); \
  d = MUL(mmulbtacc, D, K) (d, ac, bc); \
  d = MUL(mmulbtaccneg, D, K) (d, ac, bc); \
  KEEP_A(d); KEEP_A(old); \
  KEEP_M(ar); KEEP_M(ac); KEEP_M(br); KEEP_M(bc); \
}
