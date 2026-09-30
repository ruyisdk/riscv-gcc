/* Wide values own full groups.
   These compile tests do not establish numerical execution semantics.  */
#include <riscv_ztt.h>
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define VALUES(T, K) \
void values_##T##_##K (int branch) \
{ \
  __riscv_ztt_##T##_1x##K##_t m = __riscv_ztt_mzero_m_##T##_1x##K (); \
  __riscv_ztt_##T##_1x##K##_t saved = __riscv_ztt_mcopy_m2m_##T##_1x##K (m); \
  __riscv_ztt_##T##_accx##K##_t a = __riscv_ztt_mcopy_m2a_##T##_accx##K (m); \
  __riscv_ztt_##T##_accx##K##_t keep = a; \
  __asm__ volatile ("" : "+&War" (a) : "War" (keep)); \
  __asm__ volatile ("" : "+&Wmr" (m) : "Wmr" (saved)); \
  if (branch) \
    a = __riscv_ztt_mclear_acc_##T##_accx##K (); \
  __riscv_ztt_##T##_1x##K##_t result = __riscv_ztt_mcopy_a2m_##T##_1x##K (keep); \
  __asm__ volatile ("" : : "Wmr" (result), "Wmr" (saved)); \
  a = __riscv_ztt_mzero_acc_##T##_accx##K (); \
  m = __riscv_ztt_mcopy_a2m_##T##_1x##K (a); \
  __asm__ volatile ("" : : "Wmr" (m)); \
  m = __riscv_ztt_mclear_m_##T##_1x##K (); \
  __asm__ volatile ("" : : "Wmr" (m)); \
}

#define ROWCOL(T, K) \
void rowcol_##T##_##K (void) \
{ \
  __riscv_ztt_##T##_##K##x1_t m = __riscv_ztt_mzero_m_##T##_##K##x1 (); \
  __riscv_ztt_##T##_accx##K##_t a = __riscv_ztt_mcopy_m2a_##T##_accx##K (m); \
  m = __riscv_ztt_mcopy_a2m_##T##_##K##x1 (a); \
  __asm__ volatile ("" : : "Wmr" (m)); \
}

#define ALL_RM(M, T, K) \
  M (T##_rnu, K) M (T##_rne, K) M (T##_rdn, K) M (T##_rod, K)
#define W64(M, K) ALL_RM (M, i64, K) ALL_RM (M, u64, K)
#define W128(M, K) ALL_RM (M, i128, K) ALL_RM (M, u128, K)
#if TEST_UDS <= 64
W64 (VALUES, 1)
#endif
#if TEST_UDS >= 32
W64 (VALUES, 2)
W64 (ROWCOL, 2)
#endif
#if TEST_UDS >= 64
W64 (VALUES, 4)
W64 (ROWCOL, 4)
#endif
#if TEST_UDS == 128
W64 (VALUES, 8)
W64 (ROWCOL, 8)
#endif
#if TEST_UDS >= 32
W128 (VALUES, 1)
#endif
#if TEST_UDS >= 64
W128 (VALUES, 2)
W128 (ROWCOL, 2)
#endif
#if TEST_UDS == 128
W128 (VALUES, 4)
W128 (ROWCOL, 4)
#endif

/* 64-bit C carriers exist on both XLENs and retain their full memory width. */
#define UTILS(T, H, K) \
void utils_##T##_##K (void) \
{ \
  __riscv_ztt_##T##_1x##H##_t a = __riscv_ztt_mzero_m_##T##_1x##H (); \
  __riscv_ztt_##T##_1x##K##_t b = __riscv_ztt_mconcat_m_##T##_1x##K (a, a); \
  a = __riscv_ztt_mextract_##T##_1x##H (b, 1); \
  __asm__ volatile ("" : : "Wmr" (a), "Wmr" (b)); \
  __riscv_ztt_##T##_##H##x1_t c = __riscv_ztt_mzero_m_##T##_##H##x1 (); \
  __riscv_ztt_##T##_##K##x1_t d = __riscv_ztt_mconcat_m_##T##_##K##x1 (c, c); \
  c = __riscv_ztt_mextract_##T##_##H##x1 (d, 0); \
  __asm__ volatile ("" : : "Wmr" (c), "Wmr" (d)); \
}
#if TEST_UDS == 32 || TEST_UDS == 64
UTILS (i64_rne, 1, 2)
UTILS (u64_rod, 1, 2)
#endif
#if TEST_UDS == 64 || TEST_UDS == 128
UTILS (i64_rdn, 2, 4)
UTILS (u64_rnu, 2, 4)
UTILS (i128_rne, 1, 2)
UTILS (u128_rod, 1, 2)
#endif
#if TEST_UDS == 128
UTILS (i64_rnu, 4, 8)
UTILS (u64_rdn, 4, 8)
UTILS (i128_rdn, 2, 4)
UTILS (u128_rnu, 2, 4)
#endif

#define MEMORY(T, C, K) \
void memory_##T (const C *in, C *out, size_t stride) \
{ \
  __riscv_ztt_##T##_1x##K##_t a = __riscv_ztt_mls_rm_##T##_1x##K (in); \
  __riscv_ztt_mss_rm (out, a); \
  a = __riscv_ztt_mls_cm_##T##_1x##K (in); \
  __riscv_ztt_mss_cm (out, a); \
  a = __riscv_ztt_mls_st_##T##_1x##K (in, stride); \
  __riscv_ztt_mss_st (out, stride, a); \
  a = __riscv_ztt_mls_tst_##T##_1x##K (in, stride); \
  __riscv_ztt_mss_tst (out, stride, a); \
}
#define MEMORY_RM(T, C, K) \
  MEMORY (T##_rnu, C, K) MEMORY (T##_rne, C, K) \
  MEMORY (T##_rdn, C, K) MEMORY (T##_rod, C, K)
#if TEST_UDS == 128
MEMORY_RM (i64, int64_t, 2)
MEMORY_RM (u64, uint64_t, 2)
#else
MEMORY_RM (i64, int64_t, 1)
MEMORY_RM (u64, uint64_t, 1)
#endif

#ifndef __riscv_ztt_wide64_values
#error Missing wide64 value capability
#endif
#if TEST_UDS >= 32
#ifndef __riscv_ztt_wide128_values
#error Missing wide128 value capability
#endif
#endif

#ifdef __cplusplus
}
#endif
