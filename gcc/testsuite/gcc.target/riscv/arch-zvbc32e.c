/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zvbc32e -mabi=lp64d" } */

int
foo ()
{
}

/* { dg-final { scan-assembler "zvbc32e0p7_zve32x1p0_zvl32b1p0" } } */
