#include <stddef.h>
#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ordinary_query_call (signed char *);

#if QUERY_CASE == 0
int query_guard (signed char *out)
{
  if (!__riscv_ztt_get_ameown ())
    return 0;
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, value);
  return 1;
}

int query_guard_call (signed char *out)
{
  if (!__riscv_ztt_get_ameown ())
    return 0;
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  ordinary_query_call (out);
  __riscv_ztt_mss_rm (out, value);
  return 1;
}

int query_guard_builtin (signed char *out)
{
  if (!__builtin_riscv_ztt_get_ameown ())
    return 0;
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, value);
  return 1;
}
#elif QUERY_CASE == 1
/* Merely observing ameown does not revoke the caller-owned contract.  */
size_t query_observer (signed char *out)
{
  size_t observed = __riscv_ztt_get_ameown ();
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, value);
  return observed;
}

size_t query_observer_after (signed char *out)
{
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, value);
  return __riscv_ztt_get_ameown ();
}

size_t query_observer_call (signed char *out)
{
  size_t observed = __riscv_ztt_get_ameown ();
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  ordinary_query_call (out);
  __riscv_ztt_mss_rm (out, value);
  return observed;
}
#elif QUERY_CASE == 2
size_t query_scalar (void)
{
  return __riscv_ztt_get_ameown ();
}
#else
#error "Select a query contract"
#endif

#ifdef __cplusplus
}
#endif
