/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p21 -mabi=lp64d -O3" } */

/* A byte-granularity zip {0,4,1,5} on a PV4QI vector has no corresponding
   P-extension instruction (zip16p operates on halfwords).  The vec_perm
   expander used to claim support and emit an unrecognizable insn, causing an
   ICE in the vregs pass.  It must now fall back to generic expansion.  */

void bar (unsigned char *q, unsigned short *data16s, int len)
{
  int i;

  for (i = 0; i < len; i++)
    {
      q[2 * i] =
	(((data16s[i] & 0xFF) << 8) | ((data16s[i] >> 8) & 0xFF)) & 0xFF;
      q[2 * i + 1] =
	((unsigned short)
	 (((data16s[i] & 0xFF) << 8) | ((data16s[i] >> 8) & 0xFF))) >> 8;
    }
}
