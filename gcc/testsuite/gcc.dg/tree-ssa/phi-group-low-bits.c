/* { dg-do compile } */
/* { dg-options "-O2 -fgimple -fdump-tree-vrp1-details" } */
/* { dg-require-effective-target int32plus } */

extern void consume (unsigned);

#define CYCLE(NAME, LHS, OP, RHS) \
unsigned __GIMPLE (ssa,startwith("vrp1")) \
NAME (unsigned seed, unsigned n, unsigned gate) \
{ \
  unsigned p; unsigned i; unsigned initial; unsigned selector; \
__BB(2): \
  initial_4 = seed_1(D) & 4294967292u; \
  initial_5 = initial_4 | 1u; \
  goto __BB4; \
__BB(3): \
  p_10 = LHS OP RHS; \
  i_11 = i_9 + 1u; \
  if (i_11 < n_2(D)) goto __BB7; else goto __BB8; \
__BB(4): \
  p_6 = __PHI (__BB2: initial_5, __BB7: p_10); \
  i_7 = __PHI (__BB2: 0u, __BB7: i_11); \
  goto __BB6; \
__BB(5): \
  goto __BB6; \
__BB(6): \
  p_8 = __PHI (__BB4: p_6, __BB5: p_10); \
  i_9 = __PHI (__BB4: i_7, __BB5: i_11); \
  consume (p_8); \
  goto __BB3; \
__BB(7): \
  selector_12 = i_11 & gate_3(D); \
  if (selector_12 != 0u) goto __BB4; else goto __BB5; \
__BB(8): \
  return p_10; \
}

CYCLE (cycle_add, p_8, +, 4u)
CYCLE (cycle_sub, p_8, -, 4u)
CYCLE (cycle_reverse, 4u, -, p_8)
CYCLE (cycle_odd, p_8, +, 3u)
CYCLE (cycle_eight, p_8, +, 8u)
CYCLE (cycle_zero, p_8, +, 0u)

/* { dg-final { scan-tree-dump-times "PHI ANALYZER : New PHI GROUP < p_" 4 "vrp1" } } */
