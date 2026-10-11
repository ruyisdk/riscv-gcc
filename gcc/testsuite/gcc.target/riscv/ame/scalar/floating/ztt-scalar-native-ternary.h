#include <stdint.h>
#include <riscv_ztt.h>

#define M __riscv_ztt_u32_rnu_1x1_t
#define LOAD __riscv_ztt_mls_rm_u32_rnu_1x1
#define STORE __riscv_ztt_mss_rm

#define TEST(T, C) \
void native_arg_##T (uint32_t *out, const uint32_t *b, \
                     const uint32_t *old, C x) \
{ \
  STORE (out, __riscv_ztt_mmulacc_ew_x_u32_rnu_1x1_##T \
    (LOAD (old), LOAD (b), __riscv_ztt_scalar_make_##T (x))); \
} \
C native_live_##T (uint32_t *out, uint32_t *saved_b, uint32_t *saved_old, \
                    const uint32_t *b, const uint32_t *old, volatile C *in) \
{ \
  C x = *in; \
  M src = LOAD (b), dst = LOAD (old); \
  STORE (out, __riscv_ztt_mmulacc_ew_x_u32_rnu_1x1_##T \
    (dst, src, __riscv_ztt_scalar_make_##T (x))); \
  STORE (saved_b, src); \
  STORE (saved_old, dst); \
  return x; \
} \
void native_discard_##T (const uint32_t *b, const uint32_t *old, \
                         volatile C *in) \
{ \
  C x = *in; \
  (void) __riscv_ztt_mmulacc_ew_x_u32_rnu_1x1_##T \
    (LOAD (old), LOAD (b), __riscv_ztt_scalar_make_##T (x)); \
}

TEST (f16_rne, _Float16)
TEST (bf16_rne, __bf16)
TEST (f32_rne, float)
