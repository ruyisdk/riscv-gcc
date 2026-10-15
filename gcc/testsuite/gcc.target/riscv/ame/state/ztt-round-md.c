/* { dg-do compile } */
/* { dg-options "-O2 -fsignaling-nans -frounding-math -fno-math-errno -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32imafd_zicsr_zfa_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64imafd_zicsr_zfa_ztt0p6 -mabi=lp64d" { target rv64 } } */
#include "ztt-round-md.h"
/* { dg-final { scan-assembler-times {\tfround\.s\t} 6 } } */
/* { dg-final { scan-assembler-times {\tfroundnx\.s\t} 3 } } */
/* { dg-final { scan-assembler-times {\tfcvt\.[wl]\.s } 4 } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for common preparation at insn [0-9]+: 6} 12 "ztt_md_reuse" } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for common preparation at insn [0-9]+: 4} 2 "ztt_md_reuse" } } */
