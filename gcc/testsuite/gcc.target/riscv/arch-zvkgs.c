/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zvkgs -mabi=lp64d" } */

int
foo ()
{
}

/* { dg-final { scan-assembler "zve32x1p0_zvkg1p0_zvkgs0p7_zvl32b1p0" } } */
