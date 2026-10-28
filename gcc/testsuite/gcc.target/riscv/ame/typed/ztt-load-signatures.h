#include <riscv_ztt.h>

#ifdef __cplusplus
#define CHECK(A, B) static_assert (__is_same (__typeof__ (A), B), #A)
#else
#define CHECK(A, B) _Static_assert (__builtin_types_compatible_p \
  (__typeof__ (A), B), #A)
#endif

#define SIGNATURES(T, E, S) \
typedef __riscv_ztt_##T##_##S##_t T##_##S##_m; \
typedef T##_##S##_m T##_##S##_load (const E *); \
typedef T##_##S##_m T##_##S##_stride (const E *, __SIZE_TYPE__); \
CHECK (__riscv_ztt_mls_rm_##T##_##S, T##_##S##_load); \
CHECK (__riscv_ztt_mls_cm_##T##_##S, T##_##S##_load); \
CHECK (__riscv_ztt_mls_st_##T##_##S, T##_##S##_stride); \
CHECK (__riscv_ztt_mls_tst_##T##_##S, T##_##S##_stride)

#define INTEGER(T, E) \
SIGNATURES (T##_rnu, E, 1x1); \
SIGNATURES (T##_rdn, E, 1x1); \
SIGNATURES (T##_rnu_sat, E, 1x1)

INTEGER (i8, __INT8_TYPE__);
INTEGER (u8, __UINT8_TYPE__);
INTEGER (i16, __INT16_TYPE__);
INTEGER (u16, __UINT16_TYPE__);
INTEGER (i32, __INT32_TYPE__);
INTEGER (u32, __UINT32_TYPE__);
INTEGER (i64, __INT64_TYPE__);
INTEGER (u64, __UINT64_TYPE__);
INTEGER (i128, __riscv_ztt_i128_storage_t);
INTEGER (u128, __riscv_ztt_u128_storage_t);
SIGNATURES (i32_rnu, __INT32_TYPE__, 1x2);
SIGNATURES (i32_rnu, __INT32_TYPE__, 2x1);

#define FLOAT(T, E) \
SIGNATURES (T##_rne, E, 1x1); \
SIGNATURES (T##_rtz, E, 1x1); \
SIGNATURES (T##_rne, E, 1x2)

FLOAT (f16, _Float16);
FLOAT (bf16, __bf16);
FLOAT (f32, float);
FLOAT (f64, double);

void
signature_use (__INT32_TYPE__ *out, const __INT32_TYPE__ *in)
{
  i32_rnu_1x1_m a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  i32_rnu_1x2_m b = __riscv_ztt_mls_st_i32_rnu_1x2 (in + 64, 128);
  i32_rdn_1x1_m d = __riscv_ztt_mls_cm_i32_rdn_1x1 (in + 128);
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (out + 64, b);
  __riscv_ztt_mss_cm (out + 192, d);
}
