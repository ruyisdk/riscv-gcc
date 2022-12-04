/* { dg-do compile } */
/* { dg-skip-if "test rvv" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-std=gnu99" } */

#include <riscv_vector.h>

typedef signed char int8x32_t __attribute__((__vector_size__ (32)));

/* Sizeless objects with global scope.  */

vint8m1_t global_rvv_sc; /* { dg-error {RVV type 'vint8m1_t' does not have a fixed size} } */
static vint8m1_t local_rvv_sc; /* { dg-error {RVV type 'vint8m1_t' does not have a fixed size} } */
extern vint8m1_t extern_rvv_sc; /* { dg-error {RVV type 'vint8m1_t' does not have a fixed size} } */
__thread vint8m1_t tls_rvv_sc; /* { dg-error {variables of type 'vint8m1_t' cannot have thread-local storage duration} } */
_Atomic vint8m1_t atomic_rvv_sc; /* { dg-error {RVV type 'vint8m1_t' does not have a fixed size} } */

/* Sizeless arrays.  */

typedef vint8m1_t array_type[2]; /* { dg-error {array elements cannot have RVV type 'vint8m1_t'} } */
extern vint8m1_t extern_array[]; /* { dg-error {array elements cannot have RVV type 'vint8m1_t'} } */

/* Sizeless fields.  */

struct struct1 {
  vint8m1_t a; /* { dg-error {fields cannot have RVV type 'vint8m1_t'} } */
};

union union1 {
  vint8m1_t a; /* { dg-error {fields cannot have RVV type 'vint8m1_t'} } */
};

/* Pointers to sizeless types.  */

vint8m1_t *global_rvv_sc_ptr;
vint8m1_t *invalid_rvv_sc_ptr = &(vint8m1_t) { *global_rvv_sc_ptr }; /* { dg-error {initializer element is not constant} } */
  /* { dg-error {RVV type 'vint8m1_t' does not have a fixed size} "2nd line" { target *-*-* } .-1 } */

/* Sizeless arguments and return values.  */

void ext_consume_rvv_sc (vint8m1_t);
void ext_consume_varargs (int, ...);
vint8m1_t ext_produce_rvv_sc ();

/* Main tests for statements and expressions.  */

