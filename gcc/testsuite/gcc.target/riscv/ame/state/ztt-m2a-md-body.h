#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef __INT32_TYPE__ m2a_element;
extern void m2a_callee (void);
extern volatile int m2a_condition;

#define M2A_COPY(NAME, TC, COUNT, ELEMENT, BARRIER) \
__attribute__((noinline, noclone)) \
void NAME (const ELEMENT *in, ELEMENT *out, ELEMENT *live) \
{ \
  __riscv_ztt_##TC##_1x##COUNT##_t m \
    = __riscv_ztt_mls_rm_##TC##_1x##COUNT (in); \
  __riscv_ztt_##TC##_accx##COUNT##_t a \
    = __riscv_ztt_mcopy_m2a_##TC##_accx##COUNT (m); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##TC##_1x##COUNT (a)); \
  BARRIER; \
  __riscv_ztt_mss_rm (live, m); \
}
#define M2A_PACKET(NAME, COUNT) \
  M2A_COPY (NAME, i8_rnu, COUNT, signed char, (void) 0)
#if __riscv_ztt_uds == 8
M2A_PACKET (m2a_packet, 1)
M2A_PACKET (m2a_packets, 2)
#elif __riscv_ztt_uds == 16
M2A_PACKET (m2a_packet, 2)
M2A_PACKET (m2a_packets, 4)
#elif __riscv_ztt_uds == 32
M2A_PACKET (m2a_packet, 4)
M2A_PACKET (m2a_packets, 8)
#elif __riscv_ztt_uds == 64
M2A_PACKET (m2a_packet, 8)
M2A_PACKET (m2a_packets, 16)
#elif __riscv_ztt_uds == 128
M2A_PACKET (m2a_packet, 16)
#endif
#undef M2A_PACKET

#if __riscv_ztt_uds <= 32
M2A_COPY (m2a_single, i32_rnu, 1, m2a_element, (void) 0)
M2A_COPY (m2a_rnu, i32_rnu, 2, m2a_element, (void) 0)
M2A_COPY (m2a_rne, i32_rne, 2, m2a_element, (void) 0)
M2A_COPY (m2a_rdn, i32_rdn, 2, m2a_element, (void) 0)
M2A_COPY (m2a_rod, i32_rod, 2, m2a_element, (void) 0)
M2A_COPY (m2a_quad, i32_rnu, 4, m2a_element, (void) 0)
M2A_COPY (m2a_asm, i32_rnu, 2, m2a_element,
          __asm__ volatile ("" ::: "memory"))
M2A_COPY (m2a_call, i32_rnu, 2, m2a_element, m2a_callee ())
M2A_COPY (m2a_join, i32_rnu, 2, m2a_element,
          if (m2a_condition) __asm__ volatile ("" ::: "memory"))
void m2a_disjoint (const m2a_element *in, m2a_element *out, m2a_element *live)
{
  __riscv_ztt_i32_rne_1x1_t other = __riscv_ztt_mls_rm_i32_rne_1x1 (in);
  __riscv_ztt_i32_1x2_t m = __riscv_ztt_mls_rm_i32_1x2 (in);
  __riscv_ztt_i32_accx2_t a = __riscv_ztt_mcopy_m2a_i32_accx2 (m);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x2 (a));
  __riscv_ztt_mss_rm (live, other);
}
#endif
M2A_COPY (m2a_wide64, i64_rnu, 2, __INT64_TYPE__, (void) 0)
M2A_COPY (m2a_wide128, i128_rnu, 2, __riscv_ztt_i128_storage_t, (void) 0)
#undef M2A_COPY
#ifdef __cplusplus
}
#endif
