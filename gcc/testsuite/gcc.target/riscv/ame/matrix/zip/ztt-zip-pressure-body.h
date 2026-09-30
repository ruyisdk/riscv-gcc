/* preserve old groups under pressure.  */
#include <stdint.h>
#include <riscv_ztt.h>

#define TEST(F) \
  void F##_pressure (int32_t *oa, int32_t *ob, int32_t *oc, int32_t *od, \
                      int32_t *oe, int32_t *of, int32_t *old_a, int32_t *old_b, \
                      const int32_t *ia, const int32_t *ib, const int32_t *ic, \
                      const int32_t *id, const int32_t *ie, const int32_t *iff) \
  { \
    __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (ia); \
    __riscv_ztt_i32_1x1_t b = __riscv_ztt_mls_rm_i32_1x1 (ib); \
    __riscv_ztt_i32_1x1_t c = __riscv_ztt_mls_rm_i32_1x1 (ic); \
    __riscv_ztt_i32_1x1_t d = __riscv_ztt_mls_rm_i32_1x1 (id); \
    __riscv_ztt_i32_1x1_t e = __riscv_ztt_mls_rm_i32_1x1 (ie); \
    __riscv_ztt_i32_1x1_t f = __riscv_ztt_mls_rm_i32_1x1 (iff); \
    __riscv_ztt_i32_1x1_t copy_a = a; \
    __riscv_ztt_i32_1x1_t copy_b = b; \
    __riscv_ztt_i32_1x2_t pair = __riscv_ztt_mconcat_m_i32_1x2 (a, b); \
    pair = __riscv_ztt_##F##_i32_1x2 (pair); \
    a = __riscv_ztt_mextract_i32_1x1 (pair, 0); \
    b = __riscv_ztt_mextract_i32_1x1 (pair, 1); \
    __riscv_ztt_mss_rm (oa, a); \
    __riscv_ztt_mss_rm (ob, b); \
    __riscv_ztt_mss_rm (oc, c); \
    __riscv_ztt_mss_rm (od, d); \
    __riscv_ztt_mss_rm (oe, e); \
    __riscv_ztt_mss_rm (of, f); \
    __riscv_ztt_mss_rm (old_a, copy_a); \
    __riscv_ztt_mss_rm (old_b, copy_b); \
  }
TEST(mcolzip_ew)
TEST(mrowzip_ew)
TEST(mcolunzip_ew)
TEST(mrowunzip_ew)
