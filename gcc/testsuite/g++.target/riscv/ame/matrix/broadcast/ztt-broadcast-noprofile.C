/* integer broadcast.  */
/* { dg-do preprocess { target rv64 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" } */
#ifdef __riscv_ztt_mbcast_m_x_int
#error broadcast capability requires Ztt and a typed profile
#endif
