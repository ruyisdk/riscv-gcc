#include <riscv_ztt.h>
#ifndef IX_TYPE
#define IX_TYPE u64_rnu
#define IX_ALT u64_rod
#define IX_CARRIER __UINT64_TYPE__
#endif
#define IX_T_(T) __riscv_ztt_##T##_1x1_t
#define IX_T(T) IX_T_(T)
#define IX_F_(F,T) __riscv_ztt_##F##_##T##_1x1
#define IX_F(F,T) IX_F_(F,T)
#define IX_ARGS const IX_CARRIER *in, IX_CARRIER *previous, \
  IX_CARRIER *out, IX_CARRIER *saved, int control
#ifdef __cplusplus
extern "C" {
#endif
extern void ix_callee (void);
#define IX_CASE(F,NAME,FIRST,BETWEEN,AFTER) \
__attribute__((noipa)) void ix_##F##_##NAME (IX_ARGS) \
{ \
  IX_T(FIRST) a = IX_F(mls_rm,FIRST) (in); \
  __riscv_ztt_mss_rm (previous,a); \
  BETWEEN; \
  IX_T(IX_TYPE) b = IX_F(F,IX_TYPE) (); \
  __riscv_ztt_mss_rm (out,b); \
  AFTER; \
}
#define IX_FAMILY(F) \
IX_CASE(F,repeat,IX_TYPE, , ) \
IX_CASE(F,changed,IX_ALT, , ) \
IX_CASE(F,call,IX_TYPE,ix_callee (), ) \
IX_CASE(F,barrier,IX_TYPE,__asm__ volatile ("# AME state boundary" ::: "memory"), ) \
IX_CASE(F,join,IX_TYPE,if (control) ix_callee (), ) \
IX_CASE(F,live,IX_TYPE, ,__riscv_ztt_mss_rm (saved,a)) \
__attribute__((noipa)) void ix_##F##_unknown (IX_ARGS) \
{ \
  IX_T(IX_TYPE) b = IX_F(F,IX_TYPE) (); \
  __riscv_ztt_mss_rm (out,b); \
}
IX_FAMILY(mrowid_ew)
IX_FAMILY(mcolid_ew)
#ifdef __cplusplus
}
#endif
