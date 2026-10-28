#include <riscv_ztt.h>
#ifndef MR_LEFT
#define MR_LEFT i32_rnu
#define MR_RIGHT i32_rnu
#define MR_DEST i32_rnu
#define MR_LE __INT32_TYPE__
#define MR_RE __INT32_TYPE__
#define MR_DE __INT32_TYPE__
#endif
#define MR_M_(T) __riscv_ztt_##T##_1x1_t
#define MR_M(T) MR_M_(T)
#define MR_A_(T) __riscv_ztt_##T##_accx1_t
#define MR_A(T) MR_A_(T)
#define MR_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define MR_F(F,T) MR_F_(F,T)
#define MR_AF_(F,T) __riscv_ztt_##F##_##T##_accx1
#define MR_AF(F,T) MR_AF_(F,T)
#define MR_ARGS const MR_LE *left, const MR_RE *right, const MR_DE *old, MR_DE *out, MR_LE *saved, int flag
#define MR_CASE(NAME,BEFORE,AFTER,SAVE,RHS) \
__attribute__((noipa)) void mr_##NAME (MR_ARGS) \
{ \
  MR_M(MR_LEFT) a = MR_F(mls_rm,MR_LEFT) (left); \
  MR_M(MR_RIGHT) b = MR_F(mls_rm,MR_RIGHT) (right); \
  MR_A(MR_DEST) d = MR_AF(mcopy_m2a,MR_DEST) (MR_F(mls_rm,MR_DEST) (old)); \
  BEFORE; \
  d = MR_AF(mmulacc_2d,MR_DEST) (d, a, RHS); \
  AFTER; \
  __riscv_ztt_mss_rm (out, MR_F(mcopy_a2m,MR_DEST) (d)); \
  SAVE; \
}
#ifdef __cplusplus
extern "C" {
#endif
extern void mr_callee (void);
extern volatile unsigned long mr_observed;
MR_CASE(product, mr_callee (), , , b)
MR_CASE(live, mr_callee (), , __riscv_ztt_mss_rm (saved, a), b)
MR_CASE(after, mr_callee (), mr_callee (), , b)
MR_CASE(ready, , , , b)
MR_CASE(barrier, mr_callee (); __asm__ volatile ("# AME observer" : "+Wmr" (a), "+Wmr" (b) : : "memory"), , , b)
MR_CASE(shared, mr_callee (), , __riscv_ztt_mss_rm (saved, a), a)
MR_CASE(query, mr_callee (); __asm__ volatile ("csrr %0,ameown" : "=r" (mr_observed), "+Wmr" (a), "+Wmr" (b) : : "memory"), , , b)
MR_CASE(join, if (flag) mr_callee (), , , b)
#ifdef __cplusplus
}
#endif
