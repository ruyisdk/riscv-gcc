/* { dg-do compile } */
/* { dg-options "-mriscv-attribute -march=rv64iq -mabi=lp64q" } */

void foo(){}

/* { dg-final { scan-assembler ".attribute arch, \"rv64i2p1_f2p2_d2p2_q2p2_zicsr2p0\"" } } */


