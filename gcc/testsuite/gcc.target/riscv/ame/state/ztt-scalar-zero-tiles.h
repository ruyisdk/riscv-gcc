#ifdef __cplusplus
extern "C"
#endif
__attribute__((noipa)) void
tiles (unsigned char *dst, const unsigned char *src, unsigned long n,
       unsigned long rows, unsigned long cols, unsigned long stride)
{
  for (unsigned long q = 0; q < 4; ++q)
    for (unsigned long r = 0; r < n; ++r)
      for (unsigned long c = 0; c < n; ++c)
        dst[(q * n + r) * n + c]
          = r < rows && q * n + c < cols ? src[r * stride + q * n + c] : 0;
}
