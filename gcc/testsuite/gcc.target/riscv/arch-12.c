/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32efd -mabi=ilp32e" } */
int foo()
{
}

/* { dg-error "RV32E must not be used with the D ISA extension" "" { target *-*-* } 0 } */
