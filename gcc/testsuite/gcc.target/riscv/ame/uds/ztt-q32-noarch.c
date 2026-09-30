/* Q32.  */
/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" { target rv64 } } */
#if defined(__riscv_ztt_i8_u8_shapes) || defined(__riscv_ztt_acc_matmul_packed)
#error unexpected AME shape capabilities
#endif
int no_q32_capability;
