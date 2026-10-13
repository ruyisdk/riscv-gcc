#ifndef GW_TYPE
#define GW_TYPE i32
#define GW_CARRIER __INT32_TYPE__
#endif
#ifndef GW_INDEX
#define GW_INDEX u32
#define GW_INDEX_CARRIER __UINT32_TYPE__
#endif
#include "ztt-gather-wide.h"

#ifdef __cplusplus
extern "C" {
#endif
void gw_index_live (GW_ARGS)
{
  GW_LOAD;
  GW_T(GW_TYPE) c = GW_NAME(mcolgather_ew, GW_TYPE) (a, b);
  __riscv_ztt_mss_rm (out, c);
  __riscv_ztt_mss_rm (saved_index, b);
}

void gw_shared (const __UINT32_TYPE__ *in, __UINT32_TYPE__ *out)
{
  __riscv_ztt_u32_1x1_t a = __riscv_ztt_mls_rm_u32_1x1 (in);
  __riscv_ztt_u32_1x1_t b = __riscv_ztt_mcolgather_ew_u32_1x1 (a, a);
  __riscv_ztt_mss_rm (out, b);
}
#ifdef __cplusplus
}
#endif
