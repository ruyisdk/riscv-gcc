/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zbb -mabi=ilp32 -O2" } */

unsigned long
rori_4 (unsigned long i)
{
  return (i >> 31) | (i << 1);
}


unsigned long
rori_5 (unsigned long i)
{
  return (i >> 1) | (i << 31);
}

/* { dg-final { scan-assembler-times "rori\t" 2 } } */
