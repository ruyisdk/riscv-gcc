/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-ztt_md_reuse -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32imafd_zicsr_ztt0p6 -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64imafd_zicsr_ztt0p6 -mabi=lp64d" { target rv64 } } */
#include "ztt-scalar-fp-md.h"
/* { dg-final { scan-assembler-times {fmin\.s} 3 } } */
/* { dg-final { scan-assembler-times {fmax\.s} 1 } } */
/* { dg-final { scan-assembler-times {fsgnj\.s} 1 } } */
/* { dg-final { scan-assembler-times {fclass\.s} 1 } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for common preparation at insn [0-9]+: 6} 5 "ztt_md_reuse" } } */
