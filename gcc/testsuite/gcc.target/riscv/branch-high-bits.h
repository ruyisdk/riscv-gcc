#ifdef __cplusplus
extern "C" {
#endif

extern unsigned long hit (unsigned long);
extern unsigned long miss (unsigned long);
#define LIMIT (1UL << (sizeof (long) * 8 - 2))

unsigned long
branch_high_gt (unsigned long x)
{
  return x > LIMIT - 1 ? hit (x) : miss (x);
}

unsigned long
branch_high_le (unsigned long x)
{
  return x <= LIMIT - 1 ? hit (x) : miss (x);
}

unsigned long
branch_cheap (unsigned long x)
{
  return x > 255 ? hit (x) : miss (x);
}

unsigned long
shared_compare (unsigned long a, unsigned long b, unsigned long c)
{
  return (a < LIMIT) + (b < LIMIT) + (c < LIMIT) + LIMIT;
}

#ifdef __cplusplus
}
#endif
