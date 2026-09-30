/* Selected kind/RM/operation matrix, not an exhaustive tuple product.  */
#include <riscv_ztt.h>
#if __riscv_ztt_integer_kinds_matrix != 1
#error missing integer matrix support
#endif
#define TYPE_(D, S) __riscv_ztt_##D##_##S##_t
#define TYPE(D, S) TYPE_(D, S)
#define FN_(O, D, S) __riscv_ztt_##O##_##D##_##S
#define FN(O, D, S) FN_(O, D, S)
#define CHANGE(X) __asm__ volatile ("" : "+Wmr" (X))
#define KEEP(X) __asm__ volatile ("" : : "Wmr" (X))

#if TEST_UDS == 8
void case_8_0 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne, 1x2) r = FN(madd_ew, i4_rne, 1x2) (a, b);
  KEEP(r);
}
void case_8_1 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 2x1) r = FN(msub_ew, i4_rdn, 2x1) (a, b);
  KEEP(r);
}
void case_8_2 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod, 1x2) r = FN(mmul_ew, i4_rod, 1x2) (a, b);
  KEEP(r);
}
void case_8_3 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 2x1) r = FN(mmulneg_ew, i4_rnu, 2x1) (a, b);
  KEEP(r);
}
void case_8_4 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne, 1x2) r = FN(mabsdiff_ew, i4_rne, 1x2) (a, b);
  KEEP(r);
}
void case_8_5 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 2x1) r = FN(mhdiff_ew, i4_rdn, 2x1) (a, b);
  KEEP(r);
}
void case_8_6 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod, 1x2) r = FN(mmean_ew, i4_rod, 1x2) (a, b);
  KEEP(r);
}
void case_8_7 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 2x1) r = FN(mcmpge_ew, i4_rnu, 2x1) (a, b);
  KEEP(r);
}
void case_8_8 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne, 1x2) r = FN(mcmplt_ew, i4_rne, 1x2) (a, b);
  KEEP(r);
}
void case_8_9 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 2x1) b = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 2x1) r = FN(mselge_ew, i4_rdn, 2x1) (a, b);
  KEEP(r);
}
void case_8_10 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod, 1x2) b = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod, 1x2) r = FN(msellt_ew, i4_rod, 1x2) (a, b);
  KEEP(r);
}
void case_8_11 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 2x1) r = FN(msll_ew, i4_rnu, 2x1) (a, b);
  KEEP(r);
}
void case_8_12 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(i4_rne, 1x2) r = FN(msll_ew_x, i4_rne, 1x2) (a, 1);
  KEEP(r);
}
void case_8_13 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 2x1) r = FN(msrl_ew, i4_rdn, 2x1) (a, b);
  KEEP(r);
}
void case_8_14 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod, 1x2) r = FN(msrl_ew_x, i4_rod, 1x2) (a, 1);
  KEEP(r);
}
void case_8_15 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 2x1) r = FN(msra_ew, i4_rnu, 2x1) (a, b);
  KEEP(r);
}
void case_8_16 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(i4_rne, 1x2) r = FN(msra_ew_x, i4_rne, 1x2) (a, 1);
  KEEP(r);
}
void case_8_17 (void)
{
  TYPE(i4_rdn, 2x1) old = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 2x1) r = FN(mmulacc_ew, i4_rdn, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_18 (void)
{
  TYPE(i4_rod, 1x2) old = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(old);
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod, 1x2) r = FN(mmulaccneg_ew, i4_rod, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_19 (void)
{
  TYPE(i4_rnu, 2x1) old = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 2x1) r = FN(mmuladd_ew, i4_rnu, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_20 (void)
{
  TYPE(i4_rne, 1x2) old = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(old);
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne, 1x2) r = FN(mmulsub_ew, i4_rne, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_21 (void)
{
  TYPE(i4_rdn, 2x1) old = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 2x1) b = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 2x1) r = FN(mcmovge_ew, i4_rdn, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_22 (void)
{
  TYPE(i4_rod, 1x2) old = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(old);
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod, 1x2) b = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod, 1x2) r = FN(mcmovlt_ew, i4_rod, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_23 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 2x1) b = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 2x1) r = FN(mmin_ew, i4_rdn, 2x1) (a, b);
  KEEP(r);
}
void case_8_24 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod, 1x2) b = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod, 1x2) r = FN(mmax_ew, i4_rod, 1x2) (a, b);
  KEEP(r);
}
void case_8_25 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 2x1) b = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 2x1) r = FN(mand_ew, i4_rnu, 2x1) (a, b);
  KEEP(r);
}
void case_8_26 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(i4_rne, 1x2) b = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne, 1x2) r = FN(mandnot_ew, i4_rne, 1x2) (a, b);
  KEEP(r);
}
void case_8_27 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 2x1) b = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 2x1) r = FN(mor_ew, i4_rdn, 2x1) (a, b);
  KEEP(r);
}
void case_8_28 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod, 1x2) b = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod, 1x2) r = FN(mornot_ew, i4_rod, 1x2) (a, b);
  KEEP(r);
}
void case_8_29 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 2x1) b = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 2x1) r = FN(mxor_ew, i4_rnu, 2x1) (a, b);
  KEEP(r);
}
void case_8_30 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x2) r = FN(madd_ew, u4_rnu, 1x2) (a, b);
  KEEP(r);
}
void case_8_31 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne, 2x1) r = FN(msub_ew, u4_rne, 2x1) (a, b);
  KEEP(r);
}
void case_8_32 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x2) r = FN(mmul_ew, u4_rdn, 1x2) (a, b);
  KEEP(r);
}
void case_8_33 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod, 2x1) r = FN(mmulneg_ew, u4_rod, 2x1) (a, b);
  KEEP(r);
}
void case_8_34 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x2) r = FN(mabsdiff_ew, u4_rnu, 1x2) (a, b);
  KEEP(r);
}
void case_8_35 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne, 2x1) r = FN(mhdiff_ew, u4_rne, 2x1) (a, b);
  KEEP(r);
}
void case_8_36 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x2) r = FN(mmean_ew, u4_rdn, 1x2) (a, b);
  KEEP(r);
}
void case_8_37 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod, 2x1) r = FN(mcmpge_ew, u4_rod, 2x1) (a, b);
  KEEP(r);
}
void case_8_38 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x2) r = FN(mcmplt_ew, u4_rnu, 1x2) (a, b);
  KEEP(r);
}
void case_8_39 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne, 2x1) r = FN(mselge_ew, u4_rne, 2x1) (a, b);
  KEEP(r);
}
void case_8_40 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x2) r = FN(msellt_ew, u4_rdn, 1x2) (a, b);
  KEEP(r);
}
void case_8_41 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod, 2x1) r = FN(msll_ew, u4_rod, 2x1) (a, b);
  KEEP(r);
}
void case_8_42 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) r = FN(msll_ew_x, u4_rnu, 1x2) (a, 1);
  KEEP(r);
}
void case_8_43 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne, 2x1) r = FN(msrl_ew, u4_rne, 2x1) (a, b);
  KEEP(r);
}
void case_8_44 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) r = FN(msrl_ew_x, u4_rdn, 1x2) (a, 1);
  KEEP(r);
}
void case_8_45 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod, 2x1) r = FN(msra_ew, u4_rod, 2x1) (a, b);
  KEEP(r);
}
void case_8_46 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) r = FN(msra_ew_x, u4_rnu, 1x2) (a, 1);
  KEEP(r);
}
void case_8_47 (void)
{
  TYPE(u4_rne, 2x1) old = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne, 2x1) r = FN(mmulacc_ew, u4_rne, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_48 (void)
{
  TYPE(u4_rdn, 1x2) old = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(old);
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x2) r = FN(mmulaccneg_ew, u4_rdn, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_49 (void)
{
  TYPE(u4_rod, 2x1) old = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod, 2x1) r = FN(mmuladd_ew, u4_rod, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_50 (void)
{
  TYPE(u4_rnu, 1x2) old = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(old);
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x2) r = FN(mmulsub_ew, u4_rnu, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_51 (void)
{
  TYPE(u4_rne, 2x1) old = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne, 2x1) r = FN(mcmovge_ew, u4_rne, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_52 (void)
{
  TYPE(u4_rdn, 1x2) old = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(old);
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x2) r = FN(mcmovlt_ew, u4_rdn, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_53 (void)
{
  TYPE(u4_rne, 2x1) a = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne, 2x1) r = FN(mmin_ew, u4_rne, 2x1) (a, b);
  KEEP(r);
}
void case_8_54 (void)
{
  TYPE(u4_rdn, 1x2) a = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x2) r = FN(mmax_ew, u4_rdn, 1x2) (a, b);
  KEEP(r);
}
void case_8_55 (void)
{
  TYPE(u4_rod, 2x1) a = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod, 2x1) r = FN(mand_ew, u4_rod, 2x1) (a, b);
  KEEP(r);
}
void case_8_56 (void)
{
  TYPE(u4_rnu, 1x2) a = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x2) r = FN(mandnot_ew, u4_rnu, 1x2) (a, b);
  KEEP(r);
}
void case_8_57 (void)
{
  TYPE(u4_rne, 2x1) a = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne, 2x1) r = FN(mor_ew, u4_rne, 2x1) (a, b);
  KEEP(r);
}
void case_8_58 (void)
{
  TYPE(u4_rdn, 1x2) a = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x2) r = FN(mornot_ew, u4_rdn, 1x2) (a, b);
  KEEP(r);
}
void case_8_59 (void)
{
  TYPE(u4_rod, 2x1) a = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod, 2x1) r = FN(mxor_ew, u4_rod, 2x1) (a, b);
  KEEP(r);
}
void case_8_60 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x2) r = FN(madd_ew, i4_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_61 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 2x1) r = FN(msub_ew, i4_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_62 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x2) r = FN(mmul_ew, i4_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_63 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 2x1) r = FN(mmulneg_ew, i4_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_64 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x2) r = FN(mabsdiff_ew, i4_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_65 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 2x1) r = FN(mhdiff_ew, i4_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_66 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x2) r = FN(mmean_ew, i4_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_67 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 2x1) r = FN(mcmpge_ew, i4_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_68 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x2) r = FN(mcmplt_ew, i4_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_69 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 2x1) b = FN(mzero_m, i4_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 2x1) r = FN(mselge_ew, i4_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_70 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x2) b = FN(mzero_m, i4_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x2) r = FN(msellt_ew, i4_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_71 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 2x1) r = FN(msll_ew, i4_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_72 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x2) r = FN(msll_ew_x, i4_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_8_73 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 2x1) r = FN(msrl_ew, i4_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_74 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x2) r = FN(msrl_ew_x, i4_rod_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_8_75 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 2x1) r = FN(msra_ew, i4_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_76 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x2) r = FN(msra_ew_x, i4_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_8_77 (void)
{
  TYPE(i4_rdn_sat, 2x1) old = FN(mzero_m, i4_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 2x1) r = FN(mmulacc_ew, i4_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_78 (void)
{
  TYPE(i4_rod_sat, 1x2) old = FN(mzero_m, i4_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x2) r = FN(mmulaccneg_ew, i4_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_79 (void)
{
  TYPE(i4_rnu_sat, 2x1) old = FN(mzero_m, i4_rnu_sat, 2x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 2x1) r = FN(mmuladd_ew, i4_rnu_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_80 (void)
{
  TYPE(i4_rne_sat, 1x2) old = FN(mzero_m, i4_rne_sat, 1x2) ();
  CHANGE(old);
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x2) r = FN(mmulsub_ew, i4_rne_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_81 (void)
{
  TYPE(i4_rdn_sat, 2x1) old = FN(mzero_m, i4_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 2x1) b = FN(mzero_m, i4_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 2x1) r = FN(mcmovge_ew, i4_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_82 (void)
{
  TYPE(i4_rod_sat, 1x2) old = FN(mzero_m, i4_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x2) b = FN(mzero_m, i4_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x2) r = FN(mcmovlt_ew, i4_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_83 (void)
{
  TYPE(i4_rdn_sat, 2x1) a = FN(mzero_m, i4_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 2x1) b = FN(mzero_m, i4_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 2x1) r = FN(mmin_ew, i4_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_84 (void)
{
  TYPE(i4_rod_sat, 1x2) a = FN(mzero_m, i4_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x2) b = FN(mzero_m, i4_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x2) r = FN(mmax_ew, i4_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_85 (void)
{
  TYPE(i4_rnu_sat, 2x1) a = FN(mzero_m, i4_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 2x1) b = FN(mzero_m, i4_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 2x1) r = FN(mand_ew, i4_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_86 (void)
{
  TYPE(i4_rne_sat, 1x2) a = FN(mzero_m, i4_rne_sat, 1x2) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x2) b = FN(mzero_m, i4_rne_sat, 1x2) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x2) r = FN(mandnot_ew, i4_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_87 (void)
{
  TYPE(i4_rdn_sat, 2x1) a = FN(mzero_m, i4_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 2x1) b = FN(mzero_m, i4_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 2x1) r = FN(mor_ew, i4_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_88 (void)
{
  TYPE(i4_rod_sat, 1x2) a = FN(mzero_m, i4_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x2) b = FN(mzero_m, i4_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x2) r = FN(mornot_ew, i4_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_89 (void)
{
  TYPE(i4_rnu_sat, 2x1) a = FN(mzero_m, i4_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 2x1) b = FN(mzero_m, i4_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 2x1) r = FN(mxor_ew, i4_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_90 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x2) r = FN(madd_ew, u4_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_91 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 2x1) r = FN(msub_ew, u4_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_92 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x2) r = FN(mmul_ew, u4_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_93 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 2x1) r = FN(mmulneg_ew, u4_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_94 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x2) r = FN(mabsdiff_ew, u4_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_95 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 2x1) r = FN(mhdiff_ew, u4_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_96 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x2) r = FN(mmean_ew, u4_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_97 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 2x1) r = FN(mcmpge_ew, u4_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_98 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x2) r = FN(mcmplt_ew, u4_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_99 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 2x1) b = FN(mzero_m, u4_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 2x1) r = FN(mselge_ew, u4_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_100 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x2) b = FN(mzero_m, u4_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x2) r = FN(msellt_ew, u4_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_101 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 2x1) r = FN(msll_ew, u4_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_102 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x2) r = FN(msll_ew_x, u4_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_8_103 (void)
{
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 2x1) r = FN(msrl_ew, u4_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_104 (void)
{
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x2) r = FN(msrl_ew_x, u4_rdn_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_8_105 (void)
{
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 2x1) r = FN(msra_ew, u4_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_106 (void)
{
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x2) r = FN(msra_ew_x, u4_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_8_107 (void)
{
  TYPE(u4_rne_sat, 2x1) old = FN(mzero_m, u4_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod, 2x1) b = FN(mzero_m, u4_rod, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 2x1) r = FN(mmulacc_ew, u4_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_108 (void)
{
  TYPE(u4_rdn_sat, 1x2) old = FN(mzero_m, u4_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x2) b = FN(mzero_m, u4_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x2) r = FN(mmulaccneg_ew, u4_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_109 (void)
{
  TYPE(u4_rod_sat, 2x1) old = FN(mzero_m, u4_rod_sat, 2x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 2x1) a = FN(mzero_m, i4_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne, 2x1) b = FN(mzero_m, u4_rne, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 2x1) r = FN(mmuladd_ew, u4_rod_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_110 (void)
{
  TYPE(u4_rnu_sat, 1x2) old = FN(mzero_m, u4_rnu_sat, 1x2) ();
  CHANGE(old);
  TYPE(i4_rne, 1x2) a = FN(mzero_m, i4_rne, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x2) b = FN(mzero_m, u4_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x2) r = FN(mmulsub_ew, u4_rnu_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_111 (void)
{
  TYPE(u4_rne_sat, 2x1) old = FN(mzero_m, u4_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 2x1) a = FN(mzero_m, i4_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 2x1) b = FN(mzero_m, u4_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 2x1) r = FN(mcmovge_ew, u4_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_8_112 (void)
{
  TYPE(u4_rdn_sat, 1x2) old = FN(mzero_m, u4_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i4_rod, 1x2) a = FN(mzero_m, i4_rod, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x2) b = FN(mzero_m, u4_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x2) r = FN(mcmovlt_ew, u4_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_8_113 (void)
{
  TYPE(u4_rne_sat, 2x1) a = FN(mzero_m, u4_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 2x1) b = FN(mzero_m, u4_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 2x1) r = FN(mmin_ew, u4_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_114 (void)
{
  TYPE(u4_rdn_sat, 1x2) a = FN(mzero_m, u4_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x2) b = FN(mzero_m, u4_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x2) r = FN(mmax_ew, u4_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_115 (void)
{
  TYPE(u4_rod_sat, 2x1) a = FN(mzero_m, u4_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 2x1) b = FN(mzero_m, u4_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 2x1) r = FN(mand_ew, u4_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_116 (void)
{
  TYPE(u4_rnu_sat, 1x2) a = FN(mzero_m, u4_rnu_sat, 1x2) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x2) b = FN(mzero_m, u4_rnu_sat, 1x2) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x2) r = FN(mandnot_ew, u4_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_117 (void)
{
  TYPE(u4_rne_sat, 2x1) a = FN(mzero_m, u4_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 2x1) b = FN(mzero_m, u4_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 2x1) r = FN(mor_ew, u4_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_118 (void)
{
  TYPE(u4_rdn_sat, 1x2) a = FN(mzero_m, u4_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x2) b = FN(mzero_m, u4_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x2) r = FN(mornot_ew, u4_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_8_119 (void)
{
  TYPE(u4_rod_sat, 2x1) a = FN(mzero_m, u4_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 2x1) b = FN(mzero_m, u4_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 2x1) r = FN(mxor_ew, u4_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_8_120 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x1) r = FN(madd_ew, i8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_121 (void)
{
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 1x1) r = FN(msub_ew, i8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_122 (void)
{
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x1) b = FN(mzero_m, u8_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x1) r = FN(mmul_ew, i8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_123 (void)
{
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x1) r = FN(mmulneg_ew, i8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_124 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x1) r = FN(mabsdiff_ew, i8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_125 (void)
{
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 1x1) r = FN(mhdiff_ew, i8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_126 (void)
{
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x1) b = FN(mzero_m, u8_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x1) r = FN(mmean_ew, i8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_127 (void)
{
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x1) r = FN(mcmpge_ew, i8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_128 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x1) r = FN(mcmplt_ew, i8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_129 (void)
{
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 1x1) b = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 1x1) r = FN(mselge_ew, i8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_130 (void)
{
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x1) b = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x1) r = FN(msellt_ew, i8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_131 (void)
{
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x1) r = FN(msll_ew, i8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_132 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x1) r = FN(msll_ew_x, i8_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_133 (void)
{
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 1x1) r = FN(msrl_ew, i8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_134 (void)
{
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x1) r = FN(msrl_ew_x, i8_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_135 (void)
{
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x1) r = FN(msra_ew, i8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_136 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x1) r = FN(msra_ew_x, i8_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_137 (void)
{
  TYPE(i8_rdn_sat, 1x1) old = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 1x1) r = FN(mmulacc_ew, i8_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_138 (void)
{
  TYPE(i8_rod_sat, 1x1) old = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x1) b = FN(mzero_m, u8_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x1) r = FN(mmulaccneg_ew, i8_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_139 (void)
{
  TYPE(i8_rnu_sat, 1x1) old = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x1) r = FN(mmuladd_ew, i8_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_140 (void)
{
  TYPE(i8_rne_sat, 1x1) old = FN(mzero_m, i8_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x1) r = FN(mmulsub_ew, i8_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_141 (void)
{
  TYPE(i8_rdn_sat, 1x1) old = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 1x1) b = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 1x1) r = FN(mcmovge_ew, i8_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_142 (void)
{
  TYPE(i8_rod_sat, 1x1) old = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x1) b = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x1) r = FN(mcmovlt_ew, i8_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_143 (void)
{
  TYPE(i8_rnu_sat, 1x1) a = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x1) r = FN(mcolgather_ew, i8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_144 (void)
{
  TYPE(i8_rne_sat, 1x1) a = FN(mzero_m, i8_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x1) r = FN(mrowgather_ew, i8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_145 (void)
{
  TYPE(i8_rdn_sat, 1x1) old = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i8_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_146 (void)
{
  TYPE(i8_rod_sat, 1x1) old = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x1) b = FN(mzero_m, u8_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x1) r = FN(mrowscatadd_ew, i8_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_147 (void)
{
  TYPE(i8_rnu_sat, 1x1) old = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i8_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_148 (void)
{
  TYPE(i8_rne_sat, 1x1) old = FN(mzero_m, i8_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x1) r = FN(mrowscatmax_ew, i8_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_149 (void)
{
  TYPE(i8_rdn_sat, 1x1) a = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 1x1) b = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 1x1) r = FN(mmin_ew, i8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_150 (void)
{
  TYPE(i8_rod_sat, 1x1) a = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x1) b = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x1) r = FN(mmax_ew, i8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_151 (void)
{
  TYPE(i8_rnu_sat, 1x1) a = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 1x1) b = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x1) r = FN(mand_ew, i8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_152 (void)
{
  TYPE(i8_rne_sat, 1x1) a = FN(mzero_m, i8_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x1) b = FN(mzero_m, i8_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x1) r = FN(mandnot_ew, i8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_153 (void)
{
  TYPE(i8_rdn_sat, 1x1) a = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 1x1) b = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 1x1) r = FN(mor_ew, i8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_154 (void)
{
  TYPE(i8_rod_sat, 1x1) a = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x1) b = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x1) r = FN(mornot_ew, i8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_155 (void)
{
  TYPE(i8_rnu_sat, 1x1) a = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 1x1) b = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x1) r = FN(mxor_ew, i8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_156 (void)
{
  TYPE(i8_rne_sat, 1x1) a = FN(mzero_m, i8_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i8_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_157 (void)
{
  TYPE(i8_rdn_sat, 1x1) a = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i8_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_158 (void)
{
  TYPE(i8_rod_sat, 1x1) a = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x1) b = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x2) pair = FN(mconcat_m, i8_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i8_rod_sat, 1x2) (pair);
  a = FN(mextract, i8_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i8_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_159 (void)
{
  TYPE(i8_rnu_sat, 1x1) a = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 1x1) b = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x2) pair = FN(mconcat_m, i8_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i8_rnu_sat, 1x2) (pair);
  a = FN(mextract, i8_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i8_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_160 (void)
{
  TYPE(i8_rne_sat, 1x1) r = FN(mcolid_ew, i8_rne_sat, 1x1) ();
  KEEP(r);
}
void case_8_161 (void)
{
  TYPE(i8_rdn_sat, 1x1) a = FN(mzero_m, i8_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i8_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_162 (void)
{
  TYPE(i8_rod_sat, 1x1) a = FN(mzero_m, i8_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x1) r = FN(mrowshift_ew_x, i8_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_163 (void)
{
  TYPE(i8_rnu_sat, 1x1) a = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 1x1) b = FN(mzero_m, i8_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 1x2) pair = FN(mconcat_m, i8_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i8_rnu_sat, 1x2) (pair);
  a = FN(mextract, i8_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i8_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_164 (void)
{
  TYPE(i8_rne_sat, 1x1) a = FN(mzero_m, i8_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x1) b = FN(mzero_m, i8_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x2) pair = FN(mconcat_m, i8_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i8_rne_sat, 1x2) (pair);
  a = FN(mextract, i8_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i8_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_165 (void)
{
  TYPE(i8_rdn_sat, 1x1) r = FN(mrowid_ew, i8_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_8_166 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x1) r = FN(madd_ew, u8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_167 (void)
{
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 1x1) r = FN(msub_ew, u8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_168 (void)
{
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x1) b = FN(mzero_m, u8_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x1) r = FN(mmul_ew, u8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_169 (void)
{
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x1) r = FN(mmulneg_ew, u8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_170 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x1) r = FN(mabsdiff_ew, u8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_171 (void)
{
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 1x1) r = FN(mhdiff_ew, u8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_172 (void)
{
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x1) b = FN(mzero_m, u8_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x1) r = FN(mmean_ew, u8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_173 (void)
{
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x1) r = FN(mcmpge_ew, u8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_174 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x1) r = FN(mcmplt_ew, u8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_175 (void)
{
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 1x1) b = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 1x1) r = FN(mselge_ew, u8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_176 (void)
{
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x1) b = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x1) r = FN(msellt_ew, u8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_177 (void)
{
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x1) r = FN(msll_ew, u8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_178 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x1) r = FN(msll_ew_x, u8_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_179 (void)
{
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 1x1) r = FN(msrl_ew, u8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_180 (void)
{
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x1) r = FN(msrl_ew_x, u8_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_181 (void)
{
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x1) r = FN(msra_ew, u8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_182 (void)
{
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x1) r = FN(msra_ew_x, u8_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_183 (void)
{
  TYPE(u8_rne_sat, 1x1) old = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 1x1) r = FN(mmulacc_ew, u8_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_184 (void)
{
  TYPE(u8_rdn_sat, 1x1) old = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x1) b = FN(mzero_m, u8_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u8_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_185 (void)
{
  TYPE(u8_rod_sat, 1x1) old = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x1) r = FN(mmuladd_ew, u8_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_186 (void)
{
  TYPE(u8_rnu_sat, 1x1) old = FN(mzero_m, u8_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x1) r = FN(mmulsub_ew, u8_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_187 (void)
{
  TYPE(u8_rne_sat, 1x1) old = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 1x1) b = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 1x1) r = FN(mcmovge_ew, u8_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_188 (void)
{
  TYPE(u8_rdn_sat, 1x1) old = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x1) b = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x1) r = FN(mcmovlt_ew, u8_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_189 (void)
{
  TYPE(u8_rod_sat, 1x1) a = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x1) r = FN(mcolgather_ew, u8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_190 (void)
{
  TYPE(u8_rnu_sat, 1x1) a = FN(mzero_m, u8_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x1) r = FN(mrowgather_ew, u8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_191 (void)
{
  TYPE(u8_rne_sat, 1x1) old = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 1x1) a = FN(mzero_m, i8_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod, 1x1) b = FN(mzero_m, u8_rod, 1x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 1x1) r = FN(mcolscatadd_ew, u8_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_192 (void)
{
  TYPE(u8_rdn_sat, 1x1) old = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rod, 1x1) a = FN(mzero_m, i8_rod, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x1) b = FN(mzero_m, u8_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u8_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_193 (void)
{
  TYPE(u8_rod_sat, 1x1) old = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 1x1) a = FN(mzero_m, i8_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne, 1x1) b = FN(mzero_m, u8_rne, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x1) r = FN(mcolscatmax_ew, u8_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_194 (void)
{
  TYPE(u8_rnu_sat, 1x1) old = FN(mzero_m, u8_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i8_rne, 1x1) a = FN(mzero_m, i8_rne, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x1) b = FN(mzero_m, u8_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u8_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_195 (void)
{
  TYPE(u8_rne_sat, 1x1) a = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 1x1) b = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 1x1) r = FN(mmin_ew, u8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_196 (void)
{
  TYPE(u8_rdn_sat, 1x1) a = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x1) b = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x1) r = FN(mmax_ew, u8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_197 (void)
{
  TYPE(u8_rod_sat, 1x1) a = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 1x1) b = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x1) r = FN(mand_ew, u8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_198 (void)
{
  TYPE(u8_rnu_sat, 1x1) a = FN(mzero_m, u8_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x1) b = FN(mzero_m, u8_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x1) r = FN(mandnot_ew, u8_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_199 (void)
{
  TYPE(u8_rne_sat, 1x1) a = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 1x1) b = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 1x1) r = FN(mor_ew, u8_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_200 (void)
{
  TYPE(u8_rdn_sat, 1x1) a = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x1) b = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x1) r = FN(mornot_ew, u8_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_201 (void)
{
  TYPE(u8_rod_sat, 1x1) a = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 1x1) b = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x1) r = FN(mxor_ew, u8_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_202 (void)
{
  TYPE(u8_rnu_sat, 1x1) a = FN(mzero_m, u8_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u8_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_203 (void)
{
  TYPE(u8_rne_sat, 1x1) a = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 1x1) r = FN(mcolshift_ew_x, u8_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_204 (void)
{
  TYPE(u8_rdn_sat, 1x1) a = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x1) b = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x2) pair = FN(mconcat_m, u8_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u8_rdn_sat, 1x2) (pair);
  a = FN(mextract, u8_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u8_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_205 (void)
{
  TYPE(u8_rod_sat, 1x1) a = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 1x1) b = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x2) pair = FN(mconcat_m, u8_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u8_rod_sat, 1x2) (pair);
  a = FN(mextract, u8_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u8_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_206 (void)
{
  TYPE(u8_rnu_sat, 1x1) r = FN(mcolid_ew, u8_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_8_207 (void)
{
  TYPE(u8_rne_sat, 1x1) a = FN(mzero_m, u8_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u8_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_208 (void)
{
  TYPE(u8_rdn_sat, 1x1) a = FN(mzero_m, u8_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u8_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_209 (void)
{
  TYPE(u8_rod_sat, 1x1) a = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 1x1) b = FN(mzero_m, u8_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 1x2) pair = FN(mconcat_m, u8_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u8_rod_sat, 1x2) (pair);
  a = FN(mextract, u8_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u8_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_210 (void)
{
  TYPE(u8_rnu_sat, 1x1) a = FN(mzero_m, u8_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x1) b = FN(mzero_m, u8_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x2) pair = FN(mconcat_m, u8_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u8_rnu_sat, 1x2) (pair);
  a = FN(mextract, u8_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u8_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_211 (void)
{
  TYPE(u8_rne_sat, 1x1) r = FN(mrowid_ew, u8_rne_sat, 1x1) ();
  KEEP(r);
}
void case_8_212 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(madd_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_213 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(msub_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_214 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mmul_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_215 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mmulneg_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_216 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mabsdiff_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_217 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mhdiff_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_218 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mmean_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_219 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mcmpge_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_220 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mcmplt_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_221 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) b = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mselge_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_222 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(msellt_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_223 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(msll_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_224 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) r = FN(msll_ew_x, i16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_225 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(msrl_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_226 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) r = FN(msrl_ew_x, i16_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_227 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(msra_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_228 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) r = FN(msra_ew_x, i16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_229 (void)
{
  TYPE(i16_rdn_sat, 1x1) old = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mmulacc_ew, i16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_230 (void)
{
  TYPE(i16_rod_sat, 1x1) old = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mmulaccneg_ew, i16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_231 (void)
{
  TYPE(i16_rnu_sat, 1x1) old = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mmuladd_ew, i16_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_232 (void)
{
  TYPE(i16_rne_sat, 1x1) old = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mmulsub_ew, i16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_233 (void)
{
  TYPE(i16_rdn_sat, 1x1) old = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) b = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mcmovge_ew, i16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_234 (void)
{
  TYPE(i16_rod_sat, 1x1) old = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mcmovlt_ew, i16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_235 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mcolgather_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_236 (void)
{
  TYPE(i16_rne_sat, 1x1) a = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mrowgather_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_237 (void)
{
  TYPE(i16_rdn_sat, 1x1) old = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_238 (void)
{
  TYPE(i16_rod_sat, 1x1) old = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mrowscatadd_ew, i16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_239 (void)
{
  TYPE(i16_rnu_sat, 1x1) old = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i16_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_240 (void)
{
  TYPE(i16_rne_sat, 1x1) old = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mrowscatmax_ew, i16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_241 (void)
{
  TYPE(i16_rdn_sat, 1x1) a = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) b = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mmin_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_242 (void)
{
  TYPE(i16_rod_sat, 1x1) a = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mmax_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_243 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 1x1) b = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mand_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_244 (void)
{
  TYPE(i16_rne_sat, 1x1) a = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) b = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mandnot_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_245 (void)
{
  TYPE(i16_rdn_sat, 1x1) a = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) b = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mor_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_246 (void)
{
  TYPE(i16_rod_sat, 1x1) a = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mornot_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_247 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 1x1) b = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mxor_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_248 (void)
{
  TYPE(i16_rne_sat, 1x1) a = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_249 (void)
{
  TYPE(i16_rdn_sat, 1x1) a = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i16_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_250 (void)
{
  TYPE(i16_rod_sat, 1x1) a = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x2) pair = FN(mconcat_m, i16_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i16_rod_sat, 1x2) (pair);
  a = FN(mextract, i16_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i16_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_251 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 1x1) b = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x2) pair = FN(mconcat_m, i16_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i16_rnu_sat, 1x2) (pair);
  a = FN(mextract, i16_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i16_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_252 (void)
{
  TYPE(i16_rne_sat, 1x1) r = FN(mcolid_ew, i16_rne_sat, 1x1) ();
  KEEP(r);
}
void case_8_253 (void)
{
  TYPE(i16_rdn_sat, 1x1) a = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i16_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_254 (void)
{
  TYPE(i16_rod_sat, 1x1) a = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) r = FN(mrowshift_ew_x, i16_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_255 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 1x1) b = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x2) pair = FN(mconcat_m, i16_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i16_rnu_sat, 1x2) (pair);
  a = FN(mextract, i16_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i16_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_256 (void)
{
  TYPE(i16_rne_sat, 1x1) a = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) b = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x2) pair = FN(mconcat_m, i16_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i16_rne_sat, 1x2) (pair);
  a = FN(mextract, i16_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i16_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_257 (void)
{
  TYPE(i16_rdn_sat, 1x1) r = FN(mrowid_ew, i16_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_8_258 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(madd_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_259 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(msub_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_260 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mmul_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_261 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mmulneg_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_262 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mabsdiff_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_263 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mhdiff_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_264 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mmean_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_265 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mcmpge_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_266 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mcmplt_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_267 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) b = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mselge_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_268 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(msellt_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_269 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(msll_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_270 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) r = FN(msll_ew_x, u16_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_271 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(msrl_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_272 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) r = FN(msrl_ew_x, u16_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_273 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(msra_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_274 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) r = FN(msra_ew_x, u16_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_275 (void)
{
  TYPE(u16_rne_sat, 1x1) old = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mmulacc_ew, u16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_276 (void)
{
  TYPE(u16_rdn_sat, 1x1) old = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_277 (void)
{
  TYPE(u16_rod_sat, 1x1) old = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mmuladd_ew, u16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_278 (void)
{
  TYPE(u16_rnu_sat, 1x1) old = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mmulsub_ew, u16_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_279 (void)
{
  TYPE(u16_rne_sat, 1x1) old = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) b = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mcmovge_ew, u16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_280 (void)
{
  TYPE(u16_rdn_sat, 1x1) old = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mcmovlt_ew, u16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_281 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mcolgather_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_282 (void)
{
  TYPE(u16_rnu_sat, 1x1) a = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mrowgather_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_283 (void)
{
  TYPE(u16_rne_sat, 1x1) old = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mcolscatadd_ew, u16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_284 (void)
{
  TYPE(u16_rdn_sat, 1x1) old = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_285 (void)
{
  TYPE(u16_rod_sat, 1x1) old = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mcolscatmax_ew, u16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_286 (void)
{
  TYPE(u16_rnu_sat, 1x1) old = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u16_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_287 (void)
{
  TYPE(u16_rne_sat, 1x1) a = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) b = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mmin_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_288 (void)
{
  TYPE(u16_rdn_sat, 1x1) a = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mmax_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_289 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 1x1) b = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mand_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_290 (void)
{
  TYPE(u16_rnu_sat, 1x1) a = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) b = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mandnot_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_291 (void)
{
  TYPE(u16_rne_sat, 1x1) a = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) b = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mor_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_292 (void)
{
  TYPE(u16_rdn_sat, 1x1) a = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mornot_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_293 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 1x1) b = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mxor_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_294 (void)
{
  TYPE(u16_rnu_sat, 1x1) a = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u16_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_295 (void)
{
  TYPE(u16_rne_sat, 1x1) a = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) r = FN(mcolshift_ew_x, u16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_296 (void)
{
  TYPE(u16_rdn_sat, 1x1) a = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x2) pair = FN(mconcat_m, u16_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u16_rdn_sat, 1x2) (pair);
  a = FN(mextract, u16_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u16_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_297 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 1x1) b = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x2) pair = FN(mconcat_m, u16_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u16_rod_sat, 1x2) (pair);
  a = FN(mextract, u16_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u16_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_298 (void)
{
  TYPE(u16_rnu_sat, 1x1) r = FN(mcolid_ew, u16_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_8_299 (void)
{
  TYPE(u16_rne_sat, 1x1) a = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_300 (void)
{
  TYPE(u16_rdn_sat, 1x1) a = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u16_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_301 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 1x1) b = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x2) pair = FN(mconcat_m, u16_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u16_rod_sat, 1x2) (pair);
  a = FN(mextract, u16_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u16_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_302 (void)
{
  TYPE(u16_rnu_sat, 1x1) a = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) b = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x2) pair = FN(mconcat_m, u16_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u16_rnu_sat, 1x2) (pair);
  a = FN(mextract, u16_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u16_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_303 (void)
{
  TYPE(u16_rne_sat, 1x1) r = FN(mrowid_ew, u16_rne_sat, 1x1) ();
  KEEP(r);
}
void case_8_304 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(madd_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_305 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(msub_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_306 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmul_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_307 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mmulneg_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_308 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mabsdiff_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_309 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mhdiff_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_310 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmean_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_311 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mcmpge_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_312 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mcmplt_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_313 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mselge_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_314 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(msellt_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_315 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(msll_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_316 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) r = FN(msll_ew_x, i32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_317 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(msrl_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_318 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) r = FN(msrl_ew_x, i32_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_319 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(msra_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_320 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) r = FN(msra_ew_x, i32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_321 (void)
{
  TYPE(i32_rdn_sat, 1x1) old = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mmulacc_ew, i32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_322 (void)
{
  TYPE(i32_rod_sat, 1x1) old = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmulaccneg_ew, i32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_323 (void)
{
  TYPE(i32_rnu_sat, 1x1) old = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mmuladd_ew, i32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_324 (void)
{
  TYPE(i32_rne_sat, 1x1) old = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mmulsub_ew, i32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_325 (void)
{
  TYPE(i32_rdn_sat, 1x1) old = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mcmovge_ew, i32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_326 (void)
{
  TYPE(i32_rod_sat, 1x1) old = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mcmovlt_ew, i32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_327 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mcolgather_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_328 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mrowgather_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_329 (void)
{
  TYPE(i32_rdn_sat, 1x1) old = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_330 (void)
{
  TYPE(i32_rod_sat, 1x1) old = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mrowscatadd_ew, i32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_331 (void)
{
  TYPE(i32_rnu_sat, 1x1) old = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_332 (void)
{
  TYPE(i32_rne_sat, 1x1) old = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mrowscatmax_ew, i32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_333 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mmin_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_334 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmax_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_335 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mand_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_336 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) b = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mandnot_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_337 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mor_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_338 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mornot_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_339 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mxor_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_340 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_341 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_342 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) pair = FN(mconcat_m, i32_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i32_rod_sat, 1x2) (pair);
  a = FN(mextract, i32_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_343 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x2) pair = FN(mconcat_m, i32_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i32_rnu_sat, 1x2) (pair);
  a = FN(mextract, i32_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_344 (void)
{
  TYPE(i32_rne_sat, 1x1) r = FN(mcolid_ew, i32_rne_sat, 1x1) ();
  KEEP(r);
}
void case_8_345 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_346 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) r = FN(mrowshift_ew_x, i32_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_347 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x2) pair = FN(mconcat_m, i32_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i32_rnu_sat, 1x2) (pair);
  a = FN(mextract, i32_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_348 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) b = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x2) pair = FN(mconcat_m, i32_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i32_rne_sat, 1x2) (pair);
  a = FN(mextract, i32_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_349 (void)
{
  TYPE(i32_rdn_sat, 1x1) r = FN(mrowid_ew, i32_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_8_350 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(madd_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_351 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(msub_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_352 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmul_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_353 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mmulneg_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_354 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mabsdiff_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_355 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mhdiff_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_356 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmean_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_357 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mcmpge_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_358 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mcmplt_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_359 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mselge_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_360 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(msellt_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_361 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(msll_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_362 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) r = FN(msll_ew_x, u32_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_363 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(msrl_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_364 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) r = FN(msrl_ew_x, u32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_365 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(msra_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_366 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) r = FN(msra_ew_x, u32_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_367 (void)
{
  TYPE(u32_rne_sat, 1x1) old = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mmulacc_ew, u32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_368 (void)
{
  TYPE(u32_rdn_sat, 1x1) old = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_369 (void)
{
  TYPE(u32_rod_sat, 1x1) old = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mmuladd_ew, u32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_370 (void)
{
  TYPE(u32_rnu_sat, 1x1) old = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mmulsub_ew, u32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_371 (void)
{
  TYPE(u32_rne_sat, 1x1) old = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mcmovge_ew, u32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_372 (void)
{
  TYPE(u32_rdn_sat, 1x1) old = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mcmovlt_ew, u32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_373 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mcolgather_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_374 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mrowgather_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_375 (void)
{
  TYPE(u32_rne_sat, 1x1) old = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mcolscatadd_ew, u32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_376 (void)
{
  TYPE(u32_rdn_sat, 1x1) old = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_377 (void)
{
  TYPE(u32_rod_sat, 1x1) old = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mcolscatmax_ew, u32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_378 (void)
{
  TYPE(u32_rnu_sat, 1x1) old = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_8_379 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mmin_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_380 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmax_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_381 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mand_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_382 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) b = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mandnot_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_383 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mor_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_384 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mornot_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_385 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mxor_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_8_386 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u32_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_387 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) r = FN(mcolshift_ew_x, u32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_388 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) pair = FN(mconcat_m, u32_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u32_rdn_sat, 1x2) (pair);
  a = FN(mextract, u32_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_389 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x2) pair = FN(mconcat_m, u32_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u32_rod_sat, 1x2) (pair);
  a = FN(mextract, u32_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_390 (void)
{
  TYPE(u32_rnu_sat, 1x1) r = FN(mcolid_ew, u32_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_8_391 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_392 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_8_393 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x2) pair = FN(mconcat_m, u32_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u32_rod_sat, 1x2) (pair);
  a = FN(mextract, u32_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_394 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) b = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x2) pair = FN(mconcat_m, u32_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u32_rnu_sat, 1x2) (pair);
  a = FN(mextract, u32_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_8_395 (void)
{
  TYPE(u32_rne_sat, 1x1) r = FN(mrowid_ew, u32_rne_sat, 1x1) ();
  KEEP(r);
}
#endif

#if TEST_UDS == 16
void case_16_0 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne, 1x4) r = FN(madd_ew, i4_rne, 1x4) (a, b);
  KEEP(r);
}
void case_16_1 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 4x1) r = FN(msub_ew, i4_rdn, 4x1) (a, b);
  KEEP(r);
}
void case_16_2 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod, 1x4) r = FN(mmul_ew, i4_rod, 1x4) (a, b);
  KEEP(r);
}
void case_16_3 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 4x1) r = FN(mmulneg_ew, i4_rnu, 4x1) (a, b);
  KEEP(r);
}
void case_16_4 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne, 1x4) r = FN(mabsdiff_ew, i4_rne, 1x4) (a, b);
  KEEP(r);
}
void case_16_5 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 4x1) r = FN(mhdiff_ew, i4_rdn, 4x1) (a, b);
  KEEP(r);
}
void case_16_6 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod, 1x4) r = FN(mmean_ew, i4_rod, 1x4) (a, b);
  KEEP(r);
}
void case_16_7 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 4x1) r = FN(mcmpge_ew, i4_rnu, 4x1) (a, b);
  KEEP(r);
}
void case_16_8 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne, 1x4) r = FN(mcmplt_ew, i4_rne, 1x4) (a, b);
  KEEP(r);
}
void case_16_9 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 4x1) b = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 4x1) r = FN(mselge_ew, i4_rdn, 4x1) (a, b);
  KEEP(r);
}
void case_16_10 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod, 1x4) b = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod, 1x4) r = FN(msellt_ew, i4_rod, 1x4) (a, b);
  KEEP(r);
}
void case_16_11 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 4x1) r = FN(msll_ew, i4_rnu, 4x1) (a, b);
  KEEP(r);
}
void case_16_12 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(i4_rne, 1x4) r = FN(msll_ew_x, i4_rne, 1x4) (a, 1);
  KEEP(r);
}
void case_16_13 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 4x1) r = FN(msrl_ew, i4_rdn, 4x1) (a, b);
  KEEP(r);
}
void case_16_14 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod, 1x4) r = FN(msrl_ew_x, i4_rod, 1x4) (a, 1);
  KEEP(r);
}
void case_16_15 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 4x1) r = FN(msra_ew, i4_rnu, 4x1) (a, b);
  KEEP(r);
}
void case_16_16 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(i4_rne, 1x4) r = FN(msra_ew_x, i4_rne, 1x4) (a, 1);
  KEEP(r);
}
void case_16_17 (void)
{
  TYPE(i4_rdn, 4x1) old = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 4x1) r = FN(mmulacc_ew, i4_rdn, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_18 (void)
{
  TYPE(i4_rod, 1x4) old = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(old);
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod, 1x4) r = FN(mmulaccneg_ew, i4_rod, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_19 (void)
{
  TYPE(i4_rnu, 4x1) old = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 4x1) r = FN(mmuladd_ew, i4_rnu, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_20 (void)
{
  TYPE(i4_rne, 1x4) old = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(old);
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne, 1x4) r = FN(mmulsub_ew, i4_rne, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_21 (void)
{
  TYPE(i4_rdn, 4x1) old = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 4x1) b = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 4x1) r = FN(mcmovge_ew, i4_rdn, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_22 (void)
{
  TYPE(i4_rod, 1x4) old = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(old);
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod, 1x4) b = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod, 1x4) r = FN(mcmovlt_ew, i4_rod, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_23 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 4x1) b = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 4x1) r = FN(mmin_ew, i4_rdn, 4x1) (a, b);
  KEEP(r);
}
void case_16_24 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod, 1x4) b = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod, 1x4) r = FN(mmax_ew, i4_rod, 1x4) (a, b);
  KEEP(r);
}
void case_16_25 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 4x1) b = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 4x1) r = FN(mand_ew, i4_rnu, 4x1) (a, b);
  KEEP(r);
}
void case_16_26 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(i4_rne, 1x4) b = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne, 1x4) r = FN(mandnot_ew, i4_rne, 1x4) (a, b);
  KEEP(r);
}
void case_16_27 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 4x1) b = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 4x1) r = FN(mor_ew, i4_rdn, 4x1) (a, b);
  KEEP(r);
}
void case_16_28 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod, 1x4) b = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod, 1x4) r = FN(mornot_ew, i4_rod, 1x4) (a, b);
  KEEP(r);
}
void case_16_29 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 4x1) b = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 4x1) r = FN(mxor_ew, i4_rnu, 4x1) (a, b);
  KEEP(r);
}
void case_16_30 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x4) r = FN(madd_ew, u4_rnu, 1x4) (a, b);
  KEEP(r);
}
void case_16_31 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne, 4x1) r = FN(msub_ew, u4_rne, 4x1) (a, b);
  KEEP(r);
}
void case_16_32 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x4) r = FN(mmul_ew, u4_rdn, 1x4) (a, b);
  KEEP(r);
}
void case_16_33 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod, 4x1) r = FN(mmulneg_ew, u4_rod, 4x1) (a, b);
  KEEP(r);
}
void case_16_34 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x4) r = FN(mabsdiff_ew, u4_rnu, 1x4) (a, b);
  KEEP(r);
}
void case_16_35 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne, 4x1) r = FN(mhdiff_ew, u4_rne, 4x1) (a, b);
  KEEP(r);
}
void case_16_36 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x4) r = FN(mmean_ew, u4_rdn, 1x4) (a, b);
  KEEP(r);
}
void case_16_37 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod, 4x1) r = FN(mcmpge_ew, u4_rod, 4x1) (a, b);
  KEEP(r);
}
void case_16_38 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x4) r = FN(mcmplt_ew, u4_rnu, 1x4) (a, b);
  KEEP(r);
}
void case_16_39 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne, 4x1) r = FN(mselge_ew, u4_rne, 4x1) (a, b);
  KEEP(r);
}
void case_16_40 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x4) r = FN(msellt_ew, u4_rdn, 1x4) (a, b);
  KEEP(r);
}
void case_16_41 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod, 4x1) r = FN(msll_ew, u4_rod, 4x1) (a, b);
  KEEP(r);
}
void case_16_42 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) r = FN(msll_ew_x, u4_rnu, 1x4) (a, 1);
  KEEP(r);
}
void case_16_43 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne, 4x1) r = FN(msrl_ew, u4_rne, 4x1) (a, b);
  KEEP(r);
}
void case_16_44 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) r = FN(msrl_ew_x, u4_rdn, 1x4) (a, 1);
  KEEP(r);
}
void case_16_45 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod, 4x1) r = FN(msra_ew, u4_rod, 4x1) (a, b);
  KEEP(r);
}
void case_16_46 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) r = FN(msra_ew_x, u4_rnu, 1x4) (a, 1);
  KEEP(r);
}
void case_16_47 (void)
{
  TYPE(u4_rne, 4x1) old = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne, 4x1) r = FN(mmulacc_ew, u4_rne, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_48 (void)
{
  TYPE(u4_rdn, 1x4) old = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(old);
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x4) r = FN(mmulaccneg_ew, u4_rdn, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_49 (void)
{
  TYPE(u4_rod, 4x1) old = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod, 4x1) r = FN(mmuladd_ew, u4_rod, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_50 (void)
{
  TYPE(u4_rnu, 1x4) old = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(old);
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x4) r = FN(mmulsub_ew, u4_rnu, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_51 (void)
{
  TYPE(u4_rne, 4x1) old = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne, 4x1) r = FN(mcmovge_ew, u4_rne, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_52 (void)
{
  TYPE(u4_rdn, 1x4) old = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(old);
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x4) r = FN(mcmovlt_ew, u4_rdn, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_53 (void)
{
  TYPE(u4_rne, 4x1) a = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne, 4x1) r = FN(mmin_ew, u4_rne, 4x1) (a, b);
  KEEP(r);
}
void case_16_54 (void)
{
  TYPE(u4_rdn, 1x4) a = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x4) r = FN(mmax_ew, u4_rdn, 1x4) (a, b);
  KEEP(r);
}
void case_16_55 (void)
{
  TYPE(u4_rod, 4x1) a = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod, 4x1) r = FN(mand_ew, u4_rod, 4x1) (a, b);
  KEEP(r);
}
void case_16_56 (void)
{
  TYPE(u4_rnu, 1x4) a = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x4) r = FN(mandnot_ew, u4_rnu, 1x4) (a, b);
  KEEP(r);
}
void case_16_57 (void)
{
  TYPE(u4_rne, 4x1) a = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne, 4x1) r = FN(mor_ew, u4_rne, 4x1) (a, b);
  KEEP(r);
}
void case_16_58 (void)
{
  TYPE(u4_rdn, 1x4) a = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x4) r = FN(mornot_ew, u4_rdn, 1x4) (a, b);
  KEEP(r);
}
void case_16_59 (void)
{
  TYPE(u4_rod, 4x1) a = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod, 4x1) r = FN(mxor_ew, u4_rod, 4x1) (a, b);
  KEEP(r);
}
void case_16_60 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x4) r = FN(madd_ew, i4_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_61 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 4x1) r = FN(msub_ew, i4_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_62 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x4) r = FN(mmul_ew, i4_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_63 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 4x1) r = FN(mmulneg_ew, i4_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_64 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x4) r = FN(mabsdiff_ew, i4_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_65 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 4x1) r = FN(mhdiff_ew, i4_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_66 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x4) r = FN(mmean_ew, i4_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_67 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 4x1) r = FN(mcmpge_ew, i4_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_68 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x4) r = FN(mcmplt_ew, i4_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_69 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 4x1) b = FN(mzero_m, i4_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 4x1) r = FN(mselge_ew, i4_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_70 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x4) b = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x4) r = FN(msellt_ew, i4_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_71 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 4x1) r = FN(msll_ew, i4_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_72 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x4) r = FN(msll_ew_x, i4_rne_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_16_73 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 4x1) r = FN(msrl_ew, i4_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_74 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x4) r = FN(msrl_ew_x, i4_rod_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_16_75 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 4x1) r = FN(msra_ew, i4_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_76 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x4) r = FN(msra_ew_x, i4_rne_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_16_77 (void)
{
  TYPE(i4_rdn_sat, 4x1) old = FN(mzero_m, i4_rdn_sat, 4x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 4x1) r = FN(mmulacc_ew, i4_rdn_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_78 (void)
{
  TYPE(i4_rod_sat, 1x4) old = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE(old);
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x4) r = FN(mmulaccneg_ew, i4_rod_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_79 (void)
{
  TYPE(i4_rnu_sat, 4x1) old = FN(mzero_m, i4_rnu_sat, 4x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 4x1) r = FN(mmuladd_ew, i4_rnu_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_80 (void)
{
  TYPE(i4_rne_sat, 1x4) old = FN(mzero_m, i4_rne_sat, 1x4) ();
  CHANGE(old);
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x4) r = FN(mmulsub_ew, i4_rne_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_81 (void)
{
  TYPE(i4_rdn_sat, 4x1) old = FN(mzero_m, i4_rdn_sat, 4x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 4x1) b = FN(mzero_m, i4_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 4x1) r = FN(mcmovge_ew, i4_rdn_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_82 (void)
{
  TYPE(i4_rod_sat, 1x4) old = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE(old);
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x4) b = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x4) r = FN(mcmovlt_ew, i4_rod_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_83 (void)
{
  TYPE(i4_rdn_sat, 4x1) a = FN(mzero_m, i4_rdn_sat, 4x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 4x1) b = FN(mzero_m, i4_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 4x1) r = FN(mmin_ew, i4_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_84 (void)
{
  TYPE(i4_rod_sat, 1x4) a = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x4) b = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x4) r = FN(mmax_ew, i4_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_85 (void)
{
  TYPE(i4_rnu_sat, 4x1) a = FN(mzero_m, i4_rnu_sat, 4x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 4x1) b = FN(mzero_m, i4_rnu_sat, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 4x1) r = FN(mand_ew, i4_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_86 (void)
{
  TYPE(i4_rne_sat, 1x4) a = FN(mzero_m, i4_rne_sat, 1x4) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x4) b = FN(mzero_m, i4_rne_sat, 1x4) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x4) r = FN(mandnot_ew, i4_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_87 (void)
{
  TYPE(i4_rdn_sat, 4x1) a = FN(mzero_m, i4_rdn_sat, 4x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 4x1) b = FN(mzero_m, i4_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 4x1) r = FN(mor_ew, i4_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_88 (void)
{
  TYPE(i4_rod_sat, 1x4) a = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x4) b = FN(mzero_m, i4_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x4) r = FN(mornot_ew, i4_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_89 (void)
{
  TYPE(i4_rnu_sat, 4x1) a = FN(mzero_m, i4_rnu_sat, 4x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 4x1) b = FN(mzero_m, i4_rnu_sat, 4x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 4x1) r = FN(mxor_ew, i4_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_90 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x4) r = FN(madd_ew, u4_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_91 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 4x1) r = FN(msub_ew, u4_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_92 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x4) r = FN(mmul_ew, u4_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_93 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 4x1) r = FN(mmulneg_ew, u4_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_94 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x4) r = FN(mabsdiff_ew, u4_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_95 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 4x1) r = FN(mhdiff_ew, u4_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_96 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x4) r = FN(mmean_ew, u4_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_97 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 4x1) r = FN(mcmpge_ew, u4_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_98 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x4) r = FN(mcmplt_ew, u4_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_99 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 4x1) b = FN(mzero_m, u4_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 4x1) r = FN(mselge_ew, u4_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_100 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x4) b = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x4) r = FN(msellt_ew, u4_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_101 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 4x1) r = FN(msll_ew, u4_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_102 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x4) r = FN(msll_ew_x, u4_rnu_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_16_103 (void)
{
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 4x1) r = FN(msrl_ew, u4_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_104 (void)
{
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x4) r = FN(msrl_ew_x, u4_rdn_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_16_105 (void)
{
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 4x1) r = FN(msra_ew, u4_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_106 (void)
{
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x4) r = FN(msra_ew_x, u4_rnu_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_16_107 (void)
{
  TYPE(u4_rne_sat, 4x1) old = FN(mzero_m, u4_rne_sat, 4x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod, 4x1) b = FN(mzero_m, u4_rod, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 4x1) r = FN(mmulacc_ew, u4_rne_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_108 (void)
{
  TYPE(u4_rdn_sat, 1x4) old = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE(old);
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x4) b = FN(mzero_m, u4_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x4) r = FN(mmulaccneg_ew, u4_rdn_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_109 (void)
{
  TYPE(u4_rod_sat, 4x1) old = FN(mzero_m, u4_rod_sat, 4x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 4x1) a = FN(mzero_m, i4_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne, 4x1) b = FN(mzero_m, u4_rne, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 4x1) r = FN(mmuladd_ew, u4_rod_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_110 (void)
{
  TYPE(u4_rnu_sat, 1x4) old = FN(mzero_m, u4_rnu_sat, 1x4) ();
  CHANGE(old);
  TYPE(i4_rne, 1x4) a = FN(mzero_m, i4_rne, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x4) b = FN(mzero_m, u4_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x4) r = FN(mmulsub_ew, u4_rnu_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_111 (void)
{
  TYPE(u4_rne_sat, 4x1) old = FN(mzero_m, u4_rne_sat, 4x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 4x1) a = FN(mzero_m, i4_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 4x1) b = FN(mzero_m, u4_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 4x1) r = FN(mcmovge_ew, u4_rne_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_16_112 (void)
{
  TYPE(u4_rdn_sat, 1x4) old = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE(old);
  TYPE(i4_rod, 1x4) a = FN(mzero_m, i4_rod, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x4) b = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x4) r = FN(mcmovlt_ew, u4_rdn_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_16_113 (void)
{
  TYPE(u4_rne_sat, 4x1) a = FN(mzero_m, u4_rne_sat, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 4x1) b = FN(mzero_m, u4_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 4x1) r = FN(mmin_ew, u4_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_114 (void)
{
  TYPE(u4_rdn_sat, 1x4) a = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x4) b = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x4) r = FN(mmax_ew, u4_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_115 (void)
{
  TYPE(u4_rod_sat, 4x1) a = FN(mzero_m, u4_rod_sat, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 4x1) b = FN(mzero_m, u4_rod_sat, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 4x1) r = FN(mand_ew, u4_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_116 (void)
{
  TYPE(u4_rnu_sat, 1x4) a = FN(mzero_m, u4_rnu_sat, 1x4) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x4) b = FN(mzero_m, u4_rnu_sat, 1x4) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x4) r = FN(mandnot_ew, u4_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_117 (void)
{
  TYPE(u4_rne_sat, 4x1) a = FN(mzero_m, u4_rne_sat, 4x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 4x1) b = FN(mzero_m, u4_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 4x1) r = FN(mor_ew, u4_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_118 (void)
{
  TYPE(u4_rdn_sat, 1x4) a = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x4) b = FN(mzero_m, u4_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x4) r = FN(mornot_ew, u4_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_16_119 (void)
{
  TYPE(u4_rod_sat, 4x1) a = FN(mzero_m, u4_rod_sat, 4x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 4x1) b = FN(mzero_m, u4_rod_sat, 4x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 4x1) r = FN(mxor_ew, u4_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_16_120 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x2) b = FN(mzero_m, u8_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x2) r = FN(madd_ew, i8_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_121 (void)
{
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod, 2x1) b = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 2x1) r = FN(msub_ew, i8_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_122 (void)
{
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x2) b = FN(mzero_m, u8_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x2) r = FN(mmul_ew, i8_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_123 (void)
{
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 2x1) r = FN(mmulneg_ew, i8_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_124 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x2) b = FN(mzero_m, u8_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x2) r = FN(mabsdiff_ew, i8_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_125 (void)
{
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod, 2x1) b = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 2x1) r = FN(mhdiff_ew, i8_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_126 (void)
{
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x2) b = FN(mzero_m, u8_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x2) r = FN(mmean_ew, i8_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_127 (void)
{
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 2x1) r = FN(mcmpge_ew, i8_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_128 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x2) b = FN(mzero_m, u8_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x2) r = FN(mcmplt_ew, i8_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_129 (void)
{
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 2x1) b = FN(mzero_m, i8_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 2x1) r = FN(mselge_ew, i8_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_130 (void)
{
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x2) b = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x2) r = FN(msellt_ew, i8_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_131 (void)
{
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 2x1) r = FN(msll_ew, i8_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_132 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x2) r = FN(msll_ew_x, i8_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_16_133 (void)
{
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod, 2x1) b = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 2x1) r = FN(msrl_ew, i8_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_134 (void)
{
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x2) r = FN(msrl_ew_x, i8_rod_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_16_135 (void)
{
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 2x1) r = FN(msra_ew, i8_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_136 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x2) r = FN(msra_ew_x, i8_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_16_137 (void)
{
  TYPE(i8_rdn_sat, 2x1) old = FN(mzero_m, i8_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod, 2x1) b = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 2x1) r = FN(mmulacc_ew, i8_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_16_138 (void)
{
  TYPE(i8_rod_sat, 1x2) old = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x2) b = FN(mzero_m, u8_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x2) r = FN(mmulaccneg_ew, i8_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_16_139 (void)
{
  TYPE(i8_rnu_sat, 2x1) old = FN(mzero_m, i8_rnu_sat, 2x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 2x1) r = FN(mmuladd_ew, i8_rnu_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_16_140 (void)
{
  TYPE(i8_rne_sat, 1x2) old = FN(mzero_m, i8_rne_sat, 1x2) ();
  CHANGE(old);
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x2) b = FN(mzero_m, u8_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x2) r = FN(mmulsub_ew, i8_rne_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_16_141 (void)
{
  TYPE(i8_rdn_sat, 2x1) old = FN(mzero_m, i8_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 2x1) b = FN(mzero_m, i8_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 2x1) r = FN(mcmovge_ew, i8_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_16_142 (void)
{
  TYPE(i8_rod_sat, 1x2) old = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x2) b = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x2) r = FN(mcmovlt_ew, i8_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_16_143 (void)
{
  TYPE(i8_rdn_sat, 2x1) a = FN(mzero_m, i8_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 2x1) b = FN(mzero_m, i8_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 2x1) r = FN(mmin_ew, i8_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_144 (void)
{
  TYPE(i8_rod_sat, 1x2) a = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x2) b = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x2) r = FN(mmax_ew, i8_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_145 (void)
{
  TYPE(i8_rnu_sat, 2x1) a = FN(mzero_m, i8_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 2x1) b = FN(mzero_m, i8_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 2x1) r = FN(mand_ew, i8_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_146 (void)
{
  TYPE(i8_rne_sat, 1x2) a = FN(mzero_m, i8_rne_sat, 1x2) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x2) b = FN(mzero_m, i8_rne_sat, 1x2) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x2) r = FN(mandnot_ew, i8_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_147 (void)
{
  TYPE(i8_rdn_sat, 2x1) a = FN(mzero_m, i8_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 2x1) b = FN(mzero_m, i8_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 2x1) r = FN(mor_ew, i8_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_148 (void)
{
  TYPE(i8_rod_sat, 1x2) a = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x2) b = FN(mzero_m, i8_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x2) r = FN(mornot_ew, i8_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_149 (void)
{
  TYPE(i8_rnu_sat, 2x1) a = FN(mzero_m, i8_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 2x1) b = FN(mzero_m, i8_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 2x1) r = FN(mxor_ew, i8_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_150 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x2) b = FN(mzero_m, u8_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x2) r = FN(madd_ew, u8_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_151 (void)
{
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod, 2x1) b = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 2x1) r = FN(msub_ew, u8_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_152 (void)
{
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x2) b = FN(mzero_m, u8_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x2) r = FN(mmul_ew, u8_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_153 (void)
{
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 2x1) r = FN(mmulneg_ew, u8_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_154 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x2) b = FN(mzero_m, u8_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x2) r = FN(mabsdiff_ew, u8_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_155 (void)
{
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod, 2x1) b = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 2x1) r = FN(mhdiff_ew, u8_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_156 (void)
{
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x2) b = FN(mzero_m, u8_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x2) r = FN(mmean_ew, u8_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_157 (void)
{
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 2x1) r = FN(mcmpge_ew, u8_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_158 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x2) b = FN(mzero_m, u8_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x2) r = FN(mcmplt_ew, u8_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_159 (void)
{
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 2x1) b = FN(mzero_m, u8_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 2x1) r = FN(mselge_ew, u8_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_160 (void)
{
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x2) b = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x2) r = FN(msellt_ew, u8_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_161 (void)
{
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 2x1) r = FN(msll_ew, u8_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_162 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x2) r = FN(msll_ew_x, u8_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_16_163 (void)
{
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod, 2x1) b = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 2x1) r = FN(msrl_ew, u8_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_164 (void)
{
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x2) r = FN(msrl_ew_x, u8_rdn_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_16_165 (void)
{
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 2x1) r = FN(msra_ew, u8_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_166 (void)
{
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x2) r = FN(msra_ew_x, u8_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_16_167 (void)
{
  TYPE(u8_rne_sat, 2x1) old = FN(mzero_m, u8_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod, 2x1) b = FN(mzero_m, u8_rod, 2x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 2x1) r = FN(mmulacc_ew, u8_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_16_168 (void)
{
  TYPE(u8_rdn_sat, 1x2) old = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x2) b = FN(mzero_m, u8_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x2) r = FN(mmulaccneg_ew, u8_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_16_169 (void)
{
  TYPE(u8_rod_sat, 2x1) old = FN(mzero_m, u8_rod_sat, 2x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 2x1) a = FN(mzero_m, i8_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne, 2x1) b = FN(mzero_m, u8_rne, 2x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 2x1) r = FN(mmuladd_ew, u8_rod_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_16_170 (void)
{
  TYPE(u8_rnu_sat, 1x2) old = FN(mzero_m, u8_rnu_sat, 1x2) ();
  CHANGE(old);
  TYPE(i8_rne, 1x2) a = FN(mzero_m, i8_rne, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x2) b = FN(mzero_m, u8_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x2) r = FN(mmulsub_ew, u8_rnu_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_16_171 (void)
{
  TYPE(u8_rne_sat, 2x1) old = FN(mzero_m, u8_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 2x1) a = FN(mzero_m, i8_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 2x1) b = FN(mzero_m, u8_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 2x1) r = FN(mcmovge_ew, u8_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_16_172 (void)
{
  TYPE(u8_rdn_sat, 1x2) old = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i8_rod, 1x2) a = FN(mzero_m, i8_rod, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x2) b = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x2) r = FN(mcmovlt_ew, u8_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_16_173 (void)
{
  TYPE(u8_rne_sat, 2x1) a = FN(mzero_m, u8_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 2x1) b = FN(mzero_m, u8_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 2x1) r = FN(mmin_ew, u8_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_174 (void)
{
  TYPE(u8_rdn_sat, 1x2) a = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x2) b = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x2) r = FN(mmax_ew, u8_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_175 (void)
{
  TYPE(u8_rod_sat, 2x1) a = FN(mzero_m, u8_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 2x1) b = FN(mzero_m, u8_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 2x1) r = FN(mand_ew, u8_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_176 (void)
{
  TYPE(u8_rnu_sat, 1x2) a = FN(mzero_m, u8_rnu_sat, 1x2) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x2) b = FN(mzero_m, u8_rnu_sat, 1x2) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x2) r = FN(mandnot_ew, u8_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_177 (void)
{
  TYPE(u8_rne_sat, 2x1) a = FN(mzero_m, u8_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 2x1) b = FN(mzero_m, u8_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 2x1) r = FN(mor_ew, u8_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_178 (void)
{
  TYPE(u8_rdn_sat, 1x2) a = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x2) b = FN(mzero_m, u8_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x2) r = FN(mornot_ew, u8_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_16_179 (void)
{
  TYPE(u8_rod_sat, 2x1) a = FN(mzero_m, u8_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 2x1) b = FN(mzero_m, u8_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 2x1) r = FN(mxor_ew, u8_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_16_180 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(madd_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_181 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(msub_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_182 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mmul_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_183 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mmulneg_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_184 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mabsdiff_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_185 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mhdiff_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_186 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mmean_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_187 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mcmpge_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_188 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mcmplt_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_189 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) b = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mselge_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_190 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(msellt_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_191 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(msll_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_192 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) r = FN(msll_ew_x, i16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_193 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(msrl_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_194 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) r = FN(msrl_ew_x, i16_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_195 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(msra_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_196 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) r = FN(msra_ew_x, i16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_197 (void)
{
  TYPE(i16_rdn_sat, 1x1) old = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mmulacc_ew, i16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_198 (void)
{
  TYPE(i16_rod_sat, 1x1) old = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mmulaccneg_ew, i16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_199 (void)
{
  TYPE(i16_rnu_sat, 1x1) old = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mmuladd_ew, i16_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_200 (void)
{
  TYPE(i16_rne_sat, 1x1) old = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mmulsub_ew, i16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_201 (void)
{
  TYPE(i16_rdn_sat, 1x1) old = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) b = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mcmovge_ew, i16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_202 (void)
{
  TYPE(i16_rod_sat, 1x1) old = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mcmovlt_ew, i16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_203 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mcolgather_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_204 (void)
{
  TYPE(i16_rne_sat, 1x1) a = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mrowgather_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_205 (void)
{
  TYPE(i16_rdn_sat, 1x1) old = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_206 (void)
{
  TYPE(i16_rod_sat, 1x1) old = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mrowscatadd_ew, i16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_207 (void)
{
  TYPE(i16_rnu_sat, 1x1) old = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i16_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_208 (void)
{
  TYPE(i16_rne_sat, 1x1) old = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mrowscatmax_ew, i16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_209 (void)
{
  TYPE(i16_rdn_sat, 1x1) a = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) b = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mmin_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_210 (void)
{
  TYPE(i16_rod_sat, 1x1) a = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mmax_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_211 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 1x1) b = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mand_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_212 (void)
{
  TYPE(i16_rne_sat, 1x1) a = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) b = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x1) r = FN(mandnot_ew, i16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_213 (void)
{
  TYPE(i16_rdn_sat, 1x1) a = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) b = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 1x1) r = FN(mor_ew, i16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_214 (void)
{
  TYPE(i16_rod_sat, 1x1) a = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x1) r = FN(mornot_ew, i16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_215 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 1x1) b = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x1) r = FN(mxor_ew, i16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_216 (void)
{
  TYPE(i16_rne_sat, 1x1) a = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_217 (void)
{
  TYPE(i16_rdn_sat, 1x1) a = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i16_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_218 (void)
{
  TYPE(i16_rod_sat, 1x1) a = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) b = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x2) pair = FN(mconcat_m, i16_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i16_rod_sat, 1x2) (pair);
  a = FN(mextract, i16_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i16_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_219 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 1x1) b = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x2) pair = FN(mconcat_m, i16_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i16_rnu_sat, 1x2) (pair);
  a = FN(mextract, i16_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i16_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_220 (void)
{
  TYPE(i16_rne_sat, 1x1) r = FN(mcolid_ew, i16_rne_sat, 1x1) ();
  KEEP(r);
}
void case_16_221 (void)
{
  TYPE(i16_rdn_sat, 1x1) a = FN(mzero_m, i16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i16_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_222 (void)
{
  TYPE(i16_rod_sat, 1x1) a = FN(mzero_m, i16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x1) r = FN(mrowshift_ew_x, i16_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_223 (void)
{
  TYPE(i16_rnu_sat, 1x1) a = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 1x1) b = FN(mzero_m, i16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 1x2) pair = FN(mconcat_m, i16_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i16_rnu_sat, 1x2) (pair);
  a = FN(mextract, i16_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i16_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_224 (void)
{
  TYPE(i16_rne_sat, 1x1) a = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x1) b = FN(mzero_m, i16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x2) pair = FN(mconcat_m, i16_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i16_rne_sat, 1x2) (pair);
  a = FN(mextract, i16_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i16_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_225 (void)
{
  TYPE(i16_rdn_sat, 1x1) r = FN(mrowid_ew, i16_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_16_226 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(madd_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_227 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(msub_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_228 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mmul_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_229 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mmulneg_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_230 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mabsdiff_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_231 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mhdiff_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_232 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mmean_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_233 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mcmpge_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_234 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mcmplt_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_235 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) b = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mselge_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_236 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(msellt_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_237 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(msll_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_238 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) r = FN(msll_ew_x, u16_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_239 (void)
{
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(msrl_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_240 (void)
{
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) r = FN(msrl_ew_x, u16_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_241 (void)
{
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(msra_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_242 (void)
{
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) r = FN(msra_ew_x, u16_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_243 (void)
{
  TYPE(u16_rne_sat, 1x1) old = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mmulacc_ew, u16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_244 (void)
{
  TYPE(u16_rdn_sat, 1x1) old = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_245 (void)
{
  TYPE(u16_rod_sat, 1x1) old = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mmuladd_ew, u16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_246 (void)
{
  TYPE(u16_rnu_sat, 1x1) old = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mmulsub_ew, u16_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_247 (void)
{
  TYPE(u16_rne_sat, 1x1) old = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) b = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mcmovge_ew, u16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_248 (void)
{
  TYPE(u16_rdn_sat, 1x1) old = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mcmovlt_ew, u16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_249 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mcolgather_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_250 (void)
{
  TYPE(u16_rnu_sat, 1x1) a = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mrowgather_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_251 (void)
{
  TYPE(u16_rne_sat, 1x1) old = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 1x1) a = FN(mzero_m, i16_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod, 1x1) b = FN(mzero_m, u16_rod, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mcolscatadd_ew, u16_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_252 (void)
{
  TYPE(u16_rdn_sat, 1x1) old = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rod, 1x1) a = FN(mzero_m, i16_rod, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x1) b = FN(mzero_m, u16_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u16_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_253 (void)
{
  TYPE(u16_rod_sat, 1x1) old = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 1x1) a = FN(mzero_m, i16_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne, 1x1) b = FN(mzero_m, u16_rne, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mcolscatmax_ew, u16_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_254 (void)
{
  TYPE(u16_rnu_sat, 1x1) old = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i16_rne, 1x1) a = FN(mzero_m, i16_rne, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x1) b = FN(mzero_m, u16_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u16_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_255 (void)
{
  TYPE(u16_rne_sat, 1x1) a = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) b = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mmin_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_256 (void)
{
  TYPE(u16_rdn_sat, 1x1) a = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mmax_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_257 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 1x1) b = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mand_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_258 (void)
{
  TYPE(u16_rnu_sat, 1x1) a = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) b = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x1) r = FN(mandnot_ew, u16_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_259 (void)
{
  TYPE(u16_rne_sat, 1x1) a = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) b = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 1x1) r = FN(mor_ew, u16_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_260 (void)
{
  TYPE(u16_rdn_sat, 1x1) a = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x1) r = FN(mornot_ew, u16_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_261 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 1x1) b = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x1) r = FN(mxor_ew, u16_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_262 (void)
{
  TYPE(u16_rnu_sat, 1x1) a = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u16_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_263 (void)
{
  TYPE(u16_rne_sat, 1x1) a = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) r = FN(mcolshift_ew_x, u16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_264 (void)
{
  TYPE(u16_rdn_sat, 1x1) a = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) b = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x2) pair = FN(mconcat_m, u16_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u16_rdn_sat, 1x2) (pair);
  a = FN(mextract, u16_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u16_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_265 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 1x1) b = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x2) pair = FN(mconcat_m, u16_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u16_rod_sat, 1x2) (pair);
  a = FN(mextract, u16_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u16_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_266 (void)
{
  TYPE(u16_rnu_sat, 1x1) r = FN(mcolid_ew, u16_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_16_267 (void)
{
  TYPE(u16_rne_sat, 1x1) a = FN(mzero_m, u16_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u16_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_268 (void)
{
  TYPE(u16_rdn_sat, 1x1) a = FN(mzero_m, u16_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u16_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_269 (void)
{
  TYPE(u16_rod_sat, 1x1) a = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 1x1) b = FN(mzero_m, u16_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 1x2) pair = FN(mconcat_m, u16_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u16_rod_sat, 1x2) (pair);
  a = FN(mextract, u16_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u16_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_270 (void)
{
  TYPE(u16_rnu_sat, 1x1) a = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x1) b = FN(mzero_m, u16_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x2) pair = FN(mconcat_m, u16_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u16_rnu_sat, 1x2) (pair);
  a = FN(mextract, u16_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u16_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_271 (void)
{
  TYPE(u16_rne_sat, 1x1) r = FN(mrowid_ew, u16_rne_sat, 1x1) ();
  KEEP(r);
}
void case_16_272 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(madd_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_273 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(msub_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_274 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmul_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_275 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mmulneg_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_276 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mabsdiff_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_277 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mhdiff_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_278 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmean_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_279 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mcmpge_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_280 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mcmplt_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_281 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mselge_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_282 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(msellt_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_283 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(msll_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_284 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) r = FN(msll_ew_x, i32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_285 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(msrl_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_286 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) r = FN(msrl_ew_x, i32_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_287 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(msra_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_288 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) r = FN(msra_ew_x, i32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_289 (void)
{
  TYPE(i32_rdn_sat, 1x1) old = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mmulacc_ew, i32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_290 (void)
{
  TYPE(i32_rod_sat, 1x1) old = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmulaccneg_ew, i32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_291 (void)
{
  TYPE(i32_rnu_sat, 1x1) old = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mmuladd_ew, i32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_292 (void)
{
  TYPE(i32_rne_sat, 1x1) old = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mmulsub_ew, i32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_293 (void)
{
  TYPE(i32_rdn_sat, 1x1) old = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mcmovge_ew, i32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_294 (void)
{
  TYPE(i32_rod_sat, 1x1) old = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mcmovlt_ew, i32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_295 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mcolgather_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_296 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mrowgather_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_297 (void)
{
  TYPE(i32_rdn_sat, 1x1) old = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_298 (void)
{
  TYPE(i32_rod_sat, 1x1) old = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mrowscatadd_ew, i32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_299 (void)
{
  TYPE(i32_rnu_sat, 1x1) old = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_300 (void)
{
  TYPE(i32_rne_sat, 1x1) old = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mrowscatmax_ew, i32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_301 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mmin_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_302 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmax_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_303 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mand_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_304 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) b = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mandnot_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_305 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mor_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_306 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mornot_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_307 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mxor_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_308 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_309 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_310 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) pair = FN(mconcat_m, i32_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i32_rod_sat, 1x2) (pair);
  a = FN(mextract, i32_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_311 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x2) pair = FN(mconcat_m, i32_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i32_rnu_sat, 1x2) (pair);
  a = FN(mextract, i32_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_312 (void)
{
  TYPE(i32_rne_sat, 1x1) r = FN(mcolid_ew, i32_rne_sat, 1x1) ();
  KEEP(r);
}
void case_16_313 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_314 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) r = FN(mrowshift_ew_x, i32_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_315 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x2) pair = FN(mconcat_m, i32_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i32_rnu_sat, 1x2) (pair);
  a = FN(mextract, i32_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_316 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) b = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x2) pair = FN(mconcat_m, i32_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i32_rne_sat, 1x2) (pair);
  a = FN(mextract, i32_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_317 (void)
{
  TYPE(i32_rdn_sat, 1x1) r = FN(mrowid_ew, i32_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_16_318 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(madd_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_319 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(msub_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_320 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmul_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_321 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mmulneg_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_322 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mabsdiff_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_323 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mhdiff_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_324 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmean_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_325 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mcmpge_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_326 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mcmplt_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_327 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mselge_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_328 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(msellt_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_329 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(msll_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_330 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) r = FN(msll_ew_x, u32_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_331 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(msrl_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_332 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) r = FN(msrl_ew_x, u32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_333 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(msra_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_334 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) r = FN(msra_ew_x, u32_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_335 (void)
{
  TYPE(u32_rne_sat, 1x1) old = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mmulacc_ew, u32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_336 (void)
{
  TYPE(u32_rdn_sat, 1x1) old = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_337 (void)
{
  TYPE(u32_rod_sat, 1x1) old = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mmuladd_ew, u32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_338 (void)
{
  TYPE(u32_rnu_sat, 1x1) old = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mmulsub_ew, u32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_339 (void)
{
  TYPE(u32_rne_sat, 1x1) old = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mcmovge_ew, u32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_340 (void)
{
  TYPE(u32_rdn_sat, 1x1) old = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mcmovlt_ew, u32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_341 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mcolgather_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_342 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mrowgather_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_343 (void)
{
  TYPE(u32_rne_sat, 1x1) old = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mcolscatadd_ew, u32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_344 (void)
{
  TYPE(u32_rdn_sat, 1x1) old = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_345 (void)
{
  TYPE(u32_rod_sat, 1x1) old = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mcolscatmax_ew, u32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_346 (void)
{
  TYPE(u32_rnu_sat, 1x1) old = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_347 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mmin_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_348 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmax_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_349 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mand_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_350 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) b = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mandnot_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_351 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mor_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_352 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mornot_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_353 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mxor_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_354 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u32_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_355 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) r = FN(mcolshift_ew_x, u32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_356 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) pair = FN(mconcat_m, u32_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u32_rdn_sat, 1x2) (pair);
  a = FN(mextract, u32_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_357 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x2) pair = FN(mconcat_m, u32_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u32_rod_sat, 1x2) (pair);
  a = FN(mextract, u32_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_358 (void)
{
  TYPE(u32_rnu_sat, 1x1) r = FN(mcolid_ew, u32_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_16_359 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_360 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_361 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x2) pair = FN(mconcat_m, u32_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u32_rod_sat, 1x2) (pair);
  a = FN(mextract, u32_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_362 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) b = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x2) pair = FN(mconcat_m, u32_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u32_rnu_sat, 1x2) (pair);
  a = FN(mextract, u32_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_363 (void)
{
  TYPE(u32_rne_sat, 1x1) r = FN(mrowid_ew, u32_rne_sat, 1x1) ();
  KEEP(r);
}
void case_16_364 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(madd_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_365 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(msub_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_366 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmul_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_367 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mmulneg_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_368 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mabsdiff_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_369 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mhdiff_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_370 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmean_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_371 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mcmpge_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_372 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mcmplt_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_373 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mselge_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_374 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(msellt_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_375 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(msll_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_376 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) r = FN(msll_ew_x, i64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_377 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(msrl_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_378 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) r = FN(msrl_ew_x, i64_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_379 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(msra_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_380 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) r = FN(msra_ew_x, i64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_381 (void)
{
  TYPE(i64_rdn_sat, 1x1) old = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mmulacc_ew, i64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_382 (void)
{
  TYPE(i64_rod_sat, 1x1) old = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmulaccneg_ew, i64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_383 (void)
{
  TYPE(i64_rnu_sat, 1x1) old = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mmuladd_ew, i64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_384 (void)
{
  TYPE(i64_rne_sat, 1x1) old = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mmulsub_ew, i64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_385 (void)
{
  TYPE(i64_rdn_sat, 1x1) old = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mcmovge_ew, i64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_386 (void)
{
  TYPE(i64_rod_sat, 1x1) old = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mcmovlt_ew, i64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_387 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mcolgather_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_388 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mrowgather_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_389 (void)
{
  TYPE(i64_rdn_sat, 1x1) old = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_390 (void)
{
  TYPE(i64_rod_sat, 1x1) old = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mrowscatadd_ew, i64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_391 (void)
{
  TYPE(i64_rnu_sat, 1x1) old = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_392 (void)
{
  TYPE(i64_rne_sat, 1x1) old = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mrowscatmax_ew, i64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_393 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mmin_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_394 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmax_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_395 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mand_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_396 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) b = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mandnot_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_397 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mor_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_398 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mornot_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_399 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mxor_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_400 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_401 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_402 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) pair = FN(mconcat_m, i64_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i64_rod_sat, 1x2) (pair);
  a = FN(mextract, i64_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_403 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x2) pair = FN(mconcat_m, i64_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i64_rnu_sat, 1x2) (pair);
  a = FN(mextract, i64_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_404 (void)
{
  TYPE(i64_rne_sat, 1x1) r = FN(mcolid_ew, i64_rne_sat, 1x1) ();
  KEEP(r);
}
void case_16_405 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_406 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) r = FN(mrowshift_ew_x, i64_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_407 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x2) pair = FN(mconcat_m, i64_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i64_rnu_sat, 1x2) (pair);
  a = FN(mextract, i64_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_408 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) b = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x2) pair = FN(mconcat_m, i64_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i64_rne_sat, 1x2) (pair);
  a = FN(mextract, i64_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_409 (void)
{
  TYPE(i64_rdn_sat, 1x1) r = FN(mrowid_ew, i64_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_16_410 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(madd_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_411 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(msub_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_412 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmul_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_413 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mmulneg_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_414 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mabsdiff_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_415 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mhdiff_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_416 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmean_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_417 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mcmpge_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_418 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mcmplt_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_419 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mselge_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_420 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(msellt_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_421 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(msll_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_422 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) r = FN(msll_ew_x, u64_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_423 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(msrl_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_424 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) r = FN(msrl_ew_x, u64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_425 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(msra_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_426 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) r = FN(msra_ew_x, u64_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_427 (void)
{
  TYPE(u64_rne_sat, 1x1) old = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mmulacc_ew, u64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_428 (void)
{
  TYPE(u64_rdn_sat, 1x1) old = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_429 (void)
{
  TYPE(u64_rod_sat, 1x1) old = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mmuladd_ew, u64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_430 (void)
{
  TYPE(u64_rnu_sat, 1x1) old = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mmulsub_ew, u64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_431 (void)
{
  TYPE(u64_rne_sat, 1x1) old = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mcmovge_ew, u64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_432 (void)
{
  TYPE(u64_rdn_sat, 1x1) old = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mcmovlt_ew, u64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_433 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mcolgather_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_434 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mrowgather_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_435 (void)
{
  TYPE(u64_rne_sat, 1x1) old = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mcolscatadd_ew, u64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_436 (void)
{
  TYPE(u64_rdn_sat, 1x1) old = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_437 (void)
{
  TYPE(u64_rod_sat, 1x1) old = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mcolscatmax_ew, u64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_438 (void)
{
  TYPE(u64_rnu_sat, 1x1) old = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_16_439 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mmin_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_440 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmax_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_441 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mand_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_442 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) b = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mandnot_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_443 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mor_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_444 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mornot_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_445 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mxor_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_16_446 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u64_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_447 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) r = FN(mcolshift_ew_x, u64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_448 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) pair = FN(mconcat_m, u64_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u64_rdn_sat, 1x2) (pair);
  a = FN(mextract, u64_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_449 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x2) pair = FN(mconcat_m, u64_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u64_rod_sat, 1x2) (pair);
  a = FN(mextract, u64_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_450 (void)
{
  TYPE(u64_rnu_sat, 1x1) r = FN(mcolid_ew, u64_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_16_451 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_452 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_16_453 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x2) pair = FN(mconcat_m, u64_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u64_rod_sat, 1x2) (pair);
  a = FN(mextract, u64_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_454 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) b = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x2) pair = FN(mconcat_m, u64_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u64_rnu_sat, 1x2) (pair);
  a = FN(mextract, u64_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_16_455 (void)
{
  TYPE(u64_rne_sat, 1x1) r = FN(mrowid_ew, u64_rne_sat, 1x1) ();
  KEEP(r);
}
#endif

#if TEST_UDS == 32
void case_32_0 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne, 1x8) r = FN(madd_ew, i4_rne, 1x8) (a, b);
  KEEP(r);
}
void case_32_1 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 8x1) r = FN(msub_ew, i4_rdn, 8x1) (a, b);
  KEEP(r);
}
void case_32_2 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod, 1x8) r = FN(mmul_ew, i4_rod, 1x8) (a, b);
  KEEP(r);
}
void case_32_3 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 8x1) r = FN(mmulneg_ew, i4_rnu, 8x1) (a, b);
  KEEP(r);
}
void case_32_4 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne, 1x8) r = FN(mabsdiff_ew, i4_rne, 1x8) (a, b);
  KEEP(r);
}
void case_32_5 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 8x1) r = FN(mhdiff_ew, i4_rdn, 8x1) (a, b);
  KEEP(r);
}
void case_32_6 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod, 1x8) r = FN(mmean_ew, i4_rod, 1x8) (a, b);
  KEEP(r);
}
void case_32_7 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 8x1) r = FN(mcmpge_ew, i4_rnu, 8x1) (a, b);
  KEEP(r);
}
void case_32_8 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne, 1x8) r = FN(mcmplt_ew, i4_rne, 1x8) (a, b);
  KEEP(r);
}
void case_32_9 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 8x1) b = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 8x1) r = FN(mselge_ew, i4_rdn, 8x1) (a, b);
  KEEP(r);
}
void case_32_10 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod, 1x8) b = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod, 1x8) r = FN(msellt_ew, i4_rod, 1x8) (a, b);
  KEEP(r);
}
void case_32_11 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 8x1) r = FN(msll_ew, i4_rnu, 8x1) (a, b);
  KEEP(r);
}
void case_32_12 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(i4_rne, 1x8) r = FN(msll_ew_x, i4_rne, 1x8) (a, 1);
  KEEP(r);
}
void case_32_13 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 8x1) r = FN(msrl_ew, i4_rdn, 8x1) (a, b);
  KEEP(r);
}
void case_32_14 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod, 1x8) r = FN(msrl_ew_x, i4_rod, 1x8) (a, 1);
  KEEP(r);
}
void case_32_15 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 8x1) r = FN(msra_ew, i4_rnu, 8x1) (a, b);
  KEEP(r);
}
void case_32_16 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(i4_rne, 1x8) r = FN(msra_ew_x, i4_rne, 1x8) (a, 1);
  KEEP(r);
}
void case_32_17 (void)
{
  TYPE(i4_rdn, 8x1) old = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 8x1) r = FN(mmulacc_ew, i4_rdn, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_18 (void)
{
  TYPE(i4_rod, 1x8) old = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(old);
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod, 1x8) r = FN(mmulaccneg_ew, i4_rod, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_19 (void)
{
  TYPE(i4_rnu, 8x1) old = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 8x1) r = FN(mmuladd_ew, i4_rnu, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_20 (void)
{
  TYPE(i4_rne, 1x8) old = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(old);
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne, 1x8) r = FN(mmulsub_ew, i4_rne, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_21 (void)
{
  TYPE(i4_rdn, 8x1) old = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 8x1) b = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 8x1) r = FN(mcmovge_ew, i4_rdn, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_22 (void)
{
  TYPE(i4_rod, 1x8) old = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(old);
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod, 1x8) b = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod, 1x8) r = FN(mcmovlt_ew, i4_rod, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_23 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 8x1) b = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 8x1) r = FN(mmin_ew, i4_rdn, 8x1) (a, b);
  KEEP(r);
}
void case_32_24 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod, 1x8) b = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod, 1x8) r = FN(mmax_ew, i4_rod, 1x8) (a, b);
  KEEP(r);
}
void case_32_25 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 8x1) b = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 8x1) r = FN(mand_ew, i4_rnu, 8x1) (a, b);
  KEEP(r);
}
void case_32_26 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(i4_rne, 1x8) b = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne, 1x8) r = FN(mandnot_ew, i4_rne, 1x8) (a, b);
  KEEP(r);
}
void case_32_27 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 8x1) b = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 8x1) r = FN(mor_ew, i4_rdn, 8x1) (a, b);
  KEEP(r);
}
void case_32_28 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod, 1x8) b = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod, 1x8) r = FN(mornot_ew, i4_rod, 1x8) (a, b);
  KEEP(r);
}
void case_32_29 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 8x1) b = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 8x1) r = FN(mxor_ew, i4_rnu, 8x1) (a, b);
  KEEP(r);
}
void case_32_30 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x8) r = FN(madd_ew, u4_rnu, 1x8) (a, b);
  KEEP(r);
}
void case_32_31 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne, 8x1) r = FN(msub_ew, u4_rne, 8x1) (a, b);
  KEEP(r);
}
void case_32_32 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x8) r = FN(mmul_ew, u4_rdn, 1x8) (a, b);
  KEEP(r);
}
void case_32_33 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod, 8x1) r = FN(mmulneg_ew, u4_rod, 8x1) (a, b);
  KEEP(r);
}
void case_32_34 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x8) r = FN(mabsdiff_ew, u4_rnu, 1x8) (a, b);
  KEEP(r);
}
void case_32_35 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne, 8x1) r = FN(mhdiff_ew, u4_rne, 8x1) (a, b);
  KEEP(r);
}
void case_32_36 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x8) r = FN(mmean_ew, u4_rdn, 1x8) (a, b);
  KEEP(r);
}
void case_32_37 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod, 8x1) r = FN(mcmpge_ew, u4_rod, 8x1) (a, b);
  KEEP(r);
}
void case_32_38 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x8) r = FN(mcmplt_ew, u4_rnu, 1x8) (a, b);
  KEEP(r);
}
void case_32_39 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne, 8x1) r = FN(mselge_ew, u4_rne, 8x1) (a, b);
  KEEP(r);
}
void case_32_40 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x8) r = FN(msellt_ew, u4_rdn, 1x8) (a, b);
  KEEP(r);
}
void case_32_41 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod, 8x1) r = FN(msll_ew, u4_rod, 8x1) (a, b);
  KEEP(r);
}
void case_32_42 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) r = FN(msll_ew_x, u4_rnu, 1x8) (a, 1);
  KEEP(r);
}
void case_32_43 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne, 8x1) r = FN(msrl_ew, u4_rne, 8x1) (a, b);
  KEEP(r);
}
void case_32_44 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) r = FN(msrl_ew_x, u4_rdn, 1x8) (a, 1);
  KEEP(r);
}
void case_32_45 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod, 8x1) r = FN(msra_ew, u4_rod, 8x1) (a, b);
  KEEP(r);
}
void case_32_46 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) r = FN(msra_ew_x, u4_rnu, 1x8) (a, 1);
  KEEP(r);
}
void case_32_47 (void)
{
  TYPE(u4_rne, 8x1) old = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne, 8x1) r = FN(mmulacc_ew, u4_rne, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_48 (void)
{
  TYPE(u4_rdn, 1x8) old = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(old);
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x8) r = FN(mmulaccneg_ew, u4_rdn, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_49 (void)
{
  TYPE(u4_rod, 8x1) old = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod, 8x1) r = FN(mmuladd_ew, u4_rod, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_50 (void)
{
  TYPE(u4_rnu, 1x8) old = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(old);
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x8) r = FN(mmulsub_ew, u4_rnu, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_51 (void)
{
  TYPE(u4_rne, 8x1) old = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne, 8x1) r = FN(mcmovge_ew, u4_rne, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_52 (void)
{
  TYPE(u4_rdn, 1x8) old = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(old);
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x8) r = FN(mcmovlt_ew, u4_rdn, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_53 (void)
{
  TYPE(u4_rne, 8x1) a = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne, 8x1) r = FN(mmin_ew, u4_rne, 8x1) (a, b);
  KEEP(r);
}
void case_32_54 (void)
{
  TYPE(u4_rdn, 1x8) a = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x8) r = FN(mmax_ew, u4_rdn, 1x8) (a, b);
  KEEP(r);
}
void case_32_55 (void)
{
  TYPE(u4_rod, 8x1) a = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod, 8x1) r = FN(mand_ew, u4_rod, 8x1) (a, b);
  KEEP(r);
}
void case_32_56 (void)
{
  TYPE(u4_rnu, 1x8) a = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x8) r = FN(mandnot_ew, u4_rnu, 1x8) (a, b);
  KEEP(r);
}
void case_32_57 (void)
{
  TYPE(u4_rne, 8x1) a = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne, 8x1) r = FN(mor_ew, u4_rne, 8x1) (a, b);
  KEEP(r);
}
void case_32_58 (void)
{
  TYPE(u4_rdn, 1x8) a = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x8) r = FN(mornot_ew, u4_rdn, 1x8) (a, b);
  KEEP(r);
}
void case_32_59 (void)
{
  TYPE(u4_rod, 8x1) a = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod, 8x1) r = FN(mxor_ew, u4_rod, 8x1) (a, b);
  KEEP(r);
}
void case_32_60 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x8) r = FN(madd_ew, i4_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_61 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 8x1) r = FN(msub_ew, i4_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_62 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x8) r = FN(mmul_ew, i4_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_63 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 8x1) r = FN(mmulneg_ew, i4_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_64 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x8) r = FN(mabsdiff_ew, i4_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_65 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 8x1) r = FN(mhdiff_ew, i4_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_66 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x8) r = FN(mmean_ew, i4_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_67 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 8x1) r = FN(mcmpge_ew, i4_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_68 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x8) r = FN(mcmplt_ew, i4_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_69 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 8x1) b = FN(mzero_m, i4_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 8x1) r = FN(mselge_ew, i4_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_70 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x8) b = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x8) r = FN(msellt_ew, i4_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_71 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 8x1) r = FN(msll_ew, i4_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_72 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x8) r = FN(msll_ew_x, i4_rne_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_32_73 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 8x1) r = FN(msrl_ew, i4_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_74 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x8) r = FN(msrl_ew_x, i4_rod_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_32_75 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 8x1) r = FN(msra_ew, i4_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_76 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x8) r = FN(msra_ew_x, i4_rne_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_32_77 (void)
{
  TYPE(i4_rdn_sat, 8x1) old = FN(mzero_m, i4_rdn_sat, 8x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 8x1) r = FN(mmulacc_ew, i4_rdn_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_78 (void)
{
  TYPE(i4_rod_sat, 1x8) old = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE(old);
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x8) r = FN(mmulaccneg_ew, i4_rod_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_79 (void)
{
  TYPE(i4_rnu_sat, 8x1) old = FN(mzero_m, i4_rnu_sat, 8x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 8x1) r = FN(mmuladd_ew, i4_rnu_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_80 (void)
{
  TYPE(i4_rne_sat, 1x8) old = FN(mzero_m, i4_rne_sat, 1x8) ();
  CHANGE(old);
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x8) r = FN(mmulsub_ew, i4_rne_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_81 (void)
{
  TYPE(i4_rdn_sat, 8x1) old = FN(mzero_m, i4_rdn_sat, 8x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 8x1) b = FN(mzero_m, i4_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 8x1) r = FN(mcmovge_ew, i4_rdn_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_82 (void)
{
  TYPE(i4_rod_sat, 1x8) old = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE(old);
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x8) b = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x8) r = FN(mcmovlt_ew, i4_rod_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_83 (void)
{
  TYPE(i4_rdn_sat, 8x1) a = FN(mzero_m, i4_rdn_sat, 8x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 8x1) b = FN(mzero_m, i4_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 8x1) r = FN(mmin_ew, i4_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_84 (void)
{
  TYPE(i4_rod_sat, 1x8) a = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x8) b = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x8) r = FN(mmax_ew, i4_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_85 (void)
{
  TYPE(i4_rnu_sat, 8x1) a = FN(mzero_m, i4_rnu_sat, 8x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 8x1) b = FN(mzero_m, i4_rnu_sat, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 8x1) r = FN(mand_ew, i4_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_86 (void)
{
  TYPE(i4_rne_sat, 1x8) a = FN(mzero_m, i4_rne_sat, 1x8) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x8) b = FN(mzero_m, i4_rne_sat, 1x8) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x8) r = FN(mandnot_ew, i4_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_87 (void)
{
  TYPE(i4_rdn_sat, 8x1) a = FN(mzero_m, i4_rdn_sat, 8x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 8x1) b = FN(mzero_m, i4_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 8x1) r = FN(mor_ew, i4_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_88 (void)
{
  TYPE(i4_rod_sat, 1x8) a = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x8) b = FN(mzero_m, i4_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x8) r = FN(mornot_ew, i4_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_89 (void)
{
  TYPE(i4_rnu_sat, 8x1) a = FN(mzero_m, i4_rnu_sat, 8x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 8x1) b = FN(mzero_m, i4_rnu_sat, 8x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 8x1) r = FN(mxor_ew, i4_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_90 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x8) r = FN(madd_ew, u4_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_91 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 8x1) r = FN(msub_ew, u4_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_92 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x8) r = FN(mmul_ew, u4_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_93 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 8x1) r = FN(mmulneg_ew, u4_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_94 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x8) r = FN(mabsdiff_ew, u4_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_95 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 8x1) r = FN(mhdiff_ew, u4_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_96 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x8) r = FN(mmean_ew, u4_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_97 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 8x1) r = FN(mcmpge_ew, u4_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_98 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x8) r = FN(mcmplt_ew, u4_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_99 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 8x1) b = FN(mzero_m, u4_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 8x1) r = FN(mselge_ew, u4_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_100 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x8) b = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x8) r = FN(msellt_ew, u4_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_101 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 8x1) r = FN(msll_ew, u4_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_102 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x8) r = FN(msll_ew_x, u4_rnu_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_32_103 (void)
{
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 8x1) r = FN(msrl_ew, u4_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_104 (void)
{
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x8) r = FN(msrl_ew_x, u4_rdn_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_32_105 (void)
{
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 8x1) r = FN(msra_ew, u4_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_106 (void)
{
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x8) r = FN(msra_ew_x, u4_rnu_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_32_107 (void)
{
  TYPE(u4_rne_sat, 8x1) old = FN(mzero_m, u4_rne_sat, 8x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod, 8x1) b = FN(mzero_m, u4_rod, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 8x1) r = FN(mmulacc_ew, u4_rne_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_108 (void)
{
  TYPE(u4_rdn_sat, 1x8) old = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE(old);
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x8) b = FN(mzero_m, u4_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x8) r = FN(mmulaccneg_ew, u4_rdn_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_109 (void)
{
  TYPE(u4_rod_sat, 8x1) old = FN(mzero_m, u4_rod_sat, 8x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 8x1) a = FN(mzero_m, i4_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne, 8x1) b = FN(mzero_m, u4_rne, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 8x1) r = FN(mmuladd_ew, u4_rod_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_110 (void)
{
  TYPE(u4_rnu_sat, 1x8) old = FN(mzero_m, u4_rnu_sat, 1x8) ();
  CHANGE(old);
  TYPE(i4_rne, 1x8) a = FN(mzero_m, i4_rne, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x8) b = FN(mzero_m, u4_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x8) r = FN(mmulsub_ew, u4_rnu_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_111 (void)
{
  TYPE(u4_rne_sat, 8x1) old = FN(mzero_m, u4_rne_sat, 8x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 8x1) a = FN(mzero_m, i4_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 8x1) b = FN(mzero_m, u4_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 8x1) r = FN(mcmovge_ew, u4_rne_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_32_112 (void)
{
  TYPE(u4_rdn_sat, 1x8) old = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE(old);
  TYPE(i4_rod, 1x8) a = FN(mzero_m, i4_rod, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x8) b = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x8) r = FN(mcmovlt_ew, u4_rdn_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_32_113 (void)
{
  TYPE(u4_rne_sat, 8x1) a = FN(mzero_m, u4_rne_sat, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 8x1) b = FN(mzero_m, u4_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 8x1) r = FN(mmin_ew, u4_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_114 (void)
{
  TYPE(u4_rdn_sat, 1x8) a = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x8) b = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x8) r = FN(mmax_ew, u4_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_115 (void)
{
  TYPE(u4_rod_sat, 8x1) a = FN(mzero_m, u4_rod_sat, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 8x1) b = FN(mzero_m, u4_rod_sat, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 8x1) r = FN(mand_ew, u4_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_116 (void)
{
  TYPE(u4_rnu_sat, 1x8) a = FN(mzero_m, u4_rnu_sat, 1x8) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x8) b = FN(mzero_m, u4_rnu_sat, 1x8) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x8) r = FN(mandnot_ew, u4_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_117 (void)
{
  TYPE(u4_rne_sat, 8x1) a = FN(mzero_m, u4_rne_sat, 8x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 8x1) b = FN(mzero_m, u4_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 8x1) r = FN(mor_ew, u4_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_118 (void)
{
  TYPE(u4_rdn_sat, 1x8) a = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x8) b = FN(mzero_m, u4_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x8) r = FN(mornot_ew, u4_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_32_119 (void)
{
  TYPE(u4_rod_sat, 8x1) a = FN(mzero_m, u4_rod_sat, 8x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 8x1) b = FN(mzero_m, u4_rod_sat, 8x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 8x1) r = FN(mxor_ew, u4_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_32_120 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x4) b = FN(mzero_m, u8_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x4) r = FN(madd_ew, i8_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_121 (void)
{
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod, 4x1) b = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 4x1) r = FN(msub_ew, i8_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_122 (void)
{
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x4) b = FN(mzero_m, u8_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x4) r = FN(mmul_ew, i8_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_123 (void)
{
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 4x1) r = FN(mmulneg_ew, i8_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_124 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x4) b = FN(mzero_m, u8_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x4) r = FN(mabsdiff_ew, i8_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_125 (void)
{
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod, 4x1) b = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 4x1) r = FN(mhdiff_ew, i8_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_126 (void)
{
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x4) b = FN(mzero_m, u8_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x4) r = FN(mmean_ew, i8_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_127 (void)
{
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 4x1) r = FN(mcmpge_ew, i8_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_128 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x4) b = FN(mzero_m, u8_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x4) r = FN(mcmplt_ew, i8_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_129 (void)
{
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 4x1) b = FN(mzero_m, i8_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 4x1) r = FN(mselge_ew, i8_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_130 (void)
{
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x4) b = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x4) r = FN(msellt_ew, i8_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_131 (void)
{
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 4x1) r = FN(msll_ew, i8_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_132 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x4) r = FN(msll_ew_x, i8_rne_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_32_133 (void)
{
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod, 4x1) b = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 4x1) r = FN(msrl_ew, i8_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_134 (void)
{
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x4) r = FN(msrl_ew_x, i8_rod_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_32_135 (void)
{
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 4x1) r = FN(msra_ew, i8_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_136 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x4) r = FN(msra_ew_x, i8_rne_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_32_137 (void)
{
  TYPE(i8_rdn_sat, 4x1) old = FN(mzero_m, i8_rdn_sat, 4x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod, 4x1) b = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 4x1) r = FN(mmulacc_ew, i8_rdn_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_32_138 (void)
{
  TYPE(i8_rod_sat, 1x4) old = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE(old);
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x4) b = FN(mzero_m, u8_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x4) r = FN(mmulaccneg_ew, i8_rod_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_32_139 (void)
{
  TYPE(i8_rnu_sat, 4x1) old = FN(mzero_m, i8_rnu_sat, 4x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 4x1) r = FN(mmuladd_ew, i8_rnu_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_32_140 (void)
{
  TYPE(i8_rne_sat, 1x4) old = FN(mzero_m, i8_rne_sat, 1x4) ();
  CHANGE(old);
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x4) b = FN(mzero_m, u8_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x4) r = FN(mmulsub_ew, i8_rne_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_32_141 (void)
{
  TYPE(i8_rdn_sat, 4x1) old = FN(mzero_m, i8_rdn_sat, 4x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 4x1) b = FN(mzero_m, i8_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 4x1) r = FN(mcmovge_ew, i8_rdn_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_32_142 (void)
{
  TYPE(i8_rod_sat, 1x4) old = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE(old);
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x4) b = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x4) r = FN(mcmovlt_ew, i8_rod_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_32_143 (void)
{
  TYPE(i8_rdn_sat, 4x1) a = FN(mzero_m, i8_rdn_sat, 4x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 4x1) b = FN(mzero_m, i8_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 4x1) r = FN(mmin_ew, i8_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_144 (void)
{
  TYPE(i8_rod_sat, 1x4) a = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x4) b = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x4) r = FN(mmax_ew, i8_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_145 (void)
{
  TYPE(i8_rnu_sat, 4x1) a = FN(mzero_m, i8_rnu_sat, 4x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 4x1) b = FN(mzero_m, i8_rnu_sat, 4x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 4x1) r = FN(mand_ew, i8_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_146 (void)
{
  TYPE(i8_rne_sat, 1x4) a = FN(mzero_m, i8_rne_sat, 1x4) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x4) b = FN(mzero_m, i8_rne_sat, 1x4) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x4) r = FN(mandnot_ew, i8_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_147 (void)
{
  TYPE(i8_rdn_sat, 4x1) a = FN(mzero_m, i8_rdn_sat, 4x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 4x1) b = FN(mzero_m, i8_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 4x1) r = FN(mor_ew, i8_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_148 (void)
{
  TYPE(i8_rod_sat, 1x4) a = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x4) b = FN(mzero_m, i8_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x4) r = FN(mornot_ew, i8_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_149 (void)
{
  TYPE(i8_rnu_sat, 4x1) a = FN(mzero_m, i8_rnu_sat, 4x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 4x1) b = FN(mzero_m, i8_rnu_sat, 4x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 4x1) r = FN(mxor_ew, i8_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_150 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x4) b = FN(mzero_m, u8_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x4) r = FN(madd_ew, u8_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_151 (void)
{
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod, 4x1) b = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 4x1) r = FN(msub_ew, u8_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_152 (void)
{
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x4) b = FN(mzero_m, u8_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x4) r = FN(mmul_ew, u8_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_153 (void)
{
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 4x1) r = FN(mmulneg_ew, u8_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_154 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x4) b = FN(mzero_m, u8_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x4) r = FN(mabsdiff_ew, u8_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_155 (void)
{
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod, 4x1) b = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 4x1) r = FN(mhdiff_ew, u8_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_156 (void)
{
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x4) b = FN(mzero_m, u8_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x4) r = FN(mmean_ew, u8_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_157 (void)
{
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 4x1) r = FN(mcmpge_ew, u8_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_158 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x4) b = FN(mzero_m, u8_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x4) r = FN(mcmplt_ew, u8_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_159 (void)
{
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 4x1) b = FN(mzero_m, u8_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 4x1) r = FN(mselge_ew, u8_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_160 (void)
{
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x4) b = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x4) r = FN(msellt_ew, u8_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_161 (void)
{
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 4x1) r = FN(msll_ew, u8_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_162 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x4) r = FN(msll_ew_x, u8_rnu_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_32_163 (void)
{
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod, 4x1) b = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 4x1) r = FN(msrl_ew, u8_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_164 (void)
{
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x4) r = FN(msrl_ew_x, u8_rdn_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_32_165 (void)
{
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 4x1) r = FN(msra_ew, u8_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_166 (void)
{
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x4) r = FN(msra_ew_x, u8_rnu_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_32_167 (void)
{
  TYPE(u8_rne_sat, 4x1) old = FN(mzero_m, u8_rne_sat, 4x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod, 4x1) b = FN(mzero_m, u8_rod, 4x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 4x1) r = FN(mmulacc_ew, u8_rne_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_32_168 (void)
{
  TYPE(u8_rdn_sat, 1x4) old = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE(old);
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x4) b = FN(mzero_m, u8_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x4) r = FN(mmulaccneg_ew, u8_rdn_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_32_169 (void)
{
  TYPE(u8_rod_sat, 4x1) old = FN(mzero_m, u8_rod_sat, 4x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 4x1) a = FN(mzero_m, i8_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne, 4x1) b = FN(mzero_m, u8_rne, 4x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 4x1) r = FN(mmuladd_ew, u8_rod_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_32_170 (void)
{
  TYPE(u8_rnu_sat, 1x4) old = FN(mzero_m, u8_rnu_sat, 1x4) ();
  CHANGE(old);
  TYPE(i8_rne, 1x4) a = FN(mzero_m, i8_rne, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x4) b = FN(mzero_m, u8_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x4) r = FN(mmulsub_ew, u8_rnu_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_32_171 (void)
{
  TYPE(u8_rne_sat, 4x1) old = FN(mzero_m, u8_rne_sat, 4x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 4x1) a = FN(mzero_m, i8_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 4x1) b = FN(mzero_m, u8_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 4x1) r = FN(mcmovge_ew, u8_rne_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_32_172 (void)
{
  TYPE(u8_rdn_sat, 1x4) old = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE(old);
  TYPE(i8_rod, 1x4) a = FN(mzero_m, i8_rod, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x4) b = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x4) r = FN(mcmovlt_ew, u8_rdn_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_32_173 (void)
{
  TYPE(u8_rne_sat, 4x1) a = FN(mzero_m, u8_rne_sat, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 4x1) b = FN(mzero_m, u8_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 4x1) r = FN(mmin_ew, u8_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_174 (void)
{
  TYPE(u8_rdn_sat, 1x4) a = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x4) b = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x4) r = FN(mmax_ew, u8_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_175 (void)
{
  TYPE(u8_rod_sat, 4x1) a = FN(mzero_m, u8_rod_sat, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 4x1) b = FN(mzero_m, u8_rod_sat, 4x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 4x1) r = FN(mand_ew, u8_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_176 (void)
{
  TYPE(u8_rnu_sat, 1x4) a = FN(mzero_m, u8_rnu_sat, 1x4) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x4) b = FN(mzero_m, u8_rnu_sat, 1x4) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x4) r = FN(mandnot_ew, u8_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_177 (void)
{
  TYPE(u8_rne_sat, 4x1) a = FN(mzero_m, u8_rne_sat, 4x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 4x1) b = FN(mzero_m, u8_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 4x1) r = FN(mor_ew, u8_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_178 (void)
{
  TYPE(u8_rdn_sat, 1x4) a = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x4) b = FN(mzero_m, u8_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x4) r = FN(mornot_ew, u8_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_32_179 (void)
{
  TYPE(u8_rod_sat, 4x1) a = FN(mzero_m, u8_rod_sat, 4x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 4x1) b = FN(mzero_m, u8_rod_sat, 4x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 4x1) r = FN(mxor_ew, u8_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_32_180 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x2) b = FN(mzero_m, u16_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x2) r = FN(madd_ew, i16_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_181 (void)
{
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod, 2x1) b = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 2x1) r = FN(msub_ew, i16_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_182 (void)
{
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x2) b = FN(mzero_m, u16_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x2) r = FN(mmul_ew, i16_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_183 (void)
{
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 2x1) r = FN(mmulneg_ew, i16_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_184 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x2) b = FN(mzero_m, u16_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x2) r = FN(mabsdiff_ew, i16_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_185 (void)
{
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod, 2x1) b = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 2x1) r = FN(mhdiff_ew, i16_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_186 (void)
{
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x2) b = FN(mzero_m, u16_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x2) r = FN(mmean_ew, i16_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_187 (void)
{
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 2x1) r = FN(mcmpge_ew, i16_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_188 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x2) b = FN(mzero_m, u16_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x2) r = FN(mcmplt_ew, i16_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_189 (void)
{
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 2x1) b = FN(mzero_m, i16_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 2x1) r = FN(mselge_ew, i16_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_190 (void)
{
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x2) b = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x2) r = FN(msellt_ew, i16_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_191 (void)
{
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 2x1) r = FN(msll_ew, i16_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_192 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x2) r = FN(msll_ew_x, i16_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_32_193 (void)
{
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod, 2x1) b = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 2x1) r = FN(msrl_ew, i16_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_194 (void)
{
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x2) r = FN(msrl_ew_x, i16_rod_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_32_195 (void)
{
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 2x1) r = FN(msra_ew, i16_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_196 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x2) r = FN(msra_ew_x, i16_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_32_197 (void)
{
  TYPE(i16_rdn_sat, 2x1) old = FN(mzero_m, i16_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod, 2x1) b = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 2x1) r = FN(mmulacc_ew, i16_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_32_198 (void)
{
  TYPE(i16_rod_sat, 1x2) old = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x2) b = FN(mzero_m, u16_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x2) r = FN(mmulaccneg_ew, i16_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_32_199 (void)
{
  TYPE(i16_rnu_sat, 2x1) old = FN(mzero_m, i16_rnu_sat, 2x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 2x1) r = FN(mmuladd_ew, i16_rnu_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_32_200 (void)
{
  TYPE(i16_rne_sat, 1x2) old = FN(mzero_m, i16_rne_sat, 1x2) ();
  CHANGE(old);
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x2) b = FN(mzero_m, u16_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x2) r = FN(mmulsub_ew, i16_rne_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_32_201 (void)
{
  TYPE(i16_rdn_sat, 2x1) old = FN(mzero_m, i16_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 2x1) b = FN(mzero_m, i16_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 2x1) r = FN(mcmovge_ew, i16_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_32_202 (void)
{
  TYPE(i16_rod_sat, 1x2) old = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x2) b = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x2) r = FN(mcmovlt_ew, i16_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_32_203 (void)
{
  TYPE(i16_rdn_sat, 2x1) a = FN(mzero_m, i16_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 2x1) b = FN(mzero_m, i16_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 2x1) r = FN(mmin_ew, i16_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_204 (void)
{
  TYPE(i16_rod_sat, 1x2) a = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x2) b = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x2) r = FN(mmax_ew, i16_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_205 (void)
{
  TYPE(i16_rnu_sat, 2x1) a = FN(mzero_m, i16_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 2x1) b = FN(mzero_m, i16_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 2x1) r = FN(mand_ew, i16_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_206 (void)
{
  TYPE(i16_rne_sat, 1x2) a = FN(mzero_m, i16_rne_sat, 1x2) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x2) b = FN(mzero_m, i16_rne_sat, 1x2) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x2) r = FN(mandnot_ew, i16_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_207 (void)
{
  TYPE(i16_rdn_sat, 2x1) a = FN(mzero_m, i16_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 2x1) b = FN(mzero_m, i16_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 2x1) r = FN(mor_ew, i16_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_208 (void)
{
  TYPE(i16_rod_sat, 1x2) a = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x2) b = FN(mzero_m, i16_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x2) r = FN(mornot_ew, i16_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_209 (void)
{
  TYPE(i16_rnu_sat, 2x1) a = FN(mzero_m, i16_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 2x1) b = FN(mzero_m, i16_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 2x1) r = FN(mxor_ew, i16_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_210 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x2) b = FN(mzero_m, u16_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x2) r = FN(madd_ew, u16_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_211 (void)
{
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod, 2x1) b = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 2x1) r = FN(msub_ew, u16_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_212 (void)
{
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x2) b = FN(mzero_m, u16_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x2) r = FN(mmul_ew, u16_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_213 (void)
{
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 2x1) r = FN(mmulneg_ew, u16_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_214 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x2) b = FN(mzero_m, u16_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x2) r = FN(mabsdiff_ew, u16_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_215 (void)
{
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod, 2x1) b = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 2x1) r = FN(mhdiff_ew, u16_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_216 (void)
{
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x2) b = FN(mzero_m, u16_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x2) r = FN(mmean_ew, u16_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_217 (void)
{
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 2x1) r = FN(mcmpge_ew, u16_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_218 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x2) b = FN(mzero_m, u16_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x2) r = FN(mcmplt_ew, u16_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_219 (void)
{
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 2x1) b = FN(mzero_m, u16_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 2x1) r = FN(mselge_ew, u16_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_220 (void)
{
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x2) b = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x2) r = FN(msellt_ew, u16_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_221 (void)
{
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 2x1) r = FN(msll_ew, u16_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_222 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x2) r = FN(msll_ew_x, u16_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_32_223 (void)
{
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod, 2x1) b = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 2x1) r = FN(msrl_ew, u16_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_224 (void)
{
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x2) r = FN(msrl_ew_x, u16_rdn_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_32_225 (void)
{
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 2x1) r = FN(msra_ew, u16_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_226 (void)
{
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x2) r = FN(msra_ew_x, u16_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_32_227 (void)
{
  TYPE(u16_rne_sat, 2x1) old = FN(mzero_m, u16_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod, 2x1) b = FN(mzero_m, u16_rod, 2x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 2x1) r = FN(mmulacc_ew, u16_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_32_228 (void)
{
  TYPE(u16_rdn_sat, 1x2) old = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x2) b = FN(mzero_m, u16_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x2) r = FN(mmulaccneg_ew, u16_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_32_229 (void)
{
  TYPE(u16_rod_sat, 2x1) old = FN(mzero_m, u16_rod_sat, 2x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 2x1) a = FN(mzero_m, i16_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne, 2x1) b = FN(mzero_m, u16_rne, 2x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 2x1) r = FN(mmuladd_ew, u16_rod_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_32_230 (void)
{
  TYPE(u16_rnu_sat, 1x2) old = FN(mzero_m, u16_rnu_sat, 1x2) ();
  CHANGE(old);
  TYPE(i16_rne, 1x2) a = FN(mzero_m, i16_rne, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x2) b = FN(mzero_m, u16_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x2) r = FN(mmulsub_ew, u16_rnu_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_32_231 (void)
{
  TYPE(u16_rne_sat, 2x1) old = FN(mzero_m, u16_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 2x1) a = FN(mzero_m, i16_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 2x1) b = FN(mzero_m, u16_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 2x1) r = FN(mcmovge_ew, u16_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_32_232 (void)
{
  TYPE(u16_rdn_sat, 1x2) old = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i16_rod, 1x2) a = FN(mzero_m, i16_rod, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x2) b = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x2) r = FN(mcmovlt_ew, u16_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_32_233 (void)
{
  TYPE(u16_rne_sat, 2x1) a = FN(mzero_m, u16_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 2x1) b = FN(mzero_m, u16_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 2x1) r = FN(mmin_ew, u16_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_234 (void)
{
  TYPE(u16_rdn_sat, 1x2) a = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x2) b = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x2) r = FN(mmax_ew, u16_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_235 (void)
{
  TYPE(u16_rod_sat, 2x1) a = FN(mzero_m, u16_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 2x1) b = FN(mzero_m, u16_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 2x1) r = FN(mand_ew, u16_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_236 (void)
{
  TYPE(u16_rnu_sat, 1x2) a = FN(mzero_m, u16_rnu_sat, 1x2) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x2) b = FN(mzero_m, u16_rnu_sat, 1x2) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x2) r = FN(mandnot_ew, u16_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_237 (void)
{
  TYPE(u16_rne_sat, 2x1) a = FN(mzero_m, u16_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 2x1) b = FN(mzero_m, u16_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 2x1) r = FN(mor_ew, u16_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_238 (void)
{
  TYPE(u16_rdn_sat, 1x2) a = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x2) b = FN(mzero_m, u16_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x2) r = FN(mornot_ew, u16_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_32_239 (void)
{
  TYPE(u16_rod_sat, 2x1) a = FN(mzero_m, u16_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 2x1) b = FN(mzero_m, u16_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 2x1) r = FN(mxor_ew, u16_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_32_240 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(madd_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_241 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(msub_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_242 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmul_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_243 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mmulneg_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_244 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mabsdiff_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_245 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mhdiff_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_246 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmean_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_247 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mcmpge_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_248 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mcmplt_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_249 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mselge_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_250 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(msellt_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_251 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(msll_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_252 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) r = FN(msll_ew_x, i32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_253 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(msrl_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_254 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) r = FN(msrl_ew_x, i32_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_255 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(msra_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_256 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) r = FN(msra_ew_x, i32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_257 (void)
{
  TYPE(i32_rdn_sat, 1x1) old = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mmulacc_ew, i32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_258 (void)
{
  TYPE(i32_rod_sat, 1x1) old = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmulaccneg_ew, i32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_259 (void)
{
  TYPE(i32_rnu_sat, 1x1) old = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mmuladd_ew, i32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_260 (void)
{
  TYPE(i32_rne_sat, 1x1) old = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mmulsub_ew, i32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_261 (void)
{
  TYPE(i32_rdn_sat, 1x1) old = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mcmovge_ew, i32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_262 (void)
{
  TYPE(i32_rod_sat, 1x1) old = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mcmovlt_ew, i32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_263 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mcolgather_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_264 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mrowgather_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_265 (void)
{
  TYPE(i32_rdn_sat, 1x1) old = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_266 (void)
{
  TYPE(i32_rod_sat, 1x1) old = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mrowscatadd_ew, i32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_267 (void)
{
  TYPE(i32_rnu_sat, 1x1) old = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_268 (void)
{
  TYPE(i32_rne_sat, 1x1) old = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mrowscatmax_ew, i32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_269 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mmin_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_270 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mmax_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_271 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mand_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_272 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) b = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x1) r = FN(mandnot_ew, i32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_273 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) b = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 1x1) r = FN(mor_ew, i32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_274 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x1) r = FN(mornot_ew, i32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_275 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x1) r = FN(mxor_ew, i32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_276 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_277 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_278 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) b = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) pair = FN(mconcat_m, i32_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i32_rod_sat, 1x2) (pair);
  a = FN(mextract, i32_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_279 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x2) pair = FN(mconcat_m, i32_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i32_rnu_sat, 1x2) (pair);
  a = FN(mextract, i32_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_280 (void)
{
  TYPE(i32_rne_sat, 1x1) r = FN(mcolid_ew, i32_rne_sat, 1x1) ();
  KEEP(r);
}
void case_32_281 (void)
{
  TYPE(i32_rdn_sat, 1x1) a = FN(mzero_m, i32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_282 (void)
{
  TYPE(i32_rod_sat, 1x1) a = FN(mzero_m, i32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x1) r = FN(mrowshift_ew_x, i32_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_283 (void)
{
  TYPE(i32_rnu_sat, 1x1) a = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 1x1) b = FN(mzero_m, i32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 1x2) pair = FN(mconcat_m, i32_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i32_rnu_sat, 1x2) (pair);
  a = FN(mextract, i32_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_284 (void)
{
  TYPE(i32_rne_sat, 1x1) a = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x1) b = FN(mzero_m, i32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x2) pair = FN(mconcat_m, i32_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i32_rne_sat, 1x2) (pair);
  a = FN(mextract, i32_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i32_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_285 (void)
{
  TYPE(i32_rdn_sat, 1x1) r = FN(mrowid_ew, i32_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_32_286 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(madd_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_287 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(msub_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_288 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmul_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_289 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mmulneg_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_290 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mabsdiff_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_291 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mhdiff_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_292 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmean_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_293 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mcmpge_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_294 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mcmplt_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_295 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mselge_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_296 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(msellt_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_297 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(msll_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_298 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) r = FN(msll_ew_x, u32_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_299 (void)
{
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(msrl_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_300 (void)
{
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) r = FN(msrl_ew_x, u32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_301 (void)
{
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(msra_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_302 (void)
{
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) r = FN(msra_ew_x, u32_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_303 (void)
{
  TYPE(u32_rne_sat, 1x1) old = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mmulacc_ew, u32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_304 (void)
{
  TYPE(u32_rdn_sat, 1x1) old = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_305 (void)
{
  TYPE(u32_rod_sat, 1x1) old = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mmuladd_ew, u32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_306 (void)
{
  TYPE(u32_rnu_sat, 1x1) old = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mmulsub_ew, u32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_307 (void)
{
  TYPE(u32_rne_sat, 1x1) old = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mcmovge_ew, u32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_308 (void)
{
  TYPE(u32_rdn_sat, 1x1) old = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mcmovlt_ew, u32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_309 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mcolgather_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_310 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mrowgather_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_311 (void)
{
  TYPE(u32_rne_sat, 1x1) old = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 1x1) a = FN(mzero_m, i32_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod, 1x1) b = FN(mzero_m, u32_rod, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mcolscatadd_ew, u32_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_312 (void)
{
  TYPE(u32_rdn_sat, 1x1) old = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rod, 1x1) a = FN(mzero_m, i32_rod, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x1) b = FN(mzero_m, u32_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u32_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_313 (void)
{
  TYPE(u32_rod_sat, 1x1) old = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 1x1) a = FN(mzero_m, i32_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne, 1x1) b = FN(mzero_m, u32_rne, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mcolscatmax_ew, u32_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_314 (void)
{
  TYPE(u32_rnu_sat, 1x1) old = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i32_rne, 1x1) a = FN(mzero_m, i32_rne, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x1) b = FN(mzero_m, u32_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u32_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_315 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mmin_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_316 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mmax_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_317 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mand_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_318 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) b = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x1) r = FN(mandnot_ew, u32_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_319 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) b = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 1x1) r = FN(mor_ew, u32_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_320 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x1) r = FN(mornot_ew, u32_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_321 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x1) r = FN(mxor_ew, u32_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_322 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u32_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_323 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) r = FN(mcolshift_ew_x, u32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_324 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) b = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) pair = FN(mconcat_m, u32_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u32_rdn_sat, 1x2) (pair);
  a = FN(mextract, u32_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_325 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x2) pair = FN(mconcat_m, u32_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u32_rod_sat, 1x2) (pair);
  a = FN(mextract, u32_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_326 (void)
{
  TYPE(u32_rnu_sat, 1x1) r = FN(mcolid_ew, u32_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_32_327 (void)
{
  TYPE(u32_rne_sat, 1x1) a = FN(mzero_m, u32_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u32_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_328 (void)
{
  TYPE(u32_rdn_sat, 1x1) a = FN(mzero_m, u32_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u32_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_329 (void)
{
  TYPE(u32_rod_sat, 1x1) a = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 1x1) b = FN(mzero_m, u32_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 1x2) pair = FN(mconcat_m, u32_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u32_rod_sat, 1x2) (pair);
  a = FN(mextract, u32_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_330 (void)
{
  TYPE(u32_rnu_sat, 1x1) a = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x1) b = FN(mzero_m, u32_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x2) pair = FN(mconcat_m, u32_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u32_rnu_sat, 1x2) (pair);
  a = FN(mextract, u32_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u32_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_331 (void)
{
  TYPE(u32_rne_sat, 1x1) r = FN(mrowid_ew, u32_rne_sat, 1x1) ();
  KEEP(r);
}
void case_32_332 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(madd_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_333 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(msub_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_334 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmul_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_335 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mmulneg_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_336 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mabsdiff_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_337 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mhdiff_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_338 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmean_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_339 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mcmpge_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_340 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mcmplt_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_341 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mselge_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_342 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(msellt_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_343 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(msll_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_344 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) r = FN(msll_ew_x, i64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_345 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(msrl_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_346 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) r = FN(msrl_ew_x, i64_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_347 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(msra_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_348 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) r = FN(msra_ew_x, i64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_349 (void)
{
  TYPE(i64_rdn_sat, 1x1) old = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mmulacc_ew, i64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_350 (void)
{
  TYPE(i64_rod_sat, 1x1) old = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmulaccneg_ew, i64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_351 (void)
{
  TYPE(i64_rnu_sat, 1x1) old = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mmuladd_ew, i64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_352 (void)
{
  TYPE(i64_rne_sat, 1x1) old = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mmulsub_ew, i64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_353 (void)
{
  TYPE(i64_rdn_sat, 1x1) old = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mcmovge_ew, i64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_354 (void)
{
  TYPE(i64_rod_sat, 1x1) old = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mcmovlt_ew, i64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_355 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mcolgather_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_356 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mrowgather_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_357 (void)
{
  TYPE(i64_rdn_sat, 1x1) old = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_358 (void)
{
  TYPE(i64_rod_sat, 1x1) old = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mrowscatadd_ew, i64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_359 (void)
{
  TYPE(i64_rnu_sat, 1x1) old = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_360 (void)
{
  TYPE(i64_rne_sat, 1x1) old = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mrowscatmax_ew, i64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_361 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mmin_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_362 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmax_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_363 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mand_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_364 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) b = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mandnot_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_365 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mor_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_366 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mornot_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_367 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mxor_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_368 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_369 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_370 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) pair = FN(mconcat_m, i64_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i64_rod_sat, 1x2) (pair);
  a = FN(mextract, i64_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_371 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x2) pair = FN(mconcat_m, i64_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i64_rnu_sat, 1x2) (pair);
  a = FN(mextract, i64_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_372 (void)
{
  TYPE(i64_rne_sat, 1x1) r = FN(mcolid_ew, i64_rne_sat, 1x1) ();
  KEEP(r);
}
void case_32_373 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_374 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) r = FN(mrowshift_ew_x, i64_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_375 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x2) pair = FN(mconcat_m, i64_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i64_rnu_sat, 1x2) (pair);
  a = FN(mextract, i64_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_376 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) b = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x2) pair = FN(mconcat_m, i64_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i64_rne_sat, 1x2) (pair);
  a = FN(mextract, i64_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_377 (void)
{
  TYPE(i64_rdn_sat, 1x1) r = FN(mrowid_ew, i64_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_32_378 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(madd_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_379 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(msub_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_380 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmul_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_381 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mmulneg_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_382 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mabsdiff_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_383 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mhdiff_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_384 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmean_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_385 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mcmpge_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_386 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mcmplt_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_387 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mselge_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_388 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(msellt_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_389 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(msll_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_390 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) r = FN(msll_ew_x, u64_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_391 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(msrl_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_392 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) r = FN(msrl_ew_x, u64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_393 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(msra_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_394 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) r = FN(msra_ew_x, u64_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_395 (void)
{
  TYPE(u64_rne_sat, 1x1) old = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mmulacc_ew, u64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_396 (void)
{
  TYPE(u64_rdn_sat, 1x1) old = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_397 (void)
{
  TYPE(u64_rod_sat, 1x1) old = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mmuladd_ew, u64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_398 (void)
{
  TYPE(u64_rnu_sat, 1x1) old = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mmulsub_ew, u64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_399 (void)
{
  TYPE(u64_rne_sat, 1x1) old = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mcmovge_ew, u64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_400 (void)
{
  TYPE(u64_rdn_sat, 1x1) old = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mcmovlt_ew, u64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_401 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mcolgather_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_402 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mrowgather_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_403 (void)
{
  TYPE(u64_rne_sat, 1x1) old = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mcolscatadd_ew, u64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_404 (void)
{
  TYPE(u64_rdn_sat, 1x1) old = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_405 (void)
{
  TYPE(u64_rod_sat, 1x1) old = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mcolscatmax_ew, u64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_406 (void)
{
  TYPE(u64_rnu_sat, 1x1) old = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_407 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mmin_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_408 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmax_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_409 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mand_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_410 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) b = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mandnot_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_411 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mor_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_412 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mornot_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_413 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mxor_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_414 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u64_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_415 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) r = FN(mcolshift_ew_x, u64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_416 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) pair = FN(mconcat_m, u64_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u64_rdn_sat, 1x2) (pair);
  a = FN(mextract, u64_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_417 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x2) pair = FN(mconcat_m, u64_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u64_rod_sat, 1x2) (pair);
  a = FN(mextract, u64_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_418 (void)
{
  TYPE(u64_rnu_sat, 1x1) r = FN(mcolid_ew, u64_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_32_419 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_420 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_421 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x2) pair = FN(mconcat_m, u64_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u64_rod_sat, 1x2) (pair);
  a = FN(mextract, u64_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_422 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) b = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x2) pair = FN(mconcat_m, u64_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u64_rnu_sat, 1x2) (pair);
  a = FN(mextract, u64_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_423 (void)
{
  TYPE(u64_rne_sat, 1x1) r = FN(mrowid_ew, u64_rne_sat, 1x1) ();
  KEEP(r);
}
void case_32_424 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(madd_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_425 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(msub_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_426 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmul_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_427 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mmulneg_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_428 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mabsdiff_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_429 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mhdiff_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_430 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmean_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_431 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mcmpge_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_432 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mcmplt_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_433 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mselge_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_434 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(msellt_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_435 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(msll_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_436 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) r = FN(msll_ew_x, i128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_437 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(msrl_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_438 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) r = FN(msrl_ew_x, i128_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_439 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(msra_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_440 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) r = FN(msra_ew_x, i128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_441 (void)
{
  TYPE(i128_rdn_sat, 1x1) old = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mmulacc_ew, i128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_442 (void)
{
  TYPE(i128_rod_sat, 1x1) old = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmulaccneg_ew, i128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_443 (void)
{
  TYPE(i128_rnu_sat, 1x1) old = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mmuladd_ew, i128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_444 (void)
{
  TYPE(i128_rne_sat, 1x1) old = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mmulsub_ew, i128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_445 (void)
{
  TYPE(i128_rdn_sat, 1x1) old = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mcmovge_ew, i128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_446 (void)
{
  TYPE(i128_rod_sat, 1x1) old = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mcmovlt_ew, i128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_447 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mcolgather_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_448 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mrowgather_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_449 (void)
{
  TYPE(i128_rdn_sat, 1x1) old = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_450 (void)
{
  TYPE(i128_rod_sat, 1x1) old = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mrowscatadd_ew, i128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_451 (void)
{
  TYPE(i128_rnu_sat, 1x1) old = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_452 (void)
{
  TYPE(i128_rne_sat, 1x1) old = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mrowscatmax_ew, i128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_453 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mmin_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_454 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmax_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_455 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mand_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_456 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) b = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mandnot_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_457 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mor_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_458 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mornot_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_459 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mxor_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_460 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_461 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_462 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x2) pair = FN(mconcat_m, i128_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i128_rod_sat, 1x2) (pair);
  a = FN(mextract, i128_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_463 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x2) pair = FN(mconcat_m, i128_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i128_rnu_sat, 1x2) (pair);
  a = FN(mextract, i128_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_464 (void)
{
  TYPE(i128_rne_sat, 1x1) r = FN(mcolid_ew, i128_rne_sat, 1x1) ();
  KEEP(r);
}
void case_32_465 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_466 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) r = FN(mrowshift_ew_x, i128_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_467 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x2) pair = FN(mconcat_m, i128_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i128_rnu_sat, 1x2) (pair);
  a = FN(mextract, i128_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_468 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) b = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x2) pair = FN(mconcat_m, i128_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i128_rne_sat, 1x2) (pair);
  a = FN(mextract, i128_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_469 (void)
{
  TYPE(i128_rdn_sat, 1x1) r = FN(mrowid_ew, i128_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_32_470 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(madd_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_471 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(msub_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_472 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmul_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_473 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mmulneg_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_474 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mabsdiff_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_475 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mhdiff_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_476 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmean_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_477 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mcmpge_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_478 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mcmplt_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_479 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mselge_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_480 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(msellt_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_481 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(msll_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_482 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) r = FN(msll_ew_x, u128_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_483 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(msrl_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_484 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) r = FN(msrl_ew_x, u128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_485 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(msra_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_486 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) r = FN(msra_ew_x, u128_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_487 (void)
{
  TYPE(u128_rne_sat, 1x1) old = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mmulacc_ew, u128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_488 (void)
{
  TYPE(u128_rdn_sat, 1x1) old = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_489 (void)
{
  TYPE(u128_rod_sat, 1x1) old = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mmuladd_ew, u128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_490 (void)
{
  TYPE(u128_rnu_sat, 1x1) old = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mmulsub_ew, u128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_491 (void)
{
  TYPE(u128_rne_sat, 1x1) old = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mcmovge_ew, u128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_492 (void)
{
  TYPE(u128_rdn_sat, 1x1) old = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mcmovlt_ew, u128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_493 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mcolgather_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_494 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mrowgather_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_495 (void)
{
  TYPE(u128_rne_sat, 1x1) old = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mcolscatadd_ew, u128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_496 (void)
{
  TYPE(u128_rdn_sat, 1x1) old = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_497 (void)
{
  TYPE(u128_rod_sat, 1x1) old = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mcolscatmax_ew, u128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_498 (void)
{
  TYPE(u128_rnu_sat, 1x1) old = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_32_499 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mmin_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_500 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmax_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_501 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mand_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_502 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) b = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mandnot_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_503 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mor_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_504 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mornot_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_505 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mxor_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_32_506 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u128_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_507 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) r = FN(mcolshift_ew_x, u128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_508 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x2) pair = FN(mconcat_m, u128_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u128_rdn_sat, 1x2) (pair);
  a = FN(mextract, u128_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_509 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x2) pair = FN(mconcat_m, u128_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u128_rod_sat, 1x2) (pair);
  a = FN(mextract, u128_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_510 (void)
{
  TYPE(u128_rnu_sat, 1x1) r = FN(mcolid_ew, u128_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_32_511 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_512 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_32_513 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x2) pair = FN(mconcat_m, u128_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u128_rod_sat, 1x2) (pair);
  a = FN(mextract, u128_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_514 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) b = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x2) pair = FN(mconcat_m, u128_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u128_rnu_sat, 1x2) (pair);
  a = FN(mextract, u128_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_32_515 (void)
{
  TYPE(u128_rne_sat, 1x1) r = FN(mrowid_ew, u128_rne_sat, 1x1) ();
  KEEP(r);
}
#endif

#if TEST_UDS == 64
void case_64_0 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne, 1x16) r = FN(madd_ew, i4_rne, 1x16) (a, b);
  KEEP(r);
}
void case_64_1 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 16x1) r = FN(msub_ew, i4_rdn, 16x1) (a, b);
  KEEP(r);
}
void case_64_2 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod, 1x16) r = FN(mmul_ew, i4_rod, 1x16) (a, b);
  KEEP(r);
}
void case_64_3 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 16x1) r = FN(mmulneg_ew, i4_rnu, 16x1) (a, b);
  KEEP(r);
}
void case_64_4 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne, 1x16) r = FN(mabsdiff_ew, i4_rne, 1x16) (a, b);
  KEEP(r);
}
void case_64_5 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 16x1) r = FN(mhdiff_ew, i4_rdn, 16x1) (a, b);
  KEEP(r);
}
void case_64_6 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod, 1x16) r = FN(mmean_ew, i4_rod, 1x16) (a, b);
  KEEP(r);
}
void case_64_7 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 16x1) r = FN(mcmpge_ew, i4_rnu, 16x1) (a, b);
  KEEP(r);
}
void case_64_8 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne, 1x16) r = FN(mcmplt_ew, i4_rne, 1x16) (a, b);
  KEEP(r);
}
void case_64_9 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 16x1) b = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 16x1) r = FN(mselge_ew, i4_rdn, 16x1) (a, b);
  KEEP(r);
}
void case_64_10 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod, 1x16) b = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod, 1x16) r = FN(msellt_ew, i4_rod, 1x16) (a, b);
  KEEP(r);
}
void case_64_11 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 16x1) r = FN(msll_ew, i4_rnu, 16x1) (a, b);
  KEEP(r);
}
void case_64_12 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(i4_rne, 1x16) r = FN(msll_ew_x, i4_rne, 1x16) (a, 1);
  KEEP(r);
}
void case_64_13 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 16x1) r = FN(msrl_ew, i4_rdn, 16x1) (a, b);
  KEEP(r);
}
void case_64_14 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod, 1x16) r = FN(msrl_ew_x, i4_rod, 1x16) (a, 1);
  KEEP(r);
}
void case_64_15 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 16x1) r = FN(msra_ew, i4_rnu, 16x1) (a, b);
  KEEP(r);
}
void case_64_16 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(i4_rne, 1x16) r = FN(msra_ew_x, i4_rne, 1x16) (a, 1);
  KEEP(r);
}
void case_64_17 (void)
{
  TYPE(i4_rdn, 16x1) old = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 16x1) r = FN(mmulacc_ew, i4_rdn, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_18 (void)
{
  TYPE(i4_rod, 1x16) old = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(old);
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod, 1x16) r = FN(mmulaccneg_ew, i4_rod, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_19 (void)
{
  TYPE(i4_rnu, 16x1) old = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 16x1) r = FN(mmuladd_ew, i4_rnu, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_20 (void)
{
  TYPE(i4_rne, 1x16) old = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(old);
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne, 1x16) r = FN(mmulsub_ew, i4_rne, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_21 (void)
{
  TYPE(i4_rdn, 16x1) old = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 16x1) b = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 16x1) r = FN(mcmovge_ew, i4_rdn, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_22 (void)
{
  TYPE(i4_rod, 1x16) old = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(old);
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod, 1x16) b = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod, 1x16) r = FN(mcmovlt_ew, i4_rod, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_23 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 16x1) b = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 16x1) r = FN(mmin_ew, i4_rdn, 16x1) (a, b);
  KEEP(r);
}
void case_64_24 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod, 1x16) b = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod, 1x16) r = FN(mmax_ew, i4_rod, 1x16) (a, b);
  KEEP(r);
}
void case_64_25 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 16x1) b = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 16x1) r = FN(mand_ew, i4_rnu, 16x1) (a, b);
  KEEP(r);
}
void case_64_26 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(i4_rne, 1x16) b = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne, 1x16) r = FN(mandnot_ew, i4_rne, 1x16) (a, b);
  KEEP(r);
}
void case_64_27 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 16x1) b = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 16x1) r = FN(mor_ew, i4_rdn, 16x1) (a, b);
  KEEP(r);
}
void case_64_28 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod, 1x16) b = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod, 1x16) r = FN(mornot_ew, i4_rod, 1x16) (a, b);
  KEEP(r);
}
void case_64_29 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 16x1) b = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 16x1) r = FN(mxor_ew, i4_rnu, 16x1) (a, b);
  KEEP(r);
}
void case_64_30 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x16) r = FN(madd_ew, u4_rnu, 1x16) (a, b);
  KEEP(r);
}
void case_64_31 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne, 16x1) r = FN(msub_ew, u4_rne, 16x1) (a, b);
  KEEP(r);
}
void case_64_32 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x16) r = FN(mmul_ew, u4_rdn, 1x16) (a, b);
  KEEP(r);
}
void case_64_33 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod, 16x1) r = FN(mmulneg_ew, u4_rod, 16x1) (a, b);
  KEEP(r);
}
void case_64_34 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x16) r = FN(mabsdiff_ew, u4_rnu, 1x16) (a, b);
  KEEP(r);
}
void case_64_35 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne, 16x1) r = FN(mhdiff_ew, u4_rne, 16x1) (a, b);
  KEEP(r);
}
void case_64_36 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x16) r = FN(mmean_ew, u4_rdn, 1x16) (a, b);
  KEEP(r);
}
void case_64_37 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod, 16x1) r = FN(mcmpge_ew, u4_rod, 16x1) (a, b);
  KEEP(r);
}
void case_64_38 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x16) r = FN(mcmplt_ew, u4_rnu, 1x16) (a, b);
  KEEP(r);
}
void case_64_39 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne, 16x1) r = FN(mselge_ew, u4_rne, 16x1) (a, b);
  KEEP(r);
}
void case_64_40 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x16) r = FN(msellt_ew, u4_rdn, 1x16) (a, b);
  KEEP(r);
}
void case_64_41 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod, 16x1) r = FN(msll_ew, u4_rod, 16x1) (a, b);
  KEEP(r);
}
void case_64_42 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) r = FN(msll_ew_x, u4_rnu, 1x16) (a, 1);
  KEEP(r);
}
void case_64_43 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne, 16x1) r = FN(msrl_ew, u4_rne, 16x1) (a, b);
  KEEP(r);
}
void case_64_44 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) r = FN(msrl_ew_x, u4_rdn, 1x16) (a, 1);
  KEEP(r);
}
void case_64_45 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod, 16x1) r = FN(msra_ew, u4_rod, 16x1) (a, b);
  KEEP(r);
}
void case_64_46 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) r = FN(msra_ew_x, u4_rnu, 1x16) (a, 1);
  KEEP(r);
}
void case_64_47 (void)
{
  TYPE(u4_rne, 16x1) old = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne, 16x1) r = FN(mmulacc_ew, u4_rne, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_48 (void)
{
  TYPE(u4_rdn, 1x16) old = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(old);
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x16) r = FN(mmulaccneg_ew, u4_rdn, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_49 (void)
{
  TYPE(u4_rod, 16x1) old = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod, 16x1) r = FN(mmuladd_ew, u4_rod, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_50 (void)
{
  TYPE(u4_rnu, 1x16) old = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(old);
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x16) r = FN(mmulsub_ew, u4_rnu, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_51 (void)
{
  TYPE(u4_rne, 16x1) old = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne, 16x1) r = FN(mcmovge_ew, u4_rne, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_52 (void)
{
  TYPE(u4_rdn, 1x16) old = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(old);
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x16) r = FN(mcmovlt_ew, u4_rdn, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_53 (void)
{
  TYPE(u4_rne, 16x1) a = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne, 16x1) r = FN(mmin_ew, u4_rne, 16x1) (a, b);
  KEEP(r);
}
void case_64_54 (void)
{
  TYPE(u4_rdn, 1x16) a = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x16) r = FN(mmax_ew, u4_rdn, 1x16) (a, b);
  KEEP(r);
}
void case_64_55 (void)
{
  TYPE(u4_rod, 16x1) a = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod, 16x1) r = FN(mand_ew, u4_rod, 16x1) (a, b);
  KEEP(r);
}
void case_64_56 (void)
{
  TYPE(u4_rnu, 1x16) a = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x16) r = FN(mandnot_ew, u4_rnu, 1x16) (a, b);
  KEEP(r);
}
void case_64_57 (void)
{
  TYPE(u4_rne, 16x1) a = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne, 16x1) r = FN(mor_ew, u4_rne, 16x1) (a, b);
  KEEP(r);
}
void case_64_58 (void)
{
  TYPE(u4_rdn, 1x16) a = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x16) r = FN(mornot_ew, u4_rdn, 1x16) (a, b);
  KEEP(r);
}
void case_64_59 (void)
{
  TYPE(u4_rod, 16x1) a = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod, 16x1) r = FN(mxor_ew, u4_rod, 16x1) (a, b);
  KEEP(r);
}
void case_64_60 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x16) r = FN(madd_ew, i4_rne_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_61 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 16x1) r = FN(msub_ew, i4_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_62 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x16) r = FN(mmul_ew, i4_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_63 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 16x1) r = FN(mmulneg_ew, i4_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_64 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x16) r = FN(mabsdiff_ew, i4_rne_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_65 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 16x1) r = FN(mhdiff_ew, i4_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_66 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x16) r = FN(mmean_ew, i4_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_67 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 16x1) r = FN(mcmpge_ew, i4_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_68 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x16) r = FN(mcmplt_ew, i4_rne_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_69 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 16x1) b = FN(mzero_m, i4_rdn_sat, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 16x1) r = FN(mselge_ew, i4_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_70 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x16) b = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x16) r = FN(msellt_ew, i4_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_71 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 16x1) r = FN(msll_ew, i4_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_72 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x16) r = FN(msll_ew_x, i4_rne_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_64_73 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 16x1) r = FN(msrl_ew, i4_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_74 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x16) r = FN(msrl_ew_x, i4_rod_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_64_75 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 16x1) r = FN(msra_ew, i4_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_76 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x16) r = FN(msra_ew_x, i4_rne_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_64_77 (void)
{
  TYPE(i4_rdn_sat, 16x1) old = FN(mzero_m, i4_rdn_sat, 16x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 16x1) r = FN(mmulacc_ew, i4_rdn_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_78 (void)
{
  TYPE(i4_rod_sat, 1x16) old = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE(old);
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x16) r = FN(mmulaccneg_ew, i4_rod_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_79 (void)
{
  TYPE(i4_rnu_sat, 16x1) old = FN(mzero_m, i4_rnu_sat, 16x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 16x1) r = FN(mmuladd_ew, i4_rnu_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_80 (void)
{
  TYPE(i4_rne_sat, 1x16) old = FN(mzero_m, i4_rne_sat, 1x16) ();
  CHANGE(old);
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x16) r = FN(mmulsub_ew, i4_rne_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_81 (void)
{
  TYPE(i4_rdn_sat, 16x1) old = FN(mzero_m, i4_rdn_sat, 16x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 16x1) b = FN(mzero_m, i4_rdn_sat, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 16x1) r = FN(mcmovge_ew, i4_rdn_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_82 (void)
{
  TYPE(i4_rod_sat, 1x16) old = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE(old);
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x16) b = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x16) r = FN(mcmovlt_ew, i4_rod_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_83 (void)
{
  TYPE(i4_rdn_sat, 16x1) a = FN(mzero_m, i4_rdn_sat, 16x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 16x1) b = FN(mzero_m, i4_rdn_sat, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 16x1) r = FN(mmin_ew, i4_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_84 (void)
{
  TYPE(i4_rod_sat, 1x16) a = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x16) b = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x16) r = FN(mmax_ew, i4_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_85 (void)
{
  TYPE(i4_rnu_sat, 16x1) a = FN(mzero_m, i4_rnu_sat, 16x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 16x1) b = FN(mzero_m, i4_rnu_sat, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 16x1) r = FN(mand_ew, i4_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_86 (void)
{
  TYPE(i4_rne_sat, 1x16) a = FN(mzero_m, i4_rne_sat, 1x16) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x16) b = FN(mzero_m, i4_rne_sat, 1x16) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x16) r = FN(mandnot_ew, i4_rne_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_87 (void)
{
  TYPE(i4_rdn_sat, 16x1) a = FN(mzero_m, i4_rdn_sat, 16x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 16x1) b = FN(mzero_m, i4_rdn_sat, 16x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 16x1) r = FN(mor_ew, i4_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_88 (void)
{
  TYPE(i4_rod_sat, 1x16) a = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x16) b = FN(mzero_m, i4_rod_sat, 1x16) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x16) r = FN(mornot_ew, i4_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_89 (void)
{
  TYPE(i4_rnu_sat, 16x1) a = FN(mzero_m, i4_rnu_sat, 16x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 16x1) b = FN(mzero_m, i4_rnu_sat, 16x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 16x1) r = FN(mxor_ew, i4_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_90 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x16) r = FN(madd_ew, u4_rnu_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_91 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 16x1) r = FN(msub_ew, u4_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_92 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x16) r = FN(mmul_ew, u4_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_93 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 16x1) r = FN(mmulneg_ew, u4_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_94 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x16) r = FN(mabsdiff_ew, u4_rnu_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_95 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 16x1) r = FN(mhdiff_ew, u4_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_96 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x16) r = FN(mmean_ew, u4_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_97 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 16x1) r = FN(mcmpge_ew, u4_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_98 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x16) r = FN(mcmplt_ew, u4_rnu_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_99 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 16x1) b = FN(mzero_m, u4_rne_sat, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 16x1) r = FN(mselge_ew, u4_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_100 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x16) b = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x16) r = FN(msellt_ew, u4_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_101 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 16x1) r = FN(msll_ew, u4_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_102 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x16) r = FN(msll_ew_x, u4_rnu_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_64_103 (void)
{
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 16x1) r = FN(msrl_ew, u4_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_104 (void)
{
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x16) r = FN(msrl_ew_x, u4_rdn_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_64_105 (void)
{
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 16x1) r = FN(msra_ew, u4_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_106 (void)
{
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x16) r = FN(msra_ew_x, u4_rnu_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_64_107 (void)
{
  TYPE(u4_rne_sat, 16x1) old = FN(mzero_m, u4_rne_sat, 16x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod, 16x1) b = FN(mzero_m, u4_rod, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 16x1) r = FN(mmulacc_ew, u4_rne_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_108 (void)
{
  TYPE(u4_rdn_sat, 1x16) old = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE(old);
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x16) b = FN(mzero_m, u4_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x16) r = FN(mmulaccneg_ew, u4_rdn_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_109 (void)
{
  TYPE(u4_rod_sat, 16x1) old = FN(mzero_m, u4_rod_sat, 16x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 16x1) a = FN(mzero_m, i4_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne, 16x1) b = FN(mzero_m, u4_rne, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 16x1) r = FN(mmuladd_ew, u4_rod_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_110 (void)
{
  TYPE(u4_rnu_sat, 1x16) old = FN(mzero_m, u4_rnu_sat, 1x16) ();
  CHANGE(old);
  TYPE(i4_rne, 1x16) a = FN(mzero_m, i4_rne, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x16) b = FN(mzero_m, u4_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x16) r = FN(mmulsub_ew, u4_rnu_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_111 (void)
{
  TYPE(u4_rne_sat, 16x1) old = FN(mzero_m, u4_rne_sat, 16x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 16x1) a = FN(mzero_m, i4_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 16x1) b = FN(mzero_m, u4_rne_sat, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 16x1) r = FN(mcmovge_ew, u4_rne_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_64_112 (void)
{
  TYPE(u4_rdn_sat, 1x16) old = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE(old);
  TYPE(i4_rod, 1x16) a = FN(mzero_m, i4_rod, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x16) b = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x16) r = FN(mcmovlt_ew, u4_rdn_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_64_113 (void)
{
  TYPE(u4_rne_sat, 16x1) a = FN(mzero_m, u4_rne_sat, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 16x1) b = FN(mzero_m, u4_rne_sat, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 16x1) r = FN(mmin_ew, u4_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_114 (void)
{
  TYPE(u4_rdn_sat, 1x16) a = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x16) b = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x16) r = FN(mmax_ew, u4_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_115 (void)
{
  TYPE(u4_rod_sat, 16x1) a = FN(mzero_m, u4_rod_sat, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 16x1) b = FN(mzero_m, u4_rod_sat, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 16x1) r = FN(mand_ew, u4_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_116 (void)
{
  TYPE(u4_rnu_sat, 1x16) a = FN(mzero_m, u4_rnu_sat, 1x16) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x16) b = FN(mzero_m, u4_rnu_sat, 1x16) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x16) r = FN(mandnot_ew, u4_rnu_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_117 (void)
{
  TYPE(u4_rne_sat, 16x1) a = FN(mzero_m, u4_rne_sat, 16x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 16x1) b = FN(mzero_m, u4_rne_sat, 16x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 16x1) r = FN(mor_ew, u4_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_118 (void)
{
  TYPE(u4_rdn_sat, 1x16) a = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x16) b = FN(mzero_m, u4_rdn_sat, 1x16) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x16) r = FN(mornot_ew, u4_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_64_119 (void)
{
  TYPE(u4_rod_sat, 16x1) a = FN(mzero_m, u4_rod_sat, 16x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 16x1) b = FN(mzero_m, u4_rod_sat, 16x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 16x1) r = FN(mxor_ew, u4_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_64_120 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x8) b = FN(mzero_m, u8_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x8) r = FN(madd_ew, i8_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_121 (void)
{
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod, 8x1) b = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 8x1) r = FN(msub_ew, i8_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_122 (void)
{
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x8) b = FN(mzero_m, u8_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x8) r = FN(mmul_ew, i8_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_123 (void)
{
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 8x1) r = FN(mmulneg_ew, i8_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_124 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x8) b = FN(mzero_m, u8_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x8) r = FN(mabsdiff_ew, i8_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_125 (void)
{
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod, 8x1) b = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 8x1) r = FN(mhdiff_ew, i8_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_126 (void)
{
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x8) b = FN(mzero_m, u8_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x8) r = FN(mmean_ew, i8_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_127 (void)
{
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 8x1) r = FN(mcmpge_ew, i8_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_128 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x8) b = FN(mzero_m, u8_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x8) r = FN(mcmplt_ew, i8_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_129 (void)
{
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 8x1) b = FN(mzero_m, i8_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 8x1) r = FN(mselge_ew, i8_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_130 (void)
{
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x8) b = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x8) r = FN(msellt_ew, i8_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_131 (void)
{
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 8x1) r = FN(msll_ew, i8_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_132 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x8) r = FN(msll_ew_x, i8_rne_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_64_133 (void)
{
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod, 8x1) b = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 8x1) r = FN(msrl_ew, i8_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_134 (void)
{
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x8) r = FN(msrl_ew_x, i8_rod_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_64_135 (void)
{
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 8x1) r = FN(msra_ew, i8_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_136 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x8) r = FN(msra_ew_x, i8_rne_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_64_137 (void)
{
  TYPE(i8_rdn_sat, 8x1) old = FN(mzero_m, i8_rdn_sat, 8x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod, 8x1) b = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 8x1) r = FN(mmulacc_ew, i8_rdn_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_64_138 (void)
{
  TYPE(i8_rod_sat, 1x8) old = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE(old);
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x8) b = FN(mzero_m, u8_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x8) r = FN(mmulaccneg_ew, i8_rod_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_64_139 (void)
{
  TYPE(i8_rnu_sat, 8x1) old = FN(mzero_m, i8_rnu_sat, 8x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 8x1) r = FN(mmuladd_ew, i8_rnu_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_64_140 (void)
{
  TYPE(i8_rne_sat, 1x8) old = FN(mzero_m, i8_rne_sat, 1x8) ();
  CHANGE(old);
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x8) b = FN(mzero_m, u8_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x8) r = FN(mmulsub_ew, i8_rne_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_64_141 (void)
{
  TYPE(i8_rdn_sat, 8x1) old = FN(mzero_m, i8_rdn_sat, 8x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 8x1) b = FN(mzero_m, i8_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 8x1) r = FN(mcmovge_ew, i8_rdn_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_64_142 (void)
{
  TYPE(i8_rod_sat, 1x8) old = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE(old);
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x8) b = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x8) r = FN(mcmovlt_ew, i8_rod_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_64_143 (void)
{
  TYPE(i8_rdn_sat, 8x1) a = FN(mzero_m, i8_rdn_sat, 8x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 8x1) b = FN(mzero_m, i8_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 8x1) r = FN(mmin_ew, i8_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_144 (void)
{
  TYPE(i8_rod_sat, 1x8) a = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x8) b = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x8) r = FN(mmax_ew, i8_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_145 (void)
{
  TYPE(i8_rnu_sat, 8x1) a = FN(mzero_m, i8_rnu_sat, 8x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 8x1) b = FN(mzero_m, i8_rnu_sat, 8x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 8x1) r = FN(mand_ew, i8_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_146 (void)
{
  TYPE(i8_rne_sat, 1x8) a = FN(mzero_m, i8_rne_sat, 1x8) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x8) b = FN(mzero_m, i8_rne_sat, 1x8) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x8) r = FN(mandnot_ew, i8_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_147 (void)
{
  TYPE(i8_rdn_sat, 8x1) a = FN(mzero_m, i8_rdn_sat, 8x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 8x1) b = FN(mzero_m, i8_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 8x1) r = FN(mor_ew, i8_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_148 (void)
{
  TYPE(i8_rod_sat, 1x8) a = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x8) b = FN(mzero_m, i8_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x8) r = FN(mornot_ew, i8_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_149 (void)
{
  TYPE(i8_rnu_sat, 8x1) a = FN(mzero_m, i8_rnu_sat, 8x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 8x1) b = FN(mzero_m, i8_rnu_sat, 8x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 8x1) r = FN(mxor_ew, i8_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_150 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x8) b = FN(mzero_m, u8_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x8) r = FN(madd_ew, u8_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_151 (void)
{
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod, 8x1) b = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 8x1) r = FN(msub_ew, u8_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_152 (void)
{
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x8) b = FN(mzero_m, u8_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x8) r = FN(mmul_ew, u8_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_153 (void)
{
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 8x1) r = FN(mmulneg_ew, u8_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_154 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x8) b = FN(mzero_m, u8_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x8) r = FN(mabsdiff_ew, u8_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_155 (void)
{
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod, 8x1) b = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 8x1) r = FN(mhdiff_ew, u8_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_156 (void)
{
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x8) b = FN(mzero_m, u8_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x8) r = FN(mmean_ew, u8_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_157 (void)
{
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 8x1) r = FN(mcmpge_ew, u8_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_158 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x8) b = FN(mzero_m, u8_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x8) r = FN(mcmplt_ew, u8_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_159 (void)
{
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 8x1) b = FN(mzero_m, u8_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 8x1) r = FN(mselge_ew, u8_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_160 (void)
{
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x8) b = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x8) r = FN(msellt_ew, u8_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_161 (void)
{
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 8x1) r = FN(msll_ew, u8_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_162 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x8) r = FN(msll_ew_x, u8_rnu_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_64_163 (void)
{
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod, 8x1) b = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 8x1) r = FN(msrl_ew, u8_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_164 (void)
{
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x8) r = FN(msrl_ew_x, u8_rdn_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_64_165 (void)
{
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 8x1) r = FN(msra_ew, u8_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_166 (void)
{
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x8) r = FN(msra_ew_x, u8_rnu_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_64_167 (void)
{
  TYPE(u8_rne_sat, 8x1) old = FN(mzero_m, u8_rne_sat, 8x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod, 8x1) b = FN(mzero_m, u8_rod, 8x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 8x1) r = FN(mmulacc_ew, u8_rne_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_64_168 (void)
{
  TYPE(u8_rdn_sat, 1x8) old = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE(old);
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x8) b = FN(mzero_m, u8_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x8) r = FN(mmulaccneg_ew, u8_rdn_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_64_169 (void)
{
  TYPE(u8_rod_sat, 8x1) old = FN(mzero_m, u8_rod_sat, 8x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 8x1) a = FN(mzero_m, i8_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne, 8x1) b = FN(mzero_m, u8_rne, 8x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 8x1) r = FN(mmuladd_ew, u8_rod_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_64_170 (void)
{
  TYPE(u8_rnu_sat, 1x8) old = FN(mzero_m, u8_rnu_sat, 1x8) ();
  CHANGE(old);
  TYPE(i8_rne, 1x8) a = FN(mzero_m, i8_rne, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x8) b = FN(mzero_m, u8_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x8) r = FN(mmulsub_ew, u8_rnu_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_64_171 (void)
{
  TYPE(u8_rne_sat, 8x1) old = FN(mzero_m, u8_rne_sat, 8x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 8x1) a = FN(mzero_m, i8_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 8x1) b = FN(mzero_m, u8_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 8x1) r = FN(mcmovge_ew, u8_rne_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_64_172 (void)
{
  TYPE(u8_rdn_sat, 1x8) old = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE(old);
  TYPE(i8_rod, 1x8) a = FN(mzero_m, i8_rod, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x8) b = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x8) r = FN(mcmovlt_ew, u8_rdn_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_64_173 (void)
{
  TYPE(u8_rne_sat, 8x1) a = FN(mzero_m, u8_rne_sat, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 8x1) b = FN(mzero_m, u8_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 8x1) r = FN(mmin_ew, u8_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_174 (void)
{
  TYPE(u8_rdn_sat, 1x8) a = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x8) b = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x8) r = FN(mmax_ew, u8_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_175 (void)
{
  TYPE(u8_rod_sat, 8x1) a = FN(mzero_m, u8_rod_sat, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 8x1) b = FN(mzero_m, u8_rod_sat, 8x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 8x1) r = FN(mand_ew, u8_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_176 (void)
{
  TYPE(u8_rnu_sat, 1x8) a = FN(mzero_m, u8_rnu_sat, 1x8) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x8) b = FN(mzero_m, u8_rnu_sat, 1x8) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x8) r = FN(mandnot_ew, u8_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_177 (void)
{
  TYPE(u8_rne_sat, 8x1) a = FN(mzero_m, u8_rne_sat, 8x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 8x1) b = FN(mzero_m, u8_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 8x1) r = FN(mor_ew, u8_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_178 (void)
{
  TYPE(u8_rdn_sat, 1x8) a = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x8) b = FN(mzero_m, u8_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x8) r = FN(mornot_ew, u8_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_64_179 (void)
{
  TYPE(u8_rod_sat, 8x1) a = FN(mzero_m, u8_rod_sat, 8x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 8x1) b = FN(mzero_m, u8_rod_sat, 8x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 8x1) r = FN(mxor_ew, u8_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_64_180 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x4) b = FN(mzero_m, u16_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x4) r = FN(madd_ew, i16_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_181 (void)
{
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod, 4x1) b = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 4x1) r = FN(msub_ew, i16_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_182 (void)
{
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x4) b = FN(mzero_m, u16_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x4) r = FN(mmul_ew, i16_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_183 (void)
{
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 4x1) r = FN(mmulneg_ew, i16_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_184 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x4) b = FN(mzero_m, u16_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x4) r = FN(mabsdiff_ew, i16_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_185 (void)
{
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod, 4x1) b = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 4x1) r = FN(mhdiff_ew, i16_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_186 (void)
{
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x4) b = FN(mzero_m, u16_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x4) r = FN(mmean_ew, i16_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_187 (void)
{
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 4x1) r = FN(mcmpge_ew, i16_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_188 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x4) b = FN(mzero_m, u16_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x4) r = FN(mcmplt_ew, i16_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_189 (void)
{
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 4x1) b = FN(mzero_m, i16_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 4x1) r = FN(mselge_ew, i16_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_190 (void)
{
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x4) b = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x4) r = FN(msellt_ew, i16_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_191 (void)
{
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 4x1) r = FN(msll_ew, i16_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_192 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x4) r = FN(msll_ew_x, i16_rne_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_64_193 (void)
{
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod, 4x1) b = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 4x1) r = FN(msrl_ew, i16_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_194 (void)
{
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x4) r = FN(msrl_ew_x, i16_rod_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_64_195 (void)
{
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 4x1) r = FN(msra_ew, i16_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_196 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x4) r = FN(msra_ew_x, i16_rne_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_64_197 (void)
{
  TYPE(i16_rdn_sat, 4x1) old = FN(mzero_m, i16_rdn_sat, 4x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod, 4x1) b = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 4x1) r = FN(mmulacc_ew, i16_rdn_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_64_198 (void)
{
  TYPE(i16_rod_sat, 1x4) old = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE(old);
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x4) b = FN(mzero_m, u16_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x4) r = FN(mmulaccneg_ew, i16_rod_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_64_199 (void)
{
  TYPE(i16_rnu_sat, 4x1) old = FN(mzero_m, i16_rnu_sat, 4x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 4x1) r = FN(mmuladd_ew, i16_rnu_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_64_200 (void)
{
  TYPE(i16_rne_sat, 1x4) old = FN(mzero_m, i16_rne_sat, 1x4) ();
  CHANGE(old);
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x4) b = FN(mzero_m, u16_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x4) r = FN(mmulsub_ew, i16_rne_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_64_201 (void)
{
  TYPE(i16_rdn_sat, 4x1) old = FN(mzero_m, i16_rdn_sat, 4x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 4x1) b = FN(mzero_m, i16_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 4x1) r = FN(mcmovge_ew, i16_rdn_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_64_202 (void)
{
  TYPE(i16_rod_sat, 1x4) old = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE(old);
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x4) b = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x4) r = FN(mcmovlt_ew, i16_rod_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_64_203 (void)
{
  TYPE(i16_rdn_sat, 4x1) a = FN(mzero_m, i16_rdn_sat, 4x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 4x1) b = FN(mzero_m, i16_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 4x1) r = FN(mmin_ew, i16_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_204 (void)
{
  TYPE(i16_rod_sat, 1x4) a = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x4) b = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x4) r = FN(mmax_ew, i16_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_205 (void)
{
  TYPE(i16_rnu_sat, 4x1) a = FN(mzero_m, i16_rnu_sat, 4x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 4x1) b = FN(mzero_m, i16_rnu_sat, 4x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 4x1) r = FN(mand_ew, i16_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_206 (void)
{
  TYPE(i16_rne_sat, 1x4) a = FN(mzero_m, i16_rne_sat, 1x4) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x4) b = FN(mzero_m, i16_rne_sat, 1x4) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x4) r = FN(mandnot_ew, i16_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_207 (void)
{
  TYPE(i16_rdn_sat, 4x1) a = FN(mzero_m, i16_rdn_sat, 4x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 4x1) b = FN(mzero_m, i16_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 4x1) r = FN(mor_ew, i16_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_208 (void)
{
  TYPE(i16_rod_sat, 1x4) a = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x4) b = FN(mzero_m, i16_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x4) r = FN(mornot_ew, i16_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_209 (void)
{
  TYPE(i16_rnu_sat, 4x1) a = FN(mzero_m, i16_rnu_sat, 4x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 4x1) b = FN(mzero_m, i16_rnu_sat, 4x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 4x1) r = FN(mxor_ew, i16_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_210 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x4) b = FN(mzero_m, u16_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x4) r = FN(madd_ew, u16_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_211 (void)
{
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod, 4x1) b = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 4x1) r = FN(msub_ew, u16_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_212 (void)
{
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x4) b = FN(mzero_m, u16_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x4) r = FN(mmul_ew, u16_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_213 (void)
{
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 4x1) r = FN(mmulneg_ew, u16_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_214 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x4) b = FN(mzero_m, u16_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x4) r = FN(mabsdiff_ew, u16_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_215 (void)
{
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod, 4x1) b = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 4x1) r = FN(mhdiff_ew, u16_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_216 (void)
{
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x4) b = FN(mzero_m, u16_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x4) r = FN(mmean_ew, u16_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_217 (void)
{
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 4x1) r = FN(mcmpge_ew, u16_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_218 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x4) b = FN(mzero_m, u16_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x4) r = FN(mcmplt_ew, u16_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_219 (void)
{
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 4x1) b = FN(mzero_m, u16_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 4x1) r = FN(mselge_ew, u16_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_220 (void)
{
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x4) b = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x4) r = FN(msellt_ew, u16_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_221 (void)
{
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 4x1) r = FN(msll_ew, u16_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_222 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x4) r = FN(msll_ew_x, u16_rnu_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_64_223 (void)
{
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod, 4x1) b = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 4x1) r = FN(msrl_ew, u16_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_224 (void)
{
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x4) r = FN(msrl_ew_x, u16_rdn_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_64_225 (void)
{
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 4x1) r = FN(msra_ew, u16_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_226 (void)
{
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x4) r = FN(msra_ew_x, u16_rnu_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_64_227 (void)
{
  TYPE(u16_rne_sat, 4x1) old = FN(mzero_m, u16_rne_sat, 4x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod, 4x1) b = FN(mzero_m, u16_rod, 4x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 4x1) r = FN(mmulacc_ew, u16_rne_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_64_228 (void)
{
  TYPE(u16_rdn_sat, 1x4) old = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE(old);
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x4) b = FN(mzero_m, u16_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x4) r = FN(mmulaccneg_ew, u16_rdn_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_64_229 (void)
{
  TYPE(u16_rod_sat, 4x1) old = FN(mzero_m, u16_rod_sat, 4x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 4x1) a = FN(mzero_m, i16_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne, 4x1) b = FN(mzero_m, u16_rne, 4x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 4x1) r = FN(mmuladd_ew, u16_rod_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_64_230 (void)
{
  TYPE(u16_rnu_sat, 1x4) old = FN(mzero_m, u16_rnu_sat, 1x4) ();
  CHANGE(old);
  TYPE(i16_rne, 1x4) a = FN(mzero_m, i16_rne, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x4) b = FN(mzero_m, u16_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x4) r = FN(mmulsub_ew, u16_rnu_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_64_231 (void)
{
  TYPE(u16_rne_sat, 4x1) old = FN(mzero_m, u16_rne_sat, 4x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 4x1) a = FN(mzero_m, i16_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 4x1) b = FN(mzero_m, u16_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 4x1) r = FN(mcmovge_ew, u16_rne_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_64_232 (void)
{
  TYPE(u16_rdn_sat, 1x4) old = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE(old);
  TYPE(i16_rod, 1x4) a = FN(mzero_m, i16_rod, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x4) b = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x4) r = FN(mcmovlt_ew, u16_rdn_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_64_233 (void)
{
  TYPE(u16_rne_sat, 4x1) a = FN(mzero_m, u16_rne_sat, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 4x1) b = FN(mzero_m, u16_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 4x1) r = FN(mmin_ew, u16_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_234 (void)
{
  TYPE(u16_rdn_sat, 1x4) a = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x4) b = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x4) r = FN(mmax_ew, u16_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_235 (void)
{
  TYPE(u16_rod_sat, 4x1) a = FN(mzero_m, u16_rod_sat, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 4x1) b = FN(mzero_m, u16_rod_sat, 4x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 4x1) r = FN(mand_ew, u16_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_236 (void)
{
  TYPE(u16_rnu_sat, 1x4) a = FN(mzero_m, u16_rnu_sat, 1x4) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x4) b = FN(mzero_m, u16_rnu_sat, 1x4) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x4) r = FN(mandnot_ew, u16_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_237 (void)
{
  TYPE(u16_rne_sat, 4x1) a = FN(mzero_m, u16_rne_sat, 4x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 4x1) b = FN(mzero_m, u16_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 4x1) r = FN(mor_ew, u16_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_238 (void)
{
  TYPE(u16_rdn_sat, 1x4) a = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x4) b = FN(mzero_m, u16_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x4) r = FN(mornot_ew, u16_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_64_239 (void)
{
  TYPE(u16_rod_sat, 4x1) a = FN(mzero_m, u16_rod_sat, 4x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 4x1) b = FN(mzero_m, u16_rod_sat, 4x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 4x1) r = FN(mxor_ew, u16_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_64_240 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x2) b = FN(mzero_m, u32_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x2) r = FN(madd_ew, i32_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_241 (void)
{
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod, 2x1) b = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 2x1) r = FN(msub_ew, i32_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_242 (void)
{
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x2) b = FN(mzero_m, u32_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) r = FN(mmul_ew, i32_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_243 (void)
{
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 2x1) r = FN(mmulneg_ew, i32_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_244 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x2) b = FN(mzero_m, u32_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x2) r = FN(mabsdiff_ew, i32_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_245 (void)
{
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod, 2x1) b = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 2x1) r = FN(mhdiff_ew, i32_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_246 (void)
{
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x2) b = FN(mzero_m, u32_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) r = FN(mmean_ew, i32_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_247 (void)
{
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 2x1) r = FN(mcmpge_ew, i32_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_248 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x2) b = FN(mzero_m, u32_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x2) r = FN(mcmplt_ew, i32_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_249 (void)
{
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 2x1) b = FN(mzero_m, i32_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 2x1) r = FN(mselge_ew, i32_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_250 (void)
{
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x2) b = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) r = FN(msellt_ew, i32_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_251 (void)
{
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 2x1) r = FN(msll_ew, i32_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_252 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x2) r = FN(msll_ew_x, i32_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_64_253 (void)
{
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod, 2x1) b = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 2x1) r = FN(msrl_ew, i32_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_254 (void)
{
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x2) r = FN(msrl_ew_x, i32_rod_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_64_255 (void)
{
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 2x1) r = FN(msra_ew, i32_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_256 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x2) r = FN(msra_ew_x, i32_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_64_257 (void)
{
  TYPE(i32_rdn_sat, 2x1) old = FN(mzero_m, i32_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod, 2x1) b = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 2x1) r = FN(mmulacc_ew, i32_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_64_258 (void)
{
  TYPE(i32_rod_sat, 1x2) old = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x2) b = FN(mzero_m, u32_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) r = FN(mmulaccneg_ew, i32_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_64_259 (void)
{
  TYPE(i32_rnu_sat, 2x1) old = FN(mzero_m, i32_rnu_sat, 2x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 2x1) r = FN(mmuladd_ew, i32_rnu_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_64_260 (void)
{
  TYPE(i32_rne_sat, 1x2) old = FN(mzero_m, i32_rne_sat, 1x2) ();
  CHANGE(old);
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x2) b = FN(mzero_m, u32_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x2) r = FN(mmulsub_ew, i32_rne_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_64_261 (void)
{
  TYPE(i32_rdn_sat, 2x1) old = FN(mzero_m, i32_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 2x1) b = FN(mzero_m, i32_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 2x1) r = FN(mcmovge_ew, i32_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_64_262 (void)
{
  TYPE(i32_rod_sat, 1x2) old = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x2) b = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) r = FN(mcmovlt_ew, i32_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_64_263 (void)
{
  TYPE(i32_rdn_sat, 2x1) a = FN(mzero_m, i32_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 2x1) b = FN(mzero_m, i32_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 2x1) r = FN(mmin_ew, i32_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_264 (void)
{
  TYPE(i32_rod_sat, 1x2) a = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x2) b = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) r = FN(mmax_ew, i32_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_265 (void)
{
  TYPE(i32_rnu_sat, 2x1) a = FN(mzero_m, i32_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 2x1) b = FN(mzero_m, i32_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 2x1) r = FN(mand_ew, i32_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_266 (void)
{
  TYPE(i32_rne_sat, 1x2) a = FN(mzero_m, i32_rne_sat, 1x2) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x2) b = FN(mzero_m, i32_rne_sat, 1x2) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x2) r = FN(mandnot_ew, i32_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_267 (void)
{
  TYPE(i32_rdn_sat, 2x1) a = FN(mzero_m, i32_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 2x1) b = FN(mzero_m, i32_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 2x1) r = FN(mor_ew, i32_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_268 (void)
{
  TYPE(i32_rod_sat, 1x2) a = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x2) b = FN(mzero_m, i32_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x2) r = FN(mornot_ew, i32_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_269 (void)
{
  TYPE(i32_rnu_sat, 2x1) a = FN(mzero_m, i32_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 2x1) b = FN(mzero_m, i32_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 2x1) r = FN(mxor_ew, i32_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_270 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x2) b = FN(mzero_m, u32_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x2) r = FN(madd_ew, u32_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_271 (void)
{
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod, 2x1) b = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 2x1) r = FN(msub_ew, u32_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_272 (void)
{
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x2) b = FN(mzero_m, u32_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) r = FN(mmul_ew, u32_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_273 (void)
{
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 2x1) r = FN(mmulneg_ew, u32_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_274 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x2) b = FN(mzero_m, u32_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x2) r = FN(mabsdiff_ew, u32_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_275 (void)
{
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod, 2x1) b = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 2x1) r = FN(mhdiff_ew, u32_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_276 (void)
{
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x2) b = FN(mzero_m, u32_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) r = FN(mmean_ew, u32_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_277 (void)
{
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 2x1) r = FN(mcmpge_ew, u32_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_278 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x2) b = FN(mzero_m, u32_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x2) r = FN(mcmplt_ew, u32_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_279 (void)
{
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 2x1) b = FN(mzero_m, u32_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 2x1) r = FN(mselge_ew, u32_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_280 (void)
{
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x2) b = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) r = FN(msellt_ew, u32_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_281 (void)
{
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 2x1) r = FN(msll_ew, u32_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_282 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x2) r = FN(msll_ew_x, u32_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_64_283 (void)
{
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod, 2x1) b = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 2x1) r = FN(msrl_ew, u32_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_284 (void)
{
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x2) r = FN(msrl_ew_x, u32_rdn_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_64_285 (void)
{
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 2x1) r = FN(msra_ew, u32_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_286 (void)
{
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x2) r = FN(msra_ew_x, u32_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_64_287 (void)
{
  TYPE(u32_rne_sat, 2x1) old = FN(mzero_m, u32_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod, 2x1) b = FN(mzero_m, u32_rod, 2x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 2x1) r = FN(mmulacc_ew, u32_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_64_288 (void)
{
  TYPE(u32_rdn_sat, 1x2) old = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x2) b = FN(mzero_m, u32_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) r = FN(mmulaccneg_ew, u32_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_64_289 (void)
{
  TYPE(u32_rod_sat, 2x1) old = FN(mzero_m, u32_rod_sat, 2x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 2x1) a = FN(mzero_m, i32_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne, 2x1) b = FN(mzero_m, u32_rne, 2x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 2x1) r = FN(mmuladd_ew, u32_rod_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_64_290 (void)
{
  TYPE(u32_rnu_sat, 1x2) old = FN(mzero_m, u32_rnu_sat, 1x2) ();
  CHANGE(old);
  TYPE(i32_rne, 1x2) a = FN(mzero_m, i32_rne, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x2) b = FN(mzero_m, u32_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x2) r = FN(mmulsub_ew, u32_rnu_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_64_291 (void)
{
  TYPE(u32_rne_sat, 2x1) old = FN(mzero_m, u32_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 2x1) a = FN(mzero_m, i32_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 2x1) b = FN(mzero_m, u32_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 2x1) r = FN(mcmovge_ew, u32_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_64_292 (void)
{
  TYPE(u32_rdn_sat, 1x2) old = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i32_rod, 1x2) a = FN(mzero_m, i32_rod, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x2) b = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) r = FN(mcmovlt_ew, u32_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_64_293 (void)
{
  TYPE(u32_rne_sat, 2x1) a = FN(mzero_m, u32_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 2x1) b = FN(mzero_m, u32_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 2x1) r = FN(mmin_ew, u32_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_294 (void)
{
  TYPE(u32_rdn_sat, 1x2) a = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x2) b = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) r = FN(mmax_ew, u32_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_295 (void)
{
  TYPE(u32_rod_sat, 2x1) a = FN(mzero_m, u32_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 2x1) b = FN(mzero_m, u32_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 2x1) r = FN(mand_ew, u32_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_296 (void)
{
  TYPE(u32_rnu_sat, 1x2) a = FN(mzero_m, u32_rnu_sat, 1x2) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x2) b = FN(mzero_m, u32_rnu_sat, 1x2) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x2) r = FN(mandnot_ew, u32_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_297 (void)
{
  TYPE(u32_rne_sat, 2x1) a = FN(mzero_m, u32_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 2x1) b = FN(mzero_m, u32_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 2x1) r = FN(mor_ew, u32_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_298 (void)
{
  TYPE(u32_rdn_sat, 1x2) a = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x2) b = FN(mzero_m, u32_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x2) r = FN(mornot_ew, u32_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_64_299 (void)
{
  TYPE(u32_rod_sat, 2x1) a = FN(mzero_m, u32_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 2x1) b = FN(mzero_m, u32_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 2x1) r = FN(mxor_ew, u32_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_64_300 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(madd_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_301 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(msub_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_302 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmul_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_303 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mmulneg_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_304 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mabsdiff_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_305 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mhdiff_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_306 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmean_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_307 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mcmpge_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_308 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mcmplt_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_309 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mselge_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_310 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(msellt_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_311 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(msll_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_312 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) r = FN(msll_ew_x, i64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_313 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(msrl_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_314 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) r = FN(msrl_ew_x, i64_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_315 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(msra_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_316 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) r = FN(msra_ew_x, i64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_317 (void)
{
  TYPE(i64_rdn_sat, 1x1) old = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mmulacc_ew, i64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_318 (void)
{
  TYPE(i64_rod_sat, 1x1) old = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmulaccneg_ew, i64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_319 (void)
{
  TYPE(i64_rnu_sat, 1x1) old = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mmuladd_ew, i64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_320 (void)
{
  TYPE(i64_rne_sat, 1x1) old = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mmulsub_ew, i64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_321 (void)
{
  TYPE(i64_rdn_sat, 1x1) old = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mcmovge_ew, i64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_322 (void)
{
  TYPE(i64_rod_sat, 1x1) old = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mcmovlt_ew, i64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_323 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mcolgather_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_324 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mrowgather_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_325 (void)
{
  TYPE(i64_rdn_sat, 1x1) old = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_326 (void)
{
  TYPE(i64_rod_sat, 1x1) old = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mrowscatadd_ew, i64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_327 (void)
{
  TYPE(i64_rnu_sat, 1x1) old = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_328 (void)
{
  TYPE(i64_rne_sat, 1x1) old = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mrowscatmax_ew, i64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_329 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mmin_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_330 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mmax_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_331 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mand_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_332 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) b = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x1) r = FN(mandnot_ew, i64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_333 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) b = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 1x1) r = FN(mor_ew, i64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_334 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x1) r = FN(mornot_ew, i64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_335 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x1) r = FN(mxor_ew, i64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_336 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_337 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_338 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) b = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) pair = FN(mconcat_m, i64_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i64_rod_sat, 1x2) (pair);
  a = FN(mextract, i64_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_339 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x2) pair = FN(mconcat_m, i64_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i64_rnu_sat, 1x2) (pair);
  a = FN(mextract, i64_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_340 (void)
{
  TYPE(i64_rne_sat, 1x1) r = FN(mcolid_ew, i64_rne_sat, 1x1) ();
  KEEP(r);
}
void case_64_341 (void)
{
  TYPE(i64_rdn_sat, 1x1) a = FN(mzero_m, i64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_342 (void)
{
  TYPE(i64_rod_sat, 1x1) a = FN(mzero_m, i64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x1) r = FN(mrowshift_ew_x, i64_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_343 (void)
{
  TYPE(i64_rnu_sat, 1x1) a = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 1x1) b = FN(mzero_m, i64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 1x2) pair = FN(mconcat_m, i64_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i64_rnu_sat, 1x2) (pair);
  a = FN(mextract, i64_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_344 (void)
{
  TYPE(i64_rne_sat, 1x1) a = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x1) b = FN(mzero_m, i64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x2) pair = FN(mconcat_m, i64_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i64_rne_sat, 1x2) (pair);
  a = FN(mextract, i64_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i64_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_345 (void)
{
  TYPE(i64_rdn_sat, 1x1) r = FN(mrowid_ew, i64_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_64_346 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(madd_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_347 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(msub_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_348 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmul_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_349 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mmulneg_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_350 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mabsdiff_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_351 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mhdiff_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_352 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmean_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_353 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mcmpge_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_354 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mcmplt_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_355 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mselge_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_356 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(msellt_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_357 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(msll_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_358 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) r = FN(msll_ew_x, u64_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_359 (void)
{
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(msrl_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_360 (void)
{
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) r = FN(msrl_ew_x, u64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_361 (void)
{
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(msra_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_362 (void)
{
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) r = FN(msra_ew_x, u64_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_363 (void)
{
  TYPE(u64_rne_sat, 1x1) old = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mmulacc_ew, u64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_364 (void)
{
  TYPE(u64_rdn_sat, 1x1) old = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_365 (void)
{
  TYPE(u64_rod_sat, 1x1) old = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mmuladd_ew, u64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_366 (void)
{
  TYPE(u64_rnu_sat, 1x1) old = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mmulsub_ew, u64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_367 (void)
{
  TYPE(u64_rne_sat, 1x1) old = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mcmovge_ew, u64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_368 (void)
{
  TYPE(u64_rdn_sat, 1x1) old = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mcmovlt_ew, u64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_369 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mcolgather_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_370 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mrowgather_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_371 (void)
{
  TYPE(u64_rne_sat, 1x1) old = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 1x1) a = FN(mzero_m, i64_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod, 1x1) b = FN(mzero_m, u64_rod, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mcolscatadd_ew, u64_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_372 (void)
{
  TYPE(u64_rdn_sat, 1x1) old = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rod, 1x1) a = FN(mzero_m, i64_rod, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x1) b = FN(mzero_m, u64_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u64_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_373 (void)
{
  TYPE(u64_rod_sat, 1x1) old = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 1x1) a = FN(mzero_m, i64_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne, 1x1) b = FN(mzero_m, u64_rne, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mcolscatmax_ew, u64_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_374 (void)
{
  TYPE(u64_rnu_sat, 1x1) old = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i64_rne, 1x1) a = FN(mzero_m, i64_rne, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x1) b = FN(mzero_m, u64_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u64_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_375 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mmin_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_376 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mmax_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_377 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mand_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_378 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) b = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x1) r = FN(mandnot_ew, u64_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_379 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) b = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 1x1) r = FN(mor_ew, u64_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_380 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x1) r = FN(mornot_ew, u64_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_381 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x1) r = FN(mxor_ew, u64_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_382 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u64_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_383 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) r = FN(mcolshift_ew_x, u64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_384 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) b = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) pair = FN(mconcat_m, u64_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u64_rdn_sat, 1x2) (pair);
  a = FN(mextract, u64_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_385 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x2) pair = FN(mconcat_m, u64_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u64_rod_sat, 1x2) (pair);
  a = FN(mextract, u64_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_386 (void)
{
  TYPE(u64_rnu_sat, 1x1) r = FN(mcolid_ew, u64_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_64_387 (void)
{
  TYPE(u64_rne_sat, 1x1) a = FN(mzero_m, u64_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u64_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_388 (void)
{
  TYPE(u64_rdn_sat, 1x1) a = FN(mzero_m, u64_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u64_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_389 (void)
{
  TYPE(u64_rod_sat, 1x1) a = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 1x1) b = FN(mzero_m, u64_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 1x2) pair = FN(mconcat_m, u64_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u64_rod_sat, 1x2) (pair);
  a = FN(mextract, u64_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_390 (void)
{
  TYPE(u64_rnu_sat, 1x1) a = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x1) b = FN(mzero_m, u64_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x2) pair = FN(mconcat_m, u64_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u64_rnu_sat, 1x2) (pair);
  a = FN(mextract, u64_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u64_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_391 (void)
{
  TYPE(u64_rne_sat, 1x1) r = FN(mrowid_ew, u64_rne_sat, 1x1) ();
  KEEP(r);
}
void case_64_392 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(madd_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_393 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(msub_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_394 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmul_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_395 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mmulneg_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_396 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mabsdiff_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_397 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mhdiff_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_398 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmean_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_399 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mcmpge_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_400 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mcmplt_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_401 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mselge_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_402 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(msellt_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_403 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(msll_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_404 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) r = FN(msll_ew_x, i128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_405 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(msrl_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_406 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) r = FN(msrl_ew_x, i128_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_407 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(msra_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_408 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) r = FN(msra_ew_x, i128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_409 (void)
{
  TYPE(i128_rdn_sat, 1x1) old = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mmulacc_ew, i128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_410 (void)
{
  TYPE(i128_rod_sat, 1x1) old = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmulaccneg_ew, i128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_411 (void)
{
  TYPE(i128_rnu_sat, 1x1) old = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mmuladd_ew, i128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_412 (void)
{
  TYPE(i128_rne_sat, 1x1) old = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mmulsub_ew, i128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_413 (void)
{
  TYPE(i128_rdn_sat, 1x1) old = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mcmovge_ew, i128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_414 (void)
{
  TYPE(i128_rod_sat, 1x1) old = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mcmovlt_ew, i128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_415 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mcolgather_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_416 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mrowgather_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_417 (void)
{
  TYPE(i128_rdn_sat, 1x1) old = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_418 (void)
{
  TYPE(i128_rod_sat, 1x1) old = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mrowscatadd_ew, i128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_419 (void)
{
  TYPE(i128_rnu_sat, 1x1) old = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_420 (void)
{
  TYPE(i128_rne_sat, 1x1) old = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mrowscatmax_ew, i128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_421 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mmin_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_422 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmax_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_423 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mand_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_424 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) b = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mandnot_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_425 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mor_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_426 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mornot_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_427 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mxor_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_428 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_429 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_430 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x2) pair = FN(mconcat_m, i128_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i128_rod_sat, 1x2) (pair);
  a = FN(mextract, i128_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_431 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x2) pair = FN(mconcat_m, i128_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i128_rnu_sat, 1x2) (pair);
  a = FN(mextract, i128_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_432 (void)
{
  TYPE(i128_rne_sat, 1x1) r = FN(mcolid_ew, i128_rne_sat, 1x1) ();
  KEEP(r);
}
void case_64_433 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_434 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) r = FN(mrowshift_ew_x, i128_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_435 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x2) pair = FN(mconcat_m, i128_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i128_rnu_sat, 1x2) (pair);
  a = FN(mextract, i128_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_436 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) b = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x2) pair = FN(mconcat_m, i128_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i128_rne_sat, 1x2) (pair);
  a = FN(mextract, i128_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_437 (void)
{
  TYPE(i128_rdn_sat, 1x1) r = FN(mrowid_ew, i128_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_64_438 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(madd_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_439 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(msub_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_440 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmul_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_441 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mmulneg_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_442 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mabsdiff_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_443 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mhdiff_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_444 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmean_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_445 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mcmpge_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_446 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mcmplt_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_447 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mselge_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_448 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(msellt_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_449 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(msll_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_450 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) r = FN(msll_ew_x, u128_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_451 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(msrl_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_452 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) r = FN(msrl_ew_x, u128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_453 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(msra_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_454 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) r = FN(msra_ew_x, u128_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_455 (void)
{
  TYPE(u128_rne_sat, 1x1) old = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mmulacc_ew, u128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_456 (void)
{
  TYPE(u128_rdn_sat, 1x1) old = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_457 (void)
{
  TYPE(u128_rod_sat, 1x1) old = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mmuladd_ew, u128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_458 (void)
{
  TYPE(u128_rnu_sat, 1x1) old = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mmulsub_ew, u128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_459 (void)
{
  TYPE(u128_rne_sat, 1x1) old = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mcmovge_ew, u128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_460 (void)
{
  TYPE(u128_rdn_sat, 1x1) old = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mcmovlt_ew, u128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_461 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mcolgather_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_462 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mrowgather_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_463 (void)
{
  TYPE(u128_rne_sat, 1x1) old = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mcolscatadd_ew, u128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_464 (void)
{
  TYPE(u128_rdn_sat, 1x1) old = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_465 (void)
{
  TYPE(u128_rod_sat, 1x1) old = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mcolscatmax_ew, u128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_466 (void)
{
  TYPE(u128_rnu_sat, 1x1) old = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_64_467 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mmin_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_468 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmax_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_469 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mand_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_470 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) b = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mandnot_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_471 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mor_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_472 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mornot_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_473 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mxor_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_64_474 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u128_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_475 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) r = FN(mcolshift_ew_x, u128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_476 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x2) pair = FN(mconcat_m, u128_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u128_rdn_sat, 1x2) (pair);
  a = FN(mextract, u128_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_477 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x2) pair = FN(mconcat_m, u128_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u128_rod_sat, 1x2) (pair);
  a = FN(mextract, u128_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_478 (void)
{
  TYPE(u128_rnu_sat, 1x1) r = FN(mcolid_ew, u128_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_64_479 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_480 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_64_481 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x2) pair = FN(mconcat_m, u128_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u128_rod_sat, 1x2) (pair);
  a = FN(mextract, u128_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_482 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) b = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x2) pair = FN(mconcat_m, u128_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u128_rnu_sat, 1x2) (pair);
  a = FN(mextract, u128_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_64_483 (void)
{
  TYPE(u128_rne_sat, 1x1) r = FN(mrowid_ew, u128_rne_sat, 1x1) ();
  KEEP(r);
}
#endif

#if TEST_UDS == 128
void case_128_0 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne, 1x32) r = FN(madd_ew, i4_rne, 1x32) (a, b);
  KEEP(r);
}
void case_128_1 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 32x1) r = FN(msub_ew, i4_rdn, 32x1) (a, b);
  KEEP(r);
}
void case_128_2 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod, 1x32) r = FN(mmul_ew, i4_rod, 1x32) (a, b);
  KEEP(r);
}
void case_128_3 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 32x1) r = FN(mmulneg_ew, i4_rnu, 32x1) (a, b);
  KEEP(r);
}
void case_128_4 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne, 1x32) r = FN(mabsdiff_ew, i4_rne, 1x32) (a, b);
  KEEP(r);
}
void case_128_5 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 32x1) r = FN(mhdiff_ew, i4_rdn, 32x1) (a, b);
  KEEP(r);
}
void case_128_6 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod, 1x32) r = FN(mmean_ew, i4_rod, 1x32) (a, b);
  KEEP(r);
}
void case_128_7 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 32x1) r = FN(mcmpge_ew, i4_rnu, 32x1) (a, b);
  KEEP(r);
}
void case_128_8 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne, 1x32) r = FN(mcmplt_ew, i4_rne, 1x32) (a, b);
  KEEP(r);
}
void case_128_9 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 32x1) b = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 32x1) r = FN(mselge_ew, i4_rdn, 32x1) (a, b);
  KEEP(r);
}
void case_128_10 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod, 1x32) b = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod, 1x32) r = FN(msellt_ew, i4_rod, 1x32) (a, b);
  KEEP(r);
}
void case_128_11 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 32x1) r = FN(msll_ew, i4_rnu, 32x1) (a, b);
  KEEP(r);
}
void case_128_12 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(i4_rne, 1x32) r = FN(msll_ew_x, i4_rne, 1x32) (a, 1);
  KEEP(r);
}
void case_128_13 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 32x1) r = FN(msrl_ew, i4_rdn, 32x1) (a, b);
  KEEP(r);
}
void case_128_14 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod, 1x32) r = FN(msrl_ew_x, i4_rod, 1x32) (a, 1);
  KEEP(r);
}
void case_128_15 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 32x1) r = FN(msra_ew, i4_rnu, 32x1) (a, b);
  KEEP(r);
}
void case_128_16 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(i4_rne, 1x32) r = FN(msra_ew_x, i4_rne, 1x32) (a, 1);
  KEEP(r);
}
void case_128_17 (void)
{
  TYPE(i4_rdn, 32x1) old = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 32x1) r = FN(mmulacc_ew, i4_rdn, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_18 (void)
{
  TYPE(i4_rod, 1x32) old = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(old);
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod, 1x32) r = FN(mmulaccneg_ew, i4_rod, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_19 (void)
{
  TYPE(i4_rnu, 32x1) old = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 32x1) r = FN(mmuladd_ew, i4_rnu, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_20 (void)
{
  TYPE(i4_rne, 1x32) old = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(old);
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne, 1x32) r = FN(mmulsub_ew, i4_rne, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_21 (void)
{
  TYPE(i4_rdn, 32x1) old = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 32x1) b = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 32x1) r = FN(mcmovge_ew, i4_rdn, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_22 (void)
{
  TYPE(i4_rod, 1x32) old = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(old);
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod, 1x32) b = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod, 1x32) r = FN(mcmovlt_ew, i4_rod, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_23 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 32x1) b = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 32x1) r = FN(mmin_ew, i4_rdn, 32x1) (a, b);
  KEEP(r);
}
void case_128_24 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod, 1x32) b = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod, 1x32) r = FN(mmax_ew, i4_rod, 1x32) (a, b);
  KEEP(r);
}
void case_128_25 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 32x1) b = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 32x1) r = FN(mand_ew, i4_rnu, 32x1) (a, b);
  KEEP(r);
}
void case_128_26 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(i4_rne, 1x32) b = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne, 1x32) r = FN(mandnot_ew, i4_rne, 1x32) (a, b);
  KEEP(r);
}
void case_128_27 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(i4_rdn, 32x1) b = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn, 32x1) r = FN(mor_ew, i4_rdn, 32x1) (a, b);
  KEEP(r);
}
void case_128_28 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod, 1x32) b = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod, 1x32) r = FN(mornot_ew, i4_rod, 1x32) (a, b);
  KEEP(r);
}
void case_128_29 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(i4_rnu, 32x1) b = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu, 32x1) r = FN(mxor_ew, i4_rnu, 32x1) (a, b);
  KEEP(r);
}
void case_128_30 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x32) r = FN(madd_ew, u4_rnu, 1x32) (a, b);
  KEEP(r);
}
void case_128_31 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne, 32x1) r = FN(msub_ew, u4_rne, 32x1) (a, b);
  KEEP(r);
}
void case_128_32 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x32) r = FN(mmul_ew, u4_rdn, 1x32) (a, b);
  KEEP(r);
}
void case_128_33 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod, 32x1) r = FN(mmulneg_ew, u4_rod, 32x1) (a, b);
  KEEP(r);
}
void case_128_34 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x32) r = FN(mabsdiff_ew, u4_rnu, 1x32) (a, b);
  KEEP(r);
}
void case_128_35 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne, 32x1) r = FN(mhdiff_ew, u4_rne, 32x1) (a, b);
  KEEP(r);
}
void case_128_36 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x32) r = FN(mmean_ew, u4_rdn, 1x32) (a, b);
  KEEP(r);
}
void case_128_37 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod, 32x1) r = FN(mcmpge_ew, u4_rod, 32x1) (a, b);
  KEEP(r);
}
void case_128_38 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x32) r = FN(mcmplt_ew, u4_rnu, 1x32) (a, b);
  KEEP(r);
}
void case_128_39 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne, 32x1) r = FN(mselge_ew, u4_rne, 32x1) (a, b);
  KEEP(r);
}
void case_128_40 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x32) r = FN(msellt_ew, u4_rdn, 1x32) (a, b);
  KEEP(r);
}
void case_128_41 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod, 32x1) r = FN(msll_ew, u4_rod, 32x1) (a, b);
  KEEP(r);
}
void case_128_42 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) r = FN(msll_ew_x, u4_rnu, 1x32) (a, 1);
  KEEP(r);
}
void case_128_43 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne, 32x1) r = FN(msrl_ew, u4_rne, 32x1) (a, b);
  KEEP(r);
}
void case_128_44 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) r = FN(msrl_ew_x, u4_rdn, 1x32) (a, 1);
  KEEP(r);
}
void case_128_45 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod, 32x1) r = FN(msra_ew, u4_rod, 32x1) (a, b);
  KEEP(r);
}
void case_128_46 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) r = FN(msra_ew_x, u4_rnu, 1x32) (a, 1);
  KEEP(r);
}
void case_128_47 (void)
{
  TYPE(u4_rne, 32x1) old = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne, 32x1) r = FN(mmulacc_ew, u4_rne, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_48 (void)
{
  TYPE(u4_rdn, 1x32) old = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(old);
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x32) r = FN(mmulaccneg_ew, u4_rdn, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_49 (void)
{
  TYPE(u4_rod, 32x1) old = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod, 32x1) r = FN(mmuladd_ew, u4_rod, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_50 (void)
{
  TYPE(u4_rnu, 1x32) old = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(old);
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x32) r = FN(mmulsub_ew, u4_rnu, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_51 (void)
{
  TYPE(u4_rne, 32x1) old = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne, 32x1) r = FN(mcmovge_ew, u4_rne, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_52 (void)
{
  TYPE(u4_rdn, 1x32) old = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(old);
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x32) r = FN(mcmovlt_ew, u4_rdn, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_53 (void)
{
  TYPE(u4_rne, 32x1) a = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne, 32x1) r = FN(mmin_ew, u4_rne, 32x1) (a, b);
  KEEP(r);
}
void case_128_54 (void)
{
  TYPE(u4_rdn, 1x32) a = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x32) r = FN(mmax_ew, u4_rdn, 1x32) (a, b);
  KEEP(r);
}
void case_128_55 (void)
{
  TYPE(u4_rod, 32x1) a = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod, 32x1) r = FN(mand_ew, u4_rod, 32x1) (a, b);
  KEEP(r);
}
void case_128_56 (void)
{
  TYPE(u4_rnu, 1x32) a = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu, 1x32) r = FN(mandnot_ew, u4_rnu, 1x32) (a, b);
  KEEP(r);
}
void case_128_57 (void)
{
  TYPE(u4_rne, 32x1) a = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne, 32x1) r = FN(mor_ew, u4_rne, 32x1) (a, b);
  KEEP(r);
}
void case_128_58 (void)
{
  TYPE(u4_rdn, 1x32) a = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn, 1x32) r = FN(mornot_ew, u4_rdn, 1x32) (a, b);
  KEEP(r);
}
void case_128_59 (void)
{
  TYPE(u4_rod, 32x1) a = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod, 32x1) r = FN(mxor_ew, u4_rod, 32x1) (a, b);
  KEEP(r);
}
void case_128_60 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x32) r = FN(madd_ew, i4_rne_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_61 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 32x1) r = FN(msub_ew, i4_rdn_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_62 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x32) r = FN(mmul_ew, i4_rod_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_63 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 32x1) r = FN(mmulneg_ew, i4_rnu_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_64 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x32) r = FN(mabsdiff_ew, i4_rne_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_65 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 32x1) r = FN(mhdiff_ew, i4_rdn_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_66 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x32) r = FN(mmean_ew, i4_rod_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_67 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 32x1) r = FN(mcmpge_ew, i4_rnu_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_68 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x32) r = FN(mcmplt_ew, i4_rne_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_69 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 32x1) b = FN(mzero_m, i4_rdn_sat, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 32x1) r = FN(mselge_ew, i4_rdn_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_70 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x32) b = FN(mzero_m, i4_rod_sat, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x32) r = FN(msellt_ew, i4_rod_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_71 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 32x1) r = FN(msll_ew, i4_rnu_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_72 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x32) r = FN(msll_ew_x, i4_rne_sat, 1x32) (a, 1);
  KEEP(r);
}
void case_128_73 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 32x1) r = FN(msrl_ew, i4_rdn_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_74 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x32) r = FN(msrl_ew_x, i4_rod_sat, 1x32) (a, 1);
  KEEP(r);
}
void case_128_75 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 32x1) r = FN(msra_ew, i4_rnu_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_76 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x32) r = FN(msra_ew_x, i4_rne_sat, 1x32) (a, 1);
  KEEP(r);
}
void case_128_77 (void)
{
  TYPE(i4_rdn_sat, 32x1) old = FN(mzero_m, i4_rdn_sat, 32x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 32x1) r = FN(mmulacc_ew, i4_rdn_sat, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_78 (void)
{
  TYPE(i4_rod_sat, 1x32) old = FN(mzero_m, i4_rod_sat, 1x32) ();
  CHANGE(old);
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x32) r = FN(mmulaccneg_ew, i4_rod_sat, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_79 (void)
{
  TYPE(i4_rnu_sat, 32x1) old = FN(mzero_m, i4_rnu_sat, 32x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 32x1) r = FN(mmuladd_ew, i4_rnu_sat, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_80 (void)
{
  TYPE(i4_rne_sat, 1x32) old = FN(mzero_m, i4_rne_sat, 1x32) ();
  CHANGE(old);
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x32) r = FN(mmulsub_ew, i4_rne_sat, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_81 (void)
{
  TYPE(i4_rdn_sat, 32x1) old = FN(mzero_m, i4_rdn_sat, 32x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 32x1) b = FN(mzero_m, i4_rdn_sat, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 32x1) r = FN(mcmovge_ew, i4_rdn_sat, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_82 (void)
{
  TYPE(i4_rod_sat, 1x32) old = FN(mzero_m, i4_rod_sat, 1x32) ();
  CHANGE(old);
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x32) b = FN(mzero_m, i4_rod_sat, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x32) r = FN(mcmovlt_ew, i4_rod_sat, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_83 (void)
{
  TYPE(i4_rdn_sat, 32x1) a = FN(mzero_m, i4_rdn_sat, 32x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 32x1) b = FN(mzero_m, i4_rdn_sat, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 32x1) r = FN(mmin_ew, i4_rdn_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_84 (void)
{
  TYPE(i4_rod_sat, 1x32) a = FN(mzero_m, i4_rod_sat, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x32) b = FN(mzero_m, i4_rod_sat, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x32) r = FN(mmax_ew, i4_rod_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_85 (void)
{
  TYPE(i4_rnu_sat, 32x1) a = FN(mzero_m, i4_rnu_sat, 32x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 32x1) b = FN(mzero_m, i4_rnu_sat, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 32x1) r = FN(mand_ew, i4_rnu_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_86 (void)
{
  TYPE(i4_rne_sat, 1x32) a = FN(mzero_m, i4_rne_sat, 1x32) ();
  CHANGE(a);
  TYPE(i4_rne_sat, 1x32) b = FN(mzero_m, i4_rne_sat, 1x32) ();
  CHANGE(b);
  TYPE(i4_rne_sat, 1x32) r = FN(mandnot_ew, i4_rne_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_87 (void)
{
  TYPE(i4_rdn_sat, 32x1) a = FN(mzero_m, i4_rdn_sat, 32x1) ();
  CHANGE(a);
  TYPE(i4_rdn_sat, 32x1) b = FN(mzero_m, i4_rdn_sat, 32x1) ();
  CHANGE(b);
  TYPE(i4_rdn_sat, 32x1) r = FN(mor_ew, i4_rdn_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_88 (void)
{
  TYPE(i4_rod_sat, 1x32) a = FN(mzero_m, i4_rod_sat, 1x32) ();
  CHANGE(a);
  TYPE(i4_rod_sat, 1x32) b = FN(mzero_m, i4_rod_sat, 1x32) ();
  CHANGE(b);
  TYPE(i4_rod_sat, 1x32) r = FN(mornot_ew, i4_rod_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_89 (void)
{
  TYPE(i4_rnu_sat, 32x1) a = FN(mzero_m, i4_rnu_sat, 32x1) ();
  CHANGE(a);
  TYPE(i4_rnu_sat, 32x1) b = FN(mzero_m, i4_rnu_sat, 32x1) ();
  CHANGE(b);
  TYPE(i4_rnu_sat, 32x1) r = FN(mxor_ew, i4_rnu_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_90 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x32) r = FN(madd_ew, u4_rnu_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_91 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 32x1) r = FN(msub_ew, u4_rne_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_92 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x32) r = FN(mmul_ew, u4_rdn_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_93 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 32x1) r = FN(mmulneg_ew, u4_rod_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_94 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x32) r = FN(mabsdiff_ew, u4_rnu_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_95 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 32x1) r = FN(mhdiff_ew, u4_rne_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_96 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x32) r = FN(mmean_ew, u4_rdn_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_97 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 32x1) r = FN(mcmpge_ew, u4_rod_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_98 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x32) r = FN(mcmplt_ew, u4_rnu_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_99 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 32x1) b = FN(mzero_m, u4_rne_sat, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 32x1) r = FN(mselge_ew, u4_rne_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_100 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x32) b = FN(mzero_m, u4_rdn_sat, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x32) r = FN(msellt_ew, u4_rdn_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_101 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 32x1) r = FN(msll_ew, u4_rod_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_102 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x32) r = FN(msll_ew_x, u4_rnu_sat, 1x32) (a, 1);
  KEEP(r);
}
void case_128_103 (void)
{
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 32x1) r = FN(msrl_ew, u4_rne_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_104 (void)
{
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x32) r = FN(msrl_ew_x, u4_rdn_sat, 1x32) (a, 1);
  KEEP(r);
}
void case_128_105 (void)
{
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 32x1) r = FN(msra_ew, u4_rod_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_106 (void)
{
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x32) r = FN(msra_ew_x, u4_rnu_sat, 1x32) (a, 1);
  KEEP(r);
}
void case_128_107 (void)
{
  TYPE(u4_rne_sat, 32x1) old = FN(mzero_m, u4_rne_sat, 32x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod, 32x1) b = FN(mzero_m, u4_rod, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 32x1) r = FN(mmulacc_ew, u4_rne_sat, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_108 (void)
{
  TYPE(u4_rdn_sat, 1x32) old = FN(mzero_m, u4_rdn_sat, 1x32) ();
  CHANGE(old);
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu, 1x32) b = FN(mzero_m, u4_rnu, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x32) r = FN(mmulaccneg_ew, u4_rdn_sat, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_109 (void)
{
  TYPE(u4_rod_sat, 32x1) old = FN(mzero_m, u4_rod_sat, 32x1) ();
  CHANGE(old);
  TYPE(i4_rnu, 32x1) a = FN(mzero_m, i4_rnu, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne, 32x1) b = FN(mzero_m, u4_rne, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 32x1) r = FN(mmuladd_ew, u4_rod_sat, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_110 (void)
{
  TYPE(u4_rnu_sat, 1x32) old = FN(mzero_m, u4_rnu_sat, 1x32) ();
  CHANGE(old);
  TYPE(i4_rne, 1x32) a = FN(mzero_m, i4_rne, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn, 1x32) b = FN(mzero_m, u4_rdn, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x32) r = FN(mmulsub_ew, u4_rnu_sat, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_111 (void)
{
  TYPE(u4_rne_sat, 32x1) old = FN(mzero_m, u4_rne_sat, 32x1) ();
  CHANGE(old);
  TYPE(i4_rdn, 32x1) a = FN(mzero_m, i4_rdn, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 32x1) b = FN(mzero_m, u4_rne_sat, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 32x1) r = FN(mcmovge_ew, u4_rne_sat, 32x1) (old, a, b);
  KEEP(r);
}
void case_128_112 (void)
{
  TYPE(u4_rdn_sat, 1x32) old = FN(mzero_m, u4_rdn_sat, 1x32) ();
  CHANGE(old);
  TYPE(i4_rod, 1x32) a = FN(mzero_m, i4_rod, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x32) b = FN(mzero_m, u4_rdn_sat, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x32) r = FN(mcmovlt_ew, u4_rdn_sat, 1x32) (old, a, b);
  KEEP(r);
}
void case_128_113 (void)
{
  TYPE(u4_rne_sat, 32x1) a = FN(mzero_m, u4_rne_sat, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 32x1) b = FN(mzero_m, u4_rne_sat, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 32x1) r = FN(mmin_ew, u4_rne_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_114 (void)
{
  TYPE(u4_rdn_sat, 1x32) a = FN(mzero_m, u4_rdn_sat, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x32) b = FN(mzero_m, u4_rdn_sat, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x32) r = FN(mmax_ew, u4_rdn_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_115 (void)
{
  TYPE(u4_rod_sat, 32x1) a = FN(mzero_m, u4_rod_sat, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 32x1) b = FN(mzero_m, u4_rod_sat, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 32x1) r = FN(mand_ew, u4_rod_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_116 (void)
{
  TYPE(u4_rnu_sat, 1x32) a = FN(mzero_m, u4_rnu_sat, 1x32) ();
  CHANGE(a);
  TYPE(u4_rnu_sat, 1x32) b = FN(mzero_m, u4_rnu_sat, 1x32) ();
  CHANGE(b);
  TYPE(u4_rnu_sat, 1x32) r = FN(mandnot_ew, u4_rnu_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_117 (void)
{
  TYPE(u4_rne_sat, 32x1) a = FN(mzero_m, u4_rne_sat, 32x1) ();
  CHANGE(a);
  TYPE(u4_rne_sat, 32x1) b = FN(mzero_m, u4_rne_sat, 32x1) ();
  CHANGE(b);
  TYPE(u4_rne_sat, 32x1) r = FN(mor_ew, u4_rne_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_118 (void)
{
  TYPE(u4_rdn_sat, 1x32) a = FN(mzero_m, u4_rdn_sat, 1x32) ();
  CHANGE(a);
  TYPE(u4_rdn_sat, 1x32) b = FN(mzero_m, u4_rdn_sat, 1x32) ();
  CHANGE(b);
  TYPE(u4_rdn_sat, 1x32) r = FN(mornot_ew, u4_rdn_sat, 1x32) (a, b);
  KEEP(r);
}
void case_128_119 (void)
{
  TYPE(u4_rod_sat, 32x1) a = FN(mzero_m, u4_rod_sat, 32x1) ();
  CHANGE(a);
  TYPE(u4_rod_sat, 32x1) b = FN(mzero_m, u4_rod_sat, 32x1) ();
  CHANGE(b);
  TYPE(u4_rod_sat, 32x1) r = FN(mxor_ew, u4_rod_sat, 32x1) (a, b);
  KEEP(r);
}
void case_128_120 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x16) b = FN(mzero_m, u8_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x16) r = FN(madd_ew, i8_rne_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_121 (void)
{
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod, 16x1) b = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 16x1) r = FN(msub_ew, i8_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_122 (void)
{
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x16) b = FN(mzero_m, u8_rnu, 1x16) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x16) r = FN(mmul_ew, i8_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_123 (void)
{
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 16x1) r = FN(mmulneg_ew, i8_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_124 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x16) b = FN(mzero_m, u8_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x16) r = FN(mabsdiff_ew, i8_rne_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_125 (void)
{
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod, 16x1) b = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 16x1) r = FN(mhdiff_ew, i8_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_126 (void)
{
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x16) b = FN(mzero_m, u8_rnu, 1x16) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x16) r = FN(mmean_ew, i8_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_127 (void)
{
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 16x1) r = FN(mcmpge_ew, i8_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_128 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x16) b = FN(mzero_m, u8_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x16) r = FN(mcmplt_ew, i8_rne_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_129 (void)
{
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 16x1) b = FN(mzero_m, i8_rdn_sat, 16x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 16x1) r = FN(mselge_ew, i8_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_130 (void)
{
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x16) b = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x16) r = FN(msellt_ew, i8_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_131 (void)
{
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 16x1) r = FN(msll_ew, i8_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_132 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x16) r = FN(msll_ew_x, i8_rne_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_128_133 (void)
{
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod, 16x1) b = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 16x1) r = FN(msrl_ew, i8_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_134 (void)
{
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x16) r = FN(msrl_ew_x, i8_rod_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_128_135 (void)
{
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 16x1) r = FN(msra_ew, i8_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_136 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x16) r = FN(msra_ew_x, i8_rne_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_128_137 (void)
{
  TYPE(i8_rdn_sat, 16x1) old = FN(mzero_m, i8_rdn_sat, 16x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod, 16x1) b = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 16x1) r = FN(mmulacc_ew, i8_rdn_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_128_138 (void)
{
  TYPE(i8_rod_sat, 1x16) old = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE(old);
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x16) b = FN(mzero_m, u8_rnu, 1x16) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x16) r = FN(mmulaccneg_ew, i8_rod_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_128_139 (void)
{
  TYPE(i8_rnu_sat, 16x1) old = FN(mzero_m, i8_rnu_sat, 16x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 16x1) r = FN(mmuladd_ew, i8_rnu_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_128_140 (void)
{
  TYPE(i8_rne_sat, 1x16) old = FN(mzero_m, i8_rne_sat, 1x16) ();
  CHANGE(old);
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x16) b = FN(mzero_m, u8_rdn, 1x16) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x16) r = FN(mmulsub_ew, i8_rne_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_128_141 (void)
{
  TYPE(i8_rdn_sat, 16x1) old = FN(mzero_m, i8_rdn_sat, 16x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 16x1) b = FN(mzero_m, i8_rdn_sat, 16x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 16x1) r = FN(mcmovge_ew, i8_rdn_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_128_142 (void)
{
  TYPE(i8_rod_sat, 1x16) old = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE(old);
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x16) b = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x16) r = FN(mcmovlt_ew, i8_rod_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_128_143 (void)
{
  TYPE(i8_rdn_sat, 16x1) a = FN(mzero_m, i8_rdn_sat, 16x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 16x1) b = FN(mzero_m, i8_rdn_sat, 16x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 16x1) r = FN(mmin_ew, i8_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_144 (void)
{
  TYPE(i8_rod_sat, 1x16) a = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x16) b = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x16) r = FN(mmax_ew, i8_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_145 (void)
{
  TYPE(i8_rnu_sat, 16x1) a = FN(mzero_m, i8_rnu_sat, 16x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 16x1) b = FN(mzero_m, i8_rnu_sat, 16x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 16x1) r = FN(mand_ew, i8_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_146 (void)
{
  TYPE(i8_rne_sat, 1x16) a = FN(mzero_m, i8_rne_sat, 1x16) ();
  CHANGE(a);
  TYPE(i8_rne_sat, 1x16) b = FN(mzero_m, i8_rne_sat, 1x16) ();
  CHANGE(b);
  TYPE(i8_rne_sat, 1x16) r = FN(mandnot_ew, i8_rne_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_147 (void)
{
  TYPE(i8_rdn_sat, 16x1) a = FN(mzero_m, i8_rdn_sat, 16x1) ();
  CHANGE(a);
  TYPE(i8_rdn_sat, 16x1) b = FN(mzero_m, i8_rdn_sat, 16x1) ();
  CHANGE(b);
  TYPE(i8_rdn_sat, 16x1) r = FN(mor_ew, i8_rdn_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_148 (void)
{
  TYPE(i8_rod_sat, 1x16) a = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE(a);
  TYPE(i8_rod_sat, 1x16) b = FN(mzero_m, i8_rod_sat, 1x16) ();
  CHANGE(b);
  TYPE(i8_rod_sat, 1x16) r = FN(mornot_ew, i8_rod_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_149 (void)
{
  TYPE(i8_rnu_sat, 16x1) a = FN(mzero_m, i8_rnu_sat, 16x1) ();
  CHANGE(a);
  TYPE(i8_rnu_sat, 16x1) b = FN(mzero_m, i8_rnu_sat, 16x1) ();
  CHANGE(b);
  TYPE(i8_rnu_sat, 16x1) r = FN(mxor_ew, i8_rnu_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_150 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x16) b = FN(mzero_m, u8_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x16) r = FN(madd_ew, u8_rnu_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_151 (void)
{
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod, 16x1) b = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 16x1) r = FN(msub_ew, u8_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_152 (void)
{
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x16) b = FN(mzero_m, u8_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x16) r = FN(mmul_ew, u8_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_153 (void)
{
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 16x1) r = FN(mmulneg_ew, u8_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_154 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x16) b = FN(mzero_m, u8_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x16) r = FN(mabsdiff_ew, u8_rnu_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_155 (void)
{
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod, 16x1) b = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 16x1) r = FN(mhdiff_ew, u8_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_156 (void)
{
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x16) b = FN(mzero_m, u8_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x16) r = FN(mmean_ew, u8_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_157 (void)
{
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 16x1) r = FN(mcmpge_ew, u8_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_158 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x16) b = FN(mzero_m, u8_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x16) r = FN(mcmplt_ew, u8_rnu_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_159 (void)
{
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 16x1) b = FN(mzero_m, u8_rne_sat, 16x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 16x1) r = FN(mselge_ew, u8_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_160 (void)
{
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x16) b = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x16) r = FN(msellt_ew, u8_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_161 (void)
{
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 16x1) r = FN(msll_ew, u8_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_162 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x16) r = FN(msll_ew_x, u8_rnu_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_128_163 (void)
{
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod, 16x1) b = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 16x1) r = FN(msrl_ew, u8_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_164 (void)
{
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x16) r = FN(msrl_ew_x, u8_rdn_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_128_165 (void)
{
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 16x1) r = FN(msra_ew, u8_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_166 (void)
{
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x16) r = FN(msra_ew_x, u8_rnu_sat, 1x16) (a, 1);
  KEEP(r);
}
void case_128_167 (void)
{
  TYPE(u8_rne_sat, 16x1) old = FN(mzero_m, u8_rne_sat, 16x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod, 16x1) b = FN(mzero_m, u8_rod, 16x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 16x1) r = FN(mmulacc_ew, u8_rne_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_128_168 (void)
{
  TYPE(u8_rdn_sat, 1x16) old = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE(old);
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(u8_rnu, 1x16) b = FN(mzero_m, u8_rnu, 1x16) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x16) r = FN(mmulaccneg_ew, u8_rdn_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_128_169 (void)
{
  TYPE(u8_rod_sat, 16x1) old = FN(mzero_m, u8_rod_sat, 16x1) ();
  CHANGE(old);
  TYPE(i8_rnu, 16x1) a = FN(mzero_m, i8_rnu, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne, 16x1) b = FN(mzero_m, u8_rne, 16x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 16x1) r = FN(mmuladd_ew, u8_rod_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_128_170 (void)
{
  TYPE(u8_rnu_sat, 1x16) old = FN(mzero_m, u8_rnu_sat, 1x16) ();
  CHANGE(old);
  TYPE(i8_rne, 1x16) a = FN(mzero_m, i8_rne, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn, 1x16) b = FN(mzero_m, u8_rdn, 1x16) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x16) r = FN(mmulsub_ew, u8_rnu_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_128_171 (void)
{
  TYPE(u8_rne_sat, 16x1) old = FN(mzero_m, u8_rne_sat, 16x1) ();
  CHANGE(old);
  TYPE(i8_rdn, 16x1) a = FN(mzero_m, i8_rdn, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 16x1) b = FN(mzero_m, u8_rne_sat, 16x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 16x1) r = FN(mcmovge_ew, u8_rne_sat, 16x1) (old, a, b);
  KEEP(r);
}
void case_128_172 (void)
{
  TYPE(u8_rdn_sat, 1x16) old = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE(old);
  TYPE(i8_rod, 1x16) a = FN(mzero_m, i8_rod, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x16) b = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x16) r = FN(mcmovlt_ew, u8_rdn_sat, 1x16) (old, a, b);
  KEEP(r);
}
void case_128_173 (void)
{
  TYPE(u8_rne_sat, 16x1) a = FN(mzero_m, u8_rne_sat, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 16x1) b = FN(mzero_m, u8_rne_sat, 16x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 16x1) r = FN(mmin_ew, u8_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_174 (void)
{
  TYPE(u8_rdn_sat, 1x16) a = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x16) b = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x16) r = FN(mmax_ew, u8_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_175 (void)
{
  TYPE(u8_rod_sat, 16x1) a = FN(mzero_m, u8_rod_sat, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 16x1) b = FN(mzero_m, u8_rod_sat, 16x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 16x1) r = FN(mand_ew, u8_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_176 (void)
{
  TYPE(u8_rnu_sat, 1x16) a = FN(mzero_m, u8_rnu_sat, 1x16) ();
  CHANGE(a);
  TYPE(u8_rnu_sat, 1x16) b = FN(mzero_m, u8_rnu_sat, 1x16) ();
  CHANGE(b);
  TYPE(u8_rnu_sat, 1x16) r = FN(mandnot_ew, u8_rnu_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_177 (void)
{
  TYPE(u8_rne_sat, 16x1) a = FN(mzero_m, u8_rne_sat, 16x1) ();
  CHANGE(a);
  TYPE(u8_rne_sat, 16x1) b = FN(mzero_m, u8_rne_sat, 16x1) ();
  CHANGE(b);
  TYPE(u8_rne_sat, 16x1) r = FN(mor_ew, u8_rne_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_178 (void)
{
  TYPE(u8_rdn_sat, 1x16) a = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE(a);
  TYPE(u8_rdn_sat, 1x16) b = FN(mzero_m, u8_rdn_sat, 1x16) ();
  CHANGE(b);
  TYPE(u8_rdn_sat, 1x16) r = FN(mornot_ew, u8_rdn_sat, 1x16) (a, b);
  KEEP(r);
}
void case_128_179 (void)
{
  TYPE(u8_rod_sat, 16x1) a = FN(mzero_m, u8_rod_sat, 16x1) ();
  CHANGE(a);
  TYPE(u8_rod_sat, 16x1) b = FN(mzero_m, u8_rod_sat, 16x1) ();
  CHANGE(b);
  TYPE(u8_rod_sat, 16x1) r = FN(mxor_ew, u8_rod_sat, 16x1) (a, b);
  KEEP(r);
}
void case_128_180 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x8) b = FN(mzero_m, u16_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x8) r = FN(madd_ew, i16_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_181 (void)
{
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod, 8x1) b = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 8x1) r = FN(msub_ew, i16_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_182 (void)
{
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x8) b = FN(mzero_m, u16_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x8) r = FN(mmul_ew, i16_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_183 (void)
{
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 8x1) r = FN(mmulneg_ew, i16_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_184 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x8) b = FN(mzero_m, u16_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x8) r = FN(mabsdiff_ew, i16_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_185 (void)
{
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod, 8x1) b = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 8x1) r = FN(mhdiff_ew, i16_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_186 (void)
{
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x8) b = FN(mzero_m, u16_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x8) r = FN(mmean_ew, i16_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_187 (void)
{
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 8x1) r = FN(mcmpge_ew, i16_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_188 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x8) b = FN(mzero_m, u16_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x8) r = FN(mcmplt_ew, i16_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_189 (void)
{
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 8x1) b = FN(mzero_m, i16_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 8x1) r = FN(mselge_ew, i16_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_190 (void)
{
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x8) b = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x8) r = FN(msellt_ew, i16_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_191 (void)
{
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 8x1) r = FN(msll_ew, i16_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_192 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x8) r = FN(msll_ew_x, i16_rne_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_128_193 (void)
{
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod, 8x1) b = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 8x1) r = FN(msrl_ew, i16_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_194 (void)
{
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x8) r = FN(msrl_ew_x, i16_rod_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_128_195 (void)
{
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 8x1) r = FN(msra_ew, i16_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_196 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x8) r = FN(msra_ew_x, i16_rne_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_128_197 (void)
{
  TYPE(i16_rdn_sat, 8x1) old = FN(mzero_m, i16_rdn_sat, 8x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod, 8x1) b = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 8x1) r = FN(mmulacc_ew, i16_rdn_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_128_198 (void)
{
  TYPE(i16_rod_sat, 1x8) old = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE(old);
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x8) b = FN(mzero_m, u16_rnu, 1x8) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x8) r = FN(mmulaccneg_ew, i16_rod_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_128_199 (void)
{
  TYPE(i16_rnu_sat, 8x1) old = FN(mzero_m, i16_rnu_sat, 8x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 8x1) r = FN(mmuladd_ew, i16_rnu_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_128_200 (void)
{
  TYPE(i16_rne_sat, 1x8) old = FN(mzero_m, i16_rne_sat, 1x8) ();
  CHANGE(old);
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x8) b = FN(mzero_m, u16_rdn, 1x8) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x8) r = FN(mmulsub_ew, i16_rne_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_128_201 (void)
{
  TYPE(i16_rdn_sat, 8x1) old = FN(mzero_m, i16_rdn_sat, 8x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 8x1) b = FN(mzero_m, i16_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 8x1) r = FN(mcmovge_ew, i16_rdn_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_128_202 (void)
{
  TYPE(i16_rod_sat, 1x8) old = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE(old);
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x8) b = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x8) r = FN(mcmovlt_ew, i16_rod_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_128_203 (void)
{
  TYPE(i16_rdn_sat, 8x1) a = FN(mzero_m, i16_rdn_sat, 8x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 8x1) b = FN(mzero_m, i16_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 8x1) r = FN(mmin_ew, i16_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_204 (void)
{
  TYPE(i16_rod_sat, 1x8) a = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x8) b = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x8) r = FN(mmax_ew, i16_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_205 (void)
{
  TYPE(i16_rnu_sat, 8x1) a = FN(mzero_m, i16_rnu_sat, 8x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 8x1) b = FN(mzero_m, i16_rnu_sat, 8x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 8x1) r = FN(mand_ew, i16_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_206 (void)
{
  TYPE(i16_rne_sat, 1x8) a = FN(mzero_m, i16_rne_sat, 1x8) ();
  CHANGE(a);
  TYPE(i16_rne_sat, 1x8) b = FN(mzero_m, i16_rne_sat, 1x8) ();
  CHANGE(b);
  TYPE(i16_rne_sat, 1x8) r = FN(mandnot_ew, i16_rne_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_207 (void)
{
  TYPE(i16_rdn_sat, 8x1) a = FN(mzero_m, i16_rdn_sat, 8x1) ();
  CHANGE(a);
  TYPE(i16_rdn_sat, 8x1) b = FN(mzero_m, i16_rdn_sat, 8x1) ();
  CHANGE(b);
  TYPE(i16_rdn_sat, 8x1) r = FN(mor_ew, i16_rdn_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_208 (void)
{
  TYPE(i16_rod_sat, 1x8) a = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE(a);
  TYPE(i16_rod_sat, 1x8) b = FN(mzero_m, i16_rod_sat, 1x8) ();
  CHANGE(b);
  TYPE(i16_rod_sat, 1x8) r = FN(mornot_ew, i16_rod_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_209 (void)
{
  TYPE(i16_rnu_sat, 8x1) a = FN(mzero_m, i16_rnu_sat, 8x1) ();
  CHANGE(a);
  TYPE(i16_rnu_sat, 8x1) b = FN(mzero_m, i16_rnu_sat, 8x1) ();
  CHANGE(b);
  TYPE(i16_rnu_sat, 8x1) r = FN(mxor_ew, i16_rnu_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_210 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x8) b = FN(mzero_m, u16_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x8) r = FN(madd_ew, u16_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_211 (void)
{
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod, 8x1) b = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 8x1) r = FN(msub_ew, u16_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_212 (void)
{
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x8) b = FN(mzero_m, u16_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x8) r = FN(mmul_ew, u16_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_213 (void)
{
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 8x1) r = FN(mmulneg_ew, u16_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_214 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x8) b = FN(mzero_m, u16_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x8) r = FN(mabsdiff_ew, u16_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_215 (void)
{
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod, 8x1) b = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 8x1) r = FN(mhdiff_ew, u16_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_216 (void)
{
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x8) b = FN(mzero_m, u16_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x8) r = FN(mmean_ew, u16_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_217 (void)
{
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 8x1) r = FN(mcmpge_ew, u16_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_218 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x8) b = FN(mzero_m, u16_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x8) r = FN(mcmplt_ew, u16_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_219 (void)
{
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 8x1) b = FN(mzero_m, u16_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 8x1) r = FN(mselge_ew, u16_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_220 (void)
{
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x8) b = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x8) r = FN(msellt_ew, u16_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_221 (void)
{
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 8x1) r = FN(msll_ew, u16_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_222 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x8) r = FN(msll_ew_x, u16_rnu_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_128_223 (void)
{
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod, 8x1) b = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 8x1) r = FN(msrl_ew, u16_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_224 (void)
{
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x8) r = FN(msrl_ew_x, u16_rdn_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_128_225 (void)
{
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 8x1) r = FN(msra_ew, u16_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_226 (void)
{
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x8) r = FN(msra_ew_x, u16_rnu_sat, 1x8) (a, 1);
  KEEP(r);
}
void case_128_227 (void)
{
  TYPE(u16_rne_sat, 8x1) old = FN(mzero_m, u16_rne_sat, 8x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod, 8x1) b = FN(mzero_m, u16_rod, 8x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 8x1) r = FN(mmulacc_ew, u16_rne_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_128_228 (void)
{
  TYPE(u16_rdn_sat, 1x8) old = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE(old);
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(u16_rnu, 1x8) b = FN(mzero_m, u16_rnu, 1x8) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x8) r = FN(mmulaccneg_ew, u16_rdn_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_128_229 (void)
{
  TYPE(u16_rod_sat, 8x1) old = FN(mzero_m, u16_rod_sat, 8x1) ();
  CHANGE(old);
  TYPE(i16_rnu, 8x1) a = FN(mzero_m, i16_rnu, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne, 8x1) b = FN(mzero_m, u16_rne, 8x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 8x1) r = FN(mmuladd_ew, u16_rod_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_128_230 (void)
{
  TYPE(u16_rnu_sat, 1x8) old = FN(mzero_m, u16_rnu_sat, 1x8) ();
  CHANGE(old);
  TYPE(i16_rne, 1x8) a = FN(mzero_m, i16_rne, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn, 1x8) b = FN(mzero_m, u16_rdn, 1x8) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x8) r = FN(mmulsub_ew, u16_rnu_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_128_231 (void)
{
  TYPE(u16_rne_sat, 8x1) old = FN(mzero_m, u16_rne_sat, 8x1) ();
  CHANGE(old);
  TYPE(i16_rdn, 8x1) a = FN(mzero_m, i16_rdn, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 8x1) b = FN(mzero_m, u16_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 8x1) r = FN(mcmovge_ew, u16_rne_sat, 8x1) (old, a, b);
  KEEP(r);
}
void case_128_232 (void)
{
  TYPE(u16_rdn_sat, 1x8) old = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE(old);
  TYPE(i16_rod, 1x8) a = FN(mzero_m, i16_rod, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x8) b = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x8) r = FN(mcmovlt_ew, u16_rdn_sat, 1x8) (old, a, b);
  KEEP(r);
}
void case_128_233 (void)
{
  TYPE(u16_rne_sat, 8x1) a = FN(mzero_m, u16_rne_sat, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 8x1) b = FN(mzero_m, u16_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 8x1) r = FN(mmin_ew, u16_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_234 (void)
{
  TYPE(u16_rdn_sat, 1x8) a = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x8) b = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x8) r = FN(mmax_ew, u16_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_235 (void)
{
  TYPE(u16_rod_sat, 8x1) a = FN(mzero_m, u16_rod_sat, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 8x1) b = FN(mzero_m, u16_rod_sat, 8x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 8x1) r = FN(mand_ew, u16_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_236 (void)
{
  TYPE(u16_rnu_sat, 1x8) a = FN(mzero_m, u16_rnu_sat, 1x8) ();
  CHANGE(a);
  TYPE(u16_rnu_sat, 1x8) b = FN(mzero_m, u16_rnu_sat, 1x8) ();
  CHANGE(b);
  TYPE(u16_rnu_sat, 1x8) r = FN(mandnot_ew, u16_rnu_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_237 (void)
{
  TYPE(u16_rne_sat, 8x1) a = FN(mzero_m, u16_rne_sat, 8x1) ();
  CHANGE(a);
  TYPE(u16_rne_sat, 8x1) b = FN(mzero_m, u16_rne_sat, 8x1) ();
  CHANGE(b);
  TYPE(u16_rne_sat, 8x1) r = FN(mor_ew, u16_rne_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_238 (void)
{
  TYPE(u16_rdn_sat, 1x8) a = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE(a);
  TYPE(u16_rdn_sat, 1x8) b = FN(mzero_m, u16_rdn_sat, 1x8) ();
  CHANGE(b);
  TYPE(u16_rdn_sat, 1x8) r = FN(mornot_ew, u16_rdn_sat, 1x8) (a, b);
  KEEP(r);
}
void case_128_239 (void)
{
  TYPE(u16_rod_sat, 8x1) a = FN(mzero_m, u16_rod_sat, 8x1) ();
  CHANGE(a);
  TYPE(u16_rod_sat, 8x1) b = FN(mzero_m, u16_rod_sat, 8x1) ();
  CHANGE(b);
  TYPE(u16_rod_sat, 8x1) r = FN(mxor_ew, u16_rod_sat, 8x1) (a, b);
  KEEP(r);
}
void case_128_240 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x4) b = FN(mzero_m, u32_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x4) r = FN(madd_ew, i32_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_241 (void)
{
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod, 4x1) b = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 4x1) r = FN(msub_ew, i32_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_242 (void)
{
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x4) b = FN(mzero_m, u32_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x4) r = FN(mmul_ew, i32_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_243 (void)
{
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 4x1) r = FN(mmulneg_ew, i32_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_244 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x4) b = FN(mzero_m, u32_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x4) r = FN(mabsdiff_ew, i32_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_245 (void)
{
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod, 4x1) b = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 4x1) r = FN(mhdiff_ew, i32_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_246 (void)
{
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x4) b = FN(mzero_m, u32_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x4) r = FN(mmean_ew, i32_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_247 (void)
{
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 4x1) r = FN(mcmpge_ew, i32_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_248 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x4) b = FN(mzero_m, u32_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x4) r = FN(mcmplt_ew, i32_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_249 (void)
{
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 4x1) b = FN(mzero_m, i32_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 4x1) r = FN(mselge_ew, i32_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_250 (void)
{
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x4) b = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x4) r = FN(msellt_ew, i32_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_251 (void)
{
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 4x1) r = FN(msll_ew, i32_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_252 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x4) r = FN(msll_ew_x, i32_rne_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_128_253 (void)
{
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod, 4x1) b = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 4x1) r = FN(msrl_ew, i32_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_254 (void)
{
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x4) r = FN(msrl_ew_x, i32_rod_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_128_255 (void)
{
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 4x1) r = FN(msra_ew, i32_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_256 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x4) r = FN(msra_ew_x, i32_rne_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_128_257 (void)
{
  TYPE(i32_rdn_sat, 4x1) old = FN(mzero_m, i32_rdn_sat, 4x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod, 4x1) b = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 4x1) r = FN(mmulacc_ew, i32_rdn_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_128_258 (void)
{
  TYPE(i32_rod_sat, 1x4) old = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE(old);
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x4) b = FN(mzero_m, u32_rnu, 1x4) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x4) r = FN(mmulaccneg_ew, i32_rod_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_128_259 (void)
{
  TYPE(i32_rnu_sat, 4x1) old = FN(mzero_m, i32_rnu_sat, 4x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 4x1) r = FN(mmuladd_ew, i32_rnu_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_128_260 (void)
{
  TYPE(i32_rne_sat, 1x4) old = FN(mzero_m, i32_rne_sat, 1x4) ();
  CHANGE(old);
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x4) b = FN(mzero_m, u32_rdn, 1x4) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x4) r = FN(mmulsub_ew, i32_rne_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_128_261 (void)
{
  TYPE(i32_rdn_sat, 4x1) old = FN(mzero_m, i32_rdn_sat, 4x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 4x1) b = FN(mzero_m, i32_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 4x1) r = FN(mcmovge_ew, i32_rdn_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_128_262 (void)
{
  TYPE(i32_rod_sat, 1x4) old = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE(old);
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x4) b = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x4) r = FN(mcmovlt_ew, i32_rod_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_128_263 (void)
{
  TYPE(i32_rdn_sat, 4x1) a = FN(mzero_m, i32_rdn_sat, 4x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 4x1) b = FN(mzero_m, i32_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 4x1) r = FN(mmin_ew, i32_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_264 (void)
{
  TYPE(i32_rod_sat, 1x4) a = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x4) b = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x4) r = FN(mmax_ew, i32_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_265 (void)
{
  TYPE(i32_rnu_sat, 4x1) a = FN(mzero_m, i32_rnu_sat, 4x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 4x1) b = FN(mzero_m, i32_rnu_sat, 4x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 4x1) r = FN(mand_ew, i32_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_266 (void)
{
  TYPE(i32_rne_sat, 1x4) a = FN(mzero_m, i32_rne_sat, 1x4) ();
  CHANGE(a);
  TYPE(i32_rne_sat, 1x4) b = FN(mzero_m, i32_rne_sat, 1x4) ();
  CHANGE(b);
  TYPE(i32_rne_sat, 1x4) r = FN(mandnot_ew, i32_rne_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_267 (void)
{
  TYPE(i32_rdn_sat, 4x1) a = FN(mzero_m, i32_rdn_sat, 4x1) ();
  CHANGE(a);
  TYPE(i32_rdn_sat, 4x1) b = FN(mzero_m, i32_rdn_sat, 4x1) ();
  CHANGE(b);
  TYPE(i32_rdn_sat, 4x1) r = FN(mor_ew, i32_rdn_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_268 (void)
{
  TYPE(i32_rod_sat, 1x4) a = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE(a);
  TYPE(i32_rod_sat, 1x4) b = FN(mzero_m, i32_rod_sat, 1x4) ();
  CHANGE(b);
  TYPE(i32_rod_sat, 1x4) r = FN(mornot_ew, i32_rod_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_269 (void)
{
  TYPE(i32_rnu_sat, 4x1) a = FN(mzero_m, i32_rnu_sat, 4x1) ();
  CHANGE(a);
  TYPE(i32_rnu_sat, 4x1) b = FN(mzero_m, i32_rnu_sat, 4x1) ();
  CHANGE(b);
  TYPE(i32_rnu_sat, 4x1) r = FN(mxor_ew, i32_rnu_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_270 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x4) b = FN(mzero_m, u32_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x4) r = FN(madd_ew, u32_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_271 (void)
{
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod, 4x1) b = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 4x1) r = FN(msub_ew, u32_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_272 (void)
{
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x4) b = FN(mzero_m, u32_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x4) r = FN(mmul_ew, u32_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_273 (void)
{
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 4x1) r = FN(mmulneg_ew, u32_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_274 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x4) b = FN(mzero_m, u32_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x4) r = FN(mabsdiff_ew, u32_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_275 (void)
{
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod, 4x1) b = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 4x1) r = FN(mhdiff_ew, u32_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_276 (void)
{
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x4) b = FN(mzero_m, u32_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x4) r = FN(mmean_ew, u32_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_277 (void)
{
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 4x1) r = FN(mcmpge_ew, u32_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_278 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x4) b = FN(mzero_m, u32_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x4) r = FN(mcmplt_ew, u32_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_279 (void)
{
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 4x1) b = FN(mzero_m, u32_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 4x1) r = FN(mselge_ew, u32_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_280 (void)
{
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x4) b = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x4) r = FN(msellt_ew, u32_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_281 (void)
{
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 4x1) r = FN(msll_ew, u32_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_282 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x4) r = FN(msll_ew_x, u32_rnu_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_128_283 (void)
{
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod, 4x1) b = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 4x1) r = FN(msrl_ew, u32_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_284 (void)
{
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x4) r = FN(msrl_ew_x, u32_rdn_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_128_285 (void)
{
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 4x1) r = FN(msra_ew, u32_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_286 (void)
{
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x4) r = FN(msra_ew_x, u32_rnu_sat, 1x4) (a, 1);
  KEEP(r);
}
void case_128_287 (void)
{
  TYPE(u32_rne_sat, 4x1) old = FN(mzero_m, u32_rne_sat, 4x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod, 4x1) b = FN(mzero_m, u32_rod, 4x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 4x1) r = FN(mmulacc_ew, u32_rne_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_128_288 (void)
{
  TYPE(u32_rdn_sat, 1x4) old = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE(old);
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(u32_rnu, 1x4) b = FN(mzero_m, u32_rnu, 1x4) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x4) r = FN(mmulaccneg_ew, u32_rdn_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_128_289 (void)
{
  TYPE(u32_rod_sat, 4x1) old = FN(mzero_m, u32_rod_sat, 4x1) ();
  CHANGE(old);
  TYPE(i32_rnu, 4x1) a = FN(mzero_m, i32_rnu, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne, 4x1) b = FN(mzero_m, u32_rne, 4x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 4x1) r = FN(mmuladd_ew, u32_rod_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_128_290 (void)
{
  TYPE(u32_rnu_sat, 1x4) old = FN(mzero_m, u32_rnu_sat, 1x4) ();
  CHANGE(old);
  TYPE(i32_rne, 1x4) a = FN(mzero_m, i32_rne, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn, 1x4) b = FN(mzero_m, u32_rdn, 1x4) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x4) r = FN(mmulsub_ew, u32_rnu_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_128_291 (void)
{
  TYPE(u32_rne_sat, 4x1) old = FN(mzero_m, u32_rne_sat, 4x1) ();
  CHANGE(old);
  TYPE(i32_rdn, 4x1) a = FN(mzero_m, i32_rdn, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 4x1) b = FN(mzero_m, u32_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 4x1) r = FN(mcmovge_ew, u32_rne_sat, 4x1) (old, a, b);
  KEEP(r);
}
void case_128_292 (void)
{
  TYPE(u32_rdn_sat, 1x4) old = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE(old);
  TYPE(i32_rod, 1x4) a = FN(mzero_m, i32_rod, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x4) b = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x4) r = FN(mcmovlt_ew, u32_rdn_sat, 1x4) (old, a, b);
  KEEP(r);
}
void case_128_293 (void)
{
  TYPE(u32_rne_sat, 4x1) a = FN(mzero_m, u32_rne_sat, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 4x1) b = FN(mzero_m, u32_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 4x1) r = FN(mmin_ew, u32_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_294 (void)
{
  TYPE(u32_rdn_sat, 1x4) a = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x4) b = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x4) r = FN(mmax_ew, u32_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_295 (void)
{
  TYPE(u32_rod_sat, 4x1) a = FN(mzero_m, u32_rod_sat, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 4x1) b = FN(mzero_m, u32_rod_sat, 4x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 4x1) r = FN(mand_ew, u32_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_296 (void)
{
  TYPE(u32_rnu_sat, 1x4) a = FN(mzero_m, u32_rnu_sat, 1x4) ();
  CHANGE(a);
  TYPE(u32_rnu_sat, 1x4) b = FN(mzero_m, u32_rnu_sat, 1x4) ();
  CHANGE(b);
  TYPE(u32_rnu_sat, 1x4) r = FN(mandnot_ew, u32_rnu_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_297 (void)
{
  TYPE(u32_rne_sat, 4x1) a = FN(mzero_m, u32_rne_sat, 4x1) ();
  CHANGE(a);
  TYPE(u32_rne_sat, 4x1) b = FN(mzero_m, u32_rne_sat, 4x1) ();
  CHANGE(b);
  TYPE(u32_rne_sat, 4x1) r = FN(mor_ew, u32_rne_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_298 (void)
{
  TYPE(u32_rdn_sat, 1x4) a = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE(a);
  TYPE(u32_rdn_sat, 1x4) b = FN(mzero_m, u32_rdn_sat, 1x4) ();
  CHANGE(b);
  TYPE(u32_rdn_sat, 1x4) r = FN(mornot_ew, u32_rdn_sat, 1x4) (a, b);
  KEEP(r);
}
void case_128_299 (void)
{
  TYPE(u32_rod_sat, 4x1) a = FN(mzero_m, u32_rod_sat, 4x1) ();
  CHANGE(a);
  TYPE(u32_rod_sat, 4x1) b = FN(mzero_m, u32_rod_sat, 4x1) ();
  CHANGE(b);
  TYPE(u32_rod_sat, 4x1) r = FN(mxor_ew, u32_rod_sat, 4x1) (a, b);
  KEEP(r);
}
void case_128_300 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x2) b = FN(mzero_m, u64_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x2) r = FN(madd_ew, i64_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_301 (void)
{
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod, 2x1) b = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 2x1) r = FN(msub_ew, i64_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_302 (void)
{
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x2) b = FN(mzero_m, u64_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) r = FN(mmul_ew, i64_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_303 (void)
{
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 2x1) r = FN(mmulneg_ew, i64_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_304 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x2) b = FN(mzero_m, u64_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x2) r = FN(mabsdiff_ew, i64_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_305 (void)
{
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod, 2x1) b = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 2x1) r = FN(mhdiff_ew, i64_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_306 (void)
{
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x2) b = FN(mzero_m, u64_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) r = FN(mmean_ew, i64_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_307 (void)
{
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 2x1) r = FN(mcmpge_ew, i64_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_308 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x2) b = FN(mzero_m, u64_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x2) r = FN(mcmplt_ew, i64_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_309 (void)
{
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 2x1) b = FN(mzero_m, i64_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 2x1) r = FN(mselge_ew, i64_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_310 (void)
{
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x2) b = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) r = FN(msellt_ew, i64_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_311 (void)
{
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 2x1) r = FN(msll_ew, i64_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_312 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x2) r = FN(msll_ew_x, i64_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_128_313 (void)
{
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod, 2x1) b = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 2x1) r = FN(msrl_ew, i64_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_314 (void)
{
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x2) r = FN(msrl_ew_x, i64_rod_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_128_315 (void)
{
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 2x1) r = FN(msra_ew, i64_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_316 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x2) r = FN(msra_ew_x, i64_rne_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_128_317 (void)
{
  TYPE(i64_rdn_sat, 2x1) old = FN(mzero_m, i64_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod, 2x1) b = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 2x1) r = FN(mmulacc_ew, i64_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_128_318 (void)
{
  TYPE(i64_rod_sat, 1x2) old = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x2) b = FN(mzero_m, u64_rnu, 1x2) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) r = FN(mmulaccneg_ew, i64_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_128_319 (void)
{
  TYPE(i64_rnu_sat, 2x1) old = FN(mzero_m, i64_rnu_sat, 2x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 2x1) r = FN(mmuladd_ew, i64_rnu_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_128_320 (void)
{
  TYPE(i64_rne_sat, 1x2) old = FN(mzero_m, i64_rne_sat, 1x2) ();
  CHANGE(old);
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x2) b = FN(mzero_m, u64_rdn, 1x2) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x2) r = FN(mmulsub_ew, i64_rne_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_128_321 (void)
{
  TYPE(i64_rdn_sat, 2x1) old = FN(mzero_m, i64_rdn_sat, 2x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 2x1) b = FN(mzero_m, i64_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 2x1) r = FN(mcmovge_ew, i64_rdn_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_128_322 (void)
{
  TYPE(i64_rod_sat, 1x2) old = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE(old);
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x2) b = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) r = FN(mcmovlt_ew, i64_rod_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_128_323 (void)
{
  TYPE(i64_rdn_sat, 2x1) a = FN(mzero_m, i64_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 2x1) b = FN(mzero_m, i64_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 2x1) r = FN(mmin_ew, i64_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_324 (void)
{
  TYPE(i64_rod_sat, 1x2) a = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x2) b = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) r = FN(mmax_ew, i64_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_325 (void)
{
  TYPE(i64_rnu_sat, 2x1) a = FN(mzero_m, i64_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 2x1) b = FN(mzero_m, i64_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 2x1) r = FN(mand_ew, i64_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_326 (void)
{
  TYPE(i64_rne_sat, 1x2) a = FN(mzero_m, i64_rne_sat, 1x2) ();
  CHANGE(a);
  TYPE(i64_rne_sat, 1x2) b = FN(mzero_m, i64_rne_sat, 1x2) ();
  CHANGE(b);
  TYPE(i64_rne_sat, 1x2) r = FN(mandnot_ew, i64_rne_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_327 (void)
{
  TYPE(i64_rdn_sat, 2x1) a = FN(mzero_m, i64_rdn_sat, 2x1) ();
  CHANGE(a);
  TYPE(i64_rdn_sat, 2x1) b = FN(mzero_m, i64_rdn_sat, 2x1) ();
  CHANGE(b);
  TYPE(i64_rdn_sat, 2x1) r = FN(mor_ew, i64_rdn_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_328 (void)
{
  TYPE(i64_rod_sat, 1x2) a = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE(a);
  TYPE(i64_rod_sat, 1x2) b = FN(mzero_m, i64_rod_sat, 1x2) ();
  CHANGE(b);
  TYPE(i64_rod_sat, 1x2) r = FN(mornot_ew, i64_rod_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_329 (void)
{
  TYPE(i64_rnu_sat, 2x1) a = FN(mzero_m, i64_rnu_sat, 2x1) ();
  CHANGE(a);
  TYPE(i64_rnu_sat, 2x1) b = FN(mzero_m, i64_rnu_sat, 2x1) ();
  CHANGE(b);
  TYPE(i64_rnu_sat, 2x1) r = FN(mxor_ew, i64_rnu_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_330 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x2) b = FN(mzero_m, u64_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x2) r = FN(madd_ew, u64_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_331 (void)
{
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod, 2x1) b = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 2x1) r = FN(msub_ew, u64_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_332 (void)
{
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x2) b = FN(mzero_m, u64_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) r = FN(mmul_ew, u64_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_333 (void)
{
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 2x1) r = FN(mmulneg_ew, u64_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_334 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x2) b = FN(mzero_m, u64_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x2) r = FN(mabsdiff_ew, u64_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_335 (void)
{
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod, 2x1) b = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 2x1) r = FN(mhdiff_ew, u64_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_336 (void)
{
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x2) b = FN(mzero_m, u64_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) r = FN(mmean_ew, u64_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_337 (void)
{
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 2x1) r = FN(mcmpge_ew, u64_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_338 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x2) b = FN(mzero_m, u64_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x2) r = FN(mcmplt_ew, u64_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_339 (void)
{
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 2x1) b = FN(mzero_m, u64_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 2x1) r = FN(mselge_ew, u64_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_340 (void)
{
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x2) b = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) r = FN(msellt_ew, u64_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_341 (void)
{
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 2x1) r = FN(msll_ew, u64_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_342 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x2) r = FN(msll_ew_x, u64_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_128_343 (void)
{
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod, 2x1) b = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 2x1) r = FN(msrl_ew, u64_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_344 (void)
{
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x2) r = FN(msrl_ew_x, u64_rdn_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_128_345 (void)
{
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 2x1) r = FN(msra_ew, u64_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_346 (void)
{
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x2) r = FN(msra_ew_x, u64_rnu_sat, 1x2) (a, 1);
  KEEP(r);
}
void case_128_347 (void)
{
  TYPE(u64_rne_sat, 2x1) old = FN(mzero_m, u64_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod, 2x1) b = FN(mzero_m, u64_rod, 2x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 2x1) r = FN(mmulacc_ew, u64_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_128_348 (void)
{
  TYPE(u64_rdn_sat, 1x2) old = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(u64_rnu, 1x2) b = FN(mzero_m, u64_rnu, 1x2) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) r = FN(mmulaccneg_ew, u64_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_128_349 (void)
{
  TYPE(u64_rod_sat, 2x1) old = FN(mzero_m, u64_rod_sat, 2x1) ();
  CHANGE(old);
  TYPE(i64_rnu, 2x1) a = FN(mzero_m, i64_rnu, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne, 2x1) b = FN(mzero_m, u64_rne, 2x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 2x1) r = FN(mmuladd_ew, u64_rod_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_128_350 (void)
{
  TYPE(u64_rnu_sat, 1x2) old = FN(mzero_m, u64_rnu_sat, 1x2) ();
  CHANGE(old);
  TYPE(i64_rne, 1x2) a = FN(mzero_m, i64_rne, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn, 1x2) b = FN(mzero_m, u64_rdn, 1x2) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x2) r = FN(mmulsub_ew, u64_rnu_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_128_351 (void)
{
  TYPE(u64_rne_sat, 2x1) old = FN(mzero_m, u64_rne_sat, 2x1) ();
  CHANGE(old);
  TYPE(i64_rdn, 2x1) a = FN(mzero_m, i64_rdn, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 2x1) b = FN(mzero_m, u64_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 2x1) r = FN(mcmovge_ew, u64_rne_sat, 2x1) (old, a, b);
  KEEP(r);
}
void case_128_352 (void)
{
  TYPE(u64_rdn_sat, 1x2) old = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE(old);
  TYPE(i64_rod, 1x2) a = FN(mzero_m, i64_rod, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x2) b = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) r = FN(mcmovlt_ew, u64_rdn_sat, 1x2) (old, a, b);
  KEEP(r);
}
void case_128_353 (void)
{
  TYPE(u64_rne_sat, 2x1) a = FN(mzero_m, u64_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 2x1) b = FN(mzero_m, u64_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 2x1) r = FN(mmin_ew, u64_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_354 (void)
{
  TYPE(u64_rdn_sat, 1x2) a = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x2) b = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) r = FN(mmax_ew, u64_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_355 (void)
{
  TYPE(u64_rod_sat, 2x1) a = FN(mzero_m, u64_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 2x1) b = FN(mzero_m, u64_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 2x1) r = FN(mand_ew, u64_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_356 (void)
{
  TYPE(u64_rnu_sat, 1x2) a = FN(mzero_m, u64_rnu_sat, 1x2) ();
  CHANGE(a);
  TYPE(u64_rnu_sat, 1x2) b = FN(mzero_m, u64_rnu_sat, 1x2) ();
  CHANGE(b);
  TYPE(u64_rnu_sat, 1x2) r = FN(mandnot_ew, u64_rnu_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_357 (void)
{
  TYPE(u64_rne_sat, 2x1) a = FN(mzero_m, u64_rne_sat, 2x1) ();
  CHANGE(a);
  TYPE(u64_rne_sat, 2x1) b = FN(mzero_m, u64_rne_sat, 2x1) ();
  CHANGE(b);
  TYPE(u64_rne_sat, 2x1) r = FN(mor_ew, u64_rne_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_358 (void)
{
  TYPE(u64_rdn_sat, 1x2) a = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE(a);
  TYPE(u64_rdn_sat, 1x2) b = FN(mzero_m, u64_rdn_sat, 1x2) ();
  CHANGE(b);
  TYPE(u64_rdn_sat, 1x2) r = FN(mornot_ew, u64_rdn_sat, 1x2) (a, b);
  KEEP(r);
}
void case_128_359 (void)
{
  TYPE(u64_rod_sat, 2x1) a = FN(mzero_m, u64_rod_sat, 2x1) ();
  CHANGE(a);
  TYPE(u64_rod_sat, 2x1) b = FN(mzero_m, u64_rod_sat, 2x1) ();
  CHANGE(b);
  TYPE(u64_rod_sat, 2x1) r = FN(mxor_ew, u64_rod_sat, 2x1) (a, b);
  KEEP(r);
}
void case_128_360 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(madd_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_361 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(msub_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_362 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmul_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_363 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mmulneg_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_364 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mabsdiff_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_365 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mhdiff_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_366 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmean_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_367 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mcmpge_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_368 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mcmplt_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_369 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mselge_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_370 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(msellt_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_371 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(msll_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_372 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) r = FN(msll_ew_x, i128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_373 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(msrl_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_374 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) r = FN(msrl_ew_x, i128_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_375 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(msra_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_376 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) r = FN(msra_ew_x, i128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_377 (void)
{
  TYPE(i128_rdn_sat, 1x1) old = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mmulacc_ew, i128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_378 (void)
{
  TYPE(i128_rod_sat, 1x1) old = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmulaccneg_ew, i128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_379 (void)
{
  TYPE(i128_rnu_sat, 1x1) old = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mmuladd_ew, i128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_380 (void)
{
  TYPE(i128_rne_sat, 1x1) old = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mmulsub_ew, i128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_381 (void)
{
  TYPE(i128_rdn_sat, 1x1) old = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mcmovge_ew, i128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_382 (void)
{
  TYPE(i128_rod_sat, 1x1) old = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mcmovlt_ew, i128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_383 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mcolgather_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_384 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mrowgather_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_385 (void)
{
  TYPE(i128_rdn_sat, 1x1) old = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mcolscatadd_ew, i128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_386 (void)
{
  TYPE(i128_rod_sat, 1x1) old = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mrowscatadd_ew, i128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_387 (void)
{
  TYPE(i128_rnu_sat, 1x1) old = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mcolscatmax_ew, i128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_388 (void)
{
  TYPE(i128_rne_sat, 1x1) old = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mrowscatmax_ew, i128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_389 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mmin_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_390 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mmax_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_391 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mand_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_392 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) b = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x1) r = FN(mandnot_ew, i128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_393 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) b = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rdn_sat, 1x1) r = FN(mor_ew, i128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_394 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x1) r = FN(mornot_ew, i128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_395 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x1) r = FN(mxor_ew, i128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_396 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) r = FN(mcolbcast_ew_x, i128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_397 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) r = FN(mcolshift_ew_x, i128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_398 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) b = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rod_sat, 1x2) pair = FN(mconcat_m, i128_rod_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, i128_rod_sat, 1x2) (pair);
  a = FN(mextract, i128_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_128_399 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x2) pair = FN(mconcat_m, i128_rnu_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, i128_rnu_sat, 1x2) (pair);
  a = FN(mextract, i128_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_128_400 (void)
{
  TYPE(i128_rne_sat, 1x1) r = FN(mcolid_ew, i128_rne_sat, 1x1) ();
  KEEP(r);
}
void case_128_401 (void)
{
  TYPE(i128_rdn_sat, 1x1) a = FN(mzero_m, i128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rdn_sat, 1x1) r = FN(mrowbcast_ew_x, i128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_402 (void)
{
  TYPE(i128_rod_sat, 1x1) a = FN(mzero_m, i128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rod_sat, 1x1) r = FN(mrowshift_ew_x, i128_rod_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_403 (void)
{
  TYPE(i128_rnu_sat, 1x1) a = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rnu_sat, 1x1) b = FN(mzero_m, i128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rnu_sat, 1x2) pair = FN(mconcat_m, i128_rnu_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, i128_rnu_sat, 1x2) (pair);
  a = FN(mextract, i128_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_128_404 (void)
{
  TYPE(i128_rne_sat, 1x1) a = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(i128_rne_sat, 1x1) b = FN(mzero_m, i128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(i128_rne_sat, 1x2) pair = FN(mconcat_m, i128_rne_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, i128_rne_sat, 1x2) (pair);
  a = FN(mextract, i128_rne_sat, 1x1) (pair, 0);
  b = FN(mextract, i128_rne_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_128_405 (void)
{
  TYPE(i128_rdn_sat, 1x1) r = FN(mrowid_ew, i128_rdn_sat, 1x1) ();
  KEEP(r);
}
void case_128_406 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(madd_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_407 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(msub_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_408 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmul_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_409 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mmulneg_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_410 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mabsdiff_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_411 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mhdiff_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_412 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmean_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_413 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mcmpge_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_414 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mcmplt_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_415 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mselge_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_416 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(msellt_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_417 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(msll_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_418 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) r = FN(msll_ew_x, u128_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_419 (void)
{
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(msrl_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_420 (void)
{
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) r = FN(msrl_ew_x, u128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_421 (void)
{
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(msra_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_422 (void)
{
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) r = FN(msra_ew_x, u128_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_423 (void)
{
  TYPE(u128_rne_sat, 1x1) old = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mmulacc_ew, u128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_424 (void)
{
  TYPE(u128_rdn_sat, 1x1) old = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmulaccneg_ew, u128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_425 (void)
{
  TYPE(u128_rod_sat, 1x1) old = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mmuladd_ew, u128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_426 (void)
{
  TYPE(u128_rnu_sat, 1x1) old = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mmulsub_ew, u128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_427 (void)
{
  TYPE(u128_rne_sat, 1x1) old = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mcmovge_ew, u128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_428 (void)
{
  TYPE(u128_rdn_sat, 1x1) old = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mcmovlt_ew, u128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_429 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mcolgather_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_430 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mrowgather_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_431 (void)
{
  TYPE(u128_rne_sat, 1x1) old = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rdn, 1x1) a = FN(mzero_m, i128_rdn, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod, 1x1) b = FN(mzero_m, u128_rod, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mcolscatadd_ew, u128_rne_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_432 (void)
{
  TYPE(u128_rdn_sat, 1x1) old = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rod, 1x1) a = FN(mzero_m, i128_rod, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu, 1x1) b = FN(mzero_m, u128_rnu, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mrowscatadd_ew, u128_rdn_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_433 (void)
{
  TYPE(u128_rod_sat, 1x1) old = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rnu, 1x1) a = FN(mzero_m, i128_rnu, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne, 1x1) b = FN(mzero_m, u128_rne, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mcolscatmax_ew, u128_rod_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_434 (void)
{
  TYPE(u128_rnu_sat, 1x1) old = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(old);
  TYPE(i128_rne, 1x1) a = FN(mzero_m, i128_rne, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn, 1x1) b = FN(mzero_m, u128_rdn, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mrowscatmax_ew, u128_rnu_sat, 1x1) (old, a, b);
  KEEP(r);
}
void case_128_435 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mmin_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_436 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mmax_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_437 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mand_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_438 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) b = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x1) r = FN(mandnot_ew, u128_rnu_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_439 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) b = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rne_sat, 1x1) r = FN(mor_ew, u128_rne_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_440 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x1) r = FN(mornot_ew, u128_rdn_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_441 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x1) r = FN(mxor_ew, u128_rod_sat, 1x1) (a, b);
  KEEP(r);
}
void case_128_442 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) r = FN(mcolbcast_ew_x, u128_rnu_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_443 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) r = FN(mcolshift_ew_x, u128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_444 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) b = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rdn_sat, 1x2) pair = FN(mconcat_m, u128_rdn_sat, 1x2) (a, b);
  pair = FN(mcolzip_ew, u128_rdn_sat, 1x2) (pair);
  a = FN(mextract, u128_rdn_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rdn_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_128_445 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x2) pair = FN(mconcat_m, u128_rod_sat, 1x2) (a, b);
  pair = FN(mcolunzip_ew, u128_rod_sat, 1x2) (pair);
  a = FN(mextract, u128_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_128_446 (void)
{
  TYPE(u128_rnu_sat, 1x1) r = FN(mcolid_ew, u128_rnu_sat, 1x1) ();
  KEEP(r);
}
void case_128_447 (void)
{
  TYPE(u128_rne_sat, 1x1) a = FN(mzero_m, u128_rne_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rne_sat, 1x1) r = FN(mrowbcast_ew_x, u128_rne_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_448 (void)
{
  TYPE(u128_rdn_sat, 1x1) a = FN(mzero_m, u128_rdn_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rdn_sat, 1x1) r = FN(mrowshift_ew_x, u128_rdn_sat, 1x1) (a, 1);
  KEEP(r);
}
void case_128_449 (void)
{
  TYPE(u128_rod_sat, 1x1) a = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rod_sat, 1x1) b = FN(mzero_m, u128_rod_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rod_sat, 1x2) pair = FN(mconcat_m, u128_rod_sat, 1x2) (a, b);
  pair = FN(mrowzip_ew, u128_rod_sat, 1x2) (pair);
  a = FN(mextract, u128_rod_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rod_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_128_450 (void)
{
  TYPE(u128_rnu_sat, 1x1) a = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(a);
  TYPE(u128_rnu_sat, 1x1) b = FN(mzero_m, u128_rnu_sat, 1x1) ();
  CHANGE(b);
  TYPE(u128_rnu_sat, 1x2) pair = FN(mconcat_m, u128_rnu_sat, 1x2) (a, b);
  pair = FN(mrowunzip_ew, u128_rnu_sat, 1x2) (pair);
  a = FN(mextract, u128_rnu_sat, 1x1) (pair, 0);
  b = FN(mextract, u128_rnu_sat, 1x1) (pair, 1);
  KEEP(a);
  KEEP(b);
}
void case_128_451 (void)
{
  TYPE(u128_rne_sat, 1x1) r = FN(mrowid_ew, u128_rne_sat, 1x1) ();
  KEEP(r);
}
#endif
