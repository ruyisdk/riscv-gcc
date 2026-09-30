/* integer index constructors.  */
/* { dg-do preprocess { target rv64 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" } */
#if defined (__riscv_ztt_mrowid_ew_int) || defined (__riscv_ztt_mcolid_ew_int)
#error constructors require Ztt and a typed profile
#endif
