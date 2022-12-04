/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zbb -mabi=lp64 -O2" } */

unsigned int rev(unsigned int i)
{
  int j;
  unsigned int ret = (((i << 24) >> 24) << 24)
    | (((i << 16) >> 24) << 16)
    | (((i << 8) >> 24) << 8)
    | (i >> 24);

  return ret;
}

/* { dg-final { scan-assembler-times "rev8\t" 1 } } */
/* { dg-final { scan-assembler-times "srai\t" 1 } } */