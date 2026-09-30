/* Narrow ACC feature gates.  */
/* { dg-do preprocess } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#if defined(__riscv_ztt_i8_u8_accx1_irm) || defined(__riscv_ztt_i16_u16_accx1_irm)
#error narrow ACC capability must be absent
#endif
