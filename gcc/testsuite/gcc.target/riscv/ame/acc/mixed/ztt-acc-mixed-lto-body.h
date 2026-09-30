/* Mixed integer matmul.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_uds == 8
#define D i8_rne
#define L u16_rdn
#define R i8_rod
#define DC int8_t
#define LC uint16_t
#define RC int8_t
#elif __riscv_ztt_uds == 16
#define D i16_rne
#define L u32_rdn
#define R i16_rod
#define DC int16_t
#define LC uint32_t
#define RC int16_t
#else
#define D i32_rne
#define L u32_rdn
#define R i32_rod
#define DC int32_t
#define LC uint32_t
#define RC int32_t
#endif
#define TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define TYPE(T, S) TYPE_(T, S)
#define API_(OP, T, S) __riscv_ztt_##OP##_##T##_##S
#define API(OP, T, S) API_(OP, T, S)
#ifdef __cplusplus
extern "C" {
#endif
#ifdef REVERSE
#define ENTRY mixed_lto_other
#define FIRST mmulaccneg_2d
#define SECOND mmulacc_2d
#else
#define ENTRY mixed_lto_first
#define FIRST mmulacc_2d
#define SECOND mmulaccneg_2d
extern void mixed_lto_other (const void **, void **);
#endif
__attribute__((noinline))
void ENTRY (const void **in, void **out)
{
  TYPE (D, accx2) old = API (mcopy_m2a, D, accx2) (
    API (mls_rm, D, 1x2) ((const DC *) in[0]));
  TYPE (L, 1x2) left = API (mls_rm, L, 1x2) ((const LC *) in[1]);
  TYPE (R, 2x1) right = API (mls_rm, R, 2x1) ((const RC *) in[2]);
  TYPE (D, accx2) first = API (FIRST, D, accx2) (old, left, right);
  TYPE (D, accx2) second = API (SECOND, D, accx2) (old, left, right);
  __riscv_ztt_mss_rm ((DC *) out[0], API (mcopy_a2m, D, 1x2) (first));
  __riscv_ztt_mss_rm ((DC *) out[1], API (mcopy_a2m, D, 1x2) (second));
  __riscv_ztt_mss_rm ((DC *) out[2], API (mcopy_a2m, D, 1x2) (old));
}
#ifndef REVERSE
void mixed_lto_entry (const void **in, void **out)
{
  mixed_lto_first (in, out);
  mixed_lto_other (in, out + 3);
}
#endif
#ifdef __cplusplus
}
#endif
