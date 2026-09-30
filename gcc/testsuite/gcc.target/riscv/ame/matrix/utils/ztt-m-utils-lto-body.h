/* M utilities.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_uds == 8
#define T i8_rne
#define C int8_t
#define HALF 1x1
#define BIG 2x1
#elif __riscv_ztt_uds == 16
#define T i16_rod
#define C int16_t
#define HALF 1x1
#define BIG 2x1
#elif __riscv_ztt_uds == 32
#define T u32_rdn
#define C uint32_t
#define HALF 1x1
#define BIG 2x1
#elif __riscv_ztt_uds == 64
#define T i32_rnu
#define C int32_t
#define HALF 2x1
#define BIG 4x1
#else
#define T u32_rne
#define C uint32_t
#define HALF 4x1
#define BIG 8x1
#endif
#define OP_(O, T, S) __riscv_ztt_##O##_##T##_##S
#define OP(O, T, S) OP_ (O, T, S)
#ifdef __cplusplus
extern "C" {
#endif
#ifdef REVERSE
#define ENTRY m_utils_other
#define FIRST 1
#else
#define ENTRY m_utils_first
#define FIRST 0
extern void m_utils_other (const C *, const C *, C *);
#endif
__attribute__((noinline))
void ENTRY (const C *in0, const C *in1, C *out)
{
  __typeof__ (OP (mls_rm, T, HALF) (in0)) a = OP (mls_rm, T, HALF) (in0);
  __typeof__ (a) b = OP (mls_rm, T, HALF) (in1);
  __typeof__ (OP (mconcat_m, T, BIG) (a, b)) joined = OP (mconcat_m, T, BIG) (a, b);
  __riscv_ztt_mss_rm (out, OP (mextract, T, HALF) (joined, FIRST));
  __riscv_ztt_mss_rm (out, OP (mextract, T, HALF) (joined, 1 - FIRST));
}
#ifndef REVERSE
void m_utils_entry (const C *in0, const C *in1, C *out)
{
  m_utils_first (in0, in1, out);
  m_utils_other (in0, in1, out);
}
#endif
#ifdef __cplusplus
}
#endif
