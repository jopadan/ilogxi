#pragma once

#ifdef __cplusplus
#include <bit>
#include <limits>
#include <cassert>
#include <cstdint>

template<typename _Tp,
         typename _Up = typename std::enable_if<std::is_signed<_Tp>::value,
                      typename std::make_unsigned<_Tp>::type>::type>
_Up ilogx(_Up i, _Up base)
{
	return ((std::bit_width(i) - 1) / (std::bit_width(base) - 1));
}

extern "C" {
#else
#include <assert.h>
#include <stdint.h>
#endif

#include "bitwidth.h"

extern inline int32_t ilogxid(int32_t i, int32_t base)
{
	assert(base > 1 && base < INT32_WIDTH);
	return ((bit_width_i32(i) - 1) / (bit_width_i32(base) - 1));
}

extern inline int64_t ilogxiq(int64_t i, int64_t base)
{
	assert(base > 1 && base < INT64_WIDTH);
	return ((bit_width_i64(i) - 1) / (bit_width_i64(base) - 1));
}

extern inline uint32_t ilogxud(uint32_t u, uint32_t base)
{
	assert(base > 1 && base < UINT32_WIDTH);
	return ((bit_width_i32(u) - 1) / (bit_width_i32(base) - 1));
}

extern inline uint64_t ilogxuq(uint64_t u, uint64_t base)
{
	assert(base > 1 && base < UINT64_WIDTH);
	return ((bit_width_u64(u) - 1) / (bit_width_u64(base) - 1));
}

extern inline intmax_t ilogximax(intmax_t i, intmax_t base)
{
	assert(base > 1 && base < INTMAX_WIDTH);
	return ((bit_width_imax(i) - 1) / (bit_width_imax(base) - 1));
}

extern inline uintmax_t ilogxumax(uintmax_t u, uintmax_t base)
{
	assert(base > 1 && base < UINTMAX_WIDTH);
	return ((bit_width_umax(u) - 1) / (bit_width_umax(base) - 1));
}

#ifdef __cplusplus
}
#endif
