#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TEST_SELF_PREP(B, STORAGE) \
void self_unknown##B (const STORAGE *a, STORAGE *out, long e) \
{ \
  __riscv_ztt_i##B##_rnu_1x1_t x = __riscv_ztt_mls_rm_i##B##_rnu_1x1 (a); \
  __asm__ volatile ("" ::: "memory"); \
  x = __riscv_ztt_mldexpacc_ew_x_i##B##_rnu_1x1 (x, x, e); \
  __riscv_ztt_mss_rm (out, x); \
} \
void self_known##B (const STORAGE *a, STORAGE *out, long e) \
{ \
  __riscv_ztt_i##B##_rnu_1x1_t x = __riscv_ztt_mls_rm_i##B##_rnu_1x1 (a); \
  x = __riscv_ztt_mldexpacc_ew_x_i##B##_rnu_1x1 (x, x, e); \
  __riscv_ztt_mss_rm (out, x); \
} \
void self_distinct##B (const STORAGE *a, const STORAGE *b, STORAGE *out, long e) \
{ \
  __riscv_ztt_i##B##_rnu_1x1_t x = __riscv_ztt_mls_rm_i##B##_rnu_1x1 (a); \
  __riscv_ztt_i##B##_rnu_1x1_t y = __riscv_ztt_mls_rm_i##B##_rnu_1x1 (b); \
  __asm__ volatile ("" ::: "memory"); \
  x = __riscv_ztt_mldexpacc_ew_x_i##B##_rnu_1x1 (x, y, e); \
  __riscv_ztt_mss_rm (out, x); \
} \
void self_live##B (const STORAGE *a, STORAGE *out, STORAGE *copy, long e) \
{ \
  __riscv_ztt_i##B##_rnu_1x1_t x = __riscv_ztt_mls_rm_i##B##_rnu_1x1 (a); \
  __asm__ volatile ("" ::: "memory"); \
  __riscv_ztt_i##B##_rnu_1x1_t y \
    = __riscv_ztt_mldexpacc_ew_x_i##B##_rnu_1x1 (x, x, e); \
  __riscv_ztt_mss_rm (out, y); \
  __riscv_ztt_mss_rm (copy, x); \
}

TEST_SELF_PREP (64, __INT64_TYPE__)
TEST_SELF_PREP (128, __riscv_ztt_i128_storage_t)
#undef TEST_SELF_PREP

#ifdef __cplusplus
}
#endif
