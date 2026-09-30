/* Width and group coverage.  */
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l8_r8_d8, 8, 8, 8, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l8_r8_d16, 8, 8, 16, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l8_r8_d32, 8, 8, 32, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l8_r16_d8, 8, 16, 8, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l8_r16_d16, 8, 16, 16, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l8_r16_d32, 8, 16, 32, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l8_r32_d8, 8, 32, 8, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l8_r32_d16, 8, 32, 16, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l8_r32_d32, 8, 32, 32, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l16_r8_d8, 16, 8, 8, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l16_r8_d16, 16, 8, 16, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l16_r8_d32, 16, 8, 32, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l16_r16_d8, 16, 16, 8, 1, 1)
#endif
#if __riscv_ztt_uds <= 16
FUNCTION (mixed_l16_r16_d16, 16, 16, 16, 1, 1)
#endif
#if __riscv_ztt_uds <= 16
FUNCTION (mixed_l16_r16_d32, 16, 16, 32, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l16_r32_d8, 16, 32, 8, 1, 1)
#endif
#if __riscv_ztt_uds <= 16
FUNCTION (mixed_l16_r32_d16, 16, 32, 16, 1, 1)
#endif
#if __riscv_ztt_uds <= 16
FUNCTION (mixed_l16_r32_d32, 16, 32, 32, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l32_r8_d8, 32, 8, 8, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l32_r8_d16, 32, 8, 16, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l32_r8_d32, 32, 8, 32, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l32_r16_d8, 32, 16, 8, 1, 1)
#endif
#if __riscv_ztt_uds <= 16
FUNCTION (mixed_l32_r16_d16, 32, 16, 16, 1, 1)
#endif
#if __riscv_ztt_uds <= 16
FUNCTION (mixed_l32_r16_d32, 32, 16, 32, 1, 1)
#endif
#if __riscv_ztt_uds <= 8
FUNCTION (mixed_l32_r32_d8, 32, 32, 8, 1, 1)
#endif
#if __riscv_ztt_uds <= 16
FUNCTION (mixed_l32_r32_d16, 32, 32, 16, 1, 1)
#endif
#if __riscv_ztt_uds <= 32
FUNCTION (mixed_l32_r32_d32, 32, 32, 32, 1, 1)
#endif
#if __riscv_ztt_uds == 8
#if __riscv_ztt_accregs >= 1
FUNCTION (mixed_q2_k1, 8, 8, 8, 2, 1)
FUNCTION (mixed_left_wide_k1, 16, 8, 8, 2, 1)
FUNCTION (mixed_right_wide_k1, 8, 16, 8, 2, 1)
FUNCTION (mixed_acc_wide_k1, 8, 8, 16, 2, 1)
#endif
#if __riscv_ztt_accregs >= 2
FUNCTION (mixed_q2_k2, 8, 8, 8, 2, 2)
FUNCTION (mixed_left_wide_k2, 16, 8, 8, 2, 2)
FUNCTION (mixed_right_wide_k2, 8, 16, 8, 2, 2)
FUNCTION (mixed_acc_wide_k2, 8, 8, 16, 2, 2)
#endif
#if __riscv_ztt_accregs >= 4
FUNCTION (mixed_q2_k4, 8, 8, 8, 2, 4)
FUNCTION (mixed_left_wide_k4, 16, 8, 8, 2, 4)
FUNCTION (mixed_right_wide_k4, 8, 16, 8, 2, 4)
#endif
#if __riscv_ztt_accregs >= 1
FUNCTION (mixed_q4_k1, 8, 8, 8, 4, 1)
#endif
#if __riscv_ztt_accregs >= 2
FUNCTION (mixed_q4_k2, 8, 8, 8, 4, 2)
#endif
#if __riscv_ztt_accregs >= 4
FUNCTION (mixed_q4_k4, 8, 8, 8, 4, 4)
#endif
#endif
#if __riscv_ztt_uds == 16
#if __riscv_ztt_accregs >= 1
FUNCTION (mixed_q2_k1, 16, 16, 16, 2, 1)
FUNCTION (mixed_left_wide_k1, 32, 16, 16, 2, 1)
FUNCTION (mixed_right_wide_k1, 16, 32, 16, 2, 1)
FUNCTION (mixed_acc_wide_k1, 16, 16, 32, 2, 1)
#endif
#if __riscv_ztt_accregs >= 2
FUNCTION (mixed_q2_k2, 16, 16, 16, 2, 2)
FUNCTION (mixed_left_wide_k2, 32, 16, 16, 2, 2)
FUNCTION (mixed_right_wide_k2, 16, 32, 16, 2, 2)
FUNCTION (mixed_acc_wide_k2, 16, 16, 32, 2, 2)
#endif
#if __riscv_ztt_accregs >= 4
FUNCTION (mixed_q2_k4, 16, 16, 16, 2, 4)
FUNCTION (mixed_left_wide_k4, 32, 16, 16, 2, 4)
FUNCTION (mixed_right_wide_k4, 16, 32, 16, 2, 4)
#endif
#if __riscv_ztt_accregs >= 1
FUNCTION (mixed_q4_k1, 16, 16, 16, 4, 1)
#endif
#if __riscv_ztt_accregs >= 2
FUNCTION (mixed_q4_k2, 16, 16, 16, 4, 2)
#endif
#if __riscv_ztt_accregs >= 4
FUNCTION (mixed_q4_k4, 16, 16, 16, 4, 4)
#endif
#endif
#if __riscv_ztt_uds == 32
#if __riscv_ztt_accregs >= 1
FUNCTION (mixed_q2_k1, 32, 32, 32, 2, 1)
#endif
#if __riscv_ztt_accregs >= 2
FUNCTION (mixed_q2_k2, 32, 32, 32, 2, 2)
#endif
#if __riscv_ztt_accregs >= 4
FUNCTION (mixed_q2_k4, 32, 32, 32, 2, 4)
#endif
#if __riscv_ztt_accregs >= 1
FUNCTION (mixed_q4_k1, 32, 32, 32, 4, 1)
#endif
#if __riscv_ztt_accregs >= 2
FUNCTION (mixed_q4_k2, 32, 32, 32, 4, 2)
#endif
#if __riscv_ztt_accregs >= 4
FUNCTION (mixed_q4_k4, 32, 32, 32, 4, 4)
#endif
#endif
