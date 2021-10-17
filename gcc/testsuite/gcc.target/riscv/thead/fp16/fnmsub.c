/* { dg-do assemble } */
/* { dg-skip-if "test float16 insns" { *-*-* } { "*" } { "-march=*g*xtheadc*" "-march=*f*xtheadc*" } } */
/* { dg-options "-O2 --save-temps" } */

_Float16 func(_Float16 a, _Float16 b, _Float16 c)
{
  return -a * b + c;
}

/* { dg-final { scan-assembler "fnmsub.h" } }*/
