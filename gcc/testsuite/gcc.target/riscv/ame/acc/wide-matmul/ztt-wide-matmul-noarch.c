/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_wide_matmul_int
#error unexpected wide matmul capability
#endif
int ordinary;
