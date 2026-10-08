#include <riscv_ztt.h>

#define ZERO(D, S) \
void zero_##D##_##S (void) \
{ \
  __riscv_ztt_##D##_##S##_t x = __riscv_ztt_mzero_m_##D##_##S (); \
  __asm__ volatile ("" : : "Wmr" (x)); \
}
ZERO(i32_rnu, 1x1)
ZERO(u32_rne_sat, 1x1)
ZERO(i64_rdn, 1x1)
ZERO(u128_rod, 1x1)
ZERO(u8_rnu, 1x4)
ZERO(i4_rod_sat, 1x8)
ZERO(i32_rne, 1x2)
ZERO(f32_rne, 1x1)

void acc_zero (void)
{
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mzero_acc_i32_rnu_accx1 ();
  __asm__ volatile ("" : : "War" (a));
}

void raw_zero (unsigned long d)
{
  __builtin_riscv_ztt_msettyp (0, d);
  __builtin_riscv_ztt_mzero_2d_m (0);
}
