/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -march=rv32i_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -march=rv64i_zicsr -mabi=lp64" { target rv64 } } */

void unavailable (void)
{
  __builtin_riscv_ztt_get_ameown (); /* { dg-error "implicit declaration" } */
  __builtin_riscv_ztt_get_amestype (); /* { dg-error "implicit declaration" } */
  __builtin_riscv_ztt_get_amenlen (); /* { dg-error "implicit declaration" } */
  __builtin_riscv_ztt_get_ameudsz (); /* { dg-error "implicit declaration" } */
  __builtin_riscv_ztt_get_amefflags (); /* { dg-error "implicit declaration" } */
  __builtin_riscv_ztt_get_amexsat (); /* { dg-error "implicit declaration" } */
  __builtin_riscv_ztt_get_amestatus (); /* { dg-error "implicit declaration" } */
  __builtin_riscv_ztt_acquire (0); /* { dg-error "implicit declaration" } */
}
