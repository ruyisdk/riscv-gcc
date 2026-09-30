/* UDS32, i32/RNU only.  */
#include <stdint.h>
#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C"
#endif
void acc_pressure (const int32_t *const *in, int32_t *const *out, int branch)
{
  typedef __riscv_ztt_i32_rnu_accx1_t A;
  typedef __riscv_ztt_i32_rnu_1x1_t M;
  A a0 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[0]));
  A a1 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[1]));
  A a2 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[2]));
  A a3 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[3]));
  A a4 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[4]));
  A a5 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[5]));
  A a6 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[6]));
  A a7 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[7]));
  A a8 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[8]));
  A a9 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[9]));
  A a10 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[10]));
  A a11 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[11]));
  A a12 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[12]));
  A a13 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[13]));
  A a14 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[14]));
  A a15 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[15]));
  A a16 = __riscv_ztt_mcopy_m2a_i32_accx1
    (__riscv_ztt_mls_rm_i32_1x1 (in[16]));
  M m0 = __riscv_ztt_mls_rm_i32_1x1 (in[17]);
  M m1 = __riscv_ztt_mls_rm_i32_1x1 (in[18]);
  M m2 = __riscv_ztt_mls_rm_i32_1x1 (in[19]);
  M m3 = __riscv_ztt_mls_rm_i32_1x1 (in[20]);
  M m4 = __riscv_ztt_mls_rm_i32_1x1 (in[21]);
  M m5 = __riscv_ztt_mls_rm_i32_1x1 (in[22]);
  M m6 = __riscv_ztt_mls_rm_i32_1x1 (in[23]);
  M m7 = __riscv_ztt_mls_rm_i32_1x1 (in[24]);
  M m8 = __riscv_ztt_mls_rm_i32_1x1 (in[25]);
  M m9 = __riscv_ztt_mls_rm_i32_1x1 (in[26]);
  M m10 = __riscv_ztt_mls_rm_i32_1x1 (in[27]);
  M m11 = __riscv_ztt_mls_rm_i32_1x1 (in[28]);
  M m12 = __riscv_ztt_mls_rm_i32_1x1 (in[29]);
  M m13 = __riscv_ztt_mls_rm_i32_1x1 (in[30]);
  M m14 = __riscv_ztt_mls_rm_i32_1x1 (in[31]);
  M m15 = __riscv_ztt_mls_rm_i32_1x1 (in[32]);
  M m16 = __riscv_ztt_mls_rm_i32_1x1 (in[33]);
  M m17 = __riscv_ztt_mls_rm_i32_1x1 (in[34]);
  M m18 = __riscv_ztt_mls_rm_i32_1x1 (in[35]);
  M m19 = __riscv_ztt_mls_rm_i32_1x1 (in[36]);
  M m20 = __riscv_ztt_mls_rm_i32_1x1 (in[37]);
  M m21 = __riscv_ztt_mls_rm_i32_1x1 (in[38]);
  M m22 = __riscv_ztt_mls_rm_i32_1x1 (in[39]);
  M m23 = __riscv_ztt_mls_rm_i32_1x1 (in[40]);
  M m24 = __riscv_ztt_mls_rm_i32_1x1 (in[41]);
  M m25 = __riscv_ztt_mls_rm_i32_1x1 (in[42]);
  M m26 = __riscv_ztt_mls_rm_i32_1x1 (in[43]);
  M m27 = __riscv_ztt_mls_rm_i32_1x1 (in[44]);
  M m28 = __riscv_ztt_mls_rm_i32_1x1 (in[45]);
  M m29 = __riscv_ztt_mls_rm_i32_1x1 (in[46]);
  M m30 = __riscv_ztt_mls_rm_i32_1x1 (in[47]);
  M m31 = __riscv_ztt_mls_rm_i32_1x1 (in[48]);
  M m32 = __riscv_ztt_mls_rm_i32_1x1 (in[49]);
  asm volatile ("" ::: "memory");
  A updated = __riscv_ztt_mmulacc_2d_i32_accx1 (a0, m0, m1);
  A selected = branch ? updated : a1;
  __riscv_ztt_mss_rm (out[0], __riscv_ztt_mcopy_a2m_i32_1x1 (selected));
  __riscv_ztt_mss_rm (out[1], __riscv_ztt_mcopy_a2m_i32_1x1 (a0));
  __riscv_ztt_mss_rm (out[2], __riscv_ztt_mcopy_a2m_i32_1x1 (a1));
  __riscv_ztt_mss_rm (out[3], __riscv_ztt_mcopy_a2m_i32_1x1 (a2));
  __riscv_ztt_mss_rm (out[4], __riscv_ztt_mcopy_a2m_i32_1x1 (a3));
  __riscv_ztt_mss_rm (out[5], __riscv_ztt_mcopy_a2m_i32_1x1 (a4));
  __riscv_ztt_mss_rm (out[6], __riscv_ztt_mcopy_a2m_i32_1x1 (a5));
  __riscv_ztt_mss_rm (out[7], __riscv_ztt_mcopy_a2m_i32_1x1 (a6));
  __riscv_ztt_mss_rm (out[8], __riscv_ztt_mcopy_a2m_i32_1x1 (a7));
  __riscv_ztt_mss_rm (out[9], __riscv_ztt_mcopy_a2m_i32_1x1 (a8));
  __riscv_ztt_mss_rm (out[10], __riscv_ztt_mcopy_a2m_i32_1x1 (a9));
  __riscv_ztt_mss_rm (out[11], __riscv_ztt_mcopy_a2m_i32_1x1 (a10));
  __riscv_ztt_mss_rm (out[12], __riscv_ztt_mcopy_a2m_i32_1x1 (a11));
  __riscv_ztt_mss_rm (out[13], __riscv_ztt_mcopy_a2m_i32_1x1 (a12));
  __riscv_ztt_mss_rm (out[14], __riscv_ztt_mcopy_a2m_i32_1x1 (a13));
  __riscv_ztt_mss_rm (out[15], __riscv_ztt_mcopy_a2m_i32_1x1 (a14));
  __riscv_ztt_mss_rm (out[16], __riscv_ztt_mcopy_a2m_i32_1x1 (a15));
  __riscv_ztt_mss_rm (out[17], __riscv_ztt_mcopy_a2m_i32_1x1 (a16));
  __riscv_ztt_mss_rm (out[18], m0);
  __riscv_ztt_mss_rm (out[19], m1);
  __riscv_ztt_mss_rm (out[20], m2);
  __riscv_ztt_mss_rm (out[21], m3);
  __riscv_ztt_mss_rm (out[22], m4);
  __riscv_ztt_mss_rm (out[23], m5);
  __riscv_ztt_mss_rm (out[24], m6);
  __riscv_ztt_mss_rm (out[25], m7);
  __riscv_ztt_mss_rm (out[26], m8);
  __riscv_ztt_mss_rm (out[27], m9);
  __riscv_ztt_mss_rm (out[28], m10);
  __riscv_ztt_mss_rm (out[29], m11);
  __riscv_ztt_mss_rm (out[30], m12);
  __riscv_ztt_mss_rm (out[31], m13);
  __riscv_ztt_mss_rm (out[32], m14);
  __riscv_ztt_mss_rm (out[33], m15);
  __riscv_ztt_mss_rm (out[34], m16);
  __riscv_ztt_mss_rm (out[35], m17);
  __riscv_ztt_mss_rm (out[36], m18);
  __riscv_ztt_mss_rm (out[37], m19);
  __riscv_ztt_mss_rm (out[38], m20);
  __riscv_ztt_mss_rm (out[39], m21);
  __riscv_ztt_mss_rm (out[40], m22);
  __riscv_ztt_mss_rm (out[41], m23);
  __riscv_ztt_mss_rm (out[42], m24);
  __riscv_ztt_mss_rm (out[43], m25);
  __riscv_ztt_mss_rm (out[44], m26);
  __riscv_ztt_mss_rm (out[45], m27);
  __riscv_ztt_mss_rm (out[46], m28);
  __riscv_ztt_mss_rm (out[47], m29);
  __riscv_ztt_mss_rm (out[48], m30);
  __riscv_ztt_mss_rm (out[49], m31);
  __riscv_ztt_mss_rm (out[50], m32);
  __riscv_ztt_mss_rm (out[51], __riscv_ztt_mcopy_a2m_i32_1x1
    (__riscv_ztt_mclear_acc_i32_accx1 ()));
  __riscv_ztt_mss_rm (out[52], __riscv_ztt_mcopy_a2m_i32_1x1
    (__riscv_ztt_mzero_acc_i32_accx1 ()));
}
