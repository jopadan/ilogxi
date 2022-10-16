
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#if defined __i386__ || __x86_64__
#include <x86intrin.h>
#endif

extern inline int32_t bit_width_i32(int32_t i)
{
	#if defined(__GNUC__) || __has_builtin(__builtin_clz)
		return (INT32_WIDTH - __builtin_clz(i));
	#else
		#error "__builtin_clz instruction not supported!"
	#endif
}

extern inline int64_t bit_width_i64(int64_t i)
{
	#if __WORDSIZE == 64
		#if defined(__GNUC__) || __has_builtin(__builtin_clzl)
			return (INT64_WIDTH - __builtin_clzl(i));
		#else
			#error "__builtin_clzl instruction not supported!"
		#endif
	#else
		#if defined(__GNUC__) || __has_builtin(__builtin_clzll)
			return (INT64_WIDTH - __builtin_clzll(i));
		#else
			#error "__builtin_clzll instruction not supported!"
		#endif
	#endif
}

extern inline uint16_t bit_width_u16(uint16_t i)
{
	#if defined(__GNUC__) || __LZCNT__ || __has_builtin(__builtin_ia32_lzcnt_u16)
		return (UINT16_WIDTH - __builtin_ia32_lzcnt_u16(i));
	#else
		#error "__builtin_ia32_lzcnt_u16 instruction not supported!"
	#endif
}

extern inline uint32_t bit_width_u32(uint32_t i)
{
	#if defined(__GNUC__) || __LZCNT__ || __has_builtin(__builtin_ia32_lzcnt_u64)
		return (UINT32_WIDTH - __builtin_ia32_lzcnt_u32(i));
	#else
		#error "__builtin_ia32_lzcnt_u32 instruction not supported!"
	#endif
}

extern inline uint64_t bit_width_u64(uint64_t i)
{
	#if __WORDSIZE == 64
		#if defined(__GNUC__) || __LZCNT__ || __has_builtin(__builtin_ia32_lzcnt_u64)
			return (UINT64_WIDTH - __builtin_ia32_lzcnt_u64(i));
		#else
			#error "__builtin_ia32_lzcnt_u64 instruction not supported!"
		#endif
	#else
	#endif
}

extern inline intmax_t bit_width_imax(intmax_t i)
{
#if defined(__GNU__C) || __has_builtin(__builtin_clz)
	#if __WORDSIZE == 64
		return(INTMAX_WIDTH - __builtin_clzl(i));
	#elif __WORDSIZE == 32
		return(INTMAX_WIDTH - __builtin_clzll(i));
	#else
		#error "unsupported wordsize!"
	#endif
#else
	#error "__builtin_clz instruction not supported!"
#endif
}

extern inline uintmax_t bit_width_umax(uintmax_t u)
{
#if defined(__GNU__C) || __has_builtin(__builtin_clz)
	#if __WORDSIZE == 64
		return(UINTMAX_WIDTH- __builtin_clzl(u));
	#elif __WORDSIZE == 32
		return(UINTMAX_WIDTH - __builtin_clzll(u));
	#else
		#error "unsupported wordsize!"
	#endif
#else
	#error "__builtin_clz instruction not supported!"
#endif
}

#ifdef __cplusplus
}
#endif
