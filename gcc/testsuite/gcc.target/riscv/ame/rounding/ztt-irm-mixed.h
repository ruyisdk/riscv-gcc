/* single-M
   i8 integer rounding-mode subset.  */

#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

void
mixed (const signed char *in, signed char *out0, signed char *out1,
       signed char *out2, signed char *out3)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mls_rm_i8_rnu_1x1 (in);
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mls_rm_i8_rne_1x1 (in);
  __riscv_ztt_i8_rdn_1x1_t c = __riscv_ztt_mls_rm_i8_rdn_1x1 (in);
  __riscv_ztt_i8_rod_1x1_t d = __riscv_ztt_mls_rm_i8_rod_1x1 (in);
  __riscv_ztt_i8_rnu_1x1_t copy = a;
  __asm__ volatile ("" : "+Wmr" (a), "+Wmr" (copy));
  a = __riscv_ztt_madd_ew_i8_rnu_1x1 (a, copy);
  b = __riscv_ztt_madd_ew_i8_rne_1x1 (b, b);
  c = __riscv_ztt_madd_ew_i8_rdn_1x1 (c, c);
  d = __riscv_ztt_madd_ew_i8_rod_1x1 (d, d);
  __riscv_ztt_mss_rm (out0, a);
  __riscv_ztt_mss_rm (out1, b);
  __riscv_ztt_mss_rm (out2, c);
  __riscv_ztt_mss_rm (out3, d);
}

void
branch_loop (unsigned count, int flag, const signed char *in,
             signed char *out0, signed char *out1)
{
  __riscv_ztt_i8_rdn_1x1_t a;
  if (flag)
    a = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  else
    a = __riscv_ztt_mls_rm_i8_rdn_1x1 (in);
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mls_rm_i8_rod_1x1 (in);
  for (unsigned i = 0; i < count; ++i)
    {
      __riscv_ztt_i8_rdn_1x1_t z = __riscv_ztt_mclear_m_i8_rdn_1x1 ();
      a = __riscv_ztt_madd_ew_i8_rdn_1x1 (a, z);
      b = __riscv_ztt_madd_ew_i8_rod_1x1 (b, b);
      __riscv_ztt_mss_rm (out0, a);
      __riscv_ztt_mss_rm (out1, b);
    }
}

static __inline__ __attribute__ ((always_inline)) void
inline_rnu (const signed char *in, signed char *out)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mls_rm_i8_rnu_1x1 (in));
}

static __inline__ __attribute__ ((always_inline)) void
inline_rne (const signed char *in, signed char *out)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mls_rm_i8_rne_1x1 (in));
}

void
inlined_mixed (const signed char *in, signed char *out0, signed char *out1)
{
  inline_rnu (in, out0);
  inline_rne (in, out1);
}

#ifdef __cplusplus
}
#endif
