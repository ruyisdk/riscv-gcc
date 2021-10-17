
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv*p*" } } */
/* { dg-options "-O3 --save-temps" } */

#define N 4

signed short a[N];
signed short b[N];
signed short c[N];
unsigned short ua[N];
unsigned short ub[N];
unsigned short uc[N];

int func()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i] + c[i];
}

/* { dg-final { scan-assembler "add16\t" } }*/

int ufunc()
{
  int i;
  for (i=0;i<N;i++)
   ua[i]= ub[i] + uc[i];
}

/* { dg-final { scan-assembler "add16\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

