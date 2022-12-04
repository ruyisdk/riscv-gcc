/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zbb -mabi=ilp32 -O2" } */

unsigned long rev(unsigned long i)
{
  int j;
  unsigned long ret = (((i << 24) >> 24) << 24)
    | (((i << 16) >> 24) << 16)
    | (((i << 8) >> 24) << 8)
    | (i >> 24);

  return ret;
}

/* { dg-final { scan-assembler-times "rev8\t" 1 } } */
