#ifdef __cplusplus
extern "C" {
#endif

#define PACK(NAME, TYPE, QUAL, PAD) \
__attribute__((noipa)) void \
NAME (QUAL TYPE *dst, const TYPE *src, unsigned long n, \
      unsigned long rows, unsigned long cols, unsigned long stride, TYPE pad) \
{ \
  for (unsigned long r = 0; r < n; ++r) \
    for (unsigned long c = 0; c < n; ++c) \
      dst[r * n + c] = r < rows && c < cols ? src[r * stride + c] : PAD; \
}

PACK (pack8, unsigned char, , 0)
PACK (pack16, unsigned short, , 0)
PACK (pack32, unsigned int, , 0)
PACK (packword, unsigned long, , 0)
PACK (nonzero8, unsigned char, , 7)
PACK (dynamic8, unsigned char, , pad)
PACK (volatile8, unsigned char, volatile, 0)

extern unsigned long value_source (void);

__attribute__((noipa)) unsigned long
call_value (unsigned char *p)
{
  unsigned long v = 0;
  *p = v;
  v = value_source ();
  p[1] = v;
  return v;
}

__attribute__((noipa)) unsigned long
asm_value (unsigned char *p)
{
  unsigned long v = 0;
  __asm__ volatile ("" : "+r" (v));
  *p = v;
  return v;
}

#undef PACK
#ifdef __cplusplus
}
#endif
