typedef __UINTPTR_TYPE__ uintptr_t;

void
fill_pair (char *a, char *b, const char *c, __SIZE_TYPE__ offset)
{
  if (((uintptr_t) a | (uintptr_t) b | (uintptr_t) c) & 15)
    return;
  __builtin_memcpy (a + 2 * offset, "\0", 2);
  __builtin_memcpy (b + 2 * offset, "\0\200", 2);
}
