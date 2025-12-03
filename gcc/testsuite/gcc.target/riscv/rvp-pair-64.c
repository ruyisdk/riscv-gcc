/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p19 -mabi=lp64" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" "-O0" "-O1"} } */
/* { dg-require-effective-target rv64 } */

unsigned long test_pair_e_w(unsigned long a, unsigned long b) {
    unsigned long a_lo = (unsigned int)a & 0xffffffff;
    unsigned long b_lo = (unsigned int)b & 0xffffffff;
    return ((a_lo) | (b_lo << 32));
}

unsigned long test_pair_oe_w(unsigned long a, unsigned long b) {
    return (a >> 32 | b << 32);
}


unsigned long test_pair_eo_w_1(unsigned long a, unsigned long b) {
    unsigned long a_lo = a & 0x00000000ffffffff;
    unsigned long b_hi = b & 0xffffffff00000000;
    return (a_lo | b_hi);
}

unsigned long test_pair_eo_w_2(unsigned long a, unsigned long b) {
    unsigned int a_lo = (unsigned int)a;
    unsigned long b_hi = b & 0xffffffff00000000;
    return (a_lo | b_hi);
}

unsigned long test_pair_o_w(unsigned long a, unsigned long b) {
    unsigned long a_hi = a & 0xffffffff00000000;
    unsigned long b_hi = b & 0xffffffff00000000;
    return ((unsigned long)a_hi >> 32) | (b_hi);
}

/* { dg-final { scan-assembler-times {\mpack\M} 1 } } */
/* { dg-final { scan-assembler-times {\mppaireo\.w\M} 2 } } */
/* { dg-final { scan-assembler-times {\mppairoe\.w\M} 1 } } */
/* { dg-final { scan-assembler-times {\mppairo\.w\M} 1 } } */
