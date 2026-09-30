/* Combine an ordinary call with AME, RVV callee saves and dynamic alloca.  */
#include <riscv_ztt.h>
typedef __INT32_TYPE__ element_t;

#ifdef __cplusplus
extern "C" {
#endif
extern int use_buffer (void *);

__attribute__((riscv_vector_cc))
int vector_frame_call (const element_t *in, element_t *out,
                       unsigned int bytes)
{
  void *buffer = __builtin_alloca (bytes ? bytes : 16);
  asm volatile ("" : : "r" (buffer) : "v1", "memory");
  __riscv_ztt_i32_rne_1x2_t m = __riscv_ztt_mls_rm_i32_rne_1x2 (in);
  __riscv_ztt_i32_rne_accx2_t a = __riscv_ztt_mcopy_m2a_i32_rne_accx2 (m);
  asm volatile ("" : : "War" (a));
  int result = use_buffer (buffer);
  __riscv_ztt_mss_rm_i32_rne_1x2 (out,
                                __riscv_ztt_mcopy_a2m_i32_rne_1x2 (a));
  return result;
}
#ifdef __cplusplus
}
#endif
