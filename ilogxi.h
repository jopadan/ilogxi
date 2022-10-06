#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "bitwidth.h"

#include <assert.h>

extern inline int32_t ilogxid(int32_t i, int32_t base)
{
	assert(base > 1 && base < 32);
	return (bit_width_i32(i) / bit_width_i32(base));
}

extern inline int64_t ilogxiq(int64_t i, int64_t base)
{
	assert(base > 1 && base < 64);
	return (bit_width_i64(i) / bit_width_i64(base));
}

extern inline uint32_t ilogxud(uint32_t u, uint32_t base)
{
	assert(base > 1 && base < 32);
	return (bit_width_i32(u) / bit_width_i32(base));
}

extern inline uint64_t ilogxuq(uint64_t u, uint64_t base)
{
	assert(base > 1 && base < 64);
	return (bit_width_u64(u) / bit_width_u64(base));
}

#ifdef __cplusplus
}
#endif
