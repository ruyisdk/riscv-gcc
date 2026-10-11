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
#define HALF(OP) NAME_X (OP, VALUE_TYPE, HALF_SHAPE)
#define FULL(OP) NAME_X (OP, VALUE_TYPE, PAIR_SHAPE)
#define TYPE_I(TYPE, SHAPE) __riscv_ztt_##TYPE##_##SHAPE##_t
#define TYPE_X(TYPE, SHAPE) TYPE_I (TYPE, SHAPE)
typedef TYPE_X (VALUE_TYPE, HALF_SHAPE) half_t;
typedef TYPE_X (VALUE_TYPE, PAIR_SHAPE) pair_t;
#define ARGS CARRIER *out, CARRIER *out2, const CARRIER *in, const CARRIER *other, int cond
#define LOAD half_t a = HALF (mls_rm) (in); half_t b = HALF (mls_rm) (other)
#define PAIR LOAD; pair_t p = FULL (mconcat_m) (a, b)
#define SPLIT(P, I, J) half_t x = HALF (mextract) (P, I); half_t y = HALF (mextract) (P, J)
#define STORE(A, B) __riscv_ztt_mss_rm (out, A); __riscv_ztt_mss_rm (out2, B)
#define COPY(P) FULL (mcopy_m2m) (P)
#define TWICE(P) COPY (COPY (P))
#define FOUR(P) TWICE (TWICE (P))
#define FIVE(P) COPY (FOUR (P))
#define ID(P) (P)

#ifdef __cplusplus
extern "C" {
#endif
extern void clobber (void);
extern const CARRIER *observed_input (const CARRIER *);
void reference (ARGS) { LOAD; STORE (a, b); }
void repeat_reference (ARGS) { LOAD; STORE (a, a); }
void reverse_reference (ARGS) { LOAD; STORE (b, a); }
#define PROJECTS(NAME, TRANSFORM, I, J) \
void NAME (ARGS) { PAIR; pair_t q = TRANSFORM (p); SPLIT (q, I, J); STORE (x, y); }
PROJECTS (split, ID, 0, 1)
PROJECTS (repeat, ID, 0, 0)
PROJECTS (reverse, ID, 1, 0)
PROJECTS (copied, COPY, 0, 1)
PROJECTS (four_copies, FOUR, 0, 1)
PROJECTS (five_copies, FIVE, 0, 1)

void live_pair (ARGS)
{
  PAIR; SPLIT (p, 0, 1); STORE (x, y); __riscv_ztt_mss_rm (out, p);
}
void between_call (ARGS)
{
  PAIR; half_t x = HALF (mextract) (p, 0);
  clobber ();
  half_t y = HALF (mextract) (p, 1); STORE (x, y);
}
void between_asm (ARGS)
{
  PAIR; half_t x = HALF (mextract) (p, 0);
  __asm__ volatile ("" ::: "memory");
  half_t y = HALF (mextract) (p, 1); STORE (x, y);
}
void between_memory (ARGS)
{
  PAIR; half_t x = HALF (mextract) (p, 0);
  *(volatile int *) out = cond;
  half_t y = HALF (mextract) (p, 1); STORE (x, y);
}
void join (ARGS)
{
  PAIR; half_t x = HALF (mextract) (p, 0);
  if (cond) clobber ();
  half_t y = HALF (mextract) (p, 1); STORE (x, y);
}
void effect_before (ARGS)
{
  half_t a = HALF (mls_rm) (in);
  half_t b = HALF (mls_rm) (observed_input (other));
  pair_t p = FULL (mconcat_m) (a, b); SPLIT (p, 0, 1); STORE (x, y);
}
#ifdef __cplusplus
}
#endif
