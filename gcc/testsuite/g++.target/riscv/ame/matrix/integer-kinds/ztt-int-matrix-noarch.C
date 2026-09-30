/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_integer_kinds_matrix
#error Integer matrix capability must be absent
#endif
int ordinary;
