#include <riscv_ztt.h>
#ifndef UD_TYPE
#define UD_TYPE i32_rnu
#define UD_ALT i32_rod
#define UD_CARRIER __INT32_TYPE__
#endif
#ifndef UD_SHAPE
#define UD_SHAPE 1x1
#endif
#define UD_T_(T,S) __riscv_ztt_##T##_##S##_t
#define UD_T_I(T,S) UD_T_(T,S)
#define UD_T(T) UD_T_I(T,UD_SHAPE)
#define UD_F_(F,T,S) __riscv_ztt_##F##_##T##_##S
#define UD_F_I(F,T,S) UD_F_(F,T,S)
#define UD_F(F,T) UD_F_I(F,T,UD_SHAPE)
#define UD_ARGS const UD_CARRIER *in, const UD_CARRIER *other, \
  UD_CARRIER *previous, UD_CARRIER *out, UD_CARRIER *saved, \
  UD_CARRIER *saved_other, int control
#ifdef __cplusplus
extern "C" {
#endif
extern void ud_callee (void);
#define UD_CASE(NAME, OP, FIRST, BETWEEN) \
__attribute__((noipa)) void ud_##NAME (UD_ARGS) \
{ \
  UD_T(UD_TYPE) a = UD_F(mls_rm,UD_TYPE) (in); \
  UD_T(UD_TYPE) b = UD_F(mls_rm,UD_TYPE) (other); \
  UD_T(FIRST) first = UD_F(OP,FIRST) (a); \
  __riscv_ztt_mss_rm (previous, first); \
  BETWEEN; \
  UD_T(UD_TYPE) second = UD_F(OP,UD_TYPE) (b); \
  __riscv_ztt_mss_rm (out, second); \
  __riscv_ztt_mss_rm (saved, a); \
  __riscv_ztt_mss_rm (saved_other, b); \
}
#define UD_REPEAT(OP) UD_CASE(OP,OP,UD_TYPE,)
UD_REPEAT(mreduceadd_col)
UD_REPEAT(mreduceadd_row)
UD_REPEAT(mreducemax_col)
UD_REPEAT(mreducemax_row)
UD_REPEAT(mreducemin_col)
UD_REPEAT(mreducemin_row)
UD_REPEAT(mprefixadd_col)
UD_REPEAT(mprefixadd_row)
UD_REPEAT(mprefixmax_col)
UD_REPEAT(mprefixmax_row)
UD_REPEAT(mabs_ew)
#ifdef UD_FLOAT
UD_REPEAT(mfrintm_ew)
UD_REPEAT(mfrintn_ew)
UD_REPEAT(mfrintp_ew)
UD_REPEAT(mfrintz_ew)
UD_REPEAT(mexp2_ew)
UD_REPEAT(mlog2_ew)
UD_REPEAT(mcos_ew)
UD_REPEAT(msin_ew)
UD_REPEAT(mtanh_ew)
UD_REPEAT(mrec_ew)
UD_REPEAT(mrsqrt_ew)
UD_REPEAT(msqrt_ew)
#endif
UD_CASE(changed, mabs_ew, UD_ALT, )
UD_CASE(call, mabs_ew, UD_TYPE, ud_callee ())
UD_CASE(barrier, mabs_ew, UD_TYPE,
        __asm__ volatile ("# AME state boundary" ::: "memory"))
UD_CASE(join, mabs_ew, UD_TYPE, if (control & 1) ud_callee ())
__attribute__((noipa)) void ud_unknown (UD_ARGS)
{
  UD_T(UD_TYPE) a = UD_F(mls_rm,UD_TYPE) (in);
  UD_T(UD_TYPE) b = UD_F(mabs_ew,UD_TYPE) (a);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (saved, a);
}
__attribute__((noipa)) void ud_reference (UD_ARGS)
{
  UD_T(UD_TYPE) a = UD_F(mls_rm,UD_TYPE) (in);
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
