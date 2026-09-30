/* Opposite lazy declaration orders.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_uds == 16
#define D i8
#define DC int8_t
#define L i16_rne
#define LC int16_t
#define R u8_rdn
#define RC uint8_t
#define ROW 1x4
#define COL 4x1
#define A accx8
#define OUT 1x8
#elif __riscv_ztt_uds == 32
#define D u16
#define DC uint16_t
#define L i8_rod
#define LC int8_t
#define R u16_rne
#define RC uint16_t
#define ROW 1x8
#define COL 8x1
#define A accx8
#define OUT 1x8
#elif __riscv_ztt_uds == 64
#define D i8
#define DC int8_t
#define L u32_rdn
#define LC uint32_t
#define R i16_rod
#define RC int16_t
#define ROW 1x8
#define COL 8x1
#define A accx16
#define OUT 1x16
#else
#define D u8
#define DC uint8_t
#define L i8_rne
#define LC int8_t
#define R u32_rdn
#define RC uint32_t
#define ROW 1x16
#define COL 16x1
#define A accx16
#define OUT 1x16
#endif
#define TYPE_(T,S) __riscv_ztt_##T##_##S##_t
#define TYPE(T,S) TYPE_(T,S)
#define API_(OP,T,S) __riscv_ztt_##OP##_##T##_##S
#define API(OP,T,S) API_(OP,T,S)
#ifdef __cplusplus
extern "C" {
#endif
#ifdef REVERSE
#define ENTRY packed_lto_other
#define FIRST mmulaccneg_2d
#define SECOND mmulacc_2d
#else
#define ENTRY packed_lto_first
#define FIRST mmulacc_2d
#define SECOND mmulaccneg_2d
extern void packed_lto_other (const void **, void **);
#endif
__attribute__((noinline))
void ENTRY (const void **in, void **out)
{
  TYPE(D,A) old = API(mcopy_m2a,D,A) (API(mls_rm,D,OUT) ((const DC *) in[0]));
  TYPE(L,ROW) left = API(mls_rm,L,ROW) ((const LC *) in[1]);
  TYPE(R,COL) right = API(mls_rm,R,COL) ((const RC *) in[2]);
  TYPE(D,A) first = API(FIRST,D,A) (old, left, right);
  TYPE(D,A) second = API(SECOND,D,A) (old, left, right);
  __riscv_ztt_mss_rm ((DC *) out[0], API(mcopy_a2m,D,OUT) (first));
  __riscv_ztt_mss_rm ((DC *) out[1], API(mcopy_a2m,D,OUT) (second));
  __riscv_ztt_mss_rm ((DC *) out[2], API(mcopy_a2m,D,OUT) (old));
}
#ifndef REVERSE
void packed_lto_entry (const void **in, void **out)
{
  packed_lto_first (in, out);
  packed_lto_other (in, out + 3);
}
#endif
#ifdef __cplusplus
}
#endif
