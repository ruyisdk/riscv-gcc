#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ZERO(D, K) \
void zero_##D##_##K (void) \
{ \
  __riscv_ztt_##D##_accx##K##_t value = __riscv_ztt_mzero_acc_##D##_accx##K (); \
  __asm__ volatile ("" : : "War" (value)); \
}

ZERO(i32_rnu, 1)
ZERO(u32_rne_sat, 1)
ZERO(i128_rdn, 1)
ZERO(u128_rod, 2)
ZERO(u8_rnu, 4)
ZERO(i4_rod_sat, 8)
ZERO(i32_rne, 4)
ZERO(f32_rne, 1)
ZERO(bf16_rne, 2)

void raw_acc_zero (unsigned long descriptor)
{
  __builtin_riscv_ztt_asettyp (0, descriptor);
  __builtin_riscv_ztt_mzero_2d_acc (0);
}

#ifdef __cplusplus
}
#endif
