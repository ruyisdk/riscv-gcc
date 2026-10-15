#include <riscv_ztt.h>
#ifndef BI_TYPE
#define BI_TYPE i32_rnu
#define BI_CARRIER __INT32_TYPE__
#define BI_SHAPE 1x1
#define BI_FLOAT 0
#endif
#define BI_NAME_(f,t,s) __riscv_ztt_##f##_##t##_##s
#define BI_NAME(f,t,s) BI_NAME_(f,t,s)
#define BI_OP(f) BI_NAME(f,BI_TYPE,BI_SHAPE)
#define BI_T_(t,s) __riscv_ztt_##t##_##s##_t
#define BI_T(t,s) BI_T_(t,s)
typedef BI_T(BI_TYPE,BI_SHAPE) bi_matrix;
typedef BI_CARRIER element_t;
#define BI_ARGS const element_t *in, const element_t *other, element_t *out
#define BI_LOAD bi_matrix a = BI_OP(mls_rm) (in)
#define BI_SAVE(v) __riscv_ztt_mss_rm (out, v)
#if BI_FLOAT
#define BI_AND mmin_ew
#define BI_OR mmax_ew
#define BI_XOR madd_ew
#else
#define BI_AND mand_ew
#define BI_OR mor_ew
#define BI_XOR mxor_ew
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern void bi_callee (void);
extern volatile unsigned long bi_observed;
#define BI_SIMPLE(n, op) void bi_##n (BI_ARGS) \
{ BI_LOAD; bi_matrix b = BI_OP(op) (a, a); BI_SAVE(b); }
BI_SIMPLE(min, mmin_ew)
BI_SIMPLE(max, mmax_ew)
BI_SIMPLE(and, BI_AND)
BI_SIMPLE(or, BI_OR)

void bi_copy_left (BI_ARGS)
{
  BI_LOAD;
  bi_matrix c1 = BI_OP(mcopy_m2m) (a);
  bi_matrix c2 = BI_OP(mcopy_m2m) (c1);
  bi_matrix c3 = BI_OP(mcopy_m2m) (c2);
  bi_matrix c4 = BI_OP(mcopy_m2m) (c3);
  bi_matrix b = BI_OP(mmin_ew) (c4, a); BI_SAVE(b);
}
void bi_copy_right (BI_ARGS)
{
  BI_LOAD;
  bi_matrix c = BI_OP(mcopy_m2m) (a);
  bi_matrix b = BI_OP(mmax_ew) (a, c); BI_SAVE(b);
}
void bi_copies (BI_ARGS)
{
  BI_LOAD;
  bi_matrix c1 = BI_OP(mcopy_m2m) (a);
  bi_matrix c2 = BI_OP(mcopy_m2m) (c1);
  bi_matrix b = BI_OP(BI_AND) (c1, c2); BI_SAVE(b);
}
void bi_min_chain (BI_ARGS)
{
  BI_LOAD;
  bi_matrix b = BI_OP(mmin_ew) (a, a);
  bi_matrix result = BI_OP(mmax_ew) (b, b); BI_SAVE(result);
}
void bi_depth (BI_ARGS)
{
  BI_LOAD;
  bi_matrix c1 = BI_OP(mcopy_m2m) (a);
  bi_matrix c2 = BI_OP(mcopy_m2m) (c1);
  bi_matrix c3 = BI_OP(mcopy_m2m) (c2);
  bi_matrix c4 = BI_OP(mcopy_m2m) (c3);
  bi_matrix c5 = BI_OP(mcopy_m2m) (c4);
  bi_matrix b = BI_OP(mmin_ew) (c5, a); BI_SAVE(b);
}
void bi_query (BI_ARGS)
{
  BI_LOAD;
  unsigned long n = __riscv_ztt_get_amenlen ();
  bi_matrix b = BI_OP(mmin_ew) (a, a);
  BI_SAVE(b); bi_observed = n;
}
void bi_live (BI_ARGS)
{
  BI_LOAD;
  bi_matrix b = BI_OP(mmin_ew) (a, a);
  bi_callee ();
  bi_matrix result = BI_OP(madd_ew) (b, a); BI_SAVE(result);
}
void bi_call (BI_ARGS)
{
  BI_LOAD; bi_callee ();
  bi_matrix b = BI_OP(mmin_ew) (a, a); BI_SAVE(b);
}
void bi_asm (BI_ARGS)
{
  BI_LOAD; asm volatile ("" ::: "memory");
  bi_matrix b = BI_OP(mmin_ew) (a, a); BI_SAVE(b);
}
void bi_memory (BI_ARGS)
{
  BI_LOAD; bi_observed = 11;
  bi_matrix b = BI_OP(mmin_ew) (a, a); BI_SAVE(b);
}
void bi_distinct (BI_ARGS)
{
  BI_LOAD; bi_matrix c = BI_OP(mls_rm) (other);
  bi_matrix b = BI_OP(mmin_ew) (a, c); BI_SAVE(b);
}
BI_SIMPLE(double, madd_ew)
BI_SIMPLE(xor, BI_XOR)
void bi_reference (BI_ARGS) { BI_LOAD; BI_SAVE(a); }
void bi_computed (BI_ARGS)
{
  BI_LOAD;
  bi_matrix c = BI_OP(madd_ew) (a, a);
  bi_matrix b = BI_OP(mmin_ew) (c, c); BI_SAVE(b);
}
#ifdef __cplusplus
}
#endif
