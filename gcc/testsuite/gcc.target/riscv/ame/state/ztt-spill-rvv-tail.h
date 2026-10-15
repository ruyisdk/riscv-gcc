#include <riscv_ztt.h>
#include <riscv_vector.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void rv_tail_callee (void);

#define VECTOR_INPUT(P) \
  size_t vl = __riscv_vsetvl_e32m1 (count); \
  vuint32m1_t v = __riscv_vle32_v_u32m1 (P, vl)

#define CASE(NAME, EARLY, LATE, OP, GAP) \
uint32_t __attribute__((noipa)) \
NAME (const uint32_t *in, uint32_t *out, uint32_t *saved, size_t count) \
{ \
  EARLY; \
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mls_rm_u32_rnu_1x1 (in); \
  __riscv_ztt_u32_rnu_1x1_t result \
    = __riscv_ztt_mrowscatadd_ew_u32_rnu_1x1 (d, d, d); \
  __riscv_ztt_mss_rm (out, result); \
  GAP; \
  LATE; \
  v = OP; \
  vuint32m1_t z = __riscv_vmv_v_x_u32m1 (0, 1); \
  vuint32m1_t sum = __riscv_vredsum_vs_u32m1_u32m1 (v, z, vl); \
  uint32_t answer = __riscv_vmv_x_s_u32m1_u32 (sum); \
  __riscv_ztt_mss_rm (saved, d); \
  return answer; \
}

CASE (rv_tail_add, VECTOR_INPUT (in), (void) 0,
      __riscv_vadd_vv_u32m1 (v, v, vl), (void) 0)
CASE (rv_tail_mul, VECTOR_INPUT (in), (void) 0,
      __riscv_vmul_vv_u32m1 (v, v, vl), (void) 0)
CASE (rv_tail_sat, VECTOR_INPUT (in), (void) 0,
      __riscv_vsaddu_vv_u32m1 (v, v, vl), (void) 0)
CASE (rv_tail_shift, VECTOR_INPUT (in), (void) 0,
      __riscv_vsrl_vx_u32m1 (v, 3, vl), (void) 0)
CASE (rv_tail_ref, VECTOR_INPUT (in), (void) 0, v, (void) 0)
CASE (rv_tail_asm, VECTOR_INPUT (in), (void) 0,
      __riscv_vadd_vv_u32m1 (v, v, vl),
      asm volatile ("# tail boundary" ::: "memory"))
CASE (rv_tail_call, VECTOR_INPUT (in), (void) 0,
      __riscv_vadd_vv_u32m1 (v, v, vl), rv_tail_callee ())
CASE (rv_tail_late, (void) 0, VECTOR_INPUT (out),
      __riscv_vadd_vv_u32m1 (v, v, vl), (void) 0)
#undef CASE
#undef VECTOR_INPUT
#ifdef __cplusplus
}
#endif
