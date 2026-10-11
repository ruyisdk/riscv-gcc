#include <riscv_ztt.h>

#ifndef ZTT_INDEX_PREFIX
#define ZTT_INDEX_PREFIX index
#endif
#define ZTT_JOIN_1(A, B) A##_##B
#define ZTT_JOIN(A, B) ZTT_JOIN_1 (A, B)
#define ZTT_NAME(N) ZTT_JOIN (ZTT_INDEX_PREFIX, N)
#ifdef __cplusplus
extern "C" {
#endif

#define EXTRACT(T, C) \
void ZTT_NAME (extract_##T) (C *out, const C *in) \
{ \
  __riscv_ztt_##T##_2x1_t c = __riscv_ztt_mls_rm_##T##_2x1 (in); \
  __riscv_ztt_##T##_1x2_t r = __riscv_ztt_mls_rm_##T##_1x2 (in); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mextract_##T##_1x1 (c, 0)); \
  __riscv_ztt_mss_rm (out + 1, __riscv_ztt_mextract_##T##_1x1 (r, 1)); \
  __riscv_ztt_mss_rm (out + 2, __riscv_ztt_mextract_##T##_1x1 (c, 1)); \
  __riscv_ztt_mss_rm (out + 3, __riscv_ztt_mextract_##T##_1x1 (r, 0)); \
}

#define COPY(T, C) \
void ZTT_NAME (copy_##T) (C *out, const C *in) \
{ \
  __riscv_ztt_##T##_2x1_t c = __riscv_ztt_mls_rm_##T##_2x1 (in); \
  __riscv_ztt_##T##_1x2_t r = __riscv_ztt_mls_rm_##T##_1x2 (in); \
  __riscv_ztt_##T##_accx2_t a = __riscv_ztt_mcopy_m2a_##T##_accx2 (c); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##T##_2x1 (a)); \
  a = __riscv_ztt_mcopy_m2a_##T##_accx2 (r); \
  __riscv_ztt_mss_rm (out + 1, __riscv_ztt_mcopy_a2m_##T##_1x2 (a)); \
  a = __riscv_ztt_mcopy_m2a_##T##_accx2 (c); \
  __riscv_ztt_mss_rm (out + 2, __riscv_ztt_mcopy_a2m_##T##_2x1 (a)); \
}

#define UTILS(T, C) EXTRACT (T, C) COPY (T, C)
UTILS (i32_rnu, __INT32_TYPE__)
UTILS (u64_rod, __UINT64_TYPE__)
UTILS (f32_rtz, float)
UTILS (i32, __INT32_TYPE__)

#define MATMUL(T, OP, L, R) \
void ZTT_NAME (OP##_##T##_##L##_##R) \
  (__INT32_TYPE__ *out, const __INT32_TYPE__ *in) \
{ \
  __riscv_ztt_##T##_##L##_t a = __riscv_ztt_mls_rm_##T##_##L (in); \
  __riscv_ztt_##T##_##R##_t b = __riscv_ztt_mls_rm_##T##_##R (in); \
  __riscv_ztt_##T##_accx1_t d = __riscv_ztt_mzero_acc_##T##_accx1 (); \
  d = __riscv_ztt_##OP##_2d_##T##_accx1 (d, a, b); \
  d = __riscv_ztt_##OP##_2d_##T##_accx1 (d, a, b); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##T##_1x1 (d)); \
}

MATMUL (i32_rnu, mmulacc, 1x2, 2x1)
MATMUL (i32_rnu, mmulaccneg, 1x2, 2x1)
MATMUL (i32_rnu, mmulatacc, 1x2, 1x2)
MATMUL (i32_rnu, mmulatacc, 2x1, 2x1)
MATMUL (i32_rnu, mmulataccneg, 1x2, 1x2)
MATMUL (i32_rnu, mmulataccneg, 2x1, 2x1)
MATMUL (i32_rnu, mmulbtacc, 1x2, 1x2)
MATMUL (i32_rnu, mmulbtacc, 2x1, 2x1)
MATMUL (i32_rnu, mmulbtaccneg, 1x2, 1x2)
MATMUL (i32_rnu, mmulbtaccneg, 2x1, 2x1)
MATMUL (i32_rne, mmulacc, 1x2, 2x1)
MATMUL (i32_rne, mmulatacc, 2x1, 2x1)

#undef MATMUL
#undef UTILS
#undef COPY
#undef EXTRACT
#ifdef __cplusplus
}
#endif
#undef ZTT_NAME
#undef ZTT_JOIN
#undef ZTT_JOIN_1
#undef ZTT_INDEX_PREFIX
