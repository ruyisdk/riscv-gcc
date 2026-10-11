#include <riscv_ztt.h>
#ifndef SC_TYPE
#define SC_TYPE i32_rnu
#define SC_OTHER i32_rdn
#define SC_CARRIER __INT32_TYPE__
#endif
#define SC_N_(f,t,s) __riscv_ztt_##f##_##t##_##s
#define SC_N(f,t,s) SC_N_(f,t,s)
#define SC_T_(t,s) __riscv_ztt_##t##_##s##_t
#define SC_T(t,s) SC_T_(t,s)
typedef SC_CARRIER sc_element;
#define SC_ARGS const sc_element *in, sc_element *out, sc_element *extra, int k
#define SC_LOAD SC_T(SC_TYPE,1x1) a = SC_N(mls_rm,SC_TYPE,1x1) (in)
#define SC_PAIR \
  SC_T(SC_TYPE,1x2) a = SC_N(mls_rm,SC_TYPE,1x2) (in); \
  SC_T(SC_TYPE,1x1) lo = SC_N(mextract,SC_TYPE,1x1) (a,0); \
  SC_T(SC_TYPE,1x1) hi = SC_N(mextract,SC_TYPE,1x1) (a,1)
#define SC_ROW(dst,src) \
  SC_T(SC_TYPE,1x1) dst = SC_N(mrowbcast_ew_x,SC_TYPE,1x1) (src,k)
#define SC_CONVERT(dst,src) \
  SC_T(SC_TYPE,1x1) dst = SC_N(mconv_ew,SC_TYPE,1x1) (src)
#define SC_JOIN(x,y) \
  SC_T(SC_TYPE,1x2) result = SC_N(mconcat_m,SC_TYPE,1x2) (x,y); \
  __riscv_ztt_mss_rm (out,result)
#ifdef __cplusplus
extern "C" {
#endif
extern void sc_callee (void);
extern volatile unsigned long sc_observed;
void sc_rebuild (SC_ARGS)
{
  SC_PAIR; SC_CONVERT (l,lo); SC_CONVERT (h,hi);
  SC_JOIN (l,h);
}
void sc_witness (SC_ARGS)
{
  SC_PAIR;
  SC_N(mconv_ew,SC_TYPE,1x2) (a);
  SC_T(SC_TYPE,1x1) witness = SC_N(mextract,SC_TYPE,1x1) (a,0);
  SC_N(mconv_ew,SC_TYPE,1x1) (witness);
  SC_CONVERT (l,lo);
  SC_T(SC_TYPE,1x1) h = SC_N(mcopy_m2m,SC_TYPE,1x1) (hi);
  SC_JOIN (l,h);
}
void sc_project (SC_ARGS)
{
  SC_LOAD;
  SC_T(SC_TYPE,1x2) pair = SC_N(mconcat_m,SC_TYPE,1x2) (a,a);
  SC_T(SC_TYPE,1x2) copy = SC_N(mconv_ew,SC_TYPE,1x2) (pair);
  SC_T(SC_TYPE,1x1) half = SC_N(mextract,SC_TYPE,1x1) (copy,1);
  __riscv_ztt_mss_rm (out,half);
}
void sc_zip (SC_ARGS)
{
  SC_T(SC_TYPE,1x2) a = SC_N(mls_rm,SC_TYPE,1x2) (in);
  SC_T(SC_TYPE,1x2) b = SC_N(mcolzip_ew,SC_TYPE,1x2) (a);
  SC_T(SC_TYPE,1x2) c = SC_N(mconv_ew,SC_TYPE,1x2) (b);
  SC_T(SC_TYPE,1x2) d = SC_N(mcolunzip_ew,SC_TYPE,1x2) (c);
  __riscv_ztt_mss_rm (out,d);
}
void sc_gather (SC_ARGS)
{
  SC_LOAD;
  __riscv_ztt_u32_1x1_t i = __riscv_ztt_mcolid_ew_u32_1x1 ();
  __riscv_ztt_u32_1x1_t j = __riscv_ztt_mconv_ew_u32_1x1 (i);
  __riscv_ztt_u32_1x1_t l = __riscv_ztt_mconv_ew_u32_1x1 (j);
  SC_T(SC_TYPE,1x1) b = SC_N(mcolgather_ew,SC_TYPE,1x1) (a,l);
  __riscv_ztt_mss_rm (out,b);
}
void sc_broadcast (SC_ARGS)
{
  SC_LOAD; SC_ROW (b,a); SC_CONVERT (c,b);
  SC_T(SC_TYPE,1x1) d = SC_N(mcopy_m2m,SC_TYPE,1x1) (c);
  SC_ROW (e,d); __riscv_ztt_mss_rm (out,e);
}
void sc_limit (SC_ARGS)
{
  SC_LOAD; SC_ROW (b,a);
  SC_CONVERT (c,b); SC_CONVERT (d,c); SC_CONVERT (e,d);
  SC_CONVERT (f,e); SC_CONVERT (h,f);
  SC_ROW (j,h); __riscv_ztt_mss_rm (out,j);
}
void sc_shared (SC_ARGS)
{
  SC_LOAD; SC_ROW (b,a); SC_CONVERT (c,b); SC_CONVERT (d,c);
  SC_ROW (e,d); __riscv_ztt_mss_rm (out,e);
  __riscv_ztt_mss_rm (extra,c);
}
void sc_call (SC_ARGS)
{
  SC_LOAD; SC_ROW (b,a); SC_CONVERT (c,b);
  sc_callee ();
  SC_ROW (d,c); __riscv_ztt_mss_rm (out,d);
}
void sc_asm (SC_ARGS)
{
  SC_LOAD; SC_ROW (b,a); SC_CONVERT (c,b);
  asm volatile ("" ::: "memory");
  SC_ROW (d,c); __riscv_ztt_mss_rm (out,d);
}
void sc_memory (SC_ARGS)
{
  SC_LOAD; SC_ROW (b,a); SC_CONVERT (c,b);
  sc_observed = sc_observed + 1;
  SC_ROW (d,c); __riscv_ztt_mss_rm (out,d);
}
void sc_rm (SC_ARGS)
{
  SC_PAIR;
  SC_T(SC_OTHER,1x1) converted = SC_N(mconv_ew,SC_OTHER,1x1) (lo);
  SC_CONVERT (l,converted);
  SC_JOIN (l,hi);
}
#ifdef __cplusplus
}
#endif
