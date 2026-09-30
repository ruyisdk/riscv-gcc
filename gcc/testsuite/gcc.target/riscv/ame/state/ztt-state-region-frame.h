#include <riscv_ztt.h>
typedef __INT32_TYPE__ element_t;

#ifdef __cplusplus
extern "C" {
#endif
extern int region_use_buffer (void *);

__attribute__((riscv_vector_cc))
int region_vector_frame (const element_t *in, element_t *out,
                         unsigned int bytes, unsigned long descriptor)
{
  void *buffer = __builtin_alloca (bytes ? bytes : 16);
  asm volatile ("" : : "r" (buffer) : "v1", "memory");
#ifdef QUERY_REGION
  if (!__riscv_ztt_get_ameown ())
    return -1;
#else
  if (!(__riscv_ztt_ame_acquire (descriptor) & 1))
    return -1;
#endif
  __riscv_ztt_i32_rne_1x2_t m = __riscv_ztt_mls_rm_i32_rne_1x2 (in);
  __riscv_ztt_i32_rne_accx2_t a = __riscv_ztt_mcopy_m2a_i32_rne_accx2 (m);
  asm volatile ("" : : "War" (a));
  int result = region_use_buffer (buffer);
#ifndef QUERY_REGION
  __riscv_ztt_ame_release ();
  if (!(__riscv_ztt_ame_acquire (descriptor) & 1))
    return -2;
#endif
  __riscv_ztt_mss_rm_i32_rne_1x2 (out,
                                __riscv_ztt_mcopy_a2m_i32_rne_1x2 (a));
#ifndef QUERY_REGION
  __riscv_ztt_ame_release ();
#endif
  return result;
}
#ifdef __cplusplus
}
#endif
