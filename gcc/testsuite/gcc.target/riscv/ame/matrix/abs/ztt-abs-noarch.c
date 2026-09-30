/* mabs.ew.  */
/* { dg-do preprocess { target rv64 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" } */
#ifdef __riscv_ztt_mabs_ew_int
#error absolute value capability must require Ztt and a typed profile
#endif
