/* { dg-do compile } */
/* { dg-skip-if "Auxiliary source" { *-*-* } } */
extern "C"
__attribute__((used,noinline)) int scalar_lto (int x) { return x + 3; }
