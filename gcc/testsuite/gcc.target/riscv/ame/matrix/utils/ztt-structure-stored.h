#include <riscv_ztt.h>
#ifndef ST_TYPE
#define ST_TYPE i32
#define ST_CARRIER __INT32_TYPE__
#endif
#define ST_FN_(OP, TYPE, SHAPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define ST_FN_EXPAND(OP, TYPE, SHAPE) ST_FN_ (OP, TYPE, SHAPE)
#define ST_FN(OP, SHAPE) ST_FN_EXPAND (OP, ST_TYPE, SHAPE)
#define ST_TY_(TYPE, SHAPE) __riscv_ztt_##TYPE##_##SHAPE##_t
#define ST_TY(TYPE, SHAPE) ST_TY_ (TYPE, SHAPE)
typedef ST_TY (ST_TYPE, 1x1) half_t;
typedef ST_TY (ST_TYPE, 1x2) pair_t;
typedef ST_CARRIER element_t;
#define ST_ARGS const element_t *in, element_t *out, element_t *extra, unsigned flag
#define ST_LOAD pair_t x = ST_FN (mls_rm, 1x2) (in)
#define ST_SPLIT half_t lo = ST_FN (mextract, 1x1) (x, 0); \
  half_t hi = ST_FN (mextract, 1x1) (x, 1)
#define ST_STORE(P, V) __riscv_ztt_mss_rm (P, V)
#ifdef __cplusplus
extern "C" {
#endif
extern void stored_callee (void);

void stored_row (ST_ARGS)
{
  ST_LOAD;
  pair_t y = ST_FN (mrowzip_ew, 1x2) (x);
  pair_t z = ST_FN (mrowunzip_ew, 1x2) (y);
  ST_STORE (out, z);
  ST_STORE (extra, y);
}

void stored_col (ST_ARGS)
{
  ST_LOAD;
  pair_t y = ST_FN (mcolzip_ew, 1x2) (x);
  pair_t z = ST_FN (mcolunzip_ew, 1x2) (y);
  ST_STORE (out, z);
  ST_STORE (extra, y);
}

void stored_zipcopy (ST_ARGS)
{
  ST_LOAD;
  pair_t y = ST_FN (mrowzip_ew, 1x2) (x);
  pair_t q = ST_FN (mcopy_m2m, 1x2) (y);
  pair_t z = ST_FN (mrowunzip_ew, 1x2) (q);
  ST_STORE (out, z);
  ST_STORE (extra, q);
}

void stored_halves (ST_ARGS)
{
  unsigned long n = __riscv_ztt_get_amenlen ();
  ST_LOAD;
  ST_SPLIT;
  pair_t z = ST_FN (mconcat_m, 1x2) (lo, hi);
  ST_STORE (out, z);
  ST_STORE (extra, lo);
  ST_STORE (extra+n*n, hi);
}

void stored_halfcopy (ST_ARGS)
{
  unsigned long n = __riscv_ztt_get_amenlen ();
  ST_LOAD;
  ST_SPLIT;
  half_t qlo = ST_FN (mcopy_m2m, 1x1) (lo);
  half_t qhi = ST_FN (mcopy_m2m, 1x1) (hi);
  pair_t z = ST_FN (mconcat_m, 1x2) (qlo, qhi);
  ST_STORE (out, z);
  ST_STORE (extra, qlo);
  ST_STORE (extra+n*n, qhi);
}

#define ST_BOUNDARY(NAME, GAP) \
void NAME (ST_ARGS) \
{ \
  ST_LOAD; \
  pair_t y = ST_FN (mrowzip_ew, 1x2) (x); \
  pair_t z = ST_FN (mrowunzip_ew, 1x2) (y); \
  GAP; \
  ST_STORE (out, z); \
  ST_STORE (extra, y); \
}
ST_BOUNDARY (stored_call, stored_callee ())
ST_BOUNDARY (stored_asm, __asm__ volatile ("" ::: "memory"))
#undef ST_BOUNDARY

void stored_early (ST_ARGS)
{
  ST_LOAD;
  pair_t y = ST_FN (mrowzip_ew, 1x2) (x);
  ST_STORE (extra, y);
  pair_t z = ST_FN (mrowunzip_ew, 1x2) (y);
  ST_STORE (out, z);
}

void stored_other (ST_ARGS)
{
  ST_LOAD;
  pair_t y = ST_FN (mrowzip_ew, 1x2) (x);
  pair_t z = ST_FN (mrowunzip_ew, 1x2) (y);
  ST_STORE (out, z);
  pair_t w = ST_FN (mcolzip_ew, 1x2) (y);
  ST_STORE (extra, w);
}

void stored_branch (ST_ARGS)
{
  ST_LOAD;
  pair_t y = ST_FN (mrowzip_ew, 1x2) (x);
  pair_t z = ST_FN (mrowunzip_ew, 1x2) (y);
  if (flag)
    ST_STORE (extra, y);
  ST_STORE (out, z);
}

void stored_reference (ST_ARGS)
{
  ST_LOAD;
  pair_t y = ST_FN (mrowzip_ew, 1x2) (x);
  ST_STORE (out, x);
  ST_STORE (extra, y);
}

void stored_halves_reference (ST_ARGS)
{
  unsigned long n = __riscv_ztt_get_amenlen ();
  ST_LOAD;
  ST_SPLIT;
  ST_STORE (out, x);
  ST_STORE (extra, lo);
  ST_STORE (extra+n*n, hi);
}
#ifdef __cplusplus
}
#endif
#undef ST_ARGS
#undef ST_LOAD
#undef ST_SPLIT
#undef ST_STORE
#undef ST_TY
#undef ST_TY_
#undef ST_FN
#undef ST_FN_EXPAND
#undef ST_FN_
