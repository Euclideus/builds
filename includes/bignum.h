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

#include <chacha20.h>
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

typedef struct bit_array_float {
  bit_array *int_part;
  bit_array *dec_part;
  int8_t sgn;
} bit_array_float;


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

BIGNUM_API bit_array *DivideBitArrayBy10(bit_array *ba,uint8_t *remainder,volatile char *cancel);

BIGNUM_API bit_array *DivideBitArrayByPowerOf10(bit_array *ba,uint64_t pow10,volatile char *cancel);

BIGNUM_API bit_array *MultiplyBitArrayBy10(bit_array *ba,uint8_t *int_part,volatile char *cancel);

BIGNUM_API char *BitArrayToDecimalFractionalString(bit_array *ba,uint64_t ndecimals,volatile char *cancel);

BIGNUM_API bit_array **GetPowerOf10BitArrays(uint64_t powmax,volatile char *cancel);

BIGNUM_API char *BitArrayToHexadecimalIntegerString(bit_array *ba);

BIGNUM_API char *BitArrayToHexadecimalFractionalString(bit_array *ba);

BIGNUM_API bit_array *HexadecimalIntegerStringToBitArray(char *hex_str);

BIGNUM_API bit_array *HexadecimalFractionalStringToBitArray(char *hex_str);

BIGNUM_API char *BitArrayToDecimalIntegerString(bit_array *ba,volatile char *cancel);

BIGNUM_API char *DivideBy2(char *dec,volatile char *cancel);

BIGNUM_API char *MultiplyBy2(char *dec,volatile char *cancel);

BIGNUM_API bit_array *DecimalIntegerStringToBitArray(char *dec,volatile char *cancel);

BIGNUM_API bit_array_float *InitializeBitArrayFloatFromHexadecimal(char *floatval);

BIGNUM_API bit_array_float *InitializeBitArrayFloatFromDecimal(char *floatval,uint64_t precision,volatile char *cancel);

BIGNUM_API bit_array *DecimalFractionalStringToBitArray(char *dec,uint64_t max_precision,volatile char *cancel);

BIGNUM_API bit_array *ReduceBitArray(bit_array **ba);

BIGNUM_API void *CopyBitArrayFloat(void *valba);

BIGNUM_API char TestEqualBitArrays(bit_array *ba1,bit_array *ba2);

BIGNUM_API char CompareBitArrays(bit_array *ba1,bit_array *ba2);

BIGNUM_API bit_array *MultiplyBitArrays(bit_array *x,bit_array *y,volatile char *cancel);

BIGNUM_API bit_array *InvertBitArray(bit_array *ba,uint64_t precision,uint64_t *kshift,volatile char *cancel);

BIGNUM_API bit_array *
InvertSquareRootBitArray(bit_array *ba1,uint64_t precision,uint64_t *kshift,volatile char *cancel);

BIGNUM_API uint64_t TrimLowerZeroBits(bit_array *ba);

BIGNUM_API bit_array *CropBitArray(bit_array *ba,uint64_t i1,uint64_t i2);

BIGNUM_API bit_array *ConcatenateBitArrays(bit_array *ba1,bit_array *ba2);

BIGNUM_API void FreeBitArrayFloat(void *bafv);

BIGNUM_API bit_array_float *InitializeBitArrayFloatFromBitArrays(bit_array *intg,bit_array *dec,char sgn);

BIGNUM_API bit_array_float *DivideBitArrays(bit_array *ba1,bit_array *ba2,uint64_t precision,volatile char *cancel);

BIGNUM_API bit_array_float *SquareRootBitArray(bit_array *ba2,uint64_t precision,volatile char *cancel);

BIGNUM_API bit_array *FloorDivideBitArrays(bit_array *ba1,bit_array *ba2,volatile char *cancel);

BIGNUM_API bit_array *LowerBits(bit_array *ba,uint64_t nbits);

BIGNUM_API bit_array_float *AddBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2);

BIGNUM_API bit_array_float *SubtractBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2);

BIGNUM_API bit_array_float *MultiplyBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2,volatile char *cancel);

BIGNUM_API bit_array_float *ShiftLeftBitArrayFloat(bit_array_float *baf1,uint64_t n);

