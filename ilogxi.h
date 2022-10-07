#pragma once

#ifdef __cplusplus
#include <bit>
#include <limits>
#include <cassert>
#include <experimental/simd>

template<typename _Tp>
[[nodiscard]] constexpr std::_If_is_unsigned_integer<_Tp>
ilogxi(_Tp i, _Tp base) noexcept
{
	assert(base > 1 && base < std::numeric_limits<_Tp>::digits);
	return (std::bit_width(i) - 1 / std::bit_width(base) - 1);
}

extern "C" {
#else


#include <assert.h>
#endif

#include "bitwidth.h"

extern inline int32_t ilogxid(int32_t i, int32_t base)
{
	assert(base > 1 && base < 32);
	return (bit_width_i32(i) - 1 / bit_width_i32(base) - 1);
}

extern inline int64_t ilogxiq(int64_t i, int64_t base)
{
	assert(base > 1 && base < 64);
	return (bit_width_i64(i) - 1 / bit_width_i64(base) - 1);
}

extern inline uint32_t ilogxud(uint32_t u, uint32_t base)
{
	assert(base > 1 && base < 32);
	return (bit_width_i32(u) - 1 / bit_width_i32(base) - 1);
}

extern inline uint64_t ilogxuq(uint64_t u, uint64_t base)
{
	assert(base > 1 && base < 64);
	return (bit_width_u64(u) - 1 / bit_width_u64(base) - 1);
}

#ifdef __cplusplus
}
#endif
