/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zbb -mabi=lp64 -O2" } */

unsigned long
rori_4 (unsigned long i)
{
  return (i >> 63) | (i << 1);
}


unsigned long
rori_5 (unsigned long i)
{
  return (i >> 1) | (i << 63);
}

/* { dg-final { scan-assembler-times "rori\t" 2 } } */
