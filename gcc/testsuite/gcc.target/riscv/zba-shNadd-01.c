/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zba_zbs -mabi=lp64 -O2" } */

long test_1(long a, long b)
{
  return a + (b << 1);
}
long test_2(long a, long b)
{
  return a + (b << 2);
}
long test_3(long a, long b)
{
  return a + (b << 3);
}

unsigned long test_4(unsigned long a, unsigned long b)
{
  return a + ((unsigned long)(unsigned int)b << 1);
}

unsigned long test_5(unsigned long a, unsigned long b)
{
  return a + ((unsigned long)(unsigned int)b << 2);
}

unsigned long test_6(unsigned long a, unsigned long b)
{
  return a + ((unsigned long)(unsigned int)b << 3);
}

/* { dg-final { scan-assembler-times "sh1add\t" 1 } } */
/* { dg-final { scan-assembler-times "sh2add\t" 1 } } */
/* { dg-final { scan-assembler-times "sh3add\t" 1 } } */
/* { dg-final { scan-assembler-times "sh1add.uw" 1 } } */
/* { dg-final { scan-assembler-times "sh2add.uw" 1 } } */
/* { dg-final { scan-assembler-times "sh3add.uw" 1 } } */