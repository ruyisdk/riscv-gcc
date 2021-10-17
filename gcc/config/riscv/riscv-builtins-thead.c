
#include "convert.h"

enum riscv_builtin_imm {
  RISCV_BUILTIN_IMM2 = 2,
  RISCV_BUILTIN_IMM_STRAT = RISCV_BUILTIN_IMM2,
  RISCV_BUILTIN_IMM3,
  RISCV_BUILTIN_IMM4,
  RISCV_BUILTIN_IMM5,
  RISCV_BUILTIN_IMM6,
  RISCV_BUILTIN_IMM_END
};

/* Builtin types for the short immediately number.  */

static tree
riscv_build_imm_type (enum riscv_builtin_imm prec, signop unsigned_p)
{
  tree *ret;

  static tree riscv_const_imm_nodes[(RISCV_BUILTIN_IMM_END
				     - RISCV_BUILTIN_IMM_STRAT) * 2];

  ret = &riscv_const_imm_nodes[(prec - RISCV_BUILTIN_IMM_STRAT)
				   * (unsigned_p + 1)];
  if (*ret == NULL_TREE)
    {
      *ret = unsigned_p ? make_unsigned_type (BITS_PER_UNIT * 4)
			: make_signed_type (BITS_PER_UNIT * 4);

      set_min_and_max_values_for_integral_type (*ret, prec, unsigned_p);
    }

  return *ret;
}

static tree
riscv_build_function_type (enum riscv_function_type);

/* Helper function for riscv_expand_builtin().
   builtin_prototype is the prototype come from builtin description.
   exp is the expression for the function call.
   So far, only UIMM are handled.  */

static void
riscv_warning_builtin_args (enum riscv_function_type builtin_prototype,
			    tree exp)
{
  tree arg_decl =
    TYPE_ARG_TYPES (riscv_build_function_type (builtin_prototype));

  for (int argno = 0; argno < call_expr_nargs (exp); argno++)
    {
      tree argtype = TREE_VALUE (arg_decl);
      tree arg = CALL_EXPR_ARG (exp, argno);

      arg_decl = TREE_CHAIN (arg_decl);

      /* So far, only UIMM are handled. */
      if (!INTEGRAL_TYPE_P (argtype) || !CONSTANT_CLASS_P (arg))
	continue;

      signop sign = TYPE_SIGN (argtype);
      enum riscv_builtin_imm prec;
      location_t loc = EXPR_LOCATION (arg);

      for (prec = RISCV_BUILTIN_IMM_STRAT; prec < RISCV_BUILTIN_IMM_END;
	   prec = (enum riscv_builtin_imm) (prec + 1))
	{
	  if (argtype != riscv_build_imm_type (prec, sign))
	    continue;
	  else if (!int_fits_type_p (arg, argtype))
	    {
	      TYPE_PRECISION (argtype) = prec;
	      tree new_arg = convert_to_integer (argtype, arg);
	      warning_at (loc, OPT_Wbuiltin_const_overflow,
			   (TYPE_UNSIGNED (arg)
			     ? ("conversion from constant to %qT "
				"changes value from %qE to %qE")
			     : ("unsigned conversion from constant to %qT "
				"changes value from %qE to %qE")),
			    argtype, arg, new_arg);
	      TYPE_PRECISION (argtype) = BITS_PER_WORD;
	      arg = new_arg;
	    }
	  break;
	}
    }
}

/* The user-visible __fp16 type, and a pointer to that type.  Used
   across the back-end.  */
tree riscv_fp16_type_node = NULL_TREE;
tree riscv_fp16_ptr_type_node = NULL_TREE;

enum {
#define RVV_VECTOR_TYPE_DEF(MODE, ELTYPE, LMUL, ELTYPE_NODE, AVAIL) \
  ELTYPE##xm##LMUL##_t_##AVAIL,
#include "config/riscv/riscv-vector-type.def"
#undef RVV_VECTOR_TYPE_DEF
  ELTYPE_END
};

