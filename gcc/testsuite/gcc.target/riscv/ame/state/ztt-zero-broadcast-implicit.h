#include <riscv_ztt.h>
void native_zero (void)
{
  __riscv_ztt_i8_rnu_1x1_t v = __riscv_ztt_mbcast_m_x_i8_rnu_1x1_i8_rnu
    (__riscv_ztt_scalar_make_i8_rnu (0));
  __asm__ volatile ("" : : "Wmr" (v));
}
