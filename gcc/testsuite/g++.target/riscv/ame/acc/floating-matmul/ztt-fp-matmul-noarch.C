/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_floating_matmul
#error unexpected floating matmul capability
#endif
int ordinary;
