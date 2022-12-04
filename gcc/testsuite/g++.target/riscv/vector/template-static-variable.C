/* { dg-do compile } */
/* { dg-skip-if "test rvv" { *-*-* } { "*" } { "-march=rv*v*" } } */
#include<riscv_vector.h>

template <uint16_t a>
void f()
{
    unsigned int gvl = vsetvlmax_e8m1();
    static vuint16m1_t v = vmv_v_x_u16m1(a, gvl);
}

int main(int argc, char** argv)
{
    f<2>();
    return 0;
}

/* { dg-error "RVV type 'vuint16m1_t' does not have a fixed size" "" { target *-*-* } 0 } */
