#define LIMIT (1UL << (__SIZEOF_LONG__ * 8 - 2))

unsigned long
shared_lt (unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
  return (a < LIMIT) + (b < LIMIT) + (c < LIMIT) + (d < LIMIT);
}

unsigned long
threshold_live (unsigned long a, unsigned long b, unsigned long c)
{
  return (a < LIMIT) + (b < LIMIT) + (c < LIMIT) + LIMIT;
}
