/* Large packed RNU aliases, ordinary pointer ABI.  */
/* { dg-do link } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,packed_entry -DTEST_K=8 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -flto -nostdlib -Wl,--export-dynamic -Wl,-e,packed_entry -DTEST_K=8 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv64 } } */
/* { dg-additional-sources "auxiliary/ztt-acc-packed-large-lto.c" } */
#include "ztt-acc-packed-large-alias-body.h"
