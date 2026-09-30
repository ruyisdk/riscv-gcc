/* { dg-do compile } */
/* { dg-options "-Werror=implicit-function-declaration -march=rv32gc -mabi=ilp32" { target rv32 } } */
/* { dg-options "-Werror=implicit-function-declaration -march=rv64gc -mabi=lp64" { target rv64 } } */

#ifdef __riscv_ztt
#error "__riscv_ztt must require explicit -march enablement"
#endif

void
ztt_is_not_implicitly_available (void)
{
  __builtin_riscv_ztt_ame_release (); /* { dg-error "implicit declaration" } */
}
