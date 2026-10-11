#include <riscv_ztt.h>

#ifndef ZTT_ROWCOL_TYPE
#define ZTT_ROWCOL_TYPE f32_rne
#define ZTT_ROWCOL_CTYPE float
#endif
#define CAT_I(A, B) A##B
#define CAT(A, B) CAT_I (A, B)
#define TYPE(T) CAT (__riscv_ztt_, CAT (T, _1x1_t))
#define FN(OP) CAT (__riscv_ztt_, CAT (OP, CAT (_, CAT (ZTT_ROWCOL_TYPE, _1x1))))

#define TEST(OP) \
void test_##OP (ZTT_ROWCOL_CTYPE *out, const ZTT_ROWCOL_CTYPE *in, int control) \
{ \
  TYPE (ZTT_ROWCOL_TYPE) a = FN (mls_rm) (in); \
  TYPE (ZTT_ROWCOL_TYPE) b = FN (OP) (a, control); \
  __riscv_ztt_mss_rm (out, b); \
}

TEST (mrowbcast_ew_x)
TEST (mcolbcast_ew_x)
TEST (mrowshift_ew_x)
TEST (mcolshift_ew_x)

void unused_broadcast (const ZTT_ROWCOL_CTYPE *in, unsigned int control)
{
  TYPE (ZTT_ROWCOL_TYPE) a = FN (mls_rm) (in);
  (void) FN (mrowbcast_ew_x) (a, control);
}
