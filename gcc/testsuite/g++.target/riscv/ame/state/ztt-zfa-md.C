/* { dg-do compile } */
/* { dg-options "-O2 -fsignaling-nans -DFP_DOUBLE -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32imafd_zicsr_zfa_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64imafd_zicsr_zfa_ztt0p6 -mabi=lp64d" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-fenv-md.h"
/* { dg-final { scan-assembler-times {\tfrflags\t} 1 } } */
/* { dg-final { scan-assembler-times {\tfsflagsi?\t} 2 } } */
/* { dg-final { scan-assembler-times {\tfltq\.d\t} 4 } } */
/* { dg-final { scan-assembler-times {\tfleq\.d\t} 2 } } */
/* { dg-final { scan-assembler-times {\tfeq\.d\tzero,} 6 } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for common preparation at insn [0-9]+: 6} 8 "ztt_md_reuse" } } */
