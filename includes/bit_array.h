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

typedef struct bit_array bit_array;
typedef struct bit_array_float {

  bit_array *int_part;
  bit_array *dec_part;
  char sgn;

}bit_array_float;

BIT_ARRAY_API bit_array *InitializeBitArray(uint64_t size);
BIT_ARRAY_API bit_array* InitializeBitArrayFromUInt64(uint64_t val);
BIT_ARRAY_API void FreeBitArray(void *bav);
BIT_ARRAY_API void SetBit(bit_array *ba, uint64_t pos);
BIT_ARRAY_API void ClearBit(bit_array *ba, uint64_t pos);
BIT_ARRAY_API uint64_t GetBit(bit_array *ba, uint64_t pos);
BIT_ARRAY_API void SetAllBits(bit_array *ba);
BIT_ARRAY_API void SetAllBitsSieve(bit_array* ba);
BIT_ARRAY_API void SetBitsFromInt64(bit_array *ba, uint64_t pos, uint64_t num);
BIT_ARRAY_API uint32_t GetInt32(bit_array *ba, uint64_t pos);
BIT_ARRAY_API uint64_t GetInt64(bit_array *ba, uint64_t pos);
BIT_ARRAY_API uint64_t GetInt64BitPos(bit_array* ba, uint64_t pos);
BIT_ARRAY_API unsigned char ReverseByteBits(unsigned char b);
BIT_ARRAY_API uint32_t ReverseUInt32Bits(uint32_t b);
BIT_ARRAY_API uint64_t ReverseUInt64Bits(uint64_t b);
BIT_ARRAY_API void SetBitsFromChar(bit_array *ba, uint64_t pos, char c);
BIT_ARRAY_API void SetBitsFromCharBitPos(bit_array* ba, uint64_t pos, char c);
BIT_ARRAY_API void ClearAllBits(bit_array *ba);
BIT_ARRAY_API void ShiftBitsLeft(bit_array* ba, uint64_t n);
BIT_ARRAY_API void ShiftBitsLeftAndResize(bit_array* ba, uint64_t n);
BIT_ARRAY_API void ShiftBitsRight(bit_array* ba, uint64_t n);
BIT_ARRAY_API uint64_t AddBits(uint64_t x, uint64_t y, uint64_t *carry);
BIT_ARRAY_API uint64_t SubtractBits(uint64_t x, uint64_t y, uint64_t* borrow);
BIT_ARRAY_API bit_array* AddBitArrays(bit_array* ba1, bit_array* ba2);
BIT_ARRAY_API char TestUnitBitArray(bit_array* ba);
BIT_ARRAY_API bit_array* SubtractBitArrays(bit_array* ba1, bit_array* ba2, char * sign);
BIT_ARRAY_API bit_array* BitStringToBitArray(char* bitstring);
BIT_ARRAY_API bit_array* AndBitArrays(bit_array* ba1, bit_array* ba2);
BIT_ARRAY_API bit_array* OrBitArrays(bit_array* ba1, bit_array* ba2);
BIT_ARRAY_API bit_array* XorBitArrays(bit_array* ba1, bit_array* ba2);
BIT_ARRAY_API void NegateBitArray(bit_array* ba1);
BIT_ARRAY_API char TestZeroBitArray(bit_array* ba);
BIT_ARRAY_API uint64_t DivideUInt64By10(uint64_t n);
BIT_ARRAY_API bit_array* IntDivideBitArrayBy10(bit_array* ba1);
BIT_ARRAY_API bit_array* DivideBitArrayBy10(bit_array* ba, uint8_t* remainder);
BIT_ARRAY_API bit_array* DivideBitArrayByPowerOf10(bit_array* ba, uint64_t pow10);
BIT_ARRAY_API bit_array* MultiplyBitArrayBy10(bit_array* ba, uint8_t* int_part);
BIT_ARRAY_API char* BitArrayToBase10DecimalString(bit_array* ba);
BIT_ARRAY_API char* BitArrayToBase10IntegerStringRecursive(bit_array* ba);
BIT_ARRAY_API bit_array** GetPowerOf10BitArrays(uint64_t powmax);
BIT_ARRAY_API char* BitArrayToBase10IntegerString(bit_array* ba);
BIT_ARRAY_API char* DivideBy2(char* dec);
BIT_ARRAY_API char* MultiplyBy2(char* dec);
BIT_ARRAY_API bit_array* Base10IntegerStringToBitArray(char* dec);
BIT_ARRAY_API bit_array* Base10DecimalStringToBitArray(char* dec, uint64_t max_precision);
BIT_ARRAY_API bit_array *ReduceBitArray(bit_array** ba);
BIT_ARRAY_API void CleanBitArray(bit_array* ba);
BIT_ARRAY_API bit_array* CopyBitArray(bit_array* x);
BIT_ARRAY_API char TestEqualBitArrays(bit_array* ba1, bit_array* ba2);
BIT_ARRAY_API bit_array* MultiplyBitArrays(bit_array* x, bit_array* y);
BIT_ARRAY_API bit_array* InvertBitArray(bit_array* ba, uint64_t precision, uint64_t* kshift);
BIT_ARRAY_API uint64_t TrimLowerZeroBits(bit_array* ba);
BIT_ARRAY_API bit_array* ConcatenateBitArrays(bit_array* ba1, bit_array* ba2);
BIT_ARRAY_API void FreeBitArrayFloat(void* bafv);
BIT_ARRAY_API bit_array_float* InitializeBitArrayFloatFromBitArrays(bit_array* intg, bit_array* dec, char sgn);
BIT_ARRAY_API bit_array_float *DivideBitArrays(bit_array* ba1, bit_array* ba2, uint64_t precision);
BIT_ARRAY_API bit_array* LowerBits(bit_array* ba, uint64_t nbits);
BIT_ARRAY_API bit_array_float* AddBitArrayFloats(bit_array_float* baf1, bit_array_float* baf2);
BIT_ARRAY_API bit_array_float* SubtractBitArrayFloats(bit_array_float* baf1, bit_array_float* baf2);
BIT_ARRAY_API bit_array_float* MultiplyBitArrayFloats(bit_array_float* baf1, bit_array_float* baf2);
BIT_ARRAY_API void AddLeadingZeroBits(bit_array* ba, uint64_t nzeros);
BIT_ARRAY_API void AddTrailingZeroBits(bit_array* ba, uint64_t nzeros);
BIT_ARRAY_API uint64_t CountLeadingZeroBits(uint64_t x);
BIT_ARRAY_API uint64_t GetLeadingZeroBits(bit_array* ba);
BIT_ARRAY_API bit_array_float* DivideBitArrayFloats(bit_array_float* baf1, bit_array_float* baf2, uint64_t precision);
BIT_ARRAY_API bit_array* HigherBits(bit_array* ba, uint64_t nbits);
BIT_ARRAY_API uint64_t KaratsubaMultiply(uint64_t x, uint64_t y);
BIT_ARRAY_API uint64_t KaratsubaGetLength(uint64_t value);
BIT_ARRAY_API bit_array* BitArrayFactorial(bit_array* ba);
BIT_ARRAY_API bit_array* ExponentiateBitArrays(bit_array* ba1, bit_array* ba2);
BIT_ARRAY_API bit_array* BitArrayFromByteArray(unsigned char* bya, uint64_t nbytes);

extern size_t max_size_t;
extern uint64_t one_bit_array64_h;
extern uint32_t one_bit_array32_h;


#endif // BIT_ARRAY_H
