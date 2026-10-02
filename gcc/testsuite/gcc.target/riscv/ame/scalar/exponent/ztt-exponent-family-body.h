#include <riscv_ztt.h>

/* Canonical names and their default-RM declarations must resolve to the
   same operation across integer, saturating, and floating families.  */
#define CHECK_FAMILY(TYPE, CANONICAL, ALIAS) \
  void family_##TYPE (long e) \
  { \
    __riscv_ztt_##TYPE##_t a = __riscv_ztt_mzero_m_##CANONICAL (); \
    __asm__ volatile ("" : "+Wmr" (a)); \
    __riscv_ztt_##TYPE##_t b = __riscv_ztt_mldexp_ew_x_##ALIAS (a, e); \
    __riscv_ztt_##TYPE##_t c \
      = __riscv_ztt_mldexpacc_ew_x_##CANONICAL (a, b, e); \
    __asm__ volatile ("" : : "Wmr" (c)); \
  }

CHECK_FAMILY (i4_rnu_1x8, i4_rnu_1x8, i4_1x8)
CHECK_FAMILY (u128_rnu_sat_1x1, u128_rnu_sat_1x1, u128_sat_1x1)
CHECK_FAMILY (bf16_rne_1x2, bf16_rne_1x2, bf16_1x2)
/* UDS32 gives this 2x1 value two datatype groups.  */
CHECK_FAMILY (f64_rne_2x1, f64_rne_2x1, f64_2x1)
#undef CHECK_FAMILY
