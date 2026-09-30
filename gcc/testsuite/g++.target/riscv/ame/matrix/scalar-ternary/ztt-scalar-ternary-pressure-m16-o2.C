/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "../../../../../gcc.target/riscv/ame/matrix/scalar-ternary/ztt-scalar-ternary-pressure.h"
/* { dg-final { scan-assembler {mmulacc\.ew\.x[ \t]} } } */
/* { dg-final { scan-assembler {mmulaccneg\.ew\.x[ \t]} } } */
/* { dg-final { scan-assembler {mmuladd\.ew\.x[ \t]} } } */
/* { dg-final { scan-assembler {mmulsub\.ew\.x[ \t]} } } */
/* { dg-final { scan-assembler {mss\.1r[ \t]} } } */
/* { dg-final { scan-assembler {mls\.1r[ \t]} } } */
