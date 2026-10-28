#ifdef __cplusplus
extern "C" {
#endif

#define COPY(NAME, VALUE) \
void NAME (unsigned char *p) \
{ \
  __UINT16_TYPE__ value = VALUE; \
  __builtin_memcpy (p, &value, sizeof value); \
}

COPY (copy_high, 0x8000)
COPY (copy_low, 0x0080)
COPY (copy_mixed, 0x1280)

void
copy_loop (unsigned char *p, unsigned int n)
{
  for (unsigned int i = 0; i < n; ++i)
    {
      __UINT16_TYPE__ value = 0x8000;
      __builtin_memcpy (p + 3 * i, &value, sizeof value);
    }
}

#undef COPY
#ifdef __cplusplus
}
#endif
