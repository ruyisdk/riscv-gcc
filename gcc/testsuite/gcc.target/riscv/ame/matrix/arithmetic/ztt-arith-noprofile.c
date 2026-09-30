/* integer arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
#if defined(__riscv_ztt_madd_ew_int_mixed) || \
    defined(__riscv_ztt_msub_ew_int_mixed) || \
    defined(__riscv_ztt_mabsdiff_ew_int_mixed) || \
    defined(__riscv_ztt_mhdiff_ew_int_mixed) || \
    defined(__riscv_ztt_mmean_ew_int_mixed) || \
    defined(__riscv_ztt_mmulneg_ew_int_mixed)
#error unexpected arithmetic capability
#endif
#pragma riscv intrinsic "ztt" /* { dg-error "requires .*-mztt-profile=gcc-p0-n128-u8-m16-a4.*" } */
