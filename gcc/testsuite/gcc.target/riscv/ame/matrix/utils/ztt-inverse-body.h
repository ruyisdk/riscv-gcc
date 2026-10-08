#include <stdint.h>
#include <riscv_ztt.h>

#ifndef ZIP_TYPE
#define ZIP_TYPE i32_rnu
#define ZIP_CARRIER int32_t
#endif
#define ZIP_NAME_I(OP, TYPE, SHAPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define ZIP_NAME_X(OP, TYPE, SHAPE) ZIP_NAME_I (OP, TYPE, SHAPE)
#define ZIP_NAME(OP) ZIP_NAME_X (OP, ZIP_TYPE, 1x2)
#define ZIP_HALF(OP) ZIP_NAME_X (OP, ZIP_TYPE, 1x1)
#define ZIP_VALUE_I(TYPE) __riscv_ztt_##TYPE##_1x2_t
#define ZIP_VALUE_X(TYPE) ZIP_VALUE_I (TYPE)
#define ZIP_VALUE ZIP_VALUE_X (ZIP_TYPE)
#define ZIP_ARGS ZIP_CARRIER *out, const ZIP_CARRIER *a, \
                 const ZIP_CARRIER *b, ZIP_CARRIER *other, \
                 volatile unsigned *flag, int select
#define ZIP_LOAD ZIP_VALUE p = ZIP_NAME (mls_rm) (a)
#define ZIP_FIRST ZIP_VALUE q = ZIP_NAME (mcolzip_ew) (p)
#define ZIP_STORE __riscv_ztt_mss_rm (out, ZIP_NAME (mcolunzip_ew) (q))

#ifdef __cplusplus
extern "C" {
#endif
extern void inverse_callee (void);

#define ZIP_CHAIN(NAME, FIRST, SECOND) \
void inverse_##NAME (ZIP_ARGS) \
{ \
  ZIP_LOAD; \
  ZIP_VALUE q = ZIP_NAME (FIRST) (p); \
  __riscv_ztt_mss_rm (out, ZIP_NAME (SECOND) (q)); \
}
ZIP_CHAIN (col, mcolzip_ew, mcolunzip_ew)
ZIP_CHAIN (col_reverse, mcolunzip_ew, mcolzip_ew)
ZIP_CHAIN (row, mrowzip_ew, mrowunzip_ew)
ZIP_CHAIN (row_reverse, mrowunzip_ew, mrowzip_ew)
ZIP_CHAIN (cross, mcolzip_ew, mrowunzip_ew)
ZIP_CHAIN (repeated, mcolzip_ew, mcolzip_ew)

void inverse_live_parent (ZIP_ARGS)
{
  ZIP_LOAD;
  ZIP_FIRST;
  ZIP_VALUE r = ZIP_NAME (mcolunzip_ew) (q);
  __riscv_ztt_mss_rm (other, p);
  __riscv_ztt_mss_rm (out, r);
}

void inverse_live_middle (ZIP_ARGS)
{
  ZIP_LOAD;
  ZIP_FIRST;
  ZIP_VALUE r = ZIP_NAME (mcolunzip_ew) (q);
  __riscv_ztt_mss_rm (other, q);
  __riscv_ztt_mss_rm (out, r);
}

void inverse_call (ZIP_ARGS)
{
  ZIP_LOAD;
  ZIP_FIRST;
  inverse_callee ();
  ZIP_STORE;
}

void inverse_asm (ZIP_ARGS)
{
  ZIP_LOAD;
  ZIP_FIRST;
  __asm__ volatile ("" ::: "memory");
  ZIP_STORE;
}

void inverse_memory (ZIP_ARGS)
{
  ZIP_LOAD;
  ZIP_FIRST;
  *flag = 7;
  ZIP_STORE;
}

void inverse_state (ZIP_ARGS)
{
  ZIP_LOAD;
  ZIP_FIRST;
  *flag = __riscv_ztt_get_amefflags ();
  ZIP_STORE;
}

void inverse_join (ZIP_ARGS)
{
  ZIP_LOAD;
  ZIP_FIRST;
  if (!select)
    q = ZIP_NAME (mls_rm) (b);
  ZIP_STORE;
}

void inverse_effect (ZIP_ARGS)
{
  ZIP_VALUE p = ZIP_NAME (mls_rm) (((void) (*flag = *flag + 1), a));
  ZIP_FIRST;
  ZIP_STORE;
}

void inverse_nested_extract (ZIP_ARGS)
{
  ZIP_LOAD;
  ZIP_FIRST;
  ZIP_VALUE r = ZIP_NAME (mcolunzip_ew) (q);
  __riscv_ztt_mss_rm (out, ZIP_NAME (mconcat_m)
    (ZIP_HALF (mextract) (r, 0), ZIP_HALF (mextract) (r, 1)));
}

void inverse_nested_concat (ZIP_ARGS)
{
  ZIP_LOAD;
  ZIP_VALUE r = ZIP_NAME (mconcat_m)
    (ZIP_HALF (mextract) (p, 0), ZIP_HALF (mextract) (p, 1));
  ZIP_VALUE q = ZIP_NAME (mrowzip_ew) (r);
  __riscv_ztt_mss_rm (out, ZIP_NAME (mrowunzip_ew) (q));
}

void inverse_identity (ZIP_ARGS)
{
  __riscv_ztt_mss_rm (out, ZIP_NAME (mls_rm) (a));
}
#ifdef __cplusplus
}
#endif
