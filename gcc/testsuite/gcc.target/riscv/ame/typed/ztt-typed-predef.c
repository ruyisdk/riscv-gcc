/* { dg-do compile } */
/* { dg-options "-march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#if __riscv_ztt != 6000
#error "unexpected Ztt ISA version"
#endif
#if __riscv_ztt_intrinsic != 2002
#error "unexpected Ztt intrinsic interface version"
#endif
#if __riscv_ztt_profile != 1
#error "unexpected Ztt profile identifier"
#endif
#if __riscv_ztt_nelem != 16384
#error "unexpected AME_NELEM"
#endif
#if __riscv_ztt_n != 128
#error "unexpected N"
#endif
#if __riscv_ztt_uds != 8
#error "unexpected UDS"
#endif
#if __riscv_ztt_mregs != 16
#error "unexpected M register count"
#endif
#if __riscv_ztt_accregs != 4
#error "unexpected accumulator register count"
#endif
