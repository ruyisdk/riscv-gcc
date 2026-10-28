/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -fno-tree-vectorize -fdump-tree-lim2-details" } */
#include "lim-aligned-self-copy.h"
/* { dg-final { scan-tree-dump-times "independent \\(self write\\)" 3 "lim2" } } */
