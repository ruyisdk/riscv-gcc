#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void descriptor_callee (void);

#define CHAIN(NAME, TYPE, CTYPE, CONSTRUCT, GAP) \
void NAME (const CTYPE *in, CTYPE *out, CTYPE *last, int index, int flag) \
{ \
  __riscv_ztt_##TYPE##_1x1_t a = CONSTRUCT; \
  a = __riscv_ztt_mrowbcast_ew_x_##TYPE##_1x1 (a, index); \
  __riscv_ztt_##TYPE##_1x1_t b = __riscv_ztt_mzero_m_##TYPE##_1x1 (); \
  __riscv_ztt_mss_rm (out, b); \
  GAP; \
  a = __riscv_ztt_madd_ew_##TYPE##_1x1 (a, a); \
  __riscv_ztt_mss_rm (last, a); \
}

#define ZERO __riscv_ztt_mzero_m_f32_1x1 ()
CHAIN (witness_zero, f32, float, ZERO, (void) 0)
CHAIN (witness_broadcast, f32, float,
       __riscv_ztt_mbcast_m_x_f32_rne_1x1_f32_rne
         (__riscv_ztt_scalar_from_bits_f32_rne (index)), (void) 0)
CHAIN (witness_mixed, f32, float,
       __riscv_ztt_mbcast_m_x_f32_rne_1x1_i8_rdn
         (__riscv_ztt_scalar_from_bits_i8_rdn (index)), (void) 0)
CHAIN (witness_rowid, i32, __INT32_TYPE__,
       __riscv_ztt_mrowid_ew_i32_1x1 (), (void) 0)
CHAIN (witness_colid, i32, __INT32_TYPE__,
       __riscv_ztt_mcolid_ew_i32_1x1 (), (void) 0)
CHAIN (witness_load, f32, float,
       __riscv_ztt_mls_rm_f32_1x1 (in), (void) 0)
CHAIN (witness_call, f32, float, ZERO, descriptor_callee ())
CHAIN (witness_asm, f32, float, ZERO,
       __asm__ volatile ("# AME state boundary" ::: "memory"))
CHAIN (witness_join, f32, float, ZERO,
       if (flag) descriptor_callee ())
#undef ZERO
#undef CHAIN

void witness_pair (float *out, float *last, int index)
{
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mzero_m_f32_1x1 ();
  a = __riscv_ztt_mrowbcast_ew_x_f32_1x1 (a, index);
  __riscv_ztt_f32_1x2_t b = __riscv_ztt_mzero_m_f32_1x2 ();
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_madd_ew_f32_1x1 (a, a);
  __riscv_ztt_mss_rm (last, a);
}
#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
extern "C" {
#endif
#define PAIR_MEMORY(NAME, STORE) \
void NAME (float *out, float *last, int index, long stride) \
{ \
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mzero_m_f32_1x1 (); \
  a = __riscv_ztt_mrowbcast_ew_x_f32_1x1 (a, index); \
  __riscv_ztt_f32_1x2_t b = __riscv_ztt_mzero_m_f32_1x2 (); \
  STORE; \
  a = __riscv_ztt_madd_ew_f32_1x1 (a, a); \
  __riscv_ztt_mss_rm (last, a); \
}
PAIR_MEMORY (witness_pair_cm, __riscv_ztt_mss_cm (out, b))
PAIR_MEMORY (witness_pair_st, __riscv_ztt_mss_st (out, stride, b))
PAIR_MEMORY (witness_pair_tst, __riscv_ztt_mss_tst (out, stride, b))
#undef PAIR_MEMORY
#ifdef __cplusplus
}
#endif