typedef struct {
  tree node;
  const char *name;
  machine_mode mode;
  tree *eltype;
  unsigned int (*avail) (void);
} riscv_vector_type_description;
static riscv_vector_type_description riscv_vector_types[] = {
#define RVV_VECTOR_TYPE_DEF(MODE, ELTYPE, LMUL, ELTYPE_NODE, AVAIL) \
  { NULL_TREE, #ELTYPE "xm" #LMUL "_t", \
    MODE, &ELTYPE_NODE##_type_node, riscv_builtin_avail_##AVAIL},
#include "config/riscv/riscv-vector-type.def"
#undef RVV_VECTOR_TYPE_DEF
};

enum {
#define RVV_VECTOR_SEG_TYPE_DEF(MODE, ELTYPE, LMUL, NF, AVAIL, SEW, VLEN, UNSIGNED) \
  ELTYPE##x##NF##xm##LMUL##_t_##AVAIL,
#include "config/riscv/riscv-vector-seg-type.def"
#undef RVV_VECTOR_SEG_TYPE_DEF
  ELTYP_SEG_END
};

typedef struct {
  tree node;
  const char *name;
  machine_mode mode;
  bool is_unsigned;
  unsigned int (*avail) (void);
} riscv_vector_seg_type_description;
static riscv_vector_seg_type_description riscv_vector_seg_types[] = {
#define RVV_VECTOR_SEG_TYPE_DEF(MODE, ELTYPE, LMUL, NF, AVAIL, SEW, VLEN, UNSIGNED) \
  { NULL_TREE, \
    #ELTYPE "x" #NF "xm" #LMUL "_t", MODE, UNSIGNED, riscv_builtin_avail_##AVAIL},
#include "config/riscv/riscv-vector-seg-type.def"
#undef RVV_VECTOR_SEG_TYPE_DEF
};


static tree
riscv_build_vector_type (tree type, machine_mode mode)
{
  static tree types[2 * (int) MAX_MACHINE_MODE];
  int mode_index;

  mode_index = (int) mode;

  if (TREE_CODE (type) == INTEGER_TYPE && TYPE_UNSIGNED (type))
    mode_index += MAX_MACHINE_MODE;

  if (types[mode_index] == NULL_TREE)
    types[mode_index] = build_vector_type_for_mode (type, mode);
  return types[mode_index];
}

static void
riscv_init_fp16_types (void)
{
  riscv_fp16_type_node = make_node (REAL_TYPE);
  TYPE_PRECISION (riscv_fp16_type_node) = 16;
  layout_type (riscv_fp16_type_node);

  (*lang_hooks.types.register_builtin_type) (riscv_fp16_type_node, "__fp16");
  riscv_fp16_ptr_type_node = build_pointer_type (riscv_fp16_type_node);
}

static void
riscv_init_vector_types (void)
{
  tree tdecl;

  for (unsigned int i = 0; i < ARRAY_SIZE (riscv_vector_types); i++)
    {
      riscv_vector_type_description *d = &riscv_vector_types[i];
      if (d->avail ())
	{
	  tree eltype = *(d->eltype);
	  enum machine_mode mode = d->mode;
	  tree tdecl;

	  d->node = build_distinct_type_copy (
	    riscv_build_vector_type (eltype, mode));
	  tdecl = add_builtin_type (d->name,d->node);
	  TYPE_NAME (d->node) = tdecl;
	  SET_TYPE_STRUCTURAL_EQUALITY (d->node);
	}
    }

  for (unsigned int i = 0; i < ARRAY_SIZE (riscv_vector_seg_types); i++)
    {
      riscv_vector_seg_type_description *d = &riscv_vector_seg_types[i];

      if (d->avail ())
	{
	  if (d->is_unsigned)
	    d->node = make_unsigned_type (GET_MODE_PRECISION (d->mode));
	  else
	    d->node = make_signed_type (GET_MODE_PRECISION (d->mode));
	  SET_TYPE_MODE (d->node, d->mode);
	  tdecl = add_builtin_type (d->name, d->node);
	  TYPE_NAME (d->node) = tdecl;
	}

    }
}

const char *
riscv_mangle_builtin_type (const_tree type)
{
  if (TREE_CODE (TYPE_NAME (type)) == TYPE_DECL
      && DECL_NAME (TYPE_NAME (type))
      && !strcmp (IDENTIFIER_POINTER (DECL_NAME (TYPE_NAME (type))),
		  "__fp16"))
    return "__fp16";

  for (unsigned int i = 0; i < ARRAY_SIZE (riscv_vector_seg_types); i++)
    {
      if (TREE_CODE (TYPE_NAME (type)) == TYPE_DECL
	  && DECL_NAME (TYPE_NAME (type))
	  && !strcmp (IDENTIFIER_POINTER (DECL_NAME (TYPE_NAME (type))),
		      riscv_vector_seg_types[i].name))
	return riscv_vector_seg_types[i].name;
    }
  return NULL;
}

static void
extra_argument_check (const struct riscv_builtin_description *d, tree exp)
{
  int source_op = 0;
  HOST_WIDE_INT val;

  switch (d->prototype)
  {
#define RISCV_INDEX_GET_FTYPE(FTYPE) \
    case FTYPE:
#include "config/riscv/riscv-ftypes-special.def"
#undef RISCV_INDEX_GET_FTYPE
      source_op = 1;

#define RISCV_INDEX_SET_FTYPE(FTYPE) \
    case FTYPE:
#include "config/riscv/riscv-ftypes-special.def"
#undef RISCV_INDEX_SET_FTYPE
    {
      tree constarg = CALL_EXPR_ARG (exp, 1);
      machine_mode vector_mode = insn_data[d->icode].operand[source_op].mode;
      if (TREE_CODE(constarg) != INTEGER_CST)
	error ("argument 2 should be a constant");
      val = int_cst_value (constarg);
      int max_index = ((GET_MODE_SIZE (vector_mode) * BITS_PER_UNIT) / riscv_vlen) - 1;
      if (val < 0 || val > max_index)
	error ("argument 2 should be in 0 to %d", max_index);
      break;
    }

    default:
      break;
  }
}

/* Argument types.  */
#define RISCV_ATYPE_UQI unsigned_intQI_type_node
#define RISCV_ATYPE_QI intQI_type_node
#define RISCV_ATYPE_UHI unsigned_intHI_type_node
#define RISCV_ATYPE_HI intHI_type_node
#define RISCV_ATYPE_SI intSI_type_node
#define RISCV_ATYPE_UDI unsigned_intDI_type_node
#define RISCV_ATYPE_DI intDI_type_node
#define RISCV_ATYPE_HF riscv_fp16_type_node
#define RISCV_ATYPE_SF float_type_node
#define RISCV_ATYPE_DF double_type_node
#define RISCV_ATYPE_TF float128_type_node
#define RISCV_ATYPE_POINTER ptr_type_node
#define RISCV_ATYPE_INDEX intSI_type_node

#define RISCV_ATYPE_UIMM6 riscv_build_imm_type (RISCV_BUILTIN_IMM6, UNSIGNED)
#define RISCV_ATYPE_UIMM5 riscv_build_imm_type (RISCV_BUILTIN_IMM5, UNSIGNED)
#define RISCV_ATYPE_UIMM4 riscv_build_imm_type (RISCV_BUILTIN_IMM4, UNSIGNED)
#define RISCV_ATYPE_UIMM3 riscv_build_imm_type (RISCV_BUILTIN_IMM3, UNSIGNED)
#define RISCV_ATYPE_UIMM2 riscv_build_imm_type (RISCV_BUILTIN_IMM2, UNSIGNED)
#define RISCV_ATYPE_CUIMM6 RISCV_ATYPE_UIMM6
#define RISCV_ATYPE_CUIMM5 RISCV_ATYPE_UIMM5
#define RISCV_ATYPE_CUIMM4 RISCV_ATYPE_UIMM4
#define RISCV_ATYPE_CUIMM3 RISCV_ATYPE_UIMM3
#define RISCV_ATYPE_CUIMM2 RISCV_ATYPE_UIMM2

#define RISCV_ATYPE_V8TI riscv_build_vector_type (intTI_type_node, V8TImode)
#define RISCV_ATYPE_V4TI riscv_build_vector_type (intTI_type_node, V4TImode)
#define RISCV_ATYPE_V2TI riscv_build_vector_type (intTI_type_node, V2TImode)
#define RISCV_ATYPE_V1TI riscv_build_vector_type (intTI_type_node, V1TImode)
#define RISCV_ATYPE_UV8TI riscv_build_vector_type (unsigned_intTI_type_node, V8TImode)
#define RISCV_ATYPE_UV4TI riscv_build_vector_type (unsigned_intTI_type_node, V4TImode)
#define RISCV_ATYPE_UV2TI riscv_build_vector_type (unsigned_intTI_type_node, V2TImode)
#define RISCV_ATYPE_UV1TI riscv_build_vector_type (unsigned_intTI_type_node, V1TImode)

#define RISCV_ATYPE_V16DI riscv_build_vector_type (intDI_type_node, V16DImode)
#define RISCV_ATYPE_V8DI riscv_build_vector_type (intDI_type_node, V8DImode)
#define RISCV_ATYPE_V4DI riscv_build_vector_type (intDI_type_node, V4DImode)
#define RISCV_ATYPE_V2DI riscv_build_vector_type (intDI_type_node, V2DImode)
#define RISCV_ATYPE_V1DI riscv_build_vector_type (intDI_type_node, V1DImode)
#define RISCV_ATYPE_UV16DI riscv_build_vector_type (unsigned_intDI_type_node, V16DImode)
#define RISCV_ATYPE_UV8DI riscv_build_vector_type (unsigned_intDI_type_node, V8DImode)
#define RISCV_ATYPE_UV4DI riscv_build_vector_type (unsigned_intDI_type_node, V4DImode)
#define RISCV_ATYPE_UV2DI riscv_build_vector_type (unsigned_intDI_type_node, V2DImode)
#define RISCV_ATYPE_UV1DI riscv_build_vector_type (unsigned_intDI_type_node, V1DImode)

#define RISCV_ATYPE_V32SI riscv_build_vector_type (intSI_type_node, V32SImode)
#define RISCV_ATYPE_V16SI riscv_build_vector_type (intSI_type_node, V16SImode)
#define RISCV_ATYPE_V8SI riscv_build_vector_type (intSI_type_node, V8SImode)
#define RISCV_ATYPE_V4SI riscv_build_vector_type (intSI_type_node, V4SImode)
#define RISCV_ATYPE_V2SI riscv_build_vector_type (intSI_type_node, V2SImode)
#define RISCV_ATYPE_UV32SI riscv_build_vector_type (unsigned_intSI_type_node, V32SImode)
#define RISCV_ATYPE_UV16SI riscv_build_vector_type (unsigned_intSI_type_node, V16SImode)
#define RISCV_ATYPE_UV8SI riscv_build_vector_type (unsigned_intSI_type_node, V8SImode)
#define RISCV_ATYPE_UV4SI riscv_build_vector_type (unsigned_intSI_type_node, V4SImode)
#define RISCV_ATYPE_UV2SI riscv_build_vector_type (unsigned_intSI_type_node, V2SImode)

#define RISCV_ATYPE_V64HI riscv_build_vector_type (intHI_type_node, V64HImode)
#define RISCV_ATYPE_V32HI riscv_build_vector_type (intHI_type_node, V32HImode)
#define RISCV_ATYPE_V16HI riscv_build_vector_type (intHI_type_node, V16HImode)
#define RISCV_ATYPE_V8HI riscv_build_vector_type (intHI_type_node, V8HImode)
#define RISCV_ATYPE_V4HI riscv_build_vector_type (intHI_type_node, V4HImode)
#define RISCV_ATYPE_V2HI riscv_build_vector_type (intHI_type_node, V2HImode)
#define RISCV_ATYPE_UV64HI riscv_build_vector_type (unsigned_intHI_type_node, V64HImode)
#define RISCV_ATYPE_UV32HI riscv_build_vector_type (unsigned_intHI_type_node, V32HImode)
#define RISCV_ATYPE_UV16HI riscv_build_vector_type (unsigned_intHI_type_node, V16HImode)
#define RISCV_ATYPE_UV8HI riscv_build_vector_type (unsigned_intHI_type_node, V8HImode)
#define RISCV_ATYPE_UV4HI riscv_build_vector_type (unsigned_intHI_type_node, V4HImode)
#define RISCV_ATYPE_UV2HI riscv_build_vector_type (unsigned_intHI_type_node, V2HImode)

#define RISCV_ATYPE_V128QI riscv_build_vector_type (intQI_type_node, V128QImode)
#define RISCV_ATYPE_V64QI riscv_build_vector_type (intQI_type_node, V64QImode)
#define RISCV_ATYPE_V32QI riscv_build_vector_type (intQI_type_node, V32QImode)
#define RISCV_ATYPE_V16QI riscv_build_vector_type (intQI_type_node, V16QImode)
#define RISCV_ATYPE_V8QI riscv_build_vector_type (intQI_type_node, V8QImode)
#define RISCV_ATYPE_V4QI riscv_build_vector_type (intQI_type_node, V4QImode)
#define RISCV_ATYPE_UV128QI riscv_build_vector_type (unsigned_intQI_type_node, V128QImode)
#define RISCV_ATYPE_UV64QI riscv_build_vector_type (unsigned_intQI_type_node, V64QImode)
#define RISCV_ATYPE_UV32QI riscv_build_vector_type (unsigned_intQI_type_node, V32QImode)
#define RISCV_ATYPE_UV16QI riscv_build_vector_type (unsigned_intQI_type_node, V16QImode)
#define RISCV_ATYPE_UV8QI riscv_build_vector_type (unsigned_intQI_type_node, V8QImode)
#define RISCV_ATYPE_UV4QI riscv_build_vector_type (unsigned_intQI_type_node, V4QImode)

#define RISCV_ATYPE_V8TF riscv_build_vector_type (float128_type_node, V8TFmode)
#define RISCV_ATYPE_V4TF riscv_build_vector_type (float128_type_node, V4TFmode)
#define RISCV_ATYPE_V2TF riscv_build_vector_type (float128_type_node, V2TFmode)
#define RISCV_ATYPE_V1TF riscv_build_vector_type (float128_type_node, V1TFmode)

#define RISCV_ATYPE_V16DF riscv_build_vector_type (double_type_node, V16DFmode)
#define RISCV_ATYPE_V8DF riscv_build_vector_type (double_type_node, V8DFmode)
#define RISCV_ATYPE_V4DF riscv_build_vector_type (double_type_node, V4DFmode)
#define RISCV_ATYPE_V2DF riscv_build_vector_type (double_type_node, V2DFmode)
#define RISCV_ATYPE_V1DF riscv_build_vector_type (double_type_node, V1DFmode)

#define RISCV_ATYPE_V32SF riscv_build_vector_type (float_type_node, V32SFmode)
#define RISCV_ATYPE_V16SF riscv_build_vector_type (float_type_node, V16SFmode)
#define RISCV_ATYPE_V8SF riscv_build_vector_type (float_type_node, V8SFmode)
#define RISCV_ATYPE_V4SF riscv_build_vector_type (float_type_node, V4SFmode)
#define RISCV_ATYPE_V2SF riscv_build_vector_type (float_type_node, V2SFmode)
#define RISCV_ATYPE_V1SF riscv_build_vector_type (float_type_node, V1SFmode)

#define RISCV_ATYPE_V64HF riscv_build_vector_type (riscv_fp16_type_node, V64HFmode)
#define RISCV_ATYPE_V32HF riscv_build_vector_type (riscv_fp16_type_node, V32HFmode)
#define RISCV_ATYPE_V16HF riscv_build_vector_type (riscv_fp16_type_node, V16HFmode)
#define RISCV_ATYPE_V8HF riscv_build_vector_type (riscv_fp16_type_node, V8HFmode)
#define RISCV_ATYPE_V4HF riscv_build_vector_type (riscv_fp16_type_node, V4HFmode)
#define RISCV_ATYPE_V1HF riscv_build_vector_type (riscv_fp16_type_node, V1HFmode)

#include "config/riscv/riscv-builtins-v-a.def"

/* Pointer Argument types. */
#define RISCV_ATYPE_DIPTR build_pointer_type (intDI_type_node)
#define RISCV_ATYPE_QIPTR build_pointer_type (intQI_type_node)
#define RISCV_ATYPE_HIPTR build_pointer_type (intHI_type_node)
#define RISCV_ATYPE_SIPTR build_pointer_type (intSI_type_node)

#define RISCV_ATYPE_UDIPTR build_pointer_type (unsigned_intDI_type_node)
#define RISCV_ATYPE_UQIPTR build_pointer_type (unsigned_intQI_type_node)
#define RISCV_ATYPE_UHIPTR build_pointer_type (unsigned_intHI_type_node)
#define RISCV_ATYPE_USIPTR build_pointer_type (unsigned_intSI_type_node)

#define RISCV_ATYPE_DFPTR build_pointer_type (double_type_node)
#define RISCV_ATYPE_SFPTR build_pointer_type (float_type_node)
#define RISCV_ATYPE_HFPTR build_pointer_type (riscv_fp16_type_node)
