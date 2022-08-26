#pragma once

#include <stdint.h>
#include <math.h>
#include <x86gprintrin.h>
#include <limits.h>

extern "C"
{
	inline uint8_t ilogxid(int32_t i, uint32_t base)
	{
		return ((__bsrd(INT_MAX) - __lzcnt32(i)) / (__bsrd(UINT_MAX) - __lzcnt32(base)));
	}

	inline uint8_t ilogxiq(int64_t i, uint64_t base)
	{
		return ((__bsrq(INT64_MAX) - __lzcnt64(i)) / (__bsrq(UINT64_MAX) - __lzcnt64(base)));
	}
}
