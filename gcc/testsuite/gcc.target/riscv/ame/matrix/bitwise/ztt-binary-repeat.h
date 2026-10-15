#include <riscv_ztt.h>
#ifndef BR_TYPE
#define BR_TYPE i32_rnu
#define BR_CARRIER __INT32_TYPE__
#define BR_SHAPE 1x1
#define BR_FLOAT 0
#endif
#define BR_NAME_(f,t,s) __riscv_ztt_##f##_##t##_##s
#define BR_NAME(f,t,s) BR_NAME_(f,t,s)
#define BR_OP(f) BR_NAME(f,BR_TYPE,BR_SHAPE)
#define BR_T_(t,s) __riscv_ztt_##t##_##s##_t
#define BR_T(t,s) BR_T_(t,s)
typedef BR_T(BR_TYPE,BR_SHAPE) br_matrix;
typedef BR_CARRIER element_t;
#define BR_ARGS const element_t *in, const element_t *other, element_t *out
#define BR_LOAD br_matrix a = BR_OP(mls_rm) (in); \
  br_matrix b = BR_OP(mls_rm) (other)
#define BR_SAVE(v) __riscv_ztt_mss_rm (out, v)
#if BR_FLOAT
#define BR_AND mmin_ew
#define BR_OR mmax_ew
#else
#define BR_AND mand_ew
#define BR_OR mor_ew
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern void br_callee (void);
extern volatile unsigned long br_observed;
#define BR_SIMPLE(n, op, l, r) void br_##n (BR_ARGS) \
{ BR_LOAD; br_matrix t = BR_OP(op) (a, b); \
  br_matrix v = BR_OP(op) (l, r); BR_SAVE(v); }
BR_SIMPLE(min_left, mmin_ew, t, a)
BR_SIMPLE(min_right, mmin_ew, b, t)
BR_SIMPLE(max_left, mmax_ew, t, b)
BR_SIMPLE(max_right, mmax_ew, a, t)
BR_SIMPLE(and_left, BR_AND, t, a)
BR_SIMPLE(and_right, BR_AND, b, t)
BR_SIMPLE(or_left, BR_OR, t, b)
BR_SIMPLE(or_right, BR_OR, a, t)
void br_copy_result (BR_ARGS)
{
  BR_LOAD; br_matrix t = BR_OP(mmin_ew) (a, b);
  br_matrix c1 = BR_OP(mcopy_m2m) (t);
  br_matrix c2 = BR_OP(mcopy_m2m) (c1);
  br_matrix c3 = BR_OP(mcopy_m2m) (c2);
  br_matrix c4 = BR_OP(mcopy_m2m) (c3);
  br_matrix v = BR_OP(mmin_ew) (a, c4); BR_SAVE(v);
}
void br_copy_input (BR_ARGS)
{
  BR_LOAD;
  br_matrix c1 = BR_OP(mcopy_m2m) (a);
  br_matrix c2 = BR_OP(mcopy_m2m) (c1);
  br_matrix c3 = BR_OP(mcopy_m2m) (c2);
  br_matrix c4 = BR_OP(mcopy_m2m) (c3);
  br_matrix t = BR_OP(mmin_ew) (c4, b);
  br_matrix v = BR_OP(mmin_ew) (t, a); BR_SAVE(v);
}
void br_copies (BR_ARGS)
{
  BR_LOAD;
  br_matrix a1 = BR_OP(mcopy_m2m) (a);
  br_matrix a2 = BR_OP(mcopy_m2m) (a1);
  br_matrix t = BR_OP(BR_OR) (a2, b);
  br_matrix c1 = BR_OP(mcopy_m2m) (t);
  br_matrix c2 = BR_OP(mcopy_m2m) (c1);
  br_matrix v = BR_OP(BR_OR) (a1, c2); BR_SAVE(v);
}
void br_live (BR_ARGS)
{
  BR_LOAD; br_matrix t = BR_OP(mmin_ew) (a, b);
  br_matrix v = BR_OP(mmin_ew) (t, a);
  br_callee ();
  br_matrix result = BR_OP(madd_ew) (v, t); BR_SAVE(result);
}
void br_query (BR_ARGS)
{
  BR_LOAD; br_matrix t = BR_OP(mmin_ew) (a, b);
  unsigned long n = __riscv_ztt_get_amenlen ();
  br_matrix v = BR_OP(mmin_ew) (t, a);
  BR_SAVE(v); br_observed = n;
}
void br_depth (BR_ARGS)
{
  BR_LOAD; br_matrix t = BR_OP(mmin_ew) (a, b);
  br_matrix c1 = BR_OP(mcopy_m2m) (t);
  br_matrix c2 = BR_OP(mcopy_m2m) (c1);
  br_matrix c3 = BR_OP(mcopy_m2m) (c2);
  br_matrix c4 = BR_OP(mcopy_m2m) (c3);
  br_matrix c5 = BR_OP(mcopy_m2m) (c4);
  br_matrix v = BR_OP(mmin_ew) (c5, a); BR_SAVE(v);
}
void br_call (BR_ARGS)
{
  BR_LOAD; br_matrix t = BR_OP(mmin_ew) (a, b); br_callee ();
  br_matrix v = BR_OP(mmin_ew) (t, a); BR_SAVE(v);
}
void br_asm (BR_ARGS)
{
  BR_LOAD; br_matrix t = BR_OP(mmin_ew) (a, b);
  asm volatile ("" ::: "memory");
  br_matrix v = BR_OP(mmin_ew) (t, a); BR_SAVE(v);
}
void br_memory (BR_ARGS)
{
  BR_LOAD; br_matrix t = BR_OP(mmin_ew) (a, b); br_observed = 11;
  br_matrix v = BR_OP(mmin_ew) (t, a); BR_SAVE(v);
}
void br_different (BR_ARGS)
{
  BR_LOAD; br_matrix t = BR_OP(mmax_ew) (a, b);
  br_matrix v = BR_OP(mmin_ew) (t, a); BR_SAVE(v);
}
void br_reference (BR_ARGS)
{ BR_LOAD; br_matrix t = BR_OP(mmin_ew) (a, b); BR_SAVE(t); }
void br_nonmember (BR_ARGS)
{
  BR_LOAD; br_matrix t = BR_OP(mmin_ew) (a, b);
  br_matrix z = BR_OP(mzero_m) ();
  br_matrix v = BR_OP(mmin_ew) (t, z); BR_SAVE(v);
}
#ifdef __cplusplus
}
#endif
