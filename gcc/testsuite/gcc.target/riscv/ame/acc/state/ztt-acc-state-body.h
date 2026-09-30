/* Mixed 32-bit ACC descriptors.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_i32_u32_accx1_irm != 15
#error four integer ACC rounding modes required
#endif
#ifdef __cplusplus
extern "C" {
#endif
void acc_state_kernel (const uint32_t **in, uint32_t **out, int branch)
{
  __riscv_ztt_i32_rnu_1x1_t m0
    = __riscv_ztt_mls_rm_i32_rnu_1x1 ((const int32_t *) in[0]);
  __riscv_ztt_i32_rnu_accx1_t a0
    = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m0);
  __riscv_ztt_i32_rnu_1x1_t r0
    = __riscv_ztt_mls_rm_i32_rnu_1x1 ((const int32_t *) in[17]);
  __riscv_ztt_i32_rne_1x1_t m1
    = __riscv_ztt_mls_rm_i32_rne_1x1 ((const int32_t *) in[1]);
  __riscv_ztt_i32_rne_accx1_t a1
    = __riscv_ztt_mcopy_m2a_i32_rne_accx1 (m1);
  __riscv_ztt_i32_rne_1x1_t r1
    = __riscv_ztt_mls_rm_i32_rne_1x1 ((const int32_t *) in[18]);
  __riscv_ztt_i32_rdn_1x1_t m2
    = __riscv_ztt_mls_rm_i32_rdn_1x1 ((const int32_t *) in[2]);
  __riscv_ztt_i32_rdn_accx1_t a2
    = __riscv_ztt_mcopy_m2a_i32_rdn_accx1 (m2);
  __riscv_ztt_i32_rdn_1x1_t r2
    = __riscv_ztt_mls_rm_i32_rdn_1x1 ((const int32_t *) in[19]);
  __riscv_ztt_i32_rod_1x1_t m3
    = __riscv_ztt_mls_rm_i32_rod_1x1 ((const int32_t *) in[3]);
  __riscv_ztt_i32_rod_accx1_t a3
    = __riscv_ztt_mcopy_m2a_i32_rod_accx1 (m3);
  __riscv_ztt_i32_rod_1x1_t r3
    = __riscv_ztt_mls_rm_i32_rod_1x1 ((const int32_t *) in[20]);
  __riscv_ztt_u32_rnu_1x1_t m4
    = __riscv_ztt_mls_rm_u32_rnu_1x1 ((const uint32_t *) in[4]);
  __riscv_ztt_u32_rnu_accx1_t a4
    = __riscv_ztt_mcopy_m2a_u32_rnu_accx1 (m4);
  __riscv_ztt_u32_rnu_1x1_t r4
    = __riscv_ztt_mls_rm_u32_rnu_1x1 ((const uint32_t *) in[21]);
  __riscv_ztt_u32_rne_1x1_t m5
    = __riscv_ztt_mls_rm_u32_rne_1x1 ((const uint32_t *) in[5]);
  __riscv_ztt_u32_rne_accx1_t a5
    = __riscv_ztt_mcopy_m2a_u32_rne_accx1 (m5);
  __riscv_ztt_u32_rne_1x1_t r5
    = __riscv_ztt_mls_rm_u32_rne_1x1 ((const uint32_t *) in[22]);
  __riscv_ztt_u32_rdn_1x1_t m6
    = __riscv_ztt_mls_rm_u32_rdn_1x1 ((const uint32_t *) in[6]);
  __riscv_ztt_u32_rdn_accx1_t a6
    = __riscv_ztt_mcopy_m2a_u32_rdn_accx1 (m6);
  __riscv_ztt_u32_rdn_1x1_t r6
    = __riscv_ztt_mls_rm_u32_rdn_1x1 ((const uint32_t *) in[23]);
  __riscv_ztt_u32_rod_1x1_t m7
    = __riscv_ztt_mls_rm_u32_rod_1x1 ((const uint32_t *) in[7]);
  __riscv_ztt_u32_rod_accx1_t a7
    = __riscv_ztt_mcopy_m2a_u32_rod_accx1 (m7);
  __riscv_ztt_u32_rod_1x1_t r7
    = __riscv_ztt_mls_rm_u32_rod_1x1 ((const uint32_t *) in[24]);
  __riscv_ztt_i32_rnu_1x1_t m8
    = __riscv_ztt_mls_rm_i32_rnu_1x1 ((const int32_t *) in[8]);
  __riscv_ztt_i32_rnu_accx1_t a8
    = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m8);
  __riscv_ztt_i32_rnu_1x1_t r8
    = __riscv_ztt_mls_rm_i32_rnu_1x1 ((const int32_t *) in[25]);
  __riscv_ztt_i32_rne_1x1_t m9
    = __riscv_ztt_mls_rm_i32_rne_1x1 ((const int32_t *) in[9]);
  __riscv_ztt_i32_rne_accx1_t a9
    = __riscv_ztt_mcopy_m2a_i32_rne_accx1 (m9);
  __riscv_ztt_i32_rne_1x1_t r9
    = __riscv_ztt_mls_rm_i32_rne_1x1 ((const int32_t *) in[26]);
  __riscv_ztt_i32_rdn_1x1_t m10
    = __riscv_ztt_mls_rm_i32_rdn_1x1 ((const int32_t *) in[10]);
  __riscv_ztt_i32_rdn_accx1_t a10
    = __riscv_ztt_mcopy_m2a_i32_rdn_accx1 (m10);
  __riscv_ztt_i32_rdn_1x1_t r10
    = __riscv_ztt_mls_rm_i32_rdn_1x1 ((const int32_t *) in[27]);
  __riscv_ztt_i32_rod_1x1_t m11
    = __riscv_ztt_mls_rm_i32_rod_1x1 ((const int32_t *) in[11]);
  __riscv_ztt_i32_rod_accx1_t a11
    = __riscv_ztt_mcopy_m2a_i32_rod_accx1 (m11);
  __riscv_ztt_i32_rod_1x1_t r11
    = __riscv_ztt_mls_rm_i32_rod_1x1 ((const int32_t *) in[28]);
  __riscv_ztt_u32_rnu_1x1_t m12
    = __riscv_ztt_mls_rm_u32_rnu_1x1 ((const uint32_t *) in[12]);
  __riscv_ztt_u32_rnu_accx1_t a12
    = __riscv_ztt_mcopy_m2a_u32_rnu_accx1 (m12);
  __riscv_ztt_u32_rnu_1x1_t r12
    = __riscv_ztt_mls_rm_u32_rnu_1x1 ((const uint32_t *) in[29]);
  __riscv_ztt_u32_rne_1x1_t m13
    = __riscv_ztt_mls_rm_u32_rne_1x1 ((const uint32_t *) in[13]);
  __riscv_ztt_u32_rne_accx1_t a13
    = __riscv_ztt_mcopy_m2a_u32_rne_accx1 (m13);
  __riscv_ztt_u32_rne_1x1_t r13
    = __riscv_ztt_mls_rm_u32_rne_1x1 ((const uint32_t *) in[30]);
  __riscv_ztt_u32_rdn_1x1_t m14
    = __riscv_ztt_mls_rm_u32_rdn_1x1 ((const uint32_t *) in[14]);
  __riscv_ztt_u32_rdn_accx1_t a14
    = __riscv_ztt_mcopy_m2a_u32_rdn_accx1 (m14);
  __riscv_ztt_u32_rdn_1x1_t r14
    = __riscv_ztt_mls_rm_u32_rdn_1x1 ((const uint32_t *) in[31]);
  __riscv_ztt_u32_rod_1x1_t m15
    = __riscv_ztt_mls_rm_u32_rod_1x1 ((const uint32_t *) in[15]);
  __riscv_ztt_u32_rod_accx1_t a15
    = __riscv_ztt_mcopy_m2a_u32_rod_accx1 (m15);
  __riscv_ztt_u32_rod_1x1_t r15
    = __riscv_ztt_mls_rm_u32_rod_1x1 ((const uint32_t *) in[32]);
  __riscv_ztt_i32_rnu_1x1_t m16
    = __riscv_ztt_mls_rm_i32_rnu_1x1 ((const int32_t *) in[16]);
  __riscv_ztt_i32_rnu_accx1_t a16
    = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m16);
  __riscv_ztt_i32_rnu_1x1_t r16
    = __riscv_ztt_mls_rm_i32_rnu_1x1 ((const int32_t *) in[33]);
  asm volatile ("" ::: "memory");
  __riscv_ztt_i32_rnu_accx1_t b0 = a0;
  if (branch)
    b0 = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (a0, m0, r0);
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[0],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (b0));
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[17],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a0));
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[34],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (__riscv_ztt_mclear_acc_i32_rnu_accx1 ()));
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[51],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (__riscv_ztt_mzero_acc_i32_rnu_accx1 ()));
  __riscv_ztt_i32_rne_accx1_t b1 = a1;
  if (branch)
    b1 = __riscv_ztt_mmulacc_2d_i32_rne_accx1 (a1, m1, r1);
  __riscv_ztt_mss_rm_i32_rne_1x1 ((int32_t *) out[1],
    __riscv_ztt_mcopy_a2m_i32_rne_1x1 (b1));
  __riscv_ztt_mss_rm_i32_rne_1x1 ((int32_t *) out[18],
    __riscv_ztt_mcopy_a2m_i32_rne_1x1 (a1));
  __riscv_ztt_mss_rm_i32_rne_1x1 ((int32_t *) out[35],
    __riscv_ztt_mcopy_a2m_i32_rne_1x1 (__riscv_ztt_mclear_acc_i32_rne_accx1 ()));
  __riscv_ztt_mss_rm_i32_rne_1x1 ((int32_t *) out[52],
    __riscv_ztt_mcopy_a2m_i32_rne_1x1 (__riscv_ztt_mzero_acc_i32_rne_accx1 ()));
  __riscv_ztt_i32_rdn_accx1_t b2 = a2;
  if (branch)
    b2 = __riscv_ztt_mmulacc_2d_i32_rdn_accx1 (a2, m2, r2);
  __riscv_ztt_mss_rm_i32_rdn_1x1 ((int32_t *) out[2],
    __riscv_ztt_mcopy_a2m_i32_rdn_1x1 (b2));
  __riscv_ztt_mss_rm_i32_rdn_1x1 ((int32_t *) out[19],
    __riscv_ztt_mcopy_a2m_i32_rdn_1x1 (a2));
  __riscv_ztt_mss_rm_i32_rdn_1x1 ((int32_t *) out[36],
    __riscv_ztt_mcopy_a2m_i32_rdn_1x1 (__riscv_ztt_mclear_acc_i32_rdn_accx1 ()));
  __riscv_ztt_mss_rm_i32_rdn_1x1 ((int32_t *) out[53],
    __riscv_ztt_mcopy_a2m_i32_rdn_1x1 (__riscv_ztt_mzero_acc_i32_rdn_accx1 ()));
  __riscv_ztt_i32_rod_accx1_t b3 = a3;
  if (branch)
    b3 = __riscv_ztt_mmulacc_2d_i32_rod_accx1 (a3, m3, r3);
  __riscv_ztt_mss_rm_i32_rod_1x1 ((int32_t *) out[3],
    __riscv_ztt_mcopy_a2m_i32_rod_1x1 (b3));
  __riscv_ztt_mss_rm_i32_rod_1x1 ((int32_t *) out[20],
    __riscv_ztt_mcopy_a2m_i32_rod_1x1 (a3));
  __riscv_ztt_mss_rm_i32_rod_1x1 ((int32_t *) out[37],
    __riscv_ztt_mcopy_a2m_i32_rod_1x1 (__riscv_ztt_mclear_acc_i32_rod_accx1 ()));
  __riscv_ztt_mss_rm_i32_rod_1x1 ((int32_t *) out[54],
    __riscv_ztt_mcopy_a2m_i32_rod_1x1 (__riscv_ztt_mzero_acc_i32_rod_accx1 ()));
  __riscv_ztt_u32_rnu_accx1_t b4 = a4;
  if (branch)
    b4 = __riscv_ztt_mmulacc_2d_u32_rnu_accx1 (a4, m4, r4);
  __riscv_ztt_mss_rm_u32_rnu_1x1 ((uint32_t *) out[4],
    __riscv_ztt_mcopy_a2m_u32_rnu_1x1 (b4));
  __riscv_ztt_mss_rm_u32_rnu_1x1 ((uint32_t *) out[21],
    __riscv_ztt_mcopy_a2m_u32_rnu_1x1 (a4));
  __riscv_ztt_mss_rm_u32_rnu_1x1 ((uint32_t *) out[38],
    __riscv_ztt_mcopy_a2m_u32_rnu_1x1 (__riscv_ztt_mclear_acc_u32_rnu_accx1 ()));
  __riscv_ztt_mss_rm_u32_rnu_1x1 ((uint32_t *) out[55],
    __riscv_ztt_mcopy_a2m_u32_rnu_1x1 (__riscv_ztt_mzero_acc_u32_rnu_accx1 ()));
  __riscv_ztt_u32_rne_accx1_t b5 = a5;
  if (branch)
    b5 = __riscv_ztt_mmulacc_2d_u32_rne_accx1 (a5, m5, r5);
  __riscv_ztt_mss_rm_u32_rne_1x1 ((uint32_t *) out[5],
    __riscv_ztt_mcopy_a2m_u32_rne_1x1 (b5));
  __riscv_ztt_mss_rm_u32_rne_1x1 ((uint32_t *) out[22],
    __riscv_ztt_mcopy_a2m_u32_rne_1x1 (a5));
  __riscv_ztt_mss_rm_u32_rne_1x1 ((uint32_t *) out[39],
    __riscv_ztt_mcopy_a2m_u32_rne_1x1 (__riscv_ztt_mclear_acc_u32_rne_accx1 ()));
  __riscv_ztt_mss_rm_u32_rne_1x1 ((uint32_t *) out[56],
    __riscv_ztt_mcopy_a2m_u32_rne_1x1 (__riscv_ztt_mzero_acc_u32_rne_accx1 ()));
  __riscv_ztt_u32_rdn_accx1_t b6 = a6;
  if (branch)
    b6 = __riscv_ztt_mmulacc_2d_u32_rdn_accx1 (a6, m6, r6);
  __riscv_ztt_mss_rm_u32_rdn_1x1 ((uint32_t *) out[6],
    __riscv_ztt_mcopy_a2m_u32_rdn_1x1 (b6));
  __riscv_ztt_mss_rm_u32_rdn_1x1 ((uint32_t *) out[23],
    __riscv_ztt_mcopy_a2m_u32_rdn_1x1 (a6));
  __riscv_ztt_mss_rm_u32_rdn_1x1 ((uint32_t *) out[40],
    __riscv_ztt_mcopy_a2m_u32_rdn_1x1 (__riscv_ztt_mclear_acc_u32_rdn_accx1 ()));
  __riscv_ztt_mss_rm_u32_rdn_1x1 ((uint32_t *) out[57],
    __riscv_ztt_mcopy_a2m_u32_rdn_1x1 (__riscv_ztt_mzero_acc_u32_rdn_accx1 ()));
  __riscv_ztt_u32_rod_accx1_t b7 = a7;
  if (branch)
    b7 = __riscv_ztt_mmulacc_2d_u32_rod_accx1 (a7, m7, r7);
  __riscv_ztt_mss_rm_u32_rod_1x1 ((uint32_t *) out[7],
    __riscv_ztt_mcopy_a2m_u32_rod_1x1 (b7));
  __riscv_ztt_mss_rm_u32_rod_1x1 ((uint32_t *) out[24],
    __riscv_ztt_mcopy_a2m_u32_rod_1x1 (a7));
  __riscv_ztt_mss_rm_u32_rod_1x1 ((uint32_t *) out[41],
    __riscv_ztt_mcopy_a2m_u32_rod_1x1 (__riscv_ztt_mclear_acc_u32_rod_accx1 ()));
  __riscv_ztt_mss_rm_u32_rod_1x1 ((uint32_t *) out[58],
    __riscv_ztt_mcopy_a2m_u32_rod_1x1 (__riscv_ztt_mzero_acc_u32_rod_accx1 ()));
  __riscv_ztt_i32_rnu_accx1_t b8 = a8;
  if (branch)
    b8 = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (a8, m8, r8);
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[8],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (b8));
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[25],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a8));
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[42],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (__riscv_ztt_mclear_acc_i32_rnu_accx1 ()));
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[59],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (__riscv_ztt_mzero_acc_i32_rnu_accx1 ()));
  __riscv_ztt_i32_rne_accx1_t b9 = a9;
  if (branch)
    b9 = __riscv_ztt_mmulacc_2d_i32_rne_accx1 (a9, m9, r9);
  __riscv_ztt_mss_rm_i32_rne_1x1 ((int32_t *) out[9],
    __riscv_ztt_mcopy_a2m_i32_rne_1x1 (b9));
  __riscv_ztt_mss_rm_i32_rne_1x1 ((int32_t *) out[26],
    __riscv_ztt_mcopy_a2m_i32_rne_1x1 (a9));
  __riscv_ztt_mss_rm_i32_rne_1x1 ((int32_t *) out[43],
    __riscv_ztt_mcopy_a2m_i32_rne_1x1 (__riscv_ztt_mclear_acc_i32_rne_accx1 ()));
  __riscv_ztt_mss_rm_i32_rne_1x1 ((int32_t *) out[60],
    __riscv_ztt_mcopy_a2m_i32_rne_1x1 (__riscv_ztt_mzero_acc_i32_rne_accx1 ()));
  __riscv_ztt_i32_rdn_accx1_t b10 = a10;
  if (branch)
    b10 = __riscv_ztt_mmulacc_2d_i32_rdn_accx1 (a10, m10, r10);
  __riscv_ztt_mss_rm_i32_rdn_1x1 ((int32_t *) out[10],
    __riscv_ztt_mcopy_a2m_i32_rdn_1x1 (b10));
  __riscv_ztt_mss_rm_i32_rdn_1x1 ((int32_t *) out[27],
    __riscv_ztt_mcopy_a2m_i32_rdn_1x1 (a10));
  __riscv_ztt_mss_rm_i32_rdn_1x1 ((int32_t *) out[44],
    __riscv_ztt_mcopy_a2m_i32_rdn_1x1 (__riscv_ztt_mclear_acc_i32_rdn_accx1 ()));
  __riscv_ztt_mss_rm_i32_rdn_1x1 ((int32_t *) out[61],
    __riscv_ztt_mcopy_a2m_i32_rdn_1x1 (__riscv_ztt_mzero_acc_i32_rdn_accx1 ()));
  __riscv_ztt_i32_rod_accx1_t b11 = a11;
  if (branch)
    b11 = __riscv_ztt_mmulacc_2d_i32_rod_accx1 (a11, m11, r11);
  __riscv_ztt_mss_rm_i32_rod_1x1 ((int32_t *) out[11],
    __riscv_ztt_mcopy_a2m_i32_rod_1x1 (b11));
  __riscv_ztt_mss_rm_i32_rod_1x1 ((int32_t *) out[28],
    __riscv_ztt_mcopy_a2m_i32_rod_1x1 (a11));
  __riscv_ztt_mss_rm_i32_rod_1x1 ((int32_t *) out[45],
    __riscv_ztt_mcopy_a2m_i32_rod_1x1 (__riscv_ztt_mclear_acc_i32_rod_accx1 ()));
  __riscv_ztt_mss_rm_i32_rod_1x1 ((int32_t *) out[62],
    __riscv_ztt_mcopy_a2m_i32_rod_1x1 (__riscv_ztt_mzero_acc_i32_rod_accx1 ()));
  __riscv_ztt_u32_rnu_accx1_t b12 = a12;
  if (branch)
    b12 = __riscv_ztt_mmulacc_2d_u32_rnu_accx1 (a12, m12, r12);
  __riscv_ztt_mss_rm_u32_rnu_1x1 ((uint32_t *) out[12],
    __riscv_ztt_mcopy_a2m_u32_rnu_1x1 (b12));
  __riscv_ztt_mss_rm_u32_rnu_1x1 ((uint32_t *) out[29],
    __riscv_ztt_mcopy_a2m_u32_rnu_1x1 (a12));
  __riscv_ztt_mss_rm_u32_rnu_1x1 ((uint32_t *) out[46],
    __riscv_ztt_mcopy_a2m_u32_rnu_1x1 (__riscv_ztt_mclear_acc_u32_rnu_accx1 ()));
  __riscv_ztt_mss_rm_u32_rnu_1x1 ((uint32_t *) out[63],
    __riscv_ztt_mcopy_a2m_u32_rnu_1x1 (__riscv_ztt_mzero_acc_u32_rnu_accx1 ()));
  __riscv_ztt_u32_rne_accx1_t b13 = a13;
  if (branch)
    b13 = __riscv_ztt_mmulacc_2d_u32_rne_accx1 (a13, m13, r13);
  __riscv_ztt_mss_rm_u32_rne_1x1 ((uint32_t *) out[13],
    __riscv_ztt_mcopy_a2m_u32_rne_1x1 (b13));
  __riscv_ztt_mss_rm_u32_rne_1x1 ((uint32_t *) out[30],
    __riscv_ztt_mcopy_a2m_u32_rne_1x1 (a13));
  __riscv_ztt_mss_rm_u32_rne_1x1 ((uint32_t *) out[47],
    __riscv_ztt_mcopy_a2m_u32_rne_1x1 (__riscv_ztt_mclear_acc_u32_rne_accx1 ()));
  __riscv_ztt_mss_rm_u32_rne_1x1 ((uint32_t *) out[64],
    __riscv_ztt_mcopy_a2m_u32_rne_1x1 (__riscv_ztt_mzero_acc_u32_rne_accx1 ()));
  __riscv_ztt_u32_rdn_accx1_t b14 = a14;
  if (branch)
    b14 = __riscv_ztt_mmulacc_2d_u32_rdn_accx1 (a14, m14, r14);
  __riscv_ztt_mss_rm_u32_rdn_1x1 ((uint32_t *) out[14],
    __riscv_ztt_mcopy_a2m_u32_rdn_1x1 (b14));
  __riscv_ztt_mss_rm_u32_rdn_1x1 ((uint32_t *) out[31],
    __riscv_ztt_mcopy_a2m_u32_rdn_1x1 (a14));
  __riscv_ztt_mss_rm_u32_rdn_1x1 ((uint32_t *) out[48],
    __riscv_ztt_mcopy_a2m_u32_rdn_1x1 (__riscv_ztt_mclear_acc_u32_rdn_accx1 ()));
  __riscv_ztt_mss_rm_u32_rdn_1x1 ((uint32_t *) out[65],
    __riscv_ztt_mcopy_a2m_u32_rdn_1x1 (__riscv_ztt_mzero_acc_u32_rdn_accx1 ()));
  __riscv_ztt_u32_rod_accx1_t b15 = a15;
  if (branch)
    b15 = __riscv_ztt_mmulacc_2d_u32_rod_accx1 (a15, m15, r15);
  __riscv_ztt_mss_rm_u32_rod_1x1 ((uint32_t *) out[15],
    __riscv_ztt_mcopy_a2m_u32_rod_1x1 (b15));
  __riscv_ztt_mss_rm_u32_rod_1x1 ((uint32_t *) out[32],
    __riscv_ztt_mcopy_a2m_u32_rod_1x1 (a15));
  __riscv_ztt_mss_rm_u32_rod_1x1 ((uint32_t *) out[49],
    __riscv_ztt_mcopy_a2m_u32_rod_1x1 (__riscv_ztt_mclear_acc_u32_rod_accx1 ()));
  __riscv_ztt_mss_rm_u32_rod_1x1 ((uint32_t *) out[66],
    __riscv_ztt_mcopy_a2m_u32_rod_1x1 (__riscv_ztt_mzero_acc_u32_rod_accx1 ()));
  __riscv_ztt_i32_rnu_accx1_t b16 = a16;
  if (branch)
    b16 = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (a16, m16, r16);
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[16],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (b16));
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[33],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a16));
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[50],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (__riscv_ztt_mclear_acc_i32_rnu_accx1 ()));
  __riscv_ztt_mss_rm_i32_rnu_1x1 ((int32_t *) out[67],
    __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (__riscv_ztt_mzero_acc_i32_rnu_accx1 ()));
}
#ifdef __cplusplus
}
#endif
