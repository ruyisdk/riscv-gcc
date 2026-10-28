typedef __UINTPTR_TYPE__ word;

#ifdef __cplusplus
extern "C" {
#endif
extern int query_size (word *);
extern void escape_argument (void **);
extern void record_arguments (word, word, word, word, word, word, word, word,
                              void *, word);

#define PARAMETERS(Q) word a, word b, word c, word d, word e, word f, \
  word g, word h, void * Q workspace, word bytes
#define CHECK_BODY(PREPARE) \
{ \
  word t; \
  if (query_size (&t)) return 1; \
  PREPARE \
  if (!workspace) return 2; \
  word need = 12 * t * t; \
  if (((word) workspace & 15) || bytes < need) return 3; \
  word end = (word) workspace + need; \
  if (end < need) return 4; \
  if (((word) workspace < a + b && a < end) \
      || ((word) workspace < c + d && c < end) \
      || ((word) workspace < e + f && e < end) \
      || ((word) workspace < g + h && g < end)) return 5; \
  record_arguments (a, b, c, d, e, f, g, h, workspace, t); \
  return 0; \
}

int stack_argument (PARAMETERS ()) CHECK_BODY ()
int stack_addressed (PARAMETERS ())
  CHECK_BODY (escape_argument (&workspace);)
int stack_volatile (PARAMETERS (volatile)) CHECK_BODY ()

#undef CHECK_BODY
#undef PARAMETERS
#ifdef __cplusplus
}
#endif
