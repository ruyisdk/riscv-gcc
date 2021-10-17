
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv64*p*" } } */
/* { dg-options "-O3 --save-temps" } */

unsigned int a[2];
unsigned int b[2]={1,2};
unsigned int c[2]={3,7};
int i;

int func()
{
  for (i=0;i<2;i++)
   a[i]= b[i]>c[i] ? b[i] : c[i];
}

/* { dg-final { scan-assembler "umax32\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

