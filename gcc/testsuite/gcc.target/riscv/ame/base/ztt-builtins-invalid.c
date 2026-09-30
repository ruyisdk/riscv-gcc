/* { dg-do compile } */
/* { dg-skip-if "Skip LTO tests of builtin operand validation" { *-*-* } { "-flto" } } */
/* { dg-options "-O2 -march=rv32gc_ztt -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt -mabi=lp64" { target rv64 } } */

void
bad_mreg_high (void)
{
  __builtin_riscv_ztt_mzero_2d_m (32); /* { dg-error "invalid argument to built-in function" } */
}

void
bad_mreg_negative (void)
{
  __builtin_riscv_ztt_mzero_2d_m (-1); /* { dg-error "invalid argument to built-in function" } */
}

void
bad_acc_high (void)
{
  __builtin_riscv_ztt_mzero_2d_acc (16); /* { dg-error "invalid argument to built-in function" } */
}

void
bad_acc_negative (void)
{
  __builtin_riscv_ztt_mzero_2d_acc (-1); /* { dg-error "invalid argument to built-in function" } */
}

void
bad_nonconstant (unsigned int mreg)
{
  __builtin_riscv_ztt_mzero_2d_m (mreg); /* { dg-error "invalid argument to built-in function" } */
}
