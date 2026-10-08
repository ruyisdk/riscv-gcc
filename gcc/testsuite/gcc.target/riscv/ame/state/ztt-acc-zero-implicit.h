#include <riscv_ztt.h>
void zero_acc_i8 (void)
{
  __riscv_ztt_i8_rnu_accx1_t value = __riscv_ztt_mzero_acc_i8_rnu_accx1 ();
  __asm__ volatile ("" : : "War" (value));
}
