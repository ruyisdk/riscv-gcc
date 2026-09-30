/* scalar bitwise.  */
#include <stdint.h>
#include <riscv_ztt.h>
enum small_value { small_negative = -3 };
void aliases (int8_t *out, const int8_t *p, unsigned long long wide)
{
  __riscv_ztt_i8_1x1_t m = __riscv_ztt_mls_rm_i8_1x1 (p);
  m = __riscv_ztt_mand_ew_x_i8_1x1_i8 (m, __riscv_ztt_scalar_make_i8_rnu (small_negative));
  m = __riscv_ztt_mandnot_ew_x_i8_1x1_u8 (m, __riscv_ztt_scalar_make_u8_rnu (wide));
  m = __riscv_ztt_mor_ew_x_i8_1x1_i16 (m, __riscv_ztt_scalar_make_i16_rnu (-1234));
  m = __riscv_ztt_mornot_ew_x_i8_1x1_u16 (m, __riscv_ztt_scalar_make_u16_rnu (65535));
  m = __riscv_ztt_mxor_ew_x_i8_1x1_i32 (m, __riscv_ztt_scalar_make_i32_rnu (wide != 0));
  __riscv_ztt_mss_rm (out, m);
}
static __inline__ __attribute__((always_inline)) uint32_t
next_counter (volatile uint32_t *counter)
{
  uint32_t old = *counter;
  *counter = old + 1;
  return old;
}
void once (int8_t *out, const int8_t *p, volatile uint32_t *counter)
{
  __riscv_ztt_i8_1x1_t m = __riscv_ztt_mls_rm_i8_1x1 (p);
  m = __riscv_ztt_mandnot_ew_x_i8_1x1_u32 (m, __riscv_ztt_scalar_make_u32_rnu (next_counter (counter)));
  __riscv_ztt_mss_rm (out, m);
}
