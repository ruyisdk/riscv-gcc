#include <riscv_ztt.h>
#ifndef MT_TYPE
#define MT_TYPE i32_rnu
#define MT_CARRIER __INT32_TYPE__
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

void __attribute__((noipa)) mt_acc (MT_ARGS)
{
  MT_LOAD;
  MT_STORE (MT_DO (mmulacc_ew, a, a, b));
}
void __attribute__((noipa)) mt_right (MT_ARGS)
{
  MT_LOAD;
  MT_STORE (MT_DO (mmulacc_ew, b, a, b));
}
void __attribute__((noipa)) mt_both (MT_ARGS)
{
  MT_T(MT_TYPE) a = MT_NAME(mls_rm, MT_TYPE) (in);
  MT_STORE (MT_DO (mmulacc_ew, a, a, a));
}
void __attribute__((noipa)) mt_neg (MT_ARGS)
{
  MT_LOAD;
  MT_STORE (MT_DO (mmulaccneg_ew, a, a, b));
}
void __attribute__((noipa)) mt_add (MT_ARGS)
{
  MT_LOAD;
  MT_STORE (MT_DO (mmuladd_ew, b, a, b));
}
void __attribute__((noipa)) mt_sub (MT_ARGS)
{
  MT_LOAD;
  MT_STORE (MT_DO (mmulsub_ew, a, a, b));
}
void __attribute__((noipa)) mt_live (MT_ARGS)
{
  MT_LOAD;
  MT_STORE (MT_DO (mmulacc_ew, a, a, b));
  MT_NAME(mss_rm, MT_TYPE) (saved, a);
}
void __attribute__((noipa)) mt_distinct (MT_ARGS)
{
  MT_LOAD;
  MT_T(MT_TYPE) d = MT_NAME(mls_rm, MT_TYPE) (old);
  MT_STORE (MT_DO (mmulacc_ew, d, a, b));
}
void __attribute__((noipa)) mt_chain (MT_ARGS)
{
  MT_LOAD;
  a = MT_DO (mmulacc_ew, a, a, b);
  MT_STORE (MT_DO (mmulsub_ew, a, b, a));
}
void __attribute__((noipa)) mt_call (MT_ARGS)
{
  MT_LOAD;
  mt_callee ();
  MT_STORE (MT_DO (mmulacc_ew, a, a, b));
}
void __attribute__((noipa)) mt_asm (MT_ARGS)
{
  MT_LOAD;
  asm volatile ("" ::: "memory");
  MT_STORE (MT_DO (mmulacc_ew, a, a, b));
}
void __attribute__((noipa)) mt_reference (MT_ARGS)
{
  MT_T(MT_TYPE) a = MT_NAME(mls_rm, MT_TYPE) (in);
  MT_STORE (a);
}
#ifdef __cplusplus
}
#endif
