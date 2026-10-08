#include <riscv_ztt.h>

#ifdef __cplusplus
#define CHECK(C) static_assert (C, #C)
#else
#define CHECK(C) _Static_assert (C, #C)
#endif

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
CHECK (__builtin_has_attribute (__riscv_ztt_scalar_bits_i32_rnu, nothrow));
CHECK (__builtin_has_attribute (__riscv_ztt_scalar_bits_i32_rnu, leaf));
CHECK (!__builtin_has_attribute (__riscv_ztt_scalar_bits_i32_rnu, deprecated));
extern __typeof__ (__riscv_ztt_scalar_bits_i32_rnu)
  __riscv_ztt_scalar_bits_i32_rnu __attribute__ ((deprecated));
CHECK (__builtin_has_attribute (__riscv_ztt_scalar_bits_i32_rnu, deprecated));
CHECK (!__builtin_has_attribute (__riscv_ztt_scalar_bits_u32_rnu, deprecated));
CHECK (__builtin_has_attribute (__riscv_ztt_scalar_bits_u32_rnu, leaf));
CHECK (__builtin_has_attribute (__riscv_ztt_scalar_bits_u32_rnu, nothrow));

extern __typeof__ (__riscv_ztt_mzero_m_i32_rnu_1x1)
  __riscv_ztt_mzero_m_i32_rnu_1x1 __attribute__ ((deprecated));
CHECK (__builtin_has_attribute (__riscv_ztt_mzero_m_i32_rnu_1x1, deprecated));
CHECK (!__builtin_has_attribute (__riscv_ztt_mzero_m_i32_1x1, deprecated));

int before_collection (int a) { return a + 1; }

#pragma GCC push_options
#pragma GCC target ("arch=+zbb")
#pragma GCC optimize ("O1")
void
later_mixed (__INT32_TYPE__ *out, const __INT8_TYPE__ *left,
	     const __UINT16_TYPE__ *right)
{
  __riscv_ztt_i8_rne_1x1_t a = __riscv_ztt_mls_rm_i8_rne_1x1 (left);
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mls_rm_u16_rod_1x1 (right);
  __riscv_ztt_i32_rnu_1x1_t c = __riscv_ztt_mmul_ew_i32_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, c);
}
#pragma GCC pop_options
CHECK (!__builtin_has_attribute (__riscv_ztt_mzero_m_i32_1x1, target));
CHECK (!__builtin_has_attribute (__riscv_ztt_mzero_m_i32_1x1, optimize));
CHECK (__builtin_has_attribute (later_mixed, target));
CHECK (__builtin_has_attribute (later_mixed, optimize));
int after_collection (int a) { return a + 1; }
CHECK (!__builtin_has_attribute (after_collection, target));
CHECK (!__builtin_has_attribute (after_collection, optimize));
#undef CHECK
