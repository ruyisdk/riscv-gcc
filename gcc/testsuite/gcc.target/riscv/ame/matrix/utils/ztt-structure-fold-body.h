#include <stdint.h>
#include <riscv_ztt.h>

#ifndef SF_TYPE
#define SF_TYPE i32_rnu
#define SF_CARRIER int32_t
#define SF_HALF 1x1
#define SF_PAIR 1x2
#define SF_COLUMN 2x1
#endif
#define SF_NAME_I(OP, TYPE, SHAPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define SF_NAME_X(OP, TYPE, SHAPE) SF_NAME_I (OP, TYPE, SHAPE)
#define SF_NAME(OP, SHAPE) SF_NAME_X (OP, SF_TYPE, SHAPE)
#define SF_TYPE_I(TYPE, SHAPE) __riscv_ztt_##TYPE##_##SHAPE##_t
#define SF_TYPE_X(TYPE, SHAPE) SF_TYPE_I (TYPE, SHAPE)
#define SF_VALUE(SHAPE) SF_TYPE_X (SF_TYPE, SHAPE)
#ifdef __cplusplus
extern "C" {
#endif

void
structure_left (SF_CARRIER *out, const SF_CARRIER *a, const SF_CARRIER *b)
{
  SF_VALUE (SF_HALF) x = SF_NAME (mls_rm, SF_HALF) (a);
  SF_VALUE (SF_HALF) y = SF_NAME (mls_rm, SF_HALF) (b);
  SF_VALUE (SF_PAIR) pair = SF_NAME (mconcat_m, SF_PAIR) (x, y);
  __riscv_ztt_mss_rm (out, SF_NAME (mextract, SF_HALF) (pair, 0));
}

void
structure_right (SF_CARRIER *out, const SF_CARRIER *a, const SF_CARRIER *b)
{
  SF_VALUE (SF_HALF) x = SF_NAME (mls_rm, SF_HALF) (a);
  SF_VALUE (SF_HALF) y = SF_NAME (mls_rm, SF_HALF) (b);
  SF_VALUE (SF_PAIR) pair = SF_NAME (mconcat_m, SF_PAIR) (x, y);
  __riscv_ztt_mss_rm (out, SF_NAME (mextract, SF_HALF) (pair, 1));
}

void
structure_both (SF_CARRIER *out, SF_CARRIER *other, SF_CARRIER *whole,
		const SF_CARRIER *a, const SF_CARRIER *b)
{
  SF_VALUE (SF_HALF) x = SF_NAME (mls_rm, SF_HALF) (a);
  SF_VALUE (SF_HALF) y = SF_NAME (mls_rm, SF_HALF) (b);
  SF_VALUE (SF_PAIR) pair = SF_NAME (mconcat_m, SF_PAIR) (x, y);
  SF_VALUE (SF_HALF) left = SF_NAME (mextract, SF_HALF) (pair, 0);
  SF_VALUE (SF_HALF) right = SF_NAME (mextract, SF_HALF) (pair, 1);
  __riscv_ztt_mss_rm (out, left);
  __riscv_ztt_mss_rm (other, right);
  __riscv_ztt_mss_rm (whole, pair);
}

#ifdef SF_COLUMN
void
structure_column (SF_CARRIER *out, const SF_CARRIER *a, const SF_CARRIER *b)
{
  SF_VALUE (SF_HALF) x = SF_NAME (mls_rm, SF_HALF) (a);
  SF_VALUE (SF_HALF) y = SF_NAME (mls_rm, SF_HALF) (b);
  SF_VALUE (SF_COLUMN) pair = SF_NAME (mconcat_m, SF_COLUMN) (x, y);
  __riscv_ztt_mss_rm (out, SF_NAME (mextract, SF_HALF) (pair, 1));
}
#endif

#ifdef __cplusplus
}
#endif
