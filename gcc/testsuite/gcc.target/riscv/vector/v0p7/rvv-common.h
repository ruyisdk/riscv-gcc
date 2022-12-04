
#define RVV_INT8_TEST_ARG(MACRO, ...)		\
  MACRO( int8_t, int, i,  8m1,  8, x, 8, __VA_ARGS__)	\
  MACRO( int8_t, int, i,  8m2,  4, x, 8, __VA_ARGS__)	\
  MACRO( int8_t, int, i,  8m4,  2, x, 8, __VA_ARGS__)	\
  MACRO( int8_t, int, i,  8m8,  1, x, 8, __VA_ARGS__)	\
  MACRO(int16_t, int, i, 16m1, 16, x, 16, __VA_ARGS__)	\
  MACRO(int16_t, int, i, 16m2,  8, x, 16, __VA_ARGS__)	\
  MACRO(int16_t, int, i, 16m4,  4, x, 16, __VA_ARGS__)	\
  MACRO(int16_t, int, i, 16m8,  2, x, 16, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m1, 32, x, 32, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m2, 16, x, 32, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m4,  8, x, 32, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m8,  4, x, 32, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m1, 64, x, 64, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m2, 32, x, 64, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m4, 16, x, 64, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m8,  8, x, 64, __VA_ARGS__)

#define RVV_UINT8_TEST_ARG(MACRO, ...)		\
  MACRO( uint8_t, uint, u,  8m1,  8, x,  8, __VA_ARGS__)	\
  MACRO( uint8_t, uint, u,  8m2,  4, x,  8, __VA_ARGS__)	\
  MACRO( uint8_t, uint, u,  8m4,  2, x,  8, __VA_ARGS__)	\
  MACRO( uint8_t, uint, u,  8m8,  1, x,  8, __VA_ARGS__)	\
  MACRO(uint16_t, uint, u, 16m1, 16, x, 16, __VA_ARGS__)	\
  MACRO(uint16_t, uint, u, 16m2,  8, x, 16, __VA_ARGS__)	\
  MACRO(uint16_t, uint, u, 16m4,  4, x, 16, __VA_ARGS__)	\
  MACRO(uint16_t, uint, u, 16m8,  2, x, 16, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m1, 32, x, 32, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m2, 16, x, 32, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m4,  8, x, 32, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m8,  4, x, 32, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m1, 64, x, 64, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m2, 32, x, 64, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m4, 16, x, 64, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m8,  8, x, 64, __VA_ARGS__)

#define RVV_INT16_TEST_ARG(MACRO, ...)		\
  MACRO(int16_t, int, i, 16m1, 16, x, 16, __VA_ARGS__)	\
  MACRO(int16_t, int, i, 16m2,  8, x, 16, __VA_ARGS__)	\
  MACRO(int16_t, int, i, 16m4,  4, x, 16, __VA_ARGS__)	\
  MACRO(int16_t, int, i, 16m8,  2, x, 16, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m1, 32, x, 32, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m2, 16, x, 32, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m4,  8, x, 32, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m8,  4, x, 32, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m1, 64, x, 64, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m2, 32, x, 64, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m4, 16, x, 64, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m8,  8, x, 64, __VA_ARGS__)

#define RVV_UINT16_TEST_ARG(MACRO, ...)		\
  MACRO(uint16_t, uint, u, 16m1, 16, x, 16, __VA_ARGS__)	\
  MACRO(uint16_t, uint, u, 16m2,  8, x, 16, __VA_ARGS__)	\
  MACRO(uint16_t, uint, u, 16m4,  4, x, 16, __VA_ARGS__)	\
  MACRO(uint16_t, uint, u, 16m8,  2, x, 16, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m1, 32, x, 32, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m2, 16, x, 32, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m4,  8, x, 32, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m8,  4, x, 32, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m1, 64, x, 64, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m2, 32, x, 64, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m4, 16, x, 64, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m8,  8, x, 64, __VA_ARGS__)

#define RVV_INT32_TEST_ARG(MACRO, ...)		\
  MACRO(int32_t, int, i, 32m1, 32, x, 32, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m2, 16, x, 32, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m4,  8, x, 32, __VA_ARGS__)	\
  MACRO(int32_t, int, i, 32m8,  4, x, 32, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m1, 64, x, 64, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m2, 32, x, 64, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m4, 16, x, 64, __VA_ARGS__)	\
  MACRO(int64_t, int, i, 64m8,  8, x, 64, __VA_ARGS__)

#define RVV_UINT32_TEST_ARG(MACRO, ...)		\
  MACRO(uint32_t, uint, u, 32m1, 32, x, 32, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m2, 16, x, 32, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m4,  8, x, 32, __VA_ARGS__)	\
  MACRO(uint32_t, uint, u, 32m8,  4, x, 32, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m1, 64, x, 64, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m2, 32, x, 64, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m4, 16, x, 64, __VA_ARGS__)	\
  MACRO(uint64_t, uint, u, 64m8,  8, x, 64, __VA_ARGS__)
