#include <stddef.h>
#include <riscv_ztt.h>

typedef __riscv_ztt_i8_rnu_1x1_t matrix_t;
extern void ordinary_call (signed char *);

static __attribute__((always_inline)) inline void
write_value (signed char *out)
{
  matrix_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, value);
}

int guarded (unsigned long desc, signed char *out)
{
  unsigned long status = __riscv_ztt_ame_acquire (desc);
  if (!(status & 1))
    return 0;
  write_value (out);
  __riscv_ztt_ame_release ();
  return 1;
}

int queried (signed char *out)
{
  if (!__riscv_ztt_get_ameown ())
    return 0;
  write_value (out);
  __riscv_ztt_ame_release ();
  return 1;
}

int joined (unsigned long desc, int choose, signed char *out)
{
  unsigned long status;
  if (choose)
    status = __riscv_ztt_ame_acquire (desc);
  else
    status = __riscv_ztt_ame_acquire (desc + 1);
  if (!(status & 1))
    return 0;
  write_value (out);
  __riscv_ztt_ame_release ();
  return 1;
}

int repeated (unsigned long desc, int count, signed char *out)
{
  int done = 0;
  while (count-- > 0)
    {
      if (!(__riscv_ztt_ame_acquire (desc) & 1))
        continue;
      write_value (out);
      __riscv_ztt_ame_release ();
      ++done;
    }
  return done;
}

int normal_call (unsigned long desc, signed char *out)
{
  if (!(__riscv_ztt_ame_acquire (desc) & 1))
    return 0;
  matrix_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  ordinary_call (out);
  __riscv_ztt_mss_rm (out, value);
  __riscv_ztt_ame_release ();
  return 1;
}

int reacquired (unsigned long desc, signed char *out)
{
  if (!(__riscv_ztt_ame_acquire (desc) & 1))
    return 0;
  matrix_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_ame_release ();
  if (!(__riscv_ztt_ame_acquire (desc) & 1))
    return 0;
  __riscv_ztt_mss_rm (out, value);
  __riscv_ztt_ame_release ();
  return 1;
}
