#include <riscv_ztt.h>
typedef __INT32_TYPE__ cl_i32;
typedef __riscv_ztt_i32_rnu_1x1_t cl_half;
typedef __riscv_ztt_i32_rnu_1x2_t cl_pair;
#ifdef __cplusplus
extern "C" {
#endif
extern void cl_callee (void);

#define CASE(NAME, GAP, LEFT, RIGHT, KEEP) \
void NAME (cl_i32 *out, cl_i32 *saved, const cl_i32 *a, \
           const cl_i32 *b, const cl_i32 *c) \
{ \
  cl_half av = __riscv_ztt_mls_rm_i32_rnu_1x1 (a); \
  cl_half bv = __riscv_ztt_mls_rm_i32_rnu_1x1 (b); \
  cl_pair pair = __riscv_ztt_mconcat_m_i32_rnu_1x2 (av, bv); \
  GAP; \
  cl_pair other = __riscv_ztt_mls_rm_i32_rnu_1x2 (c); \
  cl_pair result = __riscv_ztt_msub_ew_i32_rnu_1x2 (LEFT, RIGHT); \
  __riscv_ztt_mss_rm (out, result); \
  KEEP; \
}
CASE (cl_left, (void) 0, pair, other, (void) 0)
CASE (cl_right, (void) 0, other, pair, (void) 0)
CASE (cl_live, (void) 0, pair, other, __riscv_ztt_mss_rm (saved, av))
CASE (cl_call, cl_callee (), pair, other, (void) 0)
CASE (cl_asm, __asm__ volatile ("" ::: "memory"), pair, other, (void) 0)
CASE (cl_store, __riscv_ztt_mss_rm (saved, av), pair, other, (void) 0)
CASE (cl_shared, (void) 0, pair, other, __riscv_ztt_mss_rm (saved, pair))

void cl_before (cl_i32 *out, const cl_i32 *a, const cl_i32 *b,
                const cl_i32 *c)
{
  cl_half av = __riscv_ztt_mls_rm_i32_rnu_1x1 (a);
  cl_half bv = __riscv_ztt_mls_rm_i32_rnu_1x1 (b);
  cl_pair other = __riscv_ztt_mls_rm_i32_rnu_1x2 (c);
  cl_pair pair = __riscv_ztt_mconcat_m_i32_rnu_1x2 (av, bv);
  __riscv_ztt_mss_rm (out, __riscv_ztt_msub_ew_i32_rnu_1x2 (pair, other));
}
#ifdef __cplusplus
}
#endif
