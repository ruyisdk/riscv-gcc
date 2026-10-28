#include <stdint.h>
#include <riscv_ztt.h>

#define ARGS unsigned long a, unsigned long b, unsigned long c, unsigned long d, \
  unsigned long e, unsigned long f, unsigned long g, unsigned long h, \
  volatile unsigned long home, const int32_t *in, int32_t *out
#define MOVE() \
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mls_rm_i32_rnu_1x1 (in); \
  __riscv_ztt_i32_rnu_accx1_t acc = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (acc))

#ifdef __cplusplus
extern "C" {
#endif

unsigned long home_write (ARGS)
{
  MOVE ();
  home += a + b + c + d + e + f + g + h;
  return home;
}

unsigned long home_zero (ARGS)
{
  MOVE ();
  home = 0;
  return home;
}

unsigned long local_write (ARGS)
{
  volatile unsigned long local = home;
  MOVE ();
  local += a + b + c + d + e + f + g + h;
  return local;
}

unsigned long home_escape (ARGS)
{
  MOVE ();
  return (unsigned long) &home;
}

#ifdef __cplusplus
}
#endif
#undef MOVE
#undef ARGS
