/* TODO: This case can't be auto vectorized now, and open
         this file when the common vectorize pass can deal
         with it. */
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } {} } */
/* { dg-options "-O3 --save-temps" } */

#if (__riscv_xlen==64)
#define N 8
#else
#define N 4
#endif

signed char a[N];
signed char b[N];
long c;
unsigned char ua[N];
unsigned char ub[N];

int auto_sra()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]>>c;
}

/* { dg-final { scan-assembler "sra8\t" } }*/

int auto_srl()
{
  int i;
  for (i=0;i<N;i++)
   ua[i]= ub[i]>>c;
}

/* { dg-final { scan-assembler "srl8\t" } }*/

int auto_sll()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]<<c;
}

/* { dg-final { scan-assembler "sll8\t" } }*/

int auto_srai()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]>>3;
}

/* { dg-final { scan-assembler "srai8\t" } }*/

int auto_srli()
{
  int i;
  for (i=0;i<N;i++)
   ua[i]= ub[i]>>3;
}

/* { dg-final { scan-assembler "srli8\t" } }*/

int auto_slli()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]<<3;
}

/* { dg-final { scan-assembler "slli8\t" } }*/

/* { dg-final { cleanup-saved-temps } } */
