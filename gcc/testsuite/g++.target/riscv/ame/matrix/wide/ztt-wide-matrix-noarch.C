/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_wide_matrix_int
#error Wide matrix capability must be absent
#endif
int ordinary;
