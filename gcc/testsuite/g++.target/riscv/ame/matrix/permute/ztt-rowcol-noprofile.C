/* controls.  */
/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_mcolbcast_ew_x_int
#error row/column capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mrowbcast_ew_x_int
#error row/column capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mcolshift_ew_x_int
#error row/column capability requires Ztt and a typed profile
#endif
#ifdef __riscv_ztt_mrowshift_ew_x_int
#error row/column capability requires Ztt and a typed profile
#endif
int gate;
