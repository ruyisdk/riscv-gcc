#include <riscv_ztt.h>
#ifndef AC_TYPE
#define AC_TYPE i32_rnu
#define AC_ELEMENT __INT32_TYPE__
#define AC_SHAPE 1x1
#endif
#define AC_NAME_(f,t,s) __riscv_ztt_##f##_##t##_##s
#define AC_NAME(f,t,s) AC_NAME_(f,t,s)
#define AC_OP(f) AC_NAME(f,AC_TYPE,AC_SHAPE)
#define AC_T_(t,s) __riscv_ztt_##t##_##s##_t
#define AC_T(t,s) AC_T_(t,s)
typedef AC_T(AC_TYPE,AC_SHAPE) ac_matrix;
typedef AC_ELEMENT ac_element;
#define AC_ARGS const ac_element *in, const ac_element *other, ac_element *out, \
  ac_element *saved_a, ac_element *saved_b, ac_element *kept
#define AC_LOAD ac_matrix a = AC_OP(mls_rm) (in); \
  ac_matrix b = AC_OP(mls_rm) (other)
#define AC_INNER ac_matrix t = AC_OP(mandnot_ew) (a, b)
#define AC_SAVE(v) __riscv_ztt_mss_rm (saved_a, a); \
  __riscv_ztt_mss_rm (saved_b, b); __riscv_ztt_mss_rm (out, v)
#ifdef __cplusplus
extern "C" {
#endif
extern void ac_callee (void);
extern volatile unsigned long ac_observed;
#define AC_SIMPLE(n,op,l,r) void ac_##n (AC_ARGS) \
{ AC_LOAD; AC_INNER; ac_matrix v = AC_OP(op) (l, r); AC_SAVE(v); }
AC_SIMPLE(and_left, mand_ew, t, a)
AC_SIMPLE(and_right, mand_ew, a, t)
AC_SIMPLE(or_left, mor_ew, t, a)
AC_SIMPLE(or_right, mor_ew, a, t)
AC_SIMPLE(and_other, mand_ew, t, b)
AC_SIMPLE(or_other, mor_ew, b, t)
void ac_copy_result (AC_ARGS)
{
  AC_LOAD; AC_INNER;
  ac_matrix c1 = AC_OP(mcopy_m2m) (t);
  ac_matrix c2 = AC_OP(mcopy_m2m) (c1);
  ac_matrix v = AC_OP(mand_ew) (c2, a); AC_SAVE(v);
}
void ac_copy_input (AC_ARGS)
{
  AC_LOAD;
  ac_matrix c = AC_OP(mcopy_m2m) (a);
  ac_matrix t = AC_OP(mandnot_ew) (c, b);
  ac_matrix v = AC_OP(mor_ew) (t, a); AC_SAVE(v);
}
void ac_reversed (AC_ARGS)
{
  AC_LOAD;
  ac_matrix t = AC_OP(mandnot_ew) (b, a);
  ac_matrix v = AC_OP(mand_ew) (t, a); AC_SAVE(v);
}
#define AC_LIVE(n,op) void ac_##n (AC_ARGS) \
{ AC_LOAD; AC_INNER; ac_matrix v = AC_OP(op) (t, a); ac_callee (); \
  __riscv_ztt_mss_rm (kept, t); AC_SAVE(v); }
AC_LIVE(live, mor_ew)
AC_LIVE(and_live, mand_ew)
void ac_call (AC_ARGS)
{
  AC_LOAD; AC_INNER; ac_callee ();
  ac_matrix v = AC_OP(mor_ew) (t, a); AC_SAVE(v);
}
void ac_asm (AC_ARGS)
{
  AC_LOAD; AC_INNER; asm volatile ("" ::: "memory");
  ac_matrix v = AC_OP(mor_ew) (t, a); AC_SAVE(v);
}
void ac_memory (AC_ARGS)
{
  AC_LOAD; AC_INNER; ac_observed = 11;
  ac_matrix v = AC_OP(mor_ew) (t, a); AC_SAVE(v);
}
void ac_unobserved (AC_ARGS)
{
  AC_LOAD; AC_INNER;
  ac_matrix v = AC_OP(mor_ew) (t, a);
  __riscv_ztt_mss_rm (saved_a, a); __riscv_ztt_mss_rm (out, v);
}
void ac_reference (AC_ARGS)
{ AC_LOAD; AC_INNER; AC_SAVE(t); }
#ifdef __cplusplus
}
#endif
