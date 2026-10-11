#include <riscv_ztt.h>

#ifndef GW_TYPE
#define GW_TYPE u128_rnu_sat
#define GW_CARRIER __riscv_ztt_u128_storage_t
#endif
#ifndef GW_INDEX
#define GW_INDEX i8_rnu_sat
#define GW_INDEX_CARRIER __INT8_TYPE__
#endif
#define GW_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define GW_NAME(f, t) GW_NAME_(f, t)
#define GW_T_(t) __riscv_ztt_##t##_1x1_t
#define GW_T(t) GW_T_(t)
typedef GW_CARRIER gw_element;
typedef GW_INDEX_CARRIER gw_index;
#define GW_ARGS const gw_element *in, const gw_index *indices, \
  gw_element *out, gw_element *saved, gw_index *saved_index
#define GW_LOAD GW_T(GW_TYPE) a = GW_NAME(mls_rm, GW_TYPE) (in); \
  GW_T(GW_INDEX) b = GW_NAME(mls_rm, GW_INDEX) (indices)
#ifdef __cplusplus
extern "C" {
#endif
extern void gw_callee (void);

void gw_col (GW_ARGS)
{
  GW_LOAD;
  GW_T(GW_TYPE) c = GW_NAME(mcolgather_ew, GW_TYPE) (a, b);
  __riscv_ztt_mss_rm (out, c);
}

void gw_row (GW_ARGS)
{
  GW_LOAD;
  GW_T(GW_TYPE) c = GW_NAME(mrowgather_ew, GW_TYPE) (a, b);
  __riscv_ztt_mss_rm (out, c);
}

void gw_live (GW_ARGS)
{
  GW_LOAD;
  GW_T(GW_TYPE) c = GW_NAME(mcolgather_ew, GW_TYPE) (a, b);
  __riscv_ztt_mss_rm (out, c);
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (saved_index, b);
}

void gw_call (GW_ARGS)
{
  GW_LOAD;
  gw_callee ();
  GW_T(GW_TYPE) c = GW_NAME(mrowgather_ew, GW_TYPE) (a, b);
  __riscv_ztt_mss_rm (out, c);
  __riscv_ztt_mss_rm (saved, a);
  __riscv_ztt_mss_rm (saved_index, b);
}

void gw_chain (GW_ARGS)
{
  GW_LOAD;
  GW_T(GW_TYPE) c = GW_NAME(mcolgather_ew, GW_TYPE) (a, b);
  GW_T(GW_TYPE) d = GW_NAME(mrowgather_ew, GW_TYPE) (c, b);
  __riscv_ztt_mss_rm (out, d);
}

void gw_reference (GW_ARGS)
{
  GW_T(GW_TYPE) a = GW_NAME(mls_rm, GW_TYPE) (in);
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
