/* mixed shifts.  */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_shift_int_mixed != 1
#error missing mixed integer shift capability
#endif

#define ZTT_SHIFT_M(ID, OP, DC, AC, BC, DT, AT, BT, S) \
void ID (DC *out, AC *keep_a, BC *keep_b, const AC *data, const BC *count) \
{ \
  __riscv_ztt_##AT##_##S##_t a = __riscv_ztt_mls_rm_##AT##_##S (data); \
  __riscv_ztt_##BT##_##S##_t b = __riscv_ztt_mls_rm_##BT##_##S (count); \
  __riscv_ztt_##DT##_##S##_t d = __riscv_ztt_##OP##_##DT##_##S (a, b); \
  __riscv_ztt_mss_rm (out, d); \
  __riscv_ztt_mss_rm (keep_a, a); \
  __riscv_ztt_mss_rm (keep_b, b); \
}
#define ZTT_SHIFT_X(ID, OP, DC, AC, DT, AT, S) \
void ID (DC *out, AC *keep_a, const AC *data, size_t count) \
{ \
  __riscv_ztt_##AT##_##S##_t a = __riscv_ztt_mls_rm_##AT##_##S (data); \
  __riscv_ztt_##DT##_##S##_t d = __riscv_ztt_##OP##_##DT##_##S (a, count); \
  __riscv_ztt_mss_rm (out, d); \
  __riscv_ztt_mss_rm (keep_a, a); \
}
