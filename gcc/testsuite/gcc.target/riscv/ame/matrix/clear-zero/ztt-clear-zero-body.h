/* Experimental single-M clear/zero names from intrinsic draft v0.2.4.  */

#include <riscv_ztt.h>

#if __riscv_ztt_intrinsic != 2002
#error full v0.2.4 support must not be advertised
#endif
#if __riscv_ztt_i8_rne_1x1_clear_zero != 1
#error missing single-M clear/zero capability
#endif
#if __riscv_ztt_uds != 8 || __riscv_ztt_mregs != 16 || __riscv_ztt_accregs != 4
#error incorrect resource profile
#endif
#ifdef ZTT_TEST_RUNTIME
#if !defined (__riscv_ztt_runtime_n) || __riscv_ztt_profile != 2
#error incorrect runtime profile
#endif
#if defined (__riscv_ztt_n) || defined (__riscv_ztt_nelem)
#error runtime N must not become a compile-time constant
#endif
#else
#if __riscv_ztt_profile != 1 || __riscv_ztt_n != 128
#error incorrect fixed profile
#endif
#endif

typedef __riscv_ztt_i8_rne_1x1_t matrix_t;

#ifdef __cplusplus
extern "C" {
#endif

void
new_zero (signed char *out)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mzero_m_i8_rne_1x1 ());
}

void
old_zero (signed char *out)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mzero_2d_m_i8_rne_1x1 ());
}

void
clear_store (signed char *out)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mclear_m_i8_rne_1x1 ());
}

void
load_then_clear (const signed char *in, signed char *out, signed char *after)
{
  matrix_t value = __riscv_ztt_mls_rm_i8_rne_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
  value = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_mss_rm (after, value);
}

void
repeated_clear (const signed char *in, signed char *out, signed char *middle,
                signed char *after)
{
  matrix_t value = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_mss_rm (out, value);
  value = __riscv_ztt_madd_ew_i8_rne_1x1
    (value, __riscv_ztt_mls_rm_i8_rne_1x1 (in));
  __riscv_ztt_mss_rm (middle, value);
  value = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_mss_rm (after, value);
}

void
keep_old (const signed char *in, signed char *out, signed char *after)
{
  matrix_t old = __riscv_ztt_mls_rm_i8_rne_1x1 (in);
  matrix_t cleared = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  __riscv_ztt_mss_rm (out, cleared);
  __riscv_ztt_mss_rm (after, old);
}

void
discard_clear (void)
{
  __riscv_ztt_mclear_m_i8_rne_1x1 ();
}

void
branch_clear (int flag, const signed char *in, signed char *out)
{
  matrix_t value;
  if (flag)
    value = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  else
    value = __riscv_ztt_mls_rm_i8_rne_1x1 (in);
  __riscv_ztt_mss_rm (out, value);
}

void
loop_clear (unsigned int count, const signed char *in, signed char *out)
{
  matrix_t value = __riscv_ztt_mls_rm_i8_rne_1x1 (in);
  for (unsigned int i = 0; i < count; ++i)
    {
      matrix_t cleared = __riscv_ztt_mclear_m_i8_rne_1x1 ();
      __riscv_ztt_mss_rm
        (out, __riscv_ztt_madd_ew_i8_rne_1x1 (value, cleared));
    }
}

#ifdef __cplusplus
}
#endif
