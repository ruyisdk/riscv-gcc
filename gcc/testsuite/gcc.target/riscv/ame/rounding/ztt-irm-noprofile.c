/* single-M
   i8 integer rounding-mode subset.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -fdiagnostics-plain-output -march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */

#ifdef __riscv_ztt_i8_1x1_irm
#error integer RM capability requires both Ztt and a typed profile
#endif
