#define RB_TYPE f32_rne
#define RB_CARRIER float
#include "ztt-bcast-control.h"

#ifdef __cplusplus
extern "C" {
#endif
void rb_dynamic (RB_ARGS)
{
  RB_LOAD; RB_ROW (b, a, k); RB_ROW (c, b, k);
  __riscv_ztt_mss_rm (out, c);
}
void rb_zero (RB_ARGS)
{
  RB_LOAD; RB_COL (b, a, k); RB_COL (c, b, 0);
  __riscv_ztt_mss_rm (out, c);
}
#ifdef __cplusplus
}
#endif
