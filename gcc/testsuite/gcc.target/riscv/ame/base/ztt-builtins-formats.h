/* GPR constants must not become encoded M or ACC register operands.  */
#define SCALAR_CASE(NAME, VALUE) \
unsigned long NAME (unsigned long x, void *p) \
{ \
  __builtin_riscv_ztt_mcolshift_ew_x (15, VALUE, 0); \
  __builtin_riscv_ztt_mrowshift_ew_x (15, VALUE, 0); \
  __builtin_riscv_ztt_mcolbcast_ew_x (15, VALUE, 0); \
  __builtin_riscv_ztt_mrowbcast_ew_x (15, VALUE, 0); \
  __builtin_riscv_ztt_mbcast_m_x (15, VALUE, VALUE); \
  __builtin_riscv_ztt_mmove32_m_x (15, VALUE, VALUE); \
  __builtin_riscv_ztt_msettyp (15, VALUE); \
  __builtin_riscv_ztt_asettyp (3, VALUE); \
  __builtin_riscv_ztt_mls_st (15, p, VALUE); \
  __builtin_riscv_ztt_mss_st (15, p, VALUE); \
  return __builtin_riscv_ztt_mmove32_x_m (15, VALUE); \
}

SCALAR_CASE (zero, 0)
SCALAR_CASE (one, 1)
SCALAR_CASE (fifteen, 15)
SCALAR_CASE (sixteen, 16)
SCALAR_CASE (thirty_one, 31)
SCALAR_CASE (thirty_two, 32)
SCALAR_CASE (negative, -1)
SCALAR_CASE (dynamic, x)

unsigned long
other_formats (void *p, unsigned long x)
{
  unsigned long result = __builtin_riscv_ztt_ame_acquire (x);
  __builtin_riscv_ztt_mzero_2d_m (15);
  __builtin_riscv_ztt_mzero_2d_acc (3);
  __builtin_riscv_ztt_mabs_ew (15, 0);
  __builtin_riscv_ztt_mmov_m_a (15, 3);
  __builtin_riscv_ztt_mmov_a_m (3, 15);
  __builtin_riscv_ztt_madd_ew (15, 0, 1);
  __builtin_riscv_ztt_mmulacc_2d (3, 0, 1);
  result += __builtin_riscv_ztt_agettyp (3);
  result += __builtin_riscv_ztt_mgettyp (15);
  __builtin_riscv_ztt_mls_1r (15, p);
  __builtin_riscv_ztt_mss_1r (15, p);
  __builtin_riscv_ztt_ame_release ();
  return result;
}

void
side_effect (volatile unsigned long *p)
{
  __builtin_riscv_ztt_mcolshift_ew_x (15, ((void) (*p = *p + 1), 0), 0);
}
