#include <riscv_ztt.h>
#ifndef GEO_TYPE
#define GEO_TYPE i32
#define GEO_CARRIER __INT32_TYPE__
#endif
#define GEO_FN_(OP, TYPE, SHAPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define GEO_FN_EXPAND(OP, TYPE, SHAPE) GEO_FN_ (OP, TYPE, SHAPE)
#define GEO_FN(OP, SHAPE) GEO_FN_EXPAND (OP, GEO_TYPE, SHAPE)
#define GEO_TY_(TYPE, SHAPE) __riscv_ztt_##TYPE##_##SHAPE##_t
#define GEO_TY(TYPE, SHAPE) GEO_TY_ (TYPE, SHAPE)
typedef GEO_TY (GEO_TYPE, 1x1) half_t;
typedef GEO_TY (GEO_TYPE, 1x2) pair_t;
typedef GEO_CARRIER element_t;
#define GEO_ARGS const element_t *in, element_t *out
#define GEO_LOAD pair_t x = GEO_FN (mls_rm, 1x2) (in)
#define GEO_STORE(V) __riscv_ztt_mss_rm (out, V)

#ifdef __cplusplus
extern "C" {
#endif
extern unsigned long geometry_callee (void);
extern volatile unsigned long geometry_observer;

#define GEO_ZIP(NAME, VALUE, GAP) \
unsigned long NAME (GEO_ARGS) \
{ \
  GEO_LOAD; \
  pair_t y = GEO_FN (mrowzip_ew, 1x2) (x); \
  unsigned long value = VALUE; \
  GAP; \
  pair_t z = GEO_FN (mrowunzip_ew, 1x2) (y); \
  GEO_STORE (z); \
  return value; \
}
GEO_ZIP (geo_zip, __riscv_ztt_get_amenlen (),
         value += __riscv_ztt_get_ameudsz ())
GEO_ZIP (geo_legacy, __builtin_riscv_ztt_read_amenlen (),
         value += __builtin_riscv_ztt_read_ameudsz ())
GEO_ZIP (geo_discard, __riscv_ztt_get_ameudsz (),
         __riscv_ztt_get_amenlen ())
GEO_ZIP (geo_flags, __riscv_ztt_get_amefflags (), (void) 0)
GEO_ZIP (geo_own, __riscv_ztt_get_ameown (), (void) 0)
GEO_ZIP (geo_type, __riscv_ztt_get_amestype (), (void) 0)
GEO_ZIP (geo_status, __riscv_ztt_get_amestatus (), (void) 0)
GEO_ZIP (geo_sat, __riscv_ztt_get_amexsat (), (void) 0)
GEO_ZIP (geo_call, geometry_callee (), (void) 0)
GEO_ZIP (geo_memory, geometry_observer, (void) 0)
GEO_ZIP (geo_asm, 0,
         __asm__ volatile ("csrr %0,amenlen" : "=r" (value) :: "memory"))
#undef GEO_ZIP

unsigned long geo_rebuild (GEO_ARGS)
{
  GEO_LOAD;
  half_t lo = GEO_FN (mextract, 1x1) (x, 0);
  unsigned long value = __riscv_ztt_get_ameudsz ();
  half_t hi = GEO_FN (mextract, 1x1) (x, 1);
  pair_t z = GEO_FN (mconcat_m, 1x2) (lo, hi);
  GEO_STORE (z);
  return value;
}

unsigned long geo_project (GEO_ARGS)
{
  unsigned long n = __riscv_ztt_get_amenlen ();
  half_t x = GEO_FN (mls_rm, 1x1) (in);
  half_t y = GEO_FN (mls_rm, 1x1) (in + n*n);
  pair_t p = GEO_FN (mconcat_m, 1x2) (x, y);
  unsigned long value = __riscv_ztt_get_ameudsz ();
  half_t z = GEO_FN (mextract, 1x1) (p, 1);
  GEO_STORE (z);
  return value;
}

unsigned long geo_shared (GEO_ARGS)
{
  unsigned long n = __riscv_ztt_get_amenlen ();
  half_t x = GEO_FN (mls_rm, 1x1) (in);
  half_t y = GEO_FN (mls_rm, 1x1) (in + n*n);
  pair_t p = GEO_FN (mconcat_m, 1x2) (x, y);
  half_t lo = GEO_FN (mextract, 1x1) (p, 0);
  unsigned long value = __riscv_ztt_get_ameudsz ();
  half_t hi = GEO_FN (mextract, 1x1) (p, 1);
  __riscv_ztt_mss_rm (out, lo);
  __riscv_ztt_mss_rm (out + n*n, hi);
  return value;
}

unsigned long geo_reference (GEO_ARGS)
{
  GEO_LOAD;
  unsigned long value = __riscv_ztt_get_amenlen ();
  value += __riscv_ztt_get_ameudsz ();
  GEO_STORE (x);
  return value;
}
#ifdef __cplusplus
}
#endif
#undef GEO_STORE
#undef GEO_LOAD
#undef GEO_ARGS
#undef GEO_TY
#undef GEO_TY_
#undef GEO_FN
#undef GEO_FN_EXPAND
#undef GEO_FN_
