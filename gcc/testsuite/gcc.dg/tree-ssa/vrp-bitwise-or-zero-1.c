/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */

extern void unexpected (void);

void
unsigned_pair (unsigned a, unsigned b)
{
  if (((a | b) & 15) == 0)
    if ((a & 15) != 0 || (b & 15) != 0)
      unexpected ();
}

void
signed_pair (int a, int b)
{
  if (((a | b) & 10) == 0)
    if ((a & 10) != 0 || (b & 10) != 0)
      unexpected ();
}

void
three_inputs (unsigned a, unsigned b, unsigned c)
{
  if (((a | b | c) & 15) == 0)
    if ((a & 15) != 0 || (b & 15) != 0 || (c & 15) != 0)
      unexpected ();
}

/* { dg-final { scan-tree-dump-not "unexpected \\(" "optimized" } } */
