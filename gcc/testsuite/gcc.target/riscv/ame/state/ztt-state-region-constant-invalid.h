#include <riscv_ztt.h>
void constant_cannot_grant (unsigned long descriptor, signed char *out, int pick)
{
  unsigned long status = __riscv_ztt_ame_acquire (descriptor);
#if CONSTANT_CASE == 0
  unsigned long selector = (status & 1) ? 1 : 1;
#elif CONSTANT_CASE == 1
  unsigned long selector = pick ? 0 : 1;
  (void) status;
#else
  unsigned long selector = (status & 1) ? 1 : 0;
  __riscv_ztt_ame_release ();
#endif
  if (selector == 1)
    {
      __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
      __riscv_ztt_mss_rm (out, value);
    }
  __riscv_ztt_ame_release ();
}
