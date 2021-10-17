
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16xm1_t test_vseg_element_get_float16x2xm1 (float16x2xm1_t source, const int index) {
    return vseg_element_get_float16x2xm1 (source, 0);
}


float16xm1_t test_vseg_element_get_float16x3xm1 (float16x3xm1_t source, const int index) {
    return vseg_element_get_float16x3xm1 (source, 0);
}


float16xm1_t test_vseg_element_get_float16x4xm1 (float16x4xm1_t source, const int index) {
    return vseg_element_get_float16x4xm1 (source, 0);
}


float16xm1_t test_vseg_element_get_float16x5xm1 (float16x5xm1_t source, const int index) {
    return vseg_element_get_float16x5xm1 (source, 0);
}


float16xm1_t test_vseg_element_get_float16x6xm1 (float16x6xm1_t source, const int index) {
    return vseg_element_get_float16x6xm1 (source, 0);
}


float16xm1_t test_vseg_element_get_float16x7xm1 (float16x7xm1_t source, const int index) {
    return vseg_element_get_float16x7xm1 (source, 0);
}


float16xm1_t test_vseg_element_get_float16x8xm1 (float16x8xm1_t source, const int index) {
    return vseg_element_get_float16x8xm1 (source, 0);
}


float16xm2_t test_vseg_element_get_float16x2xm2 (float16x2xm2_t source, const int index) {
    return vseg_element_get_float16x2xm2 (source, 0);
}


float16xm2_t test_vseg_element_get_float16x3xm2 (float16x3xm2_t source, const int index) {
    return vseg_element_get_float16x3xm2 (source, 0);
}


float16xm2_t test_vseg_element_get_float16x4xm2 (float16x4xm2_t source, const int index) {
    return vseg_element_get_float16x4xm2 (source, 0);
}


float16xm4_t test_vseg_element_get_float16x2xm4 (float16x2xm4_t source, const int index) {
    return vseg_element_get_float16x2xm4 (source, 0);
}


/* { dg-final { cleanup-saved-temps } } */

