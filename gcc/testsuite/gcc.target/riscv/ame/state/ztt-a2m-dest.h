#include <riscv_ztt.h>

#ifndef AD_TYPE
#define AD_TYPE i32_rnu
#define AD_ALT i32_rod
#define AD_CARRIER __INT32_TYPE__
#define AD_SHAPE 1x1
#define AD_ACC accx1
#endif
#define AD_NAME_(OP, T, S) __riscv_ztt_##OP##_##T##_##S
#define AD_NAME(OP, T, S) AD_NAME_ (OP, T, S)
#define AD_TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define AD_T(T, S) AD_TYPE_ (T, S)
#define LOAD(P) AD_NAME (mls_rm, AD_TYPE, AD_SHAPE) (P)
#define FROM(M) AD_NAME (mcopy_m2a, AD_TYPE, AD_ACC) (M)
#define TO(A) AD_NAME (mcopy_a2m, AD_TYPE, AD_SHAPE) (A)
#define STORE(P, M) __riscv_ztt_mss_rm (P, M)
#define CASE(N) void __attribute__((noipa)) ad_##N \
  (const AD_CARRIER *in, AD_CARRIER *old, AD_CARRIER *out, \
   AD_CARRIER *live, int condition)

#ifdef __cplusplus
extern "C" {
#endif
extern void ad_callee (void);

CASE (roundtrip)
{
  AD_T (AD_TYPE, AD_ACC) a = FROM (LOAD (in));
  STORE (out, TO (a));
}

CASE (store)
{
  AD_T (AD_TYPE, AD_SHAPE) m = LOAD (in);
  STORE (old, m);
  AD_T (AD_TYPE, AD_ACC) a = FROM (m);
  STORE (out, TO (a));
}

CASE (call)
{
  AD_T (AD_TYPE, AD_ACC) a = FROM (LOAD (in));
  ad_callee ();
  STORE (out, TO (a));
}

CASE (barrier)
{
  AD_T (AD_TYPE, AD_ACC) a = FROM (LOAD (in));
  __asm__ volatile ("# AME state boundary" ::: "memory");
  STORE (out, TO (a));
}

CASE (join)
{
  AD_T (AD_TYPE, AD_ACC) a = FROM (LOAD (in));
  if (condition)
    __asm__ volatile ("# AME state boundary" ::: "memory");
  STORE (out, TO (a));
}

CASE (changed)
{
  AD_T (AD_TYPE, AD_ACC) a = FROM (LOAD (in));
  AD_T (AD_ALT, AD_SHAPE) n
    = AD_NAME (mls_rm, AD_ALT, AD_SHAPE) (old);
  STORE (live, n);
  STORE (out, TO (a));
}

CASE (live)
{
  AD_T (AD_TYPE, AD_SHAPE) m = LOAD (in);
  AD_T (AD_TYPE, AD_ACC) a = FROM (m);
  STORE (out, TO (a));
  STORE (live, m);
}

CASE (unknown)
{
  AD_T (AD_TYPE, AD_ACC) a = AD_NAME (mzero_acc, AD_TYPE, AD_ACC) ();
  STORE (out, TO (a));
}

CASE (repeat)
{
  AD_T (AD_TYPE, AD_ACC) a = FROM (LOAD (in));
  STORE (old, TO (a));
  STORE (out, TO (a));
}

CASE (reference)
{
  STORE (out, LOAD (in));
}
#ifdef __cplusplus
}
#endif
