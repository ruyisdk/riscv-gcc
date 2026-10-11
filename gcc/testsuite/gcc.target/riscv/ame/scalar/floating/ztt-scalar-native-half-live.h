#include <stdint.h>
#include <riscv_ztt.h>

#define LIVE(T, C) \
C native_live_##T (uint32_t *out, const uint32_t *b, volatile C *in) \
{ \
  C x = *in; \
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_x_u32_rnu_1x1_##T \
    (__riscv_ztt_mls_rm_u32_rnu_1x1 (b), __riscv_ztt_scalar_make_##T (x))); \
  return x; \
}

LIVE (f16_rne, _Float16)
LIVE (bf16_rne, __bf16)
