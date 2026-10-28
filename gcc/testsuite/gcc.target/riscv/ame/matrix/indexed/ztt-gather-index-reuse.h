#ifndef GW_TYPE
#define GW_TYPE u32
#define GW_CARRIER __UINT32_TYPE__
#define GW_INDEX u32
#define GW_INDEX_CARRIER __UINT32_TYPE__
#endif
#include "ztt-gather-dead.h"

#ifdef __cplusplus
extern "C" {
#endif
void gw_data_live (GW_ARGS)
{
  GW_LOAD;
  GW_T(GW_TYPE) c = GW_NAME(mcolgather_ew, GW_TYPE) (a, b);
  __riscv_ztt_mss_rm (out, c);
  __riscv_ztt_mss_rm (saved, a);
}

void gw_data_live_row (GW_ARGS)
{
  GW_LOAD;
  GW_T(GW_TYPE) c = GW_NAME(mrowgather_ew, GW_TYPE) (a, b);
  __riscv_ztt_mss_rm (out, c);
  __riscv_ztt_mss_rm (saved, a);
}

void gw_data_call (GW_ARGS)
{
  GW_LOAD;
  gw_callee ();
  GW_T(GW_TYPE) c = GW_NAME(mcolgather_ew, GW_TYPE) (a, b);
  __riscv_ztt_mss_rm (out, c);
  __riscv_ztt_mss_rm (saved, a);
}
#ifdef __cplusplus
}
#endif
