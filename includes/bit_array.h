#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#ifdef __GNUC__
#include   <dirent.h>
#include   <unistd.h>
#elif defined(_WIN32)
#include   <dirent_win.h>
#elif defined(_WIN64)
#include   <dirent_win.h>
#endif

#include <inttypes.h>
#include <stdint.h>

#if defined(_WIN32) || defined(_WIN64)
#define BIT_ARRAY_EXPORTS 1
#ifdef BIT_ARRAY_EXPORTS
#define BIT_ARRAY_API __declspec(dllexport)
#else
#define BIT_ARRAY_API __declspec(dllimport)
#endif
#else
#define BIT_ARRAY_API
#endif

#define IEEE754_SIGNIFICAND_BITS 52
#define IEEE754_EXPONENT_BITS 11

typedef struct bit_array{

  uint64_t nbits,nblocks;
  uint64_t *array;
}bit_array;

BIT_ARRAY_API bit_array *InitializeBitArray(uint64_t size);
BIT_ARRAY_API void FreeBitArray(void *bav);
BIT_ARRAY_API void SetBit(bit_array *ba,uint64_t pos);
BIT_ARRAY_API void ClearBit(bit_array *ba,uint64_t pos);
BIT_ARRAY_API uint64_t GetBit(bit_array *ba,uint64_t pos);
BIT_ARRAY_API void SetAllBits(bit_array *ba);
BIT_ARRAY_API void SetAllBitsSieve(bit_array *ba);
BIT_ARRAY_API void SetBitsFromUInt64(bit_array *ba,uint64_t pos,uint64_t num);
BIT_ARRAY_API uint32_t GetInt32(bit_array *ba,uint64_t pos);
BIT_ARRAY_API uint64_t GetInt64(bit_array *ba,uint64_t pos);
BIT_ARRAY_API uint64_t GetInt64BitPos(bit_array *ba,uint64_t pos);
BIT_ARRAY_API unsigned char ReverseByteBits(unsigned char b);
BIT_ARRAY_API uint32_t ReverseUInt32Bits(uint32_t b);
BIT_ARRAY_API uint64_t ReverseUInt64Bits(uint64_t b);
BIT_ARRAY_API void SetBitsFromChar(bit_array *ba,uint64_t pos,char c);
BIT_ARRAY_API void SetBitsFromCharBitPos(bit_array *ba,uint64_t pos,char c);
BIT_ARRAY_API void ClearAllBits(bit_array *ba);

extern uint64_t one_bit_array64_h;
extern uint32_t one_bit_array32_h;
extern size_t max_size_t;

#endif // BIT_ARRAY_H
