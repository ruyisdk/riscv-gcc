/* Complete packed packets,
   retained sources, independent live values and destructive clears.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_acc_packed_copy != 1
#error packed copy capability required
#endif
#define CAT_(A, B) A##B
#define CAT(A, B) CAT_ (A, B)
#define DT CAT(i, TEST_BITS)
#define UT CAT(u, TEST_BITS)
#if TEST_BITS == 8
#define SC int8_t
#define UC uint8_t
#elif TEST_BITS == 16
#define SC int16_t
#define UC uint16_t
#else
#define SC int32_t
#define UC uint32_t
#endif
#define EACH_(M, D, U, K) \
  M (D##_rnu, SC, K, 0) M (D##_rne, SC, K, 1) \
  M (D##_rdn, SC, K, 2) M (D##_rod, SC, K, 3) \
  M (U##_rnu, UC, K, 4) M (U##_rne, UC, K, 5) \
  M (U##_rdn, UC, K, 6) M (U##_rod, UC, K, 7)
#define EACH_X(M, D, U, K) EACH_ (M, D, U, K)
#define EACH(M) EACH_X (M, DT, UT, TEST_K)
#define INIT(T, C, K, I) \
  __riscv_ztt_##T##_1x##K##_t v##I = __riscv_ztt_mls_rm_##T##_1x##K ((const C *) in[I]); \
  __riscv_ztt_##T##_##K##x1_t w##I = __riscv_ztt_mls_rm_##T##_##K##x1 ((const C *) in[8 + I]); \
  __riscv_ztt_##T##_accx##K##_t a##I = __riscv_ztt_mcopy_m2a_##T##_accx##K (v##I); \
  __riscv_ztt_##T##_accx##K##_t b##I = __riscv_ztt_mcopy_m2a_##T##_accx##K (w##I); \
  __riscv_ztt_##T##_accx##K##_t keep##I = a##I;
#define CLEAR(T, C, K, I) a##I = __riscv_ztt_mclear_acc_##T##_accx##K ();
#define RUN(T, C, K, I) \
  __riscv_ztt_mss_rm ((C *) out[I], __riscv_ztt_mcopy_a2m_##T##_1x##K (keep##I)); \
  __riscv_ztt_mss_rm ((C *) out[8 + I], __riscv_ztt_mcopy_a2m_##T##_1x##K (a##I)); \
  __riscv_ztt_mss_rm ((C *) out[16 + I], __riscv_ztt_mcopy_a2m_##T##_1x##K (branch ? b##I : keep##I)); \
  __riscv_ztt_mss_rm ((C *) out[24 + I], __riscv_ztt_mcopy_a2m_##T##_##K##x1 (b##I)); \
  __riscv_ztt_mss_rm ((C *) out[32 + I], v##I); \
  __riscv_ztt_mss_rm ((C *) out[40 + I], w##I); \
  __riscv_ztt_mss_rm ((C *) out[48 + I], __riscv_ztt_mcopy_a2m_##T##_1x##K ( \
    __riscv_ztt_mzero_acc_##T##_accx##K ()));
#ifdef __cplusplus
extern "C"
#endif
void acc_packed_kernel (const void **in, void **out, int branch)
{
  EACH (INIT)
  EACH (CLEAR)
  EACH (RUN)
}
#undef RUN
#undef CLEAR
#undef INIT
#undef EACH
#undef EACH_X
#undef EACH_
#undef UT
#undef DT
#undef UC
#undef SC
#undef CAT
#undef CAT_
