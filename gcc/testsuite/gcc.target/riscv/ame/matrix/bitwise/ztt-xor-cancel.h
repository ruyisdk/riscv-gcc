#include <riscv_ztt.h>
#ifndef XC_TYPE
#define XC_TYPE i32_rnu
#define XC_CARRIER __INT32_TYPE__
#define XC_SHAPE 1x1
#endif
#define XC_NAME_(f,t,s) __riscv_ztt_##f##_##t##_##s
#define XC_NAME(f,t,s) XC_NAME_(f,t,s)
#define XC_OP(f) XC_NAME(f,XC_TYPE,XC_SHAPE)
#define XC_TYPE_(t,s) __riscv_ztt_##t##_##s##_t
#define XC_T(t,s) XC_TYPE_(t,s)
typedef XC_T(XC_TYPE,XC_SHAPE) xc_matrix;
typedef XC_CARRIER element_t;
#define XC_ARGS const element_t *in, const element_t *other, element_t *out, \
  element_t *saved_a, element_t *saved_b, element_t *kept
#define XC_LOAD xc_matrix a = XC_OP(mls_rm) (in); \
  xc_matrix b = XC_OP(mls_rm) (other)
#define XC_SAVE(v) __riscv_ztt_mss_rm (saved_a, a); \
  __riscv_ztt_mss_rm (saved_b, b); __riscv_ztt_mss_rm (out, v)
#ifdef __cplusplus
extern "C" {
#endif
extern void br_callee (void);
extern volatile unsigned long br_observed;
#define XC_SIMPLE(n,l,r) void xc_##n (XC_ARGS) \
{ XC_LOAD; xc_matrix t = XC_OP(mxor_ew) (a, b); \
  xc_matrix v = XC_OP(mxor_ew) (l, r); XC_SAVE(v); }
XC_SIMPLE(left_a,t,a)
XC_SIMPLE(left_b,t,b)
XC_SIMPLE(right_a,a,t)
XC_SIMPLE(right_b,b,t)
void xc_copy_result (XC_ARGS)
{
  XC_LOAD; xc_matrix t = XC_OP(mxor_ew) (a, b);
  xc_matrix c = XC_OP(mcopy_m2m) (t);
  xc_matrix v = XC_OP(mxor_ew) (c, b); XC_SAVE(v);
}
void xc_copy_input (XC_ARGS)
{
  XC_LOAD; xc_matrix c = XC_OP(mcopy_m2m) (a);
  xc_matrix t = XC_OP(mxor_ew) (c, b);
  xc_matrix v = XC_OP(mxor_ew) (a, t); XC_SAVE(v);
}
void xc_live (XC_ARGS)
{
  XC_LOAD; xc_matrix t = XC_OP(mxor_ew) (a, b);
  xc_matrix v = XC_OP(mxor_ew) (t, a);
  __riscv_ztt_mss_rm (kept, t); XC_SAVE(v);
}
void xc_call (XC_ARGS)
{
  XC_LOAD; xc_matrix t = XC_OP(mxor_ew) (a, b); br_callee ();
  xc_matrix v = XC_OP(mxor_ew) (t, a); XC_SAVE(v);
}
void xc_asm (XC_ARGS)
{
  XC_LOAD; xc_matrix t = XC_OP(mxor_ew) (a, b);
  asm volatile ("" ::: "memory");
  xc_matrix v = XC_OP(mxor_ew) (t, a); XC_SAVE(v);
}
void xc_memory (XC_ARGS)
{
  XC_LOAD; xc_matrix t = XC_OP(mxor_ew) (a, b); br_observed = 11;
  xc_matrix v = XC_OP(mxor_ew) (t, a); XC_SAVE(v);
}
void xc_unobserved (XC_ARGS)
{
  XC_LOAD; xc_matrix t = XC_OP(mxor_ew) (a, b);
  xc_matrix v = XC_OP(mxor_ew) (t, b);
  __riscv_ztt_mss_rm (saved_a, a); __riscv_ztt_mss_rm (out, v);
}
void xc_other (XC_ARGS)
{
  XC_LOAD; xc_matrix t = XC_OP(mand_ew) (a, b);
  xc_matrix v = XC_OP(mxor_ew) (t, a); XC_SAVE(v);
}
void xc_reference (XC_ARGS)
{
  XC_LOAD; XC_SAVE(a);
}
#ifdef __cplusplus
}
#endif
