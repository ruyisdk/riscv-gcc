/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zbb -mabi=lp64 -O2" } */

unsigned long rev(unsigned long i)
{
  int j;
  unsigned long ret = (((i << 56) >> 56) << 56)
    | (((i << 48) >> 56) << 48)
    | (((i << 40) >> 56) << 40)
    | (((i << 32) >> 56) << 32)
    | (((i << 24) >> 56) << 24)
    | (((i << 16) >> 56) << 16)
    | (((i << 8) >> 56) << 8)
    | (i >> 56);

  return ret;
}

/* { dg-final { scan-assembler-times "rev8\t" 1 } } */
