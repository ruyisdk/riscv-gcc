#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void binary_callee (void);
extern volatile int binary_condition;
#if __riscv_ztt_uds <= 16
#define TN_BASIC 1
#define TN_PAIR 2
#define TN_MIXED 1
#elif __riscv_ztt_uds == 32
#define TN_BASIC 1
#define TN_PAIR 2
#define TN_MIXED 2
#elif __riscv_ztt_uds == 64
#define TN_BASIC 2
#define TN_PAIR 4
#define TN_MIXED 4
#else
#define TN_BASIC 4
#define TN_PAIR 8
#define TN_MIXED 8
#endif
#define TN_C_i16 __INT16_TYPE__
#define TN_C_i32 __INT32_TYPE__
#define TN_(KEEP, NAME, OP, D, DR, L, LR, R, RR, Q, RIGHT, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const void *old, const void *a, const void *b, void *out, \
           void *dcopy, void *acopy, void *bcopy) \
{ \
  __riscv_ztt_##D##_##DR##_1x##Q##_t d \
    = __riscv_ztt_mls_rm_##D##_##DR##_1x##Q ((const TN_C_##D *) old); \
  __riscv_ztt_##L##_##LR##_1x##Q##_t x \
    = __riscv_ztt_mls_rm_##L##_##LR##_1x##Q ((const TN_C_##L *) a); \
  __riscv_ztt_##R##_##RR##_1x##Q##_t y \
    = __riscv_ztt_mls_rm_##R##_##RR##_1x##Q ((const TN_C_##R *) b); \
  __riscv_ztt_##D##_##DR##_1x##Q##_t z \
    = __riscv_ztt_##OP##_ew_##D##_##DR##_1x##Q (d, x, RIGHT); \
  BARRIER; \
  __riscv_ztt_mss_rm ((TN_C_##D *) out, z); \
  if (KEEP) __riscv_ztt_mss_rm ((TN_C_##D *) dcopy, d); \
  __riscv_ztt_mss_rm ((TN_C_##L *) acopy, x); \
  __riscv_ztt_mss_rm ((TN_C_##R *) bcopy, y); \
}
#define TN(...) TN_ (0, __VA_ARGS__)
#define TN_LIVE(...) TN_ (1, __VA_ARGS__)
TN (tn_acc, mmulacc, i32, rnu, i32, rnu, i32, rnu, TN_BASIC, y, (void) 0)
TN (tn_neg, mmulaccneg, i32, rnu, i32, rnu, i32, rnu, TN_BASIC, y, (void) 0)
TN (tn_add, mmuladd, i32, rnu, i32, rnu, i32, rnu, TN_BASIC, y, (void) 0)
TN (tn_sub, mmulsub, i32, rnu, i32, rnu, i32, rnu, TN_BASIC, y, (void) 0)
TN (tn_ge, mcmovge, i32, rnu, i32, rne, i32, rnu, TN_BASIC, y, (void) 0)
TN (tn_lt, mcmovlt, i32, rnu, i32, rdn, i32, rnu, TN_BASIC, y, (void) 0)
TN (tn_rne, mmulacc, i32, rne, i32, rdn, i32, rod, TN_BASIC, y, (void) 0)
TN (tn_rdn, mmulacc, i32, rdn, i32, rne, i32, rnu, TN_BASIC, y, (void) 0)
TN (tn_rod, mmulacc, i32, rod, i32, rnu, i32, rne, TN_BASIC, y, (void) 0)
TN (tn_mixed, mmulacc, i32, rnu, i16, rne, i32, rdn, TN_MIXED, y, (void) 0)
TN (tn_narrow, mmulacc, i16, rod, i32, rne, i16, rdn, TN_MIXED, y, (void) 0)
TN (tn_pair, mmulacc, i32, rnu, i32, rnu, i32, rnu, TN_PAIR, y, (void) 0)
TN (tn_shared, mmulacc, i32, rnu, i32, rnu, i32, rnu, TN_BASIC, x, (void) 0)
TN (tn_asm, mmulacc, i32, rnu, i32, rnu, i32, rnu, TN_BASIC, y,
    __asm__ volatile ("" ::: "memory"))
TN (tn_call, mmulacc, i32, rnu, i32, rnu, i32, rnu, TN_BASIC, y, binary_callee ())
TN (tn_join, mmulacc, i32, rnu, i32, rnu, i32, rnu, TN_BASIC, y,
    if (binary_condition) __asm__ volatile ("" ::: "memory"))
TN_LIVE (tn_oldlive, mmulacc, i32, rnu, i32, rnu, i32, rnu, TN_BASIC, y, (void) 0)
#undef TN
#undef TN_
#undef TN_LIVE
#undef TN_C_i16
#undef TN_C_i32
#undef TN_BASIC
#undef TN_PAIR
#undef TN_MIXED
#ifdef __cplusplus
}
#endif
