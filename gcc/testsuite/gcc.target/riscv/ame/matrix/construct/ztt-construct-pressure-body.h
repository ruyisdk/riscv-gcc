/* more live M groups than fit.  */
#include <stdint.h>
#include <riscv_ztt.h>

void pressure_indices (int32_t **out)
{
#define VALUE(N) \
  __riscv_ztt_i32_rne_1x1_t v##N = __riscv_ztt_mrowid_ew_i32_rne_1x1 ()
  VALUE(0); VALUE(1); VALUE(2); VALUE(3);
  VALUE(4); VALUE(5); VALUE(6); VALUE(7);
  VALUE(8); VALUE(9); VALUE(10); VALUE(11);
  VALUE(12); VALUE(13); VALUE(14); VALUE(15);
  __riscv_ztt_i32_rne_1x1_t old = v0;
  v0 = __riscv_ztt_mcolid_ew_i32_rne_1x1 ();
  __riscv_ztt_mss_rm (out[16], old);
#define STORE(N) __riscv_ztt_mss_rm (out[N], v##N)
  STORE(0); STORE(1); STORE(2); STORE(3);
  STORE(4); STORE(5); STORE(6); STORE(7);
  STORE(8); STORE(9); STORE(10); STORE(11);
  STORE(12); STORE(13); STORE(14); STORE(15);
}
