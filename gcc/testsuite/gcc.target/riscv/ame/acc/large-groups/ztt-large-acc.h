/* Complete ACC images and
   bounded transfers, not numerical or original AME execution evidence.  */
#include <riscv_ztt.h>
#define TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define TYPE(T, S) TYPE_(T, S)
#define ZERO_A_(T, K) __riscv_ztt_mzero_acc_##T##_accx##K ()
#define ZERO_A(T, K) ZERO_A_(T, K)
#define CLEAR_A_(T, K) __riscv_ztt_mclear_acc_##T##_accx##K ()
#define CLEAR_A(T, K) CLEAR_A_(T, K)
#define ZERO_M_(T, S) __riscv_ztt_mzero_m_##T##_##S ()
#define ZERO_M(T, S) ZERO_M_(T, S)
#define FROM_(T, K, X) __riscv_ztt_mcopy_m2a_##T##_accx##K (X)
#define FROM(T, K, X) FROM_(T, K, X)
#define TO_(T, S, X) __riscv_ztt_mcopy_a2m_##T##_##S (X)
#define TO(T, S, X) TO_(T, S, X)
#define MUL_(OP, T, K, D, A, B) __riscv_ztt_##OP##_2d_##T##_accx##K (D, A, B)
#define MUL(OP, T, K, D, A, B) MUL_(OP, T, K, D, A, B)
#define KEEP_A(X) __asm__ volatile ("" : : "War" (X))
#define KEEP_M(X) __asm__ volatile ("" : : "Wmr" (X))

