#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#ifndef BIGNUM_H
#define BIGNUM_H

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
#include <bit_array.h>
#include <memfile.h>

#if defined(_WIN32) || defined(_WIN64)
#define BIGNUM_EXPORTS 1
#ifdef BIGNUM_EXPORTS
#define BIGNUM_API __declspec(dllexport)
#else
#define BIGNUM_API __declspec(dllimport)
#endif
#else
#define BIGNUM_API
#endif

#define IEEE754_SIGNIFICAND_BITS 52
#define IEEE754_EXPONENT_BITS 11

typedef struct bit_array_float{
  bit_array *int_part;
  bit_array *dec_part;
  char sgn;
}bit_array_float;


BIGNUM_API void ShiftBitsLeft(bit_array *ba,uint64_t n);
BIGNUM_API void ShiftBitsLeftAndResize(bit_array *ba,uint64_t n);
BIGNUM_API void ShiftBitsLeftAndResizeWithLeadingZeros(bit_array *ba,uint64_t n);
BIGNUM_API void ShiftBitsRight(bit_array *ba,uint64_t n);
BIGNUM_API uint64_t AddBits(uint64_t x,uint64_t y,uint64_t *carry);
BIGNUM_API uint64_t SubtractBits(uint64_t x,uint64_t y,uint64_t *borrow);
BIGNUM_API bit_array *AddBitArrays(bit_array *ba1,bit_array *ba2);
BIGNUM_API char TestUnitBitArray(bit_array *ba);
BIGNUM_API bit_array *SubtractBitArrays(bit_array *ba1,bit_array *ba2,char *sign);
BIGNUM_API bit_array *SubtractBitArraysNoReduce(bit_array *ba1,bit_array *ba2,char *sign);
BIGNUM_API bit_array *BitStringToBitArray(char *bitstring);
BIGNUM_API bit_array *AndBitArrays(bit_array *ba1,bit_array *ba2);
BIGNUM_API bit_array *OrBitArrays(bit_array *ba1,bit_array *ba2);
BIGNUM_API bit_array *XorBitArrays(bit_array *ba1,bit_array *ba2);
BIGNUM_API void NegateBitArray(bit_array *ba1);
BIGNUM_API char TestZeroBitArray(bit_array *ba);
BIGNUM_API bit_array *IntDivideBitArrayBy10(bit_array *ba1);
BIGNUM_API bit_array *DivideBitArrayBy10(bit_array *ba,uint8_t *remainder);
BIGNUM_API bit_array *DivideBitArrayByPowerOf10(bit_array *ba,uint64_t pow10);
BIGNUM_API bit_array *MultiplyBitArrayBy10(bit_array *ba,uint8_t *int_part);
BIGNUM_API char *BitArrayToDecimalFractionalString(bit_array *ba, uint64_t ndecimals);
BIGNUM_API bit_array **GetPowerOf10BitArrays(uint64_t powmax);
BIGNUM_API char *BitArrayToHexadecimalIntegerString(bit_array *ba);
BIGNUM_API char *BitArrayToHexadecimalFractionalString(bit_array *ba);
BIGNUM_API bit_array *HexadecimalIntegerStringToBitArray(char *hex_str);
BIGNUM_API bit_array *HexadecimalFractionalStringToBitArray(char *hex_str);
BIGNUM_API char *BitArrayToDecimalIntegerString(bit_array *ba);
BIGNUM_API char *DivideBy2(char *dec);
BIGNUM_API char *MultiplyBy2(char *dec);
BIGNUM_API bit_array *DecimalIntegerStringToBitArray(char *dec);
BIGNUM_API bit_array_float *InitializeBitArrayFloatFromHexadecimal(char *floatval);
BIGNUM_API bit_array_float *InitializeBitArrayFloatFromDecimal(char *floatval,uint64_t precision);
BIGNUM_API bit_array *DecimalFractionalStringToBitArray(char *dec,uint64_t max_precision);
BIGNUM_API bit_array *ReduceBitArray(bit_array **ba);
BIGNUM_API void CleanBitArray(bit_array *ba);
BIGNUM_API bit_array *CopyBitArray(bit_array *x);
BIGNUM_API void *CopyBitArrayFloat(void *valba);
BIGNUM_API char TestEqualBitArrays(bit_array *ba1,bit_array *ba2);
BIGNUM_API bit_array *MultiplyBitArrays(bit_array *x,bit_array *y);
BIGNUM_API bit_array *InvertBitArray(bit_array *ba,uint64_t precision,uint64_t *kshift);
BIGNUM_API uint64_t TrimLowerZeroBits(bit_array *ba);
BIGNUM_API bit_array *ConcatenateBitArrays(bit_array *ba1,bit_array *ba2);
BIGNUM_API void FreeBitArrayFloat(void *bafv);
BIGNUM_API bit_array_float *InitializeBitArrayFloatFromBitArrays(bit_array *intg,bit_array *dec,char sgn);
BIGNUM_API bit_array_float *DivideBitArrays(bit_array *ba1,bit_array *ba2,uint64_t precision);
BIGNUM_API bit_array *FloorDivideBitArrays(bit_array *ba1,bit_array *ba2);
BIGNUM_API bit_array *LowerBits(bit_array *ba,uint64_t nbits);
BIGNUM_API bit_array_float *AddBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2);
BIGNUM_API bit_array_float *SubtractBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2);
BIGNUM_API bit_array_float *MultiplyBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2);
BIGNUM_API void AddLeadingZeroBits(bit_array *ba,uint64_t nzeros);
BIGNUM_API void AddTrailingZeroBits(bit_array *ba,uint64_t nzeros);
BIGNUM_API uint64_t CountLeadingZeroBits(uint64_t x);
BIGNUM_API uint64_t GetLeadingZeroBits(bit_array *ba);
BIGNUM_API bit_array_float *DivideBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2,uint64_t precision);
BIGNUM_API bit_array_float *ExponentiateBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2,uint64_t precision);
BIGNUM_API bit_array *HigherBits(bit_array *ba,uint64_t nbits);
BIGNUM_API uint64_t KaratsubaMultiply(uint64_t x,uint64_t y);
BIGNUM_API uint64_t KaratsubaGetLength(uint64_t value);
BIGNUM_API bit_array *BitArrayFactorial(bit_array *ba);
BIGNUM_API bit_array *ModBitArrays(bit_array *ba1,bit_array *ba2);
BIGNUM_API bit_array *ExponentiateBitArrays(bit_array *ba1,bit_array *ba2);
BIGNUM_API bit_array *InitializeBitArrayFromByteArray(unsigned char *bya,uint64_t nbytes);
BIGNUM_API char *PrintBitArray(bit_array *);
BIGNUM_API char *PrintBitArray(bit_array *ba);
BIGNUM_API char *BitArrayToDecimalIntegerString(bit_array *ba);
BIGNUM_API void CleanBitArray(bit_array *ba);
BIGNUM_API bit_array *ReduceBitArray(bit_array **ba);
BIGNUM_API char TestZeroBitArray(bit_array *ba);
BIGNUM_API char *BitArrayToDecimalFractionalString(bit_array *ba,uint64_t ndecimals);
BIGNUM_API char* PrintBitArrayFloat(bit_array_float*);
BIGNUM_API char* PrintBitArrayFloatToDecimal(bit_array_float*, int32_t sigdigits);
BIGNUM_API char* PrintBitArrayFloatToHexadecimal(bit_array_float*);
BIGNUM_API bit_array_float *InitializeBitArrayFloatFromDouble(double val);
BIGNUM_API bit_array *InitializeBitArrayFromUInt64(uint64_t val);
BIGNUM_API uint64_t PowMod(uint64_t,uint64_t,uint64_t);
BIGNUM_API void *ReadBitArrayFloat(void *,stream_type);
BIGNUM_API void WriteBitArrayFloat(void *,void *,stream_type);


#endif
