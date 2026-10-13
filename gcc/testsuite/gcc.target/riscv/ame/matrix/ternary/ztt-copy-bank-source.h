#include <riscv_ztt.h>
#ifndef BK_TYPE
#define BK_TYPE i64_rnu
#define BK_CARRIER __INT64_TYPE__
#define BY_TYPE u64_rnu
#define BY_CARRIER __UINT64_TYPE__
#endif
#define BK_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define BK_NAME(f, t) BK_NAME_(f, t)
#define BK_T_(t) __riscv_ztt_##t##_1x1_t
#define BK_T(t) BK_T_(t)
#define COPY(x) BK_NAME(mcopy_m2m, BK_TYPE) (x)
#define BK_ARGS const BK_CARRIER *a, const BY_CARRIER *b, \
  BK_CARRIER *out, BK_CARRIER *saved, BY_CARRIER *ysaved
#define BK_LOAD BK_T(BK_TYPE) x = BK_NAME(mls_rm, BK_TYPE) (a); \
  BK_T(BY_TYPE) y = BK_NAME(mls_rm, BY_TYPE) (b)
#define BK_STORE(v) BK_NAME(mss_rm, BK_TYPE) (out, v)
#ifdef __cplusplus
extern "C" {
#endif
extern void bk_callee (void);
void __attribute__((noipa)) bk_left (BK_ARGS)
{
  BK_LOAD;
  BK_T(BK_TYPE) d = COPY (x);
  BK_STORE (BK_NAME(mmulacc_ew, BK_TYPE) (d, x, y));
}
void __attribute__((noipa)) bk_right (BK_ARGS)
{
  BK_LOAD;
  BK_T(BK_TYPE) d = COPY (x);
  BK_STORE (BK_NAME(mmulsub_ew, BK_TYPE) (x, y, d));
}
void __attribute__((noipa)) bk_live (BK_ARGS)
{
  BK_LOAD;
  BK_T(BK_TYPE) d = COPY (COPY (x));
  BK_STORE (BK_NAME(mmulacc_ew, BK_TYPE) (d, x, y));
  BK_NAME(mss_rm, BK_TYPE) (saved, d);
}
void __attribute__((noipa)) bk_both_live (BK_ARGS)
{
  BK_LOAD;
  BK_T(BK_TYPE) d = COPY (COPY (COPY (COPY (x))));
  BK_STORE (BK_NAME(mmulacc_ew, BK_TYPE) (d, x, y));
  BK_NAME(mss_rm, BK_TYPE) (saved, x);
  BK_NAME(mss_rm, BY_TYPE) (ysaved, y);
}
void __attribute__((noipa)) bk_call (BK_ARGS)
{
  BK_LOAD;
  BK_T(BK_TYPE) d = COPY (x);
  bk_callee ();
  BK_STORE (BK_NAME(mmulacc_ew, BK_TYPE) (d, x, y));
  BK_NAME(mss_rm, BK_TYPE) (saved, d);
}
void __attribute__((noipa)) bk_same (BK_ARGS)
{
  BK_T(BK_TYPE) x = BK_NAME(mls_rm, BK_TYPE) (a);
  BK_T(BK_TYPE) d = COPY (x), e = COPY (x);
  BK_STORE (BK_NAME(mmulacc_ew, BK_TYPE) (d, e, x));
  BK_NAME(mss_rm, BK_TYPE) (saved, d);
}
#ifdef __cplusplus
}
#endif
