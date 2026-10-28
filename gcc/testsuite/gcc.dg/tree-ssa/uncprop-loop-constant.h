#ifdef __cplusplus
extern "C" {
#endif

typedef __SIZE_TYPE__ size_type;
#define FN __attribute__((noipa))

FN int
outside (size_type flag, size_type n, unsigned *out)
{
  if (!(flag & 1))
    return 0;
  size_type q = 2;
  for (size_type i = 0; i < n; ++i)
    {
      out[i] = out[i] * 3 + q;
      q = 1;
    }
  return 0;
}

FN int
outside_zero (size_type flag, size_type n, unsigned *out)
{
  if (flag)
    return 0;
  size_type q = 1;
  for (size_type i = 0; i < n; ++i)
    {
      out[i] = out[i] * 3 + q;
      q = 0;
    }
  return 0;
}

FN int
inside (size_type flag, size_type n, unsigned *out)
{
  size_type bit = flag & 1;
  if (!bit)
    return 0;
  for (size_type q = 0; q < 2; ++q)
    for (size_type i = 0; i < n; ++i)
      {
        __asm__ volatile ("" : "+r" (bit));
        out[i] = out[i] * 3 + q + bit;
      }
  return 1;
}

FN size_type
local_phi (size_type flag, size_type x)
{
  if (flag == 1)
    x = 1;
  return x;
}

FN int
large (size_type flag, size_type n, unsigned *out)
{
  if (flag != 4096)
    return 0;
  for (size_type q = 0; q < 4097; q += 4096)
    for (size_type i = 0; i < n; ++i)
      out[i] = out[i] * 3 + q;
  return 1;
}

FN int
loop_local (size_type n, unsigned *out)
{
  unsigned seen = 0;
  for (size_type i = 0; i < n; ++i)
    {
      if (!out[i])
        continue;
      if (!seen)
        seen = 1;
      else
        out[i] += seen;
    }
  return seen;
}

#undef FN
#ifdef __cplusplus
}
#endif
