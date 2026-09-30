/* Q32.  */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
void msll_8_8_8_1x32 (uint8_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u8_rdn_1x32 (a, c));
}
void msrl_8_8_8_1x32 (uint8_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u8_rdn_1x32 (a, c));
}
void msra_8_8_8_1x32 (uint8_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u8_rdn_1x32 (a, c));
}
#if __riscv_ztt_uds == 128
void msll_8_8_16_1x32 (uint8_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u8_rdn_1x32 (a, c));
}
void msrl_8_8_16_1x32 (uint8_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u8_rdn_1x32 (a, c));
}
void msra_8_8_16_1x32 (uint8_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u8_rdn_1x32 (a, c));
}
#endif
void msll_8_8_0_1x32 (uint8_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_x_u8_rdn_1x32 (a, count));
}
void msrl_8_8_0_1x32 (uint8_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_x_u8_rdn_1x32 (a, count));
}
void msra_8_8_0_1x32 (uint8_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_x_u8_rdn_1x32 (a, count));
}
#if __riscv_ztt_uds == 128
void msll_8_16_8_1x32 (uint8_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u8_rdn_1x32 (a, c));
}
void msrl_8_16_8_1x32 (uint8_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u8_rdn_1x32 (a, c));
}
void msra_8_16_8_1x32 (uint8_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u8_rdn_1x32 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_8_16_16_1x32 (uint8_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u8_rdn_1x32 (a, c));
}
void msrl_8_16_16_1x32 (uint8_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u8_rdn_1x32 (a, c));
}
void msra_8_16_16_1x32 (uint8_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u8_rdn_1x32 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_8_16_0_1x32 (uint8_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_x_u8_rdn_1x32 (a, count));
}
void msrl_8_16_0_1x32 (uint8_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_x_u8_rdn_1x32 (a, count));
}
void msra_8_16_0_1x32 (uint8_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_x_u8_rdn_1x32 (a, count));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_8_8_1x32 (uint16_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u16_rdn_1x32 (a, c));
}
void msrl_16_8_8_1x32 (uint16_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u16_rdn_1x32 (a, c));
}
void msra_16_8_8_1x32 (uint16_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u16_rdn_1x32 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_8_16_1x32 (uint16_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u16_rdn_1x32 (a, c));
}
void msrl_16_8_16_1x32 (uint16_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u16_rdn_1x32 (a, c));
}
void msra_16_8_16_1x32 (uint16_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u16_rdn_1x32 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_8_0_1x32 (uint16_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_x_u16_rdn_1x32 (a, count));
}
void msrl_16_8_0_1x32 (uint16_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_x_u16_rdn_1x32 (a, count));
}
void msra_16_8_0_1x32 (uint16_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_1x32_t a = __riscv_ztt_mls_rm_i8_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_x_u16_rdn_1x32 (a, count));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_16_8_1x32 (uint16_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u16_rdn_1x32 (a, c));
}
void msrl_16_16_8_1x32 (uint16_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u16_rdn_1x32 (a, c));
}
void msra_16_16_8_1x32 (uint16_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u8_rod_1x32_t c = __riscv_ztt_mls_rm_u8_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u16_rdn_1x32 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_16_16_1x32 (uint16_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u16_rdn_1x32 (a, c));
}
void msrl_16_16_16_1x32 (uint16_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u16_rdn_1x32 (a, c));
}
void msra_16_16_16_1x32 (uint16_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_u16_rod_1x32_t c = __riscv_ztt_mls_rm_u16_rod_1x32 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u16_rdn_1x32 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_16_0_1x32 (uint16_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_x_u16_rdn_1x32 (a, count));
}
void msrl_16_16_0_1x32 (uint16_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_x_u16_rdn_1x32 (a, count));
}
void msra_16_16_0_1x32 (uint16_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_1x32_t a = __riscv_ztt_mls_rm_i16_rne_1x32 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_x_u16_rdn_1x32 (a, count));
}
#endif
void msll_8_8_8_32x1 (uint8_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u8_rdn_32x1 (a, c));
}
void msrl_8_8_8_32x1 (uint8_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u8_rdn_32x1 (a, c));
}
void msra_8_8_8_32x1 (uint8_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u8_rdn_32x1 (a, c));
}
#if __riscv_ztt_uds == 128
void msll_8_8_16_32x1 (uint8_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u8_rdn_32x1 (a, c));
}
void msrl_8_8_16_32x1 (uint8_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u8_rdn_32x1 (a, c));
}
void msra_8_8_16_32x1 (uint8_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u8_rdn_32x1 (a, c));
}
#endif
void msll_8_8_0_32x1 (uint8_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_x_u8_rdn_32x1 (a, count));
}
void msrl_8_8_0_32x1 (uint8_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_x_u8_rdn_32x1 (a, count));
}
void msra_8_8_0_32x1 (uint8_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_x_u8_rdn_32x1 (a, count));
}
#if __riscv_ztt_uds == 128
void msll_8_16_8_32x1 (uint8_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u8_rdn_32x1 (a, c));
}
void msrl_8_16_8_32x1 (uint8_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u8_rdn_32x1 (a, c));
}
void msra_8_16_8_32x1 (uint8_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u8_rdn_32x1 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_8_16_16_32x1 (uint8_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u8_rdn_32x1 (a, c));
}
void msrl_8_16_16_32x1 (uint8_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u8_rdn_32x1 (a, c));
}
void msra_8_16_16_32x1 (uint8_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u8_rdn_32x1 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_8_16_0_32x1 (uint8_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_x_u8_rdn_32x1 (a, count));
}
void msrl_8_16_0_32x1 (uint8_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_x_u8_rdn_32x1 (a, count));
}
void msra_8_16_0_32x1 (uint8_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_x_u8_rdn_32x1 (a, count));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_8_8_32x1 (uint16_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u16_rdn_32x1 (a, c));
}
void msrl_16_8_8_32x1 (uint16_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u16_rdn_32x1 (a, c));
}
void msra_16_8_8_32x1 (uint16_t *out, const int8_t *in, const uint8_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u16_rdn_32x1 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_8_16_32x1 (uint16_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u16_rdn_32x1 (a, c));
}
void msrl_16_8_16_32x1 (uint16_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u16_rdn_32x1 (a, c));
}
void msra_16_8_16_32x1 (uint16_t *out, const int8_t *in, const uint16_t *counts)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u16_rdn_32x1 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_8_0_32x1 (uint16_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_x_u16_rdn_32x1 (a, count));
}
void msrl_16_8_0_32x1 (uint16_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_x_u16_rdn_32x1 (a, count));
}
void msra_16_8_0_32x1 (uint16_t *out, const int8_t *in, size_t count)
{
  __riscv_ztt_i8_rne_32x1_t a = __riscv_ztt_mls_rm_i8_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_x_u16_rdn_32x1 (a, count));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_16_8_32x1 (uint16_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u16_rdn_32x1 (a, c));
}
void msrl_16_16_8_32x1 (uint16_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u16_rdn_32x1 (a, c));
}
void msra_16_16_8_32x1 (uint16_t *out, const int16_t *in, const uint8_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u8_rod_32x1_t c = __riscv_ztt_mls_rm_u8_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u16_rdn_32x1 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_16_16_32x1 (uint16_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_u16_rdn_32x1 (a, c));
}
void msrl_16_16_16_32x1 (uint16_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_u16_rdn_32x1 (a, c));
}
void msra_16_16_16_32x1 (uint16_t *out, const int16_t *in, const uint16_t *counts)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_u16_rod_32x1_t c = __riscv_ztt_mls_rm_u16_rod_32x1 (counts);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_u16_rdn_32x1 (a, c));
}
#endif
#if __riscv_ztt_uds == 128
void msll_16_16_0_32x1 (uint16_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msll_ew_x_u16_rdn_32x1 (a, count));
}
void msrl_16_16_0_32x1 (uint16_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msrl_ew_x_u16_rdn_32x1 (a, count));
}
void msra_16_16_0_32x1 (uint16_t *out, const int16_t *in, size_t count)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mls_rm_i16_rne_32x1 (in);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msra_ew_x_u16_rdn_32x1 (a, count));
}
#endif
