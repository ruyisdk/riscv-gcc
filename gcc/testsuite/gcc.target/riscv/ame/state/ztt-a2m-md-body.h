#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef __INT32_TYPE__ a2m_element;
extern void a2m_callee (void);
extern volatile int a2m_condition;

#define A2M_COPY(NAME, TC, SHAPE, COUNT, ELEMENT) \
__attribute__((noinline, noclone)) \
void NAME (const ELEMENT *in, ELEMENT *out) \
{ \
  __riscv_ztt_##TC##_accx##COUNT##_t a \
    = __riscv_ztt_mcopy_m2a_##TC##_accx##COUNT \
        (__riscv_ztt_mls_rm_##TC##_##SHAPE (in)); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##TC##_##SHAPE (a)); \
}
#define A2M_PACKET(NAME, COUNT) \
  A2M_COPY (NAME, i8_rnu, 1x##COUNT, COUNT, signed char)
#if __riscv_ztt_uds == 8
A2M_PACKET (a2m_packet, 1)
A2M_PACKET (a2m_packets, 2)
#elif __riscv_ztt_uds == 16
A2M_PACKET (a2m_packet, 2)
A2M_PACKET (a2m_packets, 4)
#elif __riscv_ztt_uds == 32
A2M_PACKET (a2m_packet, 4)
A2M_PACKET (a2m_packets, 8)
#elif __riscv_ztt_uds == 64
A2M_PACKET (a2m_packet, 8)
A2M_PACKET (a2m_packets, 16)
#elif __riscv_ztt_uds == 128
A2M_PACKET (a2m_packet, 16)
#endif
#undef A2M_PACKET

#if __riscv_ztt_uds <= 32
A2M_COPY (a2m_rnu, i32_rnu, 1x1, 1, a2m_element)
A2M_COPY (a2m_rne, i32_rne, 1x1, 1, a2m_element)
A2M_COPY (a2m_rdn, i32_rdn, 1x1, 1, a2m_element)
A2M_COPY (a2m_rod, i32_rod, 1x1, 1, a2m_element)
A2M_COPY (a2m_pair, i32_rnu, 1x2, 2, a2m_element)
A2M_COPY (a2m_quad, i32_rnu, 1x4, 4, a2m_element)

void a2m_twice (const a2m_element *in, a2m_element *out,
                a2m_element *other)
{
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in));
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mcopy_a2m_i32_1x1 (a);
  __riscv_ztt_mss_rm (out, m);
  __riscv_ztt_mss_rm (other, m);
}

#define A2M_BARRIER(NAME, BARRIER) \
void NAME (const a2m_element *in, a2m_element *out) \
{ \
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mcopy_m2a_i32_accx1 \
    (__riscv_ztt_mls_rm_i32_1x1 (in)); \
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mcopy_a2m_i32_1x1 (a); \
  BARRIER; \
  __riscv_ztt_mss_rm (out, m); \
}
A2M_BARRIER (a2m_asm, __asm__ volatile ("" ::: "memory"))
A2M_BARRIER (a2m_call, a2m_callee ())
A2M_BARRIER (a2m_join,
             if (a2m_condition) __asm__ volatile ("" ::: "memory"))
#undef A2M_BARRIER
#endif
#undef A2M_COPY
#ifdef __cplusplus
}
#endif
