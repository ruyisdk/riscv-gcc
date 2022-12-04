/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zbb -mabi=lp64 -O2" } */

unsigned long
clzl (unsigned long i)
{
  return __builtin_clzl (i);
}

unsigned long
ctzl (unsigned long i)
{
  return __builtin_ctzl (i);
}

unsigned long
popcountl (unsigned long i)
{
  return __builtin_popcountl (i);
}


/* { dg-final { scan-assembler-times "clz\t" 1 } } */
/* { dg-final { scan-assembler-times "ctz\t" 1 } } */
/* { dg-final { scan-assembler-times "cpop\t" 1 } } */
