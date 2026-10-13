#include <riscv_ztt.h>
#ifndef CT_TYPE
#define CT_TYPE i32_rnu
#define CT_CARRIER __INT32_TYPE__
#endif
#define CT_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define CT_NAME(f, t) CT_NAME_(f, t)
#define CT_T_(t) __riscv_ztt_##t##_1x1_t
#define CT_T(t) CT_T_(t)
#ifdef CT_EXP
#define CT_OP mldexpacc_ew
#define CT_INV mrdexpacc_ew
#else
#define CT_OP mcmovge_ew
#define CT_INV mcmovlt_ew
#endif
typedef CT_CARRIER ct_element;
#define CT_ARGS const ct_element *in, const ct_element *other, \
  const ct_element *old, ct_element *out, ct_element *saved
#define CT_LOAD CT_T(CT_TYPE) a = CT_NAME(mls_rm, CT_TYPE) (in); \
  CT_T(CT_TYPE) b = CT_NAME(mls_rm, CT_TYPE) (other)
#define CT_DO(f, d, a, b) CT_NAME(f, CT_TYPE) (d, a, b)
#define CT_STORE(x) CT_NAME(mss_rm, CT_TYPE) (out, x)
#ifdef __cplusplus
extern "C" {
#endif
extern void ct_callee (void);
void __attribute__((noipa)) ct_first (CT_ARGS)
{
  CT_LOAD;
  CT_STORE (CT_DO (CT_OP, a, a, b));
}
void __attribute__((noipa)) ct_second (CT_ARGS)
{
  CT_LOAD;
  CT_STORE (CT_DO (CT_OP, b, a, b));
}
void __attribute__((noipa)) ct_both (CT_ARGS)
{
  CT_T(CT_TYPE) a = CT_NAME(mls_rm, CT_TYPE) (in);
  CT_STORE (CT_DO (CT_OP, a, a, a));
}
void __attribute__((noipa)) ct_inverse (CT_ARGS)
{
  CT_LOAD;
  CT_STORE (CT_DO (CT_INV, a, a, b));
}
void __attribute__((noipa)) ct_live (CT_ARGS)
{
  CT_LOAD;
  CT_STORE (CT_DO (CT_OP, a, a, b));
  CT_NAME(mss_rm, CT_TYPE) (saved, a);
}
void __attribute__((noipa)) ct_distinct (CT_ARGS)
{
  CT_LOAD;
  CT_T(CT_TYPE) d = CT_NAME(mls_rm, CT_TYPE) (old);
  CT_STORE (CT_DO (CT_OP, d, a, b));
}
void __attribute__((noipa)) ct_chain (CT_ARGS)
{
  CT_LOAD;
  a = CT_DO (CT_OP, a, a, b);
  CT_STORE (CT_DO (CT_INV, a, a, b));
}
void __attribute__((noipa)) ct_call (CT_ARGS)
{
  CT_LOAD;
  ct_callee ();
  CT_STORE (CT_DO (CT_OP, a, a, b));
}
void __attribute__((noipa)) ct_asm (CT_ARGS)
{
  CT_LOAD;
  asm volatile ("" ::: "memory");
  CT_STORE (CT_DO (CT_OP, a, a, b));
}
void __attribute__((noipa)) ct_reference (CT_ARGS)
{
  CT_T(CT_TYPE) a = CT_NAME(mls_rm, CT_TYPE) (in);
  CT_STORE (a);
}
#ifdef __cplusplus
}
#endif
