#include <stdint.h>
#include <riscv_ztt.h>

#ifndef VALUE_TYPE
#define VALUE_TYPE i32_rnu
#define CARRIER int32_t
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
#define TYPE_I(T, SHAPE) __riscv_ztt_##T##_##SHAPE##_t
#define TYPE_X(T, SHAPE) TYPE_I (T, SHAPE)
#define PAIR TYPE_X (VALUE_TYPE, PAIR_SHAPE)
#define PART TYPE_X (VALUE_TYPE, HALF_SHAPE)
#define ARGS CARRIER *out, const CARRIER *in, CARRIER *other, \
             volatile unsigned *flag, int select
#define LOAD PAIR p = FULL (mls_rm) (in)
#define REBUILD PART a = HALF (mextract) (p, 0); \
                PART b = HALF (mextract) (p, 1); \
                PAIR r = FULL (mconcat_m) (a, b)
#define STORE __riscv_ztt_mss_rm (out, r)
#define DISCARD (void) FULL (mcopy_m2m) (p)

#ifdef __cplusplus
extern "C" {
#endif
extern void witness_callee (void);
void rb_direct (ARGS)
{ LOAD; __riscv_ztt_mss_rm (out, p); }
void rb_plain (ARGS)
{ LOAD; REBUILD; STORE; }
void rb_discard (ARGS)
{ LOAD; DISCARD; REBUILD; STORE; }
void rb_terminal (ARGS)
{
  LOAD;
  PART probe = HALF (mextract) (p, 0);
  (void) HALF (mcopy_m2m) (probe);
  REBUILD; STORE;
}
void rb_two_tail (ARGS)
{
  LOAD;
  PART probe = HALF (mextract) (p, 0);
  PART copy = HALF (mcopy_m2m) (probe);
  (void) HALF (mcopy_m2m) (copy);
  REBUILD; STORE;
}
void rb_live_tail (ARGS)
{
  LOAD;
  PART probe = HALF (mextract) (p, 0);
  PART copy = HALF (mcopy_m2m) (probe);
  REBUILD;
  __riscv_ztt_mss_rm (other, copy);
  STORE;
}
void rb_call (ARGS)
{ LOAD; DISCARD; witness_callee (); REBUILD; STORE; }
void rb_limit (ARGS)
{
  LOAD;
#define FOUR DISCARD; DISCARD; DISCARD; DISCARD
  FOUR; FOUR; FOUR; FOUR; DISCARD;
#undef FOUR
  REBUILD; STORE;
}
#ifdef __cplusplus
}
#endif
