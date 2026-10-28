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
#define AC_LOAD ac_matrix a = AC_OP(mls_rm) (in)
#define AC_SAVE(v) __riscv_ztt_mss_rm (saved_a, a); \
  __riscv_ztt_mss_rm (out, v)
#ifdef AC_FLOAT
#define AC_XOR msub_ew
#define AC_ANDNOT msub_ew
#else
#define AC_XOR mxor_ew
#define AC_ANDNOT mandnot_ew
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern void ac_callee (void);
extern volatile unsigned long ac_observed;
void ac_xor (AC_ARGS)
{ AC_LOAD; ac_matrix v = AC_OP(AC_XOR) (a, a); AC_SAVE(v); }
void ac_andnot (AC_ARGS)
{ AC_LOAD; ac_matrix v = AC_OP(AC_ANDNOT) (a, a); AC_SAVE(v); }
void ac_copy_xor (AC_ARGS)
{
  AC_LOAD;
  ac_matrix c1 = AC_OP(mcopy_m2m) (a);
  ac_matrix c2 = AC_OP(mcopy_m2m) (c1);
  ac_matrix v = AC_OP(AC_XOR) (c2, a); AC_SAVE(v);
}
void ac_copy_andnot (AC_ARGS)
{
  AC_LOAD;
  ac_matrix c1 = AC_OP(mcopy_m2m) (a);
  ac_matrix c2 = AC_OP(mcopy_m2m) (c1);
  ac_matrix v = AC_OP(AC_ANDNOT) (a, c2); AC_SAVE(v);
}
void ac_deep (AC_ARGS)
{
  AC_LOAD;
  ac_matrix c1 = AC_OP(mcopy_m2m) (a);
  ac_matrix c2 = AC_OP(mcopy_m2m) (c1);
  ac_matrix c3 = AC_OP(mcopy_m2m) (c2);
  ac_matrix c4 = AC_OP(mcopy_m2m) (c3);
  ac_matrix c5 = AC_OP(mcopy_m2m) (c4);
  ac_matrix v = AC_OP(AC_XOR) (c5, a); AC_SAVE(v);
}
void ac_call (AC_ARGS)
{
  AC_LOAD; ac_callee ();
  ac_matrix v = AC_OP(AC_XOR) (a, a); AC_SAVE(v);
}
void ac_asm (AC_ARGS)
{
  AC_LOAD; asm volatile ("" ::: "memory");
  ac_matrix v = AC_OP(AC_ANDNOT) (a, a); AC_SAVE(v);
}
void ac_memory (AC_ARGS)
{
  AC_LOAD; ac_observed = 11;
  ac_matrix v = AC_OP(AC_XOR) (a, a); AC_SAVE(v);
}
void ac_unobserved (AC_ARGS)
{
  AC_LOAD;
  ac_matrix v = AC_OP(AC_XOR) (a, a);
  __riscv_ztt_mss_rm (out, v);
}
void ac_dynamic (AC_ARGS)
{
  AC_LOAD; ac_matrix b = AC_OP(mls_rm) (other);
  ac_matrix v = AC_OP(AC_XOR) (a, b);
  __riscv_ztt_mss_rm (saved_b, b); AC_SAVE(v);
}
void ac_live (AC_ARGS)
{
  AC_LOAD;
  ac_matrix v = AC_OP(AC_ANDNOT) (a, a);
  ac_callee (); AC_SAVE(v);
}
void ac_reference (AC_ARGS)
{ AC_LOAD; ac_matrix v = AC_OP(mzero_m) (); AC_SAVE(v); }
#ifdef __cplusplus
}
#endif
