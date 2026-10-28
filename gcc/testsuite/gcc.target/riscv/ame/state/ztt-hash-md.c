/* { dg-do compile } */
/* { dg-options "-O2 -fno-strict-aliasing -march=rv64ima_zicsr_zknh_zksh_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fdump-rtl-ztt_md_reuse" { target { rv64 } } } */
/* { dg-options "-O2 -fno-strict-aliasing -march=rv32ima_zicsr_zknh_zksh_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fdump-rtl-ztt_md_reuse" { target { rv32 } } } */
#include "ztt-hash-md.h"
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 3} 13 "ztt_md_reuse" { target rv32 } } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 3} 11 "ztt_md_reuse" { target rv64 } } } */
/* { dg-final { scan-rtl-dump-times {Reuse Md for binary at insn [0-9]+: sources 2} 2 "ztt_md_reuse" } } */
/* { dg-final { scan-assembler {sha256sig0} } } */
/* { dg-final { scan-assembler {sha512sig0} } } */
/* { dg-final { scan-assembler {sm3p0} } } */
