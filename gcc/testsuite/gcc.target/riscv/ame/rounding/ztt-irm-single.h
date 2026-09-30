/* single-M
   i8 integer rounding-mode subset.  */

#include <riscv_ztt.h>

#if __riscv_ztt_intrinsic != 2002 || __riscv_ztt_i8_1x1_irm != 15
#error incorrect experimental interface capability
#endif
#ifdef TEST_RUNTIME
#if __riscv_ztt_profile != 2 || !defined (__riscv_ztt_runtime_n)
#error incorrect runtime profile
#endif
#if defined (__riscv_ztt_n) || defined (__riscv_ztt_nelem)
#error runtime N must not become a type constant
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
single_rnu (const signed char *in, signed char *out, signed char *other)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mls_rm_i8_rnu_1x1 (in);
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  b = __riscv_ztt_madd_ew_i8_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
single_rne (const signed char *in, signed char *out, signed char *other)
{
  __riscv_ztt_i8_rne_1x1_t a = __riscv_ztt_mls_rm_i8_rne_1x1 (in);
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  b = __riscv_ztt_madd_ew_i8_rne_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
single_rdn (const signed char *in, signed char *out, signed char *other)
{
  __riscv_ztt_i8_rdn_1x1_t a = __riscv_ztt_mls_rm_i8_rdn_1x1 (in);
  __riscv_ztt_i8_rdn_1x1_t b = __riscv_ztt_mclear_m_i8_rdn_1x1 ();
  b = __riscv_ztt_madd_ew_i8_rdn_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
single_rod (const signed char *in, signed char *out, signed char *other)
{
  __riscv_ztt_i8_rod_1x1_t a = __riscv_ztt_mls_rm_i8_rod_1x1 (in);
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mclear_m_i8_rod_1x1 ();
  b = __riscv_ztt_madd_ew_i8_rod_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
default_rnu (const signed char *in, signed char *out)
{
  __riscv_ztt_i8_1x1_t a = __riscv_ztt_mls_rm_i8_1x1 (in);
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mclear_m_i8_1x1 ();
  a = __riscv_ztt_madd_ew_i8_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mzero_m_i8_1x1 ());
}

#ifdef __cplusplus
}
static_assert (__is_same (__riscv_ztt_i8_1x1_t, __riscv_ztt_i8_rnu_1x1_t), "");
static_assert (!__is_same (__riscv_ztt_i8_rnu_1x1_t, __riscv_ztt_i8_rne_1x1_t), "");
static_assert (!__is_same (__riscv_ztt_i8_rdn_1x1_t, __riscv_ztt_i8_rod_1x1_t), "");
#else
_Static_assert (__builtin_types_compatible_p
                (__riscv_ztt_i8_1x1_t, __riscv_ztt_i8_rnu_1x1_t), "");
_Static_assert (!__builtin_types_compatible_p
                (__riscv_ztt_i8_rnu_1x1_t, __riscv_ztt_i8_rne_1x1_t), "");
_Static_assert (!__builtin_types_compatible_p
                (__riscv_ztt_i8_rdn_1x1_t, __riscv_ztt_i8_rod_1x1_t), "");
#endif
