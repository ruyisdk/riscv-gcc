/* { dg-do compile } */
/* { dg-require-effective-target rv32 } */
/* { dg-options "-march=rv32gcp0p19 -mabi=ilp32 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Og" "-g" "-flto" } } */

/* Test RV32 8-byte packed vector move patterns.
   On RV32, 8-byte vectors use register pairs and are split into
   two 32-bit loads/stores.  */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef short pv4hi __attribute__((vector_size (8)));

/* Test load operations - should generate two lw instructions */
pv8qi
load_pv8qi (pv8qi *p)
{
  return *p;
}

pv4hi
load_pv4hi (pv4hi *p)
{
  return *p;
}

/* Test store operations - should generate two sw instructions */
void
store_pv8qi (pv8qi *p, pv8qi v)
{
  *p = v;
}

void
store_pv4hi (pv4hi *p, pv4hi v)
{
  *p = v;
}

/* Test register-to-register move (function parameter passing) */
pv8qi
move_pv8qi (pv8qi a)
{
  return a;
}

pv4hi
move_pv4hi (pv4hi a)
{
  return a;
}

/* Test even register pair move using PMV.DBS/DHS.
   When both source and destination are even-numbered register pairs,
   we can use a single PMV.DxS instruction instead of two mv.  */
pv8qi
copy_pv8qi_even (pv8qi a, pv8qi b)
{
  /* a is in a0,a1, b is in a2,a3 - both even starts */
  return b;  /* Should use pmv.dbs a0,a2 */
}

pv4hi
copy_pv4hi_even (pv4hi a, pv4hi b)
{
  return b;  /* Should use pmv.dhs a0,a2 */
}

/* { dg-final { scan-assembler-times {\mlw\M} 4 } } */
/* { dg-final { scan-assembler-times {\msw\M} 4 } } */
/* { dg-final { scan-assembler-times {\mpmv\.dbs\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmv\.dhs\M} 1 } } */
