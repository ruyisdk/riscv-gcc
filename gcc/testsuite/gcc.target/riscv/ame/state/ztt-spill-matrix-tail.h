#include <riscv_ztt.h>

void
scatter_tail (const __UINT32_TYPE__ *in, __UINT32_TYPE__ *out,
	      __UINT32_TYPE__ *saved)
{
  __riscv_ztt_u32_1x1_t a = __riscv_ztt_mls_rm_u32_1x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcolscatadd_ew_u32_1x1 (a, a, a));
  __riscv_ztt_mss_rm (saved, a);
}
