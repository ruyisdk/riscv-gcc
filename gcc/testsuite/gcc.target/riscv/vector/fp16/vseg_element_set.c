
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16x2xm1_t test_vseg_element_set_float16x2xm1 (float16x2xm1_t dest, const int index, float16xm1_t element) {
    return vseg_element_set_float16x2xm1 (dest, 0, element);
}


float16x2xm2_t test_vseg_element_set_float16x2xm2 (float16x2xm2_t dest, const int index, float16xm2_t element) {
    return vseg_element_set_float16x2xm2 (dest, 0, element);
}


float16x2xm4_t test_vseg_element_set_float16x2xm4 (float16x2xm4_t dest, const int index, float16xm4_t element) {
    return vseg_element_set_float16x2xm4 (dest, 0, element);
}


float16x3xm1_t test_vseg_element_set_float16x3xm1 (float16x3xm1_t dest, const int index, float16xm1_t element) {
    return vseg_element_set_float16x3xm1 (dest, 0, element);
}


float16x3xm2_t test_vseg_element_set_float16x3xm2 (float16x3xm2_t dest, const int index, float16xm2_t element) {
    return vseg_element_set_float16x3xm2 (dest, 0, element);
}


float16x4xm1_t test_vseg_element_set_float16x4xm1 (float16x4xm1_t dest, const int index, float16xm1_t element) {
    return vseg_element_set_float16x4xm1 (dest, 0, element);
}


float16x4xm2_t test_vseg_element_set_float16x4xm2 (float16x4xm2_t dest, const int index, float16xm2_t element) {
    return vseg_element_set_float16x4xm2 (dest, 0, element);
}


float16x5xm1_t test_vseg_element_set_float16x5xm1 (float16x5xm1_t dest, const int index, float16xm1_t element) {
    return vseg_element_set_float16x5xm1 (dest, 0, element);
}


float16x6xm1_t test_vseg_element_set_float16x6xm1 (float16x6xm1_t dest, const int index, float16xm1_t element) {
    return vseg_element_set_float16x6xm1 (dest, 0, element);
}


float16x7xm1_t test_vseg_element_set_float16x7xm1 (float16x7xm1_t dest, const int index, float16xm1_t element) {
    return vseg_element_set_float16x7xm1 (dest, 0, element);
}


float16x8xm1_t test_vseg_element_set_float16x8xm1 (float16x8xm1_t dest, const int index, float16xm1_t element) {
    return vseg_element_set_float16x8xm1 (dest, 0, element);
}


/* { dg-final { cleanup-saved-temps } } */

