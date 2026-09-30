/* integer
   1x1 types with UDS=8.  Wider elements own a complete 2/4-M group.  */

#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_u8_1x1_irm != 15 || __riscv_ztt_i16_u16_1x1_irm != 15 \
    || __riscv_ztt_i32_u32_1x1_irm != 15
#error incorrect integer capability
#endif
#ifdef TEST_RUNTIME
#if defined (__riscv_ztt_n) || defined (__riscv_ztt_nelem)
#error runtime N must not be a type constant
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
test_i8_rnu_1x1 (const int8_t *in, int8_t *out, int8_t *other)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mls_rm_i8_rnu_1x1 (in);
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mclear_m_i8_rnu_1x1 ();
  b = __riscv_ztt_madd_ew_i8_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_i8_rne_1x1 (const int8_t *in, int8_t *out, int8_t *other)
{
  __riscv_ztt_i8_rne_1x1_t a = __riscv_ztt_mls_rm_i8_rne_1x1 (in);
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mclear_m_i8_rne_1x1 ();
  b = __riscv_ztt_madd_ew_i8_rne_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_i8_rdn_1x1 (const int8_t *in, int8_t *out, int8_t *other)
{
  __riscv_ztt_i8_rdn_1x1_t a = __riscv_ztt_mls_rm_i8_rdn_1x1 (in);
  __riscv_ztt_i8_rdn_1x1_t b = __riscv_ztt_mclear_m_i8_rdn_1x1 ();
  b = __riscv_ztt_madd_ew_i8_rdn_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_i8_rod_1x1 (const int8_t *in, int8_t *out, int8_t *other)
{
  __riscv_ztt_i8_rod_1x1_t a = __riscv_ztt_mls_rm_i8_rod_1x1 (in);
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mclear_m_i8_rod_1x1 ();
  b = __riscv_ztt_madd_ew_i8_rod_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
default_i8 (const int8_t *in, int8_t *out, int8_t *other)
{
  __riscv_ztt_i8_1x1_t a = __riscv_ztt_mls_rm_i8_1x1 (in);
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mclear_m_i8_1x1 ();
  a = __riscv_ztt_madd_ew_i8_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (other, __riscv_ztt_mzero_m_i8_1x1 ());
}

void
test_u8_rnu_1x1 (const uint8_t *in, uint8_t *out, uint8_t *other)
{
  __riscv_ztt_u8_rnu_1x1_t a = __riscv_ztt_mls_rm_u8_rnu_1x1 (in);
  __riscv_ztt_u8_rnu_1x1_t b = __riscv_ztt_mclear_m_u8_rnu_1x1 ();
  b = __riscv_ztt_madd_ew_u8_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_u8_rne_1x1 (const uint8_t *in, uint8_t *out, uint8_t *other)
{
  __riscv_ztt_u8_rne_1x1_t a = __riscv_ztt_mls_rm_u8_rne_1x1 (in);
  __riscv_ztt_u8_rne_1x1_t b = __riscv_ztt_mclear_m_u8_rne_1x1 ();
  b = __riscv_ztt_madd_ew_u8_rne_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_u8_rdn_1x1 (const uint8_t *in, uint8_t *out, uint8_t *other)
{
  __riscv_ztt_u8_rdn_1x1_t a = __riscv_ztt_mls_rm_u8_rdn_1x1 (in);
  __riscv_ztt_u8_rdn_1x1_t b = __riscv_ztt_mclear_m_u8_rdn_1x1 ();
  b = __riscv_ztt_madd_ew_u8_rdn_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_u8_rod_1x1 (const uint8_t *in, uint8_t *out, uint8_t *other)
{
  __riscv_ztt_u8_rod_1x1_t a = __riscv_ztt_mls_rm_u8_rod_1x1 (in);
  __riscv_ztt_u8_rod_1x1_t b = __riscv_ztt_mclear_m_u8_rod_1x1 ();
  b = __riscv_ztt_madd_ew_u8_rod_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
default_u8 (const uint8_t *in, uint8_t *out, uint8_t *other)
{
  __riscv_ztt_u8_1x1_t a = __riscv_ztt_mls_rm_u8_1x1 (in);
  __riscv_ztt_u8_rnu_1x1_t b = __riscv_ztt_mclear_m_u8_1x1 ();
  a = __riscv_ztt_madd_ew_u8_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (other, __riscv_ztt_mzero_m_u8_1x1 ());
}

void
test_i16_rnu_1x1 (const int16_t *in, int16_t *out, int16_t *other)
{
  __riscv_ztt_i16_rnu_1x1_t a = __riscv_ztt_mls_rm_i16_rnu_1x1 (in);
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mclear_m_i16_rnu_1x1 ();
  b = __riscv_ztt_madd_ew_i16_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_i16_rne_1x1 (const int16_t *in, int16_t *out, int16_t *other)
{
  __riscv_ztt_i16_rne_1x1_t a = __riscv_ztt_mls_rm_i16_rne_1x1 (in);
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mclear_m_i16_rne_1x1 ();
  b = __riscv_ztt_madd_ew_i16_rne_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_i16_rdn_1x1 (const int16_t *in, int16_t *out, int16_t *other)
{
  __riscv_ztt_i16_rdn_1x1_t a = __riscv_ztt_mls_rm_i16_rdn_1x1 (in);
  __riscv_ztt_i16_rdn_1x1_t b = __riscv_ztt_mclear_m_i16_rdn_1x1 ();
  b = __riscv_ztt_madd_ew_i16_rdn_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i16_rdn_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_i16_rod_1x1 (const int16_t *in, int16_t *out, int16_t *other)
{
  __riscv_ztt_i16_rod_1x1_t a = __riscv_ztt_mls_rm_i16_rod_1x1 (in);
  __riscv_ztt_i16_rod_1x1_t b = __riscv_ztt_mclear_m_i16_rod_1x1 ();
  b = __riscv_ztt_madd_ew_i16_rod_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
default_i16 (const int16_t *in, int16_t *out, int16_t *other)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mls_rm_i16_1x1 (in);
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mclear_m_i16_1x1 ();
  a = __riscv_ztt_madd_ew_i16_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (other, __riscv_ztt_mzero_m_i16_1x1 ());
}

void
test_u16_rnu_1x1 (const uint16_t *in, uint16_t *out, uint16_t *other)
{
  __riscv_ztt_u16_rnu_1x1_t a = __riscv_ztt_mls_rm_u16_rnu_1x1 (in);
  __riscv_ztt_u16_rnu_1x1_t b = __riscv_ztt_mclear_m_u16_rnu_1x1 ();
  b = __riscv_ztt_madd_ew_u16_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u16_rnu_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_u16_rne_1x1 (const uint16_t *in, uint16_t *out, uint16_t *other)
{
  __riscv_ztt_u16_rne_1x1_t a = __riscv_ztt_mls_rm_u16_rne_1x1 (in);
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mclear_m_u16_rne_1x1 ();
  b = __riscv_ztt_madd_ew_u16_rne_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_u16_rdn_1x1 (const uint16_t *in, uint16_t *out, uint16_t *other)
{
  __riscv_ztt_u16_rdn_1x1_t a = __riscv_ztt_mls_rm_u16_rdn_1x1 (in);
  __riscv_ztt_u16_rdn_1x1_t b = __riscv_ztt_mclear_m_u16_rdn_1x1 ();
  b = __riscv_ztt_madd_ew_u16_rdn_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_u16_rod_1x1 (const uint16_t *in, uint16_t *out, uint16_t *other)
{
  __riscv_ztt_u16_rod_1x1_t a = __riscv_ztt_mls_rm_u16_rod_1x1 (in);
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mclear_m_u16_rod_1x1 ();
  b = __riscv_ztt_madd_ew_u16_rod_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
default_u16 (const uint16_t *in, uint16_t *out, uint16_t *other)
{
  __riscv_ztt_u16_1x1_t a = __riscv_ztt_mls_rm_u16_1x1 (in);
  __riscv_ztt_u16_rnu_1x1_t b = __riscv_ztt_mclear_m_u16_1x1 ();
  a = __riscv_ztt_madd_ew_u16_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (other, __riscv_ztt_mzero_m_u16_1x1 ());
}

void
test_i32_rnu_1x1 (const int32_t *in, int32_t *out, int32_t *other)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mclear_m_i32_rnu_1x1 ();
  b = __riscv_ztt_madd_ew_i32_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_i32_rne_1x1 (const int32_t *in, int32_t *out, int32_t *other)
{
  __riscv_ztt_i32_rne_1x1_t a = __riscv_ztt_mls_rm_i32_rne_1x1 (in);
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mclear_m_i32_rne_1x1 ();
  b = __riscv_ztt_madd_ew_i32_rne_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_i32_rdn_1x1 (const int32_t *in, int32_t *out, int32_t *other)
{
  __riscv_ztt_i32_rdn_1x1_t a = __riscv_ztt_mls_rm_i32_rdn_1x1 (in);
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mclear_m_i32_rdn_1x1 ();
  b = __riscv_ztt_madd_ew_i32_rdn_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_i32_rod_1x1 (const int32_t *in, int32_t *out, int32_t *other)
{
  __riscv_ztt_i32_rod_1x1_t a = __riscv_ztt_mls_rm_i32_rod_1x1 (in);
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mclear_m_i32_rod_1x1 ();
  b = __riscv_ztt_madd_ew_i32_rod_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
default_i32 (const int32_t *in, int32_t *out, int32_t *other)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mclear_m_i32_1x1 ();
  a = __riscv_ztt_madd_ew_i32_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (other, __riscv_ztt_mzero_m_i32_1x1 ());
}

void
test_u32_rnu_1x1 (const uint32_t *in, uint32_t *out, uint32_t *other)
{
  __riscv_ztt_u32_rnu_1x1_t a = __riscv_ztt_mls_rm_u32_rnu_1x1 (in);
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mclear_m_u32_rnu_1x1 ();
  b = __riscv_ztt_madd_ew_u32_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_u32_rne_1x1 (const uint32_t *in, uint32_t *out, uint32_t *other)
{
  __riscv_ztt_u32_rne_1x1_t a = __riscv_ztt_mls_rm_u32_rne_1x1 (in);
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mclear_m_u32_rne_1x1 ();
  b = __riscv_ztt_madd_ew_u32_rne_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_u32_rdn_1x1 (const uint32_t *in, uint32_t *out, uint32_t *other)
{
  __riscv_ztt_u32_rdn_1x1_t a = __riscv_ztt_mls_rm_u32_rdn_1x1 (in);
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mclear_m_u32_rdn_1x1 ();
  b = __riscv_ztt_madd_ew_u32_rdn_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
test_u32_rod_1x1 (const uint32_t *in, uint32_t *out, uint32_t *other)
{
  __riscv_ztt_u32_rod_1x1_t a = __riscv_ztt_mls_rm_u32_rod_1x1 (in);
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mclear_m_u32_rod_1x1 ();
  b = __riscv_ztt_madd_ew_u32_rod_1x1 (a, b);
  __riscv_ztt_mss_rm (out, b);
  a = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_mss_rm (other, a);
}

void
default_u32 (const uint32_t *in, uint32_t *out, uint32_t *other)
{
  __riscv_ztt_u32_1x1_t a = __riscv_ztt_mls_rm_u32_1x1 (in);
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mclear_m_u32_1x1 ();
  a = __riscv_ztt_madd_ew_u32_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (other, __riscv_ztt_mzero_m_u32_1x1 ());
}

#ifdef __cplusplus
}
#define SAME(A,B) __is_same (A, B)
#define ASSERT(C) static_assert (C, "")
#else
#define SAME(A,B) __builtin_types_compatible_p (A, B)
#define ASSERT(C) _Static_assert (C, "")
#endif
ASSERT (SAME (__riscv_ztt_i8_1x1_t, __riscv_ztt_i8_rnu_1x1_t));
ASSERT (!SAME (__riscv_ztt_i8_rne_1x1_t, __riscv_ztt_i8_rnu_1x1_t));
ASSERT (SAME (__riscv_ztt_u8_1x1_t, __riscv_ztt_u8_rnu_1x1_t));
ASSERT (!SAME (__riscv_ztt_u8_rne_1x1_t, __riscv_ztt_u8_rnu_1x1_t));
ASSERT (SAME (__riscv_ztt_i16_1x1_t, __riscv_ztt_i16_rnu_1x1_t));
ASSERT (!SAME (__riscv_ztt_i16_rne_1x1_t, __riscv_ztt_i16_rnu_1x1_t));
ASSERT (SAME (__riscv_ztt_u16_1x1_t, __riscv_ztt_u16_rnu_1x1_t));
ASSERT (!SAME (__riscv_ztt_u16_rne_1x1_t, __riscv_ztt_u16_rnu_1x1_t));
ASSERT (SAME (__riscv_ztt_i32_1x1_t, __riscv_ztt_i32_rnu_1x1_t));
ASSERT (!SAME (__riscv_ztt_i32_rne_1x1_t, __riscv_ztt_i32_rnu_1x1_t));
ASSERT (SAME (__riscv_ztt_u32_1x1_t, __riscv_ztt_u32_rnu_1x1_t));
ASSERT (!SAME (__riscv_ztt_u32_rne_1x1_t, __riscv_ztt_u32_rnu_1x1_t));
ASSERT (!SAME (__riscv_ztt_i8_rnu_1x1_t, __riscv_ztt_u8_rnu_1x1_t));
ASSERT (!SAME (__riscv_ztt_i16_rnu_1x1_t, __riscv_ztt_u16_rnu_1x1_t));
ASSERT (!SAME (__riscv_ztt_i32_rnu_1x1_t, __riscv_ztt_u32_rnu_1x1_t));
