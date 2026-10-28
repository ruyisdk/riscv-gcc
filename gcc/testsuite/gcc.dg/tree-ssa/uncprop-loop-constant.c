/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -fno-tree-vectorize -fdump-tree-uncprop-details" } */
#include "uncprop-loop-constant.h"
/* { dg-final { scan-tree-dump "Retaining cheap loop latch constant" "uncprop1" } } */
