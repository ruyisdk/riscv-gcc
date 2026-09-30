/* integer subtraction.  */
/* { dg-do link } */
/* { dg-additional-sources "auxiliary/ztt-sub-lto.C" } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,sub_entry" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1 -flto=1 -nostdlib -Wl,--export-dynamic -Wl,-e,sub_entry" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/sub/ztt-sub-body.h"
extern "C" {
extern int sub_aux (void);
int sub_entry (void) { return sub_aux (); }
}
