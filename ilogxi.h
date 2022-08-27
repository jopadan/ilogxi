#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

#if defined __i386__ || __x86_64__
#include <x86gprintrin.h>
#endif

#ifndef __LZCNT__
#include "lzcnt.h"
#endif

	inline uint8_t ilogxid(int32_t i, int32_t base)
	{
		assert(base > 1 && base < 32);
			return (UINT32_WIDTH - __lzcnt32(i)) / (UINT32_WIDTH - __lzcnt32(base)));
	}

	inline uint8_t ilogxiq(int64_t i, int64_t base)
	{
		assert(base > 1 && base < 64);
			return ((UINT64_WIDTH - __lzcnt64(i)) / (UINT64_WIDTH - __lzcnt64(base)));
	}

#ifdef __cplusplus
}
#endif
