/* ternary arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#if defined(__riscv_ztt_mmulacc_ew_int) || defined(__riscv_ztt_mmulaccneg_ew_int) \
    || defined(__riscv_ztt_mmuladd_ew_int) || defined(__riscv_ztt_mmulsub_ew_int)
#error ternary capability leaked outside Ztt/profile gate
#endif
int no_ternary_capability;
