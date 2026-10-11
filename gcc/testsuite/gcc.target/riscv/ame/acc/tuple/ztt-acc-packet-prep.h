#include <stdint.h>
#include <riscv_ztt.h>

#define TYPE(T, S) __riscv_ztt_##T##_##S##_t
#define OP(N, T, S) __riscv_ztt_##N##_##T##_##S
#define KEEP(A) __asm__ volatile ("" : : "War" (A))
#define ROUNDTRIP(NAME, T, K, BARRIER) \
void NAME (void) \
{ \
  TYPE (T, accx##K) a = OP (mzero_acc, T, accx##K) (); \
  TYPE (T, 1x##K) m = OP (mcopy_a2m, T, 1x##K) (a); \
  BARRIER; \
  a = OP (mcopy_m2a, T, accx##K) (m); \
  KEEP (a); \
}

#ifdef __cplusplus
extern "C" {
#endif
extern void external_call (void);
ROUNDTRIP (tuple_two, i32_rnu, 2, (void) 0)
ROUNDTRIP (tuple_four, i32_rnu, 4, (void) 0)
ROUNDTRIP (wide_two, i64_rnu, 2, (void) 0)
ROUNDTRIP (wide_sixteen, i64_rnu, 16, (void) 0)
ROUNDTRIP (packed_four, i8_rnu, 4, (void) 0)
ROUNDTRIP (packed_eight, i8_rnu, 8, (void) 0)
ROUNDTRIP (packed_sixteen, i8_rnu, 16, (void) 0)
ROUNDTRIP (floating_two, f32_rne, 2, (void) 0)
ROUNDTRIP (bfloat_two, bf16_rne, 2, (void) 0)
ROUNDTRIP (asm_boundary, i64_rnu, 2, __asm__ volatile ("" ::: "memory"))
ROUNDTRIP (call_boundary, i64_rnu, 2, external_call ())

/* This logical 1x2 load prepares two independent Md packets.  */
void whole_group (const int32_t *in)
{
  TYPE (i32_rnu, 1x2) m = OP (mls_rm, i32_rnu, 1x2) (in);
  TYPE (i32_rnu, accx2) a = OP (mcopy_m2a, i32_rnu, accx2) (m);
  KEEP (a);
}

void packed_load (const int8_t *in)
{
  TYPE (i8_rnu, 1x4) m = OP (mls_rm, i8_rnu, 1x4) (in);
  TYPE (i8_rnu, accx4) a = OP (mcopy_m2a, i8_rnu, accx4) (m);
  KEEP (a);
}
#ifdef __cplusplus
}
#endif