BIGNUM_API bit_array_float *ShiftRightBitArrayFloat(bit_array_float *baf1,uint64_t n);

BIGNUM_API bit_array *ReverseBitArray(bit_array *ba);

BIGNUM_API void AddLeadingZeroBits(bit_array *ba,uint64_t nzeros);

BIGNUM_API void AddTrailingZeroBits(bit_array *ba,uint64_t nzeros);

BIGNUM_API void RemoveTrailingZeroBits(bit_array *ba);

BIGNUM_API uint64_t CountLeadingZeroBits(uint64_t x);

BIGNUM_API uint64_t GetLeadingZeroBits(bit_array *ba);

BIGNUM_API bit_array_float *DivideBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2,uint64_t precision,
                                                 volatile char *cancel);

BIGNUM_API char CompareBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2);

BIGNUM_API bit_array_float *SquareRootBitArrayFloat(bit_array_float *baf1,uint64_t precision,volatile char *cancel);

BIGNUM_API bit_array_float *ExponentiateBitArrayFloats(bit_array_float *baf1,bit_array_float *baf2,uint64_t precision,
                                                       volatile char *cancel);

BIGNUM_API bit_array *HigherBits(bit_array *ba,uint64_t nbits);

BIGNUM_API uint64_t KaratsubaMultiply(uint64_t x,uint64_t y);

BIGNUM_API uint64_t KaratsubaGetLength(uint64_t value);

BIGNUM_API bit_array *BitArrayFactorial(bit_array *ba,volatile char *cancel);

BIGNUM_API bit_array *BitArrayFactorialBinarySplitting(bit_array *ba,volatile char *cancel);

BIGNUM_API bit_array *RandomBitArray(bit_array *n1,bit_array *n2,cha_cha_20_state *seed);

BIGNUM_API void RandomizeBitArray(bit_array *ba,cha_cha_20_state *ccstate);

BIGNUM_API char MillerRabinPrimeTest(bit_array *n,int32_t k,cha_cha_20_state *seed,volatile char *cancel);

BIGNUM_API void GetPrimePair(bit_array **prime1,bit_array **prime2,uint64_t nbits,int32_t mr_its,cha_cha_20_state *seed,
                             char *abort);

BIGNUM_API bit_array *ModInverseBinaryExtendedEuclidean(bit_array *a,bit_array *m);

BIGNUM_API bit_array *MontgomeryReduce(bit_array *t,bit_array *n,bit_array *nprime,volatile char *cancel);

BIGNUM_API bit_array *MontgomeryMultiply(bit_array *a,bit_array *b,bit_array *n,bit_array *nprime,
                                         volatile char *cancel);

BIGNUM_API bit_array *MontgomeryNPrime(bit_array *n,volatile char *cancel);

BIGNUM_API bit_array *MontgomeryRSquared(bit_array *mod,volatile char *cancel);

BIGNUM_API bit_array *MontgomeryPowMod(bit_array *base,bit_array *exponent,bit_array *mod,bit_array *nprime,
                                       bit_array *r2mod,volatile char *cancel);

BIGNUM_API void FactorialPartialProductSub(bit_array *a,bit_array *b,bit_array **p,volatile char *cancel);

BIGNUM_API bit_array *ModBitArrays(bit_array *ba1,bit_array *ba2,volatile char *cancel);

BIGNUM_API bit_array_float *ModBitArrayFloats(bit_array_float *ba1,bit_array_float *ba2,volatile char *cancel);

BIGNUM_API bit_array *GCDBitArrays(bit_array *ba1,bit_array *ba2,volatile char *cancel);

BIGNUM_API bit_array_float *ExtendedGCDBitArrays(bit_array_float *a,bit_array_float *b,bit_array_float **x,
                                                 bit_array_float **y,volatile char *cancel);

BIGNUM_API bit_array *ExponentiateBitArrays(bit_array *ba1,bit_array *ba2,volatile char *cancel);

BIGNUM_API bit_array *InitializeBitArrayFromByteArray(unsigned char *bya,uint64_t nbytes);

BIGNUM_API char *PrintBitArray(bit_array *);

BIGNUM_API char *PrintBitArray(bit_array *ba);

BIGNUM_API char *BitArrayToDecimalIntegerString(bit_array *ba,volatile char *cancel);

