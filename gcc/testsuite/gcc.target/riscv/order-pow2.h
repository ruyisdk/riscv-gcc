#ifdef __cplusplus
extern "C" {
#endif

int
length_guard (unsigned long accumulate, unsigned long rows, unsigned long ptr)
{
  if (accumulate > 1)
    return 1;
  if (!rows)
    return 0;
  if (!ptr)
    return 1;
  if (rows > (~0UL / 4) || (ptr & 3))
    return 1;
  return 0;
}

int
length_valid (unsigned long accumulate, unsigned long rows, unsigned long ptr)
{
  if (accumulate > 1)
    return 0;
  if (!rows)
    return 1;
  if (!ptr)
    return 0;
  return rows < (1UL << (__SIZEOF_LONG__ * 8 - 2)) && !(ptr & 3);
}

#ifdef __cplusplus
}
#endif
