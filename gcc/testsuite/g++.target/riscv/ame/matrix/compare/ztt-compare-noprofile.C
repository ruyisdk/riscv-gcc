/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#if defined(__riscv_ztt_mcmovge_ew_int) \
    || defined(__riscv_ztt_mcmovlt_ew_int) \
    || defined(__riscv_ztt_mcmpge_ew_int) \
    || defined(__riscv_ztt_mcmplt_ew_int) \
    || defined(__riscv_ztt_mselge_ew_int) \
    || defined(__riscv_ztt_msellt_ew_int) \
    || defined(__riscv_ztt_mcmpge_ew_x_int) \
    || defined(__riscv_ztt_mcmplt_ew_x_int)
#error comparison capability leaked outside Ztt/profile
#endif
#pragma riscv intrinsic "ztt" /* { dg-error "requires .*-mztt-profile=" } */
