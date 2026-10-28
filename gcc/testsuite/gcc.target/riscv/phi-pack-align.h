typedef __SIZE_TYPE__ size_type;
typedef __UINTPTR_TYPE__ address_type;
typedef __UINT32_TYPE__ unaligned_u32 __attribute__((aligned(1), may_alias));

#ifndef RESIDUE
#define RESIDUE 0
#endif

#define PACK(NAME, STORE) \
void NAME (char *dst, const char *src, size_type tile, size_type rows, \
           size_type cols, size_type stride) \
{ \
  if (!tile || !rows || !cols || (address_type) dst % 4 != RESIDUE \
      || (address_type) src % 4 != RESIDUE) return; \
  for (size_type r = 0; r < tile; ++r) \
    for (size_type c = 0; c < tile; ++c) \
      if (c >= cols) \
        { STORE; } \
      else \
        __builtin_memcpy (dst + 4 * (r * tile + c), \
                          src + 4 * ((r < rows ? r : rows-1) * stride + c), 4); \
}

PACK (padding_memset, __builtin_memset (dst + 4 * (r * tile + c), 0, 4))
PACK (padding_scalar, *(unaligned_u32 *) (dst + 4 * (r * tile + c)) = 0)
PACK (padding_literal, __builtin_memcpy (dst + 4 * (r * tile + c), "\0\0\0\200", 4))
