/* basic-square indexed API.  */
/* { dg-do preprocess { target rv64 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" } */
#if defined (__riscv_ztt_mcolgather_ew_int) \
    || defined (__riscv_ztt_mrowgather_ew_int) \
    || defined (__riscv_ztt_mcolscatadd_ew_int) \
    || defined (__riscv_ztt_mrowscatadd_ew_int) \
    || defined (__riscv_ztt_mcolscatmax_ew_int) \
    || defined (__riscv_ztt_mrowscatmax_ew_int)
#error indexed capability requires Ztt and a typed profile
#endif
