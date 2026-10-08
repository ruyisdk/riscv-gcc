#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void binary_callee (void);
extern volatile int binary_condition;
extern volatile long binary_scalar;
#if __riscv_ztt_uds <= 16
#define TX_BASIC 1
#define TX_PAIR 2
#define TX_MIXED 1
#elif __riscv_ztt_uds == 32
#define TX_BASIC 1
#define TX_PAIR 2
#define TX_MIXED 2
#elif __riscv_ztt_uds == 64
#define TX_BASIC 2
#define TX_PAIR 4
#define TX_MIXED 4
#else
#define TX_BASIC 4
#define TX_PAIR 8
#define TX_MIXED 8
#endif
#if __riscv_ztt_uds == 8
#define TX_REUSE 2
#elif __riscv_ztt_uds == 16
#define TX_REUSE 4
#elif __riscv_ztt_uds == 32
#define TX_REUSE 8
#elif __riscv_ztt_uds == 64
#define TX_REUSE 16
#else
#define TX_REUSE 32
#endif
#define TX_C_i16 __INT16_TYPE__
#define TX_C_i32 __INT32_TYPE__
#define TX_DATA(F, D, RM, Q, OLD, X) \
  __riscv_ztt_##F##_ew_x_##D##_##RM##_1x##Q##_i32_rne \
    (OLD, X, __riscv_ztt_scalar_make_i32_rne ((__INT32_TYPE__) binary_scalar))
#define TX_EXP(F, D, RM, Q, OLD, X) \
  __riscv_ztt_##F##_ew_x_##D##_##RM##_1x##Q (OLD, X, binary_scalar)
#define TX_(KEEP, NAME, FORM, OP, D, DR, L, LR, Q, SOURCE, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const void *old, const void *a, const void *b, void *out, \
           void *dcopy, void *acopy, void *bcopy) \
{ \
  __riscv_ztt_##D##_##DR##_1x##Q##_t d \
    = __riscv_ztt_mls_rm_##D##_##DR##_1x##Q ((const TX_C_##D *) old); \
  __riscv_ztt_##L##_##LR##_1x##Q##_t x \
    = __riscv_ztt_mls_rm_##L##_##LR##_1x##Q ((const TX_C_##L *) a); \
  __riscv_ztt_##D##_##DR##_1x##Q##_t y \
    = __riscv_ztt_mls_rm_##D##_##DR##_1x##Q ((const TX_C_##D *) b); \
  __riscv_ztt_##D##_##DR##_1x##Q##_t z = FORM (OP, D, DR, Q, d, SOURCE); \
  BARRIER; \
  __riscv_ztt_mss_rm ((TX_C_##D *) out, z); \
  if (KEEP) __riscv_ztt_mss_rm ((TX_C_##D *) dcopy, d); \
  __riscv_ztt_mss_rm ((TX_C_##L *) acopy, x); \
  __riscv_ztt_mss_rm ((TX_C_##D *) bcopy, y); \
}
#define TX(...) TX_ (0, __VA_ARGS__)
#define TX_LIVE(...) TX_ (1, __VA_ARGS__)
TX (tx_acc, TX_DATA, mmulacc, i32, rnu, i32, rnu, TX_BASIC, x, (void) 0)
TX (tx_neg, TX_DATA, mmulaccneg, i32, rnu, i32, rnu, TX_BASIC, x, (void) 0)
TX (tx_add, TX_DATA, mmuladd, i32, rnu, i32, rnu, TX_BASIC, x, (void) 0)
TX (tx_sub, TX_DATA, mmulsub, i32, rnu, i32, rnu, TX_BASIC, x, (void) 0)
TX (tx_rne, TX_DATA, mmulacc, i32, rne, i32, rdn, TX_BASIC, x, (void) 0)
TX (tx_rdn, TX_DATA, mmulacc, i32, rdn, i32, rne, TX_BASIC, x, (void) 0)
TX (tx_rod, TX_DATA, mmulacc, i32, rod, i32, rnu, TX_BASIC, x, (void) 0)
TX (tx_mixed, TX_DATA, mmulacc, i32, rnu, i16, rne, TX_MIXED, x, (void) 0)
TX (tx_narrow, TX_DATA, mmulacc, i16, rod, i32, rnu, TX_MIXED, x, (void) 0)
TX (tx_pair, TX_DATA, mmulacc, i32, rnu, i32, rnu, TX_PAIR, x, (void) 0)
TX (tx_exp, TX_EXP, mldexpacc, i32, rnu, i32, rnu, TX_BASIC, x, (void) 0)
TX (tx_exp_same, TX_EXP, mldexpacc, i32, rnu, i32, rnu, TX_REUSE, d, (void) 0)
TX (tx_exp_distinct, TX_EXP, mldexpacc, i32, rnu, i32, rnu, TX_REUSE, x, (void) 0)
TX (tx_asm, TX_DATA, mmulacc, i32, rnu, i32, rnu, TX_BASIC, x,
    __asm__ volatile ("" ::: "memory"))
TX (tx_call, TX_DATA, mmulacc, i32, rnu, i32, rnu, TX_BASIC, x, binary_callee ())
TX (tx_join, TX_DATA, mmulacc, i32, rnu, i32, rnu, TX_BASIC, x,
    if (binary_condition) __asm__ volatile ("" ::: "memory"))
TX_LIVE (tx_oldlive, TX_DATA, mmulacc, i32, rnu, i32, rnu, TX_BASIC, x, (void) 0)
#undef TX
#undef TX_
#undef TX_LIVE
#undef TX_DATA
#undef TX_EXP
#undef TX_C_i16
#undef TX_C_i32
#undef TX_BASIC
#undef TX_PAIR
#undef TX_MIXED
#undef TX_REUSE
#ifdef __cplusplus
}
#endif