#define VALUE(T, K) \
void value_##T##_accx##K (int branch) \
{ \
  TYPE(T, accx##K) a = ZERO_A(T, K); \
  TYPE(T, accx##K) saved = a; \
  __asm__ volatile ("" : "+War" (a)); \
  KEEP_A(saved); \
  TYPE(T, accx##K) merged = branch ? a : saved; \
  a = CLEAR_A(T, K); \
  KEEP_A(a); KEEP_A(merged); KEEP_A(saved); \
}

#define MOVE(T, K) \
void move_##T##_accx##K (void) \
{ \
  TYPE(T, 1x##K) m = ZERO_M(T, 1x##K); \
  TYPE(T, accx##K) a = FROM(T, K, m); \
  TYPE(T, 1x##K) back = TO(T, 1x##K, a); \
  KEEP_M(back); KEEP_A(a); KEEP_M(m); \
}

#define MATMUL(T, K, S) \
void matmul_##T##_accx##K (void) \
{ \
  TYPE(T, accx##K) old = ZERO_A(T, K); \
  TYPE(S, 1x1) a = ZERO_M(S, 1x1); \
  TYPE(S, 1x1) b = ZERO_M(S, 1x1); \
  TYPE(T, accx##K) d = MUL(mmulacc, T, K, old, a, b); \
  d = MUL(mmulaccneg, T, K, d, a, b); \
  d = MUL(mmulatacc, T, K, d, a, b); \
  d = MUL(mmulataccneg, T, K, d, a, b); \
  d = MUL(mmulbtacc, T, K, d, a, b); \
  d = MUL(mmulbtaccneg, T, K, d, a, b); \
  KEEP_A(d); KEEP_A(old); KEEP_M(a); KEEP_M(b); \
}

#if TEST_UDS == 8
#if TEST_A >= 1
VALUE (i8_rnu, 1)
MATMUL (i8_rnu, 1, i8_rnu)
#if TEST_M >= 1
MOVE (i8_rnu, 1)
#endif
#endif
#if TEST_A >= 1
VALUE (u16_rne, 1)
MATMUL (u16_rne, 1, i8_rnu)
#if TEST_M >= 2
MOVE (u16_rne, 1)
#endif
#endif
#if TEST_A >= 1
VALUE (i32_rdn, 1)
MATMUL (i32_rdn, 1, i8_rnu)
#if TEST_M >= 4
MOVE (i32_rdn, 1)
#endif
#endif
#if TEST_A >= 2
VALUE (i8_rnu, 2)
MATMUL (i8_rnu, 2, i8_rnu)
#if TEST_M >= 2
MOVE (i8_rnu, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i8_rnu, 4)
MATMUL (i8_rnu, 4, i8_rnu)
#if TEST_M >= 4
MOVE (i8_rnu, 4)
#endif
#endif
#if TEST_A >= 2
VALUE (u16_rne, 2)
MATMUL (u16_rne, 2, i8_rnu)
#if TEST_M >= 4
MOVE (u16_rne, 2)
#endif
#endif
#if TEST_A >= 2
VALUE (i4_rne, 2)
MATMUL (i4_rne, 2, i8_rnu)
#if TEST_M >= 1
MOVE (i4_rne, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i4_rne, 4)
MATMUL (i4_rne, 4, i8_rnu)
#if TEST_M >= 2
MOVE (i4_rne, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (i4_rne, 8)
MATMUL (i4_rne, 8, i8_rnu)
#if TEST_M >= 4
MOVE (i4_rne, 8)
#endif
#endif
#if TEST_A >= 8
VALUE (i8_rnu, 8)
MATMUL (i8_rnu, 8, i8_rnu)
#if TEST_M >= 8
MOVE (i8_rnu, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i8_rnu, 16)
MATMUL (i8_rnu, 16, i8_rnu)
#if TEST_M >= 16
MOVE (i8_rnu, 16)
#endif
#endif
#if TEST_A >= 4
VALUE (u16_rne, 4)
MATMUL (u16_rne, 4, i8_rnu)
#if TEST_M >= 8
MOVE (u16_rne, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (u16_rne, 8)
MATMUL (u16_rne, 8, i8_rnu)
#if TEST_M >= 16
MOVE (u16_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (u16_rne, 16)
MATMUL (u16_rne, 16, i8_rnu)
#if TEST_M >= 32
MOVE (u16_rne, 16)
#endif
#endif
#if TEST_A >= 2
VALUE (i32_rdn, 2)
MATMUL (i32_rdn, 2, i8_rnu)
#if TEST_M >= 8
MOVE (i32_rdn, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i32_rdn, 4)
MATMUL (i32_rdn, 4, i8_rnu)
#if TEST_M >= 16
MOVE (i32_rdn, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (i32_rdn, 8)
MATMUL (i32_rdn, 8, i8_rnu)
#if TEST_M >= 32
MOVE (i32_rdn, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i32_rdn, 16)
MATMUL (i32_rdn, 16, i8_rnu)
#if TEST_M >= 64
MOVE (i32_rdn, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (u64_rod, 1)
MATMUL (u64_rod, 1, i8_rnu)
#if TEST_M >= 8
MOVE (u64_rod, 1)
#endif
#endif
#if TEST_A >= 2
VALUE (u64_rod, 2)
MATMUL (u64_rod, 2, i8_rnu)
#if TEST_M >= 16
MOVE (u64_rod, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (u64_rod, 4)
MATMUL (u64_rod, 4, i8_rnu)
#if TEST_M >= 32
MOVE (u64_rod, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (u64_rod, 8)
MATMUL (u64_rod, 8, i8_rnu)
#if TEST_M >= 64
MOVE (u64_rod, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (u64_rod, 16)
MATMUL (u64_rod, 16, i8_rnu)
#if TEST_M >= 128
MOVE (u64_rod, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (i128_rnu_sat, 1)
MATMUL (i128_rnu_sat, 1, i8_rnu)
#if TEST_M >= 16
MOVE (i128_rnu_sat, 1)
#endif
#endif
#if TEST_A >= 2
VALUE (i128_rnu_sat, 2)
MATMUL (i128_rnu_sat, 2, i8_rnu)
#if TEST_M >= 32
MOVE (i128_rnu_sat, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i128_rnu_sat, 4)
MATMUL (i128_rnu_sat, 4, i8_rnu)
#if TEST_M >= 64
MOVE (i128_rnu_sat, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (i128_rnu_sat, 8)
MATMUL (i128_rnu_sat, 8, i8_rnu)
#if TEST_M >= 128
MOVE (i128_rnu_sat, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i128_rnu_sat, 16)
MATMUL (i128_rnu_sat, 16, i8_rnu)
#if TEST_M >= 256
MOVE (i128_rnu_sat, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (i4_rne, 16)
MATMUL (i4_rne, 16, i8_rnu)
#if TEST_M >= 8
MOVE (i4_rne, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rne, 1)
MATMUL (f64_rne, 1, i8_rnu)
#if TEST_M >= 8
MOVE (f64_rne, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rne, 16)
MATMUL (f64_rne, 16, i8_rnu)
#if TEST_M >= 128
MOVE (f64_rne, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rtz, 1)
MATMUL (f64_rtz, 1, i8_rnu)
#if TEST_M >= 8
MOVE (f64_rtz, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rtz, 16)
MATMUL (f64_rtz, 16, i8_rnu)
#if TEST_M >= 128
MOVE (f64_rtz, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rdn, 1)
MATMUL (f64_rdn, 1, i8_rnu)
#if TEST_M >= 8
MOVE (f64_rdn, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rdn, 16)
MATMUL (f64_rdn, 16, i8_rnu)
#if TEST_M >= 128
MOVE (f64_rdn, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rup, 1)
MATMUL (f64_rup, 1, i8_rnu)
#if TEST_M >= 8
MOVE (f64_rup, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rup, 16)
MATMUL (f64_rup, 16, i8_rnu)
#if TEST_M >= 128
MOVE (f64_rup, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rmm, 1)
MATMUL (f64_rmm, 1, i8_rnu)
#if TEST_M >= 8
MOVE (f64_rmm, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rmm, 16)
MATMUL (f64_rmm, 16, i8_rnu)
#if TEST_M >= 128
MOVE (f64_rmm, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rno, 1)
MATMUL (f64_rno, 1, i8_rnu)
#if TEST_M >= 8
MOVE (f64_rno, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rno, 16)
MATMUL (f64_rno, 16, i8_rnu)
#if TEST_M >= 128
MOVE (f64_rno, 16)
#endif
#endif
#endif

#if TEST_UDS == 16
#if TEST_A >= 1
VALUE (i16_rnu, 1)
MATMUL (i16_rnu, 1, i16_rnu)
#if TEST_M >= 1
MOVE (i16_rnu, 1)
#endif
#endif
#if TEST_A >= 1
VALUE (u32_rne, 1)
MATMUL (u32_rne, 1, i16_rnu)
#if TEST_M >= 2
MOVE (u32_rne, 1)
#endif
#endif
#if TEST_A >= 1
VALUE (i64_rdn, 1)
MATMUL (i64_rdn, 1, i16_rnu)
#if TEST_M >= 4
MOVE (i64_rdn, 1)
#endif
#endif
#if TEST_A >= 2
VALUE (i16_rnu, 2)
MATMUL (i16_rnu, 2, i16_rnu)
#if TEST_M >= 2
MOVE (i16_rnu, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i16_rnu, 4)
MATMUL (i16_rnu, 4, i16_rnu)
#if TEST_M >= 4
MOVE (i16_rnu, 4)
#endif
#endif
#if TEST_A >= 2
VALUE (u32_rne, 2)
MATMUL (u32_rne, 2, i16_rnu)
#if TEST_M >= 4
MOVE (u32_rne, 2)
#endif
#endif
#if TEST_A >= 2
VALUE (i8_rne, 2)
MATMUL (i8_rne, 2, i16_rnu)
#if TEST_M >= 1
MOVE (i8_rne, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i4_rne, 4)
MATMUL (i4_rne, 4, i16_rnu)
#if TEST_M >= 1
MOVE (i4_rne, 4)
#endif
#endif
#if TEST_A >= 4
VALUE (i8_rne, 4)
MATMUL (i8_rne, 4, i16_rnu)
#if TEST_M >= 2
MOVE (i8_rne, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (i8_rne, 8)
MATMUL (i8_rne, 8, i16_rnu)
#if TEST_M >= 4
MOVE (i8_rne, 8)
#endif
#endif
#if TEST_A >= 8
VALUE (i4_rne, 8)
MATMUL (i4_rne, 8, i16_rnu)
#if TEST_M >= 2
MOVE (i4_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i4_rne, 16)
MATMUL (i4_rne, 16, i16_rnu)
#if TEST_M >= 4
MOVE (i4_rne, 16)
#endif
#endif
#if TEST_A >= 8
VALUE (i16_rnu, 8)
MATMUL (i16_rnu, 8, i16_rnu)
#if TEST_M >= 8
MOVE (i16_rnu, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i16_rnu, 16)
MATMUL (i16_rnu, 16, i16_rnu)
#if TEST_M >= 16
MOVE (i16_rnu, 16)
#endif
#endif
#if TEST_A >= 4
VALUE (u32_rne, 4)
MATMUL (u32_rne, 4, i16_rnu)
#if TEST_M >= 8
MOVE (u32_rne, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (u32_rne, 8)
MATMUL (u32_rne, 8, i16_rnu)
#if TEST_M >= 16
MOVE (u32_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (u32_rne, 16)
MATMUL (u32_rne, 16, i16_rnu)
#if TEST_M >= 32
MOVE (u32_rne, 16)
#endif
#endif
#if TEST_A >= 2
VALUE (i64_rdn, 2)
MATMUL (i64_rdn, 2, i16_rnu)
#if TEST_M >= 8
MOVE (i64_rdn, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i64_rdn, 4)
MATMUL (i64_rdn, 4, i16_rnu)
#if TEST_M >= 16
MOVE (i64_rdn, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (i64_rdn, 8)
MATMUL (i64_rdn, 8, i16_rnu)
#if TEST_M >= 32
MOVE (i64_rdn, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i64_rdn, 16)
MATMUL (i64_rdn, 16, i16_rnu)
#if TEST_M >= 64
MOVE (i64_rdn, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (u128_rod, 1)
MATMUL (u128_rod, 1, i16_rnu)
#if TEST_M >= 8
MOVE (u128_rod, 1)
#endif
#endif
#if TEST_A >= 2
VALUE (u128_rod, 2)
MATMUL (u128_rod, 2, i16_rnu)
#if TEST_M >= 16
MOVE (u128_rod, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (u128_rod, 4)
MATMUL (u128_rod, 4, i16_rnu)
#if TEST_M >= 32
MOVE (u128_rod, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (u128_rod, 8)
MATMUL (u128_rod, 8, i16_rnu)
#if TEST_M >= 64
MOVE (u128_rod, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (u128_rod, 16)
MATMUL (u128_rod, 16, i16_rnu)
#if TEST_M >= 128
MOVE (u128_rod, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (i8_rne, 16)
MATMUL (i8_rne, 16, i16_rnu)
#if TEST_M >= 8
MOVE (i8_rne, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rne, 1)
MATMUL (f64_rne, 1, i16_rnu)
#if TEST_M >= 4
MOVE (f64_rne, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rne, 16)
MATMUL (f64_rne, 16, i16_rnu)
#if TEST_M >= 64
MOVE (f64_rne, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rtz, 1)
MATMUL (f64_rtz, 1, i16_rnu)
#if TEST_M >= 4
MOVE (f64_rtz, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rtz, 16)
MATMUL (f64_rtz, 16, i16_rnu)
#if TEST_M >= 64
MOVE (f64_rtz, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rdn, 1)
MATMUL (f64_rdn, 1, i16_rnu)
#if TEST_M >= 4
MOVE (f64_rdn, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rdn, 16)
MATMUL (f64_rdn, 16, i16_rnu)
#if TEST_M >= 64
MOVE (f64_rdn, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rup, 1)
MATMUL (f64_rup, 1, i16_rnu)
#if TEST_M >= 4
MOVE (f64_rup, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rup, 16)
MATMUL (f64_rup, 16, i16_rnu)
#if TEST_M >= 64
MOVE (f64_rup, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rmm, 1)
MATMUL (f64_rmm, 1, i16_rnu)
#if TEST_M >= 4
MOVE (f64_rmm, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rmm, 16)
MATMUL (f64_rmm, 16, i16_rnu)
#if TEST_M >= 64
MOVE (f64_rmm, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rno, 1)
MATMUL (f64_rno, 1, i16_rnu)
#if TEST_M >= 4
MOVE (f64_rno, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rno, 16)
MATMUL (f64_rno, 16, i16_rnu)
#if TEST_M >= 64
MOVE (f64_rno, 16)
#endif
#endif
#endif

#if TEST_UDS == 32
#if TEST_A >= 1
VALUE (i32_rnu, 1)
MATMUL (i32_rnu, 1, i32_rnu)
#if TEST_M >= 1
MOVE (i32_rnu, 1)
#endif
#endif
#if TEST_A >= 1
VALUE (u64_rne, 1)
MATMUL (u64_rne, 1, i32_rnu)
#if TEST_M >= 2
MOVE (u64_rne, 1)
#endif
#endif
#if TEST_A >= 1
VALUE (i128_rdn, 1)
MATMUL (i128_rdn, 1, i32_rnu)
#if TEST_M >= 4
MOVE (i128_rdn, 1)
#endif
#endif
#if TEST_A >= 2
VALUE (i32_rnu, 2)
MATMUL (i32_rnu, 2, i32_rnu)
#if TEST_M >= 2
MOVE (i32_rnu, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i32_rnu, 4)
MATMUL (i32_rnu, 4, i32_rnu)
#if TEST_M >= 4
MOVE (i32_rnu, 4)
#endif
#endif
#if TEST_A >= 2
VALUE (u64_rne, 2)
MATMUL (u64_rne, 2, i32_rnu)
#if TEST_M >= 4
MOVE (u64_rne, 2)
#endif
#endif
#if TEST_A >= 2
VALUE (i16_rne, 2)
MATMUL (i16_rne, 2, i32_rnu)
#if TEST_M >= 1
MOVE (i16_rne, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i8_rne, 4)
MATMUL (i8_rne, 4, i32_rnu)
#if TEST_M >= 1
MOVE (i8_rne, 4)
#endif
#endif
#if TEST_A >= 4
VALUE (i16_rne, 4)
MATMUL (i16_rne, 4, i32_rnu)
#if TEST_M >= 2
MOVE (i16_rne, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (i16_rne, 8)
MATMUL (i16_rne, 8, i32_rnu)
#if TEST_M >= 4
MOVE (i16_rne, 8)
#endif
#endif
#if TEST_A >= 8
VALUE (i8_rne, 8)
MATMUL (i8_rne, 8, i32_rnu)
#if TEST_M >= 2
MOVE (i8_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i8_rne, 16)
MATMUL (i8_rne, 16, i32_rnu)
#if TEST_M >= 4
MOVE (i8_rne, 16)
#endif
#endif
#if TEST_A >= 8
VALUE (i4_rne, 8)
MATMUL (i4_rne, 8, i32_rnu)
#if TEST_M >= 1
MOVE (i4_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i4_rne, 16)
MATMUL (i4_rne, 16, i32_rnu)
#if TEST_M >= 2
MOVE (i4_rne, 16)
#endif
#endif
#if TEST_A >= 8
VALUE (i32_rnu, 8)
MATMUL (i32_rnu, 8, i32_rnu)
#if TEST_M >= 8
MOVE (i32_rnu, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i32_rnu, 16)
MATMUL (i32_rnu, 16, i32_rnu)
#if TEST_M >= 16
MOVE (i32_rnu, 16)
#endif
#endif
#if TEST_A >= 4
VALUE (u64_rne, 4)
MATMUL (u64_rne, 4, i32_rnu)
#if TEST_M >= 8
MOVE (u64_rne, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (u64_rne, 8)
MATMUL (u64_rne, 8, i32_rnu)
#if TEST_M >= 16
MOVE (u64_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (u64_rne, 16)
MATMUL (u64_rne, 16, i32_rnu)
#if TEST_M >= 32
MOVE (u64_rne, 16)
#endif
#endif
#if TEST_A >= 2
VALUE (i128_rdn, 2)
MATMUL (i128_rdn, 2, i32_rnu)
#if TEST_M >= 8
MOVE (i128_rdn, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i128_rdn, 4)
MATMUL (i128_rdn, 4, i32_rnu)
#if TEST_M >= 16
MOVE (i128_rdn, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (i128_rdn, 8)
MATMUL (i128_rdn, 8, i32_rnu)
#if TEST_M >= 32
MOVE (i128_rdn, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i128_rdn, 16)
MATMUL (i128_rdn, 16, i32_rnu)
#if TEST_M >= 64
MOVE (i128_rdn, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (i16_rne, 16)
MATMUL (i16_rne, 16, i32_rnu)
#if TEST_M >= 8
MOVE (i16_rne, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rne, 1)
MATMUL (f64_rne, 1, i32_rnu)
#if TEST_M >= 2
MOVE (f64_rne, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rne, 16)
MATMUL (f64_rne, 16, i32_rnu)
#if TEST_M >= 32
MOVE (f64_rne, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rtz, 1)
MATMUL (f64_rtz, 1, i32_rnu)
#if TEST_M >= 2
MOVE (f64_rtz, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rtz, 16)
MATMUL (f64_rtz, 16, i32_rnu)
#if TEST_M >= 32
MOVE (f64_rtz, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rdn, 1)
MATMUL (f64_rdn, 1, i32_rnu)
#if TEST_M >= 2
MOVE (f64_rdn, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rdn, 16)
MATMUL (f64_rdn, 16, i32_rnu)
#if TEST_M >= 32
MOVE (f64_rdn, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rup, 1)
MATMUL (f64_rup, 1, i32_rnu)
#if TEST_M >= 2
MOVE (f64_rup, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rup, 16)
MATMUL (f64_rup, 16, i32_rnu)
#if TEST_M >= 32
MOVE (f64_rup, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rmm, 1)
MATMUL (f64_rmm, 1, i32_rnu)
#if TEST_M >= 2
MOVE (f64_rmm, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rmm, 16)
MATMUL (f64_rmm, 16, i32_rnu)
#if TEST_M >= 32
MOVE (f64_rmm, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rno, 1)
MATMUL (f64_rno, 1, i32_rnu)
#if TEST_M >= 2
MOVE (f64_rno, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rno, 16)
MATMUL (f64_rno, 16, i32_rnu)
#if TEST_M >= 32
MOVE (f64_rno, 16)
#endif
#endif
#endif

#if TEST_UDS == 64
#if TEST_A >= 1
VALUE (i64_rnu, 1)
MATMUL (i64_rnu, 1, i64_rnu)
#if TEST_M >= 1
MOVE (i64_rnu, 1)
#endif
#endif
#if TEST_A >= 1
VALUE (u128_rne, 1)
MATMUL (u128_rne, 1, i64_rnu)
#if TEST_M >= 2
MOVE (u128_rne, 1)
#endif
#endif
#if TEST_A >= 2
VALUE (i64_rnu, 2)
MATMUL (i64_rnu, 2, i64_rnu)
#if TEST_M >= 2
MOVE (i64_rnu, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i64_rnu, 4)
MATMUL (i64_rnu, 4, i64_rnu)
#if TEST_M >= 4
MOVE (i64_rnu, 4)
#endif
#endif
#if TEST_A >= 2
VALUE (u128_rne, 2)
MATMUL (u128_rne, 2, i64_rnu)
#if TEST_M >= 4
MOVE (u128_rne, 2)
#endif
#endif
#if TEST_A >= 2
VALUE (i32_rne, 2)
MATMUL (i32_rne, 2, i64_rnu)
#if TEST_M >= 1
MOVE (i32_rne, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i16_rne, 4)
MATMUL (i16_rne, 4, i64_rnu)
#if TEST_M >= 1
MOVE (i16_rne, 4)
#endif
#endif
#if TEST_A >= 4
VALUE (i32_rne, 4)
MATMUL (i32_rne, 4, i64_rnu)
#if TEST_M >= 2
MOVE (i32_rne, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (i32_rne, 8)
MATMUL (i32_rne, 8, i64_rnu)
#if TEST_M >= 4
MOVE (i32_rne, 8)
#endif
#endif
#if TEST_A >= 8
VALUE (i16_rne, 8)
MATMUL (i16_rne, 8, i64_rnu)
#if TEST_M >= 2
MOVE (i16_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i16_rne, 16)
MATMUL (i16_rne, 16, i64_rnu)
#if TEST_M >= 4
MOVE (i16_rne, 16)
#endif
#endif
#if TEST_A >= 8
VALUE (i8_rne, 8)
MATMUL (i8_rne, 8, i64_rnu)
#if TEST_M >= 1
MOVE (i8_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i8_rne, 16)
MATMUL (i8_rne, 16, i64_rnu)
#if TEST_M >= 2
MOVE (i8_rne, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (i4_rne, 16)
MATMUL (i4_rne, 16, i64_rnu)
#if TEST_M >= 1
MOVE (i4_rne, 16)
#endif
#endif
#if TEST_A >= 8
VALUE (i64_rnu, 8)
MATMUL (i64_rnu, 8, i64_rnu)
#if TEST_M >= 8
MOVE (i64_rnu, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i64_rnu, 16)
MATMUL (i64_rnu, 16, i64_rnu)
#if TEST_M >= 16
MOVE (i64_rnu, 16)
#endif
#endif
#if TEST_A >= 4
VALUE (u128_rne, 4)
MATMUL (u128_rne, 4, i64_rnu)
#if TEST_M >= 8
MOVE (u128_rne, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (u128_rne, 8)
MATMUL (u128_rne, 8, i64_rnu)
#if TEST_M >= 16
MOVE (u128_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (u128_rne, 16)
MATMUL (u128_rne, 16, i64_rnu)
#if TEST_M >= 32
MOVE (u128_rne, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (i32_rne, 16)
MATMUL (i32_rne, 16, i64_rnu)
#if TEST_M >= 8
MOVE (i32_rne, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rne, 1)
MATMUL (f64_rne, 1, i64_rnu)
#if TEST_M >= 1
MOVE (f64_rne, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rne, 16)
MATMUL (f64_rne, 16, i64_rnu)
#if TEST_M >= 16
MOVE (f64_rne, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rtz, 1)
MATMUL (f64_rtz, 1, i64_rnu)
#if TEST_M >= 1
MOVE (f64_rtz, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rtz, 16)
MATMUL (f64_rtz, 16, i64_rnu)
#if TEST_M >= 16
MOVE (f64_rtz, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rdn, 1)
MATMUL (f64_rdn, 1, i64_rnu)
#if TEST_M >= 1
MOVE (f64_rdn, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rdn, 16)
MATMUL (f64_rdn, 16, i64_rnu)
#if TEST_M >= 16
MOVE (f64_rdn, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rup, 1)
MATMUL (f64_rup, 1, i64_rnu)
#if TEST_M >= 1
MOVE (f64_rup, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rup, 16)
MATMUL (f64_rup, 16, i64_rnu)
#if TEST_M >= 16
MOVE (f64_rup, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rmm, 1)
MATMUL (f64_rmm, 1, i64_rnu)
#if TEST_M >= 1
MOVE (f64_rmm, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rmm, 16)
MATMUL (f64_rmm, 16, i64_rnu)
#if TEST_M >= 16
MOVE (f64_rmm, 16)
#endif
#endif
#if TEST_A >= 1
VALUE (f64_rno, 1)
MATMUL (f64_rno, 1, i64_rnu)
#if TEST_M >= 1
MOVE (f64_rno, 1)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rno, 16)
MATMUL (f64_rno, 16, i64_rnu)
#if TEST_M >= 16
MOVE (f64_rno, 16)
#endif
#endif
#endif

#if TEST_UDS == 128
#if TEST_A >= 1
VALUE (i128_rnu, 1)
MATMUL (i128_rnu, 1, i128_rnu)
#if TEST_M >= 1
MOVE (i128_rnu, 1)
#endif
#endif
#if TEST_A >= 2
VALUE (i128_rnu, 2)
MATMUL (i128_rnu, 2, i128_rnu)
#if TEST_M >= 2
MOVE (i128_rnu, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i128_rnu, 4)
MATMUL (i128_rnu, 4, i128_rnu)
#if TEST_M >= 4
MOVE (i128_rnu, 4)
#endif
#endif
#if TEST_A >= 2
VALUE (i64_rne, 2)
MATMUL (i64_rne, 2, i128_rnu)
#if TEST_M >= 1
MOVE (i64_rne, 2)
#endif
#endif
#if TEST_A >= 4
VALUE (i32_rne, 4)
MATMUL (i32_rne, 4, i128_rnu)
#if TEST_M >= 1
MOVE (i32_rne, 4)
#endif
#endif
#if TEST_A >= 4
VALUE (i64_rne, 4)
MATMUL (i64_rne, 4, i128_rnu)
#if TEST_M >= 2
MOVE (i64_rne, 4)
#endif
#endif
#if TEST_A >= 8
VALUE (i64_rne, 8)
MATMUL (i64_rne, 8, i128_rnu)
#if TEST_M >= 4
MOVE (i64_rne, 8)
#endif
#endif
#if TEST_A >= 8
VALUE (i32_rne, 8)
MATMUL (i32_rne, 8, i128_rnu)
#if TEST_M >= 2
MOVE (i32_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i32_rne, 16)
MATMUL (i32_rne, 16, i128_rnu)
#if TEST_M >= 4
MOVE (i32_rne, 16)
#endif
#endif
#if TEST_A >= 8
VALUE (i16_rne, 8)
MATMUL (i16_rne, 8, i128_rnu)
#if TEST_M >= 1
MOVE (i16_rne, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i16_rne, 16)
MATMUL (i16_rne, 16, i128_rnu)
#if TEST_M >= 2
MOVE (i16_rne, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (i8_rne, 16)
MATMUL (i8_rne, 16, i128_rnu)
#if TEST_M >= 1
MOVE (i8_rne, 16)
#endif
#endif
#if TEST_A >= 8
VALUE (i128_rnu, 8)
MATMUL (i128_rnu, 8, i128_rnu)
#if TEST_M >= 8
MOVE (i128_rnu, 8)
#endif
#endif
#if TEST_A >= 16
VALUE (i128_rnu, 16)
MATMUL (i128_rnu, 16, i128_rnu)
#if TEST_M >= 16
MOVE (i128_rnu, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (i64_rne, 16)
MATMUL (i64_rne, 16, i128_rnu)
#if TEST_M >= 8
MOVE (i64_rne, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rne, 16)
MATMUL (f64_rne, 16, i128_rnu)
#if TEST_M >= 8
MOVE (f64_rne, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rtz, 16)
MATMUL (f64_rtz, 16, i128_rnu)
#if TEST_M >= 8
MOVE (f64_rtz, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rdn, 16)
MATMUL (f64_rdn, 16, i128_rnu)
#if TEST_M >= 8
MOVE (f64_rdn, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rup, 16)
MATMUL (f64_rup, 16, i128_rnu)
#if TEST_M >= 8
MOVE (f64_rup, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rmm, 16)
MATMUL (f64_rmm, 16, i128_rnu)
#if TEST_M >= 8
MOVE (f64_rmm, 16)
#endif
#endif
#if TEST_A >= 16
VALUE (f64_rno, 16)
MATMUL (f64_rno, 16, i128_rnu)
#if TEST_M >= 8
MOVE (f64_rno, 16)
#endif
#endif
#endif
