/* integer bitwise ANDNOT.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-bitwise-andnot-lto.c" } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,andnot_entry" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,andnot_entry" { target rv64 } } */
#include "ztt-bitwise-andnot-body.h"
extern int andnot_aux (void);
int andnot_entry (void) { return andnot_aux (); }
