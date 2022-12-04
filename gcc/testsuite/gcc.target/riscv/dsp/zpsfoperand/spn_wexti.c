/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

long long test_wexti1(long long a)
{
  return a >> 1;
}

/* { dg-final { scan-assembler "wexti\t" } }*/

unsigned long long test_wexti2(unsigned long long a)
{
  return a >> 1;
}

/* { dg-final { scan-assembler "wexti\t" } }*/


long long test_wexti3(long long a)
{
  return a << 1;
}

/* { dg-final { scan-assembler "wexti\t" } }*/

/* { dg-final { cleanup-saved-temps } } */
