#include <riscv_ztt.h>

#ifndef GI_TYPE
#define GI_TYPE i32
#define GI_CARRIER __INT32_TYPE__
#endif
#ifndef GI_INDEX
#define GI_INDEX u32
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
#define GI_COL GI_T(GI_INDEX) i = GI_NAME(mcolid_ew, GI_INDEX) ()
#define GI_ROW GI_T(GI_INDEX) i = GI_NAME(mrowid_ew, GI_INDEX) ()
#define GI_GATHER(f) GI_T(GI_TYPE) b = GI_NAME(f, GI_TYPE) (a, i); \
  __riscv_ztt_mss_rm (out, b)

#ifdef __cplusplus
extern "C" {
#endif
extern void gid_callee (void);
extern volatile unsigned long gid_observed;

void gid_col (GI_ARGS)
{
  GI_LOAD; GI_COL;
  GI_GATHER(mcolgather_ew);
}

void gid_row (GI_ARGS)
{
  GI_LOAD; GI_ROW;
  GI_GATHER(mrowgather_ew);
}

void gid_shared (GI_ARGS)
{
  GI_LOAD; GI_COL;
  GI_GATHER(mcolgather_ew);
  __riscv_ztt_mss_rm (extra, i);
}

void gid_query (GI_ARGS)
{
  GI_LOAD; GI_COL;
  unsigned long n = __riscv_ztt_get_amenlen ();
  GI_GATHER(mcolgather_ew);
  gid_observed = n;
}

void gid_cross (GI_ARGS)
{
  GI_LOAD; GI_ROW;
  GI_GATHER(mcolgather_ew);
}

void gid_call (GI_ARGS)
{
  GI_LOAD; GI_COL;
  gid_callee ();
  GI_GATHER(mcolgather_ew);
}

void gid_asm (GI_ARGS)
{
  GI_LOAD; GI_COL;
  asm volatile ("" ::: "memory");
  GI_GATHER(mcolgather_ew);
}

void gid_memory (GI_ARGS)
{
  GI_LOAD; GI_COL;
  gid_observed = gid_observed + 1;
  GI_GATHER(mcolgather_ew);
}

void gid_external (GI_ARGS)
{
  GI_LOAD;
  GI_T(GI_INDEX) i = GI_NAME(mls_rm, GI_INDEX) (indices);
  GI_GATHER(mcolgather_ew);
}

void gid_before (GI_ARGS)
{
  GI_COL; GI_LOAD;
  GI_GATHER(mcolgather_ew);
}

void gid_reference (GI_ARGS)
{
  GI_LOAD;
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
