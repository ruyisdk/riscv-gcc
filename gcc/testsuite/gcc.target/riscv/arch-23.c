/* { dg-do compile } */
/* { dg-options "-march=rv64if_zce -mabi=lp64" } */
int foo() {}
/* { dg-error "'-march=rv64if_zce': zcf extension supports in rv32 only" "" { target *-*-* } 0 } */
/* { dg-error "'-march=rv64if_zca_zcb_zce_zcf_zcmp_zcmt': zcf extension supports in rv32 only" "" { target *-*-* } 0 } */
