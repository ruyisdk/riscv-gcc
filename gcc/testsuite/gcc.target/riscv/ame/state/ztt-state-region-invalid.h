#include <stddef.h>
#include <riscv_ztt.h>

int rejected (unsigned long desc, int arbitrary, signed char *out)
{
  unsigned long status = __riscv_ztt_ame_acquire (desc);
#if CASE == 1
  if (!status)
    return 0;
#elif CASE == 2
  if (!(status & 1))
    return 0;
  __riscv_ztt_ame_release ();
  if (!(status & 1))
    return 0;
#elif CASE == 3
  if (!arbitrary)
    return 0;
#elif CASE == 4
  if (!(status & 1) && arbitrary)
    return 0;
#elif CASE == 5
  __riscv_ztt_get_amefflags ();
  if (!(status & 1))
    return 0;
#elif CASE == 6
  if (!(status & 1))
    return 0;
  if (arbitrary)
    __riscv_ztt_ame_release ();
#elif CASE == 7
  if (!(status | 2))
    return 0;
#endif
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, value);
  __riscv_ztt_ame_release ();
  return 1;
}
