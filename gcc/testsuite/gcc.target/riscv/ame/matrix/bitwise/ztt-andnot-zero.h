#include <riscv_ztt.h>
#ifndef AN_TYPE
#define AN_TYPE i32_rnu
#define AN_SHAPE 1x1
#define AN_CARRIER __INT32_TYPE__
#endif
#define AN_NAME_(f, t, s) __riscv_ztt_##f##_##t##_##s
#define AN_NAME(f, t, s) AN_NAME_(f, t, s)
#define AN_OP(f) AN_NAME(f, AN_TYPE, AN_SHAPE)
#define AN_TYPE_(t, s) __riscv_ztt_##t##_##s##_t
#define AN_MATRIX(t, s) AN_TYPE_(t, s)
typedef AN_MATRIX(AN_TYPE, AN_SHAPE) matrix_t;
typedef AN_CARRIER element_t;
#define AN_ARGS const element_t *in, const element_t *other, element_t *out
#ifdef __cplusplus
extern "C" {
#endif
extern void an_callee (void);

void an_right_zero (AN_ARGS)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  __riscv_ztt_mss_rm (out, AN_OP(mandnot_ew) (a, z));
}

void an_left_zero (AN_ARGS)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  __riscv_ztt_mss_rm (out, AN_OP(mandnot_ew) (z, a));
}

void an_loaded (AN_ARGS)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t b = AN_OP(mls_rm) (other);
  __riscv_ztt_mss_rm (out, AN_OP(mandnot_ew) (a, b));
}

void an_copy_zero (AN_ARGS)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  matrix_t c1 = AN_OP(mcopy_m2m) (z);
  matrix_t c2 = AN_OP(mcopy_m2m) (c1);
  matrix_t c3 = AN_OP(mcopy_m2m) (c2);
  matrix_t c4 = AN_OP(mcopy_m2m) (c3);
  __riscv_ztt_mss_rm (out, AN_OP(mandnot_ew) (a, c4));
}

void an_copy_limit (AN_ARGS)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  matrix_t c1 = AN_OP(mcopy_m2m) (z);
  matrix_t c2 = AN_OP(mcopy_m2m) (c1);
  matrix_t c3 = AN_OP(mcopy_m2m) (c2);
  matrix_t c4 = AN_OP(mcopy_m2m) (c3);
  matrix_t c5 = AN_OP(mcopy_m2m) (c4);
  __riscv_ztt_mss_rm (out, AN_OP(mandnot_ew) (a, c5));
}

void an_call (AN_ARGS)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  an_callee ();
  __riscv_ztt_mss_rm (out, AN_OP(mandnot_ew) (a, z));
}

void an_asm (AN_ARGS)
{
  matrix_t a = AN_OP(mls_rm) (in);
  matrix_t z = AN_OP(mzero_m) ();
  asm volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (out, AN_OP(mandnot_ew) (a, z));
}

void an_reference (AN_ARGS)
{
  __riscv_ztt_mss_rm (out, AN_OP(mls_rm) (in));
}

#ifdef __cplusplus
}
#endif
