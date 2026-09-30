/* integer bitwise ORNOT.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-bitwise-ornot-lto.c" } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,ornot_entry" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,ornot_entry" { target rv64 } } */
#include "ztt-bitwise-ornot-body.h"
extern int ornot_aux (void);
int ornot_entry (void) { return ornot_aux (); }
