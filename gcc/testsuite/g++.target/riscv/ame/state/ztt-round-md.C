/* { dg-do compile } */
/* { dg-options "-O2 -fsignaling-nans -frounding-math -fno-math-errno -DFP_DOUBLE -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv32imafd_zicsr_zfa_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64imafd_zicsr_zfa_ztt0p6 -mabi=lp64d" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-round-md.h"
/* { dg-final { scan-assembler-times {\tfround\.d\t} 6 } } */
/* { dg-final { scan-assembler-times {\tfroundnx\.d\t} 3 } } */
/* { dg-final { scan-assembler-times {\tfcvt\.[wl]\.d } 4 } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for common preparation at insn [0-9]+: 6} 12 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for common preparation at insn [0-9]+: 4} 2 "ztt_md_reuse" } } */
