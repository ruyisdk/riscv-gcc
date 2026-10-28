#include <stdint.h>
#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void index_helper (void);

#define TEST(T, E) \
  void row_##T (E *p) \
  { __riscv_ztt_mss_rm (p, __riscv_ztt_mrowid_ew_##T##_1x1 ()); } \
  void dead_##T (void) \
  { (void) __riscv_ztt_mrowid_ew_##T##_1x1 (); } \
  void branch_##T (E *p, int choose) \
  { if (choose) __riscv_ztt_mss_rm (p, __riscv_ztt_mrowid_ew_##T##_1x1 ()); } \
  void call_##T (E *p) \
  { index_helper (); __riscv_ztt_mss_rm (p, __riscv_ztt_mcolid_ew_##T##_1x1 ()); }

TEST(i8, int8_t)
TEST(u8, uint8_t)
TEST(i16, int16_t)
TEST(u16, uint16_t)
TEST(i32, int32_t)
TEST(u32, uint32_t)
TEST(i64, int64_t)
TEST(u64, uint64_t)

void
mixed_branch (int32_t *wide, int8_t *narrow, int choose)
{
  __riscv_ztt_mss_rm (wide, __riscv_ztt_mrowid_ew_i32_1x1 ());
  if (choose)
    __riscv_ztt_mss_rm (narrow, __riscv_ztt_mrowid_ew_i8_1x1 ());
}

#ifdef __cplusplus
}
#endif
