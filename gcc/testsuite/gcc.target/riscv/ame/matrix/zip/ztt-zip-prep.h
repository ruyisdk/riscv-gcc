#include <stdint.h>
#include <riscv_ztt.h>

#define TYPE(T) __riscv_ztt_##T##_1x2_t
#define OP(N, T) __riscv_ztt_##N##_##T##_1x2
#define KEEP(A) __asm__ volatile ("" : : "Wmr" (A))
#define TEST(NAME, T, C, F, BARRIER) \
void NAME (const C *in) \
{ \
  TYPE (T) a = OP (mls_rm, T) (in); \
  BARRIER; \
  a = OP (F, T) (a); \
  KEEP (a); \
}

#ifdef __cplusplus
extern "C" {
#endif
extern void external_call (void);
TEST (colzip, i32_rnu, int32_t, mcolzip_ew, (void) 0)
TEST (rowzip, i32_rnu, int32_t, mrowzip_ew, (void) 0)
TEST (colunzip, i32_rnu, int32_t, mcolunzip_ew, (void) 0)
TEST (rowunzip, i32_rnu, int32_t, mrowunzip_ew, (void) 0)
TEST (floating_zip, f32_rne, float, mcolzip_ew, (void) 0)
TEST (wide_unzip, u128_rnu, __riscv_ztt_u128_storage_t, mrowunzip_ew, (void) 0)
TEST (asm_boundary, i32_rnu, int32_t, mcolzip_ew,
      __asm__ volatile ("" ::: "memory"))
TEST (call_boundary, i32_rnu, int32_t, mcolzip_ew, external_call ())

void cross_axis (const int32_t *in)
{
  TYPE (i32_rnu) a = OP (mls_rm, i32_rnu) (in);
  a = OP (mcolzip_ew, i32_rnu) (a);
  a = OP (mrowzip_ew, i32_rnu) (a);
  KEEP (a);
}
#ifdef __cplusplus
}
#endif
