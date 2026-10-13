#include <riscv_ztt.h>
#ifndef ST_TYPE
#define ST_TYPE i32
#define ST_CARRIER __INT32_TYPE__
#endif
#define LIFE_FN_(OP, TYPE) __riscv_ztt_##OP##_##TYPE##_1x2
#define LIFE_FN_X(OP, TYPE) LIFE_FN_ (OP, TYPE)
#define LIFE_FN(OP) LIFE_FN_X (OP, ST_TYPE)
#define LIFE_TY_(TYPE) __riscv_ztt_##TYPE##_1x2_t
#define LIFE_TY(TYPE) LIFE_TY_ (TYPE)
typedef LIFE_TY (ST_TYPE) pair_t;
typedef ST_CARRIER element_t;
#define LIFE_ARGS const element_t *in, element_t *out, element_t *extra, unsigned flag
#define LIFE_STORE(P, V) __riscv_ztt_mss_rm (P, V)
#ifdef __cplusplus
extern "C" {
#endif

#define LIFE_CASE(NAME, FIRST, SECOND, PREP, STORES) \
void lifetime_##NAME (LIFE_ARGS) \
{ \
  pair_t x = LIFE_FN (mls_rm) (in); \
  pair_t y = LIFE_FN (FIRST) (x); \
  pair_t q = PREP; \
  pair_t z = LIFE_FN (SECOND) (q); \
  STORES; \
}

#define LIFE_FIRST LIFE_STORE (extra, q); LIFE_STORE (out, z)
#define LIFE_LAST LIFE_STORE (out, z); LIFE_STORE (extra, q)
LIFE_CASE (row_first, mrowzip_ew, mrowunzip_ew, y, LIFE_FIRST)
LIFE_CASE (row_last, mrowzip_ew, mrowunzip_ew, y, LIFE_LAST)
LIFE_CASE (col_first, mcolzip_ew, mcolunzip_ew, y, LIFE_FIRST)
LIFE_CASE (col_last, mcolzip_ew, mcolunzip_ew, y, LIFE_LAST)
LIFE_CASE (copy_first, mrowzip_ew, mrowunzip_ew,
           LIFE_FN (mcopy_m2m) (y), LIFE_FIRST)
LIFE_CASE (copy_last, mrowzip_ew, mrowunzip_ew,
           LIFE_FN (mcopy_m2m) (y), LIFE_LAST)
LIFE_CASE (unrow_first, mrowunzip_ew, mrowzip_ew, y, LIFE_FIRST)
LIFE_CASE (unrow_last, mrowunzip_ew, mrowzip_ew, y, LIFE_LAST)
LIFE_CASE (uncol_first, mcolunzip_ew, mcolzip_ew, y, LIFE_FIRST)
LIFE_CASE (uncol_last, mcolunzip_ew, mcolzip_ew, y, LIFE_LAST)
LIFE_CASE (middle_twice, mrowzip_ew, mrowunzip_ew, y,
           LIFE_FIRST; LIFE_STORE (extra, q))
LIFE_CASE (parent_live, mrowzip_ew, mrowunzip_ew, y,
           LIFE_STORE (extra, q); LIFE_STORE (out, x); LIFE_STORE (out, z))

#ifdef __cplusplus
}
#endif
#undef LIFE_FIRST
#undef LIFE_LAST
#undef LIFE_CASE
#undef LIFE_ARGS
#undef LIFE_STORE
#undef LIFE_TY
#undef LIFE_TY_
#undef LIFE_FN
#undef LIFE_FN_X
#undef LIFE_FN_
