#include <riscv_ztt.h>

#ifdef __cplusplus
#define SAME(A, B) __is_same (A, B)
#define CHECK(C) static_assert (C, "default ACC alias")
#else
#define SAME(A, B) __builtin_types_compatible_p (A, B)
#define CHECK(C) _Static_assert (C, "default ACC alias")
#endif

#define OP(T, K, NAME) \
  CHECK (SAME (__typeof__ (__riscv_ztt_##NAME##_##T##_accx##K), \
               __typeof__ (__riscv_ztt_##NAME##_##T##_rnu_accx##K)))
#define VALUE(T, K) \
  CHECK (SAME (__riscv_ztt_##T##_accx##K##_t, \
               __riscv_ztt_##T##_rnu_accx##K##_t)); \
  OP (T, K, mclear_acc); \
  OP (T, K, mzero_acc); \
  OP (T, K, mmulacc_2d); \
  OP (T, K, mmulaccneg_2d); \
  OP (T, K, mmulatacc_2d); \
  OP (T, K, mmulataccneg_2d); \
  OP (T, K, mmulbtacc_2d); \
  OP (T, K, mmulbtaccneg_2d); \
  void value_##T##_##K (void) \
  { \
    __riscv_ztt_##T##_accx##K##_t a = __riscv_ztt_mzero_acc_##T##_accx##K (); \
    __asm__ volatile ("" : : "War" (a)); \
    a = __riscv_ztt_mclear_acc_##T##_accx##K (); \
    __asm__ volatile ("" : : "War" (a)); \
  }
#define MOVE(T, K) \
  OP (T, K, mcopy_m2a); \
  CHECK (SAME (__typeof__ (__riscv_ztt_mcopy_a2m_##T##_1x##K), \
               __typeof__ (__riscv_ztt_mcopy_a2m_##T##_rnu_1x##K))); \
  CHECK (SAME (__typeof__ (__riscv_ztt_mcopy_a2m_##T##_##K##x1), \
               __typeof__ (__riscv_ztt_mcopy_a2m_##T##_rnu_##K##x1)))
#define PAIR(APPLY, BITS, K) APPLY (i##BITS, K) APPLY (u##BITS, K)

/* A full packed ACC group contains at least one complete packet.  */
#if __riscv_ztt_uds <= 64
PAIR (VALUE, 8, 8)
#endif
PAIR (VALUE, 8, 16)
PAIR (VALUE, 16, 8)
PAIR (VALUE, 16, 16)
PAIR (VALUE, 32, 8)
PAIR (VALUE, 32, 16)

#if __riscv_ztt_uds <= 64
MOVE (i8, 8); MOVE (u8, 8);
#endif
MOVE (i8, 16); MOVE (u8, 16);
MOVE (i16, 8); MOVE (u16, 8);
MOVE (i16, 16); MOVE (u16, 16);
MOVE (i32, 8); MOVE (u32, 8);
#if __riscv_ztt_uds >= 16
MOVE (i32, 16); MOVE (u32, 16);
#endif
