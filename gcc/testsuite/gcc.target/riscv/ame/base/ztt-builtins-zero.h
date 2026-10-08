#ifdef __cplusplus
extern "C" {
#endif

#define ZERO(NAME) \
void zero_##NAME (void) \
{ \
  __builtin_riscv_ztt_##NAME (15, 0, 0); \
}

ZERO (mabsdiff_ew_x)
ZERO (madd_ew_x)
ZERO (mand_ew_x)
ZERO (mandnot_ew_x)
ZERO (mcmpge_ew_x)
ZERO (mcmplt_ew_x)
ZERO (mcolbcast_ew_x)
ZERO (mcolshift_ew_x)
ZERO (mhdiff_ew_x)
ZERO (mldexp_ew_x)
ZERO (mldexpacc_ew_x)
ZERO (mlog2sub_ew_x)
ZERO (mmax_ew_x)
ZERO (mmean_ew_x)
ZERO (mmin_ew_x)
ZERO (mmul_ew_x)
ZERO (mmulacc_ew_x)
ZERO (mmulaccneg_ew_x)
ZERO (mmuladd_ew_x)
ZERO (mmulneg_ew_x)
ZERO (mmulsub_ew_x)
ZERO (mor_ew_x)
ZERO (mornot_ew_x)
ZERO (mpack_ew_x)
ZERO (mrowbcast_ew_x)
ZERO (mrowshift_ew_x)
ZERO (msll_ew_x)
ZERO (msra_ew_x)
ZERO (msrl_ew_x)
ZERO (msub_ew_x)
ZERO (msublog2_ew_x)
ZERO (munpack_ew_x)
ZERO (mxor_ew_x)
#undef ZERO

void
zero_effect (volatile unsigned long *p)
{
  __builtin_riscv_ztt_mcolshift_ew_x (15, ((void) (*p = *p + 1), 0), 0);
}

void
nonzero (void)
{
  __builtin_riscv_ztt_madd_ew_x (15, 31, 0);
}

void
dynamic (unsigned long x)
{
  __builtin_riscv_ztt_madd_ew_x (15, x, 0);
}

#ifdef __cplusplus
}
#endif
