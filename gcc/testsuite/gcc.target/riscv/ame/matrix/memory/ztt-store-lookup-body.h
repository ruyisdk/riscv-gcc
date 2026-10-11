#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

#define STORE_CASE(T, C) \
void store_##T (C *out0, C *out1, const C *in, size_t stride) \
{ \
  __riscv_ztt_##T##_t value = __riscv_ztt_mls_rm_##T (in); \
  __riscv_ztt_mss_rm (out0, value); \
  __riscv_ztt_mss_cm (out0, value); \
  __riscv_ztt_mss_st (out0, stride, value); \
  __riscv_ztt_mss_tst (out0, stride, value); \
  __riscv_ztt_mss_tst (out1, stride, value); \
  __riscv_ztt_mss_st (out1, stride, value); \
  __riscv_ztt_mss_cm (out1, value); \
  __riscv_ztt_mss_rm (out1, value); \
}

STORE_CASE (i8_rne_1x1, int8_t)
STORE_CASE (i8_rnu_1x2, int8_t)
STORE_CASE (i8_rnu_2x1, int8_t)
STORE_CASE (i32_rdn_1x1, int32_t)
STORE_CASE (u128_rod_1x1, __riscv_ztt_u128_storage_t)
STORE_CASE (bf16_rne_1x1, __bf16)
STORE_CASE (f64_rmm_1x1, double)

#undef STORE_CASE