BIGNUM_API void CleanBitArray(bit_array *ba);

BIGNUM_API bit_array *ReduceBitArray(bit_array **ba);

BIGNUM_API char TestZeroBitArray(bit_array *ba);

BIGNUM_API char *BitArrayToDecimalFractionalString(bit_array *ba,uint64_t ndecimals,volatile char *cancel);

BIGNUM_API char *PrintBitArrayFloat(bit_array_float *);

BIGNUM_API char *PrintBitArrayFloatToDecimal(bit_array_float *,int32_t sigdigits,volatile char *cancel);

BIGNUM_API char *PrintBitArrayFloatToHexadecimal(bit_array_float *);

BIGNUM_API bit_array_float *InitializeBitArrayFloatFromDouble(double val);

BIGNUM_API bit_array *InitializeBitArrayFromUInt64(uint64_t val);

BIGNUM_API uint64_t PowMod(uint64_t,uint64_t,uint64_t);

BIGNUM_API bit_array *PowModBitArrays(bit_array *base,bit_array *exponent,bit_array *mod,volatile char *cancel);

BIGNUM_API void *ReadBitArrayFloat(void *,stream_type);

BIGNUM_API void WriteBitArrayFloat(void *,void *,stream_type);

BIGNUM_API bit_array_float *EulersNumber(uint64_t digits,volatile char *cancel);

BIGNUM_API void EulersNumberPartialSum(uint64_t n,bit_array **p,bit_array **q,volatile char *cancel);

BIGNUM_API void EPartialSumSub(bit_array *a,bit_array *b,bit_array *baone,bit_array **p,bit_array **q,
                               volatile char *cancel);

//====================================================================================================================//
//====================================================================================================================//
//====================================================================================================================//
//====================================================================================================================//

BIGNUM_API uint64_t CiosMultiplyAccumulate(uint64_t a,uint64_t b,uint64_t c1,uint64_t c2,uint64_t *out_lo);

BIGNUM_API uint64_t CiosN0Prime(uint64_t n0);

BIGNUM_API char CiosCompare(const uint64_t *a,const uint64_t *b,size_t L);

BIGNUM_API void CiosSubtract(uint64_t *out,const uint64_t *a,const uint64_t *b,size_t L);

BIGNUM_API void CiosMontgomeryMultiplySub(uint64_t *out,const uint64_t *A,const uint64_t *B,const uint64_t *N,
                                          uint64_t n0_inv,size_t L,uint64_t *t);

BIGNUM_API void CiosMontgomeryExp(uint64_t *out,const uint64_t *base_mont,
                                  const uint64_t *exp,size_t exp_limbs,
                                  const uint64_t *N,uint64_t n0_inv,
                                  const uint64_t *one_mont,size_t L,
                                  uint64_t *t);

BIGNUM_API char CiosMillerRabinWitness(const uint64_t *a,const uint64_t *N,size_t L,
                                       const uint64_t *R2_mod_N,uint64_t n0_inv,
                                       const uint64_t *d,size_t d_limbs,size_t s,
                                       const uint64_t *one_mont,
                                       const uint64_t *n_minus_one_mont,
                                       uint64_t *a_mont,uint64_t *x,
                                       uint64_t *temp,uint64_t *t);

BIGNUM_API char CiosMillerRabinPrimeTestSub(const uint64_t *N,uint64_t L,uint64_t iterations,
                                            const uint64_t *R2_mod_N,
                                            const uint64_t *d,uint64_t d_limbs,
                                            uint64_t s,
                                            cha_cha_20_state *ccstate);
BIGNUM_API char CiosMillerRabinPrimeTest(bit_array *n,int32_t k,cha_cha_20_state *ccstate,volatile char *cancel);

BIGNUM_API uint32_t FastBitArrayMod32(bit_array *N, uint32_t p);

BIGNUM_API void PrimeSearch(bit_array **prime1,bit_array *prime2,double *primes,
                       int32_t mr_its,cha_cha_20_state *seed,char *abort);

BIGNUM_API void GetPrimePair(bit_array **prime1,bit_array **prime2,uint64_t nbits,int32_t mr_its,
                             cha_cha_20_state *seed,
                             char *abort);

#endif
