/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#if defined(__riscv_ztt_mmulacc_ew_x_int) || defined(__riscv_ztt_mmulaccneg_ew_x_int) \
    || defined(__riscv_ztt_mmuladd_ew_x_int) || defined(__riscv_ztt_mmulsub_ew_x_int)
#error scalar old-D capability leaked outside Ztt/profile
#endif
#pragma riscv intrinsic "ztt" /* { dg-error "requires .*-mztt-profile=" } */
