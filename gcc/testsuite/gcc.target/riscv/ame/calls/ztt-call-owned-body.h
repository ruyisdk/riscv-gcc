/* Ownership is managed by scalar wrappers.  Keep the typed kernel as a
   call boundary so its frame, N query and spills stay inside the owned
   interval, including under LTO.  This does not allow typed objects to
   cross acquire/release in the same function.  The wrappers require MS
   enabled and unowned entry, and the kernel must return normally with
   ownership unchanged.  They are not nested ownership guards.  */
#include <riscv_ztt.h>
typedef __INT32_TYPE__ element_t;

#ifdef __cplusplus
extern "C" {
#endif
extern int call_boundary (int);

__attribute__((noinline, noclone))
int owned_kernel (const element_t *in, element_t *out_m, element_t *out_a)
{
  __riscv_ztt_i32_rne_1x2_t m = __riscv_ztt_mls_rm_i32_rne_1x2 (in);
  __riscv_ztt_i32_rne_accx2_t a = __riscv_ztt_mcopy_m2a_i32_rne_accx2 (m);
  asm volatile ("" : : "Wmr" (m), "War" (a));
  int result = call_boundary (1);
  __riscv_ztt_mss_rm_i32_rne_1x2 (out_m, m);
  __riscv_ztt_mss_rm_i32_rne_1x2 (out_a,
                                __riscv_ztt_mcopy_a2m_i32_rne_1x2 (a));
  return result;
}

unsigned long owned_region (unsigned long desc, const element_t *in,
                            element_t *out_m, element_t *out_a)
{
  unsigned long status = __riscv_ztt_ame_acquire (desc);
  /* A failed acquire may have nonzero status bits above bit zero.  */
  if (!(status & 1))
    return status;
  owned_kernel (in, out_m, out_a);
  __riscv_ztt_ame_release ();
  return status;
}

unsigned long owned_regions (unsigned long desc, const element_t *in,
                             element_t *out_m, element_t *out_a, int count)
{
  unsigned long result = 0;
  for (int i = 0; i < count; ++i)
    {
      unsigned long status = __riscv_ztt_ame_acquire (desc);
      if (!(status & 1))
        return status;
      owned_kernel (in, out_m, out_a);
      __riscv_ztt_ame_release ();
      result += status;
    }
  return result;
}
#ifdef __cplusplus
}
#endif
