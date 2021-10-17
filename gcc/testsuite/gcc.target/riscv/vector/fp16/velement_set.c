
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16xm2_t test_velement_set_float16xm2 (float16xm2_t dest, const int index, float16xm1_t element) {
    return velement_set_float16xm2 (dest, 0, element);
}


float16xm4_t test_velement_set_float16xm4 (float16xm4_t dest, const int index, float16xm1_t element) {
    return velement_set_float16xm4 (dest, 0, element);
}


float16xm8_t test_velement_set_float16xm8 (float16xm8_t dest, const int index, float16xm1_t element) {
    return velement_set_float16xm8 (dest, 0, element);
}


/* { dg-final { cleanup-saved-temps } } */

