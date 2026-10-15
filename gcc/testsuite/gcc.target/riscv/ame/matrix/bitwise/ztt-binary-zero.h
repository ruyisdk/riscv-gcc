#include <riscv_ztt.h>
#ifndef BZ_TYPE
#define BZ_TYPE i32_rnu
#define BZ_CARRIER __INT32_TYPE__
#define BZ_SHAPE 1x1
#define BZ_FLOAT 0
#endif
#define BZ_NAME_(f,t,s) __riscv_ztt_##f##_##t##_##s
#define BZ_NAME(f,t,s) BZ_NAME_(f,t,s)
#define BZ_OP(f) BZ_NAME(f,BZ_TYPE,BZ_SHAPE)
#define BZ_T_(t,s) __riscv_ztt_##t##_##s##_t
#define BZ_T(t,s) BZ_T_(t,s)
typedef BZ_T(BZ_TYPE,BZ_SHAPE) bz_matrix;
typedef BZ_CARRIER element_t;
#define BZ_ARGS const element_t *in, const element_t *other, element_t *out
#define BZ_LOAD bz_matrix a = BZ_OP(mls_rm) (in)
#define BZ_ZERO bz_matrix z = BZ_OP(mzero_m) ()
#define BZ_SAVE(v) __riscv_ztt_mss_rm (out, v)
#if BZ_FLOAT
#define BZ_OR madd_ew
#define BZ_XOR madd_ew
#else
#define BZ_OR mor_ew
#define BZ_XOR mxor_ew
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern void bz_callee (void);
extern volatile unsigned long bz_observed;
#define BZ_SIMPLE(n, op, l, r) void bz_##n (BZ_ARGS) \
{ BZ_LOAD; BZ_ZERO; bz_matrix b = BZ_OP(op) (l, r); BZ_SAVE(b); }
BZ_SIMPLE(add_right, madd_ew, a, z)
BZ_SIMPLE(add_left, madd_ew, z, a)
BZ_SIMPLE(sub_right, msub_ew, a, z)
BZ_SIMPLE(or_right, BZ_OR, a, z)
BZ_SIMPLE(or_left, BZ_OR, z, a)
BZ_SIMPLE(xor_right, BZ_XOR, a, z)
BZ_SIMPLE(xor_left, BZ_XOR, z, a)
BZ_SIMPLE(sub_left, msub_ew, z, a)

void bz_copy (BZ_ARGS)
{
  BZ_LOAD; BZ_ZERO;
  bz_matrix c1 = BZ_OP(mcopy_m2m) (z);
  bz_matrix c2 = BZ_OP(mcopy_m2m) (c1);
  bz_matrix c3 = BZ_OP(mcopy_m2m) (c2);
  bz_matrix c4 = BZ_OP(mcopy_m2m) (c3);
  bz_matrix b = BZ_OP(madd_ew) (a, c4); BZ_SAVE(b);
}
void bz_depth (BZ_ARGS)
{
  BZ_LOAD; BZ_ZERO;
  bz_matrix c1 = BZ_OP(mcopy_m2m) (z);
  bz_matrix c2 = BZ_OP(mcopy_m2m) (c1);
  bz_matrix c3 = BZ_OP(mcopy_m2m) (c2);
  bz_matrix c4 = BZ_OP(mcopy_m2m) (c3);
  bz_matrix c5 = BZ_OP(mcopy_m2m) (c4);
  bz_matrix b = BZ_OP(madd_ew) (a, c5); BZ_SAVE(b);
}
void bz_query (BZ_ARGS)
{
  BZ_LOAD; BZ_ZERO;
  unsigned long n = __riscv_ztt_get_amenlen ();
  bz_matrix b = BZ_OP(madd_ew) (a, z);
  BZ_SAVE(b); bz_observed = n;
}
void bz_live (BZ_ARGS)
{
  BZ_LOAD; BZ_ZERO;
  bz_matrix b = BZ_OP(madd_ew) (a, z);
  bz_callee ();
  bz_matrix result = BZ_OP(madd_ew) (b, z); BZ_SAVE(result);
}
void bz_chain (BZ_ARGS)
{
  BZ_LOAD; BZ_ZERO;
  bz_matrix b = BZ_OP(madd_ew) (a, z);
  bz_matrix result = BZ_OP(BZ_OR) (b, z); BZ_SAVE(result);
}
void bz_call (BZ_ARGS)
{
  BZ_LOAD; BZ_ZERO; bz_callee ();
  bz_matrix b = BZ_OP(madd_ew) (a, z); BZ_SAVE(b);
}
void bz_asm (BZ_ARGS)
{
  BZ_LOAD; BZ_ZERO; asm volatile ("" ::: "memory");
  bz_matrix b = BZ_OP(madd_ew) (a, z); BZ_SAVE(b);
}
void bz_memory (BZ_ARGS)
{
  BZ_LOAD; BZ_ZERO; bz_observed = 11;
  bz_matrix b = BZ_OP(madd_ew) (a, z); BZ_SAVE(b);
}
void bz_loaded (BZ_ARGS)
{
  BZ_LOAD; bz_matrix z = BZ_OP(mls_rm) (other);
  bz_matrix b = BZ_OP(madd_ew) (a, z); BZ_SAVE(b);
}
void bz_nonzero (BZ_ARGS)
{
  BZ_LOAD; bz_matrix b = BZ_OP(madd_ew) (a, a); BZ_SAVE(b);
}
void bz_reference (BZ_ARGS) { BZ_LOAD; BZ_SAVE(a); }
#ifdef __cplusplus
}
#endif