void
statements (int n)
{
  /* Local declarations.  */

  unsigned char va __attribute__((__vector_size__(2)));
  vint8m1_t rvv_sc1, rvv_sc2;
  _Atomic vint8m1_t atomic_rvv_sc;
  int8x32_t gnu_sc1;
  vint16m1_t rvv_sh1;
  static vint8m1_t local_static_rvv_sc; /* { dg-error {RVV type 'vint8m1_t' does not have a fixed size} } */

  /* Layout queries.  */

  sizeof (vint8m1_t); /* { dg-error {RVV type 'vint8m1_t' does not have a fixed size} } */
  sizeof (rvv_sc1); /* { dg-error {RVV type 'vint8m1_t' does not have a fixed size} } */
  sizeof (ext_produce_rvv_sc ()); /* { dg-error {RVV type 'vint8m1_t' does not have a fixed size} } */
  _Alignof (vint8m1_t); /* { dg-error {RVV type 'vint8m1_t' does not have a defined alignment} } */
  _Alignof (rvv_sc1); /* { dg-error {RVV type 'vint8m1_t' does not have a defined alignment} } */
  _Alignof (ext_produce_rvv_sc ()); /* { dg-error {RVV type 'vint8m1_t' does not have a defined alignment} } */

  /* Initialization.  */

  vint8m1_t init_rvv_sc1 = rvv_sc1;
  vint8m1_t init_rvv_sc2 = rvv_sh1; /* { dg-error {incompatible types when initializing type 'vint8m1_t' using type 'vint16m1_t'} } */
  vint8m1_t init_rvv_sc3 = {}; /* { dg-error {empty scalar initializer} } */

  int initi_a = rvv_sc1; /* { dg-error {incompatible types when initializing type 'int' using type 'vint8m1_t'} } */
  int initi_b = { rvv_sc1 }; /* { dg-error {incompatible types when initializing type 'int' using type 'vint8m1_t'} } */

  /* Compound literals.  */

  (vint8m1_t) {}; /* { dg-error {empty scalar initializer} } */
  (vint8m1_t) { rvv_sc1 };

  (int) { rvv_sc1 }; /* { dg-error {incompatible types when initializing type 'int' using type 'vint8m1_t'} } */

  /* Arrays.  */

  vint8m1_t array[2]; /* { dg-error {array elements cannot have RVV type 'vint8m1_t'} } */
  vint8m1_t zero_length_array[0]; /* { dg-error {array elements cannot have RVV type 'vint8m1_t'} } */
  vint8m1_t empty_init_array[] = {}; /* { dg-error {array elements cannot have RVV type 'vint8m1_t'} } */
  typedef vint8m1_t vla_type[n]; /* { dg-error {array elements cannot have RVV type 'vint8m1_t'} } */

  /* Assignment.  */

  n = rvv_sc1; /* { dg-error {incompatible types when assigning to type 'int' from type 'vint8m1_t'} } */

  rvv_sc1 = 0; /* { dg-error {incompatible types when assigning to type 'vint8m1_t' from type 'int'} } */
  rvv_sc1 = rvv_sc2;
  rvv_sc1 = rvv_sh1; /* { dg-error {incompatible types when assigning to type 'vint8m1_t' from type 'vint16m1_t'} } */

  /* Casting.  */

  (void) rvv_sc1;
  (vint8m1_t) rvv_sc1;

  /* Addressing and dereferencing.  */

  vint8m1_t *rvv_sc_ptr = &rvv_sc1;
  int8x32_t *gnu_sc_ptr = &gnu_sc1;
  rvv_sc1 = *rvv_sc_ptr;

  /* Pointer assignment.  */

  gnu_sc_ptr = rvv_sc_ptr; /* { dg-warning {assignment to [^\n]* from incompatible pointer type} } */
  rvv_sc_ptr = gnu_sc_ptr; /* { dg-warning {assignment to [^\n]* from incompatible pointer type} } */

  /* Pointer arithmetic.  */

  ++rvv_sc_ptr; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  --rvv_sc_ptr; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  rvv_sc_ptr++; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  rvv_sc_ptr--; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  rvv_sc_ptr += 0; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  rvv_sc_ptr += 1; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  rvv_sc_ptr -= 0; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  rvv_sc_ptr -= 1; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  rvv_sc_ptr - rvv_sc_ptr; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  gnu_sc_ptr - rvv_sc_ptr; /* { dg-error {invalid operands to binary -} } */
  rvv_sc_ptr - gnu_sc_ptr; /* { dg-error {invalid operands to binary -} } */
  rvv_sc1 = rvv_sc_ptr[0]; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */
  rvv_sc1 = rvv_sc_ptr[1]; /* { dg-error {arithmetic on pointer to RVV type 'vint8m1_t'} } */

  /* Pointer comparison.  */

  rvv_sc_ptr == &rvv_sc1;
  rvv_sc_ptr != &rvv_sc1;
  rvv_sc_ptr < &rvv_sc1;
  rvv_sc_ptr <= &rvv_sc1;
  rvv_sc_ptr > &rvv_sc1;
  rvv_sc_ptr >= &rvv_sc1;
  gnu_sc_ptr == rvv_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  gnu_sc_ptr != rvv_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  gnu_sc_ptr < rvv_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  gnu_sc_ptr <= rvv_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  gnu_sc_ptr > rvv_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  gnu_sc_ptr >= rvv_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  rvv_sc_ptr == gnu_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  rvv_sc_ptr != gnu_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  rvv_sc_ptr < gnu_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  rvv_sc_ptr <= gnu_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  rvv_sc_ptr > gnu_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */
  rvv_sc_ptr >= gnu_sc_ptr; /* { dg-warning {comparison of distinct pointer types lacks a cast} } */

  /* Conditional expressions.  */

  0 ? rvv_sc1 : rvv_sc1;
  0 ? rvv_sc1 : rvv_sh1; /* { dg-error {type mismatch in conditional expression} } */
  0 ? rvv_sc1 : 0; /* { dg-error {type mismatch in conditional expression} } */
  0 ? 0 : rvv_sc1; /* { dg-error {type mismatch in conditional expression} } */
  0 ?: rvv_sc1; /* { dg-error {type mismatch in conditional expression} } */
  0 ? rvv_sc_ptr : rvv_sc_ptr;
  0 ? rvv_sc_ptr : gnu_sc_ptr; /* { dg-warning {pointer type mismatch in conditional expression} } */
  0 ? gnu_sc_ptr : rvv_sc_ptr; /* { dg-warning {pointer type mismatch in conditional expression} } */

  /* Generic associations.  */

  _Generic (rvv_sc1, default: 100);
  _Generic (1, vint8m1_t: 10, default: 20);

  /* Function arguments.  */

  ext_consume_rvv_sc (rvv_sc1);
  ext_consume_rvv_sc (rvv_sh1); /* { dg-error {incompatible type for argument 1 of 'ext_consume_rvv_sc'} } */
  ext_consume_varargs (rvv_sc1); /* { dg-error {incompatible type for argument 1 of 'ext_consume_varargs'} } */
  ext_consume_varargs (1, rvv_sc1);

  /* Function returns.  */

  ext_produce_rvv_sc ();
  rvv_sc1 = ext_produce_rvv_sc ();
  rvv_sh1 = ext_produce_rvv_sc (); /* { dg-error {incompatible types when assigning to type 'vint16m1_t' from type 'vint8m1_t'} } */

  /* Varargs processing.  */

  __builtin_va_list valist;
  __builtin_va_arg (valist, vint8m1_t);

  /* Statement expressions.  */

  ({ rvv_sc1; });
  ({ vint8m1_t another_rvv_sc = *rvv_sc_ptr; another_rvv_sc; });
}

/* Function parameters in definitions.  */

void
old_style (input_rvv_sc)
     vint8m1_t input_rvv_sc;
{
  vint8m1_t rvv_sc1 = input_rvv_sc;
}

void
new_style_param (vint8m1_t input_rvv_sc)
{
  vint8m1_t rvv_sc1 = input_rvv_sc;
}

/* Function return values in definitions.  */

vint8m1_t
good_return_rvv_sc (vint8m1_t param)
{
  return param;
}

vint8m1_t
bad_return_rvv_sc (vint16m1_t param)
{
  return param; /* { dg-error {incompatible types when returning type 'vint16m1_t' but 'vint8m1_t' was expected} } */
}
