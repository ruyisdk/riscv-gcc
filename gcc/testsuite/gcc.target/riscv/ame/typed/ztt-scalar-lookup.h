#include <riscv_ztt.h>

#define LOOKUP(TC) \
__UINTPTR_TYPE__ scalar_lookup_##TC (__UINTPTR_TYPE__ bits) \
{ \
  typedef __riscv_ztt_##TC##_scalar_t alias; \
  alias value = __riscv_ztt_scalar_from_bits_##TC (bits); \
  const alias qualified = value; \
  volatile alias live = qualified; \
  return __riscv_ztt_scalar_bits_##TC (value) \
    + __riscv_ztt_scalar_bits_##TC (qualified) \
    + __riscv_ztt_scalar_bits_##TC (live); \
}

#ifdef __cplusplus
extern "C" {
#endif
LOOKUP (u8_rnu)
LOOKUP (i8_rne)
LOOKUP (i32_rnu)
LOOKUP (i64_rdn)
LOOKUP (u16_rod_sat)
LOOKUP (u128_rod_sat)
LOOKUP (f16_rne)
LOOKUP (bf16_rtz)
LOOKUP (f32_rmm)
LOOKUP (f64_rno)

__UINTPTR_TYPE__ scalar_lookup_alias (__riscv_ztt_i32_scalar_t value)
{
  return __riscv_ztt_scalar_bits_i32_rnu (value);
}
#ifdef __cplusplus
}
#endif
#undef LOOKUP
