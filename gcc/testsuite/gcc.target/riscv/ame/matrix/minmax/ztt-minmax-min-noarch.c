/* integer minimum.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv32im_zicsr -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf  -march=rv64im_zicsr -mabi=lp64" { target rv64 } } */
#ifdef __riscv_ztt_mmin_ew_int_same
#error "minimum needs Ztt and a typed profile"
#endif
int unused;
