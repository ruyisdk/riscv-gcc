#include <riscv_ztt.h>

#ifndef GI_TYPE
#define GI_TYPE i32_rnu
#define GI_CARRIER __INT32_TYPE__
#define GI_SOURCE u8_rnu
#define GI_MIDDLE u16_rnu
#define GI_INDEX u32_rnu
#define GI_INDEX_CARRIER __UINT32_TYPE__
#endif
#define GI_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define GI_NAME(f, t) GI_NAME_(f, t)
#define GI_T_(t) __riscv_ztt_##t##_1x1_t
#define GI_T(t) GI_T_(t)
typedef GI_CARRIER gi_element;
typedef GI_INDEX_CARRIER gi_index;
#define GI_ARGS const gi_element *in, const gi_index *indices, \
  gi_element *out, gi_index *extra
#define GI_LOAD GI_T(GI_TYPE) a = GI_NAME(mls_rm, GI_TYPE) (in)
#define GI_COL GI_T(GI_SOURCE) s = GI_NAME(mcolid_ew, GI_SOURCE) (); \
  GI_T(GI_INDEX) i = GI_NAME(mconv_ew, GI_INDEX) (s)
#define GI_ROW GI_T(GI_SOURCE) s = GI_NAME(mrowid_ew, GI_SOURCE) (); \
  GI_T(GI_INDEX) i = GI_NAME(mconv_ew, GI_INDEX) (s)
#define GI_COPY(dst, src) GI_T(GI_INDEX) dst = GI_NAME(mcopy_m2m, GI_INDEX) (src)
#define GI_COPY1 GI_COPY(j, i)
#define GI_COPY2 GI_COPY1; GI_COPY(k, j)
#define GI_COPY3 GI_COPY2; GI_COPY(l, k)
#define GI_COPY4 GI_COPY3; GI_COPY(m, l)
#ifdef __cplusplus
extern "C" {
#endif
extern void gid_callee (void);
extern volatile unsigned long gid_observed;

void gid_col (GI_ARGS)
{
  GI_LOAD;
  GI_T(GI_SOURCE) s = GI_NAME(mcolid_ew, GI_SOURCE) ();
  GI_T(GI_SOURCE) t = GI_NAME(mcopy_m2m, GI_SOURCE) (s);
  GI_T(GI_INDEX) i = GI_NAME(mconv_ew, GI_INDEX) (t);
  GI_COPY1;
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, j);
  __riscv_ztt_mss_rm (out, b);
}

void gid_row (GI_ARGS)
{
  GI_LOAD; GI_ROW; GI_COPY2;
  GI_T(GI_TYPE) b = GI_NAME(mrowgather_ew, GI_TYPE) (a, k);
  __riscv_ztt_mss_rm (out, b);
}

void gid_shared (GI_ARGS)
{
  GI_LOAD; GI_COL; GI_COPY3;
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, l);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (extra, l);
}

void gid_query (GI_ARGS)
{
  GI_LOAD; GI_COL; GI_COPY2;
  unsigned long n = __riscv_ztt_get_amenlen ();
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, k);
  __riscv_ztt_mss_rm (out, b);
  gid_observed = n;
}

void gid_cross (GI_ARGS)
{
  GI_LOAD; GI_ROW; GI_COPY1;
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, j);
  __riscv_ztt_mss_rm (out, b);
}

void gid_call (GI_ARGS)
{
  GI_LOAD; GI_COL; GI_COPY1;
  gid_callee ();
  GI_COPY(k, j);
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, k);
  __riscv_ztt_mss_rm (out, b);
}

void gid_asm (GI_ARGS)
{
  GI_LOAD; GI_COL; GI_COPY1;
  asm volatile ("" ::: "memory");
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, j);
  __riscv_ztt_mss_rm (out, b);
}

void gid_memory (GI_ARGS)
{
  GI_LOAD; GI_COL; GI_COPY1;
  gid_observed = gid_observed + 1;
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, j);
  __riscv_ztt_mss_rm (out, b);
}

void gid_external (GI_ARGS)
{
  GI_LOAD;
  GI_T(GI_INDEX) i = GI_NAME(mls_rm, GI_INDEX) (indices);
  GI_COPY1;
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, j);
  __riscv_ztt_mss_rm (out, b);
}

void gid_before (GI_ARGS)
{
  GI_COL; GI_COPY1; GI_LOAD;
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, j);
  __riscv_ztt_mss_rm (out, b);
}

void gid_reference (GI_ARGS)
{
  GI_LOAD;
  __riscv_ztt_mss_rm (out, a);
}

void gid_limit (GI_ARGS)
{
  GI_LOAD; GI_COL; GI_COPY4;
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, m);
  __riscv_ztt_mss_rm (out, b);
}

void gid_inner (GI_ARGS)
{
  GI_LOAD; GI_COL; GI_COPY2;
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, k);
  __riscv_ztt_mss_rm (out, b);
  __riscv_ztt_mss_rm (extra, j);
}

void gid_chain (GI_ARGS)
{
  GI_LOAD;
  GI_T(GI_SOURCE) s = GI_NAME(mcolid_ew, GI_SOURCE) ();
  GI_T(GI_MIDDLE) t = GI_NAME(mconv_ew, GI_MIDDLE) (s);
  GI_T(GI_INDEX) i = GI_NAME(mconv_ew, GI_INDEX) (t);
  GI_COPY1;
  GI_T(GI_TYPE) b = GI_NAME(mcolgather_ew, GI_TYPE) (a, j);
  __riscv_ztt_mss_rm (out, b);
}
#ifdef __cplusplus
}
#endif
