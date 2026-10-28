/* { dg-do compile } */
/* { dg-options "-O2 -mstrict-align -fno-tree-vectorize -fno-tree-slp-vectorize" } */

#include "../../gcc.target/riscv/loop-pointer-align.h"

/* { dg-final { scan-assembler "\\tlw\\t" } } */
/* { dg-final { scan-assembler "\\tsw\\t" } } */
/* { dg-final { scan-assembler-not "\\tlbu\\t" } } */
/* { dg-final { scan-assembler-not "\\tsb\\t" } } */
