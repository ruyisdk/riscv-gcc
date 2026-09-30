/* runtime-N resource profiles.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
/* { dg-error "requires the .*ztt0p6.* ISA extension" "" { target *-*-* } 0 } */
