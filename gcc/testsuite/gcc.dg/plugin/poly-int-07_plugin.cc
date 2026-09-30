/* Not worth spending time optimizing this.  */
/* { dg-options "-O0" } */

#include "config.h"
#include "gcc-plugin.h"
#include "system.h"
#include "coretypes.h"
#include "poly-int-tests.h"

int plugin_is_GPL_compatible;

int
plugin_init (struct plugin_name_args *plugin_info,
	     struct plugin_gcc_version *version)
{
  test_num_coeffs_core<3> ();
  typedef poly_int<3, HOST_WIDE_INT> T;
  ASSERT_TRUE (maybe_eq (T (16, 0, 16), 64));
  ASSERT_FALSE (maybe_eq (T (16, 0, 16), 63));
  ASSERT_TRUE (maybe_eq (64, T (16, 0, 16)));
  ASSERT_FALSE (maybe_eq (T (16, 8, 16), 8));
  ASSERT_FALSE (maybe_eq (T (8, -8, -16), 16));
  ASSERT_TRUE (maybe_eq (T (8, -8, 16), 16));
  ASSERT_FALSE (maybe_eq (T (8, 8, 16), T (16, 8, 16)));
  ASSERT_TRUE (maybe_eq (T (8, 8, 16), T (16, 16, 8)));
  /* A witnessed intersection must never be rejected.  */
  for (int a = -3; a <= 3; ++a)
    for (int b = -3; b <= 3; ++b)
      for (int c = -3; c <= 3; ++c)
	for (int x = 0; x <= 3; ++x)
	  for (int y = 0; y <= 3; ++y)
	    ASSERT_TRUE (maybe_eq (T (a, b, c), a + b * x + c * y));
  return 0;
}
