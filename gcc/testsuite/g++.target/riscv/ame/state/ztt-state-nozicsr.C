/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -march=rv32i_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -march=rv64i_ztt0p6 -mabi=lp64" { target rv64 } } */

void unavailable (void)
{
  __builtin_riscv_ztt_get_ameown (); /* { dg-error "was not declared" } */
  __builtin_riscv_ztt_get_amestype (); /* { dg-error "was not declared" } */
  __builtin_riscv_ztt_get_amenlen (); /* { dg-error "was not declared" } */
  __builtin_riscv_ztt_get_ameudsz (); /* { dg-error "was not declared" } */
  __builtin_riscv_ztt_get_amefflags (); /* { dg-error "was not declared" } */
  __builtin_riscv_ztt_get_amexsat (); /* { dg-error "was not declared" } */
  __builtin_riscv_ztt_get_amestatus (); /* { dg-error "was not declared" } */
}
