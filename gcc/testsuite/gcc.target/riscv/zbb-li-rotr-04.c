/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zbb -mabi=lp64 -O2" } */

unsigned int
rori_4 (unsigned int i)
{
  return (i >> 31) | (i << 1);
}


unsigned int
rori_5 (unsigned int i)
{
  return (i >> 1) | (i << 31);
}

/* { dg-final { scan-assembler-times "roriw\t" 2 } } */
