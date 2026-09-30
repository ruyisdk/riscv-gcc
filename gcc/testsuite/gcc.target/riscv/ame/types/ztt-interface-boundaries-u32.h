/* Eight M registers fit in UDS32/M16; the 32-M negative does not.  */
#include <riscv_ztt.h>

void broadcast_supported (long x)
{
  __riscv_ztt_i32_1x8_t m = __riscv_ztt_mbcast_m_x_i32_1x8_i32
    (__riscv_ztt_scalar_make_i32_rnu (x));
  __asm__ volatile ("" : : "Wmr" (m));
}
