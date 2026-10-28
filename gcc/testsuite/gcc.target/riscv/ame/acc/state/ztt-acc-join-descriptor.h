#include <stdint.h>
#include <riscv_ztt.h>

#define JOIN(NAME, T, C, ATTR) \
ATTR void NAME (const C *in, C *out, unsigned int count) \
{ \
  __riscv_ztt_##T##_1x1_t m = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  __riscv_ztt_##T##_accx1_t a = __riscv_ztt_mcopy_m2a_##T##_accx1 (m); \
  for (unsigned int i = 0; i < count; ++i) \
    a = __riscv_ztt_mmulacc_2d_##T##_accx1 (a, m, m); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##T##_1x1 (a)); \
}

JOIN (joined_i32, i32_rnu, int32_t, __attribute__((noipa)))
/* A single-insn descriptor and O0 both retain ordinary construction.  */
JOIN (joined_u64, u64_rnu, uint64_t, __attribute__((noipa)))
JOIN (joined_f32, f32_rne, float, __attribute__((noipa)))
JOIN (unoptimized_i32, i32_rnu, int32_t,
      __attribute__((noipa, optimize("O0"))))
#undef JOIN

void local_i32 (const int32_t *in, int32_t *out)
{
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m);
  a = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (a, m, m);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a));
}
