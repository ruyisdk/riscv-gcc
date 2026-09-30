/* data-scalar arithmetic.  */
/* { dg-do preprocess } */
/* { dg-options "-march=rv32im_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_madd_ew_x_int
#error data-scalar capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_msub_ew_x_int
#error data-scalar capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mabsdiff_ew_x_int
#error data-scalar capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mhdiff_ew_x_int
#error data-scalar capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mmean_ew_x_int
#error data-scalar capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mmul_ew_x_int
#error data-scalar capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mmulneg_ew_x_int
#error data-scalar capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mmin_ew_x_int
#error data-scalar capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mmax_ew_x_int
#error data-scalar capability requires Ztt and a typed profile
#endif
