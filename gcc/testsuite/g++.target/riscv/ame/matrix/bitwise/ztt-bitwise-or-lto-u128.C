/* integer bitwise OR.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-bitwise-or-lto.C" } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,or_entry" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,or_entry" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/bitwise/ztt-bitwise-or-body.h"
extern "C" {
extern int or_aux (void);
int or_entry (void) { return or_aux (); }
}
