#ifdef __cplusplus
extern "C" {
#endif

void copy_word (unsigned char *p)
{
  __UINT32_TYPE__ value = 0x80000000u;
  __builtin_memcpy (p, &value, 4);
}

void copy_mixed (unsigned char *p)
{
  __UINT32_TYPE__ value = 0x12805678u;
  __builtin_memcpy (p, &value, 4);
}

void copy_literal (unsigned char *p)
{
  __builtin_memcpy (p, "\x80\x01\x7f\x12", 4);
}

#if __riscv_xlen == 64
void copy_long (unsigned char *p)
{
  __UINT64_TYPE__ value = 0x123456789abcdef0ULL;
  __builtin_memcpy (p, &value, 8);
}
#endif

#ifdef __cplusplus
}
#endif
