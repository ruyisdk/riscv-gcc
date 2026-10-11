#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void acc_descriptor_callee (void);

#define ACC_CHAIN(NAME, TYPE, CTYPE, K, VALUE, GAP) \
__attribute__((noipa)) void NAME \
  (const CTYPE *in, CTYPE *out, CTYPE *last, int index, int flag) \
{ \
  __riscv_ztt_##TYPE##_1x1_t a = __riscv_ztt_mls_rm_##TYPE##_1x1 (in); \
  a = __riscv_ztt_mrowbcast_ew_x_##TYPE##_1x1 (a, index); \
  __riscv_ztt_##TYPE##_accx##K##_t b = VALUE; \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##TYPE##_1x##K (b)); \
  GAP; \
  a = __riscv_ztt_madd_ew_##TYPE##_1x1 (a, a); \
  __riscv_ztt_mss_rm (last, a); \
}
#define ZF __riscv_ztt_mzero_acc_f32_rne_accx1 ()
ACC_CHAIN (acc_descriptor_zero, f32_rne, float, 1, ZF, (void) 0)
ACC_CHAIN (acc_descriptor_copy, f32_rne, float, 1,
           __riscv_ztt_mcopy_m2a_f32_rne_accx1 (a), (void) 0)
ACC_CHAIN (acc_descriptor_pair, f32_rne, float, 2,
           __riscv_ztt_mzero_acc_f32_rne_accx2 (), (void) 0)
ACC_CHAIN (acc_descriptor_int, i32_rnu, __INT32_TYPE__, 1,
           __riscv_ztt_mzero_acc_i32_rnu_accx1 (), (void) 0)
ACC_CHAIN (acc_descriptor_asm, f32_rne, float, 1, ZF,
           __asm__ volatile ("" ::: "memory"))
ACC_CHAIN (acc_descriptor_call, f32_rne, float, 1, ZF,
           acc_descriptor_callee ())
ACC_CHAIN (acc_descriptor_join, f32_rne, float, 1, ZF,
           if (flag) acc_descriptor_callee ())
#undef ZF
#undef ACC_CHAIN
#ifdef __cplusplus
}
#endif
