/* integer bitwise ANDNOT.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_mandnot_ew_int_same
#error "bitwise ANDNOT needs Ztt and a typed profile"
#endif
int unused;
