/* 1x2 values.  */
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_zip_value != 1
#error missing value zip support
#endif
#if defined (__riscv_ztt_mcolzip_ew_int) \
    || defined (__riscv_ztt_mrowzip_ew_int) \
    || defined (__riscv_ztt_mcolunzip_ew_int) \
    || defined (__riscv_ztt_mrowunzip_ew_int)
#error retired pointer zip API advertised
#endif

#define C_i8 int8_t
#define C_u8 uint8_t
#define C_i16 int16_t
#define C_u16 uint16_t
#define C_i32 int32_t
#define C_u32 uint32_t
#define C_(T) C_##T
#define C(T) C_(T)
#define TYPE_(T, R) __riscv_ztt_##T##_##R##_1x1_t
#define TYPE(T, R) TYPE_(T, R)
#define OP_(F, T, R) __riscv_ztt_##F##_##T##_##R##_1x1
#define OP(F, T, R) OP_(F, T, R)
#define DEFAULT_(F, T) __riscv_ztt_##F##_##T##_1x1
#define DEFAULT(F, T) DEFAULT_(F, T)
#define PAIR_TYPE_(T, R) __riscv_ztt_##T##_##R##_1x2_t
#define PAIR_TYPE(T, R) PAIR_TYPE_(T, R)
#define PAIR_OP_(F, T, R) __riscv_ztt_##F##_##T##_##R##_1x2
#define PAIR_OP(F, T, R) PAIR_OP_(F, T, R)

#define TEST(F, T, R) \
  void F##_##T##_##R (C(T) *out_a, C(T) *out_b, \
                      const C(T) *in_a, const C(T) *in_b, \
                      C(T) *copy_a, C(T) *copy_b) \
  { \
    TYPE(T, R) a = OP(mls_rm, T, R) (in_a); \
    TYPE(T, R) b = OP(mls_rm, T, R) (in_b); \
    TYPE(T, R) old_a = a; \
    TYPE(T, R) old_b = b; \
    PAIR_TYPE(T, R) pair = PAIR_OP(mconcat_m, T, R) (a, b); \
    pair = PAIR_OP(F, T, R) (pair); \
    a = OP(mextract, T, R) (pair, 0); \
    b = OP(mextract, T, R) (pair, 1); \
    __riscv_ztt_mss_rm (out_a, a); \
    __riscv_ztt_mss_rm (out_b, b); \
    __riscv_ztt_mss_rm (copy_a, old_a); \
    __riscv_ztt_mss_rm (copy_b, old_b); \
  }
#define RMS(F, T) \
  TEST(F, T, rnu) TEST(F, T, rne) TEST(F, T, rdn) TEST(F, T, rod)
#if __riscv_ztt_uds <= 8
#define BYTE(F) RMS(F, i8) RMS(F, u8)
#else
#define BYTE(F)
#endif
#if __riscv_ztt_uds <= 16
#define HALF(F) RMS(F, i16) RMS(F, u16)
#else
#define HALF(F)
#endif
#define FAMILY(F) BYTE(F) HALF(F) RMS(F, i32) RMS(F, u32)
FAMILY(mcolzip_ew)
FAMILY(mrowzip_ew)
FAMILY(mcolunzip_ew)
FAMILY(mrowunzip_ew)

/* One result square may be dead, but both source squares are read.  */
#define ONE(F) \
  void F##_one (int32_t *out, const int32_t *x, const int32_t *y) \
  { \
    TYPE(i32, rnu) a = OP(mls_rm, i32, rnu) (x); \
    TYPE(i32, rnu) b = OP(mls_rm, i32, rnu) (y); \
    PAIR_TYPE(i32, rnu) pair = PAIR_OP(mconcat_m, i32, rnu) (a, b); \
    pair = PAIR_OP(F, i32, rnu) (pair); \
    a = OP(mextract, i32, rnu) (pair, 0); \
    __riscv_ztt_mss_rm (out, a); \
  }
ONE(mcolzip_ew)
ONE(mrowzip_ew)
ONE(mcolunzip_ew)
ONE(mrowunzip_ew)

/* Only ordinary pointers cross the helper boundary; M values stay local.  */
static __inline__ __attribute__((always_inline)) void
zip_helper (int32_t *out_a, int32_t *out_b,
            const int32_t *x, const int32_t *y, int *events)
{
  TYPE(i32, rnu) a = OP(mls_rm, i32, rnu) (x);
  TYPE(i32, rnu) b = OP(mls_rm, i32, rnu) (y);
  PAIR_TYPE(i32, rnu) pair = PAIR_OP(mconcat_m, i32, rnu)
    ((++events[0], a), (++events[1], b));
  pair = PAIR_OP(mcolzip_ew, i32, rnu) (pair);
  a = OP(mextract, i32, rnu) (pair, 0);
  b = OP(mextract, i32, rnu) (pair, 1);
  __riscv_ztt_mss_rm (out_a, a);
  __riscv_ztt_mss_rm (out_b, b);
}

void zip_side_effects (int32_t *out_a, int32_t *out_b,
                       const int32_t *x, const int32_t *y, int *events)
{
  zip_helper (out_a, out_b, x, y, events);
}
