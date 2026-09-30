/* { dg-do compile } */
/* { dg-options "-Werror=implicit-function-declaration -march=rv32i_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-Werror=implicit-function-declaration -march=rv64i_ztt0p6 -mabi=lp64" { target rv64 } } */

#ifdef __riscv_ztt_runtime_queries
#error "Runtime CSR queries require Zicsr"
#endif

unsigned long
missing_zicsr (void)
{
  return __builtin_riscv_ztt_read_ameudsz (); /* { dg-error "implicit declaration" } */
}
