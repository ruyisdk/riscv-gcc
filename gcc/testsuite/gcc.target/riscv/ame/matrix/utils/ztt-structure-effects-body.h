#include <stdint.h>
#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C"
#endif
void
structure_effect (int32_t *out, const int32_t *a, const int32_t *b,
		  volatile int *count)
{
  __riscv_ztt_i32_rnu_1x1_t x = __riscv_ztt_mls_rm_i32_rnu_1x1 (a);
  __riscv_ztt_i32_rnu_1x1_t y = __riscv_ztt_mls_rm_i32_rnu_1x1
    (((void) (*count = *count + 1), b));
  __riscv_ztt_i32_rnu_1x2_t pair = __riscv_ztt_mconcat_m_i32_rnu_1x2 (x, y);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mextract_i32_rnu_1x1 (pair, 0));
}
