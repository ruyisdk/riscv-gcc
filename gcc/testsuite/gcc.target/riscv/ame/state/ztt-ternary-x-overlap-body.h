#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef __INT64_TYPE__ tx_i64;
typedef __riscv_ztt_i128_storage_t tx_i128;
#define TX_OVERLAP(B) \
void tx_exp_same##B (const void *a, const void *b, void *out, void *copy, long e) \
{ \
  __riscv_ztt_i##B##_rnu_1x1_t d \
    = __riscv_ztt_mls_rm_i##B##_rnu_1x1 ((const tx_i##B *) a); \
  d = __riscv_ztt_mldexpacc_ew_x_i##B##_rnu_1x1 (d, d, e); \
  __riscv_ztt_mss_rm ((tx_i##B *) out, d); \
} \
void tx_exp_distinct##B (const void *a, const void *b, void *out, void *copy, long e) \
{ \
  __riscv_ztt_i##B##_rnu_1x1_t d \
    = __riscv_ztt_mls_rm_i##B##_rnu_1x1 ((const tx_i##B *) a); \
  __riscv_ztt_i##B##_rnu_1x1_t x \
    = __riscv_ztt_mls_rm_i##B##_rnu_1x1 ((const tx_i##B *) b); \
  d = __riscv_ztt_mldexpacc_ew_x_i##B##_rnu_1x1 (d, x, e); \
  __riscv_ztt_mss_rm ((tx_i##B *) out, d); \
  __riscv_ztt_mss_rm ((tx_i##B *) copy, x); \
}
#if __riscv_ztt_uds <= 64
TX_OVERLAP (64)
#endif
TX_OVERLAP (128)
#undef TX_OVERLAP
#ifdef __cplusplus
}
#endif
