/* { dg-do preprocess } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#if defined(__riscv_ztt_integer_kinds_values) || defined(__riscv_ztt_integer_kinds_unary)
#error unexpected integer kinds
#endif
