#include <riscv_ztt.h>
#ifndef MT_TYPE
#define MT_TYPE i64_rnu
#define MT_CARRIER __INT64_TYPE__
#endif
#define MT_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define MT_NAME(f, t) MT_NAME_(f, t)
#define MT_T_(t) __riscv_ztt_##t##_1x1_t
#define MT_T(t) MT_T_(t)
typedef MT_CARRIER mt_element;
#define MT_ARGS const mt_element *in, const mt_element *other, \
  const mt_element *old, mt_element *out, mt_element *saved
#define MT_LOAD MT_T(MT_TYPE) a = MT_NAME(mls_rm, MT_TYPE) (in); \
  MT_T(MT_TYPE) b = MT_NAME(mls_rm, MT_TYPE) (other)
#define MT_DO(f, d, a, b) MT_NAME(f, MT_TYPE) (d, a, b)
#define MT_STORE(x) MT_NAME(mss_rm, MT_TYPE) (out, x)
#ifdef __cplusplus
extern "C" {
#endif
extern void mt_callee (void);
void __attribute__((noipa)) mt_both (MT_ARGS)
{
  MT_T(MT_TYPE) a = MT_NAME(mls_rm, MT_TYPE) (in);
  MT_STORE (MT_DO (mmulacc_ew, a, a, a));
}
void __attribute__((noipa)) mt_distinct (MT_ARGS)
{
  MT_LOAD;
  mt_callee ();
  MT_STORE (MT_DO (mmulacc_ew, b, a, b));
}
void __attribute__((noipa)) mt_reference (MT_ARGS)
{
  MT_T(MT_TYPE) a = MT_NAME(mls_rm, MT_TYPE) (in);
  MT_STORE (a);
}
void __attribute__((noipa)) mt_shared_call (MT_ARGS)
{
  MT_T(MT_TYPE) a = MT_NAME(mls_rm, MT_TYPE) (in);
  mt_callee ();
  MT_STORE (MT_DO (mmulacc_ew, a, a, a));
}
void __attribute__((noipa)) mt_shared_live (MT_ARGS)
{
  MT_T(MT_TYPE) a = MT_NAME(mls_rm, MT_TYPE) (in);
  mt_callee ();
  MT_STORE (MT_DO (mmulacc_ew, a, a, a));
  MT_NAME(mss_rm, MT_TYPE) (saved, a);
}
void __attribute__((noipa)) mt_shared_copy (MT_ARGS)
{
  MT_T(MT_TYPE) a = MT_NAME(mls_rm, MT_TYPE) (in);
  MT_T(MT_TYPE) b = MT_NAME(mcopy_m2m, MT_TYPE) (a);
  mt_callee ();
  MT_STORE (MT_DO (mmuladd_ew, a, b, a));
}
void __attribute__((noipa)) mt_shared_pressure (MT_ARGS)
{
  MT_LOAD;
  MT_T(MT_TYPE) d = MT_NAME(mls_rm, MT_TYPE) (old);
  mt_callee ();
  MT_STORE (MT_DO (mmulsub_ew, a, a, a));
  MT_NAME(mss_rm, MT_TYPE) (saved, MT_DO (mmulacc_ew, d, b, d));
}
void __attribute__((noipa)) mt_shared_asm (MT_ARGS)
{
  MT_T(MT_TYPE) a = MT_NAME(mls_rm, MT_TYPE) (in);
  asm volatile ("" ::: "memory");
  MT_STORE (MT_DO (mmulaccneg_ew, a, a, a));
}
#ifdef __cplusplus
}
#endif
