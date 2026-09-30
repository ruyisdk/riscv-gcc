/* Preserve the live source
   while preparing identical physical inputs only once.  */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_uds == 8
#define SHAPE 1x1
#elif __riscv_ztt_uds == 32
#define SHAPE 1x4
#else
#error unsupported test profile
#endif

#define TYPE_(T, S) __riscv_ztt_##T##_rne_##S##_t
#define TYPE_I(T, S) TYPE_(T, S)
#define TYPE(T) TYPE_I(T, SHAPE)
#define OP_(F, T, S) __riscv_ztt_##F##_##T##_rne_##S
#define OP_I(F, T, S) OP_(F, T, S)
#define OP(F, T) OP_I(F, T, SHAPE)

#define SAME(F, T, C, R) \
  void F##_same_##R (uint8_t *out, const C *in, C *copy) \
  { \
    TYPE(T) value = OP(mls_rm, T) (in); \
    TYPE(u8) result = OP(F, u8) (value, value); \
    __riscv_ztt_mss_rm (out, result); \
    __riscv_ztt_mss_rm (copy, value); \
  }

#define DISTINCT(F) \
  void F##_distinct (uint8_t *out, const int8_t *a, const int8_t *b, \
                     int8_t *acopy, int8_t *bcopy) \
  { \
    TYPE(i8) lhs = OP(mls_rm, i8) (a); \
    TYPE(i8) rhs = OP(mls_rm, i8) (b); \
    TYPE(u8) result = OP(F, u8) (lhs, rhs); \
    __riscv_ztt_mss_rm (out, result); \
    __riscv_ztt_mss_rm (acopy, lhs); \
    __riscv_ztt_mss_rm (bcopy, rhs); \
  }

#define FAMILY(F) \
  SAME (F, i8, int8_t, r1) \
  SAME (F, i16, int16_t, r2) \
  SAME (F, i32, int32_t, r4) \
  DISTINCT (F)

#ifdef O3_SHIFT
FAMILY (msll_ew)
FAMILY (msrl_ew)
FAMILY (msra_ew)
void
scalar (uint8_t *out, const int8_t *in, int8_t *copy, size_t count)
{
  TYPE(i8) value = OP(mls_rm, i8) (in);
  TYPE(u8) result = OP(msll_ew_x, u8) (value, count);
  __riscv_ztt_mss_rm (out, result);
  __riscv_ztt_mss_rm (copy, value);
}
#else
FAMILY (mmul_ew)
#endif
