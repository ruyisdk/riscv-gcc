#include <riscv_ztt.h>

static __inline__ __attribute__((always_inline)) unsigned int
scalar_next (volatile unsigned int *p)
{
  unsigned int old = *p;
  *p = old + 1;
  return old;
}

unsigned int scalar_compare (unsigned long long value)
{
  return __riscv_ztt_scalar_bits_i8_rnu
    (__riscv_ztt_scalar_make_i8_rnu (value != 0));
}

unsigned int scalar_short_circuit (int flag, volatile unsigned int *p)
{
  return __riscv_ztt_scalar_bits_u8_rnu
    (__riscv_ztt_scalar_from_bits_u8_rnu (flag && scalar_next (p)));
}

unsigned int scalar_conditional (int flag, volatile unsigned int *p)
{
  return __riscv_ztt_scalar_bits_u32_rnu
    (__riscv_ztt_scalar_make_u32_rnu (flag ? scalar_next (p) : 7));
}

unsigned int scalar_comma (volatile unsigned int *p)
{
  return __riscv_ztt_scalar_bits_u32_rnu
    (__riscv_ztt_scalar_make_u32_rnu ((scalar_next (p), 42)));
}
