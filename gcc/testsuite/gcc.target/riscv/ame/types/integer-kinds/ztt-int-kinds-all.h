/* Compile/assemble checks, not numerical execution evidence.  */
#include <riscv_ztt.h>
#include <stdint.h>
#if __riscv_ztt_integer_kinds_values != 1 || __riscv_ztt_integer_kinds_unary != 1
#error missing integer-kind value/unary support
#endif
#define TYPE_(D, S) __riscv_ztt_##D##_##S##_t
#define TYPE(D, S) TYPE_(D, S)
#define FN_(O, D, S) __riscv_ztt_##O##_##D##_##S
#define FN(O, D, S) FN_(O, D, S)
#define KEEP_M(X) __asm__ volatile ("" : : "Wmr" (X))
#define KEEP_A(X) __asm__ volatile ("" : : "War" (X))
#define CHANGE_M(X) __asm__ volatile ("" : "+Wmr" (X))
#define CHANGE_A(X) __asm__ volatile ("" : "+War" (X))

#if TEST_UDS == 8
void value_0_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 1x2) d = FN(mconv_ew, u4_rnu, 1x2) (s);
  d = FN(mabs_ew, u4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u4_rnu, 1x2) copy = FN(mcopy_m2m, u4_rnu, 1x2) (d);
  d = FN(mclear_m, u4_rnu, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu, 1x4) group = FN(mconcat_m, u4_rnu, 1x4) (copy, copy);
  TYPE(u4_rnu, 1x2) half = FN(mextract, u4_rnu, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_0_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 2x1) d = FN(mconv_ew, u4_rnu, 2x1) (s);
  d = FN(mabs_ew, u4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u4_rnu, 2x1) copy = FN(mcopy_m2m, u4_rnu, 2x1) (d);
  d = FN(mclear_m, u4_rnu, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu, 4x1) group = FN(mconcat_m, u4_rnu, 4x1) (copy, copy);
  TYPE(u4_rnu, 2x1) half = FN(mextract, u4_rnu, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_0_2 (void)
{
  TYPE(u4_rnu, 1x2) m = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE_M(m);
  TYPE(u4_rnu, accx2) a = FN(mcopy_m2a, u4_rnu, accx2) (m);
  TYPE(u4_rnu, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu, 1x2) result = FN(mcopy_a2m, u4_rnu, 1x2) (copy);
  a = FN(mclear_acc, u4_rnu, accx2) ();
  TYPE(u4_rnu, accx2) zero = FN(mzero_acc, u4_rnu, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_0_4 (void)
{
  TYPE(u4_rnu, 1x4) m = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rnu, accx4) a = FN(mcopy_m2a, u4_rnu, accx4) (m);
  TYPE(u4_rnu, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu, 1x4) result = FN(mcopy_a2m, u4_rnu, 1x4) (copy);
  a = FN(mclear_acc, u4_rnu, accx4) ();
  TYPE(u4_rnu, accx4) zero = FN(mzero_acc, u4_rnu, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_0_8 (void)
{
  TYPE(u4_rnu, 1x8) m = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rnu, accx8) a = FN(mcopy_m2a, u4_rnu, accx8) (m);
  TYPE(u4_rnu, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu, 1x8) result = FN(mcopy_a2m, u4_rnu, 1x8) (copy);
  a = FN(mclear_acc, u4_rnu, accx8) ();
  TYPE(u4_rnu, accx8) zero = FN(mzero_acc, u4_rnu, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_1_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u4_rne, 1x2) d = FN(mconv_ew, u4_rne, 1x2) (s);
  d = FN(mabs_ew, u4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u4_rne, 1x2) copy = FN(mcopy_m2m, u4_rne, 1x2) (d);
  d = FN(mclear_m, u4_rne, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne, 1x4) group = FN(mconcat_m, u4_rne, 1x4) (copy, copy);
  TYPE(u4_rne, 1x2) half = FN(mextract, u4_rne, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_1_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u4_rne, 2x1) d = FN(mconv_ew, u4_rne, 2x1) (s);
  d = FN(mabs_ew, u4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u4_rne, 2x1) copy = FN(mcopy_m2m, u4_rne, 2x1) (d);
  d = FN(mclear_m, u4_rne, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne, 4x1) group = FN(mconcat_m, u4_rne, 4x1) (copy, copy);
  TYPE(u4_rne, 2x1) half = FN(mextract, u4_rne, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_1_2 (void)
{
  TYPE(u4_rne, 1x2) m = FN(mzero_m, u4_rne, 1x2) ();
  CHANGE_M(m);
  TYPE(u4_rne, accx2) a = FN(mcopy_m2a, u4_rne, accx2) (m);
  TYPE(u4_rne, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne, 1x2) result = FN(mcopy_a2m, u4_rne, 1x2) (copy);
  a = FN(mclear_acc, u4_rne, accx2) ();
  TYPE(u4_rne, accx2) zero = FN(mzero_acc, u4_rne, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_1_4 (void)
{
  TYPE(u4_rne, 1x4) m = FN(mzero_m, u4_rne, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rne, accx4) a = FN(mcopy_m2a, u4_rne, accx4) (m);
  TYPE(u4_rne, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne, 1x4) result = FN(mcopy_a2m, u4_rne, 1x4) (copy);
  a = FN(mclear_acc, u4_rne, accx4) ();
  TYPE(u4_rne, accx4) zero = FN(mzero_acc, u4_rne, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_1_8 (void)
{
  TYPE(u4_rne, 1x8) m = FN(mzero_m, u4_rne, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rne, accx8) a = FN(mcopy_m2a, u4_rne, accx8) (m);
  TYPE(u4_rne, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne, 1x8) result = FN(mcopy_a2m, u4_rne, 1x8) (copy);
  a = FN(mclear_acc, u4_rne, accx8) ();
  TYPE(u4_rne, accx8) zero = FN(mzero_acc, u4_rne, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_2_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 1x2) d = FN(mconv_ew, u4_rdn, 1x2) (s);
  d = FN(mabs_ew, u4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u4_rdn, 1x2) copy = FN(mcopy_m2m, u4_rdn, 1x2) (d);
  d = FN(mclear_m, u4_rdn, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn, 1x4) group = FN(mconcat_m, u4_rdn, 1x4) (copy, copy);
  TYPE(u4_rdn, 1x2) half = FN(mextract, u4_rdn, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_2_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 2x1) d = FN(mconv_ew, u4_rdn, 2x1) (s);
  d = FN(mabs_ew, u4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u4_rdn, 2x1) copy = FN(mcopy_m2m, u4_rdn, 2x1) (d);
  d = FN(mclear_m, u4_rdn, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn, 4x1) group = FN(mconcat_m, u4_rdn, 4x1) (copy, copy);
  TYPE(u4_rdn, 2x1) half = FN(mextract, u4_rdn, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_2_2 (void)
{
  TYPE(u4_rdn, 1x2) m = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE_M(m);
  TYPE(u4_rdn, accx2) a = FN(mcopy_m2a, u4_rdn, accx2) (m);
  TYPE(u4_rdn, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn, 1x2) result = FN(mcopy_a2m, u4_rdn, 1x2) (copy);
  a = FN(mclear_acc, u4_rdn, accx2) ();
  TYPE(u4_rdn, accx2) zero = FN(mzero_acc, u4_rdn, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_2_4 (void)
{
  TYPE(u4_rdn, 1x4) m = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rdn, accx4) a = FN(mcopy_m2a, u4_rdn, accx4) (m);
  TYPE(u4_rdn, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn, 1x4) result = FN(mcopy_a2m, u4_rdn, 1x4) (copy);
  a = FN(mclear_acc, u4_rdn, accx4) ();
  TYPE(u4_rdn, accx4) zero = FN(mzero_acc, u4_rdn, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_2_8 (void)
{
  TYPE(u4_rdn, 1x8) m = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rdn, accx8) a = FN(mcopy_m2a, u4_rdn, accx8) (m);
  TYPE(u4_rdn, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn, 1x8) result = FN(mcopy_a2m, u4_rdn, 1x8) (copy);
  a = FN(mclear_acc, u4_rdn, accx8) ();
  TYPE(u4_rdn, accx8) zero = FN(mzero_acc, u4_rdn, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_3_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u4_rod, 1x2) d = FN(mconv_ew, u4_rod, 1x2) (s);
  d = FN(mabs_ew, u4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u4_rod, 1x2) copy = FN(mcopy_m2m, u4_rod, 1x2) (d);
  d = FN(mclear_m, u4_rod, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod, 1x4) group = FN(mconcat_m, u4_rod, 1x4) (copy, copy);
  TYPE(u4_rod, 1x2) half = FN(mextract, u4_rod, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_3_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u4_rod, 2x1) d = FN(mconv_ew, u4_rod, 2x1) (s);
  d = FN(mabs_ew, u4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u4_rod, 2x1) copy = FN(mcopy_m2m, u4_rod, 2x1) (d);
  d = FN(mclear_m, u4_rod, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod, 4x1) group = FN(mconcat_m, u4_rod, 4x1) (copy, copy);
  TYPE(u4_rod, 2x1) half = FN(mextract, u4_rod, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_3_2 (void)
{
  TYPE(u4_rod, 1x2) m = FN(mzero_m, u4_rod, 1x2) ();
  CHANGE_M(m);
  TYPE(u4_rod, accx2) a = FN(mcopy_m2a, u4_rod, accx2) (m);
  TYPE(u4_rod, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod, 1x2) result = FN(mcopy_a2m, u4_rod, 1x2) (copy);
  a = FN(mclear_acc, u4_rod, accx2) ();
  TYPE(u4_rod, accx2) zero = FN(mzero_acc, u4_rod, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_3_4 (void)
{
  TYPE(u4_rod, 1x4) m = FN(mzero_m, u4_rod, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rod, accx4) a = FN(mcopy_m2a, u4_rod, accx4) (m);
  TYPE(u4_rod, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod, 1x4) result = FN(mcopy_a2m, u4_rod, 1x4) (copy);
  a = FN(mclear_acc, u4_rod, accx4) ();
  TYPE(u4_rod, accx4) zero = FN(mzero_acc, u4_rod, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_3_8 (void)
{
  TYPE(u4_rod, 1x8) m = FN(mzero_m, u4_rod, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rod, accx8) a = FN(mcopy_m2a, u4_rod, accx8) (m);
  TYPE(u4_rod, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod, 1x8) result = FN(mcopy_a2m, u4_rod, 1x8) (copy);
  a = FN(mclear_acc, u4_rod, accx8) ();
  TYPE(u4_rod, accx8) zero = FN(mzero_acc, u4_rod, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_4_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 1x2) d = FN(mconv_ew, i4_rnu, 1x2) (s);
  d = FN(mabs_ew, i4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i4_rnu, 1x2) copy = FN(mcopy_m2m, i4_rnu, 1x2) (d);
  d = FN(mclear_m, i4_rnu, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu, 1x4) group = FN(mconcat_m, i4_rnu, 1x4) (copy, copy);
  TYPE(i4_rnu, 1x2) half = FN(mextract, i4_rnu, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_4_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 2x1) d = FN(mconv_ew, i4_rnu, 2x1) (s);
  d = FN(mabs_ew, i4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i4_rnu, 2x1) copy = FN(mcopy_m2m, i4_rnu, 2x1) (d);
  d = FN(mclear_m, i4_rnu, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu, 4x1) group = FN(mconcat_m, i4_rnu, 4x1) (copy, copy);
  TYPE(i4_rnu, 2x1) half = FN(mextract, i4_rnu, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_4_2 (void)
{
  TYPE(i4_rnu, 1x2) m = FN(mzero_m, i4_rnu, 1x2) ();
  CHANGE_M(m);
  TYPE(i4_rnu, accx2) a = FN(mcopy_m2a, i4_rnu, accx2) (m);
  TYPE(i4_rnu, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu, 1x2) result = FN(mcopy_a2m, i4_rnu, 1x2) (copy);
  a = FN(mclear_acc, i4_rnu, accx2) ();
  TYPE(i4_rnu, accx2) zero = FN(mzero_acc, i4_rnu, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_4_4 (void)
{
  TYPE(i4_rnu, 1x4) m = FN(mzero_m, i4_rnu, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rnu, accx4) a = FN(mcopy_m2a, i4_rnu, accx4) (m);
  TYPE(i4_rnu, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu, 1x4) result = FN(mcopy_a2m, i4_rnu, 1x4) (copy);
  a = FN(mclear_acc, i4_rnu, accx4) ();
  TYPE(i4_rnu, accx4) zero = FN(mzero_acc, i4_rnu, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_4_8 (void)
{
  TYPE(i4_rnu, 1x8) m = FN(mzero_m, i4_rnu, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rnu, accx8) a = FN(mcopy_m2a, i4_rnu, accx8) (m);
  TYPE(i4_rnu, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu, 1x8) result = FN(mcopy_a2m, i4_rnu, 1x8) (copy);
  a = FN(mclear_acc, i4_rnu, accx8) ();
  TYPE(i4_rnu, accx8) zero = FN(mzero_acc, i4_rnu, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_5_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i4_rne, 1x2) d = FN(mconv_ew, i4_rne, 1x2) (s);
  d = FN(mabs_ew, i4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i4_rne, 1x2) copy = FN(mcopy_m2m, i4_rne, 1x2) (d);
  d = FN(mclear_m, i4_rne, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne, 1x4) group = FN(mconcat_m, i4_rne, 1x4) (copy, copy);
  TYPE(i4_rne, 1x2) half = FN(mextract, i4_rne, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_5_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i4_rne, 2x1) d = FN(mconv_ew, i4_rne, 2x1) (s);
  d = FN(mabs_ew, i4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i4_rne, 2x1) copy = FN(mcopy_m2m, i4_rne, 2x1) (d);
  d = FN(mclear_m, i4_rne, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne, 4x1) group = FN(mconcat_m, i4_rne, 4x1) (copy, copy);
  TYPE(i4_rne, 2x1) half = FN(mextract, i4_rne, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_5_2 (void)
{
  TYPE(i4_rne, 1x2) m = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE_M(m);
  TYPE(i4_rne, accx2) a = FN(mcopy_m2a, i4_rne, accx2) (m);
  TYPE(i4_rne, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne, 1x2) result = FN(mcopy_a2m, i4_rne, 1x2) (copy);
  a = FN(mclear_acc, i4_rne, accx2) ();
  TYPE(i4_rne, accx2) zero = FN(mzero_acc, i4_rne, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_5_4 (void)
{
  TYPE(i4_rne, 1x4) m = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rne, accx4) a = FN(mcopy_m2a, i4_rne, accx4) (m);
  TYPE(i4_rne, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne, 1x4) result = FN(mcopy_a2m, i4_rne, 1x4) (copy);
  a = FN(mclear_acc, i4_rne, accx4) ();
  TYPE(i4_rne, accx4) zero = FN(mzero_acc, i4_rne, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_5_8 (void)
{
  TYPE(i4_rne, 1x8) m = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rne, accx8) a = FN(mcopy_m2a, i4_rne, accx8) (m);
  TYPE(i4_rne, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne, 1x8) result = FN(mcopy_a2m, i4_rne, 1x8) (copy);
  a = FN(mclear_acc, i4_rne, accx8) ();
  TYPE(i4_rne, accx8) zero = FN(mzero_acc, i4_rne, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_6_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 1x2) d = FN(mconv_ew, i4_rdn, 1x2) (s);
  d = FN(mabs_ew, i4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i4_rdn, 1x2) copy = FN(mcopy_m2m, i4_rdn, 1x2) (d);
  d = FN(mclear_m, i4_rdn, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn, 1x4) group = FN(mconcat_m, i4_rdn, 1x4) (copy, copy);
  TYPE(i4_rdn, 1x2) half = FN(mextract, i4_rdn, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_6_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 2x1) d = FN(mconv_ew, i4_rdn, 2x1) (s);
  d = FN(mabs_ew, i4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i4_rdn, 2x1) copy = FN(mcopy_m2m, i4_rdn, 2x1) (d);
  d = FN(mclear_m, i4_rdn, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn, 4x1) group = FN(mconcat_m, i4_rdn, 4x1) (copy, copy);
  TYPE(i4_rdn, 2x1) half = FN(mextract, i4_rdn, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_6_2 (void)
{
  TYPE(i4_rdn, 1x2) m = FN(mzero_m, i4_rdn, 1x2) ();
  CHANGE_M(m);
  TYPE(i4_rdn, accx2) a = FN(mcopy_m2a, i4_rdn, accx2) (m);
  TYPE(i4_rdn, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn, 1x2) result = FN(mcopy_a2m, i4_rdn, 1x2) (copy);
  a = FN(mclear_acc, i4_rdn, accx2) ();
  TYPE(i4_rdn, accx2) zero = FN(mzero_acc, i4_rdn, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_6_4 (void)
{
  TYPE(i4_rdn, 1x4) m = FN(mzero_m, i4_rdn, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rdn, accx4) a = FN(mcopy_m2a, i4_rdn, accx4) (m);
  TYPE(i4_rdn, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn, 1x4) result = FN(mcopy_a2m, i4_rdn, 1x4) (copy);
  a = FN(mclear_acc, i4_rdn, accx4) ();
  TYPE(i4_rdn, accx4) zero = FN(mzero_acc, i4_rdn, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_6_8 (void)
{
  TYPE(i4_rdn, 1x8) m = FN(mzero_m, i4_rdn, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rdn, accx8) a = FN(mcopy_m2a, i4_rdn, accx8) (m);
  TYPE(i4_rdn, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn, 1x8) result = FN(mcopy_a2m, i4_rdn, 1x8) (copy);
  a = FN(mclear_acc, i4_rdn, accx8) ();
  TYPE(i4_rdn, accx8) zero = FN(mzero_acc, i4_rdn, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_7_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i4_rod, 1x2) d = FN(mconv_ew, i4_rod, 1x2) (s);
  d = FN(mabs_ew, i4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i4_rod, 1x2) copy = FN(mcopy_m2m, i4_rod, 1x2) (d);
  d = FN(mclear_m, i4_rod, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod, 1x4) group = FN(mconcat_m, i4_rod, 1x4) (copy, copy);
  TYPE(i4_rod, 1x2) half = FN(mextract, i4_rod, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_7_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i4_rod, 2x1) d = FN(mconv_ew, i4_rod, 2x1) (s);
  d = FN(mabs_ew, i4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i4_rod, 2x1) copy = FN(mcopy_m2m, i4_rod, 2x1) (d);
  d = FN(mclear_m, i4_rod, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod, 4x1) group = FN(mconcat_m, i4_rod, 4x1) (copy, copy);
  TYPE(i4_rod, 2x1) half = FN(mextract, i4_rod, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_7_2 (void)
{
  TYPE(i4_rod, 1x2) m = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE_M(m);
  TYPE(i4_rod, accx2) a = FN(mcopy_m2a, i4_rod, accx2) (m);
  TYPE(i4_rod, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod, 1x2) result = FN(mcopy_a2m, i4_rod, 1x2) (copy);
  a = FN(mclear_acc, i4_rod, accx2) ();
  TYPE(i4_rod, accx2) zero = FN(mzero_acc, i4_rod, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_7_4 (void)
{
  TYPE(i4_rod, 1x4) m = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rod, accx4) a = FN(mcopy_m2a, i4_rod, accx4) (m);
  TYPE(i4_rod, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod, 1x4) result = FN(mcopy_a2m, i4_rod, 1x4) (copy);
  a = FN(mclear_acc, i4_rod, accx4) ();
  TYPE(i4_rod, accx4) zero = FN(mzero_acc, i4_rod, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_7_8 (void)
{
  TYPE(i4_rod, 1x8) m = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rod, accx8) a = FN(mcopy_m2a, i4_rod, accx8) (m);
  TYPE(i4_rod, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod, 1x8) result = FN(mcopy_a2m, i4_rod, 1x8) (copy);
  a = FN(mclear_acc, i4_rod, accx8) ();
  TYPE(i4_rod, accx8) zero = FN(mzero_acc, i4_rod, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_8_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 1x2) d = FN(mconv_ew, u4_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, u4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u4_rnu_sat, 1x2) copy = FN(mcopy_m2m, u4_rnu_sat, 1x2) (d);
  d = FN(mclear_m, u4_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu_sat, 1x4) group = FN(mconcat_m, u4_rnu_sat, 1x4) (copy, copy);
  TYPE(u4_rnu_sat, 1x2) half = FN(mextract, u4_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_8_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 2x1) d = FN(mconv_ew, u4_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, u4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u4_rnu_sat, 2x1) copy = FN(mcopy_m2m, u4_rnu_sat, 2x1) (d);
  d = FN(mclear_m, u4_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu_sat, 4x1) group = FN(mconcat_m, u4_rnu_sat, 4x1) (copy, copy);
  TYPE(u4_rnu_sat, 2x1) half = FN(mextract, u4_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_8_2 (void)
{
  TYPE(u4_rnu_sat, 1x2) m = FN(mzero_m, u4_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u4_rnu_sat, accx2) a = FN(mcopy_m2a, u4_rnu_sat, accx2) (m);
  TYPE(u4_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu_sat, 1x2) result = FN(mcopy_a2m, u4_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u4_rnu_sat, accx2) ();
  TYPE(u4_rnu_sat, accx2) zero = FN(mzero_acc, u4_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_8_4 (void)
{
  TYPE(u4_rnu_sat, 1x4) m = FN(mzero_m, u4_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rnu_sat, accx4) a = FN(mcopy_m2a, u4_rnu_sat, accx4) (m);
  TYPE(u4_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu_sat, 1x4) result = FN(mcopy_a2m, u4_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u4_rnu_sat, accx4) ();
  TYPE(u4_rnu_sat, accx4) zero = FN(mzero_acc, u4_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_8_8 (void)
{
  TYPE(u4_rnu_sat, 1x8) m = FN(mzero_m, u4_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rnu_sat, accx8) a = FN(mcopy_m2a, u4_rnu_sat, accx8) (m);
  TYPE(u4_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu_sat, 1x8) result = FN(mcopy_a2m, u4_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rnu_sat, accx8) ();
  TYPE(u4_rnu_sat, accx8) zero = FN(mzero_acc, u4_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_9_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 1x2) d = FN(mconv_ew, u4_rne_sat, 1x2) (s);
  d = FN(mabs_ew, u4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u4_rne_sat, 1x2) copy = FN(mcopy_m2m, u4_rne_sat, 1x2) (d);
  d = FN(mclear_m, u4_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne_sat, 1x4) group = FN(mconcat_m, u4_rne_sat, 1x4) (copy, copy);
  TYPE(u4_rne_sat, 1x2) half = FN(mextract, u4_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_9_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 2x1) d = FN(mconv_ew, u4_rne_sat, 2x1) (s);
  d = FN(mabs_ew, u4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u4_rne_sat, 2x1) copy = FN(mcopy_m2m, u4_rne_sat, 2x1) (d);
  d = FN(mclear_m, u4_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne_sat, 4x1) group = FN(mconcat_m, u4_rne_sat, 4x1) (copy, copy);
  TYPE(u4_rne_sat, 2x1) half = FN(mextract, u4_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_9_2 (void)
{
  TYPE(u4_rne_sat, 1x2) m = FN(mzero_m, u4_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u4_rne_sat, accx2) a = FN(mcopy_m2a, u4_rne_sat, accx2) (m);
  TYPE(u4_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne_sat, 1x2) result = FN(mcopy_a2m, u4_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u4_rne_sat, accx2) ();
  TYPE(u4_rne_sat, accx2) zero = FN(mzero_acc, u4_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_9_4 (void)
{
  TYPE(u4_rne_sat, 1x4) m = FN(mzero_m, u4_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rne_sat, accx4) a = FN(mcopy_m2a, u4_rne_sat, accx4) (m);
  TYPE(u4_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne_sat, 1x4) result = FN(mcopy_a2m, u4_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u4_rne_sat, accx4) ();
  TYPE(u4_rne_sat, accx4) zero = FN(mzero_acc, u4_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_9_8 (void)
{
  TYPE(u4_rne_sat, 1x8) m = FN(mzero_m, u4_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rne_sat, accx8) a = FN(mcopy_m2a, u4_rne_sat, accx8) (m);
  TYPE(u4_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne_sat, 1x8) result = FN(mcopy_a2m, u4_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rne_sat, accx8) ();
  TYPE(u4_rne_sat, accx8) zero = FN(mzero_acc, u4_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_10_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 1x2) d = FN(mconv_ew, u4_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, u4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u4_rdn_sat, 1x2) copy = FN(mcopy_m2m, u4_rdn_sat, 1x2) (d);
  d = FN(mclear_m, u4_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn_sat, 1x4) group = FN(mconcat_m, u4_rdn_sat, 1x4) (copy, copy);
  TYPE(u4_rdn_sat, 1x2) half = FN(mextract, u4_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_10_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 2x1) d = FN(mconv_ew, u4_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, u4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u4_rdn_sat, 2x1) copy = FN(mcopy_m2m, u4_rdn_sat, 2x1) (d);
  d = FN(mclear_m, u4_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn_sat, 4x1) group = FN(mconcat_m, u4_rdn_sat, 4x1) (copy, copy);
  TYPE(u4_rdn_sat, 2x1) half = FN(mextract, u4_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_10_2 (void)
{
  TYPE(u4_rdn_sat, 1x2) m = FN(mzero_m, u4_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u4_rdn_sat, accx2) a = FN(mcopy_m2a, u4_rdn_sat, accx2) (m);
  TYPE(u4_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn_sat, 1x2) result = FN(mcopy_a2m, u4_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u4_rdn_sat, accx2) ();
  TYPE(u4_rdn_sat, accx2) zero = FN(mzero_acc, u4_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_10_4 (void)
{
  TYPE(u4_rdn_sat, 1x4) m = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rdn_sat, accx4) a = FN(mcopy_m2a, u4_rdn_sat, accx4) (m);
  TYPE(u4_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn_sat, 1x4) result = FN(mcopy_a2m, u4_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u4_rdn_sat, accx4) ();
  TYPE(u4_rdn_sat, accx4) zero = FN(mzero_acc, u4_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_10_8 (void)
{
  TYPE(u4_rdn_sat, 1x8) m = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rdn_sat, accx8) a = FN(mcopy_m2a, u4_rdn_sat, accx8) (m);
  TYPE(u4_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn_sat, 1x8) result = FN(mcopy_a2m, u4_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rdn_sat, accx8) ();
  TYPE(u4_rdn_sat, accx8) zero = FN(mzero_acc, u4_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_11_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 1x2) d = FN(mconv_ew, u4_rod_sat, 1x2) (s);
  d = FN(mabs_ew, u4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u4_rod_sat, 1x2) copy = FN(mcopy_m2m, u4_rod_sat, 1x2) (d);
  d = FN(mclear_m, u4_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod_sat, 1x4) group = FN(mconcat_m, u4_rod_sat, 1x4) (copy, copy);
  TYPE(u4_rod_sat, 1x2) half = FN(mextract, u4_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_11_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 2x1) d = FN(mconv_ew, u4_rod_sat, 2x1) (s);
  d = FN(mabs_ew, u4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u4_rod_sat, 2x1) copy = FN(mcopy_m2m, u4_rod_sat, 2x1) (d);
  d = FN(mclear_m, u4_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod_sat, 4x1) group = FN(mconcat_m, u4_rod_sat, 4x1) (copy, copy);
  TYPE(u4_rod_sat, 2x1) half = FN(mextract, u4_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_11_2 (void)
{
  TYPE(u4_rod_sat, 1x2) m = FN(mzero_m, u4_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u4_rod_sat, accx2) a = FN(mcopy_m2a, u4_rod_sat, accx2) (m);
  TYPE(u4_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod_sat, 1x2) result = FN(mcopy_a2m, u4_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u4_rod_sat, accx2) ();
  TYPE(u4_rod_sat, accx2) zero = FN(mzero_acc, u4_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_11_4 (void)
{
  TYPE(u4_rod_sat, 1x4) m = FN(mzero_m, u4_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rod_sat, accx4) a = FN(mcopy_m2a, u4_rod_sat, accx4) (m);
  TYPE(u4_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod_sat, 1x4) result = FN(mcopy_a2m, u4_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u4_rod_sat, accx4) ();
  TYPE(u4_rod_sat, accx4) zero = FN(mzero_acc, u4_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_11_8 (void)
{
  TYPE(u4_rod_sat, 1x8) m = FN(mzero_m, u4_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rod_sat, accx8) a = FN(mcopy_m2a, u4_rod_sat, accx8) (m);
  TYPE(u4_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod_sat, 1x8) result = FN(mcopy_a2m, u4_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rod_sat, accx8) ();
  TYPE(u4_rod_sat, accx8) zero = FN(mzero_acc, u4_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_12_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 1x2) d = FN(mconv_ew, i4_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, i4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i4_rnu_sat, 1x2) copy = FN(mcopy_m2m, i4_rnu_sat, 1x2) (d);
  d = FN(mclear_m, i4_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu_sat, 1x4) group = FN(mconcat_m, i4_rnu_sat, 1x4) (copy, copy);
  TYPE(i4_rnu_sat, 1x2) half = FN(mextract, i4_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_12_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 2x1) d = FN(mconv_ew, i4_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, i4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i4_rnu_sat, 2x1) copy = FN(mcopy_m2m, i4_rnu_sat, 2x1) (d);
  d = FN(mclear_m, i4_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu_sat, 4x1) group = FN(mconcat_m, i4_rnu_sat, 4x1) (copy, copy);
  TYPE(i4_rnu_sat, 2x1) half = FN(mextract, i4_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_12_2 (void)
{
  TYPE(i4_rnu_sat, 1x2) m = FN(mzero_m, i4_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i4_rnu_sat, accx2) a = FN(mcopy_m2a, i4_rnu_sat, accx2) (m);
  TYPE(i4_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu_sat, 1x2) result = FN(mcopy_a2m, i4_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i4_rnu_sat, accx2) ();
  TYPE(i4_rnu_sat, accx2) zero = FN(mzero_acc, i4_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_12_4 (void)
{
  TYPE(i4_rnu_sat, 1x4) m = FN(mzero_m, i4_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rnu_sat, accx4) a = FN(mcopy_m2a, i4_rnu_sat, accx4) (m);
  TYPE(i4_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu_sat, 1x4) result = FN(mcopy_a2m, i4_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i4_rnu_sat, accx4) ();
  TYPE(i4_rnu_sat, accx4) zero = FN(mzero_acc, i4_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_12_8 (void)
{
  TYPE(i4_rnu_sat, 1x8) m = FN(mzero_m, i4_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rnu_sat, accx8) a = FN(mcopy_m2a, i4_rnu_sat, accx8) (m);
  TYPE(i4_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu_sat, 1x8) result = FN(mcopy_a2m, i4_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rnu_sat, accx8) ();
  TYPE(i4_rnu_sat, accx8) zero = FN(mzero_acc, i4_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_13_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 1x2) d = FN(mconv_ew, i4_rne_sat, 1x2) (s);
  d = FN(mabs_ew, i4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i4_rne_sat, 1x2) copy = FN(mcopy_m2m, i4_rne_sat, 1x2) (d);
  d = FN(mclear_m, i4_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne_sat, 1x4) group = FN(mconcat_m, i4_rne_sat, 1x4) (copy, copy);
  TYPE(i4_rne_sat, 1x2) half = FN(mextract, i4_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_13_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 2x1) d = FN(mconv_ew, i4_rne_sat, 2x1) (s);
  d = FN(mabs_ew, i4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i4_rne_sat, 2x1) copy = FN(mcopy_m2m, i4_rne_sat, 2x1) (d);
  d = FN(mclear_m, i4_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne_sat, 4x1) group = FN(mconcat_m, i4_rne_sat, 4x1) (copy, copy);
  TYPE(i4_rne_sat, 2x1) half = FN(mextract, i4_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_13_2 (void)
{
  TYPE(i4_rne_sat, 1x2) m = FN(mzero_m, i4_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i4_rne_sat, accx2) a = FN(mcopy_m2a, i4_rne_sat, accx2) (m);
  TYPE(i4_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne_sat, 1x2) result = FN(mcopy_a2m, i4_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i4_rne_sat, accx2) ();
  TYPE(i4_rne_sat, accx2) zero = FN(mzero_acc, i4_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_13_4 (void)
{
  TYPE(i4_rne_sat, 1x4) m = FN(mzero_m, i4_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rne_sat, accx4) a = FN(mcopy_m2a, i4_rne_sat, accx4) (m);
  TYPE(i4_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne_sat, 1x4) result = FN(mcopy_a2m, i4_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i4_rne_sat, accx4) ();
  TYPE(i4_rne_sat, accx4) zero = FN(mzero_acc, i4_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_13_8 (void)
{
  TYPE(i4_rne_sat, 1x8) m = FN(mzero_m, i4_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rne_sat, accx8) a = FN(mcopy_m2a, i4_rne_sat, accx8) (m);
  TYPE(i4_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne_sat, 1x8) result = FN(mcopy_a2m, i4_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rne_sat, accx8) ();
  TYPE(i4_rne_sat, accx8) zero = FN(mzero_acc, i4_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_14_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 1x2) d = FN(mconv_ew, i4_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, i4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i4_rdn_sat, 1x2) copy = FN(mcopy_m2m, i4_rdn_sat, 1x2) (d);
  d = FN(mclear_m, i4_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn_sat, 1x4) group = FN(mconcat_m, i4_rdn_sat, 1x4) (copy, copy);
  TYPE(i4_rdn_sat, 1x2) half = FN(mextract, i4_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_14_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 2x1) d = FN(mconv_ew, i4_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, i4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i4_rdn_sat, 2x1) copy = FN(mcopy_m2m, i4_rdn_sat, 2x1) (d);
  d = FN(mclear_m, i4_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn_sat, 4x1) group = FN(mconcat_m, i4_rdn_sat, 4x1) (copy, copy);
  TYPE(i4_rdn_sat, 2x1) half = FN(mextract, i4_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_14_2 (void)
{
  TYPE(i4_rdn_sat, 1x2) m = FN(mzero_m, i4_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i4_rdn_sat, accx2) a = FN(mcopy_m2a, i4_rdn_sat, accx2) (m);
  TYPE(i4_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn_sat, 1x2) result = FN(mcopy_a2m, i4_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i4_rdn_sat, accx2) ();
  TYPE(i4_rdn_sat, accx2) zero = FN(mzero_acc, i4_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_14_4 (void)
{
  TYPE(i4_rdn_sat, 1x4) m = FN(mzero_m, i4_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rdn_sat, accx4) a = FN(mcopy_m2a, i4_rdn_sat, accx4) (m);
  TYPE(i4_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn_sat, 1x4) result = FN(mcopy_a2m, i4_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i4_rdn_sat, accx4) ();
  TYPE(i4_rdn_sat, accx4) zero = FN(mzero_acc, i4_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_14_8 (void)
{
  TYPE(i4_rdn_sat, 1x8) m = FN(mzero_m, i4_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rdn_sat, accx8) a = FN(mcopy_m2a, i4_rdn_sat, accx8) (m);
  TYPE(i4_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn_sat, 1x8) result = FN(mcopy_a2m, i4_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rdn_sat, accx8) ();
  TYPE(i4_rdn_sat, accx8) zero = FN(mzero_acc, i4_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_15_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 1x2) d = FN(mconv_ew, i4_rod_sat, 1x2) (s);
  d = FN(mabs_ew, i4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i4_rod_sat, 1x2) copy = FN(mcopy_m2m, i4_rod_sat, 1x2) (d);
  d = FN(mclear_m, i4_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod_sat, 1x4) group = FN(mconcat_m, i4_rod_sat, 1x4) (copy, copy);
  TYPE(i4_rod_sat, 1x2) half = FN(mextract, i4_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_15_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 2x1) d = FN(mconv_ew, i4_rod_sat, 2x1) (s);
  d = FN(mabs_ew, i4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i4_rod_sat, 2x1) copy = FN(mcopy_m2m, i4_rod_sat, 2x1) (d);
  d = FN(mclear_m, i4_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod_sat, 4x1) group = FN(mconcat_m, i4_rod_sat, 4x1) (copy, copy);
  TYPE(i4_rod_sat, 2x1) half = FN(mextract, i4_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_15_2 (void)
{
  TYPE(i4_rod_sat, 1x2) m = FN(mzero_m, i4_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i4_rod_sat, accx2) a = FN(mcopy_m2a, i4_rod_sat, accx2) (m);
  TYPE(i4_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod_sat, 1x2) result = FN(mcopy_a2m, i4_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i4_rod_sat, accx2) ();
  TYPE(i4_rod_sat, accx2) zero = FN(mzero_acc, i4_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_15_4 (void)
{
  TYPE(i4_rod_sat, 1x4) m = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rod_sat, accx4) a = FN(mcopy_m2a, i4_rod_sat, accx4) (m);
  TYPE(i4_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod_sat, 1x4) result = FN(mcopy_a2m, i4_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i4_rod_sat, accx4) ();
  TYPE(i4_rod_sat, accx4) zero = FN(mzero_acc, i4_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_15_8 (void)
{
  TYPE(i4_rod_sat, 1x8) m = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rod_sat, accx8) a = FN(mcopy_m2a, i4_rod_sat, accx8) (m);
  TYPE(i4_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod_sat, 1x8) result = FN(mcopy_a2m, i4_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rod_sat, accx8) ();
  TYPE(i4_rod_sat, accx8) zero = FN(mzero_acc, i4_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_16_0 (void)
{
  TYPE(i8_rod, 1x1) s = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u8_rnu_sat, 1x1) d = FN(mconv_ew, u8_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x1) back = FN(mconv_ew, i8_rod, 1x1) (d);
  TYPE(u8_rnu_sat, 1x1) copy = FN(mcopy_m2m, u8_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u8_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rnu_sat, 1x2) group = FN(mconcat_m, u8_rnu_sat, 1x2) (copy, copy);
  TYPE(u8_rnu_sat, 1x1) half = FN(mextract, u8_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_16_1 (void)
{
  TYPE(u8_rnu_sat, 1x1) m = FN(mzero_m, u8_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx1) a = FN(mcopy_m2a, u8_rnu_sat, accx1) (m);
  TYPE(u8_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x1) result = FN(mcopy_a2m, u8_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx1) ();
  TYPE(u8_rnu_sat, accx1) zero = FN(mzero_acc, u8_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_16_2 (void)
{
  TYPE(u8_rnu_sat, 1x2) m = FN(mzero_m, u8_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx2) a = FN(mcopy_m2a, u8_rnu_sat, accx2) (m);
  TYPE(u8_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x2) result = FN(mcopy_a2m, u8_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx2) ();
  TYPE(u8_rnu_sat, accx2) zero = FN(mzero_acc, u8_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_16_4 (void)
{
  TYPE(u8_rnu_sat, 1x4) m = FN(mzero_m, u8_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx4) a = FN(mcopy_m2a, u8_rnu_sat, accx4) (m);
  TYPE(u8_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x4) result = FN(mcopy_a2m, u8_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx4) ();
  TYPE(u8_rnu_sat, accx4) zero = FN(mzero_acc, u8_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_17_0 (void)
{
  TYPE(i8_rod, 1x1) s = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u8_rne_sat, 1x1) d = FN(mconv_ew, u8_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x1) back = FN(mconv_ew, i8_rod, 1x1) (d);
  TYPE(u8_rne_sat, 1x1) copy = FN(mcopy_m2m, u8_rne_sat, 1x1) (d);
  d = FN(mclear_m, u8_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rne_sat, 1x2) group = FN(mconcat_m, u8_rne_sat, 1x2) (copy, copy);
  TYPE(u8_rne_sat, 1x1) half = FN(mextract, u8_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_17_1 (void)
{
  TYPE(u8_rne_sat, 1x1) m = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx1) a = FN(mcopy_m2a, u8_rne_sat, accx1) (m);
  TYPE(u8_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x1) result = FN(mcopy_a2m, u8_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx1) ();
  TYPE(u8_rne_sat, accx1) zero = FN(mzero_acc, u8_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_17_2 (void)
{
  TYPE(u8_rne_sat, 1x2) m = FN(mzero_m, u8_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx2) a = FN(mcopy_m2a, u8_rne_sat, accx2) (m);
  TYPE(u8_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x2) result = FN(mcopy_a2m, u8_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx2) ();
  TYPE(u8_rne_sat, accx2) zero = FN(mzero_acc, u8_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_17_4 (void)
{
  TYPE(u8_rne_sat, 1x4) m = FN(mzero_m, u8_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx4) a = FN(mcopy_m2a, u8_rne_sat, accx4) (m);
  TYPE(u8_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x4) result = FN(mcopy_a2m, u8_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx4) ();
  TYPE(u8_rne_sat, accx4) zero = FN(mzero_acc, u8_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_18_0 (void)
{
  TYPE(i8_rod, 1x1) s = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u8_rdn_sat, 1x1) d = FN(mconv_ew, u8_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x1) back = FN(mconv_ew, i8_rod, 1x1) (d);
  TYPE(u8_rdn_sat, 1x1) copy = FN(mcopy_m2m, u8_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u8_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rdn_sat, 1x2) group = FN(mconcat_m, u8_rdn_sat, 1x2) (copy, copy);
  TYPE(u8_rdn_sat, 1x1) half = FN(mextract, u8_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_18_1 (void)
{
  TYPE(u8_rdn_sat, 1x1) m = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx1) a = FN(mcopy_m2a, u8_rdn_sat, accx1) (m);
  TYPE(u8_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x1) result = FN(mcopy_a2m, u8_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx1) ();
  TYPE(u8_rdn_sat, accx1) zero = FN(mzero_acc, u8_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_18_2 (void)
{
  TYPE(u8_rdn_sat, 1x2) m = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx2) a = FN(mcopy_m2a, u8_rdn_sat, accx2) (m);
  TYPE(u8_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x2) result = FN(mcopy_a2m, u8_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx2) ();
  TYPE(u8_rdn_sat, accx2) zero = FN(mzero_acc, u8_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_18_4 (void)
{
  TYPE(u8_rdn_sat, 1x4) m = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx4) a = FN(mcopy_m2a, u8_rdn_sat, accx4) (m);
  TYPE(u8_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x4) result = FN(mcopy_a2m, u8_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx4) ();
  TYPE(u8_rdn_sat, accx4) zero = FN(mzero_acc, u8_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_19_0 (void)
{
  TYPE(i8_rod, 1x1) s = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u8_rod_sat, 1x1) d = FN(mconv_ew, u8_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x1) back = FN(mconv_ew, i8_rod, 1x1) (d);
  TYPE(u8_rod_sat, 1x1) copy = FN(mcopy_m2m, u8_rod_sat, 1x1) (d);
  d = FN(mclear_m, u8_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rod_sat, 1x2) group = FN(mconcat_m, u8_rod_sat, 1x2) (copy, copy);
  TYPE(u8_rod_sat, 1x1) half = FN(mextract, u8_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_19_1 (void)
{
  TYPE(u8_rod_sat, 1x1) m = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx1) a = FN(mcopy_m2a, u8_rod_sat, accx1) (m);
  TYPE(u8_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x1) result = FN(mcopy_a2m, u8_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx1) ();
  TYPE(u8_rod_sat, accx1) zero = FN(mzero_acc, u8_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_19_2 (void)
{
  TYPE(u8_rod_sat, 1x2) m = FN(mzero_m, u8_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx2) a = FN(mcopy_m2a, u8_rod_sat, accx2) (m);
  TYPE(u8_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x2) result = FN(mcopy_a2m, u8_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx2) ();
  TYPE(u8_rod_sat, accx2) zero = FN(mzero_acc, u8_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_19_4 (void)
{
  TYPE(u8_rod_sat, 1x4) m = FN(mzero_m, u8_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx4) a = FN(mcopy_m2a, u8_rod_sat, accx4) (m);
  TYPE(u8_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x4) result = FN(mcopy_a2m, u8_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx4) ();
  TYPE(u8_rod_sat, accx4) zero = FN(mzero_acc, u8_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_20_0 (void)
{
  TYPE(u8_rod, 1x1) s = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i8_rnu_sat, 1x1) d = FN(mconv_ew, i8_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x1) back = FN(mconv_ew, u8_rod, 1x1) (d);
  TYPE(i8_rnu_sat, 1x1) copy = FN(mcopy_m2m, i8_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i8_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rnu_sat, 1x2) group = FN(mconcat_m, i8_rnu_sat, 1x2) (copy, copy);
  TYPE(i8_rnu_sat, 1x1) half = FN(mextract, i8_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_20_1 (void)
{
  TYPE(i8_rnu_sat, 1x1) m = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx1) a = FN(mcopy_m2a, i8_rnu_sat, accx1) (m);
  TYPE(i8_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x1) result = FN(mcopy_a2m, i8_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx1) ();
  TYPE(i8_rnu_sat, accx1) zero = FN(mzero_acc, i8_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_20_2 (void)
{
  TYPE(i8_rnu_sat, 1x2) m = FN(mzero_m, i8_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx2) a = FN(mcopy_m2a, i8_rnu_sat, accx2) (m);
  TYPE(i8_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x2) result = FN(mcopy_a2m, i8_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx2) ();
  TYPE(i8_rnu_sat, accx2) zero = FN(mzero_acc, i8_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_20_4 (void)
{
  TYPE(i8_rnu_sat, 1x4) m = FN(mzero_m, i8_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx4) a = FN(mcopy_m2a, i8_rnu_sat, accx4) (m);
  TYPE(i8_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x4) result = FN(mcopy_a2m, i8_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx4) ();
  TYPE(i8_rnu_sat, accx4) zero = FN(mzero_acc, i8_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_21_0 (void)
{
  TYPE(u8_rod, 1x1) s = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i8_rne_sat, 1x1) d = FN(mconv_ew, i8_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x1) back = FN(mconv_ew, u8_rod, 1x1) (d);
  TYPE(i8_rne_sat, 1x1) copy = FN(mcopy_m2m, i8_rne_sat, 1x1) (d);
  d = FN(mclear_m, i8_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rne_sat, 1x2) group = FN(mconcat_m, i8_rne_sat, 1x2) (copy, copy);
  TYPE(i8_rne_sat, 1x1) half = FN(mextract, i8_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_21_1 (void)
{
  TYPE(i8_rne_sat, 1x1) m = FN(mzero_m, i8_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx1) a = FN(mcopy_m2a, i8_rne_sat, accx1) (m);
  TYPE(i8_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x1) result = FN(mcopy_a2m, i8_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx1) ();
  TYPE(i8_rne_sat, accx1) zero = FN(mzero_acc, i8_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_21_2 (void)
{
  TYPE(i8_rne_sat, 1x2) m = FN(mzero_m, i8_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx2) a = FN(mcopy_m2a, i8_rne_sat, accx2) (m);
  TYPE(i8_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x2) result = FN(mcopy_a2m, i8_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx2) ();
  TYPE(i8_rne_sat, accx2) zero = FN(mzero_acc, i8_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_21_4 (void)
{
  TYPE(i8_rne_sat, 1x4) m = FN(mzero_m, i8_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx4) a = FN(mcopy_m2a, i8_rne_sat, accx4) (m);
  TYPE(i8_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x4) result = FN(mcopy_a2m, i8_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx4) ();
  TYPE(i8_rne_sat, accx4) zero = FN(mzero_acc, i8_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_22_0 (void)
{
  TYPE(u8_rod, 1x1) s = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i8_rdn_sat, 1x1) d = FN(mconv_ew, i8_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x1) back = FN(mconv_ew, u8_rod, 1x1) (d);
  TYPE(i8_rdn_sat, 1x1) copy = FN(mcopy_m2m, i8_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i8_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rdn_sat, 1x2) group = FN(mconcat_m, i8_rdn_sat, 1x2) (copy, copy);
  TYPE(i8_rdn_sat, 1x1) half = FN(mextract, i8_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_22_1 (void)
{
  TYPE(i8_rdn_sat, 1x1) m = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx1) a = FN(mcopy_m2a, i8_rdn_sat, accx1) (m);
  TYPE(i8_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x1) result = FN(mcopy_a2m, i8_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx1) ();
  TYPE(i8_rdn_sat, accx1) zero = FN(mzero_acc, i8_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_22_2 (void)
{
  TYPE(i8_rdn_sat, 1x2) m = FN(mzero_m, i8_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx2) a = FN(mcopy_m2a, i8_rdn_sat, accx2) (m);
  TYPE(i8_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x2) result = FN(mcopy_a2m, i8_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx2) ();
  TYPE(i8_rdn_sat, accx2) zero = FN(mzero_acc, i8_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_22_4 (void)
{
  TYPE(i8_rdn_sat, 1x4) m = FN(mzero_m, i8_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx4) a = FN(mcopy_m2a, i8_rdn_sat, accx4) (m);
  TYPE(i8_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x4) result = FN(mcopy_a2m, i8_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx4) ();
  TYPE(i8_rdn_sat, accx4) zero = FN(mzero_acc, i8_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_23_0 (void)
{
  TYPE(u8_rod, 1x1) s = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i8_rod_sat, 1x1) d = FN(mconv_ew, i8_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x1) back = FN(mconv_ew, u8_rod, 1x1) (d);
  TYPE(i8_rod_sat, 1x1) copy = FN(mcopy_m2m, i8_rod_sat, 1x1) (d);
  d = FN(mclear_m, i8_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rod_sat, 1x2) group = FN(mconcat_m, i8_rod_sat, 1x2) (copy, copy);
  TYPE(i8_rod_sat, 1x1) half = FN(mextract, i8_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_23_1 (void)
{
  TYPE(i8_rod_sat, 1x1) m = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx1) a = FN(mcopy_m2a, i8_rod_sat, accx1) (m);
  TYPE(i8_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x1) result = FN(mcopy_a2m, i8_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx1) ();
  TYPE(i8_rod_sat, accx1) zero = FN(mzero_acc, i8_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_23_2 (void)
{
  TYPE(i8_rod_sat, 1x2) m = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx2) a = FN(mcopy_m2a, i8_rod_sat, accx2) (m);
  TYPE(i8_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x2) result = FN(mcopy_a2m, i8_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx2) ();
  TYPE(i8_rod_sat, accx2) zero = FN(mzero_acc, i8_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_23_4 (void)
{
  TYPE(i8_rod_sat, 1x4) m = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx4) a = FN(mcopy_m2a, i8_rod_sat, accx4) (m);
  TYPE(i8_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x4) result = FN(mcopy_a2m, i8_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx4) ();
  TYPE(i8_rod_sat, accx4) zero = FN(mzero_acc, i8_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_24_0 (void)
{
  TYPE(i16_rod, 1x1) s = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u16_rnu_sat, 1x1) d = FN(mconv_ew, u16_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x1) back = FN(mconv_ew, i16_rod, 1x1) (d);
  TYPE(u16_rnu_sat, 1x1) copy = FN(mcopy_m2m, u16_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u16_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rnu_sat, 1x2) group = FN(mconcat_m, u16_rnu_sat, 1x2) (copy, copy);
  TYPE(u16_rnu_sat, 1x1) half = FN(mextract, u16_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_24_1 (void)
{
  TYPE(u16_rnu_sat, 1x1) m = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx1) a = FN(mcopy_m2a, u16_rnu_sat, accx1) (m);
  TYPE(u16_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x1) result = FN(mcopy_a2m, u16_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx1) ();
  TYPE(u16_rnu_sat, accx1) zero = FN(mzero_acc, u16_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_24_2 (void)
{
  TYPE(u16_rnu_sat, 1x2) m = FN(mzero_m, u16_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx2) a = FN(mcopy_m2a, u16_rnu_sat, accx2) (m);
  TYPE(u16_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x2) result = FN(mcopy_a2m, u16_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx2) ();
  TYPE(u16_rnu_sat, accx2) zero = FN(mzero_acc, u16_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_25_0 (void)
{
  TYPE(i16_rod, 1x1) s = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u16_rne_sat, 1x1) d = FN(mconv_ew, u16_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x1) back = FN(mconv_ew, i16_rod, 1x1) (d);
  TYPE(u16_rne_sat, 1x1) copy = FN(mcopy_m2m, u16_rne_sat, 1x1) (d);
  d = FN(mclear_m, u16_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rne_sat, 1x2) group = FN(mconcat_m, u16_rne_sat, 1x2) (copy, copy);
  TYPE(u16_rne_sat, 1x1) half = FN(mextract, u16_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_25_1 (void)
{
  TYPE(u16_rne_sat, 1x1) m = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx1) a = FN(mcopy_m2a, u16_rne_sat, accx1) (m);
  TYPE(u16_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x1) result = FN(mcopy_a2m, u16_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx1) ();
  TYPE(u16_rne_sat, accx1) zero = FN(mzero_acc, u16_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_25_2 (void)
{
  TYPE(u16_rne_sat, 1x2) m = FN(mzero_m, u16_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx2) a = FN(mcopy_m2a, u16_rne_sat, accx2) (m);
  TYPE(u16_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x2) result = FN(mcopy_a2m, u16_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx2) ();
  TYPE(u16_rne_sat, accx2) zero = FN(mzero_acc, u16_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_26_0 (void)
{
  TYPE(i16_rod, 1x1) s = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u16_rdn_sat, 1x1) d = FN(mconv_ew, u16_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x1) back = FN(mconv_ew, i16_rod, 1x1) (d);
  TYPE(u16_rdn_sat, 1x1) copy = FN(mcopy_m2m, u16_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u16_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rdn_sat, 1x2) group = FN(mconcat_m, u16_rdn_sat, 1x2) (copy, copy);
  TYPE(u16_rdn_sat, 1x1) half = FN(mextract, u16_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_26_1 (void)
{
  TYPE(u16_rdn_sat, 1x1) m = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx1) a = FN(mcopy_m2a, u16_rdn_sat, accx1) (m);
  TYPE(u16_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x1) result = FN(mcopy_a2m, u16_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx1) ();
  TYPE(u16_rdn_sat, accx1) zero = FN(mzero_acc, u16_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_26_2 (void)
{
  TYPE(u16_rdn_sat, 1x2) m = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx2) a = FN(mcopy_m2a, u16_rdn_sat, accx2) (m);
  TYPE(u16_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x2) result = FN(mcopy_a2m, u16_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx2) ();
  TYPE(u16_rdn_sat, accx2) zero = FN(mzero_acc, u16_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_27_0 (void)
{
  TYPE(i16_rod, 1x1) s = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u16_rod_sat, 1x1) d = FN(mconv_ew, u16_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x1) back = FN(mconv_ew, i16_rod, 1x1) (d);
  TYPE(u16_rod_sat, 1x1) copy = FN(mcopy_m2m, u16_rod_sat, 1x1) (d);
  d = FN(mclear_m, u16_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rod_sat, 1x2) group = FN(mconcat_m, u16_rod_sat, 1x2) (copy, copy);
  TYPE(u16_rod_sat, 1x1) half = FN(mextract, u16_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_27_1 (void)
{
  TYPE(u16_rod_sat, 1x1) m = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx1) a = FN(mcopy_m2a, u16_rod_sat, accx1) (m);
  TYPE(u16_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x1) result = FN(mcopy_a2m, u16_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx1) ();
  TYPE(u16_rod_sat, accx1) zero = FN(mzero_acc, u16_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_27_2 (void)
{
  TYPE(u16_rod_sat, 1x2) m = FN(mzero_m, u16_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx2) a = FN(mcopy_m2a, u16_rod_sat, accx2) (m);
  TYPE(u16_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x2) result = FN(mcopy_a2m, u16_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx2) ();
  TYPE(u16_rod_sat, accx2) zero = FN(mzero_acc, u16_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_28_0 (void)
{
  TYPE(u16_rod, 1x1) s = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i16_rnu_sat, 1x1) d = FN(mconv_ew, i16_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x1) back = FN(mconv_ew, u16_rod, 1x1) (d);
  TYPE(i16_rnu_sat, 1x1) copy = FN(mcopy_m2m, i16_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i16_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rnu_sat, 1x2) group = FN(mconcat_m, i16_rnu_sat, 1x2) (copy, copy);
  TYPE(i16_rnu_sat, 1x1) half = FN(mextract, i16_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_28_1 (void)
{
  TYPE(i16_rnu_sat, 1x1) m = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx1) a = FN(mcopy_m2a, i16_rnu_sat, accx1) (m);
  TYPE(i16_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x1) result = FN(mcopy_a2m, i16_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx1) ();
  TYPE(i16_rnu_sat, accx1) zero = FN(mzero_acc, i16_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_28_2 (void)
{
  TYPE(i16_rnu_sat, 1x2) m = FN(mzero_m, i16_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx2) a = FN(mcopy_m2a, i16_rnu_sat, accx2) (m);
  TYPE(i16_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x2) result = FN(mcopy_a2m, i16_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx2) ();
  TYPE(i16_rnu_sat, accx2) zero = FN(mzero_acc, i16_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_29_0 (void)
{
  TYPE(u16_rod, 1x1) s = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i16_rne_sat, 1x1) d = FN(mconv_ew, i16_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x1) back = FN(mconv_ew, u16_rod, 1x1) (d);
  TYPE(i16_rne_sat, 1x1) copy = FN(mcopy_m2m, i16_rne_sat, 1x1) (d);
  d = FN(mclear_m, i16_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rne_sat, 1x2) group = FN(mconcat_m, i16_rne_sat, 1x2) (copy, copy);
  TYPE(i16_rne_sat, 1x1) half = FN(mextract, i16_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_29_1 (void)
{
  TYPE(i16_rne_sat, 1x1) m = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx1) a = FN(mcopy_m2a, i16_rne_sat, accx1) (m);
  TYPE(i16_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x1) result = FN(mcopy_a2m, i16_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx1) ();
  TYPE(i16_rne_sat, accx1) zero = FN(mzero_acc, i16_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_29_2 (void)
{
  TYPE(i16_rne_sat, 1x2) m = FN(mzero_m, i16_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx2) a = FN(mcopy_m2a, i16_rne_sat, accx2) (m);
  TYPE(i16_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x2) result = FN(mcopy_a2m, i16_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx2) ();
  TYPE(i16_rne_sat, accx2) zero = FN(mzero_acc, i16_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_30_0 (void)
{
  TYPE(u16_rod, 1x1) s = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i16_rdn_sat, 1x1) d = FN(mconv_ew, i16_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x1) back = FN(mconv_ew, u16_rod, 1x1) (d);
  TYPE(i16_rdn_sat, 1x1) copy = FN(mcopy_m2m, i16_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i16_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rdn_sat, 1x2) group = FN(mconcat_m, i16_rdn_sat, 1x2) (copy, copy);
  TYPE(i16_rdn_sat, 1x1) half = FN(mextract, i16_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_30_1 (void)
{
  TYPE(i16_rdn_sat, 1x1) m = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx1) a = FN(mcopy_m2a, i16_rdn_sat, accx1) (m);
  TYPE(i16_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x1) result = FN(mcopy_a2m, i16_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx1) ();
  TYPE(i16_rdn_sat, accx1) zero = FN(mzero_acc, i16_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_30_2 (void)
{
  TYPE(i16_rdn_sat, 1x2) m = FN(mzero_m, i16_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx2) a = FN(mcopy_m2a, i16_rdn_sat, accx2) (m);
  TYPE(i16_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x2) result = FN(mcopy_a2m, i16_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx2) ();
  TYPE(i16_rdn_sat, accx2) zero = FN(mzero_acc, i16_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_31_0 (void)
{
  TYPE(u16_rod, 1x1) s = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i16_rod_sat, 1x1) d = FN(mconv_ew, i16_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x1) back = FN(mconv_ew, u16_rod, 1x1) (d);
  TYPE(i16_rod_sat, 1x1) copy = FN(mcopy_m2m, i16_rod_sat, 1x1) (d);
  d = FN(mclear_m, i16_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rod_sat, 1x2) group = FN(mconcat_m, i16_rod_sat, 1x2) (copy, copy);
  TYPE(i16_rod_sat, 1x1) half = FN(mextract, i16_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_31_1 (void)
{
  TYPE(i16_rod_sat, 1x1) m = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx1) a = FN(mcopy_m2a, i16_rod_sat, accx1) (m);
  TYPE(i16_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x1) result = FN(mcopy_a2m, i16_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx1) ();
  TYPE(i16_rod_sat, accx1) zero = FN(mzero_acc, i16_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_31_2 (void)
{
  TYPE(i16_rod_sat, 1x2) m = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx2) a = FN(mcopy_m2a, i16_rod_sat, accx2) (m);
  TYPE(i16_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x2) result = FN(mcopy_a2m, i16_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx2) ();
  TYPE(i16_rod_sat, accx2) zero = FN(mzero_acc, i16_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_32_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rnu_sat, 1x1) d = FN(mconv_ew, u32_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rnu_sat, 1x1) copy = FN(mcopy_m2m, u32_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u32_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_32_1 (void)
{
  TYPE(u32_rnu_sat, 1x1) m = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx1) a = FN(mcopy_m2a, u32_rnu_sat, accx1) (m);
  TYPE(u32_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x1) result = FN(mcopy_a2m, u32_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx1) ();
  TYPE(u32_rnu_sat, accx1) zero = FN(mzero_acc, u32_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_33_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rne_sat, 1x1) d = FN(mconv_ew, u32_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rne_sat, 1x1) copy = FN(mcopy_m2m, u32_rne_sat, 1x1) (d);
  d = FN(mclear_m, u32_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_33_1 (void)
{
  TYPE(u32_rne_sat, 1x1) m = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx1) a = FN(mcopy_m2a, u32_rne_sat, accx1) (m);
  TYPE(u32_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x1) result = FN(mcopy_a2m, u32_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx1) ();
  TYPE(u32_rne_sat, accx1) zero = FN(mzero_acc, u32_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_34_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rdn_sat, 1x1) d = FN(mconv_ew, u32_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rdn_sat, 1x1) copy = FN(mcopy_m2m, u32_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u32_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_34_1 (void)
{
  TYPE(u32_rdn_sat, 1x1) m = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx1) a = FN(mcopy_m2a, u32_rdn_sat, accx1) (m);
  TYPE(u32_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x1) result = FN(mcopy_a2m, u32_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx1) ();
  TYPE(u32_rdn_sat, accx1) zero = FN(mzero_acc, u32_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_35_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rod_sat, 1x1) d = FN(mconv_ew, u32_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rod_sat, 1x1) copy = FN(mcopy_m2m, u32_rod_sat, 1x1) (d);
  d = FN(mclear_m, u32_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_35_1 (void)
{
  TYPE(u32_rod_sat, 1x1) m = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx1) a = FN(mcopy_m2a, u32_rod_sat, accx1) (m);
  TYPE(u32_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x1) result = FN(mcopy_a2m, u32_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx1) ();
  TYPE(u32_rod_sat, accx1) zero = FN(mzero_acc, u32_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_36_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rnu_sat, 1x1) d = FN(mconv_ew, i32_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rnu_sat, 1x1) copy = FN(mcopy_m2m, i32_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i32_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_36_1 (void)
{
  TYPE(i32_rnu_sat, 1x1) m = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx1) a = FN(mcopy_m2a, i32_rnu_sat, accx1) (m);
  TYPE(i32_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x1) result = FN(mcopy_a2m, i32_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx1) ();
  TYPE(i32_rnu_sat, accx1) zero = FN(mzero_acc, i32_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_37_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rne_sat, 1x1) d = FN(mconv_ew, i32_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rne_sat, 1x1) copy = FN(mcopy_m2m, i32_rne_sat, 1x1) (d);
  d = FN(mclear_m, i32_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_37_1 (void)
{
  TYPE(i32_rne_sat, 1x1) m = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx1) a = FN(mcopy_m2a, i32_rne_sat, accx1) (m);
  TYPE(i32_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x1) result = FN(mcopy_a2m, i32_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx1) ();
  TYPE(i32_rne_sat, accx1) zero = FN(mzero_acc, i32_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_38_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rdn_sat, 1x1) d = FN(mconv_ew, i32_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rdn_sat, 1x1) copy = FN(mcopy_m2m, i32_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i32_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_38_1 (void)
{
  TYPE(i32_rdn_sat, 1x1) m = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx1) a = FN(mcopy_m2a, i32_rdn_sat, accx1) (m);
  TYPE(i32_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x1) result = FN(mcopy_a2m, i32_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx1) ();
  TYPE(i32_rdn_sat, accx1) zero = FN(mzero_acc, i32_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_39_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rod_sat, 1x1) d = FN(mconv_ew, i32_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rod_sat, 1x1) copy = FN(mcopy_m2m, i32_rod_sat, 1x1) (d);
  d = FN(mclear_m, i32_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_39_1 (void)
{
  TYPE(i32_rod_sat, 1x1) m = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx1) a = FN(mcopy_m2a, i32_rod_sat, accx1) (m);
  TYPE(i32_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x1) result = FN(mcopy_a2m, i32_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx1) ();
  TYPE(i32_rod_sat, accx1) zero = FN(mzero_acc, i32_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
#endif

#if TEST_UDS == 16
void value_0_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 1x4) d = FN(mconv_ew, u4_rnu, 1x4) (s);
  d = FN(mabs_ew, u4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u4_rnu, 1x4) copy = FN(mcopy_m2m, u4_rnu, 1x4) (d);
  d = FN(mclear_m, u4_rnu, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu, 1x8) group = FN(mconcat_m, u4_rnu, 1x8) (copy, copy);
  TYPE(u4_rnu, 1x4) half = FN(mextract, u4_rnu, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_0_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 4x1) d = FN(mconv_ew, u4_rnu, 4x1) (s);
  d = FN(mabs_ew, u4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u4_rnu, 4x1) copy = FN(mcopy_m2m, u4_rnu, 4x1) (d);
  d = FN(mclear_m, u4_rnu, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu, 8x1) group = FN(mconcat_m, u4_rnu, 8x1) (copy, copy);
  TYPE(u4_rnu, 4x1) half = FN(mextract, u4_rnu, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_0_4 (void)
{
  TYPE(u4_rnu, 1x4) m = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rnu, accx4) a = FN(mcopy_m2a, u4_rnu, accx4) (m);
  TYPE(u4_rnu, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu, 1x4) result = FN(mcopy_a2m, u4_rnu, 1x4) (copy);
  a = FN(mclear_acc, u4_rnu, accx4) ();
  TYPE(u4_rnu, accx4) zero = FN(mzero_acc, u4_rnu, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_0_8 (void)
{
  TYPE(u4_rnu, 1x8) m = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rnu, accx8) a = FN(mcopy_m2a, u4_rnu, accx8) (m);
  TYPE(u4_rnu, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu, 1x8) result = FN(mcopy_a2m, u4_rnu, 1x8) (copy);
  a = FN(mclear_acc, u4_rnu, accx8) ();
  TYPE(u4_rnu, accx8) zero = FN(mzero_acc, u4_rnu, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_0_16 (void)
{
  TYPE(u4_rnu, 1x16) m = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rnu, accx16) a = FN(mcopy_m2a, u4_rnu, accx16) (m);
  TYPE(u4_rnu, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu, 1x16) result = FN(mcopy_a2m, u4_rnu, 1x16) (copy);
  a = FN(mclear_acc, u4_rnu, accx16) ();
  TYPE(u4_rnu, accx16) zero = FN(mzero_acc, u4_rnu, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_1_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u4_rne, 1x4) d = FN(mconv_ew, u4_rne, 1x4) (s);
  d = FN(mabs_ew, u4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u4_rne, 1x4) copy = FN(mcopy_m2m, u4_rne, 1x4) (d);
  d = FN(mclear_m, u4_rne, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne, 1x8) group = FN(mconcat_m, u4_rne, 1x8) (copy, copy);
  TYPE(u4_rne, 1x4) half = FN(mextract, u4_rne, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_1_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u4_rne, 4x1) d = FN(mconv_ew, u4_rne, 4x1) (s);
  d = FN(mabs_ew, u4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u4_rne, 4x1) copy = FN(mcopy_m2m, u4_rne, 4x1) (d);
  d = FN(mclear_m, u4_rne, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne, 8x1) group = FN(mconcat_m, u4_rne, 8x1) (copy, copy);
  TYPE(u4_rne, 4x1) half = FN(mextract, u4_rne, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_1_4 (void)
{
  TYPE(u4_rne, 1x4) m = FN(mzero_m, u4_rne, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rne, accx4) a = FN(mcopy_m2a, u4_rne, accx4) (m);
  TYPE(u4_rne, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne, 1x4) result = FN(mcopy_a2m, u4_rne, 1x4) (copy);
  a = FN(mclear_acc, u4_rne, accx4) ();
  TYPE(u4_rne, accx4) zero = FN(mzero_acc, u4_rne, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_1_8 (void)
{
  TYPE(u4_rne, 1x8) m = FN(mzero_m, u4_rne, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rne, accx8) a = FN(mcopy_m2a, u4_rne, accx8) (m);
  TYPE(u4_rne, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne, 1x8) result = FN(mcopy_a2m, u4_rne, 1x8) (copy);
  a = FN(mclear_acc, u4_rne, accx8) ();
  TYPE(u4_rne, accx8) zero = FN(mzero_acc, u4_rne, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_1_16 (void)
{
  TYPE(u4_rne, 1x16) m = FN(mzero_m, u4_rne, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rne, accx16) a = FN(mcopy_m2a, u4_rne, accx16) (m);
  TYPE(u4_rne, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne, 1x16) result = FN(mcopy_a2m, u4_rne, 1x16) (copy);
  a = FN(mclear_acc, u4_rne, accx16) ();
  TYPE(u4_rne, accx16) zero = FN(mzero_acc, u4_rne, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_2_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 1x4) d = FN(mconv_ew, u4_rdn, 1x4) (s);
  d = FN(mabs_ew, u4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u4_rdn, 1x4) copy = FN(mcopy_m2m, u4_rdn, 1x4) (d);
  d = FN(mclear_m, u4_rdn, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn, 1x8) group = FN(mconcat_m, u4_rdn, 1x8) (copy, copy);
  TYPE(u4_rdn, 1x4) half = FN(mextract, u4_rdn, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_2_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 4x1) d = FN(mconv_ew, u4_rdn, 4x1) (s);
  d = FN(mabs_ew, u4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u4_rdn, 4x1) copy = FN(mcopy_m2m, u4_rdn, 4x1) (d);
  d = FN(mclear_m, u4_rdn, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn, 8x1) group = FN(mconcat_m, u4_rdn, 8x1) (copy, copy);
  TYPE(u4_rdn, 4x1) half = FN(mextract, u4_rdn, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_2_4 (void)
{
  TYPE(u4_rdn, 1x4) m = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rdn, accx4) a = FN(mcopy_m2a, u4_rdn, accx4) (m);
  TYPE(u4_rdn, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn, 1x4) result = FN(mcopy_a2m, u4_rdn, 1x4) (copy);
  a = FN(mclear_acc, u4_rdn, accx4) ();
  TYPE(u4_rdn, accx4) zero = FN(mzero_acc, u4_rdn, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_2_8 (void)
{
  TYPE(u4_rdn, 1x8) m = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rdn, accx8) a = FN(mcopy_m2a, u4_rdn, accx8) (m);
  TYPE(u4_rdn, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn, 1x8) result = FN(mcopy_a2m, u4_rdn, 1x8) (copy);
  a = FN(mclear_acc, u4_rdn, accx8) ();
  TYPE(u4_rdn, accx8) zero = FN(mzero_acc, u4_rdn, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_2_16 (void)
{
  TYPE(u4_rdn, 1x16) m = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rdn, accx16) a = FN(mcopy_m2a, u4_rdn, accx16) (m);
  TYPE(u4_rdn, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn, 1x16) result = FN(mcopy_a2m, u4_rdn, 1x16) (copy);
  a = FN(mclear_acc, u4_rdn, accx16) ();
  TYPE(u4_rdn, accx16) zero = FN(mzero_acc, u4_rdn, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_3_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u4_rod, 1x4) d = FN(mconv_ew, u4_rod, 1x4) (s);
  d = FN(mabs_ew, u4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u4_rod, 1x4) copy = FN(mcopy_m2m, u4_rod, 1x4) (d);
  d = FN(mclear_m, u4_rod, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod, 1x8) group = FN(mconcat_m, u4_rod, 1x8) (copy, copy);
  TYPE(u4_rod, 1x4) half = FN(mextract, u4_rod, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_3_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u4_rod, 4x1) d = FN(mconv_ew, u4_rod, 4x1) (s);
  d = FN(mabs_ew, u4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u4_rod, 4x1) copy = FN(mcopy_m2m, u4_rod, 4x1) (d);
  d = FN(mclear_m, u4_rod, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod, 8x1) group = FN(mconcat_m, u4_rod, 8x1) (copy, copy);
  TYPE(u4_rod, 4x1) half = FN(mextract, u4_rod, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_3_4 (void)
{
  TYPE(u4_rod, 1x4) m = FN(mzero_m, u4_rod, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rod, accx4) a = FN(mcopy_m2a, u4_rod, accx4) (m);
  TYPE(u4_rod, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod, 1x4) result = FN(mcopy_a2m, u4_rod, 1x4) (copy);
  a = FN(mclear_acc, u4_rod, accx4) ();
  TYPE(u4_rod, accx4) zero = FN(mzero_acc, u4_rod, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_3_8 (void)
{
  TYPE(u4_rod, 1x8) m = FN(mzero_m, u4_rod, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rod, accx8) a = FN(mcopy_m2a, u4_rod, accx8) (m);
  TYPE(u4_rod, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod, 1x8) result = FN(mcopy_a2m, u4_rod, 1x8) (copy);
  a = FN(mclear_acc, u4_rod, accx8) ();
  TYPE(u4_rod, accx8) zero = FN(mzero_acc, u4_rod, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_3_16 (void)
{
  TYPE(u4_rod, 1x16) m = FN(mzero_m, u4_rod, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rod, accx16) a = FN(mcopy_m2a, u4_rod, accx16) (m);
  TYPE(u4_rod, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod, 1x16) result = FN(mcopy_a2m, u4_rod, 1x16) (copy);
  a = FN(mclear_acc, u4_rod, accx16) ();
  TYPE(u4_rod, accx16) zero = FN(mzero_acc, u4_rod, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_4_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 1x4) d = FN(mconv_ew, i4_rnu, 1x4) (s);
  d = FN(mabs_ew, i4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i4_rnu, 1x4) copy = FN(mcopy_m2m, i4_rnu, 1x4) (d);
  d = FN(mclear_m, i4_rnu, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu, 1x8) group = FN(mconcat_m, i4_rnu, 1x8) (copy, copy);
  TYPE(i4_rnu, 1x4) half = FN(mextract, i4_rnu, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_4_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 4x1) d = FN(mconv_ew, i4_rnu, 4x1) (s);
  d = FN(mabs_ew, i4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i4_rnu, 4x1) copy = FN(mcopy_m2m, i4_rnu, 4x1) (d);
  d = FN(mclear_m, i4_rnu, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu, 8x1) group = FN(mconcat_m, i4_rnu, 8x1) (copy, copy);
  TYPE(i4_rnu, 4x1) half = FN(mextract, i4_rnu, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_4_4 (void)
{
  TYPE(i4_rnu, 1x4) m = FN(mzero_m, i4_rnu, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rnu, accx4) a = FN(mcopy_m2a, i4_rnu, accx4) (m);
  TYPE(i4_rnu, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu, 1x4) result = FN(mcopy_a2m, i4_rnu, 1x4) (copy);
  a = FN(mclear_acc, i4_rnu, accx4) ();
  TYPE(i4_rnu, accx4) zero = FN(mzero_acc, i4_rnu, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_4_8 (void)
{
  TYPE(i4_rnu, 1x8) m = FN(mzero_m, i4_rnu, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rnu, accx8) a = FN(mcopy_m2a, i4_rnu, accx8) (m);
  TYPE(i4_rnu, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu, 1x8) result = FN(mcopy_a2m, i4_rnu, 1x8) (copy);
  a = FN(mclear_acc, i4_rnu, accx8) ();
  TYPE(i4_rnu, accx8) zero = FN(mzero_acc, i4_rnu, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_4_16 (void)
{
  TYPE(i4_rnu, 1x16) m = FN(mzero_m, i4_rnu, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rnu, accx16) a = FN(mcopy_m2a, i4_rnu, accx16) (m);
  TYPE(i4_rnu, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu, 1x16) result = FN(mcopy_a2m, i4_rnu, 1x16) (copy);
  a = FN(mclear_acc, i4_rnu, accx16) ();
  TYPE(i4_rnu, accx16) zero = FN(mzero_acc, i4_rnu, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_5_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i4_rne, 1x4) d = FN(mconv_ew, i4_rne, 1x4) (s);
  d = FN(mabs_ew, i4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i4_rne, 1x4) copy = FN(mcopy_m2m, i4_rne, 1x4) (d);
  d = FN(mclear_m, i4_rne, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne, 1x8) group = FN(mconcat_m, i4_rne, 1x8) (copy, copy);
  TYPE(i4_rne, 1x4) half = FN(mextract, i4_rne, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_5_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i4_rne, 4x1) d = FN(mconv_ew, i4_rne, 4x1) (s);
  d = FN(mabs_ew, i4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i4_rne, 4x1) copy = FN(mcopy_m2m, i4_rne, 4x1) (d);
  d = FN(mclear_m, i4_rne, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne, 8x1) group = FN(mconcat_m, i4_rne, 8x1) (copy, copy);
  TYPE(i4_rne, 4x1) half = FN(mextract, i4_rne, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_5_4 (void)
{
  TYPE(i4_rne, 1x4) m = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rne, accx4) a = FN(mcopy_m2a, i4_rne, accx4) (m);
  TYPE(i4_rne, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne, 1x4) result = FN(mcopy_a2m, i4_rne, 1x4) (copy);
  a = FN(mclear_acc, i4_rne, accx4) ();
  TYPE(i4_rne, accx4) zero = FN(mzero_acc, i4_rne, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_5_8 (void)
{
  TYPE(i4_rne, 1x8) m = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rne, accx8) a = FN(mcopy_m2a, i4_rne, accx8) (m);
  TYPE(i4_rne, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne, 1x8) result = FN(mcopy_a2m, i4_rne, 1x8) (copy);
  a = FN(mclear_acc, i4_rne, accx8) ();
  TYPE(i4_rne, accx8) zero = FN(mzero_acc, i4_rne, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_5_16 (void)
{
  TYPE(i4_rne, 1x16) m = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rne, accx16) a = FN(mcopy_m2a, i4_rne, accx16) (m);
  TYPE(i4_rne, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne, 1x16) result = FN(mcopy_a2m, i4_rne, 1x16) (copy);
  a = FN(mclear_acc, i4_rne, accx16) ();
  TYPE(i4_rne, accx16) zero = FN(mzero_acc, i4_rne, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_6_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 1x4) d = FN(mconv_ew, i4_rdn, 1x4) (s);
  d = FN(mabs_ew, i4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i4_rdn, 1x4) copy = FN(mcopy_m2m, i4_rdn, 1x4) (d);
  d = FN(mclear_m, i4_rdn, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn, 1x8) group = FN(mconcat_m, i4_rdn, 1x8) (copy, copy);
  TYPE(i4_rdn, 1x4) half = FN(mextract, i4_rdn, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_6_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 4x1) d = FN(mconv_ew, i4_rdn, 4x1) (s);
  d = FN(mabs_ew, i4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i4_rdn, 4x1) copy = FN(mcopy_m2m, i4_rdn, 4x1) (d);
  d = FN(mclear_m, i4_rdn, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn, 8x1) group = FN(mconcat_m, i4_rdn, 8x1) (copy, copy);
  TYPE(i4_rdn, 4x1) half = FN(mextract, i4_rdn, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_6_4 (void)
{
  TYPE(i4_rdn, 1x4) m = FN(mzero_m, i4_rdn, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rdn, accx4) a = FN(mcopy_m2a, i4_rdn, accx4) (m);
  TYPE(i4_rdn, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn, 1x4) result = FN(mcopy_a2m, i4_rdn, 1x4) (copy);
  a = FN(mclear_acc, i4_rdn, accx4) ();
  TYPE(i4_rdn, accx4) zero = FN(mzero_acc, i4_rdn, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_6_8 (void)
{
  TYPE(i4_rdn, 1x8) m = FN(mzero_m, i4_rdn, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rdn, accx8) a = FN(mcopy_m2a, i4_rdn, accx8) (m);
  TYPE(i4_rdn, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn, 1x8) result = FN(mcopy_a2m, i4_rdn, 1x8) (copy);
  a = FN(mclear_acc, i4_rdn, accx8) ();
  TYPE(i4_rdn, accx8) zero = FN(mzero_acc, i4_rdn, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_6_16 (void)
{
  TYPE(i4_rdn, 1x16) m = FN(mzero_m, i4_rdn, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rdn, accx16) a = FN(mcopy_m2a, i4_rdn, accx16) (m);
  TYPE(i4_rdn, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn, 1x16) result = FN(mcopy_a2m, i4_rdn, 1x16) (copy);
  a = FN(mclear_acc, i4_rdn, accx16) ();
  TYPE(i4_rdn, accx16) zero = FN(mzero_acc, i4_rdn, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_7_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i4_rod, 1x4) d = FN(mconv_ew, i4_rod, 1x4) (s);
  d = FN(mabs_ew, i4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i4_rod, 1x4) copy = FN(mcopy_m2m, i4_rod, 1x4) (d);
  d = FN(mclear_m, i4_rod, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod, 1x8) group = FN(mconcat_m, i4_rod, 1x8) (copy, copy);
  TYPE(i4_rod, 1x4) half = FN(mextract, i4_rod, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_7_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i4_rod, 4x1) d = FN(mconv_ew, i4_rod, 4x1) (s);
  d = FN(mabs_ew, i4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i4_rod, 4x1) copy = FN(mcopy_m2m, i4_rod, 4x1) (d);
  d = FN(mclear_m, i4_rod, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod, 8x1) group = FN(mconcat_m, i4_rod, 8x1) (copy, copy);
  TYPE(i4_rod, 4x1) half = FN(mextract, i4_rod, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_7_4 (void)
{
  TYPE(i4_rod, 1x4) m = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rod, accx4) a = FN(mcopy_m2a, i4_rod, accx4) (m);
  TYPE(i4_rod, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod, 1x4) result = FN(mcopy_a2m, i4_rod, 1x4) (copy);
  a = FN(mclear_acc, i4_rod, accx4) ();
  TYPE(i4_rod, accx4) zero = FN(mzero_acc, i4_rod, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_7_8 (void)
{
  TYPE(i4_rod, 1x8) m = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rod, accx8) a = FN(mcopy_m2a, i4_rod, accx8) (m);
  TYPE(i4_rod, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod, 1x8) result = FN(mcopy_a2m, i4_rod, 1x8) (copy);
  a = FN(mclear_acc, i4_rod, accx8) ();
  TYPE(i4_rod, accx8) zero = FN(mzero_acc, i4_rod, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_7_16 (void)
{
  TYPE(i4_rod, 1x16) m = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rod, accx16) a = FN(mcopy_m2a, i4_rod, accx16) (m);
  TYPE(i4_rod, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod, 1x16) result = FN(mcopy_a2m, i4_rod, 1x16) (copy);
  a = FN(mclear_acc, i4_rod, accx16) ();
  TYPE(i4_rod, accx16) zero = FN(mzero_acc, i4_rod, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_8_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 1x4) d = FN(mconv_ew, u4_rnu_sat, 1x4) (s);
  d = FN(mabs_ew, u4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u4_rnu_sat, 1x4) copy = FN(mcopy_m2m, u4_rnu_sat, 1x4) (d);
  d = FN(mclear_m, u4_rnu_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu_sat, 1x8) group = FN(mconcat_m, u4_rnu_sat, 1x8) (copy, copy);
  TYPE(u4_rnu_sat, 1x4) half = FN(mextract, u4_rnu_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_8_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 4x1) d = FN(mconv_ew, u4_rnu_sat, 4x1) (s);
  d = FN(mabs_ew, u4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u4_rnu_sat, 4x1) copy = FN(mcopy_m2m, u4_rnu_sat, 4x1) (d);
  d = FN(mclear_m, u4_rnu_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu_sat, 8x1) group = FN(mconcat_m, u4_rnu_sat, 8x1) (copy, copy);
  TYPE(u4_rnu_sat, 4x1) half = FN(mextract, u4_rnu_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_8_4 (void)
{
  TYPE(u4_rnu_sat, 1x4) m = FN(mzero_m, u4_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rnu_sat, accx4) a = FN(mcopy_m2a, u4_rnu_sat, accx4) (m);
  TYPE(u4_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu_sat, 1x4) result = FN(mcopy_a2m, u4_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u4_rnu_sat, accx4) ();
  TYPE(u4_rnu_sat, accx4) zero = FN(mzero_acc, u4_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_8_8 (void)
{
  TYPE(u4_rnu_sat, 1x8) m = FN(mzero_m, u4_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rnu_sat, accx8) a = FN(mcopy_m2a, u4_rnu_sat, accx8) (m);
  TYPE(u4_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu_sat, 1x8) result = FN(mcopy_a2m, u4_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rnu_sat, accx8) ();
  TYPE(u4_rnu_sat, accx8) zero = FN(mzero_acc, u4_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_8_16 (void)
{
  TYPE(u4_rnu_sat, 1x16) m = FN(mzero_m, u4_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rnu_sat, accx16) a = FN(mcopy_m2a, u4_rnu_sat, accx16) (m);
  TYPE(u4_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu_sat, 1x16) result = FN(mcopy_a2m, u4_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rnu_sat, accx16) ();
  TYPE(u4_rnu_sat, accx16) zero = FN(mzero_acc, u4_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_9_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 1x4) d = FN(mconv_ew, u4_rne_sat, 1x4) (s);
  d = FN(mabs_ew, u4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u4_rne_sat, 1x4) copy = FN(mcopy_m2m, u4_rne_sat, 1x4) (d);
  d = FN(mclear_m, u4_rne_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne_sat, 1x8) group = FN(mconcat_m, u4_rne_sat, 1x8) (copy, copy);
  TYPE(u4_rne_sat, 1x4) half = FN(mextract, u4_rne_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_9_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 4x1) d = FN(mconv_ew, u4_rne_sat, 4x1) (s);
  d = FN(mabs_ew, u4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u4_rne_sat, 4x1) copy = FN(mcopy_m2m, u4_rne_sat, 4x1) (d);
  d = FN(mclear_m, u4_rne_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne_sat, 8x1) group = FN(mconcat_m, u4_rne_sat, 8x1) (copy, copy);
  TYPE(u4_rne_sat, 4x1) half = FN(mextract, u4_rne_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_9_4 (void)
{
  TYPE(u4_rne_sat, 1x4) m = FN(mzero_m, u4_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rne_sat, accx4) a = FN(mcopy_m2a, u4_rne_sat, accx4) (m);
  TYPE(u4_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne_sat, 1x4) result = FN(mcopy_a2m, u4_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u4_rne_sat, accx4) ();
  TYPE(u4_rne_sat, accx4) zero = FN(mzero_acc, u4_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_9_8 (void)
{
  TYPE(u4_rne_sat, 1x8) m = FN(mzero_m, u4_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rne_sat, accx8) a = FN(mcopy_m2a, u4_rne_sat, accx8) (m);
  TYPE(u4_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne_sat, 1x8) result = FN(mcopy_a2m, u4_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rne_sat, accx8) ();
  TYPE(u4_rne_sat, accx8) zero = FN(mzero_acc, u4_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_9_16 (void)
{
  TYPE(u4_rne_sat, 1x16) m = FN(mzero_m, u4_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rne_sat, accx16) a = FN(mcopy_m2a, u4_rne_sat, accx16) (m);
  TYPE(u4_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne_sat, 1x16) result = FN(mcopy_a2m, u4_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rne_sat, accx16) ();
  TYPE(u4_rne_sat, accx16) zero = FN(mzero_acc, u4_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_10_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 1x4) d = FN(mconv_ew, u4_rdn_sat, 1x4) (s);
  d = FN(mabs_ew, u4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u4_rdn_sat, 1x4) copy = FN(mcopy_m2m, u4_rdn_sat, 1x4) (d);
  d = FN(mclear_m, u4_rdn_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn_sat, 1x8) group = FN(mconcat_m, u4_rdn_sat, 1x8) (copy, copy);
  TYPE(u4_rdn_sat, 1x4) half = FN(mextract, u4_rdn_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_10_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 4x1) d = FN(mconv_ew, u4_rdn_sat, 4x1) (s);
  d = FN(mabs_ew, u4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u4_rdn_sat, 4x1) copy = FN(mcopy_m2m, u4_rdn_sat, 4x1) (d);
  d = FN(mclear_m, u4_rdn_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn_sat, 8x1) group = FN(mconcat_m, u4_rdn_sat, 8x1) (copy, copy);
  TYPE(u4_rdn_sat, 4x1) half = FN(mextract, u4_rdn_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_10_4 (void)
{
  TYPE(u4_rdn_sat, 1x4) m = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rdn_sat, accx4) a = FN(mcopy_m2a, u4_rdn_sat, accx4) (m);
  TYPE(u4_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn_sat, 1x4) result = FN(mcopy_a2m, u4_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u4_rdn_sat, accx4) ();
  TYPE(u4_rdn_sat, accx4) zero = FN(mzero_acc, u4_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_10_8 (void)
{
  TYPE(u4_rdn_sat, 1x8) m = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rdn_sat, accx8) a = FN(mcopy_m2a, u4_rdn_sat, accx8) (m);
  TYPE(u4_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn_sat, 1x8) result = FN(mcopy_a2m, u4_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rdn_sat, accx8) ();
  TYPE(u4_rdn_sat, accx8) zero = FN(mzero_acc, u4_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_10_16 (void)
{
  TYPE(u4_rdn_sat, 1x16) m = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rdn_sat, accx16) a = FN(mcopy_m2a, u4_rdn_sat, accx16) (m);
  TYPE(u4_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn_sat, 1x16) result = FN(mcopy_a2m, u4_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rdn_sat, accx16) ();
  TYPE(u4_rdn_sat, accx16) zero = FN(mzero_acc, u4_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_11_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 1x4) d = FN(mconv_ew, u4_rod_sat, 1x4) (s);
  d = FN(mabs_ew, u4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u4_rod_sat, 1x4) copy = FN(mcopy_m2m, u4_rod_sat, 1x4) (d);
  d = FN(mclear_m, u4_rod_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod_sat, 1x8) group = FN(mconcat_m, u4_rod_sat, 1x8) (copy, copy);
  TYPE(u4_rod_sat, 1x4) half = FN(mextract, u4_rod_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_11_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 4x1) d = FN(mconv_ew, u4_rod_sat, 4x1) (s);
  d = FN(mabs_ew, u4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u4_rod_sat, 4x1) copy = FN(mcopy_m2m, u4_rod_sat, 4x1) (d);
  d = FN(mclear_m, u4_rod_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod_sat, 8x1) group = FN(mconcat_m, u4_rod_sat, 8x1) (copy, copy);
  TYPE(u4_rod_sat, 4x1) half = FN(mextract, u4_rod_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_11_4 (void)
{
  TYPE(u4_rod_sat, 1x4) m = FN(mzero_m, u4_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u4_rod_sat, accx4) a = FN(mcopy_m2a, u4_rod_sat, accx4) (m);
  TYPE(u4_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod_sat, 1x4) result = FN(mcopy_a2m, u4_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u4_rod_sat, accx4) ();
  TYPE(u4_rod_sat, accx4) zero = FN(mzero_acc, u4_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_11_8 (void)
{
  TYPE(u4_rod_sat, 1x8) m = FN(mzero_m, u4_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rod_sat, accx8) a = FN(mcopy_m2a, u4_rod_sat, accx8) (m);
  TYPE(u4_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod_sat, 1x8) result = FN(mcopy_a2m, u4_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rod_sat, accx8) ();
  TYPE(u4_rod_sat, accx8) zero = FN(mzero_acc, u4_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_11_16 (void)
{
  TYPE(u4_rod_sat, 1x16) m = FN(mzero_m, u4_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rod_sat, accx16) a = FN(mcopy_m2a, u4_rod_sat, accx16) (m);
  TYPE(u4_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod_sat, 1x16) result = FN(mcopy_a2m, u4_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rod_sat, accx16) ();
  TYPE(u4_rod_sat, accx16) zero = FN(mzero_acc, u4_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_12_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 1x4) d = FN(mconv_ew, i4_rnu_sat, 1x4) (s);
  d = FN(mabs_ew, i4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i4_rnu_sat, 1x4) copy = FN(mcopy_m2m, i4_rnu_sat, 1x4) (d);
  d = FN(mclear_m, i4_rnu_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu_sat, 1x8) group = FN(mconcat_m, i4_rnu_sat, 1x8) (copy, copy);
  TYPE(i4_rnu_sat, 1x4) half = FN(mextract, i4_rnu_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_12_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 4x1) d = FN(mconv_ew, i4_rnu_sat, 4x1) (s);
  d = FN(mabs_ew, i4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i4_rnu_sat, 4x1) copy = FN(mcopy_m2m, i4_rnu_sat, 4x1) (d);
  d = FN(mclear_m, i4_rnu_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu_sat, 8x1) group = FN(mconcat_m, i4_rnu_sat, 8x1) (copy, copy);
  TYPE(i4_rnu_sat, 4x1) half = FN(mextract, i4_rnu_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_12_4 (void)
{
  TYPE(i4_rnu_sat, 1x4) m = FN(mzero_m, i4_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rnu_sat, accx4) a = FN(mcopy_m2a, i4_rnu_sat, accx4) (m);
  TYPE(i4_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu_sat, 1x4) result = FN(mcopy_a2m, i4_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i4_rnu_sat, accx4) ();
  TYPE(i4_rnu_sat, accx4) zero = FN(mzero_acc, i4_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_12_8 (void)
{
  TYPE(i4_rnu_sat, 1x8) m = FN(mzero_m, i4_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rnu_sat, accx8) a = FN(mcopy_m2a, i4_rnu_sat, accx8) (m);
  TYPE(i4_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu_sat, 1x8) result = FN(mcopy_a2m, i4_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rnu_sat, accx8) ();
  TYPE(i4_rnu_sat, accx8) zero = FN(mzero_acc, i4_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_12_16 (void)
{
  TYPE(i4_rnu_sat, 1x16) m = FN(mzero_m, i4_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rnu_sat, accx16) a = FN(mcopy_m2a, i4_rnu_sat, accx16) (m);
  TYPE(i4_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu_sat, 1x16) result = FN(mcopy_a2m, i4_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rnu_sat, accx16) ();
  TYPE(i4_rnu_sat, accx16) zero = FN(mzero_acc, i4_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_13_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 1x4) d = FN(mconv_ew, i4_rne_sat, 1x4) (s);
  d = FN(mabs_ew, i4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i4_rne_sat, 1x4) copy = FN(mcopy_m2m, i4_rne_sat, 1x4) (d);
  d = FN(mclear_m, i4_rne_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne_sat, 1x8) group = FN(mconcat_m, i4_rne_sat, 1x8) (copy, copy);
  TYPE(i4_rne_sat, 1x4) half = FN(mextract, i4_rne_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_13_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 4x1) d = FN(mconv_ew, i4_rne_sat, 4x1) (s);
  d = FN(mabs_ew, i4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i4_rne_sat, 4x1) copy = FN(mcopy_m2m, i4_rne_sat, 4x1) (d);
  d = FN(mclear_m, i4_rne_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne_sat, 8x1) group = FN(mconcat_m, i4_rne_sat, 8x1) (copy, copy);
  TYPE(i4_rne_sat, 4x1) half = FN(mextract, i4_rne_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_13_4 (void)
{
  TYPE(i4_rne_sat, 1x4) m = FN(mzero_m, i4_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rne_sat, accx4) a = FN(mcopy_m2a, i4_rne_sat, accx4) (m);
  TYPE(i4_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne_sat, 1x4) result = FN(mcopy_a2m, i4_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i4_rne_sat, accx4) ();
  TYPE(i4_rne_sat, accx4) zero = FN(mzero_acc, i4_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_13_8 (void)
{
  TYPE(i4_rne_sat, 1x8) m = FN(mzero_m, i4_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rne_sat, accx8) a = FN(mcopy_m2a, i4_rne_sat, accx8) (m);
  TYPE(i4_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne_sat, 1x8) result = FN(mcopy_a2m, i4_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rne_sat, accx8) ();
  TYPE(i4_rne_sat, accx8) zero = FN(mzero_acc, i4_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_13_16 (void)
{
  TYPE(i4_rne_sat, 1x16) m = FN(mzero_m, i4_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rne_sat, accx16) a = FN(mcopy_m2a, i4_rne_sat, accx16) (m);
  TYPE(i4_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne_sat, 1x16) result = FN(mcopy_a2m, i4_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rne_sat, accx16) ();
  TYPE(i4_rne_sat, accx16) zero = FN(mzero_acc, i4_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_14_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 1x4) d = FN(mconv_ew, i4_rdn_sat, 1x4) (s);
  d = FN(mabs_ew, i4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i4_rdn_sat, 1x4) copy = FN(mcopy_m2m, i4_rdn_sat, 1x4) (d);
  d = FN(mclear_m, i4_rdn_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn_sat, 1x8) group = FN(mconcat_m, i4_rdn_sat, 1x8) (copy, copy);
  TYPE(i4_rdn_sat, 1x4) half = FN(mextract, i4_rdn_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_14_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 4x1) d = FN(mconv_ew, i4_rdn_sat, 4x1) (s);
  d = FN(mabs_ew, i4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i4_rdn_sat, 4x1) copy = FN(mcopy_m2m, i4_rdn_sat, 4x1) (d);
  d = FN(mclear_m, i4_rdn_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn_sat, 8x1) group = FN(mconcat_m, i4_rdn_sat, 8x1) (copy, copy);
  TYPE(i4_rdn_sat, 4x1) half = FN(mextract, i4_rdn_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_14_4 (void)
{
  TYPE(i4_rdn_sat, 1x4) m = FN(mzero_m, i4_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rdn_sat, accx4) a = FN(mcopy_m2a, i4_rdn_sat, accx4) (m);
  TYPE(i4_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn_sat, 1x4) result = FN(mcopy_a2m, i4_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i4_rdn_sat, accx4) ();
  TYPE(i4_rdn_sat, accx4) zero = FN(mzero_acc, i4_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_14_8 (void)
{
  TYPE(i4_rdn_sat, 1x8) m = FN(mzero_m, i4_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rdn_sat, accx8) a = FN(mcopy_m2a, i4_rdn_sat, accx8) (m);
  TYPE(i4_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn_sat, 1x8) result = FN(mcopy_a2m, i4_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rdn_sat, accx8) ();
  TYPE(i4_rdn_sat, accx8) zero = FN(mzero_acc, i4_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_14_16 (void)
{
  TYPE(i4_rdn_sat, 1x16) m = FN(mzero_m, i4_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rdn_sat, accx16) a = FN(mcopy_m2a, i4_rdn_sat, accx16) (m);
  TYPE(i4_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn_sat, 1x16) result = FN(mcopy_a2m, i4_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rdn_sat, accx16) ();
  TYPE(i4_rdn_sat, accx16) zero = FN(mzero_acc, i4_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_15_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 1x4) d = FN(mconv_ew, i4_rod_sat, 1x4) (s);
  d = FN(mabs_ew, i4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i4_rod_sat, 1x4) copy = FN(mcopy_m2m, i4_rod_sat, 1x4) (d);
  d = FN(mclear_m, i4_rod_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod_sat, 1x8) group = FN(mconcat_m, i4_rod_sat, 1x8) (copy, copy);
  TYPE(i4_rod_sat, 1x4) half = FN(mextract, i4_rod_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_15_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 4x1) d = FN(mconv_ew, i4_rod_sat, 4x1) (s);
  d = FN(mabs_ew, i4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i4_rod_sat, 4x1) copy = FN(mcopy_m2m, i4_rod_sat, 4x1) (d);
  d = FN(mclear_m, i4_rod_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod_sat, 8x1) group = FN(mconcat_m, i4_rod_sat, 8x1) (copy, copy);
  TYPE(i4_rod_sat, 4x1) half = FN(mextract, i4_rod_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_15_4 (void)
{
  TYPE(i4_rod_sat, 1x4) m = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i4_rod_sat, accx4) a = FN(mcopy_m2a, i4_rod_sat, accx4) (m);
  TYPE(i4_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod_sat, 1x4) result = FN(mcopy_a2m, i4_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i4_rod_sat, accx4) ();
  TYPE(i4_rod_sat, accx4) zero = FN(mzero_acc, i4_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_15_8 (void)
{
  TYPE(i4_rod_sat, 1x8) m = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rod_sat, accx8) a = FN(mcopy_m2a, i4_rod_sat, accx8) (m);
  TYPE(i4_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod_sat, 1x8) result = FN(mcopy_a2m, i4_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rod_sat, accx8) ();
  TYPE(i4_rod_sat, accx8) zero = FN(mzero_acc, i4_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_15_16 (void)
{
  TYPE(i4_rod_sat, 1x16) m = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rod_sat, accx16) a = FN(mcopy_m2a, i4_rod_sat, accx16) (m);
  TYPE(i4_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod_sat, 1x16) result = FN(mcopy_a2m, i4_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rod_sat, accx16) ();
  TYPE(i4_rod_sat, accx16) zero = FN(mzero_acc, i4_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_16_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u8_rnu_sat, 1x2) d = FN(mconv_ew, u8_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, u8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u8_rnu_sat, 1x2) copy = FN(mcopy_m2m, u8_rnu_sat, 1x2) (d);
  d = FN(mclear_m, u8_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rnu_sat, 1x4) group = FN(mconcat_m, u8_rnu_sat, 1x4) (copy, copy);
  TYPE(u8_rnu_sat, 1x2) half = FN(mextract, u8_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_16_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u8_rnu_sat, 2x1) d = FN(mconv_ew, u8_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, u8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u8_rnu_sat, 2x1) copy = FN(mcopy_m2m, u8_rnu_sat, 2x1) (d);
  d = FN(mclear_m, u8_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rnu_sat, 4x1) group = FN(mconcat_m, u8_rnu_sat, 4x1) (copy, copy);
  TYPE(u8_rnu_sat, 2x1) half = FN(mextract, u8_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_16_2 (void)
{
  TYPE(u8_rnu_sat, 1x2) m = FN(mzero_m, u8_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx2) a = FN(mcopy_m2a, u8_rnu_sat, accx2) (m);
  TYPE(u8_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x2) result = FN(mcopy_a2m, u8_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx2) ();
  TYPE(u8_rnu_sat, accx2) zero = FN(mzero_acc, u8_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_16_4 (void)
{
  TYPE(u8_rnu_sat, 1x4) m = FN(mzero_m, u8_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx4) a = FN(mcopy_m2a, u8_rnu_sat, accx4) (m);
  TYPE(u8_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x4) result = FN(mcopy_a2m, u8_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx4) ();
  TYPE(u8_rnu_sat, accx4) zero = FN(mzero_acc, u8_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_16_8 (void)
{
  TYPE(u8_rnu_sat, 1x8) m = FN(mzero_m, u8_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx8) a = FN(mcopy_m2a, u8_rnu_sat, accx8) (m);
  TYPE(u8_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x8) result = FN(mcopy_a2m, u8_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx8) ();
  TYPE(u8_rnu_sat, accx8) zero = FN(mzero_acc, u8_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_17_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u8_rne_sat, 1x2) d = FN(mconv_ew, u8_rne_sat, 1x2) (s);
  d = FN(mabs_ew, u8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u8_rne_sat, 1x2) copy = FN(mcopy_m2m, u8_rne_sat, 1x2) (d);
  d = FN(mclear_m, u8_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rne_sat, 1x4) group = FN(mconcat_m, u8_rne_sat, 1x4) (copy, copy);
  TYPE(u8_rne_sat, 1x2) half = FN(mextract, u8_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_17_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u8_rne_sat, 2x1) d = FN(mconv_ew, u8_rne_sat, 2x1) (s);
  d = FN(mabs_ew, u8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u8_rne_sat, 2x1) copy = FN(mcopy_m2m, u8_rne_sat, 2x1) (d);
  d = FN(mclear_m, u8_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rne_sat, 4x1) group = FN(mconcat_m, u8_rne_sat, 4x1) (copy, copy);
  TYPE(u8_rne_sat, 2x1) half = FN(mextract, u8_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_17_2 (void)
{
  TYPE(u8_rne_sat, 1x2) m = FN(mzero_m, u8_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx2) a = FN(mcopy_m2a, u8_rne_sat, accx2) (m);
  TYPE(u8_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x2) result = FN(mcopy_a2m, u8_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx2) ();
  TYPE(u8_rne_sat, accx2) zero = FN(mzero_acc, u8_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_17_4 (void)
{
  TYPE(u8_rne_sat, 1x4) m = FN(mzero_m, u8_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx4) a = FN(mcopy_m2a, u8_rne_sat, accx4) (m);
  TYPE(u8_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x4) result = FN(mcopy_a2m, u8_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx4) ();
  TYPE(u8_rne_sat, accx4) zero = FN(mzero_acc, u8_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_17_8 (void)
{
  TYPE(u8_rne_sat, 1x8) m = FN(mzero_m, u8_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx8) a = FN(mcopy_m2a, u8_rne_sat, accx8) (m);
  TYPE(u8_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x8) result = FN(mcopy_a2m, u8_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx8) ();
  TYPE(u8_rne_sat, accx8) zero = FN(mzero_acc, u8_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_18_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u8_rdn_sat, 1x2) d = FN(mconv_ew, u8_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, u8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u8_rdn_sat, 1x2) copy = FN(mcopy_m2m, u8_rdn_sat, 1x2) (d);
  d = FN(mclear_m, u8_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rdn_sat, 1x4) group = FN(mconcat_m, u8_rdn_sat, 1x4) (copy, copy);
  TYPE(u8_rdn_sat, 1x2) half = FN(mextract, u8_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_18_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u8_rdn_sat, 2x1) d = FN(mconv_ew, u8_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, u8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u8_rdn_sat, 2x1) copy = FN(mcopy_m2m, u8_rdn_sat, 2x1) (d);
  d = FN(mclear_m, u8_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rdn_sat, 4x1) group = FN(mconcat_m, u8_rdn_sat, 4x1) (copy, copy);
  TYPE(u8_rdn_sat, 2x1) half = FN(mextract, u8_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_18_2 (void)
{
  TYPE(u8_rdn_sat, 1x2) m = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx2) a = FN(mcopy_m2a, u8_rdn_sat, accx2) (m);
  TYPE(u8_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x2) result = FN(mcopy_a2m, u8_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx2) ();
  TYPE(u8_rdn_sat, accx2) zero = FN(mzero_acc, u8_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_18_4 (void)
{
  TYPE(u8_rdn_sat, 1x4) m = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx4) a = FN(mcopy_m2a, u8_rdn_sat, accx4) (m);
  TYPE(u8_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x4) result = FN(mcopy_a2m, u8_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx4) ();
  TYPE(u8_rdn_sat, accx4) zero = FN(mzero_acc, u8_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_18_8 (void)
{
  TYPE(u8_rdn_sat, 1x8) m = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx8) a = FN(mcopy_m2a, u8_rdn_sat, accx8) (m);
  TYPE(u8_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x8) result = FN(mcopy_a2m, u8_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx8) ();
  TYPE(u8_rdn_sat, accx8) zero = FN(mzero_acc, u8_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_19_0 (void)
{
  TYPE(i8_rod, 1x2) s = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u8_rod_sat, 1x2) d = FN(mconv_ew, u8_rod_sat, 1x2) (s);
  d = FN(mabs_ew, u8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x2) back = FN(mconv_ew, i8_rod, 1x2) (d);
  TYPE(u8_rod_sat, 1x2) copy = FN(mcopy_m2m, u8_rod_sat, 1x2) (d);
  d = FN(mclear_m, u8_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rod_sat, 1x4) group = FN(mconcat_m, u8_rod_sat, 1x4) (copy, copy);
  TYPE(u8_rod_sat, 1x2) half = FN(mextract, u8_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_19_1 (void)
{
  TYPE(i8_rod, 2x1) s = FN(mzero_m, i8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u8_rod_sat, 2x1) d = FN(mconv_ew, u8_rod_sat, 2x1) (s);
  d = FN(mabs_ew, u8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 2x1) back = FN(mconv_ew, i8_rod, 2x1) (d);
  TYPE(u8_rod_sat, 2x1) copy = FN(mcopy_m2m, u8_rod_sat, 2x1) (d);
  d = FN(mclear_m, u8_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rod_sat, 4x1) group = FN(mconcat_m, u8_rod_sat, 4x1) (copy, copy);
  TYPE(u8_rod_sat, 2x1) half = FN(mextract, u8_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_19_2 (void)
{
  TYPE(u8_rod_sat, 1x2) m = FN(mzero_m, u8_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx2) a = FN(mcopy_m2a, u8_rod_sat, accx2) (m);
  TYPE(u8_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x2) result = FN(mcopy_a2m, u8_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx2) ();
  TYPE(u8_rod_sat, accx2) zero = FN(mzero_acc, u8_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_19_4 (void)
{
  TYPE(u8_rod_sat, 1x4) m = FN(mzero_m, u8_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx4) a = FN(mcopy_m2a, u8_rod_sat, accx4) (m);
  TYPE(u8_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x4) result = FN(mcopy_a2m, u8_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx4) ();
  TYPE(u8_rod_sat, accx4) zero = FN(mzero_acc, u8_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_19_8 (void)
{
  TYPE(u8_rod_sat, 1x8) m = FN(mzero_m, u8_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx8) a = FN(mcopy_m2a, u8_rod_sat, accx8) (m);
  TYPE(u8_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x8) result = FN(mcopy_a2m, u8_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx8) ();
  TYPE(u8_rod_sat, accx8) zero = FN(mzero_acc, u8_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_20_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i8_rnu_sat, 1x2) d = FN(mconv_ew, i8_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, i8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i8_rnu_sat, 1x2) copy = FN(mcopy_m2m, i8_rnu_sat, 1x2) (d);
  d = FN(mclear_m, i8_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rnu_sat, 1x4) group = FN(mconcat_m, i8_rnu_sat, 1x4) (copy, copy);
  TYPE(i8_rnu_sat, 1x2) half = FN(mextract, i8_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_20_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i8_rnu_sat, 2x1) d = FN(mconv_ew, i8_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, i8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i8_rnu_sat, 2x1) copy = FN(mcopy_m2m, i8_rnu_sat, 2x1) (d);
  d = FN(mclear_m, i8_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rnu_sat, 4x1) group = FN(mconcat_m, i8_rnu_sat, 4x1) (copy, copy);
  TYPE(i8_rnu_sat, 2x1) half = FN(mextract, i8_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_20_2 (void)
{
  TYPE(i8_rnu_sat, 1x2) m = FN(mzero_m, i8_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx2) a = FN(mcopy_m2a, i8_rnu_sat, accx2) (m);
  TYPE(i8_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x2) result = FN(mcopy_a2m, i8_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx2) ();
  TYPE(i8_rnu_sat, accx2) zero = FN(mzero_acc, i8_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_20_4 (void)
{
  TYPE(i8_rnu_sat, 1x4) m = FN(mzero_m, i8_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx4) a = FN(mcopy_m2a, i8_rnu_sat, accx4) (m);
  TYPE(i8_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x4) result = FN(mcopy_a2m, i8_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx4) ();
  TYPE(i8_rnu_sat, accx4) zero = FN(mzero_acc, i8_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_20_8 (void)
{
  TYPE(i8_rnu_sat, 1x8) m = FN(mzero_m, i8_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx8) a = FN(mcopy_m2a, i8_rnu_sat, accx8) (m);
  TYPE(i8_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x8) result = FN(mcopy_a2m, i8_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx8) ();
  TYPE(i8_rnu_sat, accx8) zero = FN(mzero_acc, i8_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_21_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i8_rne_sat, 1x2) d = FN(mconv_ew, i8_rne_sat, 1x2) (s);
  d = FN(mabs_ew, i8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i8_rne_sat, 1x2) copy = FN(mcopy_m2m, i8_rne_sat, 1x2) (d);
  d = FN(mclear_m, i8_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rne_sat, 1x4) group = FN(mconcat_m, i8_rne_sat, 1x4) (copy, copy);
  TYPE(i8_rne_sat, 1x2) half = FN(mextract, i8_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_21_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i8_rne_sat, 2x1) d = FN(mconv_ew, i8_rne_sat, 2x1) (s);
  d = FN(mabs_ew, i8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i8_rne_sat, 2x1) copy = FN(mcopy_m2m, i8_rne_sat, 2x1) (d);
  d = FN(mclear_m, i8_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rne_sat, 4x1) group = FN(mconcat_m, i8_rne_sat, 4x1) (copy, copy);
  TYPE(i8_rne_sat, 2x1) half = FN(mextract, i8_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_21_2 (void)
{
  TYPE(i8_rne_sat, 1x2) m = FN(mzero_m, i8_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx2) a = FN(mcopy_m2a, i8_rne_sat, accx2) (m);
  TYPE(i8_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x2) result = FN(mcopy_a2m, i8_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx2) ();
  TYPE(i8_rne_sat, accx2) zero = FN(mzero_acc, i8_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_21_4 (void)
{
  TYPE(i8_rne_sat, 1x4) m = FN(mzero_m, i8_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx4) a = FN(mcopy_m2a, i8_rne_sat, accx4) (m);
  TYPE(i8_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x4) result = FN(mcopy_a2m, i8_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx4) ();
  TYPE(i8_rne_sat, accx4) zero = FN(mzero_acc, i8_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_21_8 (void)
{
  TYPE(i8_rne_sat, 1x8) m = FN(mzero_m, i8_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx8) a = FN(mcopy_m2a, i8_rne_sat, accx8) (m);
  TYPE(i8_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x8) result = FN(mcopy_a2m, i8_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx8) ();
  TYPE(i8_rne_sat, accx8) zero = FN(mzero_acc, i8_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_22_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i8_rdn_sat, 1x2) d = FN(mconv_ew, i8_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, i8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i8_rdn_sat, 1x2) copy = FN(mcopy_m2m, i8_rdn_sat, 1x2) (d);
  d = FN(mclear_m, i8_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rdn_sat, 1x4) group = FN(mconcat_m, i8_rdn_sat, 1x4) (copy, copy);
  TYPE(i8_rdn_sat, 1x2) half = FN(mextract, i8_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_22_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i8_rdn_sat, 2x1) d = FN(mconv_ew, i8_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, i8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i8_rdn_sat, 2x1) copy = FN(mcopy_m2m, i8_rdn_sat, 2x1) (d);
  d = FN(mclear_m, i8_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rdn_sat, 4x1) group = FN(mconcat_m, i8_rdn_sat, 4x1) (copy, copy);
  TYPE(i8_rdn_sat, 2x1) half = FN(mextract, i8_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_22_2 (void)
{
  TYPE(i8_rdn_sat, 1x2) m = FN(mzero_m, i8_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx2) a = FN(mcopy_m2a, i8_rdn_sat, accx2) (m);
  TYPE(i8_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x2) result = FN(mcopy_a2m, i8_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx2) ();
  TYPE(i8_rdn_sat, accx2) zero = FN(mzero_acc, i8_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_22_4 (void)
{
  TYPE(i8_rdn_sat, 1x4) m = FN(mzero_m, i8_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx4) a = FN(mcopy_m2a, i8_rdn_sat, accx4) (m);
  TYPE(i8_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x4) result = FN(mcopy_a2m, i8_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx4) ();
  TYPE(i8_rdn_sat, accx4) zero = FN(mzero_acc, i8_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_22_8 (void)
{
  TYPE(i8_rdn_sat, 1x8) m = FN(mzero_m, i8_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx8) a = FN(mcopy_m2a, i8_rdn_sat, accx8) (m);
  TYPE(i8_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x8) result = FN(mcopy_a2m, i8_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx8) ();
  TYPE(i8_rdn_sat, accx8) zero = FN(mzero_acc, i8_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_23_0 (void)
{
  TYPE(u8_rod, 1x2) s = FN(mzero_m, u8_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i8_rod_sat, 1x2) d = FN(mconv_ew, i8_rod_sat, 1x2) (s);
  d = FN(mabs_ew, i8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x2) back = FN(mconv_ew, u8_rod, 1x2) (d);
  TYPE(i8_rod_sat, 1x2) copy = FN(mcopy_m2m, i8_rod_sat, 1x2) (d);
  d = FN(mclear_m, i8_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rod_sat, 1x4) group = FN(mconcat_m, i8_rod_sat, 1x4) (copy, copy);
  TYPE(i8_rod_sat, 1x2) half = FN(mextract, i8_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_23_1 (void)
{
  TYPE(u8_rod, 2x1) s = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i8_rod_sat, 2x1) d = FN(mconv_ew, i8_rod_sat, 2x1) (s);
  d = FN(mabs_ew, i8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 2x1) back = FN(mconv_ew, u8_rod, 2x1) (d);
  TYPE(i8_rod_sat, 2x1) copy = FN(mcopy_m2m, i8_rod_sat, 2x1) (d);
  d = FN(mclear_m, i8_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rod_sat, 4x1) group = FN(mconcat_m, i8_rod_sat, 4x1) (copy, copy);
  TYPE(i8_rod_sat, 2x1) half = FN(mextract, i8_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_23_2 (void)
{
  TYPE(i8_rod_sat, 1x2) m = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx2) a = FN(mcopy_m2a, i8_rod_sat, accx2) (m);
  TYPE(i8_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x2) result = FN(mcopy_a2m, i8_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx2) ();
  TYPE(i8_rod_sat, accx2) zero = FN(mzero_acc, i8_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_23_4 (void)
{
  TYPE(i8_rod_sat, 1x4) m = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx4) a = FN(mcopy_m2a, i8_rod_sat, accx4) (m);
  TYPE(i8_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x4) result = FN(mcopy_a2m, i8_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx4) ();
  TYPE(i8_rod_sat, accx4) zero = FN(mzero_acc, i8_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_23_8 (void)
{
  TYPE(i8_rod_sat, 1x8) m = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx8) a = FN(mcopy_m2a, i8_rod_sat, accx8) (m);
  TYPE(i8_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x8) result = FN(mcopy_a2m, i8_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx8) ();
  TYPE(i8_rod_sat, accx8) zero = FN(mzero_acc, i8_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_24_0 (void)
{
  TYPE(i16_rod, 1x1) s = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u16_rnu_sat, 1x1) d = FN(mconv_ew, u16_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x1) back = FN(mconv_ew, i16_rod, 1x1) (d);
  TYPE(u16_rnu_sat, 1x1) copy = FN(mcopy_m2m, u16_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u16_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rnu_sat, 1x2) group = FN(mconcat_m, u16_rnu_sat, 1x2) (copy, copy);
  TYPE(u16_rnu_sat, 1x1) half = FN(mextract, u16_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_24_1 (void)
{
  TYPE(u16_rnu_sat, 1x1) m = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx1) a = FN(mcopy_m2a, u16_rnu_sat, accx1) (m);
  TYPE(u16_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x1) result = FN(mcopy_a2m, u16_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx1) ();
  TYPE(u16_rnu_sat, accx1) zero = FN(mzero_acc, u16_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_24_2 (void)
{
  TYPE(u16_rnu_sat, 1x2) m = FN(mzero_m, u16_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx2) a = FN(mcopy_m2a, u16_rnu_sat, accx2) (m);
  TYPE(u16_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x2) result = FN(mcopy_a2m, u16_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx2) ();
  TYPE(u16_rnu_sat, accx2) zero = FN(mzero_acc, u16_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_24_4 (void)
{
  TYPE(u16_rnu_sat, 1x4) m = FN(mzero_m, u16_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx4) a = FN(mcopy_m2a, u16_rnu_sat, accx4) (m);
  TYPE(u16_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x4) result = FN(mcopy_a2m, u16_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx4) ();
  TYPE(u16_rnu_sat, accx4) zero = FN(mzero_acc, u16_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_25_0 (void)
{
  TYPE(i16_rod, 1x1) s = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u16_rne_sat, 1x1) d = FN(mconv_ew, u16_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x1) back = FN(mconv_ew, i16_rod, 1x1) (d);
  TYPE(u16_rne_sat, 1x1) copy = FN(mcopy_m2m, u16_rne_sat, 1x1) (d);
  d = FN(mclear_m, u16_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rne_sat, 1x2) group = FN(mconcat_m, u16_rne_sat, 1x2) (copy, copy);
  TYPE(u16_rne_sat, 1x1) half = FN(mextract, u16_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_25_1 (void)
{
  TYPE(u16_rne_sat, 1x1) m = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx1) a = FN(mcopy_m2a, u16_rne_sat, accx1) (m);
  TYPE(u16_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x1) result = FN(mcopy_a2m, u16_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx1) ();
  TYPE(u16_rne_sat, accx1) zero = FN(mzero_acc, u16_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_25_2 (void)
{
  TYPE(u16_rne_sat, 1x2) m = FN(mzero_m, u16_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx2) a = FN(mcopy_m2a, u16_rne_sat, accx2) (m);
  TYPE(u16_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x2) result = FN(mcopy_a2m, u16_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx2) ();
  TYPE(u16_rne_sat, accx2) zero = FN(mzero_acc, u16_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_25_4 (void)
{
  TYPE(u16_rne_sat, 1x4) m = FN(mzero_m, u16_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx4) a = FN(mcopy_m2a, u16_rne_sat, accx4) (m);
  TYPE(u16_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x4) result = FN(mcopy_a2m, u16_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx4) ();
  TYPE(u16_rne_sat, accx4) zero = FN(mzero_acc, u16_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_26_0 (void)
{
  TYPE(i16_rod, 1x1) s = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u16_rdn_sat, 1x1) d = FN(mconv_ew, u16_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x1) back = FN(mconv_ew, i16_rod, 1x1) (d);
  TYPE(u16_rdn_sat, 1x1) copy = FN(mcopy_m2m, u16_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u16_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rdn_sat, 1x2) group = FN(mconcat_m, u16_rdn_sat, 1x2) (copy, copy);
  TYPE(u16_rdn_sat, 1x1) half = FN(mextract, u16_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_26_1 (void)
{
  TYPE(u16_rdn_sat, 1x1) m = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx1) a = FN(mcopy_m2a, u16_rdn_sat, accx1) (m);
  TYPE(u16_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x1) result = FN(mcopy_a2m, u16_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx1) ();
  TYPE(u16_rdn_sat, accx1) zero = FN(mzero_acc, u16_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_26_2 (void)
{
  TYPE(u16_rdn_sat, 1x2) m = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx2) a = FN(mcopy_m2a, u16_rdn_sat, accx2) (m);
  TYPE(u16_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x2) result = FN(mcopy_a2m, u16_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx2) ();
  TYPE(u16_rdn_sat, accx2) zero = FN(mzero_acc, u16_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_26_4 (void)
{
  TYPE(u16_rdn_sat, 1x4) m = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx4) a = FN(mcopy_m2a, u16_rdn_sat, accx4) (m);
  TYPE(u16_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x4) result = FN(mcopy_a2m, u16_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx4) ();
  TYPE(u16_rdn_sat, accx4) zero = FN(mzero_acc, u16_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_27_0 (void)
{
  TYPE(i16_rod, 1x1) s = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u16_rod_sat, 1x1) d = FN(mconv_ew, u16_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x1) back = FN(mconv_ew, i16_rod, 1x1) (d);
  TYPE(u16_rod_sat, 1x1) copy = FN(mcopy_m2m, u16_rod_sat, 1x1) (d);
  d = FN(mclear_m, u16_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rod_sat, 1x2) group = FN(mconcat_m, u16_rod_sat, 1x2) (copy, copy);
  TYPE(u16_rod_sat, 1x1) half = FN(mextract, u16_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_27_1 (void)
{
  TYPE(u16_rod_sat, 1x1) m = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx1) a = FN(mcopy_m2a, u16_rod_sat, accx1) (m);
  TYPE(u16_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x1) result = FN(mcopy_a2m, u16_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx1) ();
  TYPE(u16_rod_sat, accx1) zero = FN(mzero_acc, u16_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_27_2 (void)
{
  TYPE(u16_rod_sat, 1x2) m = FN(mzero_m, u16_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx2) a = FN(mcopy_m2a, u16_rod_sat, accx2) (m);
  TYPE(u16_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x2) result = FN(mcopy_a2m, u16_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx2) ();
  TYPE(u16_rod_sat, accx2) zero = FN(mzero_acc, u16_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_27_4 (void)
{
  TYPE(u16_rod_sat, 1x4) m = FN(mzero_m, u16_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx4) a = FN(mcopy_m2a, u16_rod_sat, accx4) (m);
  TYPE(u16_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x4) result = FN(mcopy_a2m, u16_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx4) ();
  TYPE(u16_rod_sat, accx4) zero = FN(mzero_acc, u16_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_28_0 (void)
{
  TYPE(u16_rod, 1x1) s = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i16_rnu_sat, 1x1) d = FN(mconv_ew, i16_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x1) back = FN(mconv_ew, u16_rod, 1x1) (d);
  TYPE(i16_rnu_sat, 1x1) copy = FN(mcopy_m2m, i16_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i16_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rnu_sat, 1x2) group = FN(mconcat_m, i16_rnu_sat, 1x2) (copy, copy);
  TYPE(i16_rnu_sat, 1x1) half = FN(mextract, i16_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_28_1 (void)
{
  TYPE(i16_rnu_sat, 1x1) m = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx1) a = FN(mcopy_m2a, i16_rnu_sat, accx1) (m);
  TYPE(i16_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x1) result = FN(mcopy_a2m, i16_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx1) ();
  TYPE(i16_rnu_sat, accx1) zero = FN(mzero_acc, i16_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_28_2 (void)
{
  TYPE(i16_rnu_sat, 1x2) m = FN(mzero_m, i16_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx2) a = FN(mcopy_m2a, i16_rnu_sat, accx2) (m);
  TYPE(i16_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x2) result = FN(mcopy_a2m, i16_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx2) ();
  TYPE(i16_rnu_sat, accx2) zero = FN(mzero_acc, i16_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_28_4 (void)
{
  TYPE(i16_rnu_sat, 1x4) m = FN(mzero_m, i16_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx4) a = FN(mcopy_m2a, i16_rnu_sat, accx4) (m);
  TYPE(i16_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x4) result = FN(mcopy_a2m, i16_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx4) ();
  TYPE(i16_rnu_sat, accx4) zero = FN(mzero_acc, i16_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_29_0 (void)
{
  TYPE(u16_rod, 1x1) s = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i16_rne_sat, 1x1) d = FN(mconv_ew, i16_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x1) back = FN(mconv_ew, u16_rod, 1x1) (d);
  TYPE(i16_rne_sat, 1x1) copy = FN(mcopy_m2m, i16_rne_sat, 1x1) (d);
  d = FN(mclear_m, i16_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rne_sat, 1x2) group = FN(mconcat_m, i16_rne_sat, 1x2) (copy, copy);
  TYPE(i16_rne_sat, 1x1) half = FN(mextract, i16_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_29_1 (void)
{
  TYPE(i16_rne_sat, 1x1) m = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx1) a = FN(mcopy_m2a, i16_rne_sat, accx1) (m);
  TYPE(i16_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x1) result = FN(mcopy_a2m, i16_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx1) ();
  TYPE(i16_rne_sat, accx1) zero = FN(mzero_acc, i16_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_29_2 (void)
{
  TYPE(i16_rne_sat, 1x2) m = FN(mzero_m, i16_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx2) a = FN(mcopy_m2a, i16_rne_sat, accx2) (m);
  TYPE(i16_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x2) result = FN(mcopy_a2m, i16_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx2) ();
  TYPE(i16_rne_sat, accx2) zero = FN(mzero_acc, i16_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_29_4 (void)
{
  TYPE(i16_rne_sat, 1x4) m = FN(mzero_m, i16_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx4) a = FN(mcopy_m2a, i16_rne_sat, accx4) (m);
  TYPE(i16_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x4) result = FN(mcopy_a2m, i16_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx4) ();
  TYPE(i16_rne_sat, accx4) zero = FN(mzero_acc, i16_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_30_0 (void)
{
  TYPE(u16_rod, 1x1) s = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i16_rdn_sat, 1x1) d = FN(mconv_ew, i16_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x1) back = FN(mconv_ew, u16_rod, 1x1) (d);
  TYPE(i16_rdn_sat, 1x1) copy = FN(mcopy_m2m, i16_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i16_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rdn_sat, 1x2) group = FN(mconcat_m, i16_rdn_sat, 1x2) (copy, copy);
  TYPE(i16_rdn_sat, 1x1) half = FN(mextract, i16_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_30_1 (void)
{
  TYPE(i16_rdn_sat, 1x1) m = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx1) a = FN(mcopy_m2a, i16_rdn_sat, accx1) (m);
  TYPE(i16_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x1) result = FN(mcopy_a2m, i16_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx1) ();
  TYPE(i16_rdn_sat, accx1) zero = FN(mzero_acc, i16_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_30_2 (void)
{
  TYPE(i16_rdn_sat, 1x2) m = FN(mzero_m, i16_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx2) a = FN(mcopy_m2a, i16_rdn_sat, accx2) (m);
  TYPE(i16_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x2) result = FN(mcopy_a2m, i16_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx2) ();
  TYPE(i16_rdn_sat, accx2) zero = FN(mzero_acc, i16_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_30_4 (void)
{
  TYPE(i16_rdn_sat, 1x4) m = FN(mzero_m, i16_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx4) a = FN(mcopy_m2a, i16_rdn_sat, accx4) (m);
  TYPE(i16_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x4) result = FN(mcopy_a2m, i16_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx4) ();
  TYPE(i16_rdn_sat, accx4) zero = FN(mzero_acc, i16_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_31_0 (void)
{
  TYPE(u16_rod, 1x1) s = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i16_rod_sat, 1x1) d = FN(mconv_ew, i16_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x1) back = FN(mconv_ew, u16_rod, 1x1) (d);
  TYPE(i16_rod_sat, 1x1) copy = FN(mcopy_m2m, i16_rod_sat, 1x1) (d);
  d = FN(mclear_m, i16_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rod_sat, 1x2) group = FN(mconcat_m, i16_rod_sat, 1x2) (copy, copy);
  TYPE(i16_rod_sat, 1x1) half = FN(mextract, i16_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_31_1 (void)
{
  TYPE(i16_rod_sat, 1x1) m = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx1) a = FN(mcopy_m2a, i16_rod_sat, accx1) (m);
  TYPE(i16_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x1) result = FN(mcopy_a2m, i16_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx1) ();
  TYPE(i16_rod_sat, accx1) zero = FN(mzero_acc, i16_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_31_2 (void)
{
  TYPE(i16_rod_sat, 1x2) m = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx2) a = FN(mcopy_m2a, i16_rod_sat, accx2) (m);
  TYPE(i16_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x2) result = FN(mcopy_a2m, i16_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx2) ();
  TYPE(i16_rod_sat, accx2) zero = FN(mzero_acc, i16_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_31_4 (void)
{
  TYPE(i16_rod_sat, 1x4) m = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx4) a = FN(mcopy_m2a, i16_rod_sat, accx4) (m);
  TYPE(i16_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x4) result = FN(mcopy_a2m, i16_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx4) ();
  TYPE(i16_rod_sat, accx4) zero = FN(mzero_acc, i16_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_32_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rnu_sat, 1x1) d = FN(mconv_ew, u32_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rnu_sat, 1x1) copy = FN(mcopy_m2m, u32_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u32_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rnu_sat, 1x2) group = FN(mconcat_m, u32_rnu_sat, 1x2) (copy, copy);
  TYPE(u32_rnu_sat, 1x1) half = FN(mextract, u32_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_32_1 (void)
{
  TYPE(u32_rnu_sat, 1x1) m = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx1) a = FN(mcopy_m2a, u32_rnu_sat, accx1) (m);
  TYPE(u32_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x1) result = FN(mcopy_a2m, u32_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx1) ();
  TYPE(u32_rnu_sat, accx1) zero = FN(mzero_acc, u32_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_32_2 (void)
{
  TYPE(u32_rnu_sat, 1x2) m = FN(mzero_m, u32_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx2) a = FN(mcopy_m2a, u32_rnu_sat, accx2) (m);
  TYPE(u32_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x2) result = FN(mcopy_a2m, u32_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx2) ();
  TYPE(u32_rnu_sat, accx2) zero = FN(mzero_acc, u32_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_33_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rne_sat, 1x1) d = FN(mconv_ew, u32_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rne_sat, 1x1) copy = FN(mcopy_m2m, u32_rne_sat, 1x1) (d);
  d = FN(mclear_m, u32_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rne_sat, 1x2) group = FN(mconcat_m, u32_rne_sat, 1x2) (copy, copy);
  TYPE(u32_rne_sat, 1x1) half = FN(mextract, u32_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_33_1 (void)
{
  TYPE(u32_rne_sat, 1x1) m = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx1) a = FN(mcopy_m2a, u32_rne_sat, accx1) (m);
  TYPE(u32_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x1) result = FN(mcopy_a2m, u32_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx1) ();
  TYPE(u32_rne_sat, accx1) zero = FN(mzero_acc, u32_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_33_2 (void)
{
  TYPE(u32_rne_sat, 1x2) m = FN(mzero_m, u32_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx2) a = FN(mcopy_m2a, u32_rne_sat, accx2) (m);
  TYPE(u32_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x2) result = FN(mcopy_a2m, u32_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx2) ();
  TYPE(u32_rne_sat, accx2) zero = FN(mzero_acc, u32_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_34_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rdn_sat, 1x1) d = FN(mconv_ew, u32_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rdn_sat, 1x1) copy = FN(mcopy_m2m, u32_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u32_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rdn_sat, 1x2) group = FN(mconcat_m, u32_rdn_sat, 1x2) (copy, copy);
  TYPE(u32_rdn_sat, 1x1) half = FN(mextract, u32_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_34_1 (void)
{
  TYPE(u32_rdn_sat, 1x1) m = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx1) a = FN(mcopy_m2a, u32_rdn_sat, accx1) (m);
  TYPE(u32_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x1) result = FN(mcopy_a2m, u32_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx1) ();
  TYPE(u32_rdn_sat, accx1) zero = FN(mzero_acc, u32_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_34_2 (void)
{
  TYPE(u32_rdn_sat, 1x2) m = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx2) a = FN(mcopy_m2a, u32_rdn_sat, accx2) (m);
  TYPE(u32_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x2) result = FN(mcopy_a2m, u32_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx2) ();
  TYPE(u32_rdn_sat, accx2) zero = FN(mzero_acc, u32_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_35_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rod_sat, 1x1) d = FN(mconv_ew, u32_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rod_sat, 1x1) copy = FN(mcopy_m2m, u32_rod_sat, 1x1) (d);
  d = FN(mclear_m, u32_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rod_sat, 1x2) group = FN(mconcat_m, u32_rod_sat, 1x2) (copy, copy);
  TYPE(u32_rod_sat, 1x1) half = FN(mextract, u32_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_35_1 (void)
{
  TYPE(u32_rod_sat, 1x1) m = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx1) a = FN(mcopy_m2a, u32_rod_sat, accx1) (m);
  TYPE(u32_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x1) result = FN(mcopy_a2m, u32_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx1) ();
  TYPE(u32_rod_sat, accx1) zero = FN(mzero_acc, u32_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_35_2 (void)
{
  TYPE(u32_rod_sat, 1x2) m = FN(mzero_m, u32_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx2) a = FN(mcopy_m2a, u32_rod_sat, accx2) (m);
  TYPE(u32_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x2) result = FN(mcopy_a2m, u32_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx2) ();
  TYPE(u32_rod_sat, accx2) zero = FN(mzero_acc, u32_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_36_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rnu_sat, 1x1) d = FN(mconv_ew, i32_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rnu_sat, 1x1) copy = FN(mcopy_m2m, i32_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i32_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rnu_sat, 1x2) group = FN(mconcat_m, i32_rnu_sat, 1x2) (copy, copy);
  TYPE(i32_rnu_sat, 1x1) half = FN(mextract, i32_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_36_1 (void)
{
  TYPE(i32_rnu_sat, 1x1) m = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx1) a = FN(mcopy_m2a, i32_rnu_sat, accx1) (m);
  TYPE(i32_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x1) result = FN(mcopy_a2m, i32_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx1) ();
  TYPE(i32_rnu_sat, accx1) zero = FN(mzero_acc, i32_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_36_2 (void)
{
  TYPE(i32_rnu_sat, 1x2) m = FN(mzero_m, i32_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx2) a = FN(mcopy_m2a, i32_rnu_sat, accx2) (m);
  TYPE(i32_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x2) result = FN(mcopy_a2m, i32_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx2) ();
  TYPE(i32_rnu_sat, accx2) zero = FN(mzero_acc, i32_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_37_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rne_sat, 1x1) d = FN(mconv_ew, i32_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rne_sat, 1x1) copy = FN(mcopy_m2m, i32_rne_sat, 1x1) (d);
  d = FN(mclear_m, i32_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rne_sat, 1x2) group = FN(mconcat_m, i32_rne_sat, 1x2) (copy, copy);
  TYPE(i32_rne_sat, 1x1) half = FN(mextract, i32_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_37_1 (void)
{
  TYPE(i32_rne_sat, 1x1) m = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx1) a = FN(mcopy_m2a, i32_rne_sat, accx1) (m);
  TYPE(i32_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x1) result = FN(mcopy_a2m, i32_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx1) ();
  TYPE(i32_rne_sat, accx1) zero = FN(mzero_acc, i32_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_37_2 (void)
{
  TYPE(i32_rne_sat, 1x2) m = FN(mzero_m, i32_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx2) a = FN(mcopy_m2a, i32_rne_sat, accx2) (m);
  TYPE(i32_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x2) result = FN(mcopy_a2m, i32_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx2) ();
  TYPE(i32_rne_sat, accx2) zero = FN(mzero_acc, i32_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_38_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rdn_sat, 1x1) d = FN(mconv_ew, i32_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rdn_sat, 1x1) copy = FN(mcopy_m2m, i32_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i32_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rdn_sat, 1x2) group = FN(mconcat_m, i32_rdn_sat, 1x2) (copy, copy);
  TYPE(i32_rdn_sat, 1x1) half = FN(mextract, i32_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_38_1 (void)
{
  TYPE(i32_rdn_sat, 1x1) m = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx1) a = FN(mcopy_m2a, i32_rdn_sat, accx1) (m);
  TYPE(i32_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x1) result = FN(mcopy_a2m, i32_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx1) ();
  TYPE(i32_rdn_sat, accx1) zero = FN(mzero_acc, i32_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_38_2 (void)
{
  TYPE(i32_rdn_sat, 1x2) m = FN(mzero_m, i32_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx2) a = FN(mcopy_m2a, i32_rdn_sat, accx2) (m);
  TYPE(i32_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x2) result = FN(mcopy_a2m, i32_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx2) ();
  TYPE(i32_rdn_sat, accx2) zero = FN(mzero_acc, i32_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_39_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rod_sat, 1x1) d = FN(mconv_ew, i32_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rod_sat, 1x1) copy = FN(mcopy_m2m, i32_rod_sat, 1x1) (d);
  d = FN(mclear_m, i32_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rod_sat, 1x2) group = FN(mconcat_m, i32_rod_sat, 1x2) (copy, copy);
  TYPE(i32_rod_sat, 1x1) half = FN(mextract, i32_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_39_1 (void)
{
  TYPE(i32_rod_sat, 1x1) m = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx1) a = FN(mcopy_m2a, i32_rod_sat, accx1) (m);
  TYPE(i32_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x1) result = FN(mcopy_a2m, i32_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx1) ();
  TYPE(i32_rod_sat, accx1) zero = FN(mzero_acc, i32_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_39_2 (void)
{
  TYPE(i32_rod_sat, 1x2) m = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx2) a = FN(mcopy_m2a, i32_rod_sat, accx2) (m);
  TYPE(i32_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x2) result = FN(mcopy_a2m, i32_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx2) ();
  TYPE(i32_rod_sat, accx2) zero = FN(mzero_acc, i32_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_40_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rnu_sat, 1x1) d = FN(mconv_ew, u64_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rnu_sat, 1x1) copy = FN(mcopy_m2m, u64_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u64_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_40_1 (void)
{
  TYPE(u64_rnu_sat, 1x1) m = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rnu_sat, accx1) a = FN(mcopy_m2a, u64_rnu_sat, accx1) (m);
  TYPE(u64_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rnu_sat, 1x1) result = FN(mcopy_a2m, u64_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rnu_sat, accx1) ();
  TYPE(u64_rnu_sat, accx1) zero = FN(mzero_acc, u64_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_41_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rne_sat, 1x1) d = FN(mconv_ew, u64_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rne_sat, 1x1) copy = FN(mcopy_m2m, u64_rne_sat, 1x1) (d);
  d = FN(mclear_m, u64_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_41_1 (void)
{
  TYPE(u64_rne_sat, 1x1) m = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rne_sat, accx1) a = FN(mcopy_m2a, u64_rne_sat, accx1) (m);
  TYPE(u64_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rne_sat, 1x1) result = FN(mcopy_a2m, u64_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rne_sat, accx1) ();
  TYPE(u64_rne_sat, accx1) zero = FN(mzero_acc, u64_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_42_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rdn_sat, 1x1) d = FN(mconv_ew, u64_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rdn_sat, 1x1) copy = FN(mcopy_m2m, u64_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u64_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_42_1 (void)
{
  TYPE(u64_rdn_sat, 1x1) m = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rdn_sat, accx1) a = FN(mcopy_m2a, u64_rdn_sat, accx1) (m);
  TYPE(u64_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rdn_sat, 1x1) result = FN(mcopy_a2m, u64_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rdn_sat, accx1) ();
  TYPE(u64_rdn_sat, accx1) zero = FN(mzero_acc, u64_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_43_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rod_sat, 1x1) d = FN(mconv_ew, u64_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rod_sat, 1x1) copy = FN(mcopy_m2m, u64_rod_sat, 1x1) (d);
  d = FN(mclear_m, u64_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_43_1 (void)
{
  TYPE(u64_rod_sat, 1x1) m = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rod_sat, accx1) a = FN(mcopy_m2a, u64_rod_sat, accx1) (m);
  TYPE(u64_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rod_sat, 1x1) result = FN(mcopy_a2m, u64_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rod_sat, accx1) ();
  TYPE(u64_rod_sat, accx1) zero = FN(mzero_acc, u64_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_44_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rnu_sat, 1x1) d = FN(mconv_ew, i64_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rnu_sat, 1x1) copy = FN(mcopy_m2m, i64_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i64_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_44_1 (void)
{
  TYPE(i64_rnu_sat, 1x1) m = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rnu_sat, accx1) a = FN(mcopy_m2a, i64_rnu_sat, accx1) (m);
  TYPE(i64_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rnu_sat, 1x1) result = FN(mcopy_a2m, i64_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rnu_sat, accx1) ();
  TYPE(i64_rnu_sat, accx1) zero = FN(mzero_acc, i64_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_45_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rne_sat, 1x1) d = FN(mconv_ew, i64_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rne_sat, 1x1) copy = FN(mcopy_m2m, i64_rne_sat, 1x1) (d);
  d = FN(mclear_m, i64_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_45_1 (void)
{
  TYPE(i64_rne_sat, 1x1) m = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rne_sat, accx1) a = FN(mcopy_m2a, i64_rne_sat, accx1) (m);
  TYPE(i64_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rne_sat, 1x1) result = FN(mcopy_a2m, i64_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rne_sat, accx1) ();
  TYPE(i64_rne_sat, accx1) zero = FN(mzero_acc, i64_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_46_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rdn_sat, 1x1) d = FN(mconv_ew, i64_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rdn_sat, 1x1) copy = FN(mcopy_m2m, i64_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i64_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_46_1 (void)
{
  TYPE(i64_rdn_sat, 1x1) m = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rdn_sat, accx1) a = FN(mcopy_m2a, i64_rdn_sat, accx1) (m);
  TYPE(i64_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rdn_sat, 1x1) result = FN(mcopy_a2m, i64_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rdn_sat, accx1) ();
  TYPE(i64_rdn_sat, accx1) zero = FN(mzero_acc, i64_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_47_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rod_sat, 1x1) d = FN(mconv_ew, i64_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rod_sat, 1x1) copy = FN(mcopy_m2m, i64_rod_sat, 1x1) (d);
  d = FN(mclear_m, i64_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_47_1 (void)
{
  TYPE(i64_rod_sat, 1x1) m = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rod_sat, accx1) a = FN(mcopy_m2a, i64_rod_sat, accx1) (m);
  TYPE(i64_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rod_sat, 1x1) result = FN(mcopy_a2m, i64_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rod_sat, accx1) ();
  TYPE(i64_rod_sat, accx1) zero = FN(mzero_acc, i64_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
#endif

#if TEST_UDS == 32
void value_0_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 1x8) d = FN(mconv_ew, u4_rnu, 1x8) (s);
  d = FN(mabs_ew, u4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u4_rnu, 1x8) copy = FN(mcopy_m2m, u4_rnu, 1x8) (d);
  d = FN(mclear_m, u4_rnu, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu, 1x16) group = FN(mconcat_m, u4_rnu, 1x16) (copy, copy);
  TYPE(u4_rnu, 1x8) half = FN(mextract, u4_rnu, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_0_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 8x1) d = FN(mconv_ew, u4_rnu, 8x1) (s);
  d = FN(mabs_ew, u4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u4_rnu, 8x1) copy = FN(mcopy_m2m, u4_rnu, 8x1) (d);
  d = FN(mclear_m, u4_rnu, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu, 16x1) group = FN(mconcat_m, u4_rnu, 16x1) (copy, copy);
  TYPE(u4_rnu, 8x1) half = FN(mextract, u4_rnu, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_0_8 (void)
{
  TYPE(u4_rnu, 1x8) m = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rnu, accx8) a = FN(mcopy_m2a, u4_rnu, accx8) (m);
  TYPE(u4_rnu, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu, 1x8) result = FN(mcopy_a2m, u4_rnu, 1x8) (copy);
  a = FN(mclear_acc, u4_rnu, accx8) ();
  TYPE(u4_rnu, accx8) zero = FN(mzero_acc, u4_rnu, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_0_16 (void)
{
  TYPE(u4_rnu, 1x16) m = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rnu, accx16) a = FN(mcopy_m2a, u4_rnu, accx16) (m);
  TYPE(u4_rnu, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu, 1x16) result = FN(mcopy_a2m, u4_rnu, 1x16) (copy);
  a = FN(mclear_acc, u4_rnu, accx16) ();
  TYPE(u4_rnu, accx16) zero = FN(mzero_acc, u4_rnu, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_1_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u4_rne, 1x8) d = FN(mconv_ew, u4_rne, 1x8) (s);
  d = FN(mabs_ew, u4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u4_rne, 1x8) copy = FN(mcopy_m2m, u4_rne, 1x8) (d);
  d = FN(mclear_m, u4_rne, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne, 1x16) group = FN(mconcat_m, u4_rne, 1x16) (copy, copy);
  TYPE(u4_rne, 1x8) half = FN(mextract, u4_rne, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_1_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u4_rne, 8x1) d = FN(mconv_ew, u4_rne, 8x1) (s);
  d = FN(mabs_ew, u4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u4_rne, 8x1) copy = FN(mcopy_m2m, u4_rne, 8x1) (d);
  d = FN(mclear_m, u4_rne, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne, 16x1) group = FN(mconcat_m, u4_rne, 16x1) (copy, copy);
  TYPE(u4_rne, 8x1) half = FN(mextract, u4_rne, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_1_8 (void)
{
  TYPE(u4_rne, 1x8) m = FN(mzero_m, u4_rne, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rne, accx8) a = FN(mcopy_m2a, u4_rne, accx8) (m);
  TYPE(u4_rne, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne, 1x8) result = FN(mcopy_a2m, u4_rne, 1x8) (copy);
  a = FN(mclear_acc, u4_rne, accx8) ();
  TYPE(u4_rne, accx8) zero = FN(mzero_acc, u4_rne, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_1_16 (void)
{
  TYPE(u4_rne, 1x16) m = FN(mzero_m, u4_rne, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rne, accx16) a = FN(mcopy_m2a, u4_rne, accx16) (m);
  TYPE(u4_rne, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne, 1x16) result = FN(mcopy_a2m, u4_rne, 1x16) (copy);
  a = FN(mclear_acc, u4_rne, accx16) ();
  TYPE(u4_rne, accx16) zero = FN(mzero_acc, u4_rne, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_2_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 1x8) d = FN(mconv_ew, u4_rdn, 1x8) (s);
  d = FN(mabs_ew, u4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u4_rdn, 1x8) copy = FN(mcopy_m2m, u4_rdn, 1x8) (d);
  d = FN(mclear_m, u4_rdn, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn, 1x16) group = FN(mconcat_m, u4_rdn, 1x16) (copy, copy);
  TYPE(u4_rdn, 1x8) half = FN(mextract, u4_rdn, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_2_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 8x1) d = FN(mconv_ew, u4_rdn, 8x1) (s);
  d = FN(mabs_ew, u4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u4_rdn, 8x1) copy = FN(mcopy_m2m, u4_rdn, 8x1) (d);
  d = FN(mclear_m, u4_rdn, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn, 16x1) group = FN(mconcat_m, u4_rdn, 16x1) (copy, copy);
  TYPE(u4_rdn, 8x1) half = FN(mextract, u4_rdn, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_2_8 (void)
{
  TYPE(u4_rdn, 1x8) m = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rdn, accx8) a = FN(mcopy_m2a, u4_rdn, accx8) (m);
  TYPE(u4_rdn, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn, 1x8) result = FN(mcopy_a2m, u4_rdn, 1x8) (copy);
  a = FN(mclear_acc, u4_rdn, accx8) ();
  TYPE(u4_rdn, accx8) zero = FN(mzero_acc, u4_rdn, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_2_16 (void)
{
  TYPE(u4_rdn, 1x16) m = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rdn, accx16) a = FN(mcopy_m2a, u4_rdn, accx16) (m);
  TYPE(u4_rdn, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn, 1x16) result = FN(mcopy_a2m, u4_rdn, 1x16) (copy);
  a = FN(mclear_acc, u4_rdn, accx16) ();
  TYPE(u4_rdn, accx16) zero = FN(mzero_acc, u4_rdn, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_3_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u4_rod, 1x8) d = FN(mconv_ew, u4_rod, 1x8) (s);
  d = FN(mabs_ew, u4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u4_rod, 1x8) copy = FN(mcopy_m2m, u4_rod, 1x8) (d);
  d = FN(mclear_m, u4_rod, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod, 1x16) group = FN(mconcat_m, u4_rod, 1x16) (copy, copy);
  TYPE(u4_rod, 1x8) half = FN(mextract, u4_rod, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_3_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u4_rod, 8x1) d = FN(mconv_ew, u4_rod, 8x1) (s);
  d = FN(mabs_ew, u4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u4_rod, 8x1) copy = FN(mcopy_m2m, u4_rod, 8x1) (d);
  d = FN(mclear_m, u4_rod, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod, 16x1) group = FN(mconcat_m, u4_rod, 16x1) (copy, copy);
  TYPE(u4_rod, 8x1) half = FN(mextract, u4_rod, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_3_8 (void)
{
  TYPE(u4_rod, 1x8) m = FN(mzero_m, u4_rod, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rod, accx8) a = FN(mcopy_m2a, u4_rod, accx8) (m);
  TYPE(u4_rod, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod, 1x8) result = FN(mcopy_a2m, u4_rod, 1x8) (copy);
  a = FN(mclear_acc, u4_rod, accx8) ();
  TYPE(u4_rod, accx8) zero = FN(mzero_acc, u4_rod, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_3_16 (void)
{
  TYPE(u4_rod, 1x16) m = FN(mzero_m, u4_rod, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rod, accx16) a = FN(mcopy_m2a, u4_rod, accx16) (m);
  TYPE(u4_rod, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod, 1x16) result = FN(mcopy_a2m, u4_rod, 1x16) (copy);
  a = FN(mclear_acc, u4_rod, accx16) ();
  TYPE(u4_rod, accx16) zero = FN(mzero_acc, u4_rod, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_4_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 1x8) d = FN(mconv_ew, i4_rnu, 1x8) (s);
  d = FN(mabs_ew, i4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i4_rnu, 1x8) copy = FN(mcopy_m2m, i4_rnu, 1x8) (d);
  d = FN(mclear_m, i4_rnu, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu, 1x16) group = FN(mconcat_m, i4_rnu, 1x16) (copy, copy);
  TYPE(i4_rnu, 1x8) half = FN(mextract, i4_rnu, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_4_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 8x1) d = FN(mconv_ew, i4_rnu, 8x1) (s);
  d = FN(mabs_ew, i4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i4_rnu, 8x1) copy = FN(mcopy_m2m, i4_rnu, 8x1) (d);
  d = FN(mclear_m, i4_rnu, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu, 16x1) group = FN(mconcat_m, i4_rnu, 16x1) (copy, copy);
  TYPE(i4_rnu, 8x1) half = FN(mextract, i4_rnu, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_4_8 (void)
{
  TYPE(i4_rnu, 1x8) m = FN(mzero_m, i4_rnu, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rnu, accx8) a = FN(mcopy_m2a, i4_rnu, accx8) (m);
  TYPE(i4_rnu, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu, 1x8) result = FN(mcopy_a2m, i4_rnu, 1x8) (copy);
  a = FN(mclear_acc, i4_rnu, accx8) ();
  TYPE(i4_rnu, accx8) zero = FN(mzero_acc, i4_rnu, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_4_16 (void)
{
  TYPE(i4_rnu, 1x16) m = FN(mzero_m, i4_rnu, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rnu, accx16) a = FN(mcopy_m2a, i4_rnu, accx16) (m);
  TYPE(i4_rnu, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu, 1x16) result = FN(mcopy_a2m, i4_rnu, 1x16) (copy);
  a = FN(mclear_acc, i4_rnu, accx16) ();
  TYPE(i4_rnu, accx16) zero = FN(mzero_acc, i4_rnu, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_5_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i4_rne, 1x8) d = FN(mconv_ew, i4_rne, 1x8) (s);
  d = FN(mabs_ew, i4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i4_rne, 1x8) copy = FN(mcopy_m2m, i4_rne, 1x8) (d);
  d = FN(mclear_m, i4_rne, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne, 1x16) group = FN(mconcat_m, i4_rne, 1x16) (copy, copy);
  TYPE(i4_rne, 1x8) half = FN(mextract, i4_rne, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_5_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i4_rne, 8x1) d = FN(mconv_ew, i4_rne, 8x1) (s);
  d = FN(mabs_ew, i4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i4_rne, 8x1) copy = FN(mcopy_m2m, i4_rne, 8x1) (d);
  d = FN(mclear_m, i4_rne, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne, 16x1) group = FN(mconcat_m, i4_rne, 16x1) (copy, copy);
  TYPE(i4_rne, 8x1) half = FN(mextract, i4_rne, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_5_8 (void)
{
  TYPE(i4_rne, 1x8) m = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rne, accx8) a = FN(mcopy_m2a, i4_rne, accx8) (m);
  TYPE(i4_rne, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne, 1x8) result = FN(mcopy_a2m, i4_rne, 1x8) (copy);
  a = FN(mclear_acc, i4_rne, accx8) ();
  TYPE(i4_rne, accx8) zero = FN(mzero_acc, i4_rne, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_5_16 (void)
{
  TYPE(i4_rne, 1x16) m = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rne, accx16) a = FN(mcopy_m2a, i4_rne, accx16) (m);
  TYPE(i4_rne, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne, 1x16) result = FN(mcopy_a2m, i4_rne, 1x16) (copy);
  a = FN(mclear_acc, i4_rne, accx16) ();
  TYPE(i4_rne, accx16) zero = FN(mzero_acc, i4_rne, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_6_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 1x8) d = FN(mconv_ew, i4_rdn, 1x8) (s);
  d = FN(mabs_ew, i4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i4_rdn, 1x8) copy = FN(mcopy_m2m, i4_rdn, 1x8) (d);
  d = FN(mclear_m, i4_rdn, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn, 1x16) group = FN(mconcat_m, i4_rdn, 1x16) (copy, copy);
  TYPE(i4_rdn, 1x8) half = FN(mextract, i4_rdn, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_6_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 8x1) d = FN(mconv_ew, i4_rdn, 8x1) (s);
  d = FN(mabs_ew, i4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i4_rdn, 8x1) copy = FN(mcopy_m2m, i4_rdn, 8x1) (d);
  d = FN(mclear_m, i4_rdn, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn, 16x1) group = FN(mconcat_m, i4_rdn, 16x1) (copy, copy);
  TYPE(i4_rdn, 8x1) half = FN(mextract, i4_rdn, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_6_8 (void)
{
  TYPE(i4_rdn, 1x8) m = FN(mzero_m, i4_rdn, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rdn, accx8) a = FN(mcopy_m2a, i4_rdn, accx8) (m);
  TYPE(i4_rdn, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn, 1x8) result = FN(mcopy_a2m, i4_rdn, 1x8) (copy);
  a = FN(mclear_acc, i4_rdn, accx8) ();
  TYPE(i4_rdn, accx8) zero = FN(mzero_acc, i4_rdn, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_6_16 (void)
{
  TYPE(i4_rdn, 1x16) m = FN(mzero_m, i4_rdn, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rdn, accx16) a = FN(mcopy_m2a, i4_rdn, accx16) (m);
  TYPE(i4_rdn, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn, 1x16) result = FN(mcopy_a2m, i4_rdn, 1x16) (copy);
  a = FN(mclear_acc, i4_rdn, accx16) ();
  TYPE(i4_rdn, accx16) zero = FN(mzero_acc, i4_rdn, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_7_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i4_rod, 1x8) d = FN(mconv_ew, i4_rod, 1x8) (s);
  d = FN(mabs_ew, i4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i4_rod, 1x8) copy = FN(mcopy_m2m, i4_rod, 1x8) (d);
  d = FN(mclear_m, i4_rod, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod, 1x16) group = FN(mconcat_m, i4_rod, 1x16) (copy, copy);
  TYPE(i4_rod, 1x8) half = FN(mextract, i4_rod, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_7_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i4_rod, 8x1) d = FN(mconv_ew, i4_rod, 8x1) (s);
  d = FN(mabs_ew, i4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i4_rod, 8x1) copy = FN(mcopy_m2m, i4_rod, 8x1) (d);
  d = FN(mclear_m, i4_rod, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod, 16x1) group = FN(mconcat_m, i4_rod, 16x1) (copy, copy);
  TYPE(i4_rod, 8x1) half = FN(mextract, i4_rod, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_7_8 (void)
{
  TYPE(i4_rod, 1x8) m = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rod, accx8) a = FN(mcopy_m2a, i4_rod, accx8) (m);
  TYPE(i4_rod, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod, 1x8) result = FN(mcopy_a2m, i4_rod, 1x8) (copy);
  a = FN(mclear_acc, i4_rod, accx8) ();
  TYPE(i4_rod, accx8) zero = FN(mzero_acc, i4_rod, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_7_16 (void)
{
  TYPE(i4_rod, 1x16) m = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rod, accx16) a = FN(mcopy_m2a, i4_rod, accx16) (m);
  TYPE(i4_rod, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod, 1x16) result = FN(mcopy_a2m, i4_rod, 1x16) (copy);
  a = FN(mclear_acc, i4_rod, accx16) ();
  TYPE(i4_rod, accx16) zero = FN(mzero_acc, i4_rod, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_8_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 1x8) d = FN(mconv_ew, u4_rnu_sat, 1x8) (s);
  d = FN(mabs_ew, u4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u4_rnu_sat, 1x8) copy = FN(mcopy_m2m, u4_rnu_sat, 1x8) (d);
  d = FN(mclear_m, u4_rnu_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu_sat, 1x16) group = FN(mconcat_m, u4_rnu_sat, 1x16) (copy, copy);
  TYPE(u4_rnu_sat, 1x8) half = FN(mextract, u4_rnu_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_8_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 8x1) d = FN(mconv_ew, u4_rnu_sat, 8x1) (s);
  d = FN(mabs_ew, u4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u4_rnu_sat, 8x1) copy = FN(mcopy_m2m, u4_rnu_sat, 8x1) (d);
  d = FN(mclear_m, u4_rnu_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu_sat, 16x1) group = FN(mconcat_m, u4_rnu_sat, 16x1) (copy, copy);
  TYPE(u4_rnu_sat, 8x1) half = FN(mextract, u4_rnu_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_8_8 (void)
{
  TYPE(u4_rnu_sat, 1x8) m = FN(mzero_m, u4_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rnu_sat, accx8) a = FN(mcopy_m2a, u4_rnu_sat, accx8) (m);
  TYPE(u4_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu_sat, 1x8) result = FN(mcopy_a2m, u4_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rnu_sat, accx8) ();
  TYPE(u4_rnu_sat, accx8) zero = FN(mzero_acc, u4_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_8_16 (void)
{
  TYPE(u4_rnu_sat, 1x16) m = FN(mzero_m, u4_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rnu_sat, accx16) a = FN(mcopy_m2a, u4_rnu_sat, accx16) (m);
  TYPE(u4_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu_sat, 1x16) result = FN(mcopy_a2m, u4_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rnu_sat, accx16) ();
  TYPE(u4_rnu_sat, accx16) zero = FN(mzero_acc, u4_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_9_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 1x8) d = FN(mconv_ew, u4_rne_sat, 1x8) (s);
  d = FN(mabs_ew, u4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u4_rne_sat, 1x8) copy = FN(mcopy_m2m, u4_rne_sat, 1x8) (d);
  d = FN(mclear_m, u4_rne_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne_sat, 1x16) group = FN(mconcat_m, u4_rne_sat, 1x16) (copy, copy);
  TYPE(u4_rne_sat, 1x8) half = FN(mextract, u4_rne_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_9_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 8x1) d = FN(mconv_ew, u4_rne_sat, 8x1) (s);
  d = FN(mabs_ew, u4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u4_rne_sat, 8x1) copy = FN(mcopy_m2m, u4_rne_sat, 8x1) (d);
  d = FN(mclear_m, u4_rne_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne_sat, 16x1) group = FN(mconcat_m, u4_rne_sat, 16x1) (copy, copy);
  TYPE(u4_rne_sat, 8x1) half = FN(mextract, u4_rne_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_9_8 (void)
{
  TYPE(u4_rne_sat, 1x8) m = FN(mzero_m, u4_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rne_sat, accx8) a = FN(mcopy_m2a, u4_rne_sat, accx8) (m);
  TYPE(u4_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne_sat, 1x8) result = FN(mcopy_a2m, u4_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rne_sat, accx8) ();
  TYPE(u4_rne_sat, accx8) zero = FN(mzero_acc, u4_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_9_16 (void)
{
  TYPE(u4_rne_sat, 1x16) m = FN(mzero_m, u4_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rne_sat, accx16) a = FN(mcopy_m2a, u4_rne_sat, accx16) (m);
  TYPE(u4_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne_sat, 1x16) result = FN(mcopy_a2m, u4_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rne_sat, accx16) ();
  TYPE(u4_rne_sat, accx16) zero = FN(mzero_acc, u4_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_10_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 1x8) d = FN(mconv_ew, u4_rdn_sat, 1x8) (s);
  d = FN(mabs_ew, u4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u4_rdn_sat, 1x8) copy = FN(mcopy_m2m, u4_rdn_sat, 1x8) (d);
  d = FN(mclear_m, u4_rdn_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn_sat, 1x16) group = FN(mconcat_m, u4_rdn_sat, 1x16) (copy, copy);
  TYPE(u4_rdn_sat, 1x8) half = FN(mextract, u4_rdn_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_10_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 8x1) d = FN(mconv_ew, u4_rdn_sat, 8x1) (s);
  d = FN(mabs_ew, u4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u4_rdn_sat, 8x1) copy = FN(mcopy_m2m, u4_rdn_sat, 8x1) (d);
  d = FN(mclear_m, u4_rdn_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn_sat, 16x1) group = FN(mconcat_m, u4_rdn_sat, 16x1) (copy, copy);
  TYPE(u4_rdn_sat, 8x1) half = FN(mextract, u4_rdn_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_10_8 (void)
{
  TYPE(u4_rdn_sat, 1x8) m = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rdn_sat, accx8) a = FN(mcopy_m2a, u4_rdn_sat, accx8) (m);
  TYPE(u4_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn_sat, 1x8) result = FN(mcopy_a2m, u4_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rdn_sat, accx8) ();
  TYPE(u4_rdn_sat, accx8) zero = FN(mzero_acc, u4_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_10_16 (void)
{
  TYPE(u4_rdn_sat, 1x16) m = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rdn_sat, accx16) a = FN(mcopy_m2a, u4_rdn_sat, accx16) (m);
  TYPE(u4_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn_sat, 1x16) result = FN(mcopy_a2m, u4_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rdn_sat, accx16) ();
  TYPE(u4_rdn_sat, accx16) zero = FN(mzero_acc, u4_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_11_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 1x8) d = FN(mconv_ew, u4_rod_sat, 1x8) (s);
  d = FN(mabs_ew, u4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u4_rod_sat, 1x8) copy = FN(mcopy_m2m, u4_rod_sat, 1x8) (d);
  d = FN(mclear_m, u4_rod_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod_sat, 1x16) group = FN(mconcat_m, u4_rod_sat, 1x16) (copy, copy);
  TYPE(u4_rod_sat, 1x8) half = FN(mextract, u4_rod_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_11_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 8x1) d = FN(mconv_ew, u4_rod_sat, 8x1) (s);
  d = FN(mabs_ew, u4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u4_rod_sat, 8x1) copy = FN(mcopy_m2m, u4_rod_sat, 8x1) (d);
  d = FN(mclear_m, u4_rod_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod_sat, 16x1) group = FN(mconcat_m, u4_rod_sat, 16x1) (copy, copy);
  TYPE(u4_rod_sat, 8x1) half = FN(mextract, u4_rod_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_11_8 (void)
{
  TYPE(u4_rod_sat, 1x8) m = FN(mzero_m, u4_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u4_rod_sat, accx8) a = FN(mcopy_m2a, u4_rod_sat, accx8) (m);
  TYPE(u4_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod_sat, 1x8) result = FN(mcopy_a2m, u4_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u4_rod_sat, accx8) ();
  TYPE(u4_rod_sat, accx8) zero = FN(mzero_acc, u4_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_11_16 (void)
{
  TYPE(u4_rod_sat, 1x16) m = FN(mzero_m, u4_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rod_sat, accx16) a = FN(mcopy_m2a, u4_rod_sat, accx16) (m);
  TYPE(u4_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod_sat, 1x16) result = FN(mcopy_a2m, u4_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rod_sat, accx16) ();
  TYPE(u4_rod_sat, accx16) zero = FN(mzero_acc, u4_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_12_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 1x8) d = FN(mconv_ew, i4_rnu_sat, 1x8) (s);
  d = FN(mabs_ew, i4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i4_rnu_sat, 1x8) copy = FN(mcopy_m2m, i4_rnu_sat, 1x8) (d);
  d = FN(mclear_m, i4_rnu_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu_sat, 1x16) group = FN(mconcat_m, i4_rnu_sat, 1x16) (copy, copy);
  TYPE(i4_rnu_sat, 1x8) half = FN(mextract, i4_rnu_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_12_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 8x1) d = FN(mconv_ew, i4_rnu_sat, 8x1) (s);
  d = FN(mabs_ew, i4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i4_rnu_sat, 8x1) copy = FN(mcopy_m2m, i4_rnu_sat, 8x1) (d);
  d = FN(mclear_m, i4_rnu_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu_sat, 16x1) group = FN(mconcat_m, i4_rnu_sat, 16x1) (copy, copy);
  TYPE(i4_rnu_sat, 8x1) half = FN(mextract, i4_rnu_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_12_8 (void)
{
  TYPE(i4_rnu_sat, 1x8) m = FN(mzero_m, i4_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rnu_sat, accx8) a = FN(mcopy_m2a, i4_rnu_sat, accx8) (m);
  TYPE(i4_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu_sat, 1x8) result = FN(mcopy_a2m, i4_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rnu_sat, accx8) ();
  TYPE(i4_rnu_sat, accx8) zero = FN(mzero_acc, i4_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_12_16 (void)
{
  TYPE(i4_rnu_sat, 1x16) m = FN(mzero_m, i4_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rnu_sat, accx16) a = FN(mcopy_m2a, i4_rnu_sat, accx16) (m);
  TYPE(i4_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu_sat, 1x16) result = FN(mcopy_a2m, i4_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rnu_sat, accx16) ();
  TYPE(i4_rnu_sat, accx16) zero = FN(mzero_acc, i4_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_13_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 1x8) d = FN(mconv_ew, i4_rne_sat, 1x8) (s);
  d = FN(mabs_ew, i4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i4_rne_sat, 1x8) copy = FN(mcopy_m2m, i4_rne_sat, 1x8) (d);
  d = FN(mclear_m, i4_rne_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne_sat, 1x16) group = FN(mconcat_m, i4_rne_sat, 1x16) (copy, copy);
  TYPE(i4_rne_sat, 1x8) half = FN(mextract, i4_rne_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_13_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 8x1) d = FN(mconv_ew, i4_rne_sat, 8x1) (s);
  d = FN(mabs_ew, i4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i4_rne_sat, 8x1) copy = FN(mcopy_m2m, i4_rne_sat, 8x1) (d);
  d = FN(mclear_m, i4_rne_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne_sat, 16x1) group = FN(mconcat_m, i4_rne_sat, 16x1) (copy, copy);
  TYPE(i4_rne_sat, 8x1) half = FN(mextract, i4_rne_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_13_8 (void)
{
  TYPE(i4_rne_sat, 1x8) m = FN(mzero_m, i4_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rne_sat, accx8) a = FN(mcopy_m2a, i4_rne_sat, accx8) (m);
  TYPE(i4_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne_sat, 1x8) result = FN(mcopy_a2m, i4_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rne_sat, accx8) ();
  TYPE(i4_rne_sat, accx8) zero = FN(mzero_acc, i4_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_13_16 (void)
{
  TYPE(i4_rne_sat, 1x16) m = FN(mzero_m, i4_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rne_sat, accx16) a = FN(mcopy_m2a, i4_rne_sat, accx16) (m);
  TYPE(i4_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne_sat, 1x16) result = FN(mcopy_a2m, i4_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rne_sat, accx16) ();
  TYPE(i4_rne_sat, accx16) zero = FN(mzero_acc, i4_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_14_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 1x8) d = FN(mconv_ew, i4_rdn_sat, 1x8) (s);
  d = FN(mabs_ew, i4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i4_rdn_sat, 1x8) copy = FN(mcopy_m2m, i4_rdn_sat, 1x8) (d);
  d = FN(mclear_m, i4_rdn_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn_sat, 1x16) group = FN(mconcat_m, i4_rdn_sat, 1x16) (copy, copy);
  TYPE(i4_rdn_sat, 1x8) half = FN(mextract, i4_rdn_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_14_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 8x1) d = FN(mconv_ew, i4_rdn_sat, 8x1) (s);
  d = FN(mabs_ew, i4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i4_rdn_sat, 8x1) copy = FN(mcopy_m2m, i4_rdn_sat, 8x1) (d);
  d = FN(mclear_m, i4_rdn_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn_sat, 16x1) group = FN(mconcat_m, i4_rdn_sat, 16x1) (copy, copy);
  TYPE(i4_rdn_sat, 8x1) half = FN(mextract, i4_rdn_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_14_8 (void)
{
  TYPE(i4_rdn_sat, 1x8) m = FN(mzero_m, i4_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rdn_sat, accx8) a = FN(mcopy_m2a, i4_rdn_sat, accx8) (m);
  TYPE(i4_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn_sat, 1x8) result = FN(mcopy_a2m, i4_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rdn_sat, accx8) ();
  TYPE(i4_rdn_sat, accx8) zero = FN(mzero_acc, i4_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_14_16 (void)
{
  TYPE(i4_rdn_sat, 1x16) m = FN(mzero_m, i4_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rdn_sat, accx16) a = FN(mcopy_m2a, i4_rdn_sat, accx16) (m);
  TYPE(i4_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn_sat, 1x16) result = FN(mcopy_a2m, i4_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rdn_sat, accx16) ();
  TYPE(i4_rdn_sat, accx16) zero = FN(mzero_acc, i4_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_15_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 1x8) d = FN(mconv_ew, i4_rod_sat, 1x8) (s);
  d = FN(mabs_ew, i4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i4_rod_sat, 1x8) copy = FN(mcopy_m2m, i4_rod_sat, 1x8) (d);
  d = FN(mclear_m, i4_rod_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod_sat, 1x16) group = FN(mconcat_m, i4_rod_sat, 1x16) (copy, copy);
  TYPE(i4_rod_sat, 1x8) half = FN(mextract, i4_rod_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_15_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 8x1) d = FN(mconv_ew, i4_rod_sat, 8x1) (s);
  d = FN(mabs_ew, i4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i4_rod_sat, 8x1) copy = FN(mcopy_m2m, i4_rod_sat, 8x1) (d);
  d = FN(mclear_m, i4_rod_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod_sat, 16x1) group = FN(mconcat_m, i4_rod_sat, 16x1) (copy, copy);
  TYPE(i4_rod_sat, 8x1) half = FN(mextract, i4_rod_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_15_8 (void)
{
  TYPE(i4_rod_sat, 1x8) m = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i4_rod_sat, accx8) a = FN(mcopy_m2a, i4_rod_sat, accx8) (m);
  TYPE(i4_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod_sat, 1x8) result = FN(mcopy_a2m, i4_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i4_rod_sat, accx8) ();
  TYPE(i4_rod_sat, accx8) zero = FN(mzero_acc, i4_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_15_16 (void)
{
  TYPE(i4_rod_sat, 1x16) m = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rod_sat, accx16) a = FN(mcopy_m2a, i4_rod_sat, accx16) (m);
  TYPE(i4_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod_sat, 1x16) result = FN(mcopy_a2m, i4_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rod_sat, accx16) ();
  TYPE(i4_rod_sat, accx16) zero = FN(mzero_acc, i4_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_16_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u8_rnu_sat, 1x4) d = FN(mconv_ew, u8_rnu_sat, 1x4) (s);
  d = FN(mabs_ew, u8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rnu_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u8_rnu_sat, 1x4) copy = FN(mcopy_m2m, u8_rnu_sat, 1x4) (d);
  d = FN(mclear_m, u8_rnu_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rnu_sat, 1x8) group = FN(mconcat_m, u8_rnu_sat, 1x8) (copy, copy);
  TYPE(u8_rnu_sat, 1x4) half = FN(mextract, u8_rnu_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_16_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u8_rnu_sat, 4x1) d = FN(mconv_ew, u8_rnu_sat, 4x1) (s);
  d = FN(mabs_ew, u8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rnu_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u8_rnu_sat, 4x1) copy = FN(mcopy_m2m, u8_rnu_sat, 4x1) (d);
  d = FN(mclear_m, u8_rnu_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rnu_sat, 8x1) group = FN(mconcat_m, u8_rnu_sat, 8x1) (copy, copy);
  TYPE(u8_rnu_sat, 4x1) half = FN(mextract, u8_rnu_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_16_4 (void)
{
  TYPE(u8_rnu_sat, 1x4) m = FN(mzero_m, u8_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx4) a = FN(mcopy_m2a, u8_rnu_sat, accx4) (m);
  TYPE(u8_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x4) result = FN(mcopy_a2m, u8_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx4) ();
  TYPE(u8_rnu_sat, accx4) zero = FN(mzero_acc, u8_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_16_8 (void)
{
  TYPE(u8_rnu_sat, 1x8) m = FN(mzero_m, u8_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx8) a = FN(mcopy_m2a, u8_rnu_sat, accx8) (m);
  TYPE(u8_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x8) result = FN(mcopy_a2m, u8_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx8) ();
  TYPE(u8_rnu_sat, accx8) zero = FN(mzero_acc, u8_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_16_16 (void)
{
  TYPE(u8_rnu_sat, 1x16) m = FN(mzero_m, u8_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx16) a = FN(mcopy_m2a, u8_rnu_sat, accx16) (m);
  TYPE(u8_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x16) result = FN(mcopy_a2m, u8_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx16) ();
  TYPE(u8_rnu_sat, accx16) zero = FN(mzero_acc, u8_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_17_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u8_rne_sat, 1x4) d = FN(mconv_ew, u8_rne_sat, 1x4) (s);
  d = FN(mabs_ew, u8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rne_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u8_rne_sat, 1x4) copy = FN(mcopy_m2m, u8_rne_sat, 1x4) (d);
  d = FN(mclear_m, u8_rne_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rne_sat, 1x8) group = FN(mconcat_m, u8_rne_sat, 1x8) (copy, copy);
  TYPE(u8_rne_sat, 1x4) half = FN(mextract, u8_rne_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_17_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u8_rne_sat, 4x1) d = FN(mconv_ew, u8_rne_sat, 4x1) (s);
  d = FN(mabs_ew, u8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rne_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u8_rne_sat, 4x1) copy = FN(mcopy_m2m, u8_rne_sat, 4x1) (d);
  d = FN(mclear_m, u8_rne_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rne_sat, 8x1) group = FN(mconcat_m, u8_rne_sat, 8x1) (copy, copy);
  TYPE(u8_rne_sat, 4x1) half = FN(mextract, u8_rne_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_17_4 (void)
{
  TYPE(u8_rne_sat, 1x4) m = FN(mzero_m, u8_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx4) a = FN(mcopy_m2a, u8_rne_sat, accx4) (m);
  TYPE(u8_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x4) result = FN(mcopy_a2m, u8_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx4) ();
  TYPE(u8_rne_sat, accx4) zero = FN(mzero_acc, u8_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_17_8 (void)
{
  TYPE(u8_rne_sat, 1x8) m = FN(mzero_m, u8_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx8) a = FN(mcopy_m2a, u8_rne_sat, accx8) (m);
  TYPE(u8_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x8) result = FN(mcopy_a2m, u8_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx8) ();
  TYPE(u8_rne_sat, accx8) zero = FN(mzero_acc, u8_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_17_16 (void)
{
  TYPE(u8_rne_sat, 1x16) m = FN(mzero_m, u8_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx16) a = FN(mcopy_m2a, u8_rne_sat, accx16) (m);
  TYPE(u8_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x16) result = FN(mcopy_a2m, u8_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx16) ();
  TYPE(u8_rne_sat, accx16) zero = FN(mzero_acc, u8_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_18_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u8_rdn_sat, 1x4) d = FN(mconv_ew, u8_rdn_sat, 1x4) (s);
  d = FN(mabs_ew, u8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rdn_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u8_rdn_sat, 1x4) copy = FN(mcopy_m2m, u8_rdn_sat, 1x4) (d);
  d = FN(mclear_m, u8_rdn_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rdn_sat, 1x8) group = FN(mconcat_m, u8_rdn_sat, 1x8) (copy, copy);
  TYPE(u8_rdn_sat, 1x4) half = FN(mextract, u8_rdn_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_18_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u8_rdn_sat, 4x1) d = FN(mconv_ew, u8_rdn_sat, 4x1) (s);
  d = FN(mabs_ew, u8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rdn_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u8_rdn_sat, 4x1) copy = FN(mcopy_m2m, u8_rdn_sat, 4x1) (d);
  d = FN(mclear_m, u8_rdn_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rdn_sat, 8x1) group = FN(mconcat_m, u8_rdn_sat, 8x1) (copy, copy);
  TYPE(u8_rdn_sat, 4x1) half = FN(mextract, u8_rdn_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_18_4 (void)
{
  TYPE(u8_rdn_sat, 1x4) m = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx4) a = FN(mcopy_m2a, u8_rdn_sat, accx4) (m);
  TYPE(u8_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x4) result = FN(mcopy_a2m, u8_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx4) ();
  TYPE(u8_rdn_sat, accx4) zero = FN(mzero_acc, u8_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_18_8 (void)
{
  TYPE(u8_rdn_sat, 1x8) m = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx8) a = FN(mcopy_m2a, u8_rdn_sat, accx8) (m);
  TYPE(u8_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x8) result = FN(mcopy_a2m, u8_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx8) ();
  TYPE(u8_rdn_sat, accx8) zero = FN(mzero_acc, u8_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_18_16 (void)
{
  TYPE(u8_rdn_sat, 1x16) m = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx16) a = FN(mcopy_m2a, u8_rdn_sat, accx16) (m);
  TYPE(u8_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x16) result = FN(mcopy_a2m, u8_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx16) ();
  TYPE(u8_rdn_sat, accx16) zero = FN(mzero_acc, u8_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_19_0 (void)
{
  TYPE(i8_rod, 1x4) s = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u8_rod_sat, 1x4) d = FN(mconv_ew, u8_rod_sat, 1x4) (s);
  d = FN(mabs_ew, u8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rod_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x4) back = FN(mconv_ew, i8_rod, 1x4) (d);
  TYPE(u8_rod_sat, 1x4) copy = FN(mcopy_m2m, u8_rod_sat, 1x4) (d);
  d = FN(mclear_m, u8_rod_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rod_sat, 1x8) group = FN(mconcat_m, u8_rod_sat, 1x8) (copy, copy);
  TYPE(u8_rod_sat, 1x4) half = FN(mextract, u8_rod_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_19_1 (void)
{
  TYPE(i8_rod, 4x1) s = FN(mzero_m, i8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u8_rod_sat, 4x1) d = FN(mconv_ew, u8_rod_sat, 4x1) (s);
  d = FN(mabs_ew, u8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rod_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 4x1) back = FN(mconv_ew, i8_rod, 4x1) (d);
  TYPE(u8_rod_sat, 4x1) copy = FN(mcopy_m2m, u8_rod_sat, 4x1) (d);
  d = FN(mclear_m, u8_rod_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rod_sat, 8x1) group = FN(mconcat_m, u8_rod_sat, 8x1) (copy, copy);
  TYPE(u8_rod_sat, 4x1) half = FN(mextract, u8_rod_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_19_4 (void)
{
  TYPE(u8_rod_sat, 1x4) m = FN(mzero_m, u8_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx4) a = FN(mcopy_m2a, u8_rod_sat, accx4) (m);
  TYPE(u8_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x4) result = FN(mcopy_a2m, u8_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx4) ();
  TYPE(u8_rod_sat, accx4) zero = FN(mzero_acc, u8_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_19_8 (void)
{
  TYPE(u8_rod_sat, 1x8) m = FN(mzero_m, u8_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx8) a = FN(mcopy_m2a, u8_rod_sat, accx8) (m);
  TYPE(u8_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x8) result = FN(mcopy_a2m, u8_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx8) ();
  TYPE(u8_rod_sat, accx8) zero = FN(mzero_acc, u8_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_19_16 (void)
{
  TYPE(u8_rod_sat, 1x16) m = FN(mzero_m, u8_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx16) a = FN(mcopy_m2a, u8_rod_sat, accx16) (m);
  TYPE(u8_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x16) result = FN(mcopy_a2m, u8_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx16) ();
  TYPE(u8_rod_sat, accx16) zero = FN(mzero_acc, u8_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_20_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i8_rnu_sat, 1x4) d = FN(mconv_ew, i8_rnu_sat, 1x4) (s);
  d = FN(mabs_ew, i8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rnu_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i8_rnu_sat, 1x4) copy = FN(mcopy_m2m, i8_rnu_sat, 1x4) (d);
  d = FN(mclear_m, i8_rnu_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rnu_sat, 1x8) group = FN(mconcat_m, i8_rnu_sat, 1x8) (copy, copy);
  TYPE(i8_rnu_sat, 1x4) half = FN(mextract, i8_rnu_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_20_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i8_rnu_sat, 4x1) d = FN(mconv_ew, i8_rnu_sat, 4x1) (s);
  d = FN(mabs_ew, i8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rnu_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i8_rnu_sat, 4x1) copy = FN(mcopy_m2m, i8_rnu_sat, 4x1) (d);
  d = FN(mclear_m, i8_rnu_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rnu_sat, 8x1) group = FN(mconcat_m, i8_rnu_sat, 8x1) (copy, copy);
  TYPE(i8_rnu_sat, 4x1) half = FN(mextract, i8_rnu_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_20_4 (void)
{
  TYPE(i8_rnu_sat, 1x4) m = FN(mzero_m, i8_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx4) a = FN(mcopy_m2a, i8_rnu_sat, accx4) (m);
  TYPE(i8_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x4) result = FN(mcopy_a2m, i8_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx4) ();
  TYPE(i8_rnu_sat, accx4) zero = FN(mzero_acc, i8_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_20_8 (void)
{
  TYPE(i8_rnu_sat, 1x8) m = FN(mzero_m, i8_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx8) a = FN(mcopy_m2a, i8_rnu_sat, accx8) (m);
  TYPE(i8_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x8) result = FN(mcopy_a2m, i8_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx8) ();
  TYPE(i8_rnu_sat, accx8) zero = FN(mzero_acc, i8_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_20_16 (void)
{
  TYPE(i8_rnu_sat, 1x16) m = FN(mzero_m, i8_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx16) a = FN(mcopy_m2a, i8_rnu_sat, accx16) (m);
  TYPE(i8_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x16) result = FN(mcopy_a2m, i8_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx16) ();
  TYPE(i8_rnu_sat, accx16) zero = FN(mzero_acc, i8_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_21_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i8_rne_sat, 1x4) d = FN(mconv_ew, i8_rne_sat, 1x4) (s);
  d = FN(mabs_ew, i8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rne_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i8_rne_sat, 1x4) copy = FN(mcopy_m2m, i8_rne_sat, 1x4) (d);
  d = FN(mclear_m, i8_rne_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rne_sat, 1x8) group = FN(mconcat_m, i8_rne_sat, 1x8) (copy, copy);
  TYPE(i8_rne_sat, 1x4) half = FN(mextract, i8_rne_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_21_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i8_rne_sat, 4x1) d = FN(mconv_ew, i8_rne_sat, 4x1) (s);
  d = FN(mabs_ew, i8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rne_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i8_rne_sat, 4x1) copy = FN(mcopy_m2m, i8_rne_sat, 4x1) (d);
  d = FN(mclear_m, i8_rne_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rne_sat, 8x1) group = FN(mconcat_m, i8_rne_sat, 8x1) (copy, copy);
  TYPE(i8_rne_sat, 4x1) half = FN(mextract, i8_rne_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_21_4 (void)
{
  TYPE(i8_rne_sat, 1x4) m = FN(mzero_m, i8_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx4) a = FN(mcopy_m2a, i8_rne_sat, accx4) (m);
  TYPE(i8_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x4) result = FN(mcopy_a2m, i8_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx4) ();
  TYPE(i8_rne_sat, accx4) zero = FN(mzero_acc, i8_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_21_8 (void)
{
  TYPE(i8_rne_sat, 1x8) m = FN(mzero_m, i8_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx8) a = FN(mcopy_m2a, i8_rne_sat, accx8) (m);
  TYPE(i8_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x8) result = FN(mcopy_a2m, i8_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx8) ();
  TYPE(i8_rne_sat, accx8) zero = FN(mzero_acc, i8_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_21_16 (void)
{
  TYPE(i8_rne_sat, 1x16) m = FN(mzero_m, i8_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx16) a = FN(mcopy_m2a, i8_rne_sat, accx16) (m);
  TYPE(i8_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x16) result = FN(mcopy_a2m, i8_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx16) ();
  TYPE(i8_rne_sat, accx16) zero = FN(mzero_acc, i8_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_22_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i8_rdn_sat, 1x4) d = FN(mconv_ew, i8_rdn_sat, 1x4) (s);
  d = FN(mabs_ew, i8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rdn_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i8_rdn_sat, 1x4) copy = FN(mcopy_m2m, i8_rdn_sat, 1x4) (d);
  d = FN(mclear_m, i8_rdn_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rdn_sat, 1x8) group = FN(mconcat_m, i8_rdn_sat, 1x8) (copy, copy);
  TYPE(i8_rdn_sat, 1x4) half = FN(mextract, i8_rdn_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_22_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i8_rdn_sat, 4x1) d = FN(mconv_ew, i8_rdn_sat, 4x1) (s);
  d = FN(mabs_ew, i8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rdn_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i8_rdn_sat, 4x1) copy = FN(mcopy_m2m, i8_rdn_sat, 4x1) (d);
  d = FN(mclear_m, i8_rdn_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rdn_sat, 8x1) group = FN(mconcat_m, i8_rdn_sat, 8x1) (copy, copy);
  TYPE(i8_rdn_sat, 4x1) half = FN(mextract, i8_rdn_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_22_4 (void)
{
  TYPE(i8_rdn_sat, 1x4) m = FN(mzero_m, i8_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx4) a = FN(mcopy_m2a, i8_rdn_sat, accx4) (m);
  TYPE(i8_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x4) result = FN(mcopy_a2m, i8_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx4) ();
  TYPE(i8_rdn_sat, accx4) zero = FN(mzero_acc, i8_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_22_8 (void)
{
  TYPE(i8_rdn_sat, 1x8) m = FN(mzero_m, i8_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx8) a = FN(mcopy_m2a, i8_rdn_sat, accx8) (m);
  TYPE(i8_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x8) result = FN(mcopy_a2m, i8_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx8) ();
  TYPE(i8_rdn_sat, accx8) zero = FN(mzero_acc, i8_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_22_16 (void)
{
  TYPE(i8_rdn_sat, 1x16) m = FN(mzero_m, i8_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx16) a = FN(mcopy_m2a, i8_rdn_sat, accx16) (m);
  TYPE(i8_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x16) result = FN(mcopy_a2m, i8_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx16) ();
  TYPE(i8_rdn_sat, accx16) zero = FN(mzero_acc, i8_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_23_0 (void)
{
  TYPE(u8_rod, 1x4) s = FN(mzero_m, u8_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i8_rod_sat, 1x4) d = FN(mconv_ew, i8_rod_sat, 1x4) (s);
  d = FN(mabs_ew, i8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rod_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x4) back = FN(mconv_ew, u8_rod, 1x4) (d);
  TYPE(i8_rod_sat, 1x4) copy = FN(mcopy_m2m, i8_rod_sat, 1x4) (d);
  d = FN(mclear_m, i8_rod_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rod_sat, 1x8) group = FN(mconcat_m, i8_rod_sat, 1x8) (copy, copy);
  TYPE(i8_rod_sat, 1x4) half = FN(mextract, i8_rod_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_23_1 (void)
{
  TYPE(u8_rod, 4x1) s = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i8_rod_sat, 4x1) d = FN(mconv_ew, i8_rod_sat, 4x1) (s);
  d = FN(mabs_ew, i8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rod_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 4x1) back = FN(mconv_ew, u8_rod, 4x1) (d);
  TYPE(i8_rod_sat, 4x1) copy = FN(mcopy_m2m, i8_rod_sat, 4x1) (d);
  d = FN(mclear_m, i8_rod_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rod_sat, 8x1) group = FN(mconcat_m, i8_rod_sat, 8x1) (copy, copy);
  TYPE(i8_rod_sat, 4x1) half = FN(mextract, i8_rod_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_23_4 (void)
{
  TYPE(i8_rod_sat, 1x4) m = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx4) a = FN(mcopy_m2a, i8_rod_sat, accx4) (m);
  TYPE(i8_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x4) result = FN(mcopy_a2m, i8_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx4) ();
  TYPE(i8_rod_sat, accx4) zero = FN(mzero_acc, i8_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_23_8 (void)
{
  TYPE(i8_rod_sat, 1x8) m = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx8) a = FN(mcopy_m2a, i8_rod_sat, accx8) (m);
  TYPE(i8_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x8) result = FN(mcopy_a2m, i8_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx8) ();
  TYPE(i8_rod_sat, accx8) zero = FN(mzero_acc, i8_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_23_16 (void)
{
  TYPE(i8_rod_sat, 1x16) m = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx16) a = FN(mcopy_m2a, i8_rod_sat, accx16) (m);
  TYPE(i8_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x16) result = FN(mcopy_a2m, i8_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx16) ();
  TYPE(i8_rod_sat, accx16) zero = FN(mzero_acc, i8_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_24_0 (void)
{
  TYPE(i16_rod, 1x2) s = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u16_rnu_sat, 1x2) d = FN(mconv_ew, u16_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, u16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x2) back = FN(mconv_ew, i16_rod, 1x2) (d);
  TYPE(u16_rnu_sat, 1x2) copy = FN(mcopy_m2m, u16_rnu_sat, 1x2) (d);
  d = FN(mclear_m, u16_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rnu_sat, 1x4) group = FN(mconcat_m, u16_rnu_sat, 1x4) (copy, copy);
  TYPE(u16_rnu_sat, 1x2) half = FN(mextract, u16_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_24_1 (void)
{
  TYPE(i16_rod, 2x1) s = FN(mzero_m, i16_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u16_rnu_sat, 2x1) d = FN(mconv_ew, u16_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, u16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 2x1) back = FN(mconv_ew, i16_rod, 2x1) (d);
  TYPE(u16_rnu_sat, 2x1) copy = FN(mcopy_m2m, u16_rnu_sat, 2x1) (d);
  d = FN(mclear_m, u16_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rnu_sat, 4x1) group = FN(mconcat_m, u16_rnu_sat, 4x1) (copy, copy);
  TYPE(u16_rnu_sat, 2x1) half = FN(mextract, u16_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_24_2 (void)
{
  TYPE(u16_rnu_sat, 1x2) m = FN(mzero_m, u16_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx2) a = FN(mcopy_m2a, u16_rnu_sat, accx2) (m);
  TYPE(u16_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x2) result = FN(mcopy_a2m, u16_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx2) ();
  TYPE(u16_rnu_sat, accx2) zero = FN(mzero_acc, u16_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_24_4 (void)
{
  TYPE(u16_rnu_sat, 1x4) m = FN(mzero_m, u16_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx4) a = FN(mcopy_m2a, u16_rnu_sat, accx4) (m);
  TYPE(u16_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x4) result = FN(mcopy_a2m, u16_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx4) ();
  TYPE(u16_rnu_sat, accx4) zero = FN(mzero_acc, u16_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_24_8 (void)
{
  TYPE(u16_rnu_sat, 1x8) m = FN(mzero_m, u16_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx8) a = FN(mcopy_m2a, u16_rnu_sat, accx8) (m);
  TYPE(u16_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x8) result = FN(mcopy_a2m, u16_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx8) ();
  TYPE(u16_rnu_sat, accx8) zero = FN(mzero_acc, u16_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_25_0 (void)
{
  TYPE(i16_rod, 1x2) s = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u16_rne_sat, 1x2) d = FN(mconv_ew, u16_rne_sat, 1x2) (s);
  d = FN(mabs_ew, u16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x2) back = FN(mconv_ew, i16_rod, 1x2) (d);
  TYPE(u16_rne_sat, 1x2) copy = FN(mcopy_m2m, u16_rne_sat, 1x2) (d);
  d = FN(mclear_m, u16_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rne_sat, 1x4) group = FN(mconcat_m, u16_rne_sat, 1x4) (copy, copy);
  TYPE(u16_rne_sat, 1x2) half = FN(mextract, u16_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_25_1 (void)
{
  TYPE(i16_rod, 2x1) s = FN(mzero_m, i16_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u16_rne_sat, 2x1) d = FN(mconv_ew, u16_rne_sat, 2x1) (s);
  d = FN(mabs_ew, u16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 2x1) back = FN(mconv_ew, i16_rod, 2x1) (d);
  TYPE(u16_rne_sat, 2x1) copy = FN(mcopy_m2m, u16_rne_sat, 2x1) (d);
  d = FN(mclear_m, u16_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rne_sat, 4x1) group = FN(mconcat_m, u16_rne_sat, 4x1) (copy, copy);
  TYPE(u16_rne_sat, 2x1) half = FN(mextract, u16_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_25_2 (void)
{
  TYPE(u16_rne_sat, 1x2) m = FN(mzero_m, u16_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx2) a = FN(mcopy_m2a, u16_rne_sat, accx2) (m);
  TYPE(u16_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x2) result = FN(mcopy_a2m, u16_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx2) ();
  TYPE(u16_rne_sat, accx2) zero = FN(mzero_acc, u16_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_25_4 (void)
{
  TYPE(u16_rne_sat, 1x4) m = FN(mzero_m, u16_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx4) a = FN(mcopy_m2a, u16_rne_sat, accx4) (m);
  TYPE(u16_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x4) result = FN(mcopy_a2m, u16_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx4) ();
  TYPE(u16_rne_sat, accx4) zero = FN(mzero_acc, u16_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_25_8 (void)
{
  TYPE(u16_rne_sat, 1x8) m = FN(mzero_m, u16_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx8) a = FN(mcopy_m2a, u16_rne_sat, accx8) (m);
  TYPE(u16_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x8) result = FN(mcopy_a2m, u16_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx8) ();
  TYPE(u16_rne_sat, accx8) zero = FN(mzero_acc, u16_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_26_0 (void)
{
  TYPE(i16_rod, 1x2) s = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u16_rdn_sat, 1x2) d = FN(mconv_ew, u16_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, u16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x2) back = FN(mconv_ew, i16_rod, 1x2) (d);
  TYPE(u16_rdn_sat, 1x2) copy = FN(mcopy_m2m, u16_rdn_sat, 1x2) (d);
  d = FN(mclear_m, u16_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rdn_sat, 1x4) group = FN(mconcat_m, u16_rdn_sat, 1x4) (copy, copy);
  TYPE(u16_rdn_sat, 1x2) half = FN(mextract, u16_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_26_1 (void)
{
  TYPE(i16_rod, 2x1) s = FN(mzero_m, i16_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u16_rdn_sat, 2x1) d = FN(mconv_ew, u16_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, u16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 2x1) back = FN(mconv_ew, i16_rod, 2x1) (d);
  TYPE(u16_rdn_sat, 2x1) copy = FN(mcopy_m2m, u16_rdn_sat, 2x1) (d);
  d = FN(mclear_m, u16_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rdn_sat, 4x1) group = FN(mconcat_m, u16_rdn_sat, 4x1) (copy, copy);
  TYPE(u16_rdn_sat, 2x1) half = FN(mextract, u16_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_26_2 (void)
{
  TYPE(u16_rdn_sat, 1x2) m = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx2) a = FN(mcopy_m2a, u16_rdn_sat, accx2) (m);
  TYPE(u16_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x2) result = FN(mcopy_a2m, u16_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx2) ();
  TYPE(u16_rdn_sat, accx2) zero = FN(mzero_acc, u16_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_26_4 (void)
{
  TYPE(u16_rdn_sat, 1x4) m = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx4) a = FN(mcopy_m2a, u16_rdn_sat, accx4) (m);
  TYPE(u16_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x4) result = FN(mcopy_a2m, u16_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx4) ();
  TYPE(u16_rdn_sat, accx4) zero = FN(mzero_acc, u16_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_26_8 (void)
{
  TYPE(u16_rdn_sat, 1x8) m = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx8) a = FN(mcopy_m2a, u16_rdn_sat, accx8) (m);
  TYPE(u16_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x8) result = FN(mcopy_a2m, u16_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx8) ();
  TYPE(u16_rdn_sat, accx8) zero = FN(mzero_acc, u16_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_27_0 (void)
{
  TYPE(i16_rod, 1x2) s = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u16_rod_sat, 1x2) d = FN(mconv_ew, u16_rod_sat, 1x2) (s);
  d = FN(mabs_ew, u16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x2) back = FN(mconv_ew, i16_rod, 1x2) (d);
  TYPE(u16_rod_sat, 1x2) copy = FN(mcopy_m2m, u16_rod_sat, 1x2) (d);
  d = FN(mclear_m, u16_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rod_sat, 1x4) group = FN(mconcat_m, u16_rod_sat, 1x4) (copy, copy);
  TYPE(u16_rod_sat, 1x2) half = FN(mextract, u16_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_27_1 (void)
{
  TYPE(i16_rod, 2x1) s = FN(mzero_m, i16_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u16_rod_sat, 2x1) d = FN(mconv_ew, u16_rod_sat, 2x1) (s);
  d = FN(mabs_ew, u16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 2x1) back = FN(mconv_ew, i16_rod, 2x1) (d);
  TYPE(u16_rod_sat, 2x1) copy = FN(mcopy_m2m, u16_rod_sat, 2x1) (d);
  d = FN(mclear_m, u16_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rod_sat, 4x1) group = FN(mconcat_m, u16_rod_sat, 4x1) (copy, copy);
  TYPE(u16_rod_sat, 2x1) half = FN(mextract, u16_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_27_2 (void)
{
  TYPE(u16_rod_sat, 1x2) m = FN(mzero_m, u16_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx2) a = FN(mcopy_m2a, u16_rod_sat, accx2) (m);
  TYPE(u16_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x2) result = FN(mcopy_a2m, u16_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx2) ();
  TYPE(u16_rod_sat, accx2) zero = FN(mzero_acc, u16_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_27_4 (void)
{
  TYPE(u16_rod_sat, 1x4) m = FN(mzero_m, u16_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx4) a = FN(mcopy_m2a, u16_rod_sat, accx4) (m);
  TYPE(u16_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x4) result = FN(mcopy_a2m, u16_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx4) ();
  TYPE(u16_rod_sat, accx4) zero = FN(mzero_acc, u16_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_27_8 (void)
{
  TYPE(u16_rod_sat, 1x8) m = FN(mzero_m, u16_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx8) a = FN(mcopy_m2a, u16_rod_sat, accx8) (m);
  TYPE(u16_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x8) result = FN(mcopy_a2m, u16_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx8) ();
  TYPE(u16_rod_sat, accx8) zero = FN(mzero_acc, u16_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_28_0 (void)
{
  TYPE(u16_rod, 1x2) s = FN(mzero_m, u16_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i16_rnu_sat, 1x2) d = FN(mconv_ew, i16_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, i16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x2) back = FN(mconv_ew, u16_rod, 1x2) (d);
  TYPE(i16_rnu_sat, 1x2) copy = FN(mcopy_m2m, i16_rnu_sat, 1x2) (d);
  d = FN(mclear_m, i16_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rnu_sat, 1x4) group = FN(mconcat_m, i16_rnu_sat, 1x4) (copy, copy);
  TYPE(i16_rnu_sat, 1x2) half = FN(mextract, i16_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_28_1 (void)
{
  TYPE(u16_rod, 2x1) s = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i16_rnu_sat, 2x1) d = FN(mconv_ew, i16_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, i16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 2x1) back = FN(mconv_ew, u16_rod, 2x1) (d);
  TYPE(i16_rnu_sat, 2x1) copy = FN(mcopy_m2m, i16_rnu_sat, 2x1) (d);
  d = FN(mclear_m, i16_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rnu_sat, 4x1) group = FN(mconcat_m, i16_rnu_sat, 4x1) (copy, copy);
  TYPE(i16_rnu_sat, 2x1) half = FN(mextract, i16_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_28_2 (void)
{
  TYPE(i16_rnu_sat, 1x2) m = FN(mzero_m, i16_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx2) a = FN(mcopy_m2a, i16_rnu_sat, accx2) (m);
  TYPE(i16_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x2) result = FN(mcopy_a2m, i16_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx2) ();
  TYPE(i16_rnu_sat, accx2) zero = FN(mzero_acc, i16_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_28_4 (void)
{
  TYPE(i16_rnu_sat, 1x4) m = FN(mzero_m, i16_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx4) a = FN(mcopy_m2a, i16_rnu_sat, accx4) (m);
  TYPE(i16_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x4) result = FN(mcopy_a2m, i16_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx4) ();
  TYPE(i16_rnu_sat, accx4) zero = FN(mzero_acc, i16_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_28_8 (void)
{
  TYPE(i16_rnu_sat, 1x8) m = FN(mzero_m, i16_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx8) a = FN(mcopy_m2a, i16_rnu_sat, accx8) (m);
  TYPE(i16_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x8) result = FN(mcopy_a2m, i16_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx8) ();
  TYPE(i16_rnu_sat, accx8) zero = FN(mzero_acc, i16_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_29_0 (void)
{
  TYPE(u16_rod, 1x2) s = FN(mzero_m, u16_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i16_rne_sat, 1x2) d = FN(mconv_ew, i16_rne_sat, 1x2) (s);
  d = FN(mabs_ew, i16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x2) back = FN(mconv_ew, u16_rod, 1x2) (d);
  TYPE(i16_rne_sat, 1x2) copy = FN(mcopy_m2m, i16_rne_sat, 1x2) (d);
  d = FN(mclear_m, i16_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rne_sat, 1x4) group = FN(mconcat_m, i16_rne_sat, 1x4) (copy, copy);
  TYPE(i16_rne_sat, 1x2) half = FN(mextract, i16_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_29_1 (void)
{
  TYPE(u16_rod, 2x1) s = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i16_rne_sat, 2x1) d = FN(mconv_ew, i16_rne_sat, 2x1) (s);
  d = FN(mabs_ew, i16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 2x1) back = FN(mconv_ew, u16_rod, 2x1) (d);
  TYPE(i16_rne_sat, 2x1) copy = FN(mcopy_m2m, i16_rne_sat, 2x1) (d);
  d = FN(mclear_m, i16_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rne_sat, 4x1) group = FN(mconcat_m, i16_rne_sat, 4x1) (copy, copy);
  TYPE(i16_rne_sat, 2x1) half = FN(mextract, i16_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_29_2 (void)
{
  TYPE(i16_rne_sat, 1x2) m = FN(mzero_m, i16_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx2) a = FN(mcopy_m2a, i16_rne_sat, accx2) (m);
  TYPE(i16_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x2) result = FN(mcopy_a2m, i16_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx2) ();
  TYPE(i16_rne_sat, accx2) zero = FN(mzero_acc, i16_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_29_4 (void)
{
  TYPE(i16_rne_sat, 1x4) m = FN(mzero_m, i16_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx4) a = FN(mcopy_m2a, i16_rne_sat, accx4) (m);
  TYPE(i16_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x4) result = FN(mcopy_a2m, i16_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx4) ();
  TYPE(i16_rne_sat, accx4) zero = FN(mzero_acc, i16_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_29_8 (void)
{
  TYPE(i16_rne_sat, 1x8) m = FN(mzero_m, i16_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx8) a = FN(mcopy_m2a, i16_rne_sat, accx8) (m);
  TYPE(i16_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x8) result = FN(mcopy_a2m, i16_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx8) ();
  TYPE(i16_rne_sat, accx8) zero = FN(mzero_acc, i16_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_30_0 (void)
{
  TYPE(u16_rod, 1x2) s = FN(mzero_m, u16_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i16_rdn_sat, 1x2) d = FN(mconv_ew, i16_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, i16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x2) back = FN(mconv_ew, u16_rod, 1x2) (d);
  TYPE(i16_rdn_sat, 1x2) copy = FN(mcopy_m2m, i16_rdn_sat, 1x2) (d);
  d = FN(mclear_m, i16_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rdn_sat, 1x4) group = FN(mconcat_m, i16_rdn_sat, 1x4) (copy, copy);
  TYPE(i16_rdn_sat, 1x2) half = FN(mextract, i16_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_30_1 (void)
{
  TYPE(u16_rod, 2x1) s = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i16_rdn_sat, 2x1) d = FN(mconv_ew, i16_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, i16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 2x1) back = FN(mconv_ew, u16_rod, 2x1) (d);
  TYPE(i16_rdn_sat, 2x1) copy = FN(mcopy_m2m, i16_rdn_sat, 2x1) (d);
  d = FN(mclear_m, i16_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rdn_sat, 4x1) group = FN(mconcat_m, i16_rdn_sat, 4x1) (copy, copy);
  TYPE(i16_rdn_sat, 2x1) half = FN(mextract, i16_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_30_2 (void)
{
  TYPE(i16_rdn_sat, 1x2) m = FN(mzero_m, i16_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx2) a = FN(mcopy_m2a, i16_rdn_sat, accx2) (m);
  TYPE(i16_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x2) result = FN(mcopy_a2m, i16_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx2) ();
  TYPE(i16_rdn_sat, accx2) zero = FN(mzero_acc, i16_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_30_4 (void)
{
  TYPE(i16_rdn_sat, 1x4) m = FN(mzero_m, i16_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx4) a = FN(mcopy_m2a, i16_rdn_sat, accx4) (m);
  TYPE(i16_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x4) result = FN(mcopy_a2m, i16_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx4) ();
  TYPE(i16_rdn_sat, accx4) zero = FN(mzero_acc, i16_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_30_8 (void)
{
  TYPE(i16_rdn_sat, 1x8) m = FN(mzero_m, i16_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx8) a = FN(mcopy_m2a, i16_rdn_sat, accx8) (m);
  TYPE(i16_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x8) result = FN(mcopy_a2m, i16_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx8) ();
  TYPE(i16_rdn_sat, accx8) zero = FN(mzero_acc, i16_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_31_0 (void)
{
  TYPE(u16_rod, 1x2) s = FN(mzero_m, u16_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i16_rod_sat, 1x2) d = FN(mconv_ew, i16_rod_sat, 1x2) (s);
  d = FN(mabs_ew, i16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x2) back = FN(mconv_ew, u16_rod, 1x2) (d);
  TYPE(i16_rod_sat, 1x2) copy = FN(mcopy_m2m, i16_rod_sat, 1x2) (d);
  d = FN(mclear_m, i16_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rod_sat, 1x4) group = FN(mconcat_m, i16_rod_sat, 1x4) (copy, copy);
  TYPE(i16_rod_sat, 1x2) half = FN(mextract, i16_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_31_1 (void)
{
  TYPE(u16_rod, 2x1) s = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i16_rod_sat, 2x1) d = FN(mconv_ew, i16_rod_sat, 2x1) (s);
  d = FN(mabs_ew, i16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 2x1) back = FN(mconv_ew, u16_rod, 2x1) (d);
  TYPE(i16_rod_sat, 2x1) copy = FN(mcopy_m2m, i16_rod_sat, 2x1) (d);
  d = FN(mclear_m, i16_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rod_sat, 4x1) group = FN(mconcat_m, i16_rod_sat, 4x1) (copy, copy);
  TYPE(i16_rod_sat, 2x1) half = FN(mextract, i16_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_31_2 (void)
{
  TYPE(i16_rod_sat, 1x2) m = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx2) a = FN(mcopy_m2a, i16_rod_sat, accx2) (m);
  TYPE(i16_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x2) result = FN(mcopy_a2m, i16_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx2) ();
  TYPE(i16_rod_sat, accx2) zero = FN(mzero_acc, i16_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_31_4 (void)
{
  TYPE(i16_rod_sat, 1x4) m = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx4) a = FN(mcopy_m2a, i16_rod_sat, accx4) (m);
  TYPE(i16_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x4) result = FN(mcopy_a2m, i16_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx4) ();
  TYPE(i16_rod_sat, accx4) zero = FN(mzero_acc, i16_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_31_8 (void)
{
  TYPE(i16_rod_sat, 1x8) m = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx8) a = FN(mcopy_m2a, i16_rod_sat, accx8) (m);
  TYPE(i16_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x8) result = FN(mcopy_a2m, i16_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx8) ();
  TYPE(i16_rod_sat, accx8) zero = FN(mzero_acc, i16_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_32_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rnu_sat, 1x1) d = FN(mconv_ew, u32_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rnu_sat, 1x1) copy = FN(mcopy_m2m, u32_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u32_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rnu_sat, 1x2) group = FN(mconcat_m, u32_rnu_sat, 1x2) (copy, copy);
  TYPE(u32_rnu_sat, 1x1) half = FN(mextract, u32_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_32_1 (void)
{
  TYPE(u32_rnu_sat, 1x1) m = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx1) a = FN(mcopy_m2a, u32_rnu_sat, accx1) (m);
  TYPE(u32_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x1) result = FN(mcopy_a2m, u32_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx1) ();
  TYPE(u32_rnu_sat, accx1) zero = FN(mzero_acc, u32_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_32_2 (void)
{
  TYPE(u32_rnu_sat, 1x2) m = FN(mzero_m, u32_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx2) a = FN(mcopy_m2a, u32_rnu_sat, accx2) (m);
  TYPE(u32_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x2) result = FN(mcopy_a2m, u32_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx2) ();
  TYPE(u32_rnu_sat, accx2) zero = FN(mzero_acc, u32_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_32_4 (void)
{
  TYPE(u32_rnu_sat, 1x4) m = FN(mzero_m, u32_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx4) a = FN(mcopy_m2a, u32_rnu_sat, accx4) (m);
  TYPE(u32_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x4) result = FN(mcopy_a2m, u32_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx4) ();
  TYPE(u32_rnu_sat, accx4) zero = FN(mzero_acc, u32_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_33_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rne_sat, 1x1) d = FN(mconv_ew, u32_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rne_sat, 1x1) copy = FN(mcopy_m2m, u32_rne_sat, 1x1) (d);
  d = FN(mclear_m, u32_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rne_sat, 1x2) group = FN(mconcat_m, u32_rne_sat, 1x2) (copy, copy);
  TYPE(u32_rne_sat, 1x1) half = FN(mextract, u32_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_33_1 (void)
{
  TYPE(u32_rne_sat, 1x1) m = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx1) a = FN(mcopy_m2a, u32_rne_sat, accx1) (m);
  TYPE(u32_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x1) result = FN(mcopy_a2m, u32_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx1) ();
  TYPE(u32_rne_sat, accx1) zero = FN(mzero_acc, u32_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_33_2 (void)
{
  TYPE(u32_rne_sat, 1x2) m = FN(mzero_m, u32_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx2) a = FN(mcopy_m2a, u32_rne_sat, accx2) (m);
  TYPE(u32_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x2) result = FN(mcopy_a2m, u32_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx2) ();
  TYPE(u32_rne_sat, accx2) zero = FN(mzero_acc, u32_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_33_4 (void)
{
  TYPE(u32_rne_sat, 1x4) m = FN(mzero_m, u32_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx4) a = FN(mcopy_m2a, u32_rne_sat, accx4) (m);
  TYPE(u32_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x4) result = FN(mcopy_a2m, u32_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx4) ();
  TYPE(u32_rne_sat, accx4) zero = FN(mzero_acc, u32_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_34_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rdn_sat, 1x1) d = FN(mconv_ew, u32_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rdn_sat, 1x1) copy = FN(mcopy_m2m, u32_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u32_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rdn_sat, 1x2) group = FN(mconcat_m, u32_rdn_sat, 1x2) (copy, copy);
  TYPE(u32_rdn_sat, 1x1) half = FN(mextract, u32_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_34_1 (void)
{
  TYPE(u32_rdn_sat, 1x1) m = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx1) a = FN(mcopy_m2a, u32_rdn_sat, accx1) (m);
  TYPE(u32_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x1) result = FN(mcopy_a2m, u32_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx1) ();
  TYPE(u32_rdn_sat, accx1) zero = FN(mzero_acc, u32_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_34_2 (void)
{
  TYPE(u32_rdn_sat, 1x2) m = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx2) a = FN(mcopy_m2a, u32_rdn_sat, accx2) (m);
  TYPE(u32_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x2) result = FN(mcopy_a2m, u32_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx2) ();
  TYPE(u32_rdn_sat, accx2) zero = FN(mzero_acc, u32_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_34_4 (void)
{
  TYPE(u32_rdn_sat, 1x4) m = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx4) a = FN(mcopy_m2a, u32_rdn_sat, accx4) (m);
  TYPE(u32_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x4) result = FN(mcopy_a2m, u32_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx4) ();
  TYPE(u32_rdn_sat, accx4) zero = FN(mzero_acc, u32_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_35_0 (void)
{
  TYPE(i32_rod, 1x1) s = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u32_rod_sat, 1x1) d = FN(mconv_ew, u32_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x1) back = FN(mconv_ew, i32_rod, 1x1) (d);
  TYPE(u32_rod_sat, 1x1) copy = FN(mcopy_m2m, u32_rod_sat, 1x1) (d);
  d = FN(mclear_m, u32_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rod_sat, 1x2) group = FN(mconcat_m, u32_rod_sat, 1x2) (copy, copy);
  TYPE(u32_rod_sat, 1x1) half = FN(mextract, u32_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_35_1 (void)
{
  TYPE(u32_rod_sat, 1x1) m = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx1) a = FN(mcopy_m2a, u32_rod_sat, accx1) (m);
  TYPE(u32_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x1) result = FN(mcopy_a2m, u32_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx1) ();
  TYPE(u32_rod_sat, accx1) zero = FN(mzero_acc, u32_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_35_2 (void)
{
  TYPE(u32_rod_sat, 1x2) m = FN(mzero_m, u32_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx2) a = FN(mcopy_m2a, u32_rod_sat, accx2) (m);
  TYPE(u32_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x2) result = FN(mcopy_a2m, u32_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx2) ();
  TYPE(u32_rod_sat, accx2) zero = FN(mzero_acc, u32_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_35_4 (void)
{
  TYPE(u32_rod_sat, 1x4) m = FN(mzero_m, u32_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx4) a = FN(mcopy_m2a, u32_rod_sat, accx4) (m);
  TYPE(u32_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x4) result = FN(mcopy_a2m, u32_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx4) ();
  TYPE(u32_rod_sat, accx4) zero = FN(mzero_acc, u32_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_36_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rnu_sat, 1x1) d = FN(mconv_ew, i32_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rnu_sat, 1x1) copy = FN(mcopy_m2m, i32_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i32_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rnu_sat, 1x2) group = FN(mconcat_m, i32_rnu_sat, 1x2) (copy, copy);
  TYPE(i32_rnu_sat, 1x1) half = FN(mextract, i32_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_36_1 (void)
{
  TYPE(i32_rnu_sat, 1x1) m = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx1) a = FN(mcopy_m2a, i32_rnu_sat, accx1) (m);
  TYPE(i32_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x1) result = FN(mcopy_a2m, i32_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx1) ();
  TYPE(i32_rnu_sat, accx1) zero = FN(mzero_acc, i32_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_36_2 (void)
{
  TYPE(i32_rnu_sat, 1x2) m = FN(mzero_m, i32_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx2) a = FN(mcopy_m2a, i32_rnu_sat, accx2) (m);
  TYPE(i32_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x2) result = FN(mcopy_a2m, i32_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx2) ();
  TYPE(i32_rnu_sat, accx2) zero = FN(mzero_acc, i32_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_36_4 (void)
{
  TYPE(i32_rnu_sat, 1x4) m = FN(mzero_m, i32_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx4) a = FN(mcopy_m2a, i32_rnu_sat, accx4) (m);
  TYPE(i32_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x4) result = FN(mcopy_a2m, i32_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx4) ();
  TYPE(i32_rnu_sat, accx4) zero = FN(mzero_acc, i32_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_37_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rne_sat, 1x1) d = FN(mconv_ew, i32_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rne_sat, 1x1) copy = FN(mcopy_m2m, i32_rne_sat, 1x1) (d);
  d = FN(mclear_m, i32_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rne_sat, 1x2) group = FN(mconcat_m, i32_rne_sat, 1x2) (copy, copy);
  TYPE(i32_rne_sat, 1x1) half = FN(mextract, i32_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_37_1 (void)
{
  TYPE(i32_rne_sat, 1x1) m = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx1) a = FN(mcopy_m2a, i32_rne_sat, accx1) (m);
  TYPE(i32_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x1) result = FN(mcopy_a2m, i32_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx1) ();
  TYPE(i32_rne_sat, accx1) zero = FN(mzero_acc, i32_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_37_2 (void)
{
  TYPE(i32_rne_sat, 1x2) m = FN(mzero_m, i32_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx2) a = FN(mcopy_m2a, i32_rne_sat, accx2) (m);
  TYPE(i32_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x2) result = FN(mcopy_a2m, i32_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx2) ();
  TYPE(i32_rne_sat, accx2) zero = FN(mzero_acc, i32_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_37_4 (void)
{
  TYPE(i32_rne_sat, 1x4) m = FN(mzero_m, i32_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx4) a = FN(mcopy_m2a, i32_rne_sat, accx4) (m);
  TYPE(i32_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x4) result = FN(mcopy_a2m, i32_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx4) ();
  TYPE(i32_rne_sat, accx4) zero = FN(mzero_acc, i32_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_38_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rdn_sat, 1x1) d = FN(mconv_ew, i32_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rdn_sat, 1x1) copy = FN(mcopy_m2m, i32_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i32_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rdn_sat, 1x2) group = FN(mconcat_m, i32_rdn_sat, 1x2) (copy, copy);
  TYPE(i32_rdn_sat, 1x1) half = FN(mextract, i32_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_38_1 (void)
{
  TYPE(i32_rdn_sat, 1x1) m = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx1) a = FN(mcopy_m2a, i32_rdn_sat, accx1) (m);
  TYPE(i32_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x1) result = FN(mcopy_a2m, i32_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx1) ();
  TYPE(i32_rdn_sat, accx1) zero = FN(mzero_acc, i32_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_38_2 (void)
{
  TYPE(i32_rdn_sat, 1x2) m = FN(mzero_m, i32_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx2) a = FN(mcopy_m2a, i32_rdn_sat, accx2) (m);
  TYPE(i32_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x2) result = FN(mcopy_a2m, i32_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx2) ();
  TYPE(i32_rdn_sat, accx2) zero = FN(mzero_acc, i32_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_38_4 (void)
{
  TYPE(i32_rdn_sat, 1x4) m = FN(mzero_m, i32_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx4) a = FN(mcopy_m2a, i32_rdn_sat, accx4) (m);
  TYPE(i32_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x4) result = FN(mcopy_a2m, i32_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx4) ();
  TYPE(i32_rdn_sat, accx4) zero = FN(mzero_acc, i32_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_39_0 (void)
{
  TYPE(u32_rod, 1x1) s = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i32_rod_sat, 1x1) d = FN(mconv_ew, i32_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x1) back = FN(mconv_ew, u32_rod, 1x1) (d);
  TYPE(i32_rod_sat, 1x1) copy = FN(mcopy_m2m, i32_rod_sat, 1x1) (d);
  d = FN(mclear_m, i32_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rod_sat, 1x2) group = FN(mconcat_m, i32_rod_sat, 1x2) (copy, copy);
  TYPE(i32_rod_sat, 1x1) half = FN(mextract, i32_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_39_1 (void)
{
  TYPE(i32_rod_sat, 1x1) m = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx1) a = FN(mcopy_m2a, i32_rod_sat, accx1) (m);
  TYPE(i32_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x1) result = FN(mcopy_a2m, i32_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx1) ();
  TYPE(i32_rod_sat, accx1) zero = FN(mzero_acc, i32_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_39_2 (void)
{
  TYPE(i32_rod_sat, 1x2) m = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx2) a = FN(mcopy_m2a, i32_rod_sat, accx2) (m);
  TYPE(i32_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x2) result = FN(mcopy_a2m, i32_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx2) ();
  TYPE(i32_rod_sat, accx2) zero = FN(mzero_acc, i32_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_39_4 (void)
{
  TYPE(i32_rod_sat, 1x4) m = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx4) a = FN(mcopy_m2a, i32_rod_sat, accx4) (m);
  TYPE(i32_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x4) result = FN(mcopy_a2m, i32_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx4) ();
  TYPE(i32_rod_sat, accx4) zero = FN(mzero_acc, i32_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_40_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rnu_sat, 1x1) d = FN(mconv_ew, u64_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rnu_sat, 1x1) copy = FN(mcopy_m2m, u64_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u64_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rnu_sat, 1x2) group = FN(mconcat_m, u64_rnu_sat, 1x2) (copy, copy);
  TYPE(u64_rnu_sat, 1x1) half = FN(mextract, u64_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_40_1 (void)
{
  TYPE(u64_rnu_sat, 1x1) m = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rnu_sat, accx1) a = FN(mcopy_m2a, u64_rnu_sat, accx1) (m);
  TYPE(u64_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rnu_sat, 1x1) result = FN(mcopy_a2m, u64_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rnu_sat, accx1) ();
  TYPE(u64_rnu_sat, accx1) zero = FN(mzero_acc, u64_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_40_2 (void)
{
  TYPE(u64_rnu_sat, 1x2) m = FN(mzero_m, u64_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rnu_sat, accx2) a = FN(mcopy_m2a, u64_rnu_sat, accx2) (m);
  TYPE(u64_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rnu_sat, 1x2) result = FN(mcopy_a2m, u64_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rnu_sat, accx2) ();
  TYPE(u64_rnu_sat, accx2) zero = FN(mzero_acc, u64_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_41_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rne_sat, 1x1) d = FN(mconv_ew, u64_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rne_sat, 1x1) copy = FN(mcopy_m2m, u64_rne_sat, 1x1) (d);
  d = FN(mclear_m, u64_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rne_sat, 1x2) group = FN(mconcat_m, u64_rne_sat, 1x2) (copy, copy);
  TYPE(u64_rne_sat, 1x1) half = FN(mextract, u64_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_41_1 (void)
{
  TYPE(u64_rne_sat, 1x1) m = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rne_sat, accx1) a = FN(mcopy_m2a, u64_rne_sat, accx1) (m);
  TYPE(u64_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rne_sat, 1x1) result = FN(mcopy_a2m, u64_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rne_sat, accx1) ();
  TYPE(u64_rne_sat, accx1) zero = FN(mzero_acc, u64_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_41_2 (void)
{
  TYPE(u64_rne_sat, 1x2) m = FN(mzero_m, u64_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rne_sat, accx2) a = FN(mcopy_m2a, u64_rne_sat, accx2) (m);
  TYPE(u64_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rne_sat, 1x2) result = FN(mcopy_a2m, u64_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rne_sat, accx2) ();
  TYPE(u64_rne_sat, accx2) zero = FN(mzero_acc, u64_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_42_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rdn_sat, 1x1) d = FN(mconv_ew, u64_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rdn_sat, 1x1) copy = FN(mcopy_m2m, u64_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u64_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rdn_sat, 1x2) group = FN(mconcat_m, u64_rdn_sat, 1x2) (copy, copy);
  TYPE(u64_rdn_sat, 1x1) half = FN(mextract, u64_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_42_1 (void)
{
  TYPE(u64_rdn_sat, 1x1) m = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rdn_sat, accx1) a = FN(mcopy_m2a, u64_rdn_sat, accx1) (m);
  TYPE(u64_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rdn_sat, 1x1) result = FN(mcopy_a2m, u64_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rdn_sat, accx1) ();
  TYPE(u64_rdn_sat, accx1) zero = FN(mzero_acc, u64_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_42_2 (void)
{
  TYPE(u64_rdn_sat, 1x2) m = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rdn_sat, accx2) a = FN(mcopy_m2a, u64_rdn_sat, accx2) (m);
  TYPE(u64_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rdn_sat, 1x2) result = FN(mcopy_a2m, u64_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rdn_sat, accx2) ();
  TYPE(u64_rdn_sat, accx2) zero = FN(mzero_acc, u64_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_43_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rod_sat, 1x1) d = FN(mconv_ew, u64_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rod_sat, 1x1) copy = FN(mcopy_m2m, u64_rod_sat, 1x1) (d);
  d = FN(mclear_m, u64_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rod_sat, 1x2) group = FN(mconcat_m, u64_rod_sat, 1x2) (copy, copy);
  TYPE(u64_rod_sat, 1x1) half = FN(mextract, u64_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_43_1 (void)
{
  TYPE(u64_rod_sat, 1x1) m = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rod_sat, accx1) a = FN(mcopy_m2a, u64_rod_sat, accx1) (m);
  TYPE(u64_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rod_sat, 1x1) result = FN(mcopy_a2m, u64_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rod_sat, accx1) ();
  TYPE(u64_rod_sat, accx1) zero = FN(mzero_acc, u64_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_43_2 (void)
{
  TYPE(u64_rod_sat, 1x2) m = FN(mzero_m, u64_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rod_sat, accx2) a = FN(mcopy_m2a, u64_rod_sat, accx2) (m);
  TYPE(u64_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rod_sat, 1x2) result = FN(mcopy_a2m, u64_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rod_sat, accx2) ();
  TYPE(u64_rod_sat, accx2) zero = FN(mzero_acc, u64_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_44_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rnu_sat, 1x1) d = FN(mconv_ew, i64_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rnu_sat, 1x1) copy = FN(mcopy_m2m, i64_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i64_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rnu_sat, 1x2) group = FN(mconcat_m, i64_rnu_sat, 1x2) (copy, copy);
  TYPE(i64_rnu_sat, 1x1) half = FN(mextract, i64_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_44_1 (void)
{
  TYPE(i64_rnu_sat, 1x1) m = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rnu_sat, accx1) a = FN(mcopy_m2a, i64_rnu_sat, accx1) (m);
  TYPE(i64_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rnu_sat, 1x1) result = FN(mcopy_a2m, i64_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rnu_sat, accx1) ();
  TYPE(i64_rnu_sat, accx1) zero = FN(mzero_acc, i64_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_44_2 (void)
{
  TYPE(i64_rnu_sat, 1x2) m = FN(mzero_m, i64_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rnu_sat, accx2) a = FN(mcopy_m2a, i64_rnu_sat, accx2) (m);
  TYPE(i64_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rnu_sat, 1x2) result = FN(mcopy_a2m, i64_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rnu_sat, accx2) ();
  TYPE(i64_rnu_sat, accx2) zero = FN(mzero_acc, i64_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_45_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rne_sat, 1x1) d = FN(mconv_ew, i64_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rne_sat, 1x1) copy = FN(mcopy_m2m, i64_rne_sat, 1x1) (d);
  d = FN(mclear_m, i64_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rne_sat, 1x2) group = FN(mconcat_m, i64_rne_sat, 1x2) (copy, copy);
  TYPE(i64_rne_sat, 1x1) half = FN(mextract, i64_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_45_1 (void)
{
  TYPE(i64_rne_sat, 1x1) m = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rne_sat, accx1) a = FN(mcopy_m2a, i64_rne_sat, accx1) (m);
  TYPE(i64_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rne_sat, 1x1) result = FN(mcopy_a2m, i64_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rne_sat, accx1) ();
  TYPE(i64_rne_sat, accx1) zero = FN(mzero_acc, i64_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_45_2 (void)
{
  TYPE(i64_rne_sat, 1x2) m = FN(mzero_m, i64_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rne_sat, accx2) a = FN(mcopy_m2a, i64_rne_sat, accx2) (m);
  TYPE(i64_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rne_sat, 1x2) result = FN(mcopy_a2m, i64_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rne_sat, accx2) ();
  TYPE(i64_rne_sat, accx2) zero = FN(mzero_acc, i64_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_46_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rdn_sat, 1x1) d = FN(mconv_ew, i64_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rdn_sat, 1x1) copy = FN(mcopy_m2m, i64_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i64_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rdn_sat, 1x2) group = FN(mconcat_m, i64_rdn_sat, 1x2) (copy, copy);
  TYPE(i64_rdn_sat, 1x1) half = FN(mextract, i64_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_46_1 (void)
{
  TYPE(i64_rdn_sat, 1x1) m = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rdn_sat, accx1) a = FN(mcopy_m2a, i64_rdn_sat, accx1) (m);
  TYPE(i64_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rdn_sat, 1x1) result = FN(mcopy_a2m, i64_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rdn_sat, accx1) ();
  TYPE(i64_rdn_sat, accx1) zero = FN(mzero_acc, i64_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_46_2 (void)
{
  TYPE(i64_rdn_sat, 1x2) m = FN(mzero_m, i64_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rdn_sat, accx2) a = FN(mcopy_m2a, i64_rdn_sat, accx2) (m);
  TYPE(i64_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rdn_sat, 1x2) result = FN(mcopy_a2m, i64_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rdn_sat, accx2) ();
  TYPE(i64_rdn_sat, accx2) zero = FN(mzero_acc, i64_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_47_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rod_sat, 1x1) d = FN(mconv_ew, i64_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rod_sat, 1x1) copy = FN(mcopy_m2m, i64_rod_sat, 1x1) (d);
  d = FN(mclear_m, i64_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rod_sat, 1x2) group = FN(mconcat_m, i64_rod_sat, 1x2) (copy, copy);
  TYPE(i64_rod_sat, 1x1) half = FN(mextract, i64_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_47_1 (void)
{
  TYPE(i64_rod_sat, 1x1) m = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rod_sat, accx1) a = FN(mcopy_m2a, i64_rod_sat, accx1) (m);
  TYPE(i64_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rod_sat, 1x1) result = FN(mcopy_a2m, i64_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rod_sat, accx1) ();
  TYPE(i64_rod_sat, accx1) zero = FN(mzero_acc, i64_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_47_2 (void)
{
  TYPE(i64_rod_sat, 1x2) m = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rod_sat, accx2) a = FN(mcopy_m2a, i64_rod_sat, accx2) (m);
  TYPE(i64_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rod_sat, 1x2) result = FN(mcopy_a2m, i64_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rod_sat, accx2) ();
  TYPE(i64_rod_sat, accx2) zero = FN(mzero_acc, i64_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_48_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rnu_sat, 1x1) d = FN(mconv_ew, u128_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rnu_sat, 1x1) copy = FN(mcopy_m2m, u128_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u128_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_48_1 (void)
{
  TYPE(u128_rnu_sat, 1x1) m = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rnu_sat, accx1) a = FN(mcopy_m2a, u128_rnu_sat, accx1) (m);
  TYPE(u128_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rnu_sat, 1x1) result = FN(mcopy_a2m, u128_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rnu_sat, accx1) ();
  TYPE(u128_rnu_sat, accx1) zero = FN(mzero_acc, u128_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_49_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rne_sat, 1x1) d = FN(mconv_ew, u128_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rne_sat, 1x1) copy = FN(mcopy_m2m, u128_rne_sat, 1x1) (d);
  d = FN(mclear_m, u128_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_49_1 (void)
{
  TYPE(u128_rne_sat, 1x1) m = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rne_sat, accx1) a = FN(mcopy_m2a, u128_rne_sat, accx1) (m);
  TYPE(u128_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rne_sat, 1x1) result = FN(mcopy_a2m, u128_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rne_sat, accx1) ();
  TYPE(u128_rne_sat, accx1) zero = FN(mzero_acc, u128_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_50_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rdn_sat, 1x1) d = FN(mconv_ew, u128_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rdn_sat, 1x1) copy = FN(mcopy_m2m, u128_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u128_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_50_1 (void)
{
  TYPE(u128_rdn_sat, 1x1) m = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rdn_sat, accx1) a = FN(mcopy_m2a, u128_rdn_sat, accx1) (m);
  TYPE(u128_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rdn_sat, 1x1) result = FN(mcopy_a2m, u128_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rdn_sat, accx1) ();
  TYPE(u128_rdn_sat, accx1) zero = FN(mzero_acc, u128_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_51_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rod_sat, 1x1) d = FN(mconv_ew, u128_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rod_sat, 1x1) copy = FN(mcopy_m2m, u128_rod_sat, 1x1) (d);
  d = FN(mclear_m, u128_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_51_1 (void)
{
  TYPE(u128_rod_sat, 1x1) m = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rod_sat, accx1) a = FN(mcopy_m2a, u128_rod_sat, accx1) (m);
  TYPE(u128_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rod_sat, 1x1) result = FN(mcopy_a2m, u128_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rod_sat, accx1) ();
  TYPE(u128_rod_sat, accx1) zero = FN(mzero_acc, u128_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_52_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rnu_sat, 1x1) d = FN(mconv_ew, i128_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rnu_sat, 1x1) copy = FN(mcopy_m2m, i128_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i128_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_52_1 (void)
{
  TYPE(i128_rnu_sat, 1x1) m = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rnu_sat, accx1) a = FN(mcopy_m2a, i128_rnu_sat, accx1) (m);
  TYPE(i128_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rnu_sat, 1x1) result = FN(mcopy_a2m, i128_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rnu_sat, accx1) ();
  TYPE(i128_rnu_sat, accx1) zero = FN(mzero_acc, i128_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_53_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rne_sat, 1x1) d = FN(mconv_ew, i128_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rne_sat, 1x1) copy = FN(mcopy_m2m, i128_rne_sat, 1x1) (d);
  d = FN(mclear_m, i128_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_53_1 (void)
{
  TYPE(i128_rne_sat, 1x1) m = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rne_sat, accx1) a = FN(mcopy_m2a, i128_rne_sat, accx1) (m);
  TYPE(i128_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rne_sat, 1x1) result = FN(mcopy_a2m, i128_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rne_sat, accx1) ();
  TYPE(i128_rne_sat, accx1) zero = FN(mzero_acc, i128_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_54_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rdn_sat, 1x1) d = FN(mconv_ew, i128_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rdn_sat, 1x1) copy = FN(mcopy_m2m, i128_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i128_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_54_1 (void)
{
  TYPE(i128_rdn_sat, 1x1) m = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rdn_sat, accx1) a = FN(mcopy_m2a, i128_rdn_sat, accx1) (m);
  TYPE(i128_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rdn_sat, 1x1) result = FN(mcopy_a2m, i128_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rdn_sat, accx1) ();
  TYPE(i128_rdn_sat, accx1) zero = FN(mzero_acc, i128_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_55_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rod_sat, 1x1) d = FN(mconv_ew, i128_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rod_sat, 1x1) copy = FN(mcopy_m2m, i128_rod_sat, 1x1) (d);
  d = FN(mclear_m, i128_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void acc_55_1 (void)
{
  TYPE(i128_rod_sat, 1x1) m = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rod_sat, accx1) a = FN(mcopy_m2a, i128_rod_sat, accx1) (m);
  TYPE(i128_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rod_sat, 1x1) result = FN(mcopy_a2m, i128_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rod_sat, accx1) ();
  TYPE(i128_rod_sat, accx1) zero = FN(mzero_acc, i128_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
#endif

#if TEST_UDS == 64
void value_0_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 1x16) d = FN(mconv_ew, u4_rnu, 1x16) (s);
  d = FN(mabs_ew, u4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u4_rnu, 1x16) copy = FN(mcopy_m2m, u4_rnu, 1x16) (d);
  d = FN(mclear_m, u4_rnu, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu, 1x32) group = FN(mconcat_m, u4_rnu, 1x32) (copy, copy);
  TYPE(u4_rnu, 1x16) half = FN(mextract, u4_rnu, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_0_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 16x1) d = FN(mconv_ew, u4_rnu, 16x1) (s);
  d = FN(mabs_ew, u4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u4_rnu, 16x1) copy = FN(mcopy_m2m, u4_rnu, 16x1) (d);
  d = FN(mclear_m, u4_rnu, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu, 32x1) group = FN(mconcat_m, u4_rnu, 32x1) (copy, copy);
  TYPE(u4_rnu, 16x1) half = FN(mextract, u4_rnu, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_0_16 (void)
{
  TYPE(u4_rnu, 1x16) m = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rnu, accx16) a = FN(mcopy_m2a, u4_rnu, accx16) (m);
  TYPE(u4_rnu, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu, 1x16) result = FN(mcopy_a2m, u4_rnu, 1x16) (copy);
  a = FN(mclear_acc, u4_rnu, accx16) ();
  TYPE(u4_rnu, accx16) zero = FN(mzero_acc, u4_rnu, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_1_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u4_rne, 1x16) d = FN(mconv_ew, u4_rne, 1x16) (s);
  d = FN(mabs_ew, u4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u4_rne, 1x16) copy = FN(mcopy_m2m, u4_rne, 1x16) (d);
  d = FN(mclear_m, u4_rne, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne, 1x32) group = FN(mconcat_m, u4_rne, 1x32) (copy, copy);
  TYPE(u4_rne, 1x16) half = FN(mextract, u4_rne, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_1_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u4_rne, 16x1) d = FN(mconv_ew, u4_rne, 16x1) (s);
  d = FN(mabs_ew, u4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u4_rne, 16x1) copy = FN(mcopy_m2m, u4_rne, 16x1) (d);
  d = FN(mclear_m, u4_rne, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne, 32x1) group = FN(mconcat_m, u4_rne, 32x1) (copy, copy);
  TYPE(u4_rne, 16x1) half = FN(mextract, u4_rne, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_1_16 (void)
{
  TYPE(u4_rne, 1x16) m = FN(mzero_m, u4_rne, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rne, accx16) a = FN(mcopy_m2a, u4_rne, accx16) (m);
  TYPE(u4_rne, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne, 1x16) result = FN(mcopy_a2m, u4_rne, 1x16) (copy);
  a = FN(mclear_acc, u4_rne, accx16) ();
  TYPE(u4_rne, accx16) zero = FN(mzero_acc, u4_rne, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_2_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 1x16) d = FN(mconv_ew, u4_rdn, 1x16) (s);
  d = FN(mabs_ew, u4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u4_rdn, 1x16) copy = FN(mcopy_m2m, u4_rdn, 1x16) (d);
  d = FN(mclear_m, u4_rdn, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn, 1x32) group = FN(mconcat_m, u4_rdn, 1x32) (copy, copy);
  TYPE(u4_rdn, 1x16) half = FN(mextract, u4_rdn, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_2_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 16x1) d = FN(mconv_ew, u4_rdn, 16x1) (s);
  d = FN(mabs_ew, u4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u4_rdn, 16x1) copy = FN(mcopy_m2m, u4_rdn, 16x1) (d);
  d = FN(mclear_m, u4_rdn, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn, 32x1) group = FN(mconcat_m, u4_rdn, 32x1) (copy, copy);
  TYPE(u4_rdn, 16x1) half = FN(mextract, u4_rdn, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_2_16 (void)
{
  TYPE(u4_rdn, 1x16) m = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rdn, accx16) a = FN(mcopy_m2a, u4_rdn, accx16) (m);
  TYPE(u4_rdn, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn, 1x16) result = FN(mcopy_a2m, u4_rdn, 1x16) (copy);
  a = FN(mclear_acc, u4_rdn, accx16) ();
  TYPE(u4_rdn, accx16) zero = FN(mzero_acc, u4_rdn, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_3_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u4_rod, 1x16) d = FN(mconv_ew, u4_rod, 1x16) (s);
  d = FN(mabs_ew, u4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u4_rod, 1x16) copy = FN(mcopy_m2m, u4_rod, 1x16) (d);
  d = FN(mclear_m, u4_rod, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod, 1x32) group = FN(mconcat_m, u4_rod, 1x32) (copy, copy);
  TYPE(u4_rod, 1x16) half = FN(mextract, u4_rod, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_3_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u4_rod, 16x1) d = FN(mconv_ew, u4_rod, 16x1) (s);
  d = FN(mabs_ew, u4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u4_rod, 16x1) copy = FN(mcopy_m2m, u4_rod, 16x1) (d);
  d = FN(mclear_m, u4_rod, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod, 32x1) group = FN(mconcat_m, u4_rod, 32x1) (copy, copy);
  TYPE(u4_rod, 16x1) half = FN(mextract, u4_rod, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_3_16 (void)
{
  TYPE(u4_rod, 1x16) m = FN(mzero_m, u4_rod, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rod, accx16) a = FN(mcopy_m2a, u4_rod, accx16) (m);
  TYPE(u4_rod, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod, 1x16) result = FN(mcopy_a2m, u4_rod, 1x16) (copy);
  a = FN(mclear_acc, u4_rod, accx16) ();
  TYPE(u4_rod, accx16) zero = FN(mzero_acc, u4_rod, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_4_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 1x16) d = FN(mconv_ew, i4_rnu, 1x16) (s);
  d = FN(mabs_ew, i4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i4_rnu, 1x16) copy = FN(mcopy_m2m, i4_rnu, 1x16) (d);
  d = FN(mclear_m, i4_rnu, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu, 1x32) group = FN(mconcat_m, i4_rnu, 1x32) (copy, copy);
  TYPE(i4_rnu, 1x16) half = FN(mextract, i4_rnu, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_4_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 16x1) d = FN(mconv_ew, i4_rnu, 16x1) (s);
  d = FN(mabs_ew, i4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i4_rnu, 16x1) copy = FN(mcopy_m2m, i4_rnu, 16x1) (d);
  d = FN(mclear_m, i4_rnu, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu, 32x1) group = FN(mconcat_m, i4_rnu, 32x1) (copy, copy);
  TYPE(i4_rnu, 16x1) half = FN(mextract, i4_rnu, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_4_16 (void)
{
  TYPE(i4_rnu, 1x16) m = FN(mzero_m, i4_rnu, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rnu, accx16) a = FN(mcopy_m2a, i4_rnu, accx16) (m);
  TYPE(i4_rnu, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu, 1x16) result = FN(mcopy_a2m, i4_rnu, 1x16) (copy);
  a = FN(mclear_acc, i4_rnu, accx16) ();
  TYPE(i4_rnu, accx16) zero = FN(mzero_acc, i4_rnu, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_5_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i4_rne, 1x16) d = FN(mconv_ew, i4_rne, 1x16) (s);
  d = FN(mabs_ew, i4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i4_rne, 1x16) copy = FN(mcopy_m2m, i4_rne, 1x16) (d);
  d = FN(mclear_m, i4_rne, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne, 1x32) group = FN(mconcat_m, i4_rne, 1x32) (copy, copy);
  TYPE(i4_rne, 1x16) half = FN(mextract, i4_rne, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_5_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i4_rne, 16x1) d = FN(mconv_ew, i4_rne, 16x1) (s);
  d = FN(mabs_ew, i4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i4_rne, 16x1) copy = FN(mcopy_m2m, i4_rne, 16x1) (d);
  d = FN(mclear_m, i4_rne, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne, 32x1) group = FN(mconcat_m, i4_rne, 32x1) (copy, copy);
  TYPE(i4_rne, 16x1) half = FN(mextract, i4_rne, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_5_16 (void)
{
  TYPE(i4_rne, 1x16) m = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rne, accx16) a = FN(mcopy_m2a, i4_rne, accx16) (m);
  TYPE(i4_rne, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne, 1x16) result = FN(mcopy_a2m, i4_rne, 1x16) (copy);
  a = FN(mclear_acc, i4_rne, accx16) ();
  TYPE(i4_rne, accx16) zero = FN(mzero_acc, i4_rne, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_6_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 1x16) d = FN(mconv_ew, i4_rdn, 1x16) (s);
  d = FN(mabs_ew, i4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i4_rdn, 1x16) copy = FN(mcopy_m2m, i4_rdn, 1x16) (d);
  d = FN(mclear_m, i4_rdn, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn, 1x32) group = FN(mconcat_m, i4_rdn, 1x32) (copy, copy);
  TYPE(i4_rdn, 1x16) half = FN(mextract, i4_rdn, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_6_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 16x1) d = FN(mconv_ew, i4_rdn, 16x1) (s);
  d = FN(mabs_ew, i4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i4_rdn, 16x1) copy = FN(mcopy_m2m, i4_rdn, 16x1) (d);
  d = FN(mclear_m, i4_rdn, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn, 32x1) group = FN(mconcat_m, i4_rdn, 32x1) (copy, copy);
  TYPE(i4_rdn, 16x1) half = FN(mextract, i4_rdn, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_6_16 (void)
{
  TYPE(i4_rdn, 1x16) m = FN(mzero_m, i4_rdn, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rdn, accx16) a = FN(mcopy_m2a, i4_rdn, accx16) (m);
  TYPE(i4_rdn, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn, 1x16) result = FN(mcopy_a2m, i4_rdn, 1x16) (copy);
  a = FN(mclear_acc, i4_rdn, accx16) ();
  TYPE(i4_rdn, accx16) zero = FN(mzero_acc, i4_rdn, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_7_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i4_rod, 1x16) d = FN(mconv_ew, i4_rod, 1x16) (s);
  d = FN(mabs_ew, i4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i4_rod, 1x16) copy = FN(mcopy_m2m, i4_rod, 1x16) (d);
  d = FN(mclear_m, i4_rod, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod, 1x32) group = FN(mconcat_m, i4_rod, 1x32) (copy, copy);
  TYPE(i4_rod, 1x16) half = FN(mextract, i4_rod, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_7_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i4_rod, 16x1) d = FN(mconv_ew, i4_rod, 16x1) (s);
  d = FN(mabs_ew, i4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i4_rod, 16x1) copy = FN(mcopy_m2m, i4_rod, 16x1) (d);
  d = FN(mclear_m, i4_rod, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod, 32x1) group = FN(mconcat_m, i4_rod, 32x1) (copy, copy);
  TYPE(i4_rod, 16x1) half = FN(mextract, i4_rod, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_7_16 (void)
{
  TYPE(i4_rod, 1x16) m = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rod, accx16) a = FN(mcopy_m2a, i4_rod, accx16) (m);
  TYPE(i4_rod, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod, 1x16) result = FN(mcopy_a2m, i4_rod, 1x16) (copy);
  a = FN(mclear_acc, i4_rod, accx16) ();
  TYPE(i4_rod, accx16) zero = FN(mzero_acc, i4_rod, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_8_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 1x16) d = FN(mconv_ew, u4_rnu_sat, 1x16) (s);
  d = FN(mabs_ew, u4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u4_rnu_sat, 1x16) copy = FN(mcopy_m2m, u4_rnu_sat, 1x16) (d);
  d = FN(mclear_m, u4_rnu_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu_sat, 1x32) group = FN(mconcat_m, u4_rnu_sat, 1x32) (copy, copy);
  TYPE(u4_rnu_sat, 1x16) half = FN(mextract, u4_rnu_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_8_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 16x1) d = FN(mconv_ew, u4_rnu_sat, 16x1) (s);
  d = FN(mabs_ew, u4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u4_rnu_sat, 16x1) copy = FN(mcopy_m2m, u4_rnu_sat, 16x1) (d);
  d = FN(mclear_m, u4_rnu_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rnu_sat, 32x1) group = FN(mconcat_m, u4_rnu_sat, 32x1) (copy, copy);
  TYPE(u4_rnu_sat, 16x1) half = FN(mextract, u4_rnu_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_8_16 (void)
{
  TYPE(u4_rnu_sat, 1x16) m = FN(mzero_m, u4_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rnu_sat, accx16) a = FN(mcopy_m2a, u4_rnu_sat, accx16) (m);
  TYPE(u4_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rnu_sat, 1x16) result = FN(mcopy_a2m, u4_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rnu_sat, accx16) ();
  TYPE(u4_rnu_sat, accx16) zero = FN(mzero_acc, u4_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_9_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 1x16) d = FN(mconv_ew, u4_rne_sat, 1x16) (s);
  d = FN(mabs_ew, u4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u4_rne_sat, 1x16) copy = FN(mcopy_m2m, u4_rne_sat, 1x16) (d);
  d = FN(mclear_m, u4_rne_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne_sat, 1x32) group = FN(mconcat_m, u4_rne_sat, 1x32) (copy, copy);
  TYPE(u4_rne_sat, 1x16) half = FN(mextract, u4_rne_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_9_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 16x1) d = FN(mconv_ew, u4_rne_sat, 16x1) (s);
  d = FN(mabs_ew, u4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u4_rne_sat, 16x1) copy = FN(mcopy_m2m, u4_rne_sat, 16x1) (d);
  d = FN(mclear_m, u4_rne_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rne_sat, 32x1) group = FN(mconcat_m, u4_rne_sat, 32x1) (copy, copy);
  TYPE(u4_rne_sat, 16x1) half = FN(mextract, u4_rne_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_9_16 (void)
{
  TYPE(u4_rne_sat, 1x16) m = FN(mzero_m, u4_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rne_sat, accx16) a = FN(mcopy_m2a, u4_rne_sat, accx16) (m);
  TYPE(u4_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rne_sat, 1x16) result = FN(mcopy_a2m, u4_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rne_sat, accx16) ();
  TYPE(u4_rne_sat, accx16) zero = FN(mzero_acc, u4_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_10_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 1x16) d = FN(mconv_ew, u4_rdn_sat, 1x16) (s);
  d = FN(mabs_ew, u4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u4_rdn_sat, 1x16) copy = FN(mcopy_m2m, u4_rdn_sat, 1x16) (d);
  d = FN(mclear_m, u4_rdn_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn_sat, 1x32) group = FN(mconcat_m, u4_rdn_sat, 1x32) (copy, copy);
  TYPE(u4_rdn_sat, 1x16) half = FN(mextract, u4_rdn_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_10_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 16x1) d = FN(mconv_ew, u4_rdn_sat, 16x1) (s);
  d = FN(mabs_ew, u4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u4_rdn_sat, 16x1) copy = FN(mcopy_m2m, u4_rdn_sat, 16x1) (d);
  d = FN(mclear_m, u4_rdn_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rdn_sat, 32x1) group = FN(mconcat_m, u4_rdn_sat, 32x1) (copy, copy);
  TYPE(u4_rdn_sat, 16x1) half = FN(mextract, u4_rdn_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_10_16 (void)
{
  TYPE(u4_rdn_sat, 1x16) m = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rdn_sat, accx16) a = FN(mcopy_m2a, u4_rdn_sat, accx16) (m);
  TYPE(u4_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rdn_sat, 1x16) result = FN(mcopy_a2m, u4_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rdn_sat, accx16) ();
  TYPE(u4_rdn_sat, accx16) zero = FN(mzero_acc, u4_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_11_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 1x16) d = FN(mconv_ew, u4_rod_sat, 1x16) (s);
  d = FN(mabs_ew, u4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u4_rod_sat, 1x16) copy = FN(mcopy_m2m, u4_rod_sat, 1x16) (d);
  d = FN(mclear_m, u4_rod_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod_sat, 1x32) group = FN(mconcat_m, u4_rod_sat, 1x32) (copy, copy);
  TYPE(u4_rod_sat, 1x16) half = FN(mextract, u4_rod_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_11_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 16x1) d = FN(mconv_ew, u4_rod_sat, 16x1) (s);
  d = FN(mabs_ew, u4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u4_rod_sat, 16x1) copy = FN(mcopy_m2m, u4_rod_sat, 16x1) (d);
  d = FN(mclear_m, u4_rod_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u4_rod_sat, 32x1) group = FN(mconcat_m, u4_rod_sat, 32x1) (copy, copy);
  TYPE(u4_rod_sat, 16x1) half = FN(mextract, u4_rod_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_11_16 (void)
{
  TYPE(u4_rod_sat, 1x16) m = FN(mzero_m, u4_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u4_rod_sat, accx16) a = FN(mcopy_m2a, u4_rod_sat, accx16) (m);
  TYPE(u4_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u4_rod_sat, 1x16) result = FN(mcopy_a2m, u4_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, u4_rod_sat, accx16) ();
  TYPE(u4_rod_sat, accx16) zero = FN(mzero_acc, u4_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_12_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 1x16) d = FN(mconv_ew, i4_rnu_sat, 1x16) (s);
  d = FN(mabs_ew, i4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i4_rnu_sat, 1x16) copy = FN(mcopy_m2m, i4_rnu_sat, 1x16) (d);
  d = FN(mclear_m, i4_rnu_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu_sat, 1x32) group = FN(mconcat_m, i4_rnu_sat, 1x32) (copy, copy);
  TYPE(i4_rnu_sat, 1x16) half = FN(mextract, i4_rnu_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_12_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 16x1) d = FN(mconv_ew, i4_rnu_sat, 16x1) (s);
  d = FN(mabs_ew, i4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i4_rnu_sat, 16x1) copy = FN(mcopy_m2m, i4_rnu_sat, 16x1) (d);
  d = FN(mclear_m, i4_rnu_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rnu_sat, 32x1) group = FN(mconcat_m, i4_rnu_sat, 32x1) (copy, copy);
  TYPE(i4_rnu_sat, 16x1) half = FN(mextract, i4_rnu_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_12_16 (void)
{
  TYPE(i4_rnu_sat, 1x16) m = FN(mzero_m, i4_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rnu_sat, accx16) a = FN(mcopy_m2a, i4_rnu_sat, accx16) (m);
  TYPE(i4_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rnu_sat, 1x16) result = FN(mcopy_a2m, i4_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rnu_sat, accx16) ();
  TYPE(i4_rnu_sat, accx16) zero = FN(mzero_acc, i4_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_13_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 1x16) d = FN(mconv_ew, i4_rne_sat, 1x16) (s);
  d = FN(mabs_ew, i4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i4_rne_sat, 1x16) copy = FN(mcopy_m2m, i4_rne_sat, 1x16) (d);
  d = FN(mclear_m, i4_rne_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne_sat, 1x32) group = FN(mconcat_m, i4_rne_sat, 1x32) (copy, copy);
  TYPE(i4_rne_sat, 1x16) half = FN(mextract, i4_rne_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_13_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 16x1) d = FN(mconv_ew, i4_rne_sat, 16x1) (s);
  d = FN(mabs_ew, i4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i4_rne_sat, 16x1) copy = FN(mcopy_m2m, i4_rne_sat, 16x1) (d);
  d = FN(mclear_m, i4_rne_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rne_sat, 32x1) group = FN(mconcat_m, i4_rne_sat, 32x1) (copy, copy);
  TYPE(i4_rne_sat, 16x1) half = FN(mextract, i4_rne_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_13_16 (void)
{
  TYPE(i4_rne_sat, 1x16) m = FN(mzero_m, i4_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rne_sat, accx16) a = FN(mcopy_m2a, i4_rne_sat, accx16) (m);
  TYPE(i4_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rne_sat, 1x16) result = FN(mcopy_a2m, i4_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rne_sat, accx16) ();
  TYPE(i4_rne_sat, accx16) zero = FN(mzero_acc, i4_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_14_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 1x16) d = FN(mconv_ew, i4_rdn_sat, 1x16) (s);
  d = FN(mabs_ew, i4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i4_rdn_sat, 1x16) copy = FN(mcopy_m2m, i4_rdn_sat, 1x16) (d);
  d = FN(mclear_m, i4_rdn_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn_sat, 1x32) group = FN(mconcat_m, i4_rdn_sat, 1x32) (copy, copy);
  TYPE(i4_rdn_sat, 1x16) half = FN(mextract, i4_rdn_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_14_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 16x1) d = FN(mconv_ew, i4_rdn_sat, 16x1) (s);
  d = FN(mabs_ew, i4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i4_rdn_sat, 16x1) copy = FN(mcopy_m2m, i4_rdn_sat, 16x1) (d);
  d = FN(mclear_m, i4_rdn_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rdn_sat, 32x1) group = FN(mconcat_m, i4_rdn_sat, 32x1) (copy, copy);
  TYPE(i4_rdn_sat, 16x1) half = FN(mextract, i4_rdn_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_14_16 (void)
{
  TYPE(i4_rdn_sat, 1x16) m = FN(mzero_m, i4_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rdn_sat, accx16) a = FN(mcopy_m2a, i4_rdn_sat, accx16) (m);
  TYPE(i4_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rdn_sat, 1x16) result = FN(mcopy_a2m, i4_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rdn_sat, accx16) ();
  TYPE(i4_rdn_sat, accx16) zero = FN(mzero_acc, i4_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_15_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 1x16) d = FN(mconv_ew, i4_rod_sat, 1x16) (s);
  d = FN(mabs_ew, i4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i4_rod_sat, 1x16) copy = FN(mcopy_m2m, i4_rod_sat, 1x16) (d);
  d = FN(mclear_m, i4_rod_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod_sat, 1x32) group = FN(mconcat_m, i4_rod_sat, 1x32) (copy, copy);
  TYPE(i4_rod_sat, 1x16) half = FN(mextract, i4_rod_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_15_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 16x1) d = FN(mconv_ew, i4_rod_sat, 16x1) (s);
  d = FN(mabs_ew, i4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i4_rod_sat, 16x1) copy = FN(mcopy_m2m, i4_rod_sat, 16x1) (d);
  d = FN(mclear_m, i4_rod_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i4_rod_sat, 32x1) group = FN(mconcat_m, i4_rod_sat, 32x1) (copy, copy);
  TYPE(i4_rod_sat, 16x1) half = FN(mextract, i4_rod_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_15_16 (void)
{
  TYPE(i4_rod_sat, 1x16) m = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i4_rod_sat, accx16) a = FN(mcopy_m2a, i4_rod_sat, accx16) (m);
  TYPE(i4_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i4_rod_sat, 1x16) result = FN(mcopy_a2m, i4_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, i4_rod_sat, accx16) ();
  TYPE(i4_rod_sat, accx16) zero = FN(mzero_acc, i4_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_16_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u8_rnu_sat, 1x8) d = FN(mconv_ew, u8_rnu_sat, 1x8) (s);
  d = FN(mabs_ew, u8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rnu_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u8_rnu_sat, 1x8) copy = FN(mcopy_m2m, u8_rnu_sat, 1x8) (d);
  d = FN(mclear_m, u8_rnu_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rnu_sat, 1x16) group = FN(mconcat_m, u8_rnu_sat, 1x16) (copy, copy);
  TYPE(u8_rnu_sat, 1x8) half = FN(mextract, u8_rnu_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_16_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u8_rnu_sat, 8x1) d = FN(mconv_ew, u8_rnu_sat, 8x1) (s);
  d = FN(mabs_ew, u8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rnu_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u8_rnu_sat, 8x1) copy = FN(mcopy_m2m, u8_rnu_sat, 8x1) (d);
  d = FN(mclear_m, u8_rnu_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rnu_sat, 16x1) group = FN(mconcat_m, u8_rnu_sat, 16x1) (copy, copy);
  TYPE(u8_rnu_sat, 8x1) half = FN(mextract, u8_rnu_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_16_8 (void)
{
  TYPE(u8_rnu_sat, 1x8) m = FN(mzero_m, u8_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx8) a = FN(mcopy_m2a, u8_rnu_sat, accx8) (m);
  TYPE(u8_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x8) result = FN(mcopy_a2m, u8_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx8) ();
  TYPE(u8_rnu_sat, accx8) zero = FN(mzero_acc, u8_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_16_16 (void)
{
  TYPE(u8_rnu_sat, 1x16) m = FN(mzero_m, u8_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx16) a = FN(mcopy_m2a, u8_rnu_sat, accx16) (m);
  TYPE(u8_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x16) result = FN(mcopy_a2m, u8_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx16) ();
  TYPE(u8_rnu_sat, accx16) zero = FN(mzero_acc, u8_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_17_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u8_rne_sat, 1x8) d = FN(mconv_ew, u8_rne_sat, 1x8) (s);
  d = FN(mabs_ew, u8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rne_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u8_rne_sat, 1x8) copy = FN(mcopy_m2m, u8_rne_sat, 1x8) (d);
  d = FN(mclear_m, u8_rne_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rne_sat, 1x16) group = FN(mconcat_m, u8_rne_sat, 1x16) (copy, copy);
  TYPE(u8_rne_sat, 1x8) half = FN(mextract, u8_rne_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_17_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u8_rne_sat, 8x1) d = FN(mconv_ew, u8_rne_sat, 8x1) (s);
  d = FN(mabs_ew, u8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rne_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u8_rne_sat, 8x1) copy = FN(mcopy_m2m, u8_rne_sat, 8x1) (d);
  d = FN(mclear_m, u8_rne_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rne_sat, 16x1) group = FN(mconcat_m, u8_rne_sat, 16x1) (copy, copy);
  TYPE(u8_rne_sat, 8x1) half = FN(mextract, u8_rne_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_17_8 (void)
{
  TYPE(u8_rne_sat, 1x8) m = FN(mzero_m, u8_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx8) a = FN(mcopy_m2a, u8_rne_sat, accx8) (m);
  TYPE(u8_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x8) result = FN(mcopy_a2m, u8_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx8) ();
  TYPE(u8_rne_sat, accx8) zero = FN(mzero_acc, u8_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_17_16 (void)
{
  TYPE(u8_rne_sat, 1x16) m = FN(mzero_m, u8_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx16) a = FN(mcopy_m2a, u8_rne_sat, accx16) (m);
  TYPE(u8_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x16) result = FN(mcopy_a2m, u8_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx16) ();
  TYPE(u8_rne_sat, accx16) zero = FN(mzero_acc, u8_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_18_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u8_rdn_sat, 1x8) d = FN(mconv_ew, u8_rdn_sat, 1x8) (s);
  d = FN(mabs_ew, u8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rdn_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u8_rdn_sat, 1x8) copy = FN(mcopy_m2m, u8_rdn_sat, 1x8) (d);
  d = FN(mclear_m, u8_rdn_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rdn_sat, 1x16) group = FN(mconcat_m, u8_rdn_sat, 1x16) (copy, copy);
  TYPE(u8_rdn_sat, 1x8) half = FN(mextract, u8_rdn_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_18_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u8_rdn_sat, 8x1) d = FN(mconv_ew, u8_rdn_sat, 8x1) (s);
  d = FN(mabs_ew, u8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rdn_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u8_rdn_sat, 8x1) copy = FN(mcopy_m2m, u8_rdn_sat, 8x1) (d);
  d = FN(mclear_m, u8_rdn_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rdn_sat, 16x1) group = FN(mconcat_m, u8_rdn_sat, 16x1) (copy, copy);
  TYPE(u8_rdn_sat, 8x1) half = FN(mextract, u8_rdn_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_18_8 (void)
{
  TYPE(u8_rdn_sat, 1x8) m = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx8) a = FN(mcopy_m2a, u8_rdn_sat, accx8) (m);
  TYPE(u8_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x8) result = FN(mcopy_a2m, u8_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx8) ();
  TYPE(u8_rdn_sat, accx8) zero = FN(mzero_acc, u8_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_18_16 (void)
{
  TYPE(u8_rdn_sat, 1x16) m = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx16) a = FN(mcopy_m2a, u8_rdn_sat, accx16) (m);
  TYPE(u8_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x16) result = FN(mcopy_a2m, u8_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx16) ();
  TYPE(u8_rdn_sat, accx16) zero = FN(mzero_acc, u8_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_19_0 (void)
{
  TYPE(i8_rod, 1x8) s = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u8_rod_sat, 1x8) d = FN(mconv_ew, u8_rod_sat, 1x8) (s);
  d = FN(mabs_ew, u8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rod_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x8) back = FN(mconv_ew, i8_rod, 1x8) (d);
  TYPE(u8_rod_sat, 1x8) copy = FN(mcopy_m2m, u8_rod_sat, 1x8) (d);
  d = FN(mclear_m, u8_rod_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rod_sat, 1x16) group = FN(mconcat_m, u8_rod_sat, 1x16) (copy, copy);
  TYPE(u8_rod_sat, 1x8) half = FN(mextract, u8_rod_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_19_1 (void)
{
  TYPE(i8_rod, 8x1) s = FN(mzero_m, i8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u8_rod_sat, 8x1) d = FN(mconv_ew, u8_rod_sat, 8x1) (s);
  d = FN(mabs_ew, u8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rod_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 8x1) back = FN(mconv_ew, i8_rod, 8x1) (d);
  TYPE(u8_rod_sat, 8x1) copy = FN(mcopy_m2m, u8_rod_sat, 8x1) (d);
  d = FN(mclear_m, u8_rod_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rod_sat, 16x1) group = FN(mconcat_m, u8_rod_sat, 16x1) (copy, copy);
  TYPE(u8_rod_sat, 8x1) half = FN(mextract, u8_rod_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_19_8 (void)
{
  TYPE(u8_rod_sat, 1x8) m = FN(mzero_m, u8_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx8) a = FN(mcopy_m2a, u8_rod_sat, accx8) (m);
  TYPE(u8_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x8) result = FN(mcopy_a2m, u8_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx8) ();
  TYPE(u8_rod_sat, accx8) zero = FN(mzero_acc, u8_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_19_16 (void)
{
  TYPE(u8_rod_sat, 1x16) m = FN(mzero_m, u8_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx16) a = FN(mcopy_m2a, u8_rod_sat, accx16) (m);
  TYPE(u8_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x16) result = FN(mcopy_a2m, u8_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx16) ();
  TYPE(u8_rod_sat, accx16) zero = FN(mzero_acc, u8_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_20_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i8_rnu_sat, 1x8) d = FN(mconv_ew, i8_rnu_sat, 1x8) (s);
  d = FN(mabs_ew, i8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rnu_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i8_rnu_sat, 1x8) copy = FN(mcopy_m2m, i8_rnu_sat, 1x8) (d);
  d = FN(mclear_m, i8_rnu_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rnu_sat, 1x16) group = FN(mconcat_m, i8_rnu_sat, 1x16) (copy, copy);
  TYPE(i8_rnu_sat, 1x8) half = FN(mextract, i8_rnu_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_20_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i8_rnu_sat, 8x1) d = FN(mconv_ew, i8_rnu_sat, 8x1) (s);
  d = FN(mabs_ew, i8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rnu_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i8_rnu_sat, 8x1) copy = FN(mcopy_m2m, i8_rnu_sat, 8x1) (d);
  d = FN(mclear_m, i8_rnu_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rnu_sat, 16x1) group = FN(mconcat_m, i8_rnu_sat, 16x1) (copy, copy);
  TYPE(i8_rnu_sat, 8x1) half = FN(mextract, i8_rnu_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_20_8 (void)
{
  TYPE(i8_rnu_sat, 1x8) m = FN(mzero_m, i8_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx8) a = FN(mcopy_m2a, i8_rnu_sat, accx8) (m);
  TYPE(i8_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x8) result = FN(mcopy_a2m, i8_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx8) ();
  TYPE(i8_rnu_sat, accx8) zero = FN(mzero_acc, i8_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_20_16 (void)
{
  TYPE(i8_rnu_sat, 1x16) m = FN(mzero_m, i8_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx16) a = FN(mcopy_m2a, i8_rnu_sat, accx16) (m);
  TYPE(i8_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x16) result = FN(mcopy_a2m, i8_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx16) ();
  TYPE(i8_rnu_sat, accx16) zero = FN(mzero_acc, i8_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_21_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i8_rne_sat, 1x8) d = FN(mconv_ew, i8_rne_sat, 1x8) (s);
  d = FN(mabs_ew, i8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rne_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i8_rne_sat, 1x8) copy = FN(mcopy_m2m, i8_rne_sat, 1x8) (d);
  d = FN(mclear_m, i8_rne_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rne_sat, 1x16) group = FN(mconcat_m, i8_rne_sat, 1x16) (copy, copy);
  TYPE(i8_rne_sat, 1x8) half = FN(mextract, i8_rne_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_21_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i8_rne_sat, 8x1) d = FN(mconv_ew, i8_rne_sat, 8x1) (s);
  d = FN(mabs_ew, i8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rne_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i8_rne_sat, 8x1) copy = FN(mcopy_m2m, i8_rne_sat, 8x1) (d);
  d = FN(mclear_m, i8_rne_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rne_sat, 16x1) group = FN(mconcat_m, i8_rne_sat, 16x1) (copy, copy);
  TYPE(i8_rne_sat, 8x1) half = FN(mextract, i8_rne_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_21_8 (void)
{
  TYPE(i8_rne_sat, 1x8) m = FN(mzero_m, i8_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx8) a = FN(mcopy_m2a, i8_rne_sat, accx8) (m);
  TYPE(i8_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x8) result = FN(mcopy_a2m, i8_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx8) ();
  TYPE(i8_rne_sat, accx8) zero = FN(mzero_acc, i8_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_21_16 (void)
{
  TYPE(i8_rne_sat, 1x16) m = FN(mzero_m, i8_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx16) a = FN(mcopy_m2a, i8_rne_sat, accx16) (m);
  TYPE(i8_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x16) result = FN(mcopy_a2m, i8_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx16) ();
  TYPE(i8_rne_sat, accx16) zero = FN(mzero_acc, i8_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_22_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i8_rdn_sat, 1x8) d = FN(mconv_ew, i8_rdn_sat, 1x8) (s);
  d = FN(mabs_ew, i8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rdn_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i8_rdn_sat, 1x8) copy = FN(mcopy_m2m, i8_rdn_sat, 1x8) (d);
  d = FN(mclear_m, i8_rdn_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rdn_sat, 1x16) group = FN(mconcat_m, i8_rdn_sat, 1x16) (copy, copy);
  TYPE(i8_rdn_sat, 1x8) half = FN(mextract, i8_rdn_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_22_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i8_rdn_sat, 8x1) d = FN(mconv_ew, i8_rdn_sat, 8x1) (s);
  d = FN(mabs_ew, i8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rdn_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i8_rdn_sat, 8x1) copy = FN(mcopy_m2m, i8_rdn_sat, 8x1) (d);
  d = FN(mclear_m, i8_rdn_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rdn_sat, 16x1) group = FN(mconcat_m, i8_rdn_sat, 16x1) (copy, copy);
  TYPE(i8_rdn_sat, 8x1) half = FN(mextract, i8_rdn_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_22_8 (void)
{
  TYPE(i8_rdn_sat, 1x8) m = FN(mzero_m, i8_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx8) a = FN(mcopy_m2a, i8_rdn_sat, accx8) (m);
  TYPE(i8_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x8) result = FN(mcopy_a2m, i8_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx8) ();
  TYPE(i8_rdn_sat, accx8) zero = FN(mzero_acc, i8_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_22_16 (void)
{
  TYPE(i8_rdn_sat, 1x16) m = FN(mzero_m, i8_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx16) a = FN(mcopy_m2a, i8_rdn_sat, accx16) (m);
  TYPE(i8_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x16) result = FN(mcopy_a2m, i8_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx16) ();
  TYPE(i8_rdn_sat, accx16) zero = FN(mzero_acc, i8_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_23_0 (void)
{
  TYPE(u8_rod, 1x8) s = FN(mzero_m, u8_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i8_rod_sat, 1x8) d = FN(mconv_ew, i8_rod_sat, 1x8) (s);
  d = FN(mabs_ew, i8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rod_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x8) back = FN(mconv_ew, u8_rod, 1x8) (d);
  TYPE(i8_rod_sat, 1x8) copy = FN(mcopy_m2m, i8_rod_sat, 1x8) (d);
  d = FN(mclear_m, i8_rod_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rod_sat, 1x16) group = FN(mconcat_m, i8_rod_sat, 1x16) (copy, copy);
  TYPE(i8_rod_sat, 1x8) half = FN(mextract, i8_rod_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_23_1 (void)
{
  TYPE(u8_rod, 8x1) s = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i8_rod_sat, 8x1) d = FN(mconv_ew, i8_rod_sat, 8x1) (s);
  d = FN(mabs_ew, i8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rod_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 8x1) back = FN(mconv_ew, u8_rod, 8x1) (d);
  TYPE(i8_rod_sat, 8x1) copy = FN(mcopy_m2m, i8_rod_sat, 8x1) (d);
  d = FN(mclear_m, i8_rod_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rod_sat, 16x1) group = FN(mconcat_m, i8_rod_sat, 16x1) (copy, copy);
  TYPE(i8_rod_sat, 8x1) half = FN(mextract, i8_rod_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_23_8 (void)
{
  TYPE(i8_rod_sat, 1x8) m = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx8) a = FN(mcopy_m2a, i8_rod_sat, accx8) (m);
  TYPE(i8_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x8) result = FN(mcopy_a2m, i8_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx8) ();
  TYPE(i8_rod_sat, accx8) zero = FN(mzero_acc, i8_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_23_16 (void)
{
  TYPE(i8_rod_sat, 1x16) m = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx16) a = FN(mcopy_m2a, i8_rod_sat, accx16) (m);
  TYPE(i8_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x16) result = FN(mcopy_a2m, i8_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx16) ();
  TYPE(i8_rod_sat, accx16) zero = FN(mzero_acc, i8_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_24_0 (void)
{
  TYPE(i16_rod, 1x4) s = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u16_rnu_sat, 1x4) d = FN(mconv_ew, u16_rnu_sat, 1x4) (s);
  d = FN(mabs_ew, u16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rnu_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x4) back = FN(mconv_ew, i16_rod, 1x4) (d);
  TYPE(u16_rnu_sat, 1x4) copy = FN(mcopy_m2m, u16_rnu_sat, 1x4) (d);
  d = FN(mclear_m, u16_rnu_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rnu_sat, 1x8) group = FN(mconcat_m, u16_rnu_sat, 1x8) (copy, copy);
  TYPE(u16_rnu_sat, 1x4) half = FN(mextract, u16_rnu_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_24_1 (void)
{
  TYPE(i16_rod, 4x1) s = FN(mzero_m, i16_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u16_rnu_sat, 4x1) d = FN(mconv_ew, u16_rnu_sat, 4x1) (s);
  d = FN(mabs_ew, u16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rnu_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 4x1) back = FN(mconv_ew, i16_rod, 4x1) (d);
  TYPE(u16_rnu_sat, 4x1) copy = FN(mcopy_m2m, u16_rnu_sat, 4x1) (d);
  d = FN(mclear_m, u16_rnu_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rnu_sat, 8x1) group = FN(mconcat_m, u16_rnu_sat, 8x1) (copy, copy);
  TYPE(u16_rnu_sat, 4x1) half = FN(mextract, u16_rnu_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_24_4 (void)
{
  TYPE(u16_rnu_sat, 1x4) m = FN(mzero_m, u16_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx4) a = FN(mcopy_m2a, u16_rnu_sat, accx4) (m);
  TYPE(u16_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x4) result = FN(mcopy_a2m, u16_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx4) ();
  TYPE(u16_rnu_sat, accx4) zero = FN(mzero_acc, u16_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_24_8 (void)
{
  TYPE(u16_rnu_sat, 1x8) m = FN(mzero_m, u16_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx8) a = FN(mcopy_m2a, u16_rnu_sat, accx8) (m);
  TYPE(u16_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x8) result = FN(mcopy_a2m, u16_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx8) ();
  TYPE(u16_rnu_sat, accx8) zero = FN(mzero_acc, u16_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_24_16 (void)
{
  TYPE(u16_rnu_sat, 1x16) m = FN(mzero_m, u16_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx16) a = FN(mcopy_m2a, u16_rnu_sat, accx16) (m);
  TYPE(u16_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x16) result = FN(mcopy_a2m, u16_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx16) ();
  TYPE(u16_rnu_sat, accx16) zero = FN(mzero_acc, u16_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_25_0 (void)
{
  TYPE(i16_rod, 1x4) s = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u16_rne_sat, 1x4) d = FN(mconv_ew, u16_rne_sat, 1x4) (s);
  d = FN(mabs_ew, u16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rne_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x4) back = FN(mconv_ew, i16_rod, 1x4) (d);
  TYPE(u16_rne_sat, 1x4) copy = FN(mcopy_m2m, u16_rne_sat, 1x4) (d);
  d = FN(mclear_m, u16_rne_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rne_sat, 1x8) group = FN(mconcat_m, u16_rne_sat, 1x8) (copy, copy);
  TYPE(u16_rne_sat, 1x4) half = FN(mextract, u16_rne_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_25_1 (void)
{
  TYPE(i16_rod, 4x1) s = FN(mzero_m, i16_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u16_rne_sat, 4x1) d = FN(mconv_ew, u16_rne_sat, 4x1) (s);
  d = FN(mabs_ew, u16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rne_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 4x1) back = FN(mconv_ew, i16_rod, 4x1) (d);
  TYPE(u16_rne_sat, 4x1) copy = FN(mcopy_m2m, u16_rne_sat, 4x1) (d);
  d = FN(mclear_m, u16_rne_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rne_sat, 8x1) group = FN(mconcat_m, u16_rne_sat, 8x1) (copy, copy);
  TYPE(u16_rne_sat, 4x1) half = FN(mextract, u16_rne_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_25_4 (void)
{
  TYPE(u16_rne_sat, 1x4) m = FN(mzero_m, u16_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx4) a = FN(mcopy_m2a, u16_rne_sat, accx4) (m);
  TYPE(u16_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x4) result = FN(mcopy_a2m, u16_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx4) ();
  TYPE(u16_rne_sat, accx4) zero = FN(mzero_acc, u16_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_25_8 (void)
{
  TYPE(u16_rne_sat, 1x8) m = FN(mzero_m, u16_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx8) a = FN(mcopy_m2a, u16_rne_sat, accx8) (m);
  TYPE(u16_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x8) result = FN(mcopy_a2m, u16_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx8) ();
  TYPE(u16_rne_sat, accx8) zero = FN(mzero_acc, u16_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_25_16 (void)
{
  TYPE(u16_rne_sat, 1x16) m = FN(mzero_m, u16_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx16) a = FN(mcopy_m2a, u16_rne_sat, accx16) (m);
  TYPE(u16_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x16) result = FN(mcopy_a2m, u16_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx16) ();
  TYPE(u16_rne_sat, accx16) zero = FN(mzero_acc, u16_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_26_0 (void)
{
  TYPE(i16_rod, 1x4) s = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u16_rdn_sat, 1x4) d = FN(mconv_ew, u16_rdn_sat, 1x4) (s);
  d = FN(mabs_ew, u16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rdn_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x4) back = FN(mconv_ew, i16_rod, 1x4) (d);
  TYPE(u16_rdn_sat, 1x4) copy = FN(mcopy_m2m, u16_rdn_sat, 1x4) (d);
  d = FN(mclear_m, u16_rdn_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rdn_sat, 1x8) group = FN(mconcat_m, u16_rdn_sat, 1x8) (copy, copy);
  TYPE(u16_rdn_sat, 1x4) half = FN(mextract, u16_rdn_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_26_1 (void)
{
  TYPE(i16_rod, 4x1) s = FN(mzero_m, i16_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u16_rdn_sat, 4x1) d = FN(mconv_ew, u16_rdn_sat, 4x1) (s);
  d = FN(mabs_ew, u16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rdn_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 4x1) back = FN(mconv_ew, i16_rod, 4x1) (d);
  TYPE(u16_rdn_sat, 4x1) copy = FN(mcopy_m2m, u16_rdn_sat, 4x1) (d);
  d = FN(mclear_m, u16_rdn_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rdn_sat, 8x1) group = FN(mconcat_m, u16_rdn_sat, 8x1) (copy, copy);
  TYPE(u16_rdn_sat, 4x1) half = FN(mextract, u16_rdn_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_26_4 (void)
{
  TYPE(u16_rdn_sat, 1x4) m = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx4) a = FN(mcopy_m2a, u16_rdn_sat, accx4) (m);
  TYPE(u16_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x4) result = FN(mcopy_a2m, u16_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx4) ();
  TYPE(u16_rdn_sat, accx4) zero = FN(mzero_acc, u16_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_26_8 (void)
{
  TYPE(u16_rdn_sat, 1x8) m = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx8) a = FN(mcopy_m2a, u16_rdn_sat, accx8) (m);
  TYPE(u16_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x8) result = FN(mcopy_a2m, u16_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx8) ();
  TYPE(u16_rdn_sat, accx8) zero = FN(mzero_acc, u16_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_26_16 (void)
{
  TYPE(u16_rdn_sat, 1x16) m = FN(mzero_m, u16_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx16) a = FN(mcopy_m2a, u16_rdn_sat, accx16) (m);
  TYPE(u16_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x16) result = FN(mcopy_a2m, u16_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx16) ();
  TYPE(u16_rdn_sat, accx16) zero = FN(mzero_acc, u16_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_27_0 (void)
{
  TYPE(i16_rod, 1x4) s = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u16_rod_sat, 1x4) d = FN(mconv_ew, u16_rod_sat, 1x4) (s);
  d = FN(mabs_ew, u16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rod_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x4) back = FN(mconv_ew, i16_rod, 1x4) (d);
  TYPE(u16_rod_sat, 1x4) copy = FN(mcopy_m2m, u16_rod_sat, 1x4) (d);
  d = FN(mclear_m, u16_rod_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rod_sat, 1x8) group = FN(mconcat_m, u16_rod_sat, 1x8) (copy, copy);
  TYPE(u16_rod_sat, 1x4) half = FN(mextract, u16_rod_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_27_1 (void)
{
  TYPE(i16_rod, 4x1) s = FN(mzero_m, i16_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u16_rod_sat, 4x1) d = FN(mconv_ew, u16_rod_sat, 4x1) (s);
  d = FN(mabs_ew, u16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rod_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 4x1) back = FN(mconv_ew, i16_rod, 4x1) (d);
  TYPE(u16_rod_sat, 4x1) copy = FN(mcopy_m2m, u16_rod_sat, 4x1) (d);
  d = FN(mclear_m, u16_rod_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rod_sat, 8x1) group = FN(mconcat_m, u16_rod_sat, 8x1) (copy, copy);
  TYPE(u16_rod_sat, 4x1) half = FN(mextract, u16_rod_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_27_4 (void)
{
  TYPE(u16_rod_sat, 1x4) m = FN(mzero_m, u16_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx4) a = FN(mcopy_m2a, u16_rod_sat, accx4) (m);
  TYPE(u16_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x4) result = FN(mcopy_a2m, u16_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx4) ();
  TYPE(u16_rod_sat, accx4) zero = FN(mzero_acc, u16_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_27_8 (void)
{
  TYPE(u16_rod_sat, 1x8) m = FN(mzero_m, u16_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx8) a = FN(mcopy_m2a, u16_rod_sat, accx8) (m);
  TYPE(u16_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x8) result = FN(mcopy_a2m, u16_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx8) ();
  TYPE(u16_rod_sat, accx8) zero = FN(mzero_acc, u16_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_27_16 (void)
{
  TYPE(u16_rod_sat, 1x16) m = FN(mzero_m, u16_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx16) a = FN(mcopy_m2a, u16_rod_sat, accx16) (m);
  TYPE(u16_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x16) result = FN(mcopy_a2m, u16_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx16) ();
  TYPE(u16_rod_sat, accx16) zero = FN(mzero_acc, u16_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_28_0 (void)
{
  TYPE(u16_rod, 1x4) s = FN(mzero_m, u16_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i16_rnu_sat, 1x4) d = FN(mconv_ew, i16_rnu_sat, 1x4) (s);
  d = FN(mabs_ew, i16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rnu_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x4) back = FN(mconv_ew, u16_rod, 1x4) (d);
  TYPE(i16_rnu_sat, 1x4) copy = FN(mcopy_m2m, i16_rnu_sat, 1x4) (d);
  d = FN(mclear_m, i16_rnu_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rnu_sat, 1x8) group = FN(mconcat_m, i16_rnu_sat, 1x8) (copy, copy);
  TYPE(i16_rnu_sat, 1x4) half = FN(mextract, i16_rnu_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_28_1 (void)
{
  TYPE(u16_rod, 4x1) s = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i16_rnu_sat, 4x1) d = FN(mconv_ew, i16_rnu_sat, 4x1) (s);
  d = FN(mabs_ew, i16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rnu_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 4x1) back = FN(mconv_ew, u16_rod, 4x1) (d);
  TYPE(i16_rnu_sat, 4x1) copy = FN(mcopy_m2m, i16_rnu_sat, 4x1) (d);
  d = FN(mclear_m, i16_rnu_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rnu_sat, 8x1) group = FN(mconcat_m, i16_rnu_sat, 8x1) (copy, copy);
  TYPE(i16_rnu_sat, 4x1) half = FN(mextract, i16_rnu_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_28_4 (void)
{
  TYPE(i16_rnu_sat, 1x4) m = FN(mzero_m, i16_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx4) a = FN(mcopy_m2a, i16_rnu_sat, accx4) (m);
  TYPE(i16_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x4) result = FN(mcopy_a2m, i16_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx4) ();
  TYPE(i16_rnu_sat, accx4) zero = FN(mzero_acc, i16_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_28_8 (void)
{
  TYPE(i16_rnu_sat, 1x8) m = FN(mzero_m, i16_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx8) a = FN(mcopy_m2a, i16_rnu_sat, accx8) (m);
  TYPE(i16_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x8) result = FN(mcopy_a2m, i16_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx8) ();
  TYPE(i16_rnu_sat, accx8) zero = FN(mzero_acc, i16_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_28_16 (void)
{
  TYPE(i16_rnu_sat, 1x16) m = FN(mzero_m, i16_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx16) a = FN(mcopy_m2a, i16_rnu_sat, accx16) (m);
  TYPE(i16_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x16) result = FN(mcopy_a2m, i16_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx16) ();
  TYPE(i16_rnu_sat, accx16) zero = FN(mzero_acc, i16_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_29_0 (void)
{
  TYPE(u16_rod, 1x4) s = FN(mzero_m, u16_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i16_rne_sat, 1x4) d = FN(mconv_ew, i16_rne_sat, 1x4) (s);
  d = FN(mabs_ew, i16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rne_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x4) back = FN(mconv_ew, u16_rod, 1x4) (d);
  TYPE(i16_rne_sat, 1x4) copy = FN(mcopy_m2m, i16_rne_sat, 1x4) (d);
  d = FN(mclear_m, i16_rne_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rne_sat, 1x8) group = FN(mconcat_m, i16_rne_sat, 1x8) (copy, copy);
  TYPE(i16_rne_sat, 1x4) half = FN(mextract, i16_rne_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_29_1 (void)
{
  TYPE(u16_rod, 4x1) s = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i16_rne_sat, 4x1) d = FN(mconv_ew, i16_rne_sat, 4x1) (s);
  d = FN(mabs_ew, i16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rne_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 4x1) back = FN(mconv_ew, u16_rod, 4x1) (d);
  TYPE(i16_rne_sat, 4x1) copy = FN(mcopy_m2m, i16_rne_sat, 4x1) (d);
  d = FN(mclear_m, i16_rne_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rne_sat, 8x1) group = FN(mconcat_m, i16_rne_sat, 8x1) (copy, copy);
  TYPE(i16_rne_sat, 4x1) half = FN(mextract, i16_rne_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_29_4 (void)
{
  TYPE(i16_rne_sat, 1x4) m = FN(mzero_m, i16_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx4) a = FN(mcopy_m2a, i16_rne_sat, accx4) (m);
  TYPE(i16_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x4) result = FN(mcopy_a2m, i16_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx4) ();
  TYPE(i16_rne_sat, accx4) zero = FN(mzero_acc, i16_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_29_8 (void)
{
  TYPE(i16_rne_sat, 1x8) m = FN(mzero_m, i16_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx8) a = FN(mcopy_m2a, i16_rne_sat, accx8) (m);
  TYPE(i16_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x8) result = FN(mcopy_a2m, i16_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx8) ();
  TYPE(i16_rne_sat, accx8) zero = FN(mzero_acc, i16_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_29_16 (void)
{
  TYPE(i16_rne_sat, 1x16) m = FN(mzero_m, i16_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx16) a = FN(mcopy_m2a, i16_rne_sat, accx16) (m);
  TYPE(i16_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x16) result = FN(mcopy_a2m, i16_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx16) ();
  TYPE(i16_rne_sat, accx16) zero = FN(mzero_acc, i16_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_30_0 (void)
{
  TYPE(u16_rod, 1x4) s = FN(mzero_m, u16_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i16_rdn_sat, 1x4) d = FN(mconv_ew, i16_rdn_sat, 1x4) (s);
  d = FN(mabs_ew, i16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rdn_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x4) back = FN(mconv_ew, u16_rod, 1x4) (d);
  TYPE(i16_rdn_sat, 1x4) copy = FN(mcopy_m2m, i16_rdn_sat, 1x4) (d);
  d = FN(mclear_m, i16_rdn_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rdn_sat, 1x8) group = FN(mconcat_m, i16_rdn_sat, 1x8) (copy, copy);
  TYPE(i16_rdn_sat, 1x4) half = FN(mextract, i16_rdn_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_30_1 (void)
{
  TYPE(u16_rod, 4x1) s = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i16_rdn_sat, 4x1) d = FN(mconv_ew, i16_rdn_sat, 4x1) (s);
  d = FN(mabs_ew, i16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rdn_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 4x1) back = FN(mconv_ew, u16_rod, 4x1) (d);
  TYPE(i16_rdn_sat, 4x1) copy = FN(mcopy_m2m, i16_rdn_sat, 4x1) (d);
  d = FN(mclear_m, i16_rdn_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rdn_sat, 8x1) group = FN(mconcat_m, i16_rdn_sat, 8x1) (copy, copy);
  TYPE(i16_rdn_sat, 4x1) half = FN(mextract, i16_rdn_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_30_4 (void)
{
  TYPE(i16_rdn_sat, 1x4) m = FN(mzero_m, i16_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx4) a = FN(mcopy_m2a, i16_rdn_sat, accx4) (m);
  TYPE(i16_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x4) result = FN(mcopy_a2m, i16_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx4) ();
  TYPE(i16_rdn_sat, accx4) zero = FN(mzero_acc, i16_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_30_8 (void)
{
  TYPE(i16_rdn_sat, 1x8) m = FN(mzero_m, i16_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx8) a = FN(mcopy_m2a, i16_rdn_sat, accx8) (m);
  TYPE(i16_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x8) result = FN(mcopy_a2m, i16_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx8) ();
  TYPE(i16_rdn_sat, accx8) zero = FN(mzero_acc, i16_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_30_16 (void)
{
  TYPE(i16_rdn_sat, 1x16) m = FN(mzero_m, i16_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx16) a = FN(mcopy_m2a, i16_rdn_sat, accx16) (m);
  TYPE(i16_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x16) result = FN(mcopy_a2m, i16_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx16) ();
  TYPE(i16_rdn_sat, accx16) zero = FN(mzero_acc, i16_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_31_0 (void)
{
  TYPE(u16_rod, 1x4) s = FN(mzero_m, u16_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i16_rod_sat, 1x4) d = FN(mconv_ew, i16_rod_sat, 1x4) (s);
  d = FN(mabs_ew, i16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rod_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x4) back = FN(mconv_ew, u16_rod, 1x4) (d);
  TYPE(i16_rod_sat, 1x4) copy = FN(mcopy_m2m, i16_rod_sat, 1x4) (d);
  d = FN(mclear_m, i16_rod_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rod_sat, 1x8) group = FN(mconcat_m, i16_rod_sat, 1x8) (copy, copy);
  TYPE(i16_rod_sat, 1x4) half = FN(mextract, i16_rod_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_31_1 (void)
{
  TYPE(u16_rod, 4x1) s = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i16_rod_sat, 4x1) d = FN(mconv_ew, i16_rod_sat, 4x1) (s);
  d = FN(mabs_ew, i16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rod_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 4x1) back = FN(mconv_ew, u16_rod, 4x1) (d);
  TYPE(i16_rod_sat, 4x1) copy = FN(mcopy_m2m, i16_rod_sat, 4x1) (d);
  d = FN(mclear_m, i16_rod_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rod_sat, 8x1) group = FN(mconcat_m, i16_rod_sat, 8x1) (copy, copy);
  TYPE(i16_rod_sat, 4x1) half = FN(mextract, i16_rod_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_31_4 (void)
{
  TYPE(i16_rod_sat, 1x4) m = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx4) a = FN(mcopy_m2a, i16_rod_sat, accx4) (m);
  TYPE(i16_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x4) result = FN(mcopy_a2m, i16_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx4) ();
  TYPE(i16_rod_sat, accx4) zero = FN(mzero_acc, i16_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_31_8 (void)
{
  TYPE(i16_rod_sat, 1x8) m = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx8) a = FN(mcopy_m2a, i16_rod_sat, accx8) (m);
  TYPE(i16_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x8) result = FN(mcopy_a2m, i16_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx8) ();
  TYPE(i16_rod_sat, accx8) zero = FN(mzero_acc, i16_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_31_16 (void)
{
  TYPE(i16_rod_sat, 1x16) m = FN(mzero_m, i16_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx16) a = FN(mcopy_m2a, i16_rod_sat, accx16) (m);
  TYPE(i16_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x16) result = FN(mcopy_a2m, i16_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx16) ();
  TYPE(i16_rod_sat, accx16) zero = FN(mzero_acc, i16_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_32_0 (void)
{
  TYPE(i32_rod, 1x2) s = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u32_rnu_sat, 1x2) d = FN(mconv_ew, u32_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, u32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x2) back = FN(mconv_ew, i32_rod, 1x2) (d);
  TYPE(u32_rnu_sat, 1x2) copy = FN(mcopy_m2m, u32_rnu_sat, 1x2) (d);
  d = FN(mclear_m, u32_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rnu_sat, 1x4) group = FN(mconcat_m, u32_rnu_sat, 1x4) (copy, copy);
  TYPE(u32_rnu_sat, 1x2) half = FN(mextract, u32_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_32_1 (void)
{
  TYPE(i32_rod, 2x1) s = FN(mzero_m, i32_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u32_rnu_sat, 2x1) d = FN(mconv_ew, u32_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, u32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 2x1) back = FN(mconv_ew, i32_rod, 2x1) (d);
  TYPE(u32_rnu_sat, 2x1) copy = FN(mcopy_m2m, u32_rnu_sat, 2x1) (d);
  d = FN(mclear_m, u32_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rnu_sat, 4x1) group = FN(mconcat_m, u32_rnu_sat, 4x1) (copy, copy);
  TYPE(u32_rnu_sat, 2x1) half = FN(mextract, u32_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_32_2 (void)
{
  TYPE(u32_rnu_sat, 1x2) m = FN(mzero_m, u32_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx2) a = FN(mcopy_m2a, u32_rnu_sat, accx2) (m);
  TYPE(u32_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x2) result = FN(mcopy_a2m, u32_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx2) ();
  TYPE(u32_rnu_sat, accx2) zero = FN(mzero_acc, u32_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_32_4 (void)
{
  TYPE(u32_rnu_sat, 1x4) m = FN(mzero_m, u32_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx4) a = FN(mcopy_m2a, u32_rnu_sat, accx4) (m);
  TYPE(u32_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x4) result = FN(mcopy_a2m, u32_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx4) ();
  TYPE(u32_rnu_sat, accx4) zero = FN(mzero_acc, u32_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_32_8 (void)
{
  TYPE(u32_rnu_sat, 1x8) m = FN(mzero_m, u32_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx8) a = FN(mcopy_m2a, u32_rnu_sat, accx8) (m);
  TYPE(u32_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x8) result = FN(mcopy_a2m, u32_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx8) ();
  TYPE(u32_rnu_sat, accx8) zero = FN(mzero_acc, u32_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_33_0 (void)
{
  TYPE(i32_rod, 1x2) s = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u32_rne_sat, 1x2) d = FN(mconv_ew, u32_rne_sat, 1x2) (s);
  d = FN(mabs_ew, u32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x2) back = FN(mconv_ew, i32_rod, 1x2) (d);
  TYPE(u32_rne_sat, 1x2) copy = FN(mcopy_m2m, u32_rne_sat, 1x2) (d);
  d = FN(mclear_m, u32_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rne_sat, 1x4) group = FN(mconcat_m, u32_rne_sat, 1x4) (copy, copy);
  TYPE(u32_rne_sat, 1x2) half = FN(mextract, u32_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_33_1 (void)
{
  TYPE(i32_rod, 2x1) s = FN(mzero_m, i32_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u32_rne_sat, 2x1) d = FN(mconv_ew, u32_rne_sat, 2x1) (s);
  d = FN(mabs_ew, u32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 2x1) back = FN(mconv_ew, i32_rod, 2x1) (d);
  TYPE(u32_rne_sat, 2x1) copy = FN(mcopy_m2m, u32_rne_sat, 2x1) (d);
  d = FN(mclear_m, u32_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rne_sat, 4x1) group = FN(mconcat_m, u32_rne_sat, 4x1) (copy, copy);
  TYPE(u32_rne_sat, 2x1) half = FN(mextract, u32_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_33_2 (void)
{
  TYPE(u32_rne_sat, 1x2) m = FN(mzero_m, u32_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx2) a = FN(mcopy_m2a, u32_rne_sat, accx2) (m);
  TYPE(u32_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x2) result = FN(mcopy_a2m, u32_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx2) ();
  TYPE(u32_rne_sat, accx2) zero = FN(mzero_acc, u32_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_33_4 (void)
{
  TYPE(u32_rne_sat, 1x4) m = FN(mzero_m, u32_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx4) a = FN(mcopy_m2a, u32_rne_sat, accx4) (m);
  TYPE(u32_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x4) result = FN(mcopy_a2m, u32_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx4) ();
  TYPE(u32_rne_sat, accx4) zero = FN(mzero_acc, u32_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_33_8 (void)
{
  TYPE(u32_rne_sat, 1x8) m = FN(mzero_m, u32_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx8) a = FN(mcopy_m2a, u32_rne_sat, accx8) (m);
  TYPE(u32_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x8) result = FN(mcopy_a2m, u32_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx8) ();
  TYPE(u32_rne_sat, accx8) zero = FN(mzero_acc, u32_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_34_0 (void)
{
  TYPE(i32_rod, 1x2) s = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u32_rdn_sat, 1x2) d = FN(mconv_ew, u32_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, u32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x2) back = FN(mconv_ew, i32_rod, 1x2) (d);
  TYPE(u32_rdn_sat, 1x2) copy = FN(mcopy_m2m, u32_rdn_sat, 1x2) (d);
  d = FN(mclear_m, u32_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rdn_sat, 1x4) group = FN(mconcat_m, u32_rdn_sat, 1x4) (copy, copy);
  TYPE(u32_rdn_sat, 1x2) half = FN(mextract, u32_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_34_1 (void)
{
  TYPE(i32_rod, 2x1) s = FN(mzero_m, i32_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u32_rdn_sat, 2x1) d = FN(mconv_ew, u32_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, u32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 2x1) back = FN(mconv_ew, i32_rod, 2x1) (d);
  TYPE(u32_rdn_sat, 2x1) copy = FN(mcopy_m2m, u32_rdn_sat, 2x1) (d);
  d = FN(mclear_m, u32_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rdn_sat, 4x1) group = FN(mconcat_m, u32_rdn_sat, 4x1) (copy, copy);
  TYPE(u32_rdn_sat, 2x1) half = FN(mextract, u32_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_34_2 (void)
{
  TYPE(u32_rdn_sat, 1x2) m = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx2) a = FN(mcopy_m2a, u32_rdn_sat, accx2) (m);
  TYPE(u32_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x2) result = FN(mcopy_a2m, u32_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx2) ();
  TYPE(u32_rdn_sat, accx2) zero = FN(mzero_acc, u32_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_34_4 (void)
{
  TYPE(u32_rdn_sat, 1x4) m = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx4) a = FN(mcopy_m2a, u32_rdn_sat, accx4) (m);
  TYPE(u32_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x4) result = FN(mcopy_a2m, u32_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx4) ();
  TYPE(u32_rdn_sat, accx4) zero = FN(mzero_acc, u32_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_34_8 (void)
{
  TYPE(u32_rdn_sat, 1x8) m = FN(mzero_m, u32_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx8) a = FN(mcopy_m2a, u32_rdn_sat, accx8) (m);
  TYPE(u32_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x8) result = FN(mcopy_a2m, u32_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx8) ();
  TYPE(u32_rdn_sat, accx8) zero = FN(mzero_acc, u32_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_35_0 (void)
{
  TYPE(i32_rod, 1x2) s = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u32_rod_sat, 1x2) d = FN(mconv_ew, u32_rod_sat, 1x2) (s);
  d = FN(mabs_ew, u32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x2) back = FN(mconv_ew, i32_rod, 1x2) (d);
  TYPE(u32_rod_sat, 1x2) copy = FN(mcopy_m2m, u32_rod_sat, 1x2) (d);
  d = FN(mclear_m, u32_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rod_sat, 1x4) group = FN(mconcat_m, u32_rod_sat, 1x4) (copy, copy);
  TYPE(u32_rod_sat, 1x2) half = FN(mextract, u32_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_35_1 (void)
{
  TYPE(i32_rod, 2x1) s = FN(mzero_m, i32_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u32_rod_sat, 2x1) d = FN(mconv_ew, u32_rod_sat, 2x1) (s);
  d = FN(mabs_ew, u32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 2x1) back = FN(mconv_ew, i32_rod, 2x1) (d);
  TYPE(u32_rod_sat, 2x1) copy = FN(mcopy_m2m, u32_rod_sat, 2x1) (d);
  d = FN(mclear_m, u32_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rod_sat, 4x1) group = FN(mconcat_m, u32_rod_sat, 4x1) (copy, copy);
  TYPE(u32_rod_sat, 2x1) half = FN(mextract, u32_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_35_2 (void)
{
  TYPE(u32_rod_sat, 1x2) m = FN(mzero_m, u32_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx2) a = FN(mcopy_m2a, u32_rod_sat, accx2) (m);
  TYPE(u32_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x2) result = FN(mcopy_a2m, u32_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx2) ();
  TYPE(u32_rod_sat, accx2) zero = FN(mzero_acc, u32_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_35_4 (void)
{
  TYPE(u32_rod_sat, 1x4) m = FN(mzero_m, u32_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx4) a = FN(mcopy_m2a, u32_rod_sat, accx4) (m);
  TYPE(u32_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x4) result = FN(mcopy_a2m, u32_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx4) ();
  TYPE(u32_rod_sat, accx4) zero = FN(mzero_acc, u32_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_35_8 (void)
{
  TYPE(u32_rod_sat, 1x8) m = FN(mzero_m, u32_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx8) a = FN(mcopy_m2a, u32_rod_sat, accx8) (m);
  TYPE(u32_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x8) result = FN(mcopy_a2m, u32_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx8) ();
  TYPE(u32_rod_sat, accx8) zero = FN(mzero_acc, u32_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_36_0 (void)
{
  TYPE(u32_rod, 1x2) s = FN(mzero_m, u32_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i32_rnu_sat, 1x2) d = FN(mconv_ew, i32_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, i32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x2) back = FN(mconv_ew, u32_rod, 1x2) (d);
  TYPE(i32_rnu_sat, 1x2) copy = FN(mcopy_m2m, i32_rnu_sat, 1x2) (d);
  d = FN(mclear_m, i32_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rnu_sat, 1x4) group = FN(mconcat_m, i32_rnu_sat, 1x4) (copy, copy);
  TYPE(i32_rnu_sat, 1x2) half = FN(mextract, i32_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_36_1 (void)
{
  TYPE(u32_rod, 2x1) s = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i32_rnu_sat, 2x1) d = FN(mconv_ew, i32_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, i32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 2x1) back = FN(mconv_ew, u32_rod, 2x1) (d);
  TYPE(i32_rnu_sat, 2x1) copy = FN(mcopy_m2m, i32_rnu_sat, 2x1) (d);
  d = FN(mclear_m, i32_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rnu_sat, 4x1) group = FN(mconcat_m, i32_rnu_sat, 4x1) (copy, copy);
  TYPE(i32_rnu_sat, 2x1) half = FN(mextract, i32_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_36_2 (void)
{
  TYPE(i32_rnu_sat, 1x2) m = FN(mzero_m, i32_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx2) a = FN(mcopy_m2a, i32_rnu_sat, accx2) (m);
  TYPE(i32_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x2) result = FN(mcopy_a2m, i32_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx2) ();
  TYPE(i32_rnu_sat, accx2) zero = FN(mzero_acc, i32_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_36_4 (void)
{
  TYPE(i32_rnu_sat, 1x4) m = FN(mzero_m, i32_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx4) a = FN(mcopy_m2a, i32_rnu_sat, accx4) (m);
  TYPE(i32_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x4) result = FN(mcopy_a2m, i32_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx4) ();
  TYPE(i32_rnu_sat, accx4) zero = FN(mzero_acc, i32_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_36_8 (void)
{
  TYPE(i32_rnu_sat, 1x8) m = FN(mzero_m, i32_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx8) a = FN(mcopy_m2a, i32_rnu_sat, accx8) (m);
  TYPE(i32_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x8) result = FN(mcopy_a2m, i32_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx8) ();
  TYPE(i32_rnu_sat, accx8) zero = FN(mzero_acc, i32_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_37_0 (void)
{
  TYPE(u32_rod, 1x2) s = FN(mzero_m, u32_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i32_rne_sat, 1x2) d = FN(mconv_ew, i32_rne_sat, 1x2) (s);
  d = FN(mabs_ew, i32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x2) back = FN(mconv_ew, u32_rod, 1x2) (d);
  TYPE(i32_rne_sat, 1x2) copy = FN(mcopy_m2m, i32_rne_sat, 1x2) (d);
  d = FN(mclear_m, i32_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rne_sat, 1x4) group = FN(mconcat_m, i32_rne_sat, 1x4) (copy, copy);
  TYPE(i32_rne_sat, 1x2) half = FN(mextract, i32_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_37_1 (void)
{
  TYPE(u32_rod, 2x1) s = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i32_rne_sat, 2x1) d = FN(mconv_ew, i32_rne_sat, 2x1) (s);
  d = FN(mabs_ew, i32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 2x1) back = FN(mconv_ew, u32_rod, 2x1) (d);
  TYPE(i32_rne_sat, 2x1) copy = FN(mcopy_m2m, i32_rne_sat, 2x1) (d);
  d = FN(mclear_m, i32_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rne_sat, 4x1) group = FN(mconcat_m, i32_rne_sat, 4x1) (copy, copy);
  TYPE(i32_rne_sat, 2x1) half = FN(mextract, i32_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_37_2 (void)
{
  TYPE(i32_rne_sat, 1x2) m = FN(mzero_m, i32_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx2) a = FN(mcopy_m2a, i32_rne_sat, accx2) (m);
  TYPE(i32_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x2) result = FN(mcopy_a2m, i32_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx2) ();
  TYPE(i32_rne_sat, accx2) zero = FN(mzero_acc, i32_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_37_4 (void)
{
  TYPE(i32_rne_sat, 1x4) m = FN(mzero_m, i32_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx4) a = FN(mcopy_m2a, i32_rne_sat, accx4) (m);
  TYPE(i32_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x4) result = FN(mcopy_a2m, i32_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx4) ();
  TYPE(i32_rne_sat, accx4) zero = FN(mzero_acc, i32_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_37_8 (void)
{
  TYPE(i32_rne_sat, 1x8) m = FN(mzero_m, i32_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx8) a = FN(mcopy_m2a, i32_rne_sat, accx8) (m);
  TYPE(i32_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x8) result = FN(mcopy_a2m, i32_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx8) ();
  TYPE(i32_rne_sat, accx8) zero = FN(mzero_acc, i32_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_38_0 (void)
{
  TYPE(u32_rod, 1x2) s = FN(mzero_m, u32_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i32_rdn_sat, 1x2) d = FN(mconv_ew, i32_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, i32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x2) back = FN(mconv_ew, u32_rod, 1x2) (d);
  TYPE(i32_rdn_sat, 1x2) copy = FN(mcopy_m2m, i32_rdn_sat, 1x2) (d);
  d = FN(mclear_m, i32_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rdn_sat, 1x4) group = FN(mconcat_m, i32_rdn_sat, 1x4) (copy, copy);
  TYPE(i32_rdn_sat, 1x2) half = FN(mextract, i32_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_38_1 (void)
{
  TYPE(u32_rod, 2x1) s = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i32_rdn_sat, 2x1) d = FN(mconv_ew, i32_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, i32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 2x1) back = FN(mconv_ew, u32_rod, 2x1) (d);
  TYPE(i32_rdn_sat, 2x1) copy = FN(mcopy_m2m, i32_rdn_sat, 2x1) (d);
  d = FN(mclear_m, i32_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rdn_sat, 4x1) group = FN(mconcat_m, i32_rdn_sat, 4x1) (copy, copy);
  TYPE(i32_rdn_sat, 2x1) half = FN(mextract, i32_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_38_2 (void)
{
  TYPE(i32_rdn_sat, 1x2) m = FN(mzero_m, i32_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx2) a = FN(mcopy_m2a, i32_rdn_sat, accx2) (m);
  TYPE(i32_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x2) result = FN(mcopy_a2m, i32_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx2) ();
  TYPE(i32_rdn_sat, accx2) zero = FN(mzero_acc, i32_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_38_4 (void)
{
  TYPE(i32_rdn_sat, 1x4) m = FN(mzero_m, i32_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx4) a = FN(mcopy_m2a, i32_rdn_sat, accx4) (m);
  TYPE(i32_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x4) result = FN(mcopy_a2m, i32_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx4) ();
  TYPE(i32_rdn_sat, accx4) zero = FN(mzero_acc, i32_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_38_8 (void)
{
  TYPE(i32_rdn_sat, 1x8) m = FN(mzero_m, i32_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx8) a = FN(mcopy_m2a, i32_rdn_sat, accx8) (m);
  TYPE(i32_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x8) result = FN(mcopy_a2m, i32_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx8) ();
  TYPE(i32_rdn_sat, accx8) zero = FN(mzero_acc, i32_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_39_0 (void)
{
  TYPE(u32_rod, 1x2) s = FN(mzero_m, u32_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i32_rod_sat, 1x2) d = FN(mconv_ew, i32_rod_sat, 1x2) (s);
  d = FN(mabs_ew, i32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x2) back = FN(mconv_ew, u32_rod, 1x2) (d);
  TYPE(i32_rod_sat, 1x2) copy = FN(mcopy_m2m, i32_rod_sat, 1x2) (d);
  d = FN(mclear_m, i32_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rod_sat, 1x4) group = FN(mconcat_m, i32_rod_sat, 1x4) (copy, copy);
  TYPE(i32_rod_sat, 1x2) half = FN(mextract, i32_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_39_1 (void)
{
  TYPE(u32_rod, 2x1) s = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i32_rod_sat, 2x1) d = FN(mconv_ew, i32_rod_sat, 2x1) (s);
  d = FN(mabs_ew, i32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 2x1) back = FN(mconv_ew, u32_rod, 2x1) (d);
  TYPE(i32_rod_sat, 2x1) copy = FN(mcopy_m2m, i32_rod_sat, 2x1) (d);
  d = FN(mclear_m, i32_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rod_sat, 4x1) group = FN(mconcat_m, i32_rod_sat, 4x1) (copy, copy);
  TYPE(i32_rod_sat, 2x1) half = FN(mextract, i32_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_39_2 (void)
{
  TYPE(i32_rod_sat, 1x2) m = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx2) a = FN(mcopy_m2a, i32_rod_sat, accx2) (m);
  TYPE(i32_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x2) result = FN(mcopy_a2m, i32_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx2) ();
  TYPE(i32_rod_sat, accx2) zero = FN(mzero_acc, i32_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_39_4 (void)
{
  TYPE(i32_rod_sat, 1x4) m = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx4) a = FN(mcopy_m2a, i32_rod_sat, accx4) (m);
  TYPE(i32_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x4) result = FN(mcopy_a2m, i32_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx4) ();
  TYPE(i32_rod_sat, accx4) zero = FN(mzero_acc, i32_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_39_8 (void)
{
  TYPE(i32_rod_sat, 1x8) m = FN(mzero_m, i32_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx8) a = FN(mcopy_m2a, i32_rod_sat, accx8) (m);
  TYPE(i32_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x8) result = FN(mcopy_a2m, i32_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx8) ();
  TYPE(i32_rod_sat, accx8) zero = FN(mzero_acc, i32_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_40_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rnu_sat, 1x1) d = FN(mconv_ew, u64_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rnu_sat, 1x1) copy = FN(mcopy_m2m, u64_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u64_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rnu_sat, 1x2) group = FN(mconcat_m, u64_rnu_sat, 1x2) (copy, copy);
  TYPE(u64_rnu_sat, 1x1) half = FN(mextract, u64_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_40_1 (void)
{
  TYPE(u64_rnu_sat, 1x1) m = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rnu_sat, accx1) a = FN(mcopy_m2a, u64_rnu_sat, accx1) (m);
  TYPE(u64_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rnu_sat, 1x1) result = FN(mcopy_a2m, u64_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rnu_sat, accx1) ();
  TYPE(u64_rnu_sat, accx1) zero = FN(mzero_acc, u64_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_40_2 (void)
{
  TYPE(u64_rnu_sat, 1x2) m = FN(mzero_m, u64_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rnu_sat, accx2) a = FN(mcopy_m2a, u64_rnu_sat, accx2) (m);
  TYPE(u64_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rnu_sat, 1x2) result = FN(mcopy_a2m, u64_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rnu_sat, accx2) ();
  TYPE(u64_rnu_sat, accx2) zero = FN(mzero_acc, u64_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_40_4 (void)
{
  TYPE(u64_rnu_sat, 1x4) m = FN(mzero_m, u64_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u64_rnu_sat, accx4) a = FN(mcopy_m2a, u64_rnu_sat, accx4) (m);
  TYPE(u64_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u64_rnu_sat, 1x4) result = FN(mcopy_a2m, u64_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u64_rnu_sat, accx4) ();
  TYPE(u64_rnu_sat, accx4) zero = FN(mzero_acc, u64_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_41_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rne_sat, 1x1) d = FN(mconv_ew, u64_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rne_sat, 1x1) copy = FN(mcopy_m2m, u64_rne_sat, 1x1) (d);
  d = FN(mclear_m, u64_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rne_sat, 1x2) group = FN(mconcat_m, u64_rne_sat, 1x2) (copy, copy);
  TYPE(u64_rne_sat, 1x1) half = FN(mextract, u64_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_41_1 (void)
{
  TYPE(u64_rne_sat, 1x1) m = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rne_sat, accx1) a = FN(mcopy_m2a, u64_rne_sat, accx1) (m);
  TYPE(u64_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rne_sat, 1x1) result = FN(mcopy_a2m, u64_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rne_sat, accx1) ();
  TYPE(u64_rne_sat, accx1) zero = FN(mzero_acc, u64_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_41_2 (void)
{
  TYPE(u64_rne_sat, 1x2) m = FN(mzero_m, u64_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rne_sat, accx2) a = FN(mcopy_m2a, u64_rne_sat, accx2) (m);
  TYPE(u64_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rne_sat, 1x2) result = FN(mcopy_a2m, u64_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rne_sat, accx2) ();
  TYPE(u64_rne_sat, accx2) zero = FN(mzero_acc, u64_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_41_4 (void)
{
  TYPE(u64_rne_sat, 1x4) m = FN(mzero_m, u64_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u64_rne_sat, accx4) a = FN(mcopy_m2a, u64_rne_sat, accx4) (m);
  TYPE(u64_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u64_rne_sat, 1x4) result = FN(mcopy_a2m, u64_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u64_rne_sat, accx4) ();
  TYPE(u64_rne_sat, accx4) zero = FN(mzero_acc, u64_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_42_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rdn_sat, 1x1) d = FN(mconv_ew, u64_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rdn_sat, 1x1) copy = FN(mcopy_m2m, u64_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u64_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rdn_sat, 1x2) group = FN(mconcat_m, u64_rdn_sat, 1x2) (copy, copy);
  TYPE(u64_rdn_sat, 1x1) half = FN(mextract, u64_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_42_1 (void)
{
  TYPE(u64_rdn_sat, 1x1) m = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rdn_sat, accx1) a = FN(mcopy_m2a, u64_rdn_sat, accx1) (m);
  TYPE(u64_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rdn_sat, 1x1) result = FN(mcopy_a2m, u64_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rdn_sat, accx1) ();
  TYPE(u64_rdn_sat, accx1) zero = FN(mzero_acc, u64_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_42_2 (void)
{
  TYPE(u64_rdn_sat, 1x2) m = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rdn_sat, accx2) a = FN(mcopy_m2a, u64_rdn_sat, accx2) (m);
  TYPE(u64_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rdn_sat, 1x2) result = FN(mcopy_a2m, u64_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rdn_sat, accx2) ();
  TYPE(u64_rdn_sat, accx2) zero = FN(mzero_acc, u64_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_42_4 (void)
{
  TYPE(u64_rdn_sat, 1x4) m = FN(mzero_m, u64_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u64_rdn_sat, accx4) a = FN(mcopy_m2a, u64_rdn_sat, accx4) (m);
  TYPE(u64_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u64_rdn_sat, 1x4) result = FN(mcopy_a2m, u64_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u64_rdn_sat, accx4) ();
  TYPE(u64_rdn_sat, accx4) zero = FN(mzero_acc, u64_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_43_0 (void)
{
  TYPE(i64_rod, 1x1) s = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u64_rod_sat, 1x1) d = FN(mconv_ew, u64_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x1) back = FN(mconv_ew, i64_rod, 1x1) (d);
  TYPE(u64_rod_sat, 1x1) copy = FN(mcopy_m2m, u64_rod_sat, 1x1) (d);
  d = FN(mclear_m, u64_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rod_sat, 1x2) group = FN(mconcat_m, u64_rod_sat, 1x2) (copy, copy);
  TYPE(u64_rod_sat, 1x1) half = FN(mextract, u64_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_43_1 (void)
{
  TYPE(u64_rod_sat, 1x1) m = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u64_rod_sat, accx1) a = FN(mcopy_m2a, u64_rod_sat, accx1) (m);
  TYPE(u64_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u64_rod_sat, 1x1) result = FN(mcopy_a2m, u64_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u64_rod_sat, accx1) ();
  TYPE(u64_rod_sat, accx1) zero = FN(mzero_acc, u64_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_43_2 (void)
{
  TYPE(u64_rod_sat, 1x2) m = FN(mzero_m, u64_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rod_sat, accx2) a = FN(mcopy_m2a, u64_rod_sat, accx2) (m);
  TYPE(u64_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rod_sat, 1x2) result = FN(mcopy_a2m, u64_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rod_sat, accx2) ();
  TYPE(u64_rod_sat, accx2) zero = FN(mzero_acc, u64_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_43_4 (void)
{
  TYPE(u64_rod_sat, 1x4) m = FN(mzero_m, u64_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u64_rod_sat, accx4) a = FN(mcopy_m2a, u64_rod_sat, accx4) (m);
  TYPE(u64_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u64_rod_sat, 1x4) result = FN(mcopy_a2m, u64_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u64_rod_sat, accx4) ();
  TYPE(u64_rod_sat, accx4) zero = FN(mzero_acc, u64_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_44_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rnu_sat, 1x1) d = FN(mconv_ew, i64_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rnu_sat, 1x1) copy = FN(mcopy_m2m, i64_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i64_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rnu_sat, 1x2) group = FN(mconcat_m, i64_rnu_sat, 1x2) (copy, copy);
  TYPE(i64_rnu_sat, 1x1) half = FN(mextract, i64_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_44_1 (void)
{
  TYPE(i64_rnu_sat, 1x1) m = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rnu_sat, accx1) a = FN(mcopy_m2a, i64_rnu_sat, accx1) (m);
  TYPE(i64_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rnu_sat, 1x1) result = FN(mcopy_a2m, i64_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rnu_sat, accx1) ();
  TYPE(i64_rnu_sat, accx1) zero = FN(mzero_acc, i64_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_44_2 (void)
{
  TYPE(i64_rnu_sat, 1x2) m = FN(mzero_m, i64_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rnu_sat, accx2) a = FN(mcopy_m2a, i64_rnu_sat, accx2) (m);
  TYPE(i64_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rnu_sat, 1x2) result = FN(mcopy_a2m, i64_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rnu_sat, accx2) ();
  TYPE(i64_rnu_sat, accx2) zero = FN(mzero_acc, i64_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_44_4 (void)
{
  TYPE(i64_rnu_sat, 1x4) m = FN(mzero_m, i64_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i64_rnu_sat, accx4) a = FN(mcopy_m2a, i64_rnu_sat, accx4) (m);
  TYPE(i64_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i64_rnu_sat, 1x4) result = FN(mcopy_a2m, i64_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i64_rnu_sat, accx4) ();
  TYPE(i64_rnu_sat, accx4) zero = FN(mzero_acc, i64_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_45_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rne_sat, 1x1) d = FN(mconv_ew, i64_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rne_sat, 1x1) copy = FN(mcopy_m2m, i64_rne_sat, 1x1) (d);
  d = FN(mclear_m, i64_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rne_sat, 1x2) group = FN(mconcat_m, i64_rne_sat, 1x2) (copy, copy);
  TYPE(i64_rne_sat, 1x1) half = FN(mextract, i64_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_45_1 (void)
{
  TYPE(i64_rne_sat, 1x1) m = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rne_sat, accx1) a = FN(mcopy_m2a, i64_rne_sat, accx1) (m);
  TYPE(i64_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rne_sat, 1x1) result = FN(mcopy_a2m, i64_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rne_sat, accx1) ();
  TYPE(i64_rne_sat, accx1) zero = FN(mzero_acc, i64_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_45_2 (void)
{
  TYPE(i64_rne_sat, 1x2) m = FN(mzero_m, i64_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rne_sat, accx2) a = FN(mcopy_m2a, i64_rne_sat, accx2) (m);
  TYPE(i64_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rne_sat, 1x2) result = FN(mcopy_a2m, i64_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rne_sat, accx2) ();
  TYPE(i64_rne_sat, accx2) zero = FN(mzero_acc, i64_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_45_4 (void)
{
  TYPE(i64_rne_sat, 1x4) m = FN(mzero_m, i64_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i64_rne_sat, accx4) a = FN(mcopy_m2a, i64_rne_sat, accx4) (m);
  TYPE(i64_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i64_rne_sat, 1x4) result = FN(mcopy_a2m, i64_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i64_rne_sat, accx4) ();
  TYPE(i64_rne_sat, accx4) zero = FN(mzero_acc, i64_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_46_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rdn_sat, 1x1) d = FN(mconv_ew, i64_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rdn_sat, 1x1) copy = FN(mcopy_m2m, i64_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i64_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rdn_sat, 1x2) group = FN(mconcat_m, i64_rdn_sat, 1x2) (copy, copy);
  TYPE(i64_rdn_sat, 1x1) half = FN(mextract, i64_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_46_1 (void)
{
  TYPE(i64_rdn_sat, 1x1) m = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rdn_sat, accx1) a = FN(mcopy_m2a, i64_rdn_sat, accx1) (m);
  TYPE(i64_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rdn_sat, 1x1) result = FN(mcopy_a2m, i64_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rdn_sat, accx1) ();
  TYPE(i64_rdn_sat, accx1) zero = FN(mzero_acc, i64_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_46_2 (void)
{
  TYPE(i64_rdn_sat, 1x2) m = FN(mzero_m, i64_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rdn_sat, accx2) a = FN(mcopy_m2a, i64_rdn_sat, accx2) (m);
  TYPE(i64_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rdn_sat, 1x2) result = FN(mcopy_a2m, i64_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rdn_sat, accx2) ();
  TYPE(i64_rdn_sat, accx2) zero = FN(mzero_acc, i64_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_46_4 (void)
{
  TYPE(i64_rdn_sat, 1x4) m = FN(mzero_m, i64_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i64_rdn_sat, accx4) a = FN(mcopy_m2a, i64_rdn_sat, accx4) (m);
  TYPE(i64_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i64_rdn_sat, 1x4) result = FN(mcopy_a2m, i64_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i64_rdn_sat, accx4) ();
  TYPE(i64_rdn_sat, accx4) zero = FN(mzero_acc, i64_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_47_0 (void)
{
  TYPE(u64_rod, 1x1) s = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i64_rod_sat, 1x1) d = FN(mconv_ew, i64_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x1) back = FN(mconv_ew, u64_rod, 1x1) (d);
  TYPE(i64_rod_sat, 1x1) copy = FN(mcopy_m2m, i64_rod_sat, 1x1) (d);
  d = FN(mclear_m, i64_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rod_sat, 1x2) group = FN(mconcat_m, i64_rod_sat, 1x2) (copy, copy);
  TYPE(i64_rod_sat, 1x1) half = FN(mextract, i64_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_47_1 (void)
{
  TYPE(i64_rod_sat, 1x1) m = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i64_rod_sat, accx1) a = FN(mcopy_m2a, i64_rod_sat, accx1) (m);
  TYPE(i64_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i64_rod_sat, 1x1) result = FN(mcopy_a2m, i64_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i64_rod_sat, accx1) ();
  TYPE(i64_rod_sat, accx1) zero = FN(mzero_acc, i64_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_47_2 (void)
{
  TYPE(i64_rod_sat, 1x2) m = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rod_sat, accx2) a = FN(mcopy_m2a, i64_rod_sat, accx2) (m);
  TYPE(i64_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rod_sat, 1x2) result = FN(mcopy_a2m, i64_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rod_sat, accx2) ();
  TYPE(i64_rod_sat, accx2) zero = FN(mzero_acc, i64_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_47_4 (void)
{
  TYPE(i64_rod_sat, 1x4) m = FN(mzero_m, i64_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i64_rod_sat, accx4) a = FN(mcopy_m2a, i64_rod_sat, accx4) (m);
  TYPE(i64_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i64_rod_sat, 1x4) result = FN(mcopy_a2m, i64_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i64_rod_sat, accx4) ();
  TYPE(i64_rod_sat, accx4) zero = FN(mzero_acc, i64_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_48_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rnu_sat, 1x1) d = FN(mconv_ew, u128_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rnu_sat, 1x1) copy = FN(mcopy_m2m, u128_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u128_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u128_rnu_sat, 1x2) group = FN(mconcat_m, u128_rnu_sat, 1x2) (copy, copy);
  TYPE(u128_rnu_sat, 1x1) half = FN(mextract, u128_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_48_1 (void)
{
  TYPE(u128_rnu_sat, 1x1) m = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rnu_sat, accx1) a = FN(mcopy_m2a, u128_rnu_sat, accx1) (m);
  TYPE(u128_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rnu_sat, 1x1) result = FN(mcopy_a2m, u128_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rnu_sat, accx1) ();
  TYPE(u128_rnu_sat, accx1) zero = FN(mzero_acc, u128_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_48_2 (void)
{
  TYPE(u128_rnu_sat, 1x2) m = FN(mzero_m, u128_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u128_rnu_sat, accx2) a = FN(mcopy_m2a, u128_rnu_sat, accx2) (m);
  TYPE(u128_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u128_rnu_sat, 1x2) result = FN(mcopy_a2m, u128_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u128_rnu_sat, accx2) ();
  TYPE(u128_rnu_sat, accx2) zero = FN(mzero_acc, u128_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_49_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rne_sat, 1x1) d = FN(mconv_ew, u128_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rne_sat, 1x1) copy = FN(mcopy_m2m, u128_rne_sat, 1x1) (d);
  d = FN(mclear_m, u128_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u128_rne_sat, 1x2) group = FN(mconcat_m, u128_rne_sat, 1x2) (copy, copy);
  TYPE(u128_rne_sat, 1x1) half = FN(mextract, u128_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_49_1 (void)
{
  TYPE(u128_rne_sat, 1x1) m = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rne_sat, accx1) a = FN(mcopy_m2a, u128_rne_sat, accx1) (m);
  TYPE(u128_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rne_sat, 1x1) result = FN(mcopy_a2m, u128_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rne_sat, accx1) ();
  TYPE(u128_rne_sat, accx1) zero = FN(mzero_acc, u128_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_49_2 (void)
{
  TYPE(u128_rne_sat, 1x2) m = FN(mzero_m, u128_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u128_rne_sat, accx2) a = FN(mcopy_m2a, u128_rne_sat, accx2) (m);
  TYPE(u128_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u128_rne_sat, 1x2) result = FN(mcopy_a2m, u128_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u128_rne_sat, accx2) ();
  TYPE(u128_rne_sat, accx2) zero = FN(mzero_acc, u128_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_50_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rdn_sat, 1x1) d = FN(mconv_ew, u128_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rdn_sat, 1x1) copy = FN(mcopy_m2m, u128_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u128_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u128_rdn_sat, 1x2) group = FN(mconcat_m, u128_rdn_sat, 1x2) (copy, copy);
  TYPE(u128_rdn_sat, 1x1) half = FN(mextract, u128_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_50_1 (void)
{
  TYPE(u128_rdn_sat, 1x1) m = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rdn_sat, accx1) a = FN(mcopy_m2a, u128_rdn_sat, accx1) (m);
  TYPE(u128_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rdn_sat, 1x1) result = FN(mcopy_a2m, u128_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rdn_sat, accx1) ();
  TYPE(u128_rdn_sat, accx1) zero = FN(mzero_acc, u128_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_50_2 (void)
{
  TYPE(u128_rdn_sat, 1x2) m = FN(mzero_m, u128_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u128_rdn_sat, accx2) a = FN(mcopy_m2a, u128_rdn_sat, accx2) (m);
  TYPE(u128_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u128_rdn_sat, 1x2) result = FN(mcopy_a2m, u128_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u128_rdn_sat, accx2) ();
  TYPE(u128_rdn_sat, accx2) zero = FN(mzero_acc, u128_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_51_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rod_sat, 1x1) d = FN(mconv_ew, u128_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rod_sat, 1x1) copy = FN(mcopy_m2m, u128_rod_sat, 1x1) (d);
  d = FN(mclear_m, u128_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u128_rod_sat, 1x2) group = FN(mconcat_m, u128_rod_sat, 1x2) (copy, copy);
  TYPE(u128_rod_sat, 1x1) half = FN(mextract, u128_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_51_1 (void)
{
  TYPE(u128_rod_sat, 1x1) m = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rod_sat, accx1) a = FN(mcopy_m2a, u128_rod_sat, accx1) (m);
  TYPE(u128_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rod_sat, 1x1) result = FN(mcopy_a2m, u128_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rod_sat, accx1) ();
  TYPE(u128_rod_sat, accx1) zero = FN(mzero_acc, u128_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_51_2 (void)
{
  TYPE(u128_rod_sat, 1x2) m = FN(mzero_m, u128_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u128_rod_sat, accx2) a = FN(mcopy_m2a, u128_rod_sat, accx2) (m);
  TYPE(u128_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u128_rod_sat, 1x2) result = FN(mcopy_a2m, u128_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u128_rod_sat, accx2) ();
  TYPE(u128_rod_sat, accx2) zero = FN(mzero_acc, u128_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_52_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rnu_sat, 1x1) d = FN(mconv_ew, i128_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rnu_sat, 1x1) copy = FN(mcopy_m2m, i128_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i128_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i128_rnu_sat, 1x2) group = FN(mconcat_m, i128_rnu_sat, 1x2) (copy, copy);
  TYPE(i128_rnu_sat, 1x1) half = FN(mextract, i128_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_52_1 (void)
{
  TYPE(i128_rnu_sat, 1x1) m = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rnu_sat, accx1) a = FN(mcopy_m2a, i128_rnu_sat, accx1) (m);
  TYPE(i128_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rnu_sat, 1x1) result = FN(mcopy_a2m, i128_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rnu_sat, accx1) ();
  TYPE(i128_rnu_sat, accx1) zero = FN(mzero_acc, i128_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_52_2 (void)
{
  TYPE(i128_rnu_sat, 1x2) m = FN(mzero_m, i128_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i128_rnu_sat, accx2) a = FN(mcopy_m2a, i128_rnu_sat, accx2) (m);
  TYPE(i128_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i128_rnu_sat, 1x2) result = FN(mcopy_a2m, i128_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i128_rnu_sat, accx2) ();
  TYPE(i128_rnu_sat, accx2) zero = FN(mzero_acc, i128_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_53_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rne_sat, 1x1) d = FN(mconv_ew, i128_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rne_sat, 1x1) copy = FN(mcopy_m2m, i128_rne_sat, 1x1) (d);
  d = FN(mclear_m, i128_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i128_rne_sat, 1x2) group = FN(mconcat_m, i128_rne_sat, 1x2) (copy, copy);
  TYPE(i128_rne_sat, 1x1) half = FN(mextract, i128_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_53_1 (void)
{
  TYPE(i128_rne_sat, 1x1) m = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rne_sat, accx1) a = FN(mcopy_m2a, i128_rne_sat, accx1) (m);
  TYPE(i128_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rne_sat, 1x1) result = FN(mcopy_a2m, i128_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rne_sat, accx1) ();
  TYPE(i128_rne_sat, accx1) zero = FN(mzero_acc, i128_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_53_2 (void)
{
  TYPE(i128_rne_sat, 1x2) m = FN(mzero_m, i128_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i128_rne_sat, accx2) a = FN(mcopy_m2a, i128_rne_sat, accx2) (m);
  TYPE(i128_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i128_rne_sat, 1x2) result = FN(mcopy_a2m, i128_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i128_rne_sat, accx2) ();
  TYPE(i128_rne_sat, accx2) zero = FN(mzero_acc, i128_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_54_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rdn_sat, 1x1) d = FN(mconv_ew, i128_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rdn_sat, 1x1) copy = FN(mcopy_m2m, i128_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i128_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i128_rdn_sat, 1x2) group = FN(mconcat_m, i128_rdn_sat, 1x2) (copy, copy);
  TYPE(i128_rdn_sat, 1x1) half = FN(mextract, i128_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_54_1 (void)
{
  TYPE(i128_rdn_sat, 1x1) m = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rdn_sat, accx1) a = FN(mcopy_m2a, i128_rdn_sat, accx1) (m);
  TYPE(i128_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rdn_sat, 1x1) result = FN(mcopy_a2m, i128_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rdn_sat, accx1) ();
  TYPE(i128_rdn_sat, accx1) zero = FN(mzero_acc, i128_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_54_2 (void)
{
  TYPE(i128_rdn_sat, 1x2) m = FN(mzero_m, i128_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i128_rdn_sat, accx2) a = FN(mcopy_m2a, i128_rdn_sat, accx2) (m);
  TYPE(i128_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i128_rdn_sat, 1x2) result = FN(mcopy_a2m, i128_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i128_rdn_sat, accx2) ();
  TYPE(i128_rdn_sat, accx2) zero = FN(mzero_acc, i128_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_55_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rod_sat, 1x1) d = FN(mconv_ew, i128_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rod_sat, 1x1) copy = FN(mcopy_m2m, i128_rod_sat, 1x1) (d);
  d = FN(mclear_m, i128_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i128_rod_sat, 1x2) group = FN(mconcat_m, i128_rod_sat, 1x2) (copy, copy);
  TYPE(i128_rod_sat, 1x1) half = FN(mextract, i128_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_55_1 (void)
{
  TYPE(i128_rod_sat, 1x1) m = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rod_sat, accx1) a = FN(mcopy_m2a, i128_rod_sat, accx1) (m);
  TYPE(i128_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rod_sat, 1x1) result = FN(mcopy_a2m, i128_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rod_sat, accx1) ();
  TYPE(i128_rod_sat, accx1) zero = FN(mzero_acc, i128_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_55_2 (void)
{
  TYPE(i128_rod_sat, 1x2) m = FN(mzero_m, i128_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i128_rod_sat, accx2) a = FN(mcopy_m2a, i128_rod_sat, accx2) (m);
  TYPE(i128_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i128_rod_sat, 1x2) result = FN(mcopy_a2m, i128_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i128_rod_sat, accx2) ();
  TYPE(i128_rod_sat, accx2) zero = FN(mzero_acc, i128_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
#endif

#if TEST_UDS == 128
void value_0_0 (void)
{
  TYPE(i8_rod, 1x32) s = FN(mzero_m, i8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 1x32) d = FN(mconv_ew, u4_rnu, 1x32) (s);
  d = FN(mabs_ew, u4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 1x32) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x32) back = FN(mconv_ew, i8_rod, 1x32) (d);
  TYPE(u4_rnu, 1x32) copy = FN(mcopy_m2m, u4_rnu, 1x32) (d);
  d = FN(mclear_m, u4_rnu, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_0_1 (void)
{
  TYPE(i8_rod, 32x1) s = FN(mzero_m, i8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu, 32x1) d = FN(mconv_ew, u4_rnu, 32x1) (s);
  d = FN(mabs_ew, u4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu, 32x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 32x1) back = FN(mconv_ew, i8_rod, 32x1) (d);
  TYPE(u4_rnu, 32x1) copy = FN(mcopy_m2m, u4_rnu, 32x1) (d);
  d = FN(mclear_m, u4_rnu, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_1_0 (void)
{
  TYPE(i8_rod, 1x32) s = FN(mzero_m, i8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(u4_rne, 1x32) d = FN(mconv_ew, u4_rne, 1x32) (s);
  d = FN(mabs_ew, u4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 1x32) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x32) back = FN(mconv_ew, i8_rod, 1x32) (d);
  TYPE(u4_rne, 1x32) copy = FN(mcopy_m2m, u4_rne, 1x32) (d);
  d = FN(mclear_m, u4_rne, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_1_1 (void)
{
  TYPE(i8_rod, 32x1) s = FN(mzero_m, i8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(u4_rne, 32x1) d = FN(mconv_ew, u4_rne, 32x1) (s);
  d = FN(mabs_ew, u4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne, 32x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 32x1) back = FN(mconv_ew, i8_rod, 32x1) (d);
  TYPE(u4_rne, 32x1) copy = FN(mcopy_m2m, u4_rne, 32x1) (d);
  d = FN(mclear_m, u4_rne, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_2_0 (void)
{
  TYPE(i8_rod, 1x32) s = FN(mzero_m, i8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 1x32) d = FN(mconv_ew, u4_rdn, 1x32) (s);
  d = FN(mabs_ew, u4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 1x32) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x32) back = FN(mconv_ew, i8_rod, 1x32) (d);
  TYPE(u4_rdn, 1x32) copy = FN(mcopy_m2m, u4_rdn, 1x32) (d);
  d = FN(mclear_m, u4_rdn, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_2_1 (void)
{
  TYPE(i8_rod, 32x1) s = FN(mzero_m, i8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn, 32x1) d = FN(mconv_ew, u4_rdn, 32x1) (s);
  d = FN(mabs_ew, u4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn, 32x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 32x1) back = FN(mconv_ew, i8_rod, 32x1) (d);
  TYPE(u4_rdn, 32x1) copy = FN(mcopy_m2m, u4_rdn, 32x1) (d);
  d = FN(mclear_m, u4_rdn, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_3_0 (void)
{
  TYPE(i8_rod, 1x32) s = FN(mzero_m, i8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(u4_rod, 1x32) d = FN(mconv_ew, u4_rod, 1x32) (s);
  d = FN(mabs_ew, u4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 1x32) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x32) back = FN(mconv_ew, i8_rod, 1x32) (d);
  TYPE(u4_rod, 1x32) copy = FN(mcopy_m2m, u4_rod, 1x32) (d);
  d = FN(mclear_m, u4_rod, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_3_1 (void)
{
  TYPE(i8_rod, 32x1) s = FN(mzero_m, i8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(u4_rod, 32x1) d = FN(mconv_ew, u4_rod, 32x1) (s);
  d = FN(mabs_ew, u4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod, 32x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 32x1) back = FN(mconv_ew, i8_rod, 32x1) (d);
  TYPE(u4_rod, 32x1) copy = FN(mcopy_m2m, u4_rod, 32x1) (d);
  d = FN(mclear_m, u4_rod, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_4_0 (void)
{
  TYPE(u8_rod, 1x32) s = FN(mzero_m, u8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 1x32) d = FN(mconv_ew, i4_rnu, 1x32) (s);
  d = FN(mabs_ew, i4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 1x32) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x32) back = FN(mconv_ew, u8_rod, 1x32) (d);
  TYPE(i4_rnu, 1x32) copy = FN(mcopy_m2m, i4_rnu, 1x32) (d);
  d = FN(mclear_m, i4_rnu, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_4_1 (void)
{
  TYPE(u8_rod, 32x1) s = FN(mzero_m, u8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu, 32x1) d = FN(mconv_ew, i4_rnu, 32x1) (s);
  d = FN(mabs_ew, i4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu, 32x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 32x1) back = FN(mconv_ew, u8_rod, 32x1) (d);
  TYPE(i4_rnu, 32x1) copy = FN(mcopy_m2m, i4_rnu, 32x1) (d);
  d = FN(mclear_m, i4_rnu, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_5_0 (void)
{
  TYPE(u8_rod, 1x32) s = FN(mzero_m, u8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(i4_rne, 1x32) d = FN(mconv_ew, i4_rne, 1x32) (s);
  d = FN(mabs_ew, i4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 1x32) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x32) back = FN(mconv_ew, u8_rod, 1x32) (d);
  TYPE(i4_rne, 1x32) copy = FN(mcopy_m2m, i4_rne, 1x32) (d);
  d = FN(mclear_m, i4_rne, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_5_1 (void)
{
  TYPE(u8_rod, 32x1) s = FN(mzero_m, u8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(i4_rne, 32x1) d = FN(mconv_ew, i4_rne, 32x1) (s);
  d = FN(mabs_ew, i4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne, 32x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 32x1) back = FN(mconv_ew, u8_rod, 32x1) (d);
  TYPE(i4_rne, 32x1) copy = FN(mcopy_m2m, i4_rne, 32x1) (d);
  d = FN(mclear_m, i4_rne, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_6_0 (void)
{
  TYPE(u8_rod, 1x32) s = FN(mzero_m, u8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 1x32) d = FN(mconv_ew, i4_rdn, 1x32) (s);
  d = FN(mabs_ew, i4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 1x32) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x32) back = FN(mconv_ew, u8_rod, 1x32) (d);
  TYPE(i4_rdn, 1x32) copy = FN(mcopy_m2m, i4_rdn, 1x32) (d);
  d = FN(mclear_m, i4_rdn, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_6_1 (void)
{
  TYPE(u8_rod, 32x1) s = FN(mzero_m, u8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn, 32x1) d = FN(mconv_ew, i4_rdn, 32x1) (s);
  d = FN(mabs_ew, i4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn, 32x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 32x1) back = FN(mconv_ew, u8_rod, 32x1) (d);
  TYPE(i4_rdn, 32x1) copy = FN(mcopy_m2m, i4_rdn, 32x1) (d);
  d = FN(mclear_m, i4_rdn, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_7_0 (void)
{
  TYPE(u8_rod, 1x32) s = FN(mzero_m, u8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(i4_rod, 1x32) d = FN(mconv_ew, i4_rod, 1x32) (s);
  d = FN(mabs_ew, i4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 1x32) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x32) back = FN(mconv_ew, u8_rod, 1x32) (d);
  TYPE(i4_rod, 1x32) copy = FN(mcopy_m2m, i4_rod, 1x32) (d);
  d = FN(mclear_m, i4_rod, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_7_1 (void)
{
  TYPE(u8_rod, 32x1) s = FN(mzero_m, u8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(i4_rod, 32x1) d = FN(mconv_ew, i4_rod, 32x1) (s);
  d = FN(mabs_ew, i4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod, 32x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 32x1) back = FN(mconv_ew, u8_rod, 32x1) (d);
  TYPE(i4_rod, 32x1) copy = FN(mcopy_m2m, i4_rod, 32x1) (d);
  d = FN(mclear_m, i4_rod, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_8_0 (void)
{
  TYPE(i8_rod, 1x32) s = FN(mzero_m, i8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 1x32) d = FN(mconv_ew, u4_rnu_sat, 1x32) (s);
  d = FN(mabs_ew, u4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 1x32) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x32) back = FN(mconv_ew, i8_rod, 1x32) (d);
  TYPE(u4_rnu_sat, 1x32) copy = FN(mcopy_m2m, u4_rnu_sat, 1x32) (d);
  d = FN(mclear_m, u4_rnu_sat, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_8_1 (void)
{
  TYPE(i8_rod, 32x1) s = FN(mzero_m, i8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(u4_rnu_sat, 32x1) d = FN(mconv_ew, u4_rnu_sat, 32x1) (s);
  d = FN(mabs_ew, u4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rnu_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rnu_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rnu_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rnu_sat, 32x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 32x1) back = FN(mconv_ew, i8_rod, 32x1) (d);
  TYPE(u4_rnu_sat, 32x1) copy = FN(mcopy_m2m, u4_rnu_sat, 32x1) (d);
  d = FN(mclear_m, u4_rnu_sat, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_9_0 (void)
{
  TYPE(i8_rod, 1x32) s = FN(mzero_m, i8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 1x32) d = FN(mconv_ew, u4_rne_sat, 1x32) (s);
  d = FN(mabs_ew, u4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 1x32) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x32) back = FN(mconv_ew, i8_rod, 1x32) (d);
  TYPE(u4_rne_sat, 1x32) copy = FN(mcopy_m2m, u4_rne_sat, 1x32) (d);
  d = FN(mclear_m, u4_rne_sat, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_9_1 (void)
{
  TYPE(i8_rod, 32x1) s = FN(mzero_m, i8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(u4_rne_sat, 32x1) d = FN(mconv_ew, u4_rne_sat, 32x1) (s);
  d = FN(mabs_ew, u4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rne_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rne_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rne_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rne_sat, 32x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 32x1) back = FN(mconv_ew, i8_rod, 32x1) (d);
  TYPE(u4_rne_sat, 32x1) copy = FN(mcopy_m2m, u4_rne_sat, 32x1) (d);
  d = FN(mclear_m, u4_rne_sat, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_10_0 (void)
{
  TYPE(i8_rod, 1x32) s = FN(mzero_m, i8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 1x32) d = FN(mconv_ew, u4_rdn_sat, 1x32) (s);
  d = FN(mabs_ew, u4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 1x32) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x32) back = FN(mconv_ew, i8_rod, 1x32) (d);
  TYPE(u4_rdn_sat, 1x32) copy = FN(mcopy_m2m, u4_rdn_sat, 1x32) (d);
  d = FN(mclear_m, u4_rdn_sat, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_10_1 (void)
{
  TYPE(i8_rod, 32x1) s = FN(mzero_m, i8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(u4_rdn_sat, 32x1) d = FN(mconv_ew, u4_rdn_sat, 32x1) (s);
  d = FN(mabs_ew, u4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rdn_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rdn_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rdn_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rdn_sat, 32x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 32x1) back = FN(mconv_ew, i8_rod, 32x1) (d);
  TYPE(u4_rdn_sat, 32x1) copy = FN(mcopy_m2m, u4_rdn_sat, 32x1) (d);
  d = FN(mclear_m, u4_rdn_sat, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_11_0 (void)
{
  TYPE(i8_rod, 1x32) s = FN(mzero_m, i8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 1x32) d = FN(mconv_ew, u4_rod_sat, 1x32) (s);
  d = FN(mabs_ew, u4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 1x32) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x32) back = FN(mconv_ew, i8_rod, 1x32) (d);
  TYPE(u4_rod_sat, 1x32) copy = FN(mcopy_m2m, u4_rod_sat, 1x32) (d);
  d = FN(mclear_m, u4_rod_sat, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_11_1 (void)
{
  TYPE(i8_rod, 32x1) s = FN(mzero_m, i8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(u4_rod_sat, 32x1) d = FN(mconv_ew, u4_rod_sat, 32x1) (s);
  d = FN(mabs_ew, u4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u4_rod_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u4_rod_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u4_rod_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u4_rod_sat, 32x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 32x1) back = FN(mconv_ew, i8_rod, 32x1) (d);
  TYPE(u4_rod_sat, 32x1) copy = FN(mcopy_m2m, u4_rod_sat, 32x1) (d);
  d = FN(mclear_m, u4_rod_sat, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_12_0 (void)
{
  TYPE(u8_rod, 1x32) s = FN(mzero_m, u8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 1x32) d = FN(mconv_ew, i4_rnu_sat, 1x32) (s);
  d = FN(mabs_ew, i4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 1x32) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x32) back = FN(mconv_ew, u8_rod, 1x32) (d);
  TYPE(i4_rnu_sat, 1x32) copy = FN(mcopy_m2m, i4_rnu_sat, 1x32) (d);
  d = FN(mclear_m, i4_rnu_sat, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_12_1 (void)
{
  TYPE(u8_rod, 32x1) s = FN(mzero_m, u8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(i4_rnu_sat, 32x1) d = FN(mconv_ew, i4_rnu_sat, 32x1) (s);
  d = FN(mabs_ew, i4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rnu_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rnu_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rnu_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rnu_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rnu_sat, 32x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 32x1) back = FN(mconv_ew, u8_rod, 32x1) (d);
  TYPE(i4_rnu_sat, 32x1) copy = FN(mcopy_m2m, i4_rnu_sat, 32x1) (d);
  d = FN(mclear_m, i4_rnu_sat, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_13_0 (void)
{
  TYPE(u8_rod, 1x32) s = FN(mzero_m, u8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 1x32) d = FN(mconv_ew, i4_rne_sat, 1x32) (s);
  d = FN(mabs_ew, i4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 1x32) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x32) back = FN(mconv_ew, u8_rod, 1x32) (d);
  TYPE(i4_rne_sat, 1x32) copy = FN(mcopy_m2m, i4_rne_sat, 1x32) (d);
  d = FN(mclear_m, i4_rne_sat, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_13_1 (void)
{
  TYPE(u8_rod, 32x1) s = FN(mzero_m, u8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(i4_rne_sat, 32x1) d = FN(mconv_ew, i4_rne_sat, 32x1) (s);
  d = FN(mabs_ew, i4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rne_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rne_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rne_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rne_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rne_sat, 32x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 32x1) back = FN(mconv_ew, u8_rod, 32x1) (d);
  TYPE(i4_rne_sat, 32x1) copy = FN(mcopy_m2m, i4_rne_sat, 32x1) (d);
  d = FN(mclear_m, i4_rne_sat, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_14_0 (void)
{
  TYPE(u8_rod, 1x32) s = FN(mzero_m, u8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 1x32) d = FN(mconv_ew, i4_rdn_sat, 1x32) (s);
  d = FN(mabs_ew, i4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 1x32) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x32) back = FN(mconv_ew, u8_rod, 1x32) (d);
  TYPE(i4_rdn_sat, 1x32) copy = FN(mcopy_m2m, i4_rdn_sat, 1x32) (d);
  d = FN(mclear_m, i4_rdn_sat, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_14_1 (void)
{
  TYPE(u8_rod, 32x1) s = FN(mzero_m, u8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(i4_rdn_sat, 32x1) d = FN(mconv_ew, i4_rdn_sat, 32x1) (s);
  d = FN(mabs_ew, i4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rdn_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rdn_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rdn_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rdn_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rdn_sat, 32x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 32x1) back = FN(mconv_ew, u8_rod, 32x1) (d);
  TYPE(i4_rdn_sat, 32x1) copy = FN(mcopy_m2m, i4_rdn_sat, 32x1) (d);
  d = FN(mclear_m, i4_rdn_sat, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_15_0 (void)
{
  TYPE(u8_rod, 1x32) s = FN(mzero_m, u8_rod, 1x32) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 1x32) d = FN(mconv_ew, i4_rod_sat, 1x32) (s);
  d = FN(mabs_ew, i4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 1x32) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 1x32) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 1x32) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x32) back = FN(mconv_ew, u8_rod, 1x32) (d);
  TYPE(i4_rod_sat, 1x32) copy = FN(mcopy_m2m, i4_rod_sat, 1x32) (d);
  d = FN(mclear_m, i4_rod_sat, 1x32) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_15_1 (void)
{
  TYPE(u8_rod, 32x1) s = FN(mzero_m, u8_rod, 32x1) ();
  CHANGE_M(s);
  TYPE(i4_rod_sat, 32x1) d = FN(mconv_ew, i4_rod_sat, 32x1) (s);
  d = FN(mabs_ew, i4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i4_rod_sat, 32x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i4_rod_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i4_rod_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i4_rod_sat, 32x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i4_rod_sat, 32x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 32x1) back = FN(mconv_ew, u8_rod, 32x1) (d);
  TYPE(i4_rod_sat, 32x1) copy = FN(mcopy_m2m, i4_rod_sat, 32x1) (d);
  d = FN(mclear_m, i4_rod_sat, 32x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
}
void value_16_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u8_rnu_sat, 1x16) d = FN(mconv_ew, u8_rnu_sat, 1x16) (s);
  d = FN(mabs_ew, u8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rnu_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u8_rnu_sat, 1x16) copy = FN(mcopy_m2m, u8_rnu_sat, 1x16) (d);
  d = FN(mclear_m, u8_rnu_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rnu_sat, 1x32) group = FN(mconcat_m, u8_rnu_sat, 1x32) (copy, copy);
  TYPE(u8_rnu_sat, 1x16) half = FN(mextract, u8_rnu_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_16_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u8_rnu_sat, 16x1) d = FN(mconv_ew, u8_rnu_sat, 16x1) (s);
  d = FN(mabs_ew, u8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rnu_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u8_rnu_sat, 16x1) copy = FN(mcopy_m2m, u8_rnu_sat, 16x1) (d);
  d = FN(mclear_m, u8_rnu_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rnu_sat, 32x1) group = FN(mconcat_m, u8_rnu_sat, 32x1) (copy, copy);
  TYPE(u8_rnu_sat, 16x1) half = FN(mextract, u8_rnu_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_16_16 (void)
{
  TYPE(u8_rnu_sat, 1x16) m = FN(mzero_m, u8_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rnu_sat, accx16) a = FN(mcopy_m2a, u8_rnu_sat, accx16) (m);
  TYPE(u8_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rnu_sat, 1x16) result = FN(mcopy_a2m, u8_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rnu_sat, accx16) ();
  TYPE(u8_rnu_sat, accx16) zero = FN(mzero_acc, u8_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_17_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u8_rne_sat, 1x16) d = FN(mconv_ew, u8_rne_sat, 1x16) (s);
  d = FN(mabs_ew, u8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rne_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u8_rne_sat, 1x16) copy = FN(mcopy_m2m, u8_rne_sat, 1x16) (d);
  d = FN(mclear_m, u8_rne_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rne_sat, 1x32) group = FN(mconcat_m, u8_rne_sat, 1x32) (copy, copy);
  TYPE(u8_rne_sat, 1x16) half = FN(mextract, u8_rne_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_17_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u8_rne_sat, 16x1) d = FN(mconv_ew, u8_rne_sat, 16x1) (s);
  d = FN(mabs_ew, u8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rne_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u8_rne_sat, 16x1) copy = FN(mcopy_m2m, u8_rne_sat, 16x1) (d);
  d = FN(mclear_m, u8_rne_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rne_sat, 32x1) group = FN(mconcat_m, u8_rne_sat, 32x1) (copy, copy);
  TYPE(u8_rne_sat, 16x1) half = FN(mextract, u8_rne_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_17_16 (void)
{
  TYPE(u8_rne_sat, 1x16) m = FN(mzero_m, u8_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rne_sat, accx16) a = FN(mcopy_m2a, u8_rne_sat, accx16) (m);
  TYPE(u8_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rne_sat, 1x16) result = FN(mcopy_a2m, u8_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rne_sat, accx16) ();
  TYPE(u8_rne_sat, accx16) zero = FN(mzero_acc, u8_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_18_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u8_rdn_sat, 1x16) d = FN(mconv_ew, u8_rdn_sat, 1x16) (s);
  d = FN(mabs_ew, u8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rdn_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u8_rdn_sat, 1x16) copy = FN(mcopy_m2m, u8_rdn_sat, 1x16) (d);
  d = FN(mclear_m, u8_rdn_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rdn_sat, 1x32) group = FN(mconcat_m, u8_rdn_sat, 1x32) (copy, copy);
  TYPE(u8_rdn_sat, 1x16) half = FN(mextract, u8_rdn_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_18_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u8_rdn_sat, 16x1) d = FN(mconv_ew, u8_rdn_sat, 16x1) (s);
  d = FN(mabs_ew, u8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rdn_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u8_rdn_sat, 16x1) copy = FN(mcopy_m2m, u8_rdn_sat, 16x1) (d);
  d = FN(mclear_m, u8_rdn_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rdn_sat, 32x1) group = FN(mconcat_m, u8_rdn_sat, 32x1) (copy, copy);
  TYPE(u8_rdn_sat, 16x1) half = FN(mextract, u8_rdn_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_18_16 (void)
{
  TYPE(u8_rdn_sat, 1x16) m = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rdn_sat, accx16) a = FN(mcopy_m2a, u8_rdn_sat, accx16) (m);
  TYPE(u8_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rdn_sat, 1x16) result = FN(mcopy_a2m, u8_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rdn_sat, accx16) ();
  TYPE(u8_rdn_sat, accx16) zero = FN(mzero_acc, u8_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_19_0 (void)
{
  TYPE(i8_rod, 1x16) s = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(u8_rod_sat, 1x16) d = FN(mconv_ew, u8_rod_sat, 1x16) (s);
  d = FN(mabs_ew, u8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rod_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(i8_rod, 1x16) back = FN(mconv_ew, i8_rod, 1x16) (d);
  TYPE(u8_rod_sat, 1x16) copy = FN(mcopy_m2m, u8_rod_sat, 1x16) (d);
  d = FN(mclear_m, u8_rod_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rod_sat, 1x32) group = FN(mconcat_m, u8_rod_sat, 1x32) (copy, copy);
  TYPE(u8_rod_sat, 1x16) half = FN(mextract, u8_rod_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_19_1 (void)
{
  TYPE(i8_rod, 16x1) s = FN(mzero_m, i8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(u8_rod_sat, 16x1) d = FN(mconv_ew, u8_rod_sat, 16x1) (s);
  d = FN(mabs_ew, u8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u8_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u8_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u8_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u8_rod_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(i8_rod, 16x1) back = FN(mconv_ew, i8_rod, 16x1) (d);
  TYPE(u8_rod_sat, 16x1) copy = FN(mcopy_m2m, u8_rod_sat, 16x1) (d);
  d = FN(mclear_m, u8_rod_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u8_rod_sat, 32x1) group = FN(mconcat_m, u8_rod_sat, 32x1) (copy, copy);
  TYPE(u8_rod_sat, 16x1) half = FN(mextract, u8_rod_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_19_16 (void)
{
  TYPE(u8_rod_sat, 1x16) m = FN(mzero_m, u8_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u8_rod_sat, accx16) a = FN(mcopy_m2a, u8_rod_sat, accx16) (m);
  TYPE(u8_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u8_rod_sat, 1x16) result = FN(mcopy_a2m, u8_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, u8_rod_sat, accx16) ();
  TYPE(u8_rod_sat, accx16) zero = FN(mzero_acc, u8_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_20_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i8_rnu_sat, 1x16) d = FN(mconv_ew, i8_rnu_sat, 1x16) (s);
  d = FN(mabs_ew, i8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rnu_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rnu_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rnu_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i8_rnu_sat, 1x16) copy = FN(mcopy_m2m, i8_rnu_sat, 1x16) (d);
  d = FN(mclear_m, i8_rnu_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rnu_sat, 1x32) group = FN(mconcat_m, i8_rnu_sat, 1x32) (copy, copy);
  TYPE(i8_rnu_sat, 1x16) half = FN(mextract, i8_rnu_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_20_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i8_rnu_sat, 16x1) d = FN(mconv_ew, i8_rnu_sat, 16x1) (s);
  d = FN(mabs_ew, i8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rnu_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rnu_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rnu_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i8_rnu_sat, 16x1) copy = FN(mcopy_m2m, i8_rnu_sat, 16x1) (d);
  d = FN(mclear_m, i8_rnu_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rnu_sat, 32x1) group = FN(mconcat_m, i8_rnu_sat, 32x1) (copy, copy);
  TYPE(i8_rnu_sat, 16x1) half = FN(mextract, i8_rnu_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_20_16 (void)
{
  TYPE(i8_rnu_sat, 1x16) m = FN(mzero_m, i8_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rnu_sat, accx16) a = FN(mcopy_m2a, i8_rnu_sat, accx16) (m);
  TYPE(i8_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rnu_sat, 1x16) result = FN(mcopy_a2m, i8_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rnu_sat, accx16) ();
  TYPE(i8_rnu_sat, accx16) zero = FN(mzero_acc, i8_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_21_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i8_rne_sat, 1x16) d = FN(mconv_ew, i8_rne_sat, 1x16) (s);
  d = FN(mabs_ew, i8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rne_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rne_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rne_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i8_rne_sat, 1x16) copy = FN(mcopy_m2m, i8_rne_sat, 1x16) (d);
  d = FN(mclear_m, i8_rne_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rne_sat, 1x32) group = FN(mconcat_m, i8_rne_sat, 1x32) (copy, copy);
  TYPE(i8_rne_sat, 1x16) half = FN(mextract, i8_rne_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_21_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i8_rne_sat, 16x1) d = FN(mconv_ew, i8_rne_sat, 16x1) (s);
  d = FN(mabs_ew, i8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rne_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rne_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rne_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i8_rne_sat, 16x1) copy = FN(mcopy_m2m, i8_rne_sat, 16x1) (d);
  d = FN(mclear_m, i8_rne_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rne_sat, 32x1) group = FN(mconcat_m, i8_rne_sat, 32x1) (copy, copy);
  TYPE(i8_rne_sat, 16x1) half = FN(mextract, i8_rne_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_21_16 (void)
{
  TYPE(i8_rne_sat, 1x16) m = FN(mzero_m, i8_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rne_sat, accx16) a = FN(mcopy_m2a, i8_rne_sat, accx16) (m);
  TYPE(i8_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rne_sat, 1x16) result = FN(mcopy_a2m, i8_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rne_sat, accx16) ();
  TYPE(i8_rne_sat, accx16) zero = FN(mzero_acc, i8_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_22_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i8_rdn_sat, 1x16) d = FN(mconv_ew, i8_rdn_sat, 1x16) (s);
  d = FN(mabs_ew, i8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rdn_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rdn_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rdn_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i8_rdn_sat, 1x16) copy = FN(mcopy_m2m, i8_rdn_sat, 1x16) (d);
  d = FN(mclear_m, i8_rdn_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rdn_sat, 1x32) group = FN(mconcat_m, i8_rdn_sat, 1x32) (copy, copy);
  TYPE(i8_rdn_sat, 1x16) half = FN(mextract, i8_rdn_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_22_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i8_rdn_sat, 16x1) d = FN(mconv_ew, i8_rdn_sat, 16x1) (s);
  d = FN(mabs_ew, i8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rdn_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rdn_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rdn_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i8_rdn_sat, 16x1) copy = FN(mcopy_m2m, i8_rdn_sat, 16x1) (d);
  d = FN(mclear_m, i8_rdn_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rdn_sat, 32x1) group = FN(mconcat_m, i8_rdn_sat, 32x1) (copy, copy);
  TYPE(i8_rdn_sat, 16x1) half = FN(mextract, i8_rdn_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_22_16 (void)
{
  TYPE(i8_rdn_sat, 1x16) m = FN(mzero_m, i8_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rdn_sat, accx16) a = FN(mcopy_m2a, i8_rdn_sat, accx16) (m);
  TYPE(i8_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rdn_sat, 1x16) result = FN(mcopy_a2m, i8_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rdn_sat, accx16) ();
  TYPE(i8_rdn_sat, accx16) zero = FN(mzero_acc, i8_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_23_0 (void)
{
  TYPE(u8_rod, 1x16) s = FN(mzero_m, u8_rod, 1x16) ();
  CHANGE_M(s);
  TYPE(i8_rod_sat, 1x16) d = FN(mconv_ew, i8_rod_sat, 1x16) (s);
  d = FN(mabs_ew, i8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rod_sat, 1x16) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rod_sat, 1x16) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rod_sat, 1x16) (s);
  KEEP_M(d);
  TYPE(u8_rod, 1x16) back = FN(mconv_ew, u8_rod, 1x16) (d);
  TYPE(i8_rod_sat, 1x16) copy = FN(mcopy_m2m, i8_rod_sat, 1x16) (d);
  d = FN(mclear_m, i8_rod_sat, 1x16) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rod_sat, 1x32) group = FN(mconcat_m, i8_rod_sat, 1x32) (copy, copy);
  TYPE(i8_rod_sat, 1x16) half = FN(mextract, i8_rod_sat, 1x16) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_23_1 (void)
{
  TYPE(u8_rod, 16x1) s = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE_M(s);
  TYPE(i8_rod_sat, 16x1) d = FN(mconv_ew, i8_rod_sat, 16x1) (s);
  d = FN(mabs_ew, i8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i8_rod_sat, 16x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i8_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i8_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i8_rod_sat, 16x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i8_rod_sat, 16x1) (s);
  KEEP_M(d);
  TYPE(u8_rod, 16x1) back = FN(mconv_ew, u8_rod, 16x1) (d);
  TYPE(i8_rod_sat, 16x1) copy = FN(mcopy_m2m, i8_rod_sat, 16x1) (d);
  d = FN(mclear_m, i8_rod_sat, 16x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i8_rod_sat, 32x1) group = FN(mconcat_m, i8_rod_sat, 32x1) (copy, copy);
  TYPE(i8_rod_sat, 16x1) half = FN(mextract, i8_rod_sat, 16x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_23_16 (void)
{
  TYPE(i8_rod_sat, 1x16) m = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i8_rod_sat, accx16) a = FN(mcopy_m2a, i8_rod_sat, accx16) (m);
  TYPE(i8_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i8_rod_sat, 1x16) result = FN(mcopy_a2m, i8_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, i8_rod_sat, accx16) ();
  TYPE(i8_rod_sat, accx16) zero = FN(mzero_acc, i8_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_24_0 (void)
{
  TYPE(i16_rod, 1x8) s = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u16_rnu_sat, 1x8) d = FN(mconv_ew, u16_rnu_sat, 1x8) (s);
  d = FN(mabs_ew, u16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rnu_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x8) back = FN(mconv_ew, i16_rod, 1x8) (d);
  TYPE(u16_rnu_sat, 1x8) copy = FN(mcopy_m2m, u16_rnu_sat, 1x8) (d);
  d = FN(mclear_m, u16_rnu_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rnu_sat, 1x16) group = FN(mconcat_m, u16_rnu_sat, 1x16) (copy, copy);
  TYPE(u16_rnu_sat, 1x8) half = FN(mextract, u16_rnu_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_24_1 (void)
{
  TYPE(i16_rod, 8x1) s = FN(mzero_m, i16_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u16_rnu_sat, 8x1) d = FN(mconv_ew, u16_rnu_sat, 8x1) (s);
  d = FN(mabs_ew, u16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rnu_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 8x1) back = FN(mconv_ew, i16_rod, 8x1) (d);
  TYPE(u16_rnu_sat, 8x1) copy = FN(mcopy_m2m, u16_rnu_sat, 8x1) (d);
  d = FN(mclear_m, u16_rnu_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rnu_sat, 16x1) group = FN(mconcat_m, u16_rnu_sat, 16x1) (copy, copy);
  TYPE(u16_rnu_sat, 8x1) half = FN(mextract, u16_rnu_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_24_8 (void)
{
  TYPE(u16_rnu_sat, 1x8) m = FN(mzero_m, u16_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx8) a = FN(mcopy_m2a, u16_rnu_sat, accx8) (m);
  TYPE(u16_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x8) result = FN(mcopy_a2m, u16_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx8) ();
  TYPE(u16_rnu_sat, accx8) zero = FN(mzero_acc, u16_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_24_16 (void)
{
  TYPE(u16_rnu_sat, 1x16) m = FN(mzero_m, u16_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u16_rnu_sat, accx16) a = FN(mcopy_m2a, u16_rnu_sat, accx16) (m);
  TYPE(u16_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u16_rnu_sat, 1x16) result = FN(mcopy_a2m, u16_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, u16_rnu_sat, accx16) ();
  TYPE(u16_rnu_sat, accx16) zero = FN(mzero_acc, u16_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_25_0 (void)
{
  TYPE(i16_rod, 1x8) s = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u16_rne_sat, 1x8) d = FN(mconv_ew, u16_rne_sat, 1x8) (s);
  d = FN(mabs_ew, u16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rne_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x8) back = FN(mconv_ew, i16_rod, 1x8) (d);
  TYPE(u16_rne_sat, 1x8) copy = FN(mcopy_m2m, u16_rne_sat, 1x8) (d);
  d = FN(mclear_m, u16_rne_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rne_sat, 1x16) group = FN(mconcat_m, u16_rne_sat, 1x16) (copy, copy);
  TYPE(u16_rne_sat, 1x8) half = FN(mextract, u16_rne_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_25_1 (void)
{
  TYPE(i16_rod, 8x1) s = FN(mzero_m, i16_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u16_rne_sat, 8x1) d = FN(mconv_ew, u16_rne_sat, 8x1) (s);
  d = FN(mabs_ew, u16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rne_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 8x1) back = FN(mconv_ew, i16_rod, 8x1) (d);
  TYPE(u16_rne_sat, 8x1) copy = FN(mcopy_m2m, u16_rne_sat, 8x1) (d);
  d = FN(mclear_m, u16_rne_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rne_sat, 16x1) group = FN(mconcat_m, u16_rne_sat, 16x1) (copy, copy);
  TYPE(u16_rne_sat, 8x1) half = FN(mextract, u16_rne_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_25_8 (void)
{
  TYPE(u16_rne_sat, 1x8) m = FN(mzero_m, u16_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx8) a = FN(mcopy_m2a, u16_rne_sat, accx8) (m);
  TYPE(u16_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x8) result = FN(mcopy_a2m, u16_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx8) ();
  TYPE(u16_rne_sat, accx8) zero = FN(mzero_acc, u16_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_25_16 (void)
{
  TYPE(u16_rne_sat, 1x16) m = FN(mzero_m, u16_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u16_rne_sat, accx16) a = FN(mcopy_m2a, u16_rne_sat, accx16) (m);
  TYPE(u16_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u16_rne_sat, 1x16) result = FN(mcopy_a2m, u16_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, u16_rne_sat, accx16) ();
  TYPE(u16_rne_sat, accx16) zero = FN(mzero_acc, u16_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_26_0 (void)
{
  TYPE(i16_rod, 1x8) s = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u16_rdn_sat, 1x8) d = FN(mconv_ew, u16_rdn_sat, 1x8) (s);
  d = FN(mabs_ew, u16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rdn_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x8) back = FN(mconv_ew, i16_rod, 1x8) (d);
  TYPE(u16_rdn_sat, 1x8) copy = FN(mcopy_m2m, u16_rdn_sat, 1x8) (d);
  d = FN(mclear_m, u16_rdn_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rdn_sat, 1x16) group = FN(mconcat_m, u16_rdn_sat, 1x16) (copy, copy);
  TYPE(u16_rdn_sat, 1x8) half = FN(mextract, u16_rdn_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_26_1 (void)
{
  TYPE(i16_rod, 8x1) s = FN(mzero_m, i16_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u16_rdn_sat, 8x1) d = FN(mconv_ew, u16_rdn_sat, 8x1) (s);
  d = FN(mabs_ew, u16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rdn_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 8x1) back = FN(mconv_ew, i16_rod, 8x1) (d);
  TYPE(u16_rdn_sat, 8x1) copy = FN(mcopy_m2m, u16_rdn_sat, 8x1) (d);
  d = FN(mclear_m, u16_rdn_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rdn_sat, 16x1) group = FN(mconcat_m, u16_rdn_sat, 16x1) (copy, copy);
  TYPE(u16_rdn_sat, 8x1) half = FN(mextract, u16_rdn_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_26_8 (void)
{
  TYPE(u16_rdn_sat, 1x8) m = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx8) a = FN(mcopy_m2a, u16_rdn_sat, accx8) (m);
  TYPE(u16_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x8) result = FN(mcopy_a2m, u16_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx8) ();
  TYPE(u16_rdn_sat, accx8) zero = FN(mzero_acc, u16_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_26_16 (void)
{
  TYPE(u16_rdn_sat, 1x16) m = FN(mzero_m, u16_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u16_rdn_sat, accx16) a = FN(mcopy_m2a, u16_rdn_sat, accx16) (m);
  TYPE(u16_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u16_rdn_sat, 1x16) result = FN(mcopy_a2m, u16_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, u16_rdn_sat, accx16) ();
  TYPE(u16_rdn_sat, accx16) zero = FN(mzero_acc, u16_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_27_0 (void)
{
  TYPE(i16_rod, 1x8) s = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(u16_rod_sat, 1x8) d = FN(mconv_ew, u16_rod_sat, 1x8) (s);
  d = FN(mabs_ew, u16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rod_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(i16_rod, 1x8) back = FN(mconv_ew, i16_rod, 1x8) (d);
  TYPE(u16_rod_sat, 1x8) copy = FN(mcopy_m2m, u16_rod_sat, 1x8) (d);
  d = FN(mclear_m, u16_rod_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rod_sat, 1x16) group = FN(mconcat_m, u16_rod_sat, 1x16) (copy, copy);
  TYPE(u16_rod_sat, 1x8) half = FN(mextract, u16_rod_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_27_1 (void)
{
  TYPE(i16_rod, 8x1) s = FN(mzero_m, i16_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(u16_rod_sat, 8x1) d = FN(mconv_ew, u16_rod_sat, 8x1) (s);
  d = FN(mabs_ew, u16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u16_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u16_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u16_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u16_rod_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(i16_rod, 8x1) back = FN(mconv_ew, i16_rod, 8x1) (d);
  TYPE(u16_rod_sat, 8x1) copy = FN(mcopy_m2m, u16_rod_sat, 8x1) (d);
  d = FN(mclear_m, u16_rod_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u16_rod_sat, 16x1) group = FN(mconcat_m, u16_rod_sat, 16x1) (copy, copy);
  TYPE(u16_rod_sat, 8x1) half = FN(mextract, u16_rod_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_27_8 (void)
{
  TYPE(u16_rod_sat, 1x8) m = FN(mzero_m, u16_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx8) a = FN(mcopy_m2a, u16_rod_sat, accx8) (m);
  TYPE(u16_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x8) result = FN(mcopy_a2m, u16_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx8) ();
  TYPE(u16_rod_sat, accx8) zero = FN(mzero_acc, u16_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_27_16 (void)
{
  TYPE(u16_rod_sat, 1x16) m = FN(mzero_m, u16_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u16_rod_sat, accx16) a = FN(mcopy_m2a, u16_rod_sat, accx16) (m);
  TYPE(u16_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u16_rod_sat, 1x16) result = FN(mcopy_a2m, u16_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, u16_rod_sat, accx16) ();
  TYPE(u16_rod_sat, accx16) zero = FN(mzero_acc, u16_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_28_0 (void)
{
  TYPE(u16_rod, 1x8) s = FN(mzero_m, u16_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i16_rnu_sat, 1x8) d = FN(mconv_ew, i16_rnu_sat, 1x8) (s);
  d = FN(mabs_ew, i16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rnu_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rnu_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rnu_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x8) back = FN(mconv_ew, u16_rod, 1x8) (d);
  TYPE(i16_rnu_sat, 1x8) copy = FN(mcopy_m2m, i16_rnu_sat, 1x8) (d);
  d = FN(mclear_m, i16_rnu_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rnu_sat, 1x16) group = FN(mconcat_m, i16_rnu_sat, 1x16) (copy, copy);
  TYPE(i16_rnu_sat, 1x8) half = FN(mextract, i16_rnu_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_28_1 (void)
{
  TYPE(u16_rod, 8x1) s = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i16_rnu_sat, 8x1) d = FN(mconv_ew, i16_rnu_sat, 8x1) (s);
  d = FN(mabs_ew, i16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rnu_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rnu_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rnu_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 8x1) back = FN(mconv_ew, u16_rod, 8x1) (d);
  TYPE(i16_rnu_sat, 8x1) copy = FN(mcopy_m2m, i16_rnu_sat, 8x1) (d);
  d = FN(mclear_m, i16_rnu_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rnu_sat, 16x1) group = FN(mconcat_m, i16_rnu_sat, 16x1) (copy, copy);
  TYPE(i16_rnu_sat, 8x1) half = FN(mextract, i16_rnu_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_28_8 (void)
{
  TYPE(i16_rnu_sat, 1x8) m = FN(mzero_m, i16_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx8) a = FN(mcopy_m2a, i16_rnu_sat, accx8) (m);
  TYPE(i16_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x8) result = FN(mcopy_a2m, i16_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx8) ();
  TYPE(i16_rnu_sat, accx8) zero = FN(mzero_acc, i16_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_28_16 (void)
{
  TYPE(i16_rnu_sat, 1x16) m = FN(mzero_m, i16_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i16_rnu_sat, accx16) a = FN(mcopy_m2a, i16_rnu_sat, accx16) (m);
  TYPE(i16_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i16_rnu_sat, 1x16) result = FN(mcopy_a2m, i16_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, i16_rnu_sat, accx16) ();
  TYPE(i16_rnu_sat, accx16) zero = FN(mzero_acc, i16_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_29_0 (void)
{
  TYPE(u16_rod, 1x8) s = FN(mzero_m, u16_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i16_rne_sat, 1x8) d = FN(mconv_ew, i16_rne_sat, 1x8) (s);
  d = FN(mabs_ew, i16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rne_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rne_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rne_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x8) back = FN(mconv_ew, u16_rod, 1x8) (d);
  TYPE(i16_rne_sat, 1x8) copy = FN(mcopy_m2m, i16_rne_sat, 1x8) (d);
  d = FN(mclear_m, i16_rne_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rne_sat, 1x16) group = FN(mconcat_m, i16_rne_sat, 1x16) (copy, copy);
  TYPE(i16_rne_sat, 1x8) half = FN(mextract, i16_rne_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_29_1 (void)
{
  TYPE(u16_rod, 8x1) s = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i16_rne_sat, 8x1) d = FN(mconv_ew, i16_rne_sat, 8x1) (s);
  d = FN(mabs_ew, i16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rne_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rne_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rne_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 8x1) back = FN(mconv_ew, u16_rod, 8x1) (d);
  TYPE(i16_rne_sat, 8x1) copy = FN(mcopy_m2m, i16_rne_sat, 8x1) (d);
  d = FN(mclear_m, i16_rne_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rne_sat, 16x1) group = FN(mconcat_m, i16_rne_sat, 16x1) (copy, copy);
  TYPE(i16_rne_sat, 8x1) half = FN(mextract, i16_rne_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_29_8 (void)
{
  TYPE(i16_rne_sat, 1x8) m = FN(mzero_m, i16_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx8) a = FN(mcopy_m2a, i16_rne_sat, accx8) (m);
  TYPE(i16_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x8) result = FN(mcopy_a2m, i16_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx8) ();
  TYPE(i16_rne_sat, accx8) zero = FN(mzero_acc, i16_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_29_16 (void)
{
  TYPE(i16_rne_sat, 1x16) m = FN(mzero_m, i16_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i16_rne_sat, accx16) a = FN(mcopy_m2a, i16_rne_sat, accx16) (m);
  TYPE(i16_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i16_rne_sat, 1x16) result = FN(mcopy_a2m, i16_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, i16_rne_sat, accx16) ();
  TYPE(i16_rne_sat, accx16) zero = FN(mzero_acc, i16_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_30_0 (void)
{
  TYPE(u16_rod, 1x8) s = FN(mzero_m, u16_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i16_rdn_sat, 1x8) d = FN(mconv_ew, i16_rdn_sat, 1x8) (s);
  d = FN(mabs_ew, i16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rdn_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rdn_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rdn_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x8) back = FN(mconv_ew, u16_rod, 1x8) (d);
  TYPE(i16_rdn_sat, 1x8) copy = FN(mcopy_m2m, i16_rdn_sat, 1x8) (d);
  d = FN(mclear_m, i16_rdn_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rdn_sat, 1x16) group = FN(mconcat_m, i16_rdn_sat, 1x16) (copy, copy);
  TYPE(i16_rdn_sat, 1x8) half = FN(mextract, i16_rdn_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_30_1 (void)
{
  TYPE(u16_rod, 8x1) s = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i16_rdn_sat, 8x1) d = FN(mconv_ew, i16_rdn_sat, 8x1) (s);
  d = FN(mabs_ew, i16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rdn_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rdn_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rdn_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 8x1) back = FN(mconv_ew, u16_rod, 8x1) (d);
  TYPE(i16_rdn_sat, 8x1) copy = FN(mcopy_m2m, i16_rdn_sat, 8x1) (d);
  d = FN(mclear_m, i16_rdn_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rdn_sat, 16x1) group = FN(mconcat_m, i16_rdn_sat, 16x1) (copy, copy);
  TYPE(i16_rdn_sat, 8x1) half = FN(mextract, i16_rdn_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_30_8 (void)
{
  TYPE(i16_rdn_sat, 1x8) m = FN(mzero_m, i16_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx8) a = FN(mcopy_m2a, i16_rdn_sat, accx8) (m);
  TYPE(i16_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x8) result = FN(mcopy_a2m, i16_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx8) ();
  TYPE(i16_rdn_sat, accx8) zero = FN(mzero_acc, i16_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_30_16 (void)
{
  TYPE(i16_rdn_sat, 1x16) m = FN(mzero_m, i16_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i16_rdn_sat, accx16) a = FN(mcopy_m2a, i16_rdn_sat, accx16) (m);
  TYPE(i16_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i16_rdn_sat, 1x16) result = FN(mcopy_a2m, i16_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, i16_rdn_sat, accx16) ();
  TYPE(i16_rdn_sat, accx16) zero = FN(mzero_acc, i16_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_31_0 (void)
{
  TYPE(u16_rod, 1x8) s = FN(mzero_m, u16_rod, 1x8) ();
  CHANGE_M(s);
  TYPE(i16_rod_sat, 1x8) d = FN(mconv_ew, i16_rod_sat, 1x8) (s);
  d = FN(mabs_ew, i16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rod_sat, 1x8) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rod_sat, 1x8) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rod_sat, 1x8) (s);
  KEEP_M(d);
  TYPE(u16_rod, 1x8) back = FN(mconv_ew, u16_rod, 1x8) (d);
  TYPE(i16_rod_sat, 1x8) copy = FN(mcopy_m2m, i16_rod_sat, 1x8) (d);
  d = FN(mclear_m, i16_rod_sat, 1x8) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rod_sat, 1x16) group = FN(mconcat_m, i16_rod_sat, 1x16) (copy, copy);
  TYPE(i16_rod_sat, 1x8) half = FN(mextract, i16_rod_sat, 1x8) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_31_1 (void)
{
  TYPE(u16_rod, 8x1) s = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE_M(s);
  TYPE(i16_rod_sat, 8x1) d = FN(mconv_ew, i16_rod_sat, 8x1) (s);
  d = FN(mabs_ew, i16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i16_rod_sat, 8x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i16_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i16_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i16_rod_sat, 8x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i16_rod_sat, 8x1) (s);
  KEEP_M(d);
  TYPE(u16_rod, 8x1) back = FN(mconv_ew, u16_rod, 8x1) (d);
  TYPE(i16_rod_sat, 8x1) copy = FN(mcopy_m2m, i16_rod_sat, 8x1) (d);
  d = FN(mclear_m, i16_rod_sat, 8x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i16_rod_sat, 16x1) group = FN(mconcat_m, i16_rod_sat, 16x1) (copy, copy);
  TYPE(i16_rod_sat, 8x1) half = FN(mextract, i16_rod_sat, 8x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_31_8 (void)
{
  TYPE(i16_rod_sat, 1x8) m = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx8) a = FN(mcopy_m2a, i16_rod_sat, accx8) (m);
  TYPE(i16_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x8) result = FN(mcopy_a2m, i16_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx8) ();
  TYPE(i16_rod_sat, accx8) zero = FN(mzero_acc, i16_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_31_16 (void)
{
  TYPE(i16_rod_sat, 1x16) m = FN(mzero_m, i16_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i16_rod_sat, accx16) a = FN(mcopy_m2a, i16_rod_sat, accx16) (m);
  TYPE(i16_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i16_rod_sat, 1x16) result = FN(mcopy_a2m, i16_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, i16_rod_sat, accx16) ();
  TYPE(i16_rod_sat, accx16) zero = FN(mzero_acc, i16_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_32_0 (void)
{
  TYPE(i32_rod, 1x4) s = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u32_rnu_sat, 1x4) d = FN(mconv_ew, u32_rnu_sat, 1x4) (s);
  d = FN(mabs_ew, u32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rnu_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x4) back = FN(mconv_ew, i32_rod, 1x4) (d);
  TYPE(u32_rnu_sat, 1x4) copy = FN(mcopy_m2m, u32_rnu_sat, 1x4) (d);
  d = FN(mclear_m, u32_rnu_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rnu_sat, 1x8) group = FN(mconcat_m, u32_rnu_sat, 1x8) (copy, copy);
  TYPE(u32_rnu_sat, 1x4) half = FN(mextract, u32_rnu_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_32_1 (void)
{
  TYPE(i32_rod, 4x1) s = FN(mzero_m, i32_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u32_rnu_sat, 4x1) d = FN(mconv_ew, u32_rnu_sat, 4x1) (s);
  d = FN(mabs_ew, u32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rnu_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 4x1) back = FN(mconv_ew, i32_rod, 4x1) (d);
  TYPE(u32_rnu_sat, 4x1) copy = FN(mcopy_m2m, u32_rnu_sat, 4x1) (d);
  d = FN(mclear_m, u32_rnu_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rnu_sat, 8x1) group = FN(mconcat_m, u32_rnu_sat, 8x1) (copy, copy);
  TYPE(u32_rnu_sat, 4x1) half = FN(mextract, u32_rnu_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_32_4 (void)
{
  TYPE(u32_rnu_sat, 1x4) m = FN(mzero_m, u32_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx4) a = FN(mcopy_m2a, u32_rnu_sat, accx4) (m);
  TYPE(u32_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x4) result = FN(mcopy_a2m, u32_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx4) ();
  TYPE(u32_rnu_sat, accx4) zero = FN(mzero_acc, u32_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_32_8 (void)
{
  TYPE(u32_rnu_sat, 1x8) m = FN(mzero_m, u32_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx8) a = FN(mcopy_m2a, u32_rnu_sat, accx8) (m);
  TYPE(u32_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x8) result = FN(mcopy_a2m, u32_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx8) ();
  TYPE(u32_rnu_sat, accx8) zero = FN(mzero_acc, u32_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_32_16 (void)
{
  TYPE(u32_rnu_sat, 1x16) m = FN(mzero_m, u32_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u32_rnu_sat, accx16) a = FN(mcopy_m2a, u32_rnu_sat, accx16) (m);
  TYPE(u32_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u32_rnu_sat, 1x16) result = FN(mcopy_a2m, u32_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, u32_rnu_sat, accx16) ();
  TYPE(u32_rnu_sat, accx16) zero = FN(mzero_acc, u32_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_33_0 (void)
{
  TYPE(i32_rod, 1x4) s = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u32_rne_sat, 1x4) d = FN(mconv_ew, u32_rne_sat, 1x4) (s);
  d = FN(mabs_ew, u32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rne_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x4) back = FN(mconv_ew, i32_rod, 1x4) (d);
  TYPE(u32_rne_sat, 1x4) copy = FN(mcopy_m2m, u32_rne_sat, 1x4) (d);
  d = FN(mclear_m, u32_rne_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rne_sat, 1x8) group = FN(mconcat_m, u32_rne_sat, 1x8) (copy, copy);
  TYPE(u32_rne_sat, 1x4) half = FN(mextract, u32_rne_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_33_1 (void)
{
  TYPE(i32_rod, 4x1) s = FN(mzero_m, i32_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u32_rne_sat, 4x1) d = FN(mconv_ew, u32_rne_sat, 4x1) (s);
  d = FN(mabs_ew, u32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rne_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 4x1) back = FN(mconv_ew, i32_rod, 4x1) (d);
  TYPE(u32_rne_sat, 4x1) copy = FN(mcopy_m2m, u32_rne_sat, 4x1) (d);
  d = FN(mclear_m, u32_rne_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rne_sat, 8x1) group = FN(mconcat_m, u32_rne_sat, 8x1) (copy, copy);
  TYPE(u32_rne_sat, 4x1) half = FN(mextract, u32_rne_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_33_4 (void)
{
  TYPE(u32_rne_sat, 1x4) m = FN(mzero_m, u32_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx4) a = FN(mcopy_m2a, u32_rne_sat, accx4) (m);
  TYPE(u32_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x4) result = FN(mcopy_a2m, u32_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx4) ();
  TYPE(u32_rne_sat, accx4) zero = FN(mzero_acc, u32_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_33_8 (void)
{
  TYPE(u32_rne_sat, 1x8) m = FN(mzero_m, u32_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx8) a = FN(mcopy_m2a, u32_rne_sat, accx8) (m);
  TYPE(u32_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x8) result = FN(mcopy_a2m, u32_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx8) ();
  TYPE(u32_rne_sat, accx8) zero = FN(mzero_acc, u32_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_33_16 (void)
{
  TYPE(u32_rne_sat, 1x16) m = FN(mzero_m, u32_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u32_rne_sat, accx16) a = FN(mcopy_m2a, u32_rne_sat, accx16) (m);
  TYPE(u32_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u32_rne_sat, 1x16) result = FN(mcopy_a2m, u32_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, u32_rne_sat, accx16) ();
  TYPE(u32_rne_sat, accx16) zero = FN(mzero_acc, u32_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_34_0 (void)
{
  TYPE(i32_rod, 1x4) s = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u32_rdn_sat, 1x4) d = FN(mconv_ew, u32_rdn_sat, 1x4) (s);
  d = FN(mabs_ew, u32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rdn_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x4) back = FN(mconv_ew, i32_rod, 1x4) (d);
  TYPE(u32_rdn_sat, 1x4) copy = FN(mcopy_m2m, u32_rdn_sat, 1x4) (d);
  d = FN(mclear_m, u32_rdn_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rdn_sat, 1x8) group = FN(mconcat_m, u32_rdn_sat, 1x8) (copy, copy);
  TYPE(u32_rdn_sat, 1x4) half = FN(mextract, u32_rdn_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_34_1 (void)
{
  TYPE(i32_rod, 4x1) s = FN(mzero_m, i32_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u32_rdn_sat, 4x1) d = FN(mconv_ew, u32_rdn_sat, 4x1) (s);
  d = FN(mabs_ew, u32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rdn_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 4x1) back = FN(mconv_ew, i32_rod, 4x1) (d);
  TYPE(u32_rdn_sat, 4x1) copy = FN(mcopy_m2m, u32_rdn_sat, 4x1) (d);
  d = FN(mclear_m, u32_rdn_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rdn_sat, 8x1) group = FN(mconcat_m, u32_rdn_sat, 8x1) (copy, copy);
  TYPE(u32_rdn_sat, 4x1) half = FN(mextract, u32_rdn_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_34_4 (void)
{
  TYPE(u32_rdn_sat, 1x4) m = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx4) a = FN(mcopy_m2a, u32_rdn_sat, accx4) (m);
  TYPE(u32_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x4) result = FN(mcopy_a2m, u32_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx4) ();
  TYPE(u32_rdn_sat, accx4) zero = FN(mzero_acc, u32_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_34_8 (void)
{
  TYPE(u32_rdn_sat, 1x8) m = FN(mzero_m, u32_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx8) a = FN(mcopy_m2a, u32_rdn_sat, accx8) (m);
  TYPE(u32_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x8) result = FN(mcopy_a2m, u32_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx8) ();
  TYPE(u32_rdn_sat, accx8) zero = FN(mzero_acc, u32_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_34_16 (void)
{
  TYPE(u32_rdn_sat, 1x16) m = FN(mzero_m, u32_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u32_rdn_sat, accx16) a = FN(mcopy_m2a, u32_rdn_sat, accx16) (m);
  TYPE(u32_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u32_rdn_sat, 1x16) result = FN(mcopy_a2m, u32_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, u32_rdn_sat, accx16) ();
  TYPE(u32_rdn_sat, accx16) zero = FN(mzero_acc, u32_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_35_0 (void)
{
  TYPE(i32_rod, 1x4) s = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(u32_rod_sat, 1x4) d = FN(mconv_ew, u32_rod_sat, 1x4) (s);
  d = FN(mabs_ew, u32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rod_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(i32_rod, 1x4) back = FN(mconv_ew, i32_rod, 1x4) (d);
  TYPE(u32_rod_sat, 1x4) copy = FN(mcopy_m2m, u32_rod_sat, 1x4) (d);
  d = FN(mclear_m, u32_rod_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rod_sat, 1x8) group = FN(mconcat_m, u32_rod_sat, 1x8) (copy, copy);
  TYPE(u32_rod_sat, 1x4) half = FN(mextract, u32_rod_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_35_1 (void)
{
  TYPE(i32_rod, 4x1) s = FN(mzero_m, i32_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(u32_rod_sat, 4x1) d = FN(mconv_ew, u32_rod_sat, 4x1) (s);
  d = FN(mabs_ew, u32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u32_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u32_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u32_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u32_rod_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(i32_rod, 4x1) back = FN(mconv_ew, i32_rod, 4x1) (d);
  TYPE(u32_rod_sat, 4x1) copy = FN(mcopy_m2m, u32_rod_sat, 4x1) (d);
  d = FN(mclear_m, u32_rod_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u32_rod_sat, 8x1) group = FN(mconcat_m, u32_rod_sat, 8x1) (copy, copy);
  TYPE(u32_rod_sat, 4x1) half = FN(mextract, u32_rod_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_35_4 (void)
{
  TYPE(u32_rod_sat, 1x4) m = FN(mzero_m, u32_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx4) a = FN(mcopy_m2a, u32_rod_sat, accx4) (m);
  TYPE(u32_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x4) result = FN(mcopy_a2m, u32_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx4) ();
  TYPE(u32_rod_sat, accx4) zero = FN(mzero_acc, u32_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_35_8 (void)
{
  TYPE(u32_rod_sat, 1x8) m = FN(mzero_m, u32_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx8) a = FN(mcopy_m2a, u32_rod_sat, accx8) (m);
  TYPE(u32_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x8) result = FN(mcopy_a2m, u32_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx8) ();
  TYPE(u32_rod_sat, accx8) zero = FN(mzero_acc, u32_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_35_16 (void)
{
  TYPE(u32_rod_sat, 1x16) m = FN(mzero_m, u32_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(u32_rod_sat, accx16) a = FN(mcopy_m2a, u32_rod_sat, accx16) (m);
  TYPE(u32_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(u32_rod_sat, 1x16) result = FN(mcopy_a2m, u32_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, u32_rod_sat, accx16) ();
  TYPE(u32_rod_sat, accx16) zero = FN(mzero_acc, u32_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_36_0 (void)
{
  TYPE(u32_rod, 1x4) s = FN(mzero_m, u32_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i32_rnu_sat, 1x4) d = FN(mconv_ew, i32_rnu_sat, 1x4) (s);
  d = FN(mabs_ew, i32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rnu_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rnu_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rnu_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x4) back = FN(mconv_ew, u32_rod, 1x4) (d);
  TYPE(i32_rnu_sat, 1x4) copy = FN(mcopy_m2m, i32_rnu_sat, 1x4) (d);
  d = FN(mclear_m, i32_rnu_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rnu_sat, 1x8) group = FN(mconcat_m, i32_rnu_sat, 1x8) (copy, copy);
  TYPE(i32_rnu_sat, 1x4) half = FN(mextract, i32_rnu_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_36_1 (void)
{
  TYPE(u32_rod, 4x1) s = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i32_rnu_sat, 4x1) d = FN(mconv_ew, i32_rnu_sat, 4x1) (s);
  d = FN(mabs_ew, i32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rnu_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rnu_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rnu_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 4x1) back = FN(mconv_ew, u32_rod, 4x1) (d);
  TYPE(i32_rnu_sat, 4x1) copy = FN(mcopy_m2m, i32_rnu_sat, 4x1) (d);
  d = FN(mclear_m, i32_rnu_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rnu_sat, 8x1) group = FN(mconcat_m, i32_rnu_sat, 8x1) (copy, copy);
  TYPE(i32_rnu_sat, 4x1) half = FN(mextract, i32_rnu_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_36_4 (void)
{
  TYPE(i32_rnu_sat, 1x4) m = FN(mzero_m, i32_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx4) a = FN(mcopy_m2a, i32_rnu_sat, accx4) (m);
  TYPE(i32_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x4) result = FN(mcopy_a2m, i32_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx4) ();
  TYPE(i32_rnu_sat, accx4) zero = FN(mzero_acc, i32_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_36_8 (void)
{
  TYPE(i32_rnu_sat, 1x8) m = FN(mzero_m, i32_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx8) a = FN(mcopy_m2a, i32_rnu_sat, accx8) (m);
  TYPE(i32_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x8) result = FN(mcopy_a2m, i32_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx8) ();
  TYPE(i32_rnu_sat, accx8) zero = FN(mzero_acc, i32_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_36_16 (void)
{
  TYPE(i32_rnu_sat, 1x16) m = FN(mzero_m, i32_rnu_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i32_rnu_sat, accx16) a = FN(mcopy_m2a, i32_rnu_sat, accx16) (m);
  TYPE(i32_rnu_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i32_rnu_sat, 1x16) result = FN(mcopy_a2m, i32_rnu_sat, 1x16) (copy);
  a = FN(mclear_acc, i32_rnu_sat, accx16) ();
  TYPE(i32_rnu_sat, accx16) zero = FN(mzero_acc, i32_rnu_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_37_0 (void)
{
  TYPE(u32_rod, 1x4) s = FN(mzero_m, u32_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i32_rne_sat, 1x4) d = FN(mconv_ew, i32_rne_sat, 1x4) (s);
  d = FN(mabs_ew, i32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rne_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rne_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rne_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x4) back = FN(mconv_ew, u32_rod, 1x4) (d);
  TYPE(i32_rne_sat, 1x4) copy = FN(mcopy_m2m, i32_rne_sat, 1x4) (d);
  d = FN(mclear_m, i32_rne_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rne_sat, 1x8) group = FN(mconcat_m, i32_rne_sat, 1x8) (copy, copy);
  TYPE(i32_rne_sat, 1x4) half = FN(mextract, i32_rne_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_37_1 (void)
{
  TYPE(u32_rod, 4x1) s = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i32_rne_sat, 4x1) d = FN(mconv_ew, i32_rne_sat, 4x1) (s);
  d = FN(mabs_ew, i32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rne_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rne_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rne_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 4x1) back = FN(mconv_ew, u32_rod, 4x1) (d);
  TYPE(i32_rne_sat, 4x1) copy = FN(mcopy_m2m, i32_rne_sat, 4x1) (d);
  d = FN(mclear_m, i32_rne_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rne_sat, 8x1) group = FN(mconcat_m, i32_rne_sat, 8x1) (copy, copy);
  TYPE(i32_rne_sat, 4x1) half = FN(mextract, i32_rne_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_37_4 (void)
{
  TYPE(i32_rne_sat, 1x4) m = FN(mzero_m, i32_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx4) a = FN(mcopy_m2a, i32_rne_sat, accx4) (m);
  TYPE(i32_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x4) result = FN(mcopy_a2m, i32_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx4) ();
  TYPE(i32_rne_sat, accx4) zero = FN(mzero_acc, i32_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_37_8 (void)
{
  TYPE(i32_rne_sat, 1x8) m = FN(mzero_m, i32_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx8) a = FN(mcopy_m2a, i32_rne_sat, accx8) (m);
  TYPE(i32_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x8) result = FN(mcopy_a2m, i32_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx8) ();
  TYPE(i32_rne_sat, accx8) zero = FN(mzero_acc, i32_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_37_16 (void)
{
  TYPE(i32_rne_sat, 1x16) m = FN(mzero_m, i32_rne_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i32_rne_sat, accx16) a = FN(mcopy_m2a, i32_rne_sat, accx16) (m);
  TYPE(i32_rne_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i32_rne_sat, 1x16) result = FN(mcopy_a2m, i32_rne_sat, 1x16) (copy);
  a = FN(mclear_acc, i32_rne_sat, accx16) ();
  TYPE(i32_rne_sat, accx16) zero = FN(mzero_acc, i32_rne_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_38_0 (void)
{
  TYPE(u32_rod, 1x4) s = FN(mzero_m, u32_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i32_rdn_sat, 1x4) d = FN(mconv_ew, i32_rdn_sat, 1x4) (s);
  d = FN(mabs_ew, i32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rdn_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rdn_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rdn_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x4) back = FN(mconv_ew, u32_rod, 1x4) (d);
  TYPE(i32_rdn_sat, 1x4) copy = FN(mcopy_m2m, i32_rdn_sat, 1x4) (d);
  d = FN(mclear_m, i32_rdn_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rdn_sat, 1x8) group = FN(mconcat_m, i32_rdn_sat, 1x8) (copy, copy);
  TYPE(i32_rdn_sat, 1x4) half = FN(mextract, i32_rdn_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_38_1 (void)
{
  TYPE(u32_rod, 4x1) s = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i32_rdn_sat, 4x1) d = FN(mconv_ew, i32_rdn_sat, 4x1) (s);
  d = FN(mabs_ew, i32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rdn_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rdn_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rdn_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 4x1) back = FN(mconv_ew, u32_rod, 4x1) (d);
  TYPE(i32_rdn_sat, 4x1) copy = FN(mcopy_m2m, i32_rdn_sat, 4x1) (d);
  d = FN(mclear_m, i32_rdn_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rdn_sat, 8x1) group = FN(mconcat_m, i32_rdn_sat, 8x1) (copy, copy);
  TYPE(i32_rdn_sat, 4x1) half = FN(mextract, i32_rdn_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_38_4 (void)
{
  TYPE(i32_rdn_sat, 1x4) m = FN(mzero_m, i32_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx4) a = FN(mcopy_m2a, i32_rdn_sat, accx4) (m);
  TYPE(i32_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x4) result = FN(mcopy_a2m, i32_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx4) ();
  TYPE(i32_rdn_sat, accx4) zero = FN(mzero_acc, i32_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_38_8 (void)
{
  TYPE(i32_rdn_sat, 1x8) m = FN(mzero_m, i32_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx8) a = FN(mcopy_m2a, i32_rdn_sat, accx8) (m);
  TYPE(i32_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x8) result = FN(mcopy_a2m, i32_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx8) ();
  TYPE(i32_rdn_sat, accx8) zero = FN(mzero_acc, i32_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_38_16 (void)
{
  TYPE(i32_rdn_sat, 1x16) m = FN(mzero_m, i32_rdn_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i32_rdn_sat, accx16) a = FN(mcopy_m2a, i32_rdn_sat, accx16) (m);
  TYPE(i32_rdn_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i32_rdn_sat, 1x16) result = FN(mcopy_a2m, i32_rdn_sat, 1x16) (copy);
  a = FN(mclear_acc, i32_rdn_sat, accx16) ();
  TYPE(i32_rdn_sat, accx16) zero = FN(mzero_acc, i32_rdn_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_39_0 (void)
{
  TYPE(u32_rod, 1x4) s = FN(mzero_m, u32_rod, 1x4) ();
  CHANGE_M(s);
  TYPE(i32_rod_sat, 1x4) d = FN(mconv_ew, i32_rod_sat, 1x4) (s);
  d = FN(mabs_ew, i32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rod_sat, 1x4) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rod_sat, 1x4) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rod_sat, 1x4) (s);
  KEEP_M(d);
  TYPE(u32_rod, 1x4) back = FN(mconv_ew, u32_rod, 1x4) (d);
  TYPE(i32_rod_sat, 1x4) copy = FN(mcopy_m2m, i32_rod_sat, 1x4) (d);
  d = FN(mclear_m, i32_rod_sat, 1x4) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rod_sat, 1x8) group = FN(mconcat_m, i32_rod_sat, 1x8) (copy, copy);
  TYPE(i32_rod_sat, 1x4) half = FN(mextract, i32_rod_sat, 1x4) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_39_1 (void)
{
  TYPE(u32_rod, 4x1) s = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE_M(s);
  TYPE(i32_rod_sat, 4x1) d = FN(mconv_ew, i32_rod_sat, 4x1) (s);
  d = FN(mabs_ew, i32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i32_rod_sat, 4x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i32_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i32_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i32_rod_sat, 4x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i32_rod_sat, 4x1) (s);
  KEEP_M(d);
  TYPE(u32_rod, 4x1) back = FN(mconv_ew, u32_rod, 4x1) (d);
  TYPE(i32_rod_sat, 4x1) copy = FN(mcopy_m2m, i32_rod_sat, 4x1) (d);
  d = FN(mclear_m, i32_rod_sat, 4x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i32_rod_sat, 8x1) group = FN(mconcat_m, i32_rod_sat, 8x1) (copy, copy);
  TYPE(i32_rod_sat, 4x1) half = FN(mextract, i32_rod_sat, 4x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_39_4 (void)
{
  TYPE(i32_rod_sat, 1x4) m = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx4) a = FN(mcopy_m2a, i32_rod_sat, accx4) (m);
  TYPE(i32_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x4) result = FN(mcopy_a2m, i32_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx4) ();
  TYPE(i32_rod_sat, accx4) zero = FN(mzero_acc, i32_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_39_8 (void)
{
  TYPE(i32_rod_sat, 1x8) m = FN(mzero_m, i32_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx8) a = FN(mcopy_m2a, i32_rod_sat, accx8) (m);
  TYPE(i32_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x8) result = FN(mcopy_a2m, i32_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx8) ();
  TYPE(i32_rod_sat, accx8) zero = FN(mzero_acc, i32_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_39_16 (void)
{
  TYPE(i32_rod_sat, 1x16) m = FN(mzero_m, i32_rod_sat, 1x16) ();
  CHANGE_M(m);
  TYPE(i32_rod_sat, accx16) a = FN(mcopy_m2a, i32_rod_sat, accx16) (m);
  TYPE(i32_rod_sat, accx16) copy = a;
  CHANGE_A(a);
  TYPE(i32_rod_sat, 1x16) result = FN(mcopy_a2m, i32_rod_sat, 1x16) (copy);
  a = FN(mclear_acc, i32_rod_sat, accx16) ();
  TYPE(i32_rod_sat, accx16) zero = FN(mzero_acc, i32_rod_sat, accx16) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_40_0 (void)
{
  TYPE(i64_rod, 1x2) s = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u64_rnu_sat, 1x2) d = FN(mconv_ew, u64_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, u64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x2) back = FN(mconv_ew, i64_rod, 1x2) (d);
  TYPE(u64_rnu_sat, 1x2) copy = FN(mcopy_m2m, u64_rnu_sat, 1x2) (d);
  d = FN(mclear_m, u64_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rnu_sat, 1x4) group = FN(mconcat_m, u64_rnu_sat, 1x4) (copy, copy);
  TYPE(u64_rnu_sat, 1x2) half = FN(mextract, u64_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_40_1 (void)
{
  TYPE(i64_rod, 2x1) s = FN(mzero_m, i64_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u64_rnu_sat, 2x1) d = FN(mconv_ew, u64_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, u64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 2x1) back = FN(mconv_ew, i64_rod, 2x1) (d);
  TYPE(u64_rnu_sat, 2x1) copy = FN(mcopy_m2m, u64_rnu_sat, 2x1) (d);
  d = FN(mclear_m, u64_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rnu_sat, 4x1) group = FN(mconcat_m, u64_rnu_sat, 4x1) (copy, copy);
  TYPE(u64_rnu_sat, 2x1) half = FN(mextract, u64_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_40_2 (void)
{
  TYPE(u64_rnu_sat, 1x2) m = FN(mzero_m, u64_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rnu_sat, accx2) a = FN(mcopy_m2a, u64_rnu_sat, accx2) (m);
  TYPE(u64_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rnu_sat, 1x2) result = FN(mcopy_a2m, u64_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rnu_sat, accx2) ();
  TYPE(u64_rnu_sat, accx2) zero = FN(mzero_acc, u64_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_40_4 (void)
{
  TYPE(u64_rnu_sat, 1x4) m = FN(mzero_m, u64_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u64_rnu_sat, accx4) a = FN(mcopy_m2a, u64_rnu_sat, accx4) (m);
  TYPE(u64_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u64_rnu_sat, 1x4) result = FN(mcopy_a2m, u64_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u64_rnu_sat, accx4) ();
  TYPE(u64_rnu_sat, accx4) zero = FN(mzero_acc, u64_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_40_8 (void)
{
  TYPE(u64_rnu_sat, 1x8) m = FN(mzero_m, u64_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u64_rnu_sat, accx8) a = FN(mcopy_m2a, u64_rnu_sat, accx8) (m);
  TYPE(u64_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u64_rnu_sat, 1x8) result = FN(mcopy_a2m, u64_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, u64_rnu_sat, accx8) ();
  TYPE(u64_rnu_sat, accx8) zero = FN(mzero_acc, u64_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_41_0 (void)
{
  TYPE(i64_rod, 1x2) s = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u64_rne_sat, 1x2) d = FN(mconv_ew, u64_rne_sat, 1x2) (s);
  d = FN(mabs_ew, u64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x2) back = FN(mconv_ew, i64_rod, 1x2) (d);
  TYPE(u64_rne_sat, 1x2) copy = FN(mcopy_m2m, u64_rne_sat, 1x2) (d);
  d = FN(mclear_m, u64_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rne_sat, 1x4) group = FN(mconcat_m, u64_rne_sat, 1x4) (copy, copy);
  TYPE(u64_rne_sat, 1x2) half = FN(mextract, u64_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_41_1 (void)
{
  TYPE(i64_rod, 2x1) s = FN(mzero_m, i64_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u64_rne_sat, 2x1) d = FN(mconv_ew, u64_rne_sat, 2x1) (s);
  d = FN(mabs_ew, u64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 2x1) back = FN(mconv_ew, i64_rod, 2x1) (d);
  TYPE(u64_rne_sat, 2x1) copy = FN(mcopy_m2m, u64_rne_sat, 2x1) (d);
  d = FN(mclear_m, u64_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rne_sat, 4x1) group = FN(mconcat_m, u64_rne_sat, 4x1) (copy, copy);
  TYPE(u64_rne_sat, 2x1) half = FN(mextract, u64_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_41_2 (void)
{
  TYPE(u64_rne_sat, 1x2) m = FN(mzero_m, u64_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rne_sat, accx2) a = FN(mcopy_m2a, u64_rne_sat, accx2) (m);
  TYPE(u64_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rne_sat, 1x2) result = FN(mcopy_a2m, u64_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rne_sat, accx2) ();
  TYPE(u64_rne_sat, accx2) zero = FN(mzero_acc, u64_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_41_4 (void)
{
  TYPE(u64_rne_sat, 1x4) m = FN(mzero_m, u64_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u64_rne_sat, accx4) a = FN(mcopy_m2a, u64_rne_sat, accx4) (m);
  TYPE(u64_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u64_rne_sat, 1x4) result = FN(mcopy_a2m, u64_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u64_rne_sat, accx4) ();
  TYPE(u64_rne_sat, accx4) zero = FN(mzero_acc, u64_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_41_8 (void)
{
  TYPE(u64_rne_sat, 1x8) m = FN(mzero_m, u64_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u64_rne_sat, accx8) a = FN(mcopy_m2a, u64_rne_sat, accx8) (m);
  TYPE(u64_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u64_rne_sat, 1x8) result = FN(mcopy_a2m, u64_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, u64_rne_sat, accx8) ();
  TYPE(u64_rne_sat, accx8) zero = FN(mzero_acc, u64_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_42_0 (void)
{
  TYPE(i64_rod, 1x2) s = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u64_rdn_sat, 1x2) d = FN(mconv_ew, u64_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, u64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x2) back = FN(mconv_ew, i64_rod, 1x2) (d);
  TYPE(u64_rdn_sat, 1x2) copy = FN(mcopy_m2m, u64_rdn_sat, 1x2) (d);
  d = FN(mclear_m, u64_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rdn_sat, 1x4) group = FN(mconcat_m, u64_rdn_sat, 1x4) (copy, copy);
  TYPE(u64_rdn_sat, 1x2) half = FN(mextract, u64_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_42_1 (void)
{
  TYPE(i64_rod, 2x1) s = FN(mzero_m, i64_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u64_rdn_sat, 2x1) d = FN(mconv_ew, u64_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, u64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 2x1) back = FN(mconv_ew, i64_rod, 2x1) (d);
  TYPE(u64_rdn_sat, 2x1) copy = FN(mcopy_m2m, u64_rdn_sat, 2x1) (d);
  d = FN(mclear_m, u64_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rdn_sat, 4x1) group = FN(mconcat_m, u64_rdn_sat, 4x1) (copy, copy);
  TYPE(u64_rdn_sat, 2x1) half = FN(mextract, u64_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_42_2 (void)
{
  TYPE(u64_rdn_sat, 1x2) m = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rdn_sat, accx2) a = FN(mcopy_m2a, u64_rdn_sat, accx2) (m);
  TYPE(u64_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rdn_sat, 1x2) result = FN(mcopy_a2m, u64_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rdn_sat, accx2) ();
  TYPE(u64_rdn_sat, accx2) zero = FN(mzero_acc, u64_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_42_4 (void)
{
  TYPE(u64_rdn_sat, 1x4) m = FN(mzero_m, u64_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u64_rdn_sat, accx4) a = FN(mcopy_m2a, u64_rdn_sat, accx4) (m);
  TYPE(u64_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u64_rdn_sat, 1x4) result = FN(mcopy_a2m, u64_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u64_rdn_sat, accx4) ();
  TYPE(u64_rdn_sat, accx4) zero = FN(mzero_acc, u64_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_42_8 (void)
{
  TYPE(u64_rdn_sat, 1x8) m = FN(mzero_m, u64_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u64_rdn_sat, accx8) a = FN(mcopy_m2a, u64_rdn_sat, accx8) (m);
  TYPE(u64_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u64_rdn_sat, 1x8) result = FN(mcopy_a2m, u64_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, u64_rdn_sat, accx8) ();
  TYPE(u64_rdn_sat, accx8) zero = FN(mzero_acc, u64_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_43_0 (void)
{
  TYPE(i64_rod, 1x2) s = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(u64_rod_sat, 1x2) d = FN(mconv_ew, u64_rod_sat, 1x2) (s);
  d = FN(mabs_ew, u64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(i64_rod, 1x2) back = FN(mconv_ew, i64_rod, 1x2) (d);
  TYPE(u64_rod_sat, 1x2) copy = FN(mcopy_m2m, u64_rod_sat, 1x2) (d);
  d = FN(mclear_m, u64_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rod_sat, 1x4) group = FN(mconcat_m, u64_rod_sat, 1x4) (copy, copy);
  TYPE(u64_rod_sat, 1x2) half = FN(mextract, u64_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_43_1 (void)
{
  TYPE(i64_rod, 2x1) s = FN(mzero_m, i64_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(u64_rod_sat, 2x1) d = FN(mconv_ew, u64_rod_sat, 2x1) (s);
  d = FN(mabs_ew, u64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u64_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u64_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u64_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u64_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(i64_rod, 2x1) back = FN(mconv_ew, i64_rod, 2x1) (d);
  TYPE(u64_rod_sat, 2x1) copy = FN(mcopy_m2m, u64_rod_sat, 2x1) (d);
  d = FN(mclear_m, u64_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u64_rod_sat, 4x1) group = FN(mconcat_m, u64_rod_sat, 4x1) (copy, copy);
  TYPE(u64_rod_sat, 2x1) half = FN(mextract, u64_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_43_2 (void)
{
  TYPE(u64_rod_sat, 1x2) m = FN(mzero_m, u64_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u64_rod_sat, accx2) a = FN(mcopy_m2a, u64_rod_sat, accx2) (m);
  TYPE(u64_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u64_rod_sat, 1x2) result = FN(mcopy_a2m, u64_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u64_rod_sat, accx2) ();
  TYPE(u64_rod_sat, accx2) zero = FN(mzero_acc, u64_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_43_4 (void)
{
  TYPE(u64_rod_sat, 1x4) m = FN(mzero_m, u64_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u64_rod_sat, accx4) a = FN(mcopy_m2a, u64_rod_sat, accx4) (m);
  TYPE(u64_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u64_rod_sat, 1x4) result = FN(mcopy_a2m, u64_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u64_rod_sat, accx4) ();
  TYPE(u64_rod_sat, accx4) zero = FN(mzero_acc, u64_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_43_8 (void)
{
  TYPE(u64_rod_sat, 1x8) m = FN(mzero_m, u64_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(u64_rod_sat, accx8) a = FN(mcopy_m2a, u64_rod_sat, accx8) (m);
  TYPE(u64_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(u64_rod_sat, 1x8) result = FN(mcopy_a2m, u64_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, u64_rod_sat, accx8) ();
  TYPE(u64_rod_sat, accx8) zero = FN(mzero_acc, u64_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_44_0 (void)
{
  TYPE(u64_rod, 1x2) s = FN(mzero_m, u64_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i64_rnu_sat, 1x2) d = FN(mconv_ew, i64_rnu_sat, 1x2) (s);
  d = FN(mabs_ew, i64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rnu_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rnu_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rnu_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x2) back = FN(mconv_ew, u64_rod, 1x2) (d);
  TYPE(i64_rnu_sat, 1x2) copy = FN(mcopy_m2m, i64_rnu_sat, 1x2) (d);
  d = FN(mclear_m, i64_rnu_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rnu_sat, 1x4) group = FN(mconcat_m, i64_rnu_sat, 1x4) (copy, copy);
  TYPE(i64_rnu_sat, 1x2) half = FN(mextract, i64_rnu_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_44_1 (void)
{
  TYPE(u64_rod, 2x1) s = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i64_rnu_sat, 2x1) d = FN(mconv_ew, i64_rnu_sat, 2x1) (s);
  d = FN(mabs_ew, i64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rnu_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rnu_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rnu_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 2x1) back = FN(mconv_ew, u64_rod, 2x1) (d);
  TYPE(i64_rnu_sat, 2x1) copy = FN(mcopy_m2m, i64_rnu_sat, 2x1) (d);
  d = FN(mclear_m, i64_rnu_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rnu_sat, 4x1) group = FN(mconcat_m, i64_rnu_sat, 4x1) (copy, copy);
  TYPE(i64_rnu_sat, 2x1) half = FN(mextract, i64_rnu_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_44_2 (void)
{
  TYPE(i64_rnu_sat, 1x2) m = FN(mzero_m, i64_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rnu_sat, accx2) a = FN(mcopy_m2a, i64_rnu_sat, accx2) (m);
  TYPE(i64_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rnu_sat, 1x2) result = FN(mcopy_a2m, i64_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rnu_sat, accx2) ();
  TYPE(i64_rnu_sat, accx2) zero = FN(mzero_acc, i64_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_44_4 (void)
{
  TYPE(i64_rnu_sat, 1x4) m = FN(mzero_m, i64_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i64_rnu_sat, accx4) a = FN(mcopy_m2a, i64_rnu_sat, accx4) (m);
  TYPE(i64_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i64_rnu_sat, 1x4) result = FN(mcopy_a2m, i64_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i64_rnu_sat, accx4) ();
  TYPE(i64_rnu_sat, accx4) zero = FN(mzero_acc, i64_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_44_8 (void)
{
  TYPE(i64_rnu_sat, 1x8) m = FN(mzero_m, i64_rnu_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i64_rnu_sat, accx8) a = FN(mcopy_m2a, i64_rnu_sat, accx8) (m);
  TYPE(i64_rnu_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i64_rnu_sat, 1x8) result = FN(mcopy_a2m, i64_rnu_sat, 1x8) (copy);
  a = FN(mclear_acc, i64_rnu_sat, accx8) ();
  TYPE(i64_rnu_sat, accx8) zero = FN(mzero_acc, i64_rnu_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_45_0 (void)
{
  TYPE(u64_rod, 1x2) s = FN(mzero_m, u64_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i64_rne_sat, 1x2) d = FN(mconv_ew, i64_rne_sat, 1x2) (s);
  d = FN(mabs_ew, i64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rne_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rne_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rne_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x2) back = FN(mconv_ew, u64_rod, 1x2) (d);
  TYPE(i64_rne_sat, 1x2) copy = FN(mcopy_m2m, i64_rne_sat, 1x2) (d);
  d = FN(mclear_m, i64_rne_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rne_sat, 1x4) group = FN(mconcat_m, i64_rne_sat, 1x4) (copy, copy);
  TYPE(i64_rne_sat, 1x2) half = FN(mextract, i64_rne_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_45_1 (void)
{
  TYPE(u64_rod, 2x1) s = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i64_rne_sat, 2x1) d = FN(mconv_ew, i64_rne_sat, 2x1) (s);
  d = FN(mabs_ew, i64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rne_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rne_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rne_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 2x1) back = FN(mconv_ew, u64_rod, 2x1) (d);
  TYPE(i64_rne_sat, 2x1) copy = FN(mcopy_m2m, i64_rne_sat, 2x1) (d);
  d = FN(mclear_m, i64_rne_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rne_sat, 4x1) group = FN(mconcat_m, i64_rne_sat, 4x1) (copy, copy);
  TYPE(i64_rne_sat, 2x1) half = FN(mextract, i64_rne_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_45_2 (void)
{
  TYPE(i64_rne_sat, 1x2) m = FN(mzero_m, i64_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rne_sat, accx2) a = FN(mcopy_m2a, i64_rne_sat, accx2) (m);
  TYPE(i64_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rne_sat, 1x2) result = FN(mcopy_a2m, i64_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rne_sat, accx2) ();
  TYPE(i64_rne_sat, accx2) zero = FN(mzero_acc, i64_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_45_4 (void)
{
  TYPE(i64_rne_sat, 1x4) m = FN(mzero_m, i64_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i64_rne_sat, accx4) a = FN(mcopy_m2a, i64_rne_sat, accx4) (m);
  TYPE(i64_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i64_rne_sat, 1x4) result = FN(mcopy_a2m, i64_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i64_rne_sat, accx4) ();
  TYPE(i64_rne_sat, accx4) zero = FN(mzero_acc, i64_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_45_8 (void)
{
  TYPE(i64_rne_sat, 1x8) m = FN(mzero_m, i64_rne_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i64_rne_sat, accx8) a = FN(mcopy_m2a, i64_rne_sat, accx8) (m);
  TYPE(i64_rne_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i64_rne_sat, 1x8) result = FN(mcopy_a2m, i64_rne_sat, 1x8) (copy);
  a = FN(mclear_acc, i64_rne_sat, accx8) ();
  TYPE(i64_rne_sat, accx8) zero = FN(mzero_acc, i64_rne_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_46_0 (void)
{
  TYPE(u64_rod, 1x2) s = FN(mzero_m, u64_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i64_rdn_sat, 1x2) d = FN(mconv_ew, i64_rdn_sat, 1x2) (s);
  d = FN(mabs_ew, i64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rdn_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rdn_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rdn_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x2) back = FN(mconv_ew, u64_rod, 1x2) (d);
  TYPE(i64_rdn_sat, 1x2) copy = FN(mcopy_m2m, i64_rdn_sat, 1x2) (d);
  d = FN(mclear_m, i64_rdn_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rdn_sat, 1x4) group = FN(mconcat_m, i64_rdn_sat, 1x4) (copy, copy);
  TYPE(i64_rdn_sat, 1x2) half = FN(mextract, i64_rdn_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_46_1 (void)
{
  TYPE(u64_rod, 2x1) s = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i64_rdn_sat, 2x1) d = FN(mconv_ew, i64_rdn_sat, 2x1) (s);
  d = FN(mabs_ew, i64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rdn_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rdn_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rdn_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 2x1) back = FN(mconv_ew, u64_rod, 2x1) (d);
  TYPE(i64_rdn_sat, 2x1) copy = FN(mcopy_m2m, i64_rdn_sat, 2x1) (d);
  d = FN(mclear_m, i64_rdn_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rdn_sat, 4x1) group = FN(mconcat_m, i64_rdn_sat, 4x1) (copy, copy);
  TYPE(i64_rdn_sat, 2x1) half = FN(mextract, i64_rdn_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_46_2 (void)
{
  TYPE(i64_rdn_sat, 1x2) m = FN(mzero_m, i64_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rdn_sat, accx2) a = FN(mcopy_m2a, i64_rdn_sat, accx2) (m);
  TYPE(i64_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rdn_sat, 1x2) result = FN(mcopy_a2m, i64_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rdn_sat, accx2) ();
  TYPE(i64_rdn_sat, accx2) zero = FN(mzero_acc, i64_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_46_4 (void)
{
  TYPE(i64_rdn_sat, 1x4) m = FN(mzero_m, i64_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i64_rdn_sat, accx4) a = FN(mcopy_m2a, i64_rdn_sat, accx4) (m);
  TYPE(i64_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i64_rdn_sat, 1x4) result = FN(mcopy_a2m, i64_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i64_rdn_sat, accx4) ();
  TYPE(i64_rdn_sat, accx4) zero = FN(mzero_acc, i64_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_46_8 (void)
{
  TYPE(i64_rdn_sat, 1x8) m = FN(mzero_m, i64_rdn_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i64_rdn_sat, accx8) a = FN(mcopy_m2a, i64_rdn_sat, accx8) (m);
  TYPE(i64_rdn_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i64_rdn_sat, 1x8) result = FN(mcopy_a2m, i64_rdn_sat, 1x8) (copy);
  a = FN(mclear_acc, i64_rdn_sat, accx8) ();
  TYPE(i64_rdn_sat, accx8) zero = FN(mzero_acc, i64_rdn_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_47_0 (void)
{
  TYPE(u64_rod, 1x2) s = FN(mzero_m, u64_rod, 1x2) ();
  CHANGE_M(s);
  TYPE(i64_rod_sat, 1x2) d = FN(mconv_ew, i64_rod_sat, 1x2) (s);
  d = FN(mabs_ew, i64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rod_sat, 1x2) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rod_sat, 1x2) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rod_sat, 1x2) (s);
  KEEP_M(d);
  TYPE(u64_rod, 1x2) back = FN(mconv_ew, u64_rod, 1x2) (d);
  TYPE(i64_rod_sat, 1x2) copy = FN(mcopy_m2m, i64_rod_sat, 1x2) (d);
  d = FN(mclear_m, i64_rod_sat, 1x2) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rod_sat, 1x4) group = FN(mconcat_m, i64_rod_sat, 1x4) (copy, copy);
  TYPE(i64_rod_sat, 1x2) half = FN(mextract, i64_rod_sat, 1x2) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void value_47_1 (void)
{
  TYPE(u64_rod, 2x1) s = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE_M(s);
  TYPE(i64_rod_sat, 2x1) d = FN(mconv_ew, i64_rod_sat, 2x1) (s);
  d = FN(mabs_ew, i64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i64_rod_sat, 2x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i64_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i64_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i64_rod_sat, 2x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i64_rod_sat, 2x1) (s);
  KEEP_M(d);
  TYPE(u64_rod, 2x1) back = FN(mconv_ew, u64_rod, 2x1) (d);
  TYPE(i64_rod_sat, 2x1) copy = FN(mcopy_m2m, i64_rod_sat, 2x1) (d);
  d = FN(mclear_m, i64_rod_sat, 2x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i64_rod_sat, 4x1) group = FN(mconcat_m, i64_rod_sat, 4x1) (copy, copy);
  TYPE(i64_rod_sat, 2x1) half = FN(mextract, i64_rod_sat, 2x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_47_2 (void)
{
  TYPE(i64_rod_sat, 1x2) m = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i64_rod_sat, accx2) a = FN(mcopy_m2a, i64_rod_sat, accx2) (m);
  TYPE(i64_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i64_rod_sat, 1x2) result = FN(mcopy_a2m, i64_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i64_rod_sat, accx2) ();
  TYPE(i64_rod_sat, accx2) zero = FN(mzero_acc, i64_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_47_4 (void)
{
  TYPE(i64_rod_sat, 1x4) m = FN(mzero_m, i64_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i64_rod_sat, accx4) a = FN(mcopy_m2a, i64_rod_sat, accx4) (m);
  TYPE(i64_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i64_rod_sat, 1x4) result = FN(mcopy_a2m, i64_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i64_rod_sat, accx4) ();
  TYPE(i64_rod_sat, accx4) zero = FN(mzero_acc, i64_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_47_8 (void)
{
  TYPE(i64_rod_sat, 1x8) m = FN(mzero_m, i64_rod_sat, 1x8) ();
  CHANGE_M(m);
  TYPE(i64_rod_sat, accx8) a = FN(mcopy_m2a, i64_rod_sat, accx8) (m);
  TYPE(i64_rod_sat, accx8) copy = a;
  CHANGE_A(a);
  TYPE(i64_rod_sat, 1x8) result = FN(mcopy_a2m, i64_rod_sat, 1x8) (copy);
  a = FN(mclear_acc, i64_rod_sat, accx8) ();
  TYPE(i64_rod_sat, accx8) zero = FN(mzero_acc, i64_rod_sat, accx8) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_48_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rnu_sat, 1x1) d = FN(mconv_ew, u128_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rnu_sat, 1x1) copy = FN(mcopy_m2m, u128_rnu_sat, 1x1) (d);
  d = FN(mclear_m, u128_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u128_rnu_sat, 1x2) group = FN(mconcat_m, u128_rnu_sat, 1x2) (copy, copy);
  TYPE(u128_rnu_sat, 1x1) half = FN(mextract, u128_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_48_1 (void)
{
  TYPE(u128_rnu_sat, 1x1) m = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rnu_sat, accx1) a = FN(mcopy_m2a, u128_rnu_sat, accx1) (m);
  TYPE(u128_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rnu_sat, 1x1) result = FN(mcopy_a2m, u128_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rnu_sat, accx1) ();
  TYPE(u128_rnu_sat, accx1) zero = FN(mzero_acc, u128_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_48_2 (void)
{
  TYPE(u128_rnu_sat, 1x2) m = FN(mzero_m, u128_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u128_rnu_sat, accx2) a = FN(mcopy_m2a, u128_rnu_sat, accx2) (m);
  TYPE(u128_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u128_rnu_sat, 1x2) result = FN(mcopy_a2m, u128_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, u128_rnu_sat, accx2) ();
  TYPE(u128_rnu_sat, accx2) zero = FN(mzero_acc, u128_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_48_4 (void)
{
  TYPE(u128_rnu_sat, 1x4) m = FN(mzero_m, u128_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u128_rnu_sat, accx4) a = FN(mcopy_m2a, u128_rnu_sat, accx4) (m);
  TYPE(u128_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u128_rnu_sat, 1x4) result = FN(mcopy_a2m, u128_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, u128_rnu_sat, accx4) ();
  TYPE(u128_rnu_sat, accx4) zero = FN(mzero_acc, u128_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_49_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rne_sat, 1x1) d = FN(mconv_ew, u128_rne_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rne_sat, 1x1) copy = FN(mcopy_m2m, u128_rne_sat, 1x1) (d);
  d = FN(mclear_m, u128_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u128_rne_sat, 1x2) group = FN(mconcat_m, u128_rne_sat, 1x2) (copy, copy);
  TYPE(u128_rne_sat, 1x1) half = FN(mextract, u128_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_49_1 (void)
{
  TYPE(u128_rne_sat, 1x1) m = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rne_sat, accx1) a = FN(mcopy_m2a, u128_rne_sat, accx1) (m);
  TYPE(u128_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rne_sat, 1x1) result = FN(mcopy_a2m, u128_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rne_sat, accx1) ();
  TYPE(u128_rne_sat, accx1) zero = FN(mzero_acc, u128_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_49_2 (void)
{
  TYPE(u128_rne_sat, 1x2) m = FN(mzero_m, u128_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u128_rne_sat, accx2) a = FN(mcopy_m2a, u128_rne_sat, accx2) (m);
  TYPE(u128_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u128_rne_sat, 1x2) result = FN(mcopy_a2m, u128_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, u128_rne_sat, accx2) ();
  TYPE(u128_rne_sat, accx2) zero = FN(mzero_acc, u128_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_49_4 (void)
{
  TYPE(u128_rne_sat, 1x4) m = FN(mzero_m, u128_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u128_rne_sat, accx4) a = FN(mcopy_m2a, u128_rne_sat, accx4) (m);
  TYPE(u128_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u128_rne_sat, 1x4) result = FN(mcopy_a2m, u128_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, u128_rne_sat, accx4) ();
  TYPE(u128_rne_sat, accx4) zero = FN(mzero_acc, u128_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_50_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rdn_sat, 1x1) d = FN(mconv_ew, u128_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rdn_sat, 1x1) copy = FN(mcopy_m2m, u128_rdn_sat, 1x1) (d);
  d = FN(mclear_m, u128_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u128_rdn_sat, 1x2) group = FN(mconcat_m, u128_rdn_sat, 1x2) (copy, copy);
  TYPE(u128_rdn_sat, 1x1) half = FN(mextract, u128_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_50_1 (void)
{
  TYPE(u128_rdn_sat, 1x1) m = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rdn_sat, accx1) a = FN(mcopy_m2a, u128_rdn_sat, accx1) (m);
  TYPE(u128_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rdn_sat, 1x1) result = FN(mcopy_a2m, u128_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rdn_sat, accx1) ();
  TYPE(u128_rdn_sat, accx1) zero = FN(mzero_acc, u128_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_50_2 (void)
{
  TYPE(u128_rdn_sat, 1x2) m = FN(mzero_m, u128_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u128_rdn_sat, accx2) a = FN(mcopy_m2a, u128_rdn_sat, accx2) (m);
  TYPE(u128_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u128_rdn_sat, 1x2) result = FN(mcopy_a2m, u128_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, u128_rdn_sat, accx2) ();
  TYPE(u128_rdn_sat, accx2) zero = FN(mzero_acc, u128_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_50_4 (void)
{
  TYPE(u128_rdn_sat, 1x4) m = FN(mzero_m, u128_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u128_rdn_sat, accx4) a = FN(mcopy_m2a, u128_rdn_sat, accx4) (m);
  TYPE(u128_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u128_rdn_sat, 1x4) result = FN(mcopy_a2m, u128_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, u128_rdn_sat, accx4) ();
  TYPE(u128_rdn_sat, accx4) zero = FN(mzero_acc, u128_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_51_0 (void)
{
  TYPE(i128_rod, 1x1) s = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(u128_rod_sat, 1x1) d = FN(mconv_ew, u128_rod_sat, 1x1) (s);
  d = FN(mabs_ew, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, u128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, u128_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(i128_rod, 1x1) back = FN(mconv_ew, i128_rod, 1x1) (d);
  TYPE(u128_rod_sat, 1x1) copy = FN(mcopy_m2m, u128_rod_sat, 1x1) (d);
  d = FN(mclear_m, u128_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(u128_rod_sat, 1x2) group = FN(mconcat_m, u128_rod_sat, 1x2) (copy, copy);
  TYPE(u128_rod_sat, 1x1) half = FN(mextract, u128_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_51_1 (void)
{
  TYPE(u128_rod_sat, 1x1) m = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(u128_rod_sat, accx1) a = FN(mcopy_m2a, u128_rod_sat, accx1) (m);
  TYPE(u128_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(u128_rod_sat, 1x1) result = FN(mcopy_a2m, u128_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, u128_rod_sat, accx1) ();
  TYPE(u128_rod_sat, accx1) zero = FN(mzero_acc, u128_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_51_2 (void)
{
  TYPE(u128_rod_sat, 1x2) m = FN(mzero_m, u128_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(u128_rod_sat, accx2) a = FN(mcopy_m2a, u128_rod_sat, accx2) (m);
  TYPE(u128_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(u128_rod_sat, 1x2) result = FN(mcopy_a2m, u128_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, u128_rod_sat, accx2) ();
  TYPE(u128_rod_sat, accx2) zero = FN(mzero_acc, u128_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_51_4 (void)
{
  TYPE(u128_rod_sat, 1x4) m = FN(mzero_m, u128_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(u128_rod_sat, accx4) a = FN(mcopy_m2a, u128_rod_sat, accx4) (m);
  TYPE(u128_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(u128_rod_sat, 1x4) result = FN(mcopy_a2m, u128_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, u128_rod_sat, accx4) ();
  TYPE(u128_rod_sat, accx4) zero = FN(mzero_acc, u128_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_52_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rnu_sat, 1x1) d = FN(mconv_ew, i128_rnu_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rnu_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rnu_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rnu_sat, 1x1) copy = FN(mcopy_m2m, i128_rnu_sat, 1x1) (d);
  d = FN(mclear_m, i128_rnu_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i128_rnu_sat, 1x2) group = FN(mconcat_m, i128_rnu_sat, 1x2) (copy, copy);
  TYPE(i128_rnu_sat, 1x1) half = FN(mextract, i128_rnu_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_52_1 (void)
{
  TYPE(i128_rnu_sat, 1x1) m = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rnu_sat, accx1) a = FN(mcopy_m2a, i128_rnu_sat, accx1) (m);
  TYPE(i128_rnu_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rnu_sat, 1x1) result = FN(mcopy_a2m, i128_rnu_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rnu_sat, accx1) ();
  TYPE(i128_rnu_sat, accx1) zero = FN(mzero_acc, i128_rnu_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_52_2 (void)
{
  TYPE(i128_rnu_sat, 1x2) m = FN(mzero_m, i128_rnu_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i128_rnu_sat, accx2) a = FN(mcopy_m2a, i128_rnu_sat, accx2) (m);
  TYPE(i128_rnu_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i128_rnu_sat, 1x2) result = FN(mcopy_a2m, i128_rnu_sat, 1x2) (copy);
  a = FN(mclear_acc, i128_rnu_sat, accx2) ();
  TYPE(i128_rnu_sat, accx2) zero = FN(mzero_acc, i128_rnu_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_52_4 (void)
{
  TYPE(i128_rnu_sat, 1x4) m = FN(mzero_m, i128_rnu_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i128_rnu_sat, accx4) a = FN(mcopy_m2a, i128_rnu_sat, accx4) (m);
  TYPE(i128_rnu_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i128_rnu_sat, 1x4) result = FN(mcopy_a2m, i128_rnu_sat, 1x4) (copy);
  a = FN(mclear_acc, i128_rnu_sat, accx4) ();
  TYPE(i128_rnu_sat, accx4) zero = FN(mzero_acc, i128_rnu_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_53_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rne_sat, 1x1) d = FN(mconv_ew, i128_rne_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rne_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rne_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rne_sat, 1x1) copy = FN(mcopy_m2m, i128_rne_sat, 1x1) (d);
  d = FN(mclear_m, i128_rne_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i128_rne_sat, 1x2) group = FN(mconcat_m, i128_rne_sat, 1x2) (copy, copy);
  TYPE(i128_rne_sat, 1x1) half = FN(mextract, i128_rne_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_53_1 (void)
{
  TYPE(i128_rne_sat, 1x1) m = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rne_sat, accx1) a = FN(mcopy_m2a, i128_rne_sat, accx1) (m);
  TYPE(i128_rne_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rne_sat, 1x1) result = FN(mcopy_a2m, i128_rne_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rne_sat, accx1) ();
  TYPE(i128_rne_sat, accx1) zero = FN(mzero_acc, i128_rne_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_53_2 (void)
{
  TYPE(i128_rne_sat, 1x2) m = FN(mzero_m, i128_rne_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i128_rne_sat, accx2) a = FN(mcopy_m2a, i128_rne_sat, accx2) (m);
  TYPE(i128_rne_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i128_rne_sat, 1x2) result = FN(mcopy_a2m, i128_rne_sat, 1x2) (copy);
  a = FN(mclear_acc, i128_rne_sat, accx2) ();
  TYPE(i128_rne_sat, accx2) zero = FN(mzero_acc, i128_rne_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_53_4 (void)
{
  TYPE(i128_rne_sat, 1x4) m = FN(mzero_m, i128_rne_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i128_rne_sat, accx4) a = FN(mcopy_m2a, i128_rne_sat, accx4) (m);
  TYPE(i128_rne_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i128_rne_sat, 1x4) result = FN(mcopy_a2m, i128_rne_sat, 1x4) (copy);
  a = FN(mclear_acc, i128_rne_sat, accx4) ();
  TYPE(i128_rne_sat, accx4) zero = FN(mzero_acc, i128_rne_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_54_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rdn_sat, 1x1) d = FN(mconv_ew, i128_rdn_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rdn_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rdn_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rdn_sat, 1x1) copy = FN(mcopy_m2m, i128_rdn_sat, 1x1) (d);
  d = FN(mclear_m, i128_rdn_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i128_rdn_sat, 1x2) group = FN(mconcat_m, i128_rdn_sat, 1x2) (copy, copy);
  TYPE(i128_rdn_sat, 1x1) half = FN(mextract, i128_rdn_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_54_1 (void)
{
  TYPE(i128_rdn_sat, 1x1) m = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rdn_sat, accx1) a = FN(mcopy_m2a, i128_rdn_sat, accx1) (m);
  TYPE(i128_rdn_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rdn_sat, 1x1) result = FN(mcopy_a2m, i128_rdn_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rdn_sat, accx1) ();
  TYPE(i128_rdn_sat, accx1) zero = FN(mzero_acc, i128_rdn_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_54_2 (void)
{
  TYPE(i128_rdn_sat, 1x2) m = FN(mzero_m, i128_rdn_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i128_rdn_sat, accx2) a = FN(mcopy_m2a, i128_rdn_sat, accx2) (m);
  TYPE(i128_rdn_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i128_rdn_sat, 1x2) result = FN(mcopy_a2m, i128_rdn_sat, 1x2) (copy);
  a = FN(mclear_acc, i128_rdn_sat, accx2) ();
  TYPE(i128_rdn_sat, accx2) zero = FN(mzero_acc, i128_rdn_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_54_4 (void)
{
  TYPE(i128_rdn_sat, 1x4) m = FN(mzero_m, i128_rdn_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i128_rdn_sat, accx4) a = FN(mcopy_m2a, i128_rdn_sat, accx4) (m);
  TYPE(i128_rdn_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i128_rdn_sat, 1x4) result = FN(mcopy_a2m, i128_rdn_sat, 1x4) (copy);
  a = FN(mclear_acc, i128_rdn_sat, accx4) ();
  TYPE(i128_rdn_sat, accx4) zero = FN(mzero_acc, i128_rdn_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void value_55_0 (void)
{
  TYPE(u128_rod, 1x1) s = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE_M(s);
  TYPE(i128_rod_sat, 1x1) d = FN(mconv_ew, i128_rod_sat, 1x1) (s);
  d = FN(mabs_ew, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_col, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreduceadd_row, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_col, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemax_row, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_col, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mreducemin_row, i128_rod_sat, 1x1) (d);
  KEEP_M(d);
  d = FN(mprefixadd_col, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixadd_row, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_col, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  d = FN(mprefixmax_row, i128_rod_sat, 1x1) (s);
  KEEP_M(d);
  TYPE(u128_rod, 1x1) back = FN(mconv_ew, u128_rod, 1x1) (d);
  TYPE(i128_rod_sat, 1x1) copy = FN(mcopy_m2m, i128_rod_sat, 1x1) (d);
  d = FN(mclear_m, i128_rod_sat, 1x1) ();
  KEEP_M(copy); KEEP_M(d); KEEP_M(back); KEEP_M(s);
  TYPE(i128_rod_sat, 1x2) group = FN(mconcat_m, i128_rod_sat, 1x2) (copy, copy);
  TYPE(i128_rod_sat, 1x1) half = FN(mextract, i128_rod_sat, 1x1) (group, 1);
  KEEP_M(group); KEEP_M(half);
}
void acc_55_1 (void)
{
  TYPE(i128_rod_sat, 1x1) m = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE_M(m);
  TYPE(i128_rod_sat, accx1) a = FN(mcopy_m2a, i128_rod_sat, accx1) (m);
  TYPE(i128_rod_sat, accx1) copy = a;
  CHANGE_A(a);
  TYPE(i128_rod_sat, 1x1) result = FN(mcopy_a2m, i128_rod_sat, 1x1) (copy);
  a = FN(mclear_acc, i128_rod_sat, accx1) ();
  TYPE(i128_rod_sat, accx1) zero = FN(mzero_acc, i128_rod_sat, accx1) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_55_2 (void)
{
  TYPE(i128_rod_sat, 1x2) m = FN(mzero_m, i128_rod_sat, 1x2) ();
  CHANGE_M(m);
  TYPE(i128_rod_sat, accx2) a = FN(mcopy_m2a, i128_rod_sat, accx2) (m);
  TYPE(i128_rod_sat, accx2) copy = a;
  CHANGE_A(a);
  TYPE(i128_rod_sat, 1x2) result = FN(mcopy_a2m, i128_rod_sat, 1x2) (copy);
  a = FN(mclear_acc, i128_rod_sat, accx2) ();
  TYPE(i128_rod_sat, accx2) zero = FN(mzero_acc, i128_rod_sat, accx2) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
void acc_55_4 (void)
{
  TYPE(i128_rod_sat, 1x4) m = FN(mzero_m, i128_rod_sat, 1x4) ();
  CHANGE_M(m);
  TYPE(i128_rod_sat, accx4) a = FN(mcopy_m2a, i128_rod_sat, accx4) (m);
  TYPE(i128_rod_sat, accx4) copy = a;
  CHANGE_A(a);
  TYPE(i128_rod_sat, 1x4) result = FN(mcopy_a2m, i128_rod_sat, 1x4) (copy);
  a = FN(mclear_acc, i128_rod_sat, accx4) ();
  TYPE(i128_rod_sat, accx4) zero = FN(mzero_acc, i128_rod_sat, accx4) ();
  KEEP_A(copy); KEEP_A(a); KEEP_A(zero); KEEP_M(result);
}
#endif
