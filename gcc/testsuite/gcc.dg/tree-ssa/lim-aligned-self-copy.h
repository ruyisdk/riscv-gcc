#ifdef __cplusplus
extern "C" {
#endif
#define FN __attribute__((noipa))
typedef __UINT16_TYPE__ u16;
typedef __UINT32_TYPE__ u32;
typedef __SIZE_TYPE__ size_t;
typedef u16 ua16 __attribute__((aligned(1), may_alias));

FN void half (u16 *dst, const u16 *src, size_t n)
{
  for (size_t i = 0; i < n; ++i)
    dst[i] = *src;
}

FN void word (u32 *dst, const u32 *src, size_t n)
{
  for (size_t i = 0; i < n; ++i)
    dst[i] = *src;
}

FN void aligned (char *dst, const char *src, size_t n)
{
  dst = (char *) __builtin_assume_aligned (dst, 16);
  src = (const char *) __builtin_assume_aligned (src, 16);
  for (size_t i = 0; i < n; ++i)
    __builtin_memcpy (dst + 2 * i, src, 2);
}

FN void unaligned (char *dst, const char *src, size_t n)
{
  for (size_t i = 0; i < n; ++i)
    *(ua16 *) (dst + 2 * i) = *(const ua16 *) src;
}

FN void partial (char *dst, const char *src, size_t n)
{
  for (size_t i = 0; i < n; ++i)
    *(ua16 *) (dst + i) = *(const ua16 *) src;
}

FN void changed (u16 *dst, const u16 *src, size_t n)
{
  for (size_t i = 0; i < n; ++i)
    dst[i] = *src + 1;
}

FN void vol (volatile u16 *dst, const volatile u16 *src, size_t n)
{
  for (size_t i = 0; i < n; ++i)
    dst[i] = *src;
}

FN void clobber (u16 *dst, u16 *src, size_t n)
{
  for (size_t i = 0; i < n; ++i)
    {
      dst[i] = *src;
      *src ^= 1;
    }
}
#ifdef __cplusplus
}
#endif
