#include <stdint.h>
#include <riscv_ztt.h>

#define TEST(T, C) \
void add_##T (uint32_t *out, const uint32_t *in, uintptr_t bits) \
{ \
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_x_u32_rnu_1x1_##T \
    (__riscv_ztt_mls_rm_u32_rnu_1x1 (in), \
     __riscv_ztt_scalar_from_bits_##T ((C) (bits + 1u)))); \
} \
void fused_##T (uint32_t *out, const uint32_t *in, \
               const uint32_t *old, uintptr_t bits) \
{ \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mmulacc_ew_x_u32_rnu_1x1_##T \
    (__riscv_ztt_mls_rm_u32_rnu_1x1 (old), \
     __riscv_ztt_mls_rm_u32_rnu_1x1 (in), \
     __riscv_ztt_scalar_from_bits_##T ((C) (bits + 1u)))); \
}

TEST (i32_rnu, int32_t)
TEST (u32_rnu, uint32_t)
TEST (f32_rne, uint32_t)
