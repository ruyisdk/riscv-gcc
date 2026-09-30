/* integer folds.  */
/* { dg-do preprocess { target rv64 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" } */
#if defined (__riscv_ztt_mreduceadd_col_int) \
    || defined (__riscv_ztt_mreduceadd_row_int) \
    || defined (__riscv_ztt_mreducemax_col_int) \
    || defined (__riscv_ztt_mreducemax_row_int) \
    || defined (__riscv_ztt_mreducemin_col_int) \
    || defined (__riscv_ztt_mreducemin_row_int) \
    || defined (__riscv_ztt_mprefixadd_col_int) \
    || defined (__riscv_ztt_mprefixadd_row_int) \
    || defined (__riscv_ztt_mprefixmax_col_int) \
    || defined (__riscv_ztt_mprefixmax_row_int)
#error structural capability requires Ztt and a typed profile
#endif
