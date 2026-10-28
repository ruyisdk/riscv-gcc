/* { dg-do compile } */
/* { dg-options "-O2 -mstrict-align -mstringop-strategy=vector" } */
/* { dg-additional-options "-march=rv32gcv -mabi=ilp32d" { target rv32 } } */
/* { dg-additional-options "-march=rv64gcv -mabi=lp64d" { target rv64 } } */

void copy_literal4 (unsigned char *p)
{
  __builtin_memcpy (p, "\x80\x01\x7f\x12", 4);
}

void copy_literal8 (unsigned char *p)
{
  __builtin_memcpy (p, "\x80\x01\x7f\x12\x89\xab\xcd\xef", 8);
}

/* { dg-final { scan-assembler-times {\tvle8\.v\t} 2 } } */
/* { dg-final { scan-assembler-times {\tvse8\.v\t} 2 } } */
/* { dg-final { scan-assembler-not {\tsb\t} } } */
