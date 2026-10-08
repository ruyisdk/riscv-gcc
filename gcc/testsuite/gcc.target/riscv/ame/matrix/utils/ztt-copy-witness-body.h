#include <stdint.h>
#include <riscv_ztt.h>

#ifndef VALUE_TYPE
#define VALUE_TYPE i32_rnu
#define CARRIER int32_t
#endif
#define NAME_I(OP, TYPE, SHAPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define NAME_X(OP, TYPE, SHAPE) NAME_I (OP, TYPE, SHAPE)
#define FULL(OP) NAME_X (OP, VALUE_TYPE, 1x2)
#define HALF(OP) NAME_X (OP, VALUE_TYPE, 1x1)
#define TYPE_I(T, SHAPE) __riscv_ztt_##T##_##SHAPE##_t
#define TYPE_X(T, SHAPE) TYPE_I (T, SHAPE)
#define PAIR TYPE_X (VALUE_TYPE, 1x2)
#define PART TYPE_X (VALUE_TYPE, 1x1)
#define ARGS CARRIER *out, const CARRIER *in, CARRIER *other, \
             volatile unsigned *flag, int select
#define LOAD PAIR p = FULL (mls_rm) (in)
#define ZIP PAIR q = FULL (mcolzip_ew) (p)
#define UNZIP PAIR r = FULL (mcolunzip_ew) (q)
#define STORE __riscv_ztt_mss_rm (out, r)
#define DISCARD (void) FULL (mcopy_m2m) (p)

#ifdef __cplusplus
extern "C" {
#endif
extern void witness_callee (void);

void direct (ARGS)
{
  LOAD;
  __riscv_ztt_mss_rm (out, p);
}

#define ID(X) (X)
#define COPY_HALF(X) HALF (mcopy_m2m) (X)
#define REBUILD_THEN_INVERSE(NAME, COPY) \
void NAME (ARGS) \
{ \
  LOAD; \
  PART a = HALF (mextract) (p, 0); \
  PART b = HALF (mextract) (p, 1); \
  PART x = COPY (a); \
  PART y = COPY (b); \
  PAIR joined = FULL (mconcat_m) (x, y); \
  PAIR q = FULL (mcolzip_ew) (joined); \
  UNZIP; \
  STORE; \
}
REBUILD_THEN_INVERSE (nested_halves_control, ID)
REBUILD_THEN_INVERSE (nested_halves, COPY_HALF)

#define COPY_FULL(X) FULL (mcopy_m2m) (X)
#define INVERSE_THEN_REBUILD(NAME, COPY) \
void NAME (ARGS) \
{ \
  LOAD; \
  ZIP; \
  PAIR mid = COPY (q); \
  PAIR unzipped = FULL (mcolunzip_ew) (mid); \
  PART a = HALF (mextract) (unzipped, 0); \
  PART b = HALF (mextract) (unzipped, 1); \
  PAIR r = FULL (mconcat_m) (a, b); \
  STORE; \
}
INVERSE_THEN_REBUILD (nested_inverse_control, ID)
INVERSE_THEN_REBUILD (nested_inverse, COPY_FULL)

void discard_before (ARGS)
{ LOAD; DISCARD; ZIP; UNZIP; STORE; }
void discard_between (ARGS)
{ LOAD; ZIP; DISCARD; UNZIP; STORE; }
void discard_after (ARGS)
{ LOAD; ZIP; UNZIP; DISCARD; STORE; }
void discard_middle (ARGS)
{ LOAD; ZIP; (void) FULL (mcopy_m2m) (q); UNZIP; STORE; }
void live_copy (ARGS)
{
  LOAD;
  PAIR live = FULL (mcopy_m2m) (p);
  ZIP; UNZIP;
  __riscv_ztt_mss_rm (other, live);
  STORE;
}
void call_boundary (ARGS)
{ LOAD; DISCARD; ZIP; witness_callee (); UNZIP; STORE; }
void asm_boundary (ARGS)
{ LOAD; DISCARD; ZIP; __asm__ volatile ("" ::: "memory"); UNZIP; STORE; }
void memory_boundary (ARGS)
{ LOAD; DISCARD; ZIP; *flag = 7; UNZIP; STORE; }
void query_boundary (ARGS)
{
  LOAD; DISCARD; ZIP;
  unsigned saved = __riscv_ztt_get_amefflags ();
  UNZIP; STORE;
  *flag = saved;
}
void join_boundary (ARGS)
{
  LOAD; DISCARD; ZIP;
  if (select)
    witness_callee ();
  UNZIP; STORE;
}
void limit (ARGS)
{
  LOAD;
#define FOUR DISCARD; DISCARD; DISCARD; DISCARD
  FOUR; FOUR; FOUR; FOUR; DISCARD;
#undef FOUR
  ZIP; UNZIP; STORE;
}
#ifdef __cplusplus
}
#endif
