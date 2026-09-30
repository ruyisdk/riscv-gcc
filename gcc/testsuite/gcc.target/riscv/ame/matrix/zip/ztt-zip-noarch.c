/* distinct in/out M objects.  */
/* { dg-do preprocess { target rv64 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" } */
#if defined (__riscv_ztt_mcolzip_ew_int) \
    || defined (__riscv_ztt_mrowzip_ew_int) \
    || defined (__riscv_ztt_mcolunzip_ew_int) \
    || defined (__riscv_ztt_mrowunzip_ew_int)
#error zip capability requires Ztt and a typed profile
#endif
