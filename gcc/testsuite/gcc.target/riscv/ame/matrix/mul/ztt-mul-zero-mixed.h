#include <riscv_ztt.h>
#define MIXED(name, op) \
void name (const __INT16_TYPE__ *in, __INT32_TYPE__ *out, \
           __INT16_TYPE__ *saved) \
{ \
  __riscv_ztt_i16_rnu_1x1_t a = __riscv_ztt_mls_rm_i16_rnu_1x1 (in); \
  __riscv_ztt_i16_rnu_1x1_t z = __riscv_ztt_mzero_m_i16_rnu_1x1 (); \
  __riscv_ztt_i32_rnu_1x1_t v = op (a, z); \
  __riscv_ztt_mss_rm (saved, a); \
  __riscv_ztt_mss_rm (out, v); \
}
MIXED(mixed_product, __riscv_ztt_mmul_ew_i32_rnu_1x1)
MIXED(mixed_negative, __riscv_ztt_mmulneg_ew_i32_rnu_1x1)
