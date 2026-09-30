#include <riscv_ztt.h>

#ifdef LARGE_BANKS
typedef __riscv_ztt_i128_storage_t element_t;
typedef __riscv_ztt_i128_rnu_1x1_t matrix_t;
#define CLEAR __riscv_ztt_mclear_m_i128_rnu_1x1
#else
typedef signed char element_t;
typedef __riscv_ztt_i8_rnu_1x1_t matrix_t;
#define CLEAR __riscv_ztt_mclear_m_i8_rnu_1x1
#endif

int
guarded_effect (unsigned long desc, element_t *out)
{
  unsigned long status = __riscv_ztt_ame_acquire (desc);
  if (!(status & 1))
    return 0;
  matrix_t value = CLEAR ();
  __riscv_ztt_mss_rm (out, value);
  __riscv_ztt_ame_release ();
  return 1;
}
