/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#define NSHAPE 1x1
#include "../../../../gcc.target/riscv/ame/types/ztt-nominal-families.h"
/* { dg-final { scan-assembler "madd.ew.x" } } */
/* { dg-final { scan-assembler "msub.ew.x" } } */
/* { dg-final { scan-assembler "mmul.ew.x" } } */
/* { dg-final { scan-assembler "mabsdiff.ew.x" } } */
/* { dg-final { scan-assembler "mhdiff.ew.x" } } */
/* { dg-final { scan-assembler "mmean.ew.x" } } */
/* { dg-final { scan-assembler "mmulneg.ew.x" } } */
/* { dg-final { scan-assembler "mmin.ew.x" } } */
/* { dg-final { scan-assembler "mmax.ew.x" } } */
/* { dg-final { scan-assembler "mand.ew.x" } } */
/* { dg-final { scan-assembler "mandnot.ew.x" } } */
/* { dg-final { scan-assembler "mor.ew.x" } } */
/* { dg-final { scan-assembler "mornot.ew.x" } } */
/* { dg-final { scan-assembler "mxor.ew.x" } } */
/* { dg-final { scan-assembler "mmulacc.ew.x" } } */
/* { dg-final { scan-assembler "mmulaccneg.ew.x" } } */
/* { dg-final { scan-assembler "mmuladd.ew.x" } } */
/* { dg-final { scan-assembler "mmulsub.ew.x" } } */
/* { dg-final { scan-assembler "mcmpge.ew.x" } } */
/* { dg-final { scan-assembler "mcmplt.ew.x" } } */
/* { dg-final { scan-assembler "mlog2sub.ew.x" } } */
/* { dg-final { scan-assembler "msublog2.ew.x" } } */
/* { dg-final { scan-assembler "mbcast.m.x" } } */
/* { dg-final { scan-assembler "msll.ew.x" } } */
/* { dg-final { scan-assembler "mldexp.ew.x" } } */
/* { dg-final { scan-assembler-not {call[ \t]+__riscv_ztt_} } } */
