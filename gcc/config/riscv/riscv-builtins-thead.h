
/* Macros to create an enumeration identifier for a function prototype.  */
#define RISCV_FTYPE_NAME2(A, B, C) RISCV_##A##_FTYPE_##B##_##C
#define RISCV_FTYPE_NAME3(A, B, C, D) RISCV_##A##_FTYPE_##B##_##C##_##D
#define RISCV_FTYPE_NAME4(A, B, C, D, E) RISCV_##A##_FTYPE_##B##_##C##_##D##_##E
#define RISCV_FTYPE_NAME5(A, B, C, D, E, F) RISCV_##A##_FTYPE_##B##_##C##_##D##_##E##_##F
#define RISCV_FTYPE_NAME6(A, B, C, D, E, F, G) RISCV_##A##_FTYPE_##B##_##C##_##D##_##E##_##F##_##G

/* RISCV_FTYPE_ATYPESN takes N RISCV_FTYPES-like type codes and lists
   their associated RISCV_ATYPEs.  */
#define RISCV_FTYPE_ATYPES2(A, B, C) \
  RISCV_ATYPE_##A, RISCV_FTYPE_ATYPES1(B, C)
#define RISCV_FTYPE_ATYPES3(A, B, C, D) \
  RISCV_ATYPE_##A, RISCV_FTYPE_ATYPES2(B, C, D)
#define RISCV_FTYPE_ATYPES4(A, B, C, D, E) \
  RISCV_ATYPE_##A, RISCV_FTYPE_ATYPES3(B, C, D, E)
#define RISCV_FTYPE_ATYPES5(A, B, C, D, E, F) \
  RISCV_ATYPE_##A, RISCV_FTYPE_ATYPES4(B, C, D, E, F)
#define RISCV_FTYPE_ATYPES6(A, B, C, D, E, F, G) \
  RISCV_ATYPE_##A, RISCV_FTYPE_ATYPES5(B, C, D, E, F, G)
