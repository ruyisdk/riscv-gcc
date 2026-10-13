#include <riscv_ztt.h>
#ifndef MX_KIND
#define MX_KIND 0
#endif
#ifndef MX_TYPE
#define MX_TYPE i32_rnu
#define MX_CARRIER __INT32_TYPE__
#endif
#ifndef MY_TYPE
#define MY_TYPE i16_rnu
#define MY_CARRIER __INT16_TYPE__
#endif
#define MX_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define MX_NAME(f, t) MX_NAME_(f, t)
#define MX_T_(t) __riscv_ztt_##t##_1x1_t
#define MX_T(t) MX_T_(t)
typedef MX_CARRIER mx_element;
typedef MY_CARRIER my_element;
#if MX_KIND == 1
#define MX_MAIN(d, x, y) MX_NAME(mldexpacc_ew, MX_TYPE) (d, x, y)
#define MX_OTHER(d, x, y) MX_NAME(mrdexpacc_ew, MX_TYPE) (d, x, y)
#elif MX_KIND == 2
#define MX_MAIN(d, x, y) MX_NAME(mcmovge_ew, MX_TYPE) (d, y, x)
#define MX_OTHER(d, x, y) MX_NAME(mcmovlt_ew, MX_TYPE) (d, y, x)
#else
#define MX_MAIN(d, x, y) MX_NAME(mmulacc_ew, MX_TYPE) (d, x, y)
#define MX_OTHER(d, x, y) MX_NAME(mmulsub_ew, MX_TYPE) (d, y, x)
#endif
#define MX_ARGS const mx_element *in, const my_element *other, \
  const mx_element *old, mx_element *out, mx_element *saved, my_element *ysaved
#define MX_LOAD MX_T(MX_TYPE) x = MX_NAME(mls_rm, MX_TYPE) (in); \
  MX_T(MY_TYPE) y = MX_NAME(mls_rm, MY_TYPE) (other)
#define MX_STORE(v) MX_NAME(mss_rm, MX_TYPE) (out, v)
#ifdef __cplusplus
extern "C" {
#endif
extern void mx_callee (void);
void __attribute__((noipa)) mx_first (MX_ARGS)
{
  MX_LOAD;
  MX_STORE (MX_MAIN (x, x, y));
}
void __attribute__((noipa)) mx_other (MX_ARGS)
{
  MX_LOAD;
  MX_STORE (MX_OTHER (x, x, y));
}
void __attribute__((noipa)) mx_live (MX_ARGS)
{
  MX_LOAD;
  MX_STORE (MX_MAIN (x, x, y));
  MX_NAME(mss_rm, MX_TYPE) (saved, x);
}
void __attribute__((noipa)) mx_distinct (MX_ARGS)
{
  MX_LOAD;
  MX_T(MX_TYPE) d = MX_NAME(mls_rm, MX_TYPE) (old);
  MX_STORE (MX_MAIN (d, x, y));
}
void __attribute__((noipa)) mx_chain (MX_ARGS)
{
  MX_LOAD;
  x = MX_MAIN (x, x, y);
  MX_STORE (MX_OTHER (x, x, y));
}
void __attribute__((noipa)) mx_call (MX_ARGS)
{
  MX_LOAD;
  mx_callee ();
  MX_STORE (MX_MAIN (x, x, y));
}
void __attribute__((noipa)) mx_asm (MX_ARGS)
{
  MX_LOAD;
  asm volatile ("" ::: "memory");
  MX_STORE (MX_MAIN (x, x, y));
}
void __attribute__((noipa)) mx_rhs_live (MX_ARGS)
{
  MX_LOAD;
  MX_STORE (MX_MAIN (x, x, y));
  MX_NAME(mss_rm, MY_TYPE) (ysaved, y);
}
void __attribute__((noipa)) mx_both_live (MX_ARGS)
{
  MX_LOAD;
  MX_STORE (MX_MAIN (x, x, y));
  MX_NAME(mss_rm, MX_TYPE) (saved, x);
  MX_NAME(mss_rm, MY_TYPE) (ysaved, y);
}
void __attribute__((noipa)) mx_reference (MX_ARGS)
{
  MX_T(MX_TYPE) x = MX_NAME(mls_rm, MX_TYPE) (in);
  MX_STORE (x);
}
#if MX_KIND == 0
void __attribute__((noipa)) mx_neg (MX_ARGS)
{
  MX_LOAD;
  MX_STORE (MX_NAME(mmulaccneg_ew, MX_TYPE) (x, x, y));
}
void __attribute__((noipa)) mx_add (MX_ARGS)
{
  MX_LOAD;
  MX_STORE (MX_NAME(mmuladd_ew, MX_TYPE) (x, y, x));
}
#endif
#ifdef __cplusplus
}
#endif
