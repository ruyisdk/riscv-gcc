
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16xm1_t test_velement_get_float16xm2 (float16xm2_t source, const int index) {
    return velement_get_float16xm2 (source, 0);
}


float16xm1_t test_velement_get_float16xm4 (float16xm4_t source, const int index) {
    return velement_get_float16xm4 (source, 0);
}


float16xm1_t test_velement_get_float16xm8 (float16xm8_t source, const int index) {
    return velement_get_float16xm8 (source, 0);
}


/* { dg-final { cleanup-saved-temps } } */

