#ifndef SZ_MODE
#define SZ_MODE 0
#endif
#if SZ_MODE == 2
#define SZ_BUILD GI_T(GI_TYPE) sz0 = GI_NAME(mzero_m, GI_TYPE) (); \
  GI_T(GI_TYPE) sz1 = GI_NAME(mcopy_m2m, GI_TYPE) (sz0); \
  GI_T(GI_TYPE) sz2 = GI_NAME(mcopy_m2m, GI_TYPE) (sz1); \
  GI_T(GI_TYPE) sz3 = GI_NAME(mcopy_m2m, GI_TYPE) (sz2); \
  GI_T(GI_TYPE) sz4 = GI_NAME(mcopy_m2m, GI_TYPE) (sz3); \
  GI_T(GI_TYPE) sz_zero = GI_NAME(mcopy_m2m, GI_TYPE) (sz4)
#else
#define SZ_BUILD GI_T(GI_TYPE) sz0 = GI_NAME(mzero_m, GI_TYPE) (); \
  GI_T(GI_TYPE) sz_zero = GI_NAME(mcopy_m2m, GI_TYPE) (sz0)
#endif
#if SZ_MODE == 1
#define SZ_OLD a
#define SZ_DATA sz_zero
#else
#define SZ_OLD sz_zero
#define SZ_DATA a
#endif
#define SZ_OP(f, a, i) ({ SZ_BUILD; GI_NAME(f, GI_TYPE) (SZ_OLD, SZ_DATA, i); })
#define GI_COL_OP(a, i) SZ_OP(mcolscatadd_ew, a, i)
#define GI_ROW_OP(a, i) SZ_OP(mrowscatadd_ew, a, i)
#include "ztt-gather-widen.h"

#ifdef __cplusplus
extern "C" {
#endif
void gid_add (GI_ARGS)
{
  GI_LOAD; GI_COL;
  GI_T(GI_TYPE) b = GI_NAME(mcolscatadd_ew, GI_TYPE) (a, a, i);
  __riscv_ztt_mss_rm (out, b);
}

void gid_distinct (GI_ARGS)
{
  GI_LOAD;
  GI_T(GI_TYPE) d = GI_NAME(mls_rm, GI_TYPE) (in + 1);
  GI_COL;
  GI_T(GI_TYPE) b = GI_NAME(mcolscatmax_ew, GI_TYPE) (d, a, i);
  __riscv_ztt_mss_rm (out, b);
}
#ifdef __cplusplus
}
#endif
