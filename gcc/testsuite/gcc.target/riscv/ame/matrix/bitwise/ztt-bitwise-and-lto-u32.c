/* integer bitwise AND.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-bitwise-and-lto.c" } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,and_entry" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,and_entry" { target rv64 } } */
#include "ztt-bitwise-and-body.h"
extern int and_aux (void);
int and_entry (void) { return and_aux (); }
