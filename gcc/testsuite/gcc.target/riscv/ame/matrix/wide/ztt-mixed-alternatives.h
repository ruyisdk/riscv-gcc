#include "ztt-wide-reuse.h"
#ifdef __cplusplus
extern "C" {
#endif
WR_CASE(left_dead, madd_ew, a, b, , __riscv_ztt_mss_rm (saved_other, b))
WR_CASE(right_dead, msub_ew, b, a, , __riscv_ztt_mss_rm (saved_other, b))
WR_CASE(left_live, madd_ew, a, b, , __riscv_ztt_mss_rm (saved, a))
WR_CASE(right_live, msub_ew, b, a, , __riscv_ztt_mss_rm (saved, a))
WR_CASE(same_dead, mmul_ew, a, a, , )
WR_CASE(same_live, madd_ew, a, a, , WR_SAVE)
#ifdef __cplusplus
}
#endif
