/* { dg-do compile } */
/* { dg-options "-march=rv64gcq -mabi=lp64q -O0" } */

long double foo(long double a, long double b)
{
  return a + b;
}

long double foo2(long double a, long double b)
{
  return a - b;
}

/* { dg-final { scan-assembler-times {\mfadd\.q\M} 1 } } */
/* { dg-final { scan-assembler-times {\mfsub\.q\M} 1 } } */

