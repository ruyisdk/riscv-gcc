/* nominal registration.  */
#include <stdint.h>
#pragma GCC push_options
#pragma GCC optimize ("O1")
#include <riscv_ztt.h>
#include "../fixtures/ztt-scalar-construct.h"
#pragma GCC pop_options

#ifdef __cplusplus
#define SAME(A, B) __is_same (__typeof__ (A), __typeof__ (B))
#define CHECK(C) static_assert (C, "registration signature")
#else
#define SAME(A, B) __builtin_types_compatible_p (__typeof__ (A), __typeof__ (B))
#define CHECK(C) _Static_assert (C, "registration signature")
#endif

#define BCAST_(DR, S, SR) __riscv_ztt_mbcast_m_x_i8_##DR##_1x4_##S##_##SR
#define BCAST(DR, S, SR) BCAST_ (DR, S, SR)
#define CHECK_RMS(S) \
  CHECK (!SAME (BCAST (rnu, S, rnu), BCAST (rnu, S, rne))); \
  CHECK (!SAME (BCAST (rnu, S, rnu), BCAST (rnu, S, rdn))); \
  CHECK (!SAME (BCAST (rnu, S, rnu), BCAST (rnu, S, rod))); \
  CHECK (!SAME (BCAST (rnu, S, rnu), BCAST (rne, S, rnu)))

CHECK_RMS (i8);
CHECK_RMS (u8);
CHECK_RMS (i16);
CHECK_RMS (u16);
CHECK_RMS (i32);
CHECK_RMS (u32);
CHECK (!SAME (BCAST (rnu, i8, rnu), BCAST (rnu, u8, rnu)));
CHECK (!SAME (BCAST (rnu, i8, rnu), BCAST (rnu, i16, rnu)));
CHECK (!SAME (BCAST (rnu, i16, rnu), BCAST (rnu, i32, rnu)));
CHECK (SAME (__riscv_ztt_mbcast_m_x_i8_1x4_i8, BCAST (rnu, i8, rnu)));

#define TEST(S, C, R) \
  { \
    int8_t *out = *outputs++; \
    C value = (C) scalar; \
    __riscv_ztt_i8_rnu_1x4_t a \
      = BCAST (rnu, S, R) (ZTT_TEST_MAKE (S##_##R, value)); \
    __riscv_ztt_i8_rne_1x4_t b \
      = BCAST (rne, S, R) (ZTT_TEST_MAKE (S##_##R, value)); \
    __riscv_ztt_mss_rm (out, a); \
    __riscv_ztt_mss_rm (out + 128, b); \
  }
#define TEST_RMS(S, C) \
  TEST (S, C, rnu) \
  TEST (S, C, rne) \
  TEST (S, C, rdn) \
  TEST (S, C, rod)

/* Keep all signatures and calls live in one function.  Forced collection
   then tests the catalog without repeating every per-function pass.  */
void registration_all (int8_t **outputs, int32_t scalar)
{
  TEST_RMS (i8, int8_t)
  TEST_RMS (u8, uint8_t)
  TEST_RMS (i16, int16_t)
  TEST_RMS (u16, uint16_t)
  TEST_RMS (i32, int32_t)
  TEST_RMS (u32, uint32_t)
  __riscv_ztt_i8_rnu_1x4_t result
    = __riscv_ztt_mbcast_m_x_i8_1x4_i8
      (__riscv_ztt_scalar_make_i8_rnu ((int8_t) scalar));
  __riscv_ztt_mss_rm (*outputs, result);
}
