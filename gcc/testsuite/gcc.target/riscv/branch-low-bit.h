#define CLEAR(TYPE, NAME) \
  void NAME (TYPE *p, unsigned long n) \
  { \
    for (unsigned long i = 0; i < n; ++i) \
      p[i] = 0; \
  }

CLEAR (unsigned short, clear16)
CLEAR (unsigned int, clear32)
CLEAR (unsigned long long, clear64)

extern void sink (void);

void
bit_set (unsigned long x)
{
  if ((x >> 10) & 1)
    sink ();
}

void
bit_clear (unsigned long x)
{
  if (!((x >> 10) & 1))
    sink ();
}
