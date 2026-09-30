/* Nonpacked tuple liveness.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_acc_tuple_copy != 1
#error accumulator tuple capability required
#endif
#define TYPES(M, D, C, U, K, A, B, E, F, G, H, I, J) \
  M (i##D##_rnu, C, K, A) M (i##D##_rne, C, K, B) \
  M (i##D##_rdn, C, K, E) M (i##D##_rod, C, K, F) \
  M (u##D##_rnu, U, K, G) M (u##D##_rne, U, K, H) \
  M (u##D##_rdn, U, K, I) M (u##D##_rod, U, K, J)
#if __riscv_ztt_uds == 8
#define PRIMARY(M, K, A, B, E, F, G, H, I, J) \
  TYPES (M, 8, int8_t, uint8_t, K, A, B, E, F, G, H, I, J)
#define SECONDARY(M, A, B, E, F, G, H, I, J) \
  TYPES (M, 16, int16_t, uint16_t, 2, A, B, E, F, G, H, I, J)
#elif __riscv_ztt_uds == 16
#define PRIMARY(M, K, A, B, E, F, G, H, I, J) \
  TYPES (M, 16, int16_t, uint16_t, K, A, B, E, F, G, H, I, J)
#define SECONDARY(M, A, B, E, F, G, H, I, J) \
  TYPES (M, 32, int32_t, uint32_t, 2, A, B, E, F, G, H, I, J)
#else
#define PRIMARY(M, K, A, B, E, F, G, H, I, J) \
  TYPES (M, 32, int32_t, uint32_t, K, A, B, E, F, G, H, I, J)
#define SECONDARY(M, A, B, E, F, G, H, I, J)
#endif
#if __riscv_ztt_accregs >= 4
#define EACH(M) \
  PRIMARY (M, 2, 0, 1, 2, 3, 4, 5, 6, 7) \
  PRIMARY (M, 4, 8, 9, 10, 11, 12, 13, 14, 15) \
  SECONDARY (M, 16, 17, 18, 19, 20, 21, 22, 23)
#define COUNT (__riscv_ztt_uds == 32 ? 16 : 24)
#else
#define EACH(M) \
  PRIMARY (M, 2, 0, 1, 2, 3, 4, 5, 6, 7) \
  SECONDARY (M, 8, 9, 10, 11, 12, 13, 14, 15)
#define COUNT (__riscv_ztt_uds == 32 ? 8 : 16)
#endif
#ifdef SINGLE_I8
#undef EACH
#undef COUNT
#define EACH(M) M (i8_rnu, int8_t, 2, 0)
#define COUNT 1
#endif
#define INIT(T, C, K, I) \
  __riscv_ztt_##T##_1x##K##_t v##I \
    = __riscv_ztt_mls_rm_##T##_1x##K ((const C *) in[I]); \
  __riscv_ztt_##T##_##K##x1_t w##I \
    = __riscv_ztt_mls_rm_##T##_##K##x1 ((const C *) in[COUNT + I]); \
  __riscv_ztt_##T##_accx##K##_t a##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx##K (v##I); \
  __riscv_ztt_##T##_accx##K##_t b##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx##K (w##I); \
  __riscv_ztt_##T##_accx##K##_t keep##I = a##I; \
  __riscv_ztt_##T##_accx1_t one##I \
    = __riscv_ztt_mcopy_m2a_##T##_accx1 ( \
      __riscv_ztt_mls_rm_##T##_1x1 ((const C *) in[2 * COUNT + I]));
#define CLEAR(T, C, K, I) a##I = __riscv_ztt_mclear_acc_##T##_accx##K ();
#define RUN(T, C, K, I) \
  __riscv_ztt_mss_rm ((C *) out[I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K (keep##I)); \
  __riscv_ztt_mss_rm ((C *) out[COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K (a##I)); \
  __riscv_ztt_mss_rm ((C *) out[2 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K (branch ? b##I : keep##I)); \
  __riscv_ztt_mss_rm ((C *) out[3 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_##K##x1 (b##I)); \
  __riscv_ztt_mss_rm ((C *) out[4 * COUNT + I], v##I); \
  __riscv_ztt_mss_rm ((C *) out[5 * COUNT + I], w##I); \
  __riscv_ztt_mss_rm ((C *) out[6 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x1 (one##I)); \
  __riscv_ztt_mss_rm ((C *) out[7 * COUNT + I], \
    __riscv_ztt_mcopy_a2m_##T##_1x##K (__riscv_ztt_mzero_acc_##T##_accx##K ()));
#ifdef __cplusplus
extern "C"
#endif
void acc_tuple_kernel (const void **in, void **out, int branch)
{
  EACH (INIT)
  EACH (CLEAR)
  EACH (RUN)
}
#undef RUN
#undef CLEAR
#undef INIT
#undef EACH
#undef COUNT
#undef SECONDARY
#undef PRIMARY
#undef TYPES
