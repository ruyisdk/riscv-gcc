#define GI_COL_OP(a, i) GI_NAME(mcolscatmax_ew, GI_TYPE) (a, a, i)
#define GI_ROW_OP(a, i) GI_NAME(mrowscatmax_ew, GI_TYPE) (a, a, i)
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
