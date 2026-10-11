#include <stdint.h>
#include <riscv_ztt.h>

#define TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define TYPE(T, S) TYPE_ (T, S)
#define OP_(N, T, S) __riscv_ztt_##N##_##T##_##S
#define OP(N, T, S) OP_ (N, T, S)
#define KEEP(A) __asm__ volatile ("" : : "Wmr" (A))
#define TEST(NAME, D, T, S, C, F, BARRIER) \
void NAME (const C *in) \
{ \
  TYPE (T, S) a = OP (mls_rm, T, S) (in); \
  BARRIER; \
  TYPE (D, S) d = OP (F, D, S) (a); \
  KEEP (d); \
}

#if __riscv_ztt_uds == 8
#define PACK_SHAPE 1x1
#else
#define PACK_SHAPE 1x4
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void external_call (void);
extern volatile int condition;
TEST (convert_signed, i32_rne, i64_rnu, 1x1, int64_t, mconv_ew, (void) 0)
TEST (convert_rm, i32_rod, i32_rnu, 1x2, int32_t, mconv_ew, (void) 0)
TEST (convert_sat, i8_rnu_sat, u128_rnu, PACK_SHAPE,
      __riscv_ztt_u128_storage_t, mconv_ew, (void) 0)
TEST (convert_wide, u128_rnu, u8_rnu, PACK_SHAPE, uint8_t, mconv_ew, (void) 0)
TEST (convert_fp, f16_rne, f32_rmm, 1x2, float, mconv_ew, (void) 0)
TEST (abs_small, i32_rnu, i32_rnu, 1x1, int32_t, mabs_ew, (void) 0)
TEST (abs_large, i32_rnu, i32_rnu, 1x8, int32_t, mabs_ew, (void) 0)
TEST (abs_packed, i8_rnu, i8_rnu, PACK_SHAPE, int8_t, mabs_ew, (void) 0)
TEST (reduce_add, i32_rnu, i32_rnu, 1x2, int32_t, mreduceadd_row, (void) 0)
TEST (reduce_max, f32_rne, f32_rne, 1x2, float, mreducemax_col, (void) 0)
TEST (prefix_add, i32_rnu, i32_rnu, 1x2, int32_t, mprefixadd_col, (void) 0)
TEST (sqrt_fp, f32_rne, f32_rne, 1x2, float, msqrt_ew, (void) 0)
TEST (asm_boundary, i32_rnu, i32_rnu, 1x2, int32_t, mabs_ew,
      __asm__ volatile ("" ::: "memory"))
TEST (call_boundary, i32_rnu, i32_rnu, 1x2, int32_t, mabs_ew, external_call ())
TEST (join_boundary, i32_rnu, i32_rnu, 1x2, int32_t, mabs_ew,
      if (condition) __asm__ volatile ("" ::: "memory"))

void live_source (const int32_t *in)
{
  TYPE (i32_rnu, 1x2) a = OP (mls_rm, i32_rnu, 1x2) (in);
  TYPE (i32_rnu, 1x2) d = OP (mabs_ew, i32_rnu, 1x2) (a);
  __asm__ volatile ("" : : "Wmr" (a), "Wmr" (d));
}

void convert_abs (const int64_t *in)
{
  TYPE (i64_rnu, 1x1) a = OP (mls_rm, i64_rnu, 1x1) (in);
  TYPE (i32_rne, 1x1) d = OP (mconv_ew, i32_rne, 1x1) (a);
  d = OP (mabs_ew, i32_rne, 1x1) (d);
  KEEP (d);
}
#ifdef __cplusplus
}
#endif
