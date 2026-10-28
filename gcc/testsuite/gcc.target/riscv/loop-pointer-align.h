typedef __SIZE_TYPE__ size_t;
typedef __UINTPTR_TYPE__ uintptr_t;

void
pack (char *dst, const char *src, size_t tile, size_t rows, size_t offset)
{
#ifndef RESIDUE
#define RESIDUE 0
#endif
  if (!tile || !rows
      || (uintptr_t) dst % 4 != RESIDUE
      || (uintptr_t) src % 4 != RESIDUE)
    return;
  for (size_t r = 0; r < tile; ++r)
    for (size_t c = 0; c < tile; ++c)
      {
        size_t rr = r < rows ? r : rows - 1;
        __builtin_memcpy (dst + 4 * (r * tile + c),
                          src + 4 * (rr + offset), 4);
      }
}
