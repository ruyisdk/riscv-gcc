/* integer minimum.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-minmax-min-lto.C" } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,min_entry" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,min_entry" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/minmax/ztt-minmax-min-body.h"
extern "C" {
extern int min_aux (void);
int min_entry (void) { return min_aux (); }
}
