/* { dg-do compile } */
/* { dg-options "-march=rva20s64 -mabi=lp64d" } */

void foo(){}

/* { dg-final { scan-assembler-times ".attribute arch, \"rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0"
"_ziccamoa1p0_ziccif1p0_zicclsm1p0_ziccrse1p0_zicntr2p0_zicsr2p0_zifencei2p0_zmmul1p0"
"_za128rs1p0_zaamo1p0_zalrsc1p0_zca1p0_zcd1p0_ssccptr1p0_sstvala1p0_sstvecd1p0"
"_svade1p0_svbare1p0\" 1} } */
