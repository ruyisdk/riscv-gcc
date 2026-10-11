#include <riscv_ztt.h>
#ifndef ZC_TYPE
#define ZC_TYPE i32
#define ZC_CARRIER __INT32_TYPE__
#endif
#define ZC_N_(f,t,s) __riscv_ztt_##f##_##t##_##s
#define ZC_N(f,t,s) ZC_N_(f,t,s)
#define ZC_T_(t,s) __riscv_ztt_##t##_##s##_t
#define ZC_T(t,s) ZC_T_(t,s)
typedef ZC_CARRIER zc_element;
#define ZC_ARGS const zc_element *in, zc_element *out, zc_element *extra, int k
#define ZC_LOAD ZC_T(ZC_TYPE,1x1) a = ZC_N(mls_rm,ZC_TYPE,1x1) (in)
#define ZC_PAIR \
  ZC_T(ZC_TYPE,1x2) a = ZC_N(mls_rm,ZC_TYPE,1x2) (in); \
  ZC_T(ZC_TYPE,1x1) lo = ZC_N(mextract,ZC_TYPE,1x1) (a,0); \
  ZC_T(ZC_TYPE,1x1) hi = ZC_N(mextract,ZC_TYPE,1x1) (a,1)
#define ZC_ROW(dst,src,index) \
  ZC_T(ZC_TYPE,1x1) dst = ZC_N(mrowbcast_ew_x,ZC_TYPE,1x1) (src,index)
#define ZC_ZERO(dst,src) \
  ZC_T(ZC_TYPE,1x1) dst = ZC_N(mrowshift_ew_x,ZC_TYPE,1x1) (src,0)
#define ZC_COPY(dst,src) \
  ZC_T(ZC_TYPE,1x1) dst = ZC_N(mcopy_m2m,ZC_TYPE,1x1) (src)
#define ZC_JOIN(x,y) \
  ZC_T(ZC_TYPE,1x2) result = ZC_N(mconcat_m,ZC_TYPE,1x2) (x,y); \
  __riscv_ztt_mss_rm (out,result)
#ifdef __cplusplus
extern "C" {
#endif
extern void zc_callee (void);
extern volatile unsigned long zc_observed;
void zc_rebuild (ZC_ARGS)
{
  ZC_PAIR; ZC_ZERO (l,lo);
  ZC_T(ZC_TYPE,1x1) h = ZC_N(mcolshift_ew_x,ZC_TYPE,1x1) (hi,0);
  ZC_JOIN (l,h);
}
void zc_witness (ZC_ARGS)
{
  ZC_PAIR;
  ZC_T(ZC_TYPE,1x1) witness = ZC_N(mextract,ZC_TYPE,1x1) (a,0);
  ZC_N(mrowshift_ew_x,ZC_TYPE,1x1) (witness,0);
  ZC_ZERO (l,lo); ZC_COPY (h,hi);
  ZC_JOIN (l,h);
}
void zc_gather (ZC_ARGS)
{
  ZC_LOAD;
  __riscv_ztt_u32_1x1_t i = __riscv_ztt_mcolid_ew_u32_1x1 ();
  __riscv_ztt_u32_1x1_t j = __riscv_ztt_mrowshift_ew_x_u32_1x1 (i,0);
  __riscv_ztt_u32_1x1_t l = __riscv_ztt_mcolshift_ew_x_u32_1x1 (j,0);
  ZC_T(ZC_TYPE,1x1) b = ZC_N(mcolgather_ew,ZC_TYPE,1x1) (a,l);
  __riscv_ztt_mss_rm (out,b);
}
void zc_broadcast (ZC_ARGS)
{
  ZC_LOAD; ZC_ROW (b,a,k); ZC_ZERO (c,b); ZC_COPY (d,c);
  ZC_ROW (e,d,k); __riscv_ztt_mss_rm (out,e);
}
void zc_copy (ZC_ARGS)
{
  ZC_LOAD; ZC_ROW (b,a,k); ZC_COPY (c,b);
  ZC_ROW (d,c,k); __riscv_ztt_mss_rm (out,d);
}
void zc_nonzero (ZC_ARGS)
{
  ZC_PAIR;
  ZC_T(ZC_TYPE,1x1) l = ZC_N(mrowshift_ew_x,ZC_TYPE,1x1) (lo,1);
  ZC_JOIN (l,hi);
}
void zc_dynamic (ZC_ARGS)
{
  ZC_PAIR;
  ZC_T(ZC_TYPE,1x1) l = ZC_N(mrowshift_ew_x,ZC_TYPE,1x1) (lo,k);
  ZC_JOIN (l,hi);
}
void zc_limit (ZC_ARGS)
{
  ZC_LOAD; ZC_ROW (b,a,k);
  ZC_ZERO (c,b); ZC_ZERO (d,c); ZC_ZERO (e,d); ZC_ZERO (f,e); ZC_ZERO (h,f);
  ZC_ROW (j,h,k); __riscv_ztt_mss_rm (out,j);
}
void zc_call (ZC_ARGS)
{
  ZC_LOAD; ZC_ROW (b,a,k); ZC_ZERO (c,b);
  zc_callee ();
  ZC_ROW (d,c,k); __riscv_ztt_mss_rm (out,d);
}
void zc_asm (ZC_ARGS)
{
  ZC_LOAD; ZC_ROW (b,a,k); ZC_ZERO (c,b);
  asm volatile ("" ::: "memory");
  ZC_ROW (d,c,k); __riscv_ztt_mss_rm (out,d);
}
void zc_shared (ZC_ARGS)
{
  ZC_LOAD; ZC_ROW (b,a,k); ZC_ZERO (c,b); ZC_COPY (d,c);
  ZC_ROW (e,d,k); __riscv_ztt_mss_rm (out,e);
  __riscv_ztt_mss_rm (extra,c);
}
void zc_memory (ZC_ARGS)
{
  ZC_LOAD; ZC_ROW (b,a,k); ZC_ZERO (c,b);
  zc_observed = zc_observed + 1;
  ZC_ROW (d,c,k); __riscv_ztt_mss_rm (out,d);
}
#ifdef __cplusplus
}
#endif
