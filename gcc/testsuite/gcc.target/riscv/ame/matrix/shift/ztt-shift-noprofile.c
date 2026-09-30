/* shifts.  */
/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_shift_int_mixed
#error unexpected typed shift capability
#endif
int no_shift_capability;
