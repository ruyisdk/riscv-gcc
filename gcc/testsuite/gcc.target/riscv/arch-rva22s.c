/* { dg-do compile } */
/* { dg-options "-march=rva22s64 -mabi=lp64d" } */

void foo(){}

/* { dg-final { scan-assembler-times ".attribute arch, \"rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_b1p0"
"_zic64b1p0_zicbom1p0_zicbop1p0_zicboz1p0_ziccamoa1p0_ziccif1p0_zicclsm1p0_ziccrse1p0"
"_zicntr2p0_zicsr2p0_zifencei2p0_zihintpause2p0_zmmul1p0_za64rs1p0_zaamo1p0_zalrsc1p0"
"_zfhmin1p0_zca1p0_zcd1p0_zba1p0_zbb1p0_zbs1p0_zkt1p0_ssccptr1p0_sscounterenw1p0"
"_sstvala1p0_sstvecd1p0_svade1p0_svbare1p0_svinval1p0_svpbmt1p0\" 1} } */
