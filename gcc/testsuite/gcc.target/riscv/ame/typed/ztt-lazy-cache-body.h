#include <riscv_ztt.h>

#ifdef __riscv_ztt_runtime_n
#define ZTT_LAZY_EXTRA(D, S) \
  __riscv_ztt_i32_##D##_accx1_t old = __riscv_ztt_mzero_acc_i32_##D##_accx1 (); \
  __riscv_ztt_i32_##D##_accx1_t mixed \
    = __riscv_ztt_mmulacc_2d_i32_##D##_accx1 (old, a, b); \
  __asm__ volatile ("" : : "War" (mixed)); \
  __riscv_ztt_i4_##S##_1x2_t nibble = __riscv_ztt_mzero_m_i4_##S##_1x2 (); \
  __riscv_ztt_u16_##S##_2x1_t wide = __riscv_ztt_mzero_m_u16_##S##_2x1 (); \
  __riscv_ztt_i32_##D##_accx1_t extended \
    = __riscv_ztt_mmulacc_2d_i32_##D##_accx1 (old, nibble, wide); \
  __asm__ volatile ("" : : "War" (extended));
#else
#define ZTT_LAZY_EXTRA(D, S) \
  c = __riscv_ztt_madd_ew_x_i32_##D##_1x1_i16_##S \
    (a, __riscv_ztt_scalar_make_i16_##S ((__INT16_TYPE__) 3)); \
  __riscv_ztt_mss_rm (out + 2, c);
#endif

#define ZTT_LAZY_CASE(D, S) \
  { \
    __riscv_ztt_i8_##S##_1x1_t a = __riscv_ztt_mls_rm_i8_##S##_1x1 (left); \
    __riscv_ztt_u16_##S##_1x1_t b = __riscv_ztt_mls_rm_u16_##S##_1x1 (right); \
    __riscv_ztt_i32_##D##_1x1_t c = __riscv_ztt_mconv_ew_i32_##D##_1x1 (a); \
    __riscv_ztt_mss_rm (out, c); \
    c = __riscv_ztt_mmul_ew_i32_##D##_1x1 (a, b); \
    __riscv_ztt_mss_rm (out + 1, c); \
    ZTT_LAZY_EXTRA (D, S) \
  }

#define ZTT_LAZY_ROW(D) \
  ZTT_LAZY_CASE (D, rnu) \
  ZTT_LAZY_CASE (D, rne) \
  ZTT_LAZY_CASE (D, rdn) \
  ZTT_LAZY_CASE (D, rod)

void
ZTT_LAZY_NAME (__INT32_TYPE__ *out, const __INT8_TYPE__ *left,
	       const __UINT16_TYPE__ *right)
{
  ZTT_LAZY_ROW (rnu)
  ZTT_LAZY_ROW (rne)
  ZTT_LAZY_ROW (rdn)
  ZTT_LAZY_ROW (rod)
}

#undef ZTT_LAZY_ROW
#undef ZTT_LAZY_CASE
#undef ZTT_LAZY_EXTRA
