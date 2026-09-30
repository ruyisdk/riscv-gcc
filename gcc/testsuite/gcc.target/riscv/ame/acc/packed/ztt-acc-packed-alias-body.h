/* RNU aliases are copy-only.  */
#include <stdint.h>
#include <riscv_ztt.h>
#define OP_(O, T, S) __riscv_ztt_##O##_##T##_##S
#define OP(O, T, S) OP_ (O, T, S)
#if __riscv_ztt_uds == 16
#define T i8
#define C int8_t
#elif __riscv_ztt_uds == 32
#define T u8
#define C uint8_t
#elif __riscv_ztt_uds == 64
#define T i16
#define C int16_t
#else
#define T u32
#define C uint32_t
#endif
#ifdef __cplusplus
extern "C" {
#endif
#ifdef OTHER
#define ENTRY packed_other
#else
#define ENTRY packed_first
extern void packed_other (const C *, C *);
#endif
__attribute__((noinline))
void ENTRY (const C *in, C *out)
{
  __typeof__ (OP (mls_rm, T, 1x4) (in)) m = OP (mls_rm, T, 1x4) (in);
  __typeof__ (OP (mcopy_m2a, T, accx4) (m)) a = OP (mcopy_m2a, T, accx4) (m);
  __riscv_ztt_mss_rm (out, OP (mcopy_a2m, T, 1x4) (a));
  __riscv_ztt_mss_rm (out, OP (mcopy_a2m, T, 4x1) (a));
  a = OP (mclear_acc, T, accx4) ();
  __riscv_ztt_mss_rm (out, OP (mcopy_a2m, T, 1x4) (a));
  a = OP (mzero_acc, T, accx4) ();
  __riscv_ztt_mss_rm (out, OP (mcopy_a2m, T, 1x4) (a));
}
#ifndef OTHER
void packed_entry (const C *in, C *out)
{
  packed_first (in, out);
  packed_other (in, out);
}
#endif
#ifdef __cplusplus
}
#endif
