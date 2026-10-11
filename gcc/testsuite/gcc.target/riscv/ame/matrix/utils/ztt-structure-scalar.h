#include <riscv_ztt.h>
#ifndef SCALAR_MATRIX_TYPE
#define SCALAR_MATRIX_TYPE i32
#define SCALAR_MATRIX_CARRIER __INT32_TYPE__
#endif
#define FN_(OP, TYPE, SHAPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define FN(OP, TYPE, SHAPE) FN_ (OP, TYPE, SHAPE)
#define HALF(OP) FN (OP, SCALAR_MATRIX_TYPE, 1x1)
#define PAIR(OP) FN (OP, SCALAR_MATRIX_TYPE, 1x2)
#define TY_(TYPE, SHAPE) __riscv_ztt_##TYPE##_##SHAPE##_t
#define TY(TYPE, SHAPE) TY_ (TYPE, SHAPE)
typedef TY (SCALAR_MATRIX_TYPE, 1x1) half_t;
typedef TY (SCALAR_MATRIX_TYPE, 1x2) pair_t;
typedef SCALAR_MATRIX_CARRIER element_t;
typedef __UINTPTR_TYPE__ result_t;
#define ARGS const element_t *a, const element_t *b, element_t *out, \
  unsigned int index, unsigned int divisor, float left, float right
#define LOAD half_t x = HALF (mls_rm) (a); half_t y = HALF (mls_rm) (b)
#define EXPR (index * 7U + 5U)
#define STORE(V) __riscv_ztt_mss_rm (out, V)

#ifdef __cplusplus
extern "C" {
#endif
extern void structure_callee (void);
extern volatile unsigned int structure_observer;

#define PROJECT(NAME, VALUE, GAP) \
result_t NAME (ARGS) \
{ \
  LOAD; \
  pair_t p = PAIR (mconcat_m) (x, y); \
  result_t result = VALUE; \
  GAP; \
  half_t z = HALF (mextract) (p, 1); \
  STORE (z); \
  return result; \
}
PROJECT (project_arith, EXPR, (void) 0)
PROJECT (project_pointer, (result_t) (out + (index & 3U)), (void) 0)
PROJECT (project_signed, (result_t) ((int) index * 7 + 5), (void) 0)
PROJECT (project_div, index / divisor, (void) 0)
PROJECT (project_float, left < right, (void) 0)
PROJECT (project_memory, EXPR, structure_observer = index)
PROJECT (project_call, EXPR, structure_callee ())
PROJECT (project_asm, EXPR, __asm__ volatile ("" ::: "memory"))
PROJECT (project_join, EXPR, if (index & 1U) structure_callee ())
#undef PROJECT

result_t inverse_arith (ARGS)
{
  pair_t x = PAIR (mls_rm) (a);
  pair_t y = PAIR (mrowzip_ew) (x);
  result_t result = EXPR;
  pair_t z = PAIR (mrowunzip_ew) (y);
  STORE (z);
  return result;
}

result_t rebuild_arith (ARGS)
{
  pair_t x = PAIR (mls_rm) (a);
  half_t lo = HALF (mextract) (x, 0);
  result_t result = EXPR;
  half_t hi = HALF (mextract) (x, 1);
  pair_t z = PAIR (mconcat_m) (lo, hi);
  STORE (z);
  return result;
}

result_t shared_arith (ARGS)
{
  LOAD;
  pair_t p = PAIR (mconcat_m) (x, y);
  half_t lo = HALF (mextract) (p, 0);
  result_t result = EXPR;
  half_t hi = HALF (mextract) (p, 1);
  half_t z = HALF (madd_ew) (lo, hi);
  STORE (z);
  return result;
}
#ifdef __cplusplus
}
#endif
#undef STORE
#undef EXPR
#undef LOAD
#undef ARGS
#undef TY
#undef TY_
#undef PAIR
#undef HALF
#undef FN
#undef FN_
