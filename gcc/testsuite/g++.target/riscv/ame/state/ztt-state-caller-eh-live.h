#include <riscv_ztt.h>
extern void may_throw ();

/* M/ACC are live before the throw. A new proof must precede their reloads.  */
void caller_exception_live (const signed char *in, signed char *out_m,
                            signed char *out_a)
{
  auto m = __riscv_ztt_mls_rm_i8_rne_1x2 (in);
  auto a = __riscv_ztt_mcopy_m2a_i8_rne_accx2 (m);
  asm volatile ("" : : "Wmr" (m), "War" (a));
  try { may_throw (); }
  catch (...)
    {
#ifndef EH_UNGUARDED
      if (!__riscv_ztt_get_ameown ())
        return;
#endif
    }
  __riscv_ztt_mss_rm (out_m, m);
  __riscv_ztt_mss_rm (out_a, __riscv_ztt_mcopy_a2m_i8_rne_1x2 (a));
}
