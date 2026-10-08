#include <stdint.h>
#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void overwrite_ame (void);

#define ASSIGN(T, X) (X)
#define MCOPY(T, X) __riscv_ztt_mcopy_m2m_##T (X)
#define TEST(KIND, T, C) \
void KIND##_##T (C *dst, C *saved, const C *src, const C *replacement, int choose) \
{ \
  __riscv_ztt_##T##_t a = __riscv_ztt_mls_rm_##T (src); \
  __riscv_ztt_##T##_t b = KIND (T, a); \
  overwrite_ame (); \
  a = __riscv_ztt_mls_rm_##T (replacement); \
  if (choose) \
    b = KIND (T, a); \
  __riscv_ztt_mss_rm (dst, b); \
  __riscv_ztt_mss_rm (saved, a); \
}
#define TYPE(T, C) TEST (ASSIGN, T, C) TEST (MCOPY, T, C)
TYPE (i32_rnu_1x1, int32_t)
TYPE (i32_rdn_1x2, int32_t)
TYPE (f32_rne_1x1, float)
TYPE (f32_rno_1x2, float)
#ifdef __cplusplus
}
#endif
