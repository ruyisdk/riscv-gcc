/* { dg-do assemble } */
/* { dg-skip-if "test float16 insns" { *-*-* } { "*" } { "-march=*g*xtheadc*" "-march=*f*xtheadc*" } } */
/* { dg-options "--save-temps" } */

__fp16 func3(long a)
{
  return (__fp16)a;
}

__fp16 func4(unsigned long a)
{
  return (__fp16)a;
}

__fp16 func5(float a)
{
  return (__fp16)a;
}

__fp16 func6(int a)
{
  return (__fp16)a;
}

__fp16 func7(unsigned int a)
{
  return (__fp16)a;
}

long func8(__fp16 a)
{
  return (long)a;
}

unsigned long func9(__fp16 a)
{
  return (unsigned long)a;
}

float func10(__fp16 a)
{
  return (float)a;
}

int func11(__fp16 a)
{
  return (int)a;
}

unsigned int func12(__fp16 a)
{
  return (unsigned int)a;
}

/* { dg-final { scan-assembler "fcvt.h.l" } }*/
/* { dg-final { scan-assembler "fcvt.h.lu" } }*/
/* { dg-final { scan-assembler "fcvt.h.s" } }*/
/* { dg-final { scan-assembler "fcvt.h.w" } }*/
/* { dg-final { scan-assembler "fcvt.h.wu" } }*/
/* { dg-final { scan-assembler "fcvt.l.h" } }*/
/* { dg-final { scan-assembler "fcvt.lu.h" } }*/
/* { dg-final { scan-assembler "fcvt.s.h" } }*/
/* { dg-final { scan-assembler "fcvt.w.h" } }*/
/* { dg-final { scan-assembler "fcvt.wu.h" } }*/
