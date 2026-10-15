#ifndef SC_COPY_MODE
#define SC_COPY_MODE 0
#endif
#if SC_COPY_MODE == 1
#define SC_COPY(a) GI_T(GI_TYPE) sc_old = GI_NAME(mcopy_m2m, GI_TYPE) (a)
#define SC_OLD sc_old
#define SC_DATA a
#elif SC_COPY_MODE == 2
#define SC_COPY(a) GI_T(GI_TYPE) sc_old = GI_NAME(mcopy_m2m, GI_TYPE) (a); \
  GI_T(GI_TYPE) sc_data = GI_NAME(mcopy_m2m, GI_TYPE) (a)
#define SC_OLD sc_old
#define SC_DATA sc_data
#elif SC_COPY_MODE == 3
#define SC_COPY(a) GI_T(GI_TYPE) sc0 = GI_NAME(mcopy_m2m, GI_TYPE) (a); \
  GI_T(GI_TYPE) sc1 = GI_NAME(mcopy_m2m, GI_TYPE) (sc0); \
  GI_T(GI_TYPE) sc2 = GI_NAME(mcopy_m2m, GI_TYPE) (sc1); \
  GI_T(GI_TYPE) sc3 = GI_NAME(mcopy_m2m, GI_TYPE) (sc2); \
  GI_T(GI_TYPE) sc_data = GI_NAME(mcopy_m2m, GI_TYPE) (sc3)
#define SC_OLD a
#define SC_DATA sc_data
#else
#define SC_COPY(a) GI_T(GI_TYPE) sc_data = GI_NAME(mcopy_m2m, GI_TYPE) (a)
#define SC_OLD a
#define SC_DATA sc_data
#endif
#define SC_OP(f, a, i) ({ SC_COPY(a); GI_NAME(f, GI_TYPE) (SC_OLD, SC_DATA, i); })
#define GI_COL_OP(a, i) SC_OP(mcolscatmax_ew, a, i)
#define GI_ROW_OP(a, i) SC_OP(mrowscatmax_ew, a, i)
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
