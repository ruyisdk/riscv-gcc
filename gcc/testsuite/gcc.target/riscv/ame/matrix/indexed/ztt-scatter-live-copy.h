#include <riscv_ztt.h>
#ifndef SG_TYPE
#define SG_TYPE u32
#define SG_CARRIER __UINT32_TYPE__
#endif
#define NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define NAME_EXPAND(f, t) NAME_(f, t)
#define NAME(f) NAME_EXPAND(f, SG_TYPE)
#define TYPE_(t) __riscv_ztt_##t##_1x1_t
#define TYPE(t) TYPE_(t)
typedef TYPE(SG_TYPE) matrix_t;
typedef SG_CARRIER element_t;
#define ARGS const element_t *in, const element_t *extra, element_t *out, element_t *saved
#define LOAD matrix_t a = NAME(mls_rm) (in)
#define STORE(P, V) __riscv_ztt_mss_rm (P, V)
#ifdef __cplusplus
extern "C" {
#endif
extern void sg_callee (void);
void sg_col (ARGS)
{
  LOAD;
  STORE (out, NAME(mcolscatadd_ew) (a, a, a));
  STORE (saved, a);
}
void sg_row (ARGS)
{
  LOAD;
  STORE (out, NAME(mrowscatadd_ew) (a, a, a));
  STORE (saved, a);
}
void sg_call (ARGS)
{
  LOAD;
  sg_callee ();
  STORE (out, NAME(mcolscatadd_ew) (a, a, a));
  STORE (saved, a);
}
void sg_after (ARGS)
{
  LOAD;
  STORE (out, NAME(mrowscatadd_ew) (a, a, a));
  sg_callee ();
  STORE (saved, a);
}
void sg_pressure (ARGS)
{
  LOAD;
  matrix_t b = NAME(mls_rm) (extra);
  STORE (out, NAME(mcolscatadd_ew) (a, a, a));
  STORE (saved, NAME(mrowscatadd_ew) (b, b, b));
  STORE (saved + 256, a);
  STORE (saved + 512, b);
}
void sg_asm (ARGS)
{
  LOAD;
  __asm__ volatile ("# state boundary" ::: "memory");
  STORE (out, NAME(mcolscatadd_ew) (a, a, a));
  STORE (saved, a);
}
void sg_dead (ARGS)
{
  LOAD;
  STORE (out, NAME(mcolscatadd_ew) (a, a, a));
}
void sg_distinct (ARGS)
{
  LOAD;
  matrix_t b = NAME(mls_rm) (extra);
  STORE (out, NAME(mcolscatadd_ew) (a, a, b));
  STORE (saved, a);
}
#ifdef __cplusplus
}
#endif
