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
void sg_col (ARGS) { LOAD; STORE (out, NAME(mcolgather_ew) (a, a)); }
void sg_row (ARGS) { LOAD; STORE (out, NAME(mrowgather_ew) (a, a)); }
void sg_live (ARGS)
{
  LOAD;
  STORE (out, NAME(mcolgather_ew) (a, a));
  STORE (saved, a);
}
void sg_call (ARGS)
{
  LOAD;
  sg_callee ();
  STORE (out, NAME(mcolgather_ew) (a, a));
}
void sg_pressure (ARGS)
{
  LOAD;
  matrix_t b = NAME(mls_rm) (extra);
  STORE (out, NAME(mcolgather_ew) (a, a));
  STORE (saved, NAME(mrowgather_ew) (b, b));
}
void sg_chain (ARGS)
{
  LOAD;
  matrix_t b = NAME(mcolgather_ew) (a, a);
  STORE (out, NAME(mrowgather_ew) (b, b));
}
void sg_asm (ARGS)
{
  LOAD;
  __asm__ volatile ("# state boundary" ::: "memory");
  STORE (out, NAME(mcolgather_ew) (a, a));
}
void sg_copy (ARGS)
{
  LOAD;
  matrix_t b = NAME(mcopy_m2m) (a);
  STORE (out, NAME(mcolgather_ew) (a, b));
}
void sg_distinct (ARGS)
{
  LOAD;
  matrix_t b = NAME(mls_rm) (extra);
  STORE (out, NAME(mcolgather_ew) (a, b));
}
#ifdef __cplusplus
}
#endif
