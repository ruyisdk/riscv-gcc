/* exact basic-square indices.  */
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_mrowid_ew_int != 1 || __riscv_ztt_mcolid_ew_int != 1
#error missing integer index constructors
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

#define TEST(T, R) \
  void indices_##T##_##R (C(T) *rows, C(T) *cols, C(T) *copy) \
  { \
    TYPE(T, R) a = OP(mrowid_ew, T, R) (); \
    TYPE(T, R) b = OP(mcolid_ew, T, R) (); \
    TYPE(T, R) old = a; \
    __riscv_ztt_mss_rm (rows, a); \
    __riscv_ztt_mss_rm (cols, b); \
    __riscv_ztt_mss_rm (copy, old); \
  }
#define ALIAS(T) \
  void default_##T (C(T) *rows, C(T) *cols) \
  { \
    TYPE(T, rnu) a = DEFAULT(mrowid_ew, T) (); \
    TYPE(T, rnu) b = DEFAULT(mcolid_ew, T) (); \
    __riscv_ztt_mss_rm (rows, a); \
    __riscv_ztt_mss_rm (cols, b); \
  }
#define RMS(T) TEST(T, rnu) TEST(T, rne) TEST(T, rdn) TEST(T, rod) ALIAS(T)
#if __riscv_ztt_uds <= 8
RMS(i8)
RMS(u8)
#endif
#if __riscv_ztt_uds <= 16
RMS(i16)
RMS(u16)
#endif
RMS(i32)
RMS(u32)
