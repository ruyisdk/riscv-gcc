/* runtime-N resource profiles.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-n32-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-n32-u8-m32-a16" { target rv64 } } */
/* { dg-error "unknown AME/Ztt target profile" "" { target *-*-* } 0 } */
