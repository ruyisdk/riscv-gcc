#include <stdint.h>
#include <riscv_ztt.h>

#define EDGE(NAME, T, C, ATTR) \
ATTR void NAME (const C *in, C *out, int branch) \
{ \
  __riscv_ztt_##T##_1x1_t m = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  __riscv_ztt_##T##_accx1_t a = __riscv_ztt_mcopy_m2a_##T##_accx1 (m); \
  if (branch) \
    __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##T##_1x1 (a)); \
}

EDGE (edge_i32, i32_rnu, int32_t, __attribute__((noipa)))
EDGE (edge_f32, f32_rne, float, __attribute__((noipa)))
EDGE (edge_u64, u64_rnu, uint64_t, __attribute__((noipa)))
EDGE (edge_o0, i32_rnu, int32_t, __attribute__((noipa, optimize("O0"))))
#undef EDGE

void nonlocal_i32 (const int32_t *in, int32_t *out, int first, int second)
{
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m);
  if (first)
    {
      __asm__ volatile ("" : : : "memory");
      if (second)
	__riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a));
    }
}
