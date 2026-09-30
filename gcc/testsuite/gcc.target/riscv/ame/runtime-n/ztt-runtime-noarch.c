/* { dg-do compile } */
/* { dg-options "-Werror=implicit-function-declaration -march=rv32i_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-Werror=implicit-function-declaration -march=rv64i_zicsr -mabi=lp64" { target rv64 } } */

#ifdef __riscv_ztt_runtime_queries
#error "Runtime CSR queries require Ztt"
#endif

unsigned long
missing_ztt (void)
{
  return __builtin_riscv_ztt_read_amenlen (); /* { dg-error "implicit declaration" } */
}
