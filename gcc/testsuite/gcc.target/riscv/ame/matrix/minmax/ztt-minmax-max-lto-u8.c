/* integer maximum.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-minmax-max-lto.c" } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,max_entry" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,max_entry" { target rv64 } } */
#include "ztt-minmax-max-body.h"
extern int max_aux (void);
int max_entry (void) { return max_aux (); }
