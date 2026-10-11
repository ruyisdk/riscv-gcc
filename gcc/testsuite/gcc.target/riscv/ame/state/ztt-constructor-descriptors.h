#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void descriptor_callee (void);

#define CHAIN(NAME, TYPE, CTYPE, SHAPE, CONSTRUCT, GAP) \
void NAME (const CTYPE *in, CTYPE *out, CTYPE *last, int index, int flag) \
{ \
  __riscv_ztt_##TYPE##_##SHAPE##_t a \
    = __riscv_ztt_mls_rm_##TYPE##_##SHAPE (in); \
  a = __riscv_ztt_mrowbcast_ew_x_##TYPE##_##SHAPE (a, index); \
  __riscv_ztt_##TYPE##_##SHAPE##_t b = CONSTRUCT; \
  __riscv_ztt_mss_rm (out, b); \
  GAP; \
  a = __riscv_ztt_madd_ew_##TYPE##_##SHAPE (a, a); \
  __riscv_ztt_mss_rm (last, a); \
}

#define ZERO __riscv_ztt_mzero_m_f32_1x1 ()
CHAIN (constructor_zero, f32, float, 1x1, ZERO, (void) 0)
CHAIN (constructor_broadcast, f32, float, 1x1,
       __riscv_ztt_mbcast_m_x_f32_rne_1x1_f32_rne
         (__riscv_ztt_scalar_from_bits_f32_rne (index)), (void) 0)
CHAIN (constructor_mixed, f32, float, 1x1,
       __riscv_ztt_mbcast_m_x_f32_rne_1x1_i8_rdn
         (__riscv_ztt_scalar_from_bits_i8_rdn (index)), (void) 0)
CHAIN (constructor_rowid, i32, __INT32_TYPE__, 1x1,
       __riscv_ztt_mrowid_ew_i32_1x1 (), (void) 0)
CHAIN (constructor_colid, i32, __INT32_TYPE__, 1x1,
       __riscv_ztt_mcolid_ew_i32_1x1 (), (void) 0)
CHAIN (constructor_load, f32, float, 1x1,
       __riscv_ztt_mls_rm_f32_1x1 (out), (void) 0)
CHAIN (constructor_call, f32, float, 1x1, ZERO, descriptor_callee ())
CHAIN (constructor_asm, f32, float, 1x1, ZERO,
       __asm__ volatile ("" ::: "memory"))
CHAIN (constructor_join, f32, float, 1x1, ZERO,
       if (flag) descriptor_callee ())
#undef ZERO
#undef CHAIN

void constructor_pair (const float *in, float *out, float *last,
                       int index, int flag)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in);
  a = __riscv_ztt_mrowbcast_ew_x_f32_1x1 (a, index);
  __riscv_ztt_f32_1x2_t b = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_madd_ew_f32_1x1 (a, a);
  __riscv_ztt_mss_rm (last, a);
}
#ifdef __cplusplus
}
#endif
