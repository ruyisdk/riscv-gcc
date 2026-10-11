#include <stdint.h>
#include <riscv_ztt.h>

typedef __riscv_ztt_i32_rnu_1x2_t pair_t;
typedef __riscv_ztt_i32_rnu_1x1_t half_t;
#define FULL(OP) __riscv_ztt_##OP##_i32_rnu_1x2
#define HALF(OP) __riscv_ztt_##OP##_i32_rnu_1x1
#define TWICE(OP, X) OP (OP (X))
#define FOUR(OP, X) TWICE (OP, TWICE (OP, X))
#define FIVE(OP, X) OP (FOUR (OP, X))
#define ONE(OP, X) OP (X)
#define ARGS int32_t *out, const int32_t *in, int32_t *extra

#ifdef __cplusplus
extern "C" {
#endif
void chain_direct (ARGS)
{
  __riscv_ztt_mss_rm (out, FULL (mls_rm) (in));
}

#define INVERSE(NAME, COPY, FIRST, SECOND) \
void NAME (ARGS) \
{ \
  pair_t p = FULL (mls_rm) (in); \
  pair_t q = FULL (FIRST) (p); \
  pair_t r = COPY (FULL (mcopy_m2m), q); \
  __riscv_ztt_mss_rm (out, FULL (SECOND) (r)); \
}
INVERSE (inverse_two, TWICE, mcolzip_ew, mcolunzip_ew)
INVERSE (inverse_four_col, FOUR, mcolzip_ew, mcolunzip_ew)
INVERSE (inverse_four_row, FOUR, mrowunzip_ew, mrowzip_ew)
INVERSE (inverse_five, FIVE, mcolzip_ew, mcolunzip_ew)
INVERSE (inverse_cross, FOUR, mcolzip_ew, mrowunzip_ew)

void inverse_live_chain (ARGS)
{
  pair_t p = FULL (mls_rm) (in);
  pair_t q = FULL (mcolzip_ew) (p);
  pair_t middle = TWICE (FULL (mcopy_m2m), q);
  pair_t r = TWICE (FULL (mcopy_m2m), middle);
  __riscv_ztt_mss_rm (out, FULL (mcolunzip_ew) (r));
  __riscv_ztt_mss_rm (extra, middle);
}

void inverse_barrier_chain (ARGS)
{
  pair_t p = FULL (mls_rm) (in);
  pair_t q = FULL (mcolzip_ew) (p);
  pair_t middle = TWICE (FULL (mcopy_m2m), q);
  __asm__ volatile ("" ::: "memory");
  pair_t r = TWICE (FULL (mcopy_m2m), middle);
  __riscv_ztt_mss_rm (out, FULL (mcolunzip_ew) (r));
}

#define REBUILD(NAME, LEFT, RIGHT, I, J) \
void NAME (ARGS) \
{ \
  pair_t p = FULL (mls_rm) (in); \
  half_t a = HALF (mextract) (p, I); \
  half_t b = HALF (mextract) (p, J); \
  half_t x = LEFT (HALF (mcopy_m2m), a); \
  half_t y = RIGHT (HALF (mcopy_m2m), b); \
  __riscv_ztt_mss_rm (out, FULL (mconcat_m) (x, y)); \
}
REBUILD (rebuild_two_left, TWICE, ONE, 0, 1)
REBUILD (rebuild_two_right, ONE, TWICE, 0, 1)
REBUILD (rebuild_four, FOUR, FOUR, 0, 1)
REBUILD (rebuild_five, FIVE, FOUR, 0, 1)
REBUILD (rebuild_reversed, FOUR, FOUR, 1, 0)

void rebuild_live_chain (ARGS)
{
  pair_t p = FULL (mls_rm) (in);
  half_t a = HALF (mextract) (p, 0);
  half_t b = HALF (mextract) (p, 1);
  half_t middle = TWICE (HALF (mcopy_m2m), a);
  half_t x = TWICE (HALF (mcopy_m2m), middle);
  half_t y = FOUR (HALF (mcopy_m2m), b);
  __riscv_ztt_mss_rm (out, FULL (mconcat_m) (x, y));
  __riscv_ztt_mss_rm (extra, middle);
}

void rebuild_barrier_chain (ARGS)
{
  pair_t p = FULL (mls_rm) (in);
  half_t a = HALF (mextract) (p, 0);
  half_t b = HALF (mextract) (p, 1);
  half_t x = FOUR (HALF (mcopy_m2m), a);
  __asm__ volatile ("" ::: "memory");
  half_t y = FOUR (HALF (mcopy_m2m), b);
  __riscv_ztt_mss_rm (out, FULL (mconcat_m) (x, y));
}
#ifdef __cplusplus
}
#endif
