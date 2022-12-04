/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zbb -mabi=lp64 -O2" } */

long
foo1 (long i)
{
  return (long)(signed char)i;
}

long
foo2 (long i)
{
  return (long)(signed short)i;
}

/* { dg-final { scan-assembler "sext.b" } } */
/* { dg-final { scan-assembler "sext.h" } } */
