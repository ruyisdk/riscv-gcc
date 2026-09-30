/* mconv.ew.  */
/* { dg-do preprocess { target rv64 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" } */
#ifdef __riscv_ztt_mconv_ew_int
#error conversion capability must require Ztt and a typed profile
#endif
