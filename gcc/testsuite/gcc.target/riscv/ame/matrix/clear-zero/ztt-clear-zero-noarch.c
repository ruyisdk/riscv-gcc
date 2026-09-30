/* Experimental single-M clear/zero names from intrinsic draft v0.2.4.  */
/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr -mabi=lp64" { target rv64 } } */

#ifdef __riscv_ztt_i8_rne_1x1_clear_zero
#error capability must require Ztt
#endif
