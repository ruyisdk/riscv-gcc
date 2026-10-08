#include <riscv_ztt.h>

#ifndef VALUE_TYPE
#define VALUE_TYPE i32_rnu
#define CARRIER __INT32_TYPE__
#endif
#ifndef PAIR_SHAPE
#define PAIR_SHAPE 1x2
#endif
#ifndef HALF_SHAPE
#define HALF_SHAPE 1x1
#endif
#define NAME_I(OP, TYPE, SHAPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define NAME_X(OP, TYPE, SHAPE) NAME_I (OP, TYPE, SHAPE)
#define FULL(OP) NAME_X (OP, VALUE_TYPE, PAIR_SHAPE)
#define HALF(OP) NAME_X (OP, VALUE_TYPE, HALF_SHAPE)
#define TYPE_I(TYPE, SHAPE) __riscv_ztt_##TYPE##_##SHAPE##_t
#define TYPE_X(TYPE, SHAPE) TYPE_I (TYPE, SHAPE)
typedef TYPE_X (VALUE_TYPE, PAIR_SHAPE) full_t;
typedef TYPE_X (VALUE_TYPE, HALF_SHAPE) half_t;
#define ID(X) (X)
#define COPY(X) FULL (mcopy_m2m) (X)
#define TWICE(X) COPY (COPY (X))
#define ARGS CARRIER *out, const CARRIER *in, const CARRIER *other, CARRIER *extra, int cond
#define LOAD half_t a = HALF (mls_rm) (in); half_t b = HALF (mls_rm) (other)
#define PAIR LOAD; full_t p = FULL (mconcat_m) (a, b)
#define STORE(X) __riscv_ztt_mss_rm (out, X)

#ifdef __cplusplus
extern "C" {
#endif
extern void clobber (void);
extern const CARRIER *observed_input (const CARRIER *);

void direct0 (ARGS) { LOAD; STORE (a); }
void direct1 (ARGS) { LOAD; STORE (b); }
#define PROJECT(NAME, TRANSFORM, INDEX) \
void NAME (ARGS) { PAIR; full_t q = TRANSFORM (p); STORE (HALF (mextract) (q, INDEX)); }
PROJECT (uncopied0, ID, 0)
PROJECT (uncopied1, ID, 1)
PROJECT (copied0, COPY, 0)
PROJECT (copied1, COPY, 1)
PROJECT (twice0, TWICE, 0)
PROJECT (twice1, TWICE, 1)

void live_pair (ARGS)
{
  PAIR;
  full_t q = COPY (p);
  STORE (HALF (mextract) (q, 0));
  __riscv_ztt_mss_rm (extra, p);
}
void live_copy (ARGS)
{
  PAIR;
  full_t q = COPY (p);
  STORE (HALF (mextract) (q, 0));
  __riscv_ztt_mss_rm (extra, q);
}
void between_call (ARGS)
{
  PAIR;
  clobber ();
  full_t q = COPY (p);
  STORE (HALF (mextract) (q, 0));
}
void after_call (ARGS)
{
  PAIR;
  full_t q = COPY (p);
  clobber ();
  STORE (HALF (mextract) (q, 0));
}
void asm_boundary (ARGS)
{
  PAIR;
  full_t q = COPY (p);
  __asm__ volatile ("" ::: "memory");
  STORE (HALF (mextract) (q, 0));
}
void memory_boundary (ARGS)
{
  PAIR;
  full_t q = COPY (p);
  *(volatile int *) extra = cond;
  STORE (HALF (mextract) (q, 0));
}
void join (ARGS)
{
  PAIR;
  full_t q = COPY (p);
  if (cond) clobber ();
  STORE (HALF (mextract) (q, 0));
}
void effect_before (ARGS)
{
  half_t a = HALF (mls_rm) (in);
  half_t b = HALF (mls_rm) (observed_input (other));
  full_t p = FULL (mconcat_m) (a, b);
  full_t q = COPY (p);
  STORE (HALF (mextract) (q, 0));
}
#ifdef __cplusplus
}
#endif
