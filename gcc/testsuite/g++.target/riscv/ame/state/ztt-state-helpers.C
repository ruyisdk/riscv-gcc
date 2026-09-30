/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/state/ztt-state-helpers.h"
/* { dg-final { scan-assembler-times {csrr\t[^,]+,ameown} 4 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amestype} 2 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amenlen} 2 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,ameudsz} 2 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amefflags} 2 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amexsat} 2 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amestatus} 2 } } */
/* { dg-final { scan-assembler-times {ame\.acquire} 2 } } */
/* { dg-final { scan-assembler-times {ame\.release} 2 } } */
/* { dg-final { scan-assembler {ameown(.|\n)*ame\.release(.|\n)*ame\.acquire(.|\n)*ameown} } } */
/* { dg-final { scan-assembler-not {csrw|s11|msettyp|asettyp|call\s} } } */
