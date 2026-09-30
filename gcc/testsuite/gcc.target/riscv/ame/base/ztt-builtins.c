/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt -mabi=lp64" { target rv64 } } */

unsigned long
ztt_operand_patterns (unsigned long x, unsigned long y, void *base,
		      unsigned long stride)
{
  unsigned long result;

  __builtin_riscv_ztt_ame_release ();
  __builtin_riscv_ztt_mzero_2d_m (31);
  __builtin_riscv_ztt_mzero_2d_acc (15);
  __builtin_riscv_ztt_mabs_ew (31, 16);
  __builtin_riscv_ztt_mmov_m_a (31, 15);
  __builtin_riscv_ztt_mmov_a_m (15, 31);
  __builtin_riscv_ztt_madd_ew (31, 16, 15);
  __builtin_riscv_ztt_mmulacc_2d (15, 16, 31);
  __builtin_riscv_ztt_mmulataccneg_2d (15, 16, 31);
  __builtin_riscv_ztt_mmulbtaccneg_2d (15, 16, 31);
  __builtin_riscv_ztt_madd_ew_x (31, x, 16);
  __builtin_riscv_ztt_mcolbcast_ew_x (31, x, 16);
  __builtin_riscv_ztt_mbcast_m_x (31, x, y);
  __builtin_riscv_ztt_msettyp (31, x);
  __builtin_riscv_ztt_asettyp (15, x);
  result = __builtin_riscv_ztt_agettyp (15);
  result += __builtin_riscv_ztt_mgettyp (31);
  result += __builtin_riscv_ztt_mmove8_x_m (31, x);
  result += __builtin_riscv_ztt_ame_acquire (x);
  __builtin_riscv_ztt_mls_1r (31, base);
  __builtin_riscv_ztt_mss_1r (31, base);
  __builtin_riscv_ztt_mls_st (31, base, stride);
  __builtin_riscv_ztt_mss_st (31, base, stride);

  return result;
}

/* { dg-final { scan-assembler "ame\\.release" } } */
/* { dg-final { scan-assembler "mzero\\.2d\\.m\\tm31" } } */
/* { dg-final { scan-assembler "mzero\\.2d\\.acc\\tacc15" } } */
/* { dg-final { scan-assembler "mabs\\.ew\\tm31,m16" } } */
/* { dg-final { scan-assembler "mmov\\.m\\.a\\tm31,acc15" } } */
/* { dg-final { scan-assembler "mmov\\.a\\.m\\tacc15,m31" } } */
/* { dg-final { scan-assembler "madd\\.ew\\tm31,m16,m15" } } */
/* { dg-final { scan-assembler "mmulacc\\.2d\\tacc15,m16,m31" } } */
/* { dg-final { scan-assembler "mmulataccneg\\.2d\\tacc15,m16,m31" } } */
/* { dg-final { scan-assembler "mmulbtaccneg\\.2d\\tacc15,m16,m31" } } */
/* { dg-final { scan-assembler "madd\\.ew\\.x\\tm31," } } */
/* { dg-final { scan-assembler "mcolbcast\\.ew\\.x\\tm31,\[a-z0-9\]+,m16" } } */
/* { dg-final { scan-assembler "mbcast\\.m\\.x\\tm31," } } */
/* { dg-final { scan-assembler "msettyp\\tm31," } } */
/* { dg-final { scan-assembler "asettyp\\tacc15," } } */
/* { dg-final { scan-assembler "agettyp\\t\[a-z0-9\]+,acc15" } } */
/* { dg-final { scan-assembler "mgettyp\\t\[a-z0-9\]+,m31" } } */
/* { dg-final { scan-assembler "mmove8\\.x\\.m\\t\[a-z0-9\]+,m31," } } */
/* { dg-final { scan-assembler "ame\\.acquire\\t\[a-z0-9\]+," } } */
/* { dg-final { scan-assembler "mls\\.1r\\tm31," } } */
/* { dg-final { scan-assembler "mss\\.1r\\tm31," } } */
/* { dg-final { scan-assembler "mls\\.st\\tm31,\\(\[a-z0-9\]+\\)," } } */
/* { dg-final { scan-assembler "mss\\.st\\tm31,\\(\[a-z0-9\]+\\)," } } */
