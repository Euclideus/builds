#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#ifndef ARB_H
#define ARB_H

#ifdef __GNUC__
#include   <dirent.h>
#include   <unistd.h>
#elif defined(_WIN32)
#include   <dirent_win.h>
#elif defined(_WIN64)
#include   <dirent_win.h>
#endif

#include <bit_array.h>
#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
#define ARB_EXPORTS 1
#ifdef ARB_EXPORTS
#define ARB_API __declspec(dllexport)
#else
#define ARB_API __declspec(dllimport)
#endif
#else
#define ARB_API
#endif

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#define IM1     2147483563
#define IM2     2147483399
#define AM      (1.0/IM1)
#define IMM1    (IM1-1.0)
#define IA1     40014
#define IA2     40692
#define INFD    HUGE_VAL
#define INFL    HUGE_VALL
#define IQ1     53668
#define IQ2     52774
#define IR1     12211
#define IR2     3791
#define LN2     0.693147180559945309417232121458176
#define LN10    2.302585092994045684017991454684364
#define LNPI    1.144729885849400174143427351353058
#define NTAB    32
#define NDIV    (1.0+IMM1/NTAB)
#define EPS     1.2e-7
#define RNMX    (1.0-EPS)
#define PI      3.141592653589793238462643383279502
#define EULER   2.718281828459045235360287471352662
#define M_EULER 0.57721566490153286060651209008
#define ROOT2   1.414213562373095048801688724209698
#define ROOT3   1.732050807568877293527446341505872
#define ROOT5   2.236067977499789696409173668731276
#define STREX0  "\?\'\"!#$%&()*<=>@[]^_`{}~ABCFGHIJKLMNOPQRSTUVWXYZabcfghijklmn\
opqrstuvwxyz"
#define STREX00 "\?\'\"!#$%&()*<=>@[]^_`{}~ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghij\
klmnopqrstuvwxyz"
#define STREXN  "\?\'\"!#$%&()*<=>@[]^_`{}~:+-,.;\\/ |ABCDEFGHIJKLMNOPQRSTUVWXY\
Zabcdefghijklmnopqrstuvwxyz"
#define STREX1  "\n\t\v\b\r\f\a\\\?\'\" !#$%&()+-*/,:;<=>@[]^_`{|}~."
#define STREX2  "\n\t\v\b\r\f\a "
#define STREX3  "\n\t\v\b\r\f\a\\ ,/:;|"
#define STREX4  "0123456789"
#define STREX5  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define MSUB    7
#define NSTACK  500
#define MAXDEG  50
#define DIM_MAX  20
#define NBITS   31
#define MAX_DIGITS 15
#define EPSILON 1.0E-15

typedef enum { memory_stream, file_stream }stream_type;
typedef struct cmplx cmplx;

typedef struct MEM_FILE MEM_FILE;

typedef struct cmplx {

  double r;
  double i;
}cmplx;

ARB_API double          AbsC(cmplx);
ARB_API double        **AbsCM(cmplx **);
ARB_API double         *AbsCV(cmplx *);
ARB_API cmplx           AddC(cmplx,cmplx);
ARB_API cmplx           AddNC(cmplx *);
ARB_API double         *AddV(double *,double *);
ARB_API cmplx          *AddVC(cmplx *,cmplx *);
ARB_API void            AddIPM(double **,double **,double **);
ARB_API double        **AddM(double **,double **);
ARB_API cmplx         **AddMC(cmplx **,cmplx **);
ARB_API void            AddPrimeFactors(double,double ,bit_array *,int32_t *,
                                double **);
ARB_API cmplx           Add3C(cmplx,cmplx,cmplx);
ARB_API void            AdjacentAveraging(double *,int32_t);
ARB_API void            AdjacentAveragingC(cmplx *,int32_t);
ARB_API void            AdjacentAveragingML(int32_t **,int32_t,int32_t);
ARB_API void            AdjacentAveragingInterpolation(double *,int32_t);
ARB_API void            AdjacentAveragingInterpolationC(cmplx *,int32_t);
ARB_API void            AdjacentInterpolation(double *,int32_t);
ARB_API void            AdjacentInterpolationC(cmplx *,int32_t);
ARB_API cmplx         **Adjoint(cmplx **);
ARB_API void            AdjointIP(cmplx **,cmplx **);
ARB_API void            AdjointSquareIP(cmplx **);
ARB_API void            AiryFuncSub(double,double *,double *,double *,double *);
ARB_API int32_t            AlphabeticStringComparator(char *,char *);
ARB_API double         *AllocDouble(double);
ARB_API int32_t           *AllocInt(int32_t);
ARB_API void            Amoeba(double (*)(double *),double **,double *,double,int32_t *);
ARB_API double          AmoebaTry(double **,double *,double *,double (*)(double *),
                          int32_t,double,double *);
ARB_API cmplx         **AnalyticSignal(double **);
ARB_API void            AppendFilenameR(char **,char *);
ARB_API void            AppendMatrix(double ****,double **);
ARB_API void            AppendMatrixVector(double ****,double ***);
ARB_API char           *AppendS(char **, char *);
ARB_API char          **AppendString(char ***, char *);
ARB_API cmplx           ArccosC(cmplx);
ARB_API cmplx           ArccoshC(cmplx);
ARB_API cmplx           ArcsinC(cmplx);
ARB_API cmplx           ArcsinhC(cmplx);
ARB_API cmplx           ArctanC(cmplx);
ARB_API cmplx           ArctanhC(cmplx);
ARB_API void            AugmentMatrixHC(cmplx ***,cmplx **);
ARB_API void            AugmentMatrixHL(int32_t ***,int32_t **);
ARB_API void            AugmentMatrixV(double ***,double **);
ARB_API void            AugmentMatrixVC(cmplx ***,cmplx **);
ARB_API void            AugmentMatrixVL(int32_t ***,int32_t **);
ARB_API char           *AugmentString(char **,int32_t);
ARB_API void            AugmentVector(double **,double *);
ARB_API void            AugmentVectorC(cmplx **,cmplx *);
ARB_API void            AugmentVectorL(int32_t **,int32_t *);
ARB_API double        **Autocorrelation(double **);
ARB_API double        **AutoSample1D(double (*)(double),double,double,double);
ARB_API cmplx         **AutoSample1DC(cmplx (*)(double),double,double,double);
ARB_API int32_t           *BanDec(double **,int32_t,int32_t,double **,double *);
ARB_API int32_t           *BanDecC(cmplx **,int32_t,int32_t,cmplx **,double *);
ARB_API void            BanSolve(double **,int32_t,int32_t,double *);
ARB_API void            BanSolveC(cmplx **,int32_t,int32_t,cmplx *);
ARB_API unsigned char  *Base64Decoding(char *,int32_t *);
ARB_API char           *Base64Encoding(unsigned char *, int32_t);
ARB_API char           *Base64EncodingOptionalChars(unsigned char *, int32_t, char *,char);
ARB_API void            Base64EncodingTriplet(uint8_t,uint8_t,uint8_t,char *,char *);
ARB_API double          BernoulliNumber(double, char *abort);
ARB_API double         *BesselFuncRoots(double,double,int32_t);
ARB_API double          BesselFuncSeries(double,double);
ARB_API int32_t            BesselFuncSub(double,double,double *,double *,double *,
                              double *);
ARB_API void            BesselGammas(double,double *,double *,double *,double *);
ARB_API cmplx           BesselIFunc(double,double);
ARB_API cmplx           BesselJFunc(double,double);
ARB_API cmplx           BesselKFunc(double,double);
ARB_API int32_t            BesselModFuncSub(double,double,double *,double *,double *,
                                 double *);
ARB_API cmplx           BesselYFunc(double,double);
ARB_API double          BetaFuncCF(double,double,double);
ARB_API double          BetaFuncI(double,double,double);
ARB_API void            BicubicCoefficients(double *,double *,double *,double *,double,
                                    double,double **,double **);
ARB_API double       ***BicubicInterpolation(double ***,int32_t,int32_t);
ARB_API double        **BicubicInterpolationM(double **,int32_t,int32_t);
ARB_API void            BicubicInterpolationSquare(double *,double *,double *,double *,
                                           double,double,double,double,double,
                                           double,double *,double *,double *,
                                           double **);
ARB_API int32_t            BinarySearchPos(double,double *);
ARB_API int32_t            BinarySearchPosC(double,cmplx *);
ARB_API int32_t            BinarySearchPosS(char *, char **);
ARB_API void            BinToAscii(char *);
ARB_API void            BinToAsciiB(char *);
ARB_API void            BinToAsciiI(char *);
ARB_API void            BinToAsciiL(char *);
ARB_API int32_t            Bisection(double (*)(double),double *,double,double,double,
                          int32_t);
ARB_API double          BisectionN(double (*)(double *),double *,int32_t,double,double,
                           double,int32_t);
ARB_API double        **BlockDiagonalMatrix(double ***);
ARB_API double         *BoxMuller(int32_t, int32_t *);
ARB_API double          BoxMuller1(int32_t *,int32_t *,int32_t *,int32_t *);
ARB_API double         *BoxMuller2(int32_t,double *);
ARB_API void            BracketMinimum(double (*)(double),double,double,double *,
                               double *,double *,double *,double *,double *);
ARB_API double          BrentMinimization(double (*)(double),double,double,double);
ARB_API char           *ByteArrayToString(unsigned char *,int32_t);
ARB_API int32_t           *ByteArrayToVectorL(unsigned char *,int32_t);
ARB_API uint32_t       *ByteArrayToVectorUInt32(unsigned char *, int32_t);
ARB_API double        **CartesianProduct(double *, double *,char *);
ARB_API double          Ceiling(double);
ARB_API int32_t            CenterDistr(double *);
ARB_API int32_t            CenterDistrC(cmplx *);
ARB_API double          CenterDistribution(double **);
ARB_API double          CenterDistributionC(cmplx **);
ARB_API double          CenterDistributionWindowC(cmplx **,int32_t,int32_t,double);
ARB_API int32_t            CenterDistrWindowC(cmplx *,int32_t,int32_t);
ARB_API int32_t            CenterDistr0C(cmplx *);
ARB_API void            CenterDomain(double *,double);
ARB_API void            CenterDomainC(cmplx *,double);
ARB_API double          CenterDomainFFT(double *);
ARB_API double          CenterDomainFFTC(cmplx *);
ARB_API void            ChangeExtension(char **,char *);
ARB_API char           *CharString(char);
ARB_API char           *CharToHex(char);
ARB_API double          ChebychevExpansion(double,double,double *,int32_t,double);
ARB_API double          ChiSquare(double **,double (*)(double,double *),double *);
ARB_API cmplx           CI(void);
ARB_API double         *Col(double **,int32_t);
ARB_API double          Comb(int32_t,int32_t);
ARB_API double          CombFunc(double,double);
ARB_API double        **CombineMatrices(double **,double **);
ARB_API int32_t          **CombineMatricesL(int32_t **,int32_t **);
ARB_API int32_t            CompareFloats(double,double);
ARB_API double        **ComplementaryM(double **);
ARB_API cmplx           ComplexP(double,double);
ARB_API cmplx           ComplexR(double,double);
ARB_API cmplx          *ComplexRoots(cmplx,int32_t);
ARB_API char          **ComplexString(cmplx,int32_t);
ARB_API char           *ConcatFilenameL(char *,char *);
ARB_API char           *ConcatFilenameR(char *,char *);
ARB_API char           *ConcatN(char **);
ARB_API char          **ConcatStringVector(char **,char **);
ARB_API char           *Concat4(char *,char *,char *,char *);
ARB_API char           *Concat5(char *,char *,char *,char *,char *);
ARB_API cmplx           ConjC(cmplx);
ARB_API double        **ComplementM(double **,double **);
ARB_API double         *ComplementV(double *,double *);
ARB_API char           *Concat(char*, char*);
ARB_API char           *Concat3(char*, char*, char*);
ARB_API double       ***ConvertMVVM(double ***,int32_t);
ARB_API cmplx        ***ConvertMVVMC(cmplx ***,int32_t);
ARB_API double       ***ConvertVMMV(double ***);
ARB_API cmplx        ***ConvertVMMVC(cmplx ***);
ARB_API double        **ConvolutionC(double (*)(double),double (*)(double),double,
                                     double,int32_t,double,double,int32_t);
ARB_API double        **ConvolutionD(double **,double **);
ARB_API cmplx         **ConvolutionFFT(cmplx **,cmplx **);
ARB_API cmplx          *ConvolutionFFTV(cmplx *,cmplx *);
ARB_API double        **Convolution1D(double *,double *,double *);
ARB_API cmplx           CopyC(cmplx);
ARB_API double        **CopyMatrix(double **);
ARB_API cmplx         **CopyMatrixC(cmplx **);
ARB_API void            CopyMatrixIPC(cmplx **,cmplx **);
ARB_API int32_t           **CopyMatrixI(int32_t **);
ARB_API void            CopyMatrixIP(double **,double **);
ARB_API void            CopyMatrixIPL(int32_t **,int32_t **);
ARB_API float         **CopyMatrixF(float **);
ARB_API int32_t          **CopyMatrixL(int32_t **);
ARB_API uint32_t      **CopyMatrixUInt32(uint32_t **);
ARB_API double       ***CopyMatrixVector(double ***);
ARB_API char           *CopyS(char *);
ARB_API char         ***CopyStringMatrix(char ***);
ARB_API char        ****CopyStringMatrixVector(char ****);
ARB_API char          **CopyStringVector(char **);
ARB_API cmplx        ***CopyMatrixVectorC(cmplx ***);
ARB_API void           *CopyMemFile(void *v);
ARB_API double         *CopyVector(double *);
ARB_API cmplx          *CopyVectorC(cmplx *);
ARB_API int32_t            *CopyVectorI(int32_t *);
ARB_API void            CopyVectorIP(double *,double *);
ARB_API void            CopyVectorIPC(cmplx *,cmplx *);
ARB_API void            CopyVectorIPL(int32_t *,int32_t *);
ARB_API float          *CopyVectorF(float *);
ARB_API int32_t           *CopyVectorL(int32_t *);
ARB_API double          CorrelationCoefficient(double *,double *);
ARB_API cmplx           CosC(cmplx);
ARB_API cmplx           CoshC(cmplx);
ARB_API double          Cos2PulseFunc(double);
ARB_API double          Cos4PulseFunc(double);
ARB_API double          Cos8PulseFunc(double);
ARB_API int32_t            CoulombWaveFunc(double, int32_t, double *, double *, double *,
                                int32_t, double, int32_t);
ARB_API double          CoulombWaveFuncBess(double,double,int32_t,int32_t);
ARB_API void            CoulombWaveFuncBesselSph(double,double,int32_t,double *,int32_t);
ARB_API void            CoulombWaveFuncCF(double,double,int32_t,double *,double *,
                                  double *,double *,int32_t,double);
ARB_API int32_t            CoulombWaveFuncF(double,int32_t,double *,double *,int32_t,double,
                                 int32_t);
ARB_API int32_t            CoulombWaveFuncFPF(double,double,int32_t,double *,int32_t);
ARB_API int32_t            CoulombWaveFuncG(double,int32_t,double *,double *,int32_t,double,
                                 double,int32_t);
ARB_API double          CoulombWaveFuncFPrimeSeries(double,double,int32_t,int32_t);
ARB_API double          CoulombWaveFuncFSeries(double,double,int32_t,int32_t);
ARB_API void            CoulombWaveFuncHPH(double,double,int32_t,double *,double *,double);
ARB_API void            CoulombWaveFuncIntegrateFABM(double,int32_t,double *,double *,
                                             int32_t,int32_t,double,double,int32_t);
ARB_API void            CoulombWaveFuncIntegrateF0ABM(double,double *,double *,int32_t,
                                              int32_t,double,double,int32_t);
ARB_API void            CoulombWaveFuncIntegrateFPrimeABM(double *,double *,double *,
                                                  int32_t,int32_t);
ARB_API void            CoulombWaveFuncIntegrateGABM(double,int32_t,double *,double *,
                                             int32_t,int32_t,double,double,int32_t);
ARB_API void            CoulombWaveFuncIntegrateG0ABM(double,double *,double *,int32_t,
                                              int32_t,double,double,int32_t);
ARB_API void            CoulombWaveFuncIntegrateGPrimeABM(double *,double *,double *,
                                                  int32_t,int32_t);
ARB_API void            CoulombWaveFuncNear(double *,double *,double *,double,double);
ARB_API double          Covariance(double *,double *);
ARB_API double        **CropMatrix(double **,int32_t,int32_t,int32_t,int32_t);
ARB_API cmplx         **CropMatrixC(cmplx **,int32_t,int32_t,int32_t,int32_t);
ARB_API double        **CropMatrixCentered(double **,int32_t,int32_t);
ARB_API cmplx         **CropMatrixCenteredC(cmplx **,int32_t,int32_t);
ARB_API char           *CropString(char *, int32_t, int32_t);
ARB_API char          **CropStringVector(char **,int32_t,int32_t);
ARB_API double         *CropVector(double *,int32_t,int32_t);
ARB_API cmplx          *CropVectorC(cmplx *,int32_t,int32_t);
ARB_API double         *CropVectorCentered(double *,int32_t);
ARB_API cmplx          *CropVectorCenteredC(cmplx *,int32_t);
ARB_API double        **Crop1D(double **,double,double);
ARB_API double       ***Crop2D(double ***,double,double,double,double);
ARB_API double         *CrossP(double *,double *);
ARB_API double          CubicInterpolation1(double *,double *,double);
ARB_API double         *Curl(double *(*)(double *),double *,double);
ARB_API double         *CurlCyl(double *(*)(double *),double *,double);
ARB_API double         *CurlSph(double *(*)(double *),double *,double);
ARB_API cmplx           CZ(void);
ARB_API cmplx           C1(void);
ARB_API void            DampenLeft(double *,double *,double,double);
ARB_API void            DampenLeftFit(double *,int32_t,int32_t);
ARB_API void            DampenLeftGauss(double *,int32_t,double);
ARB_API void            DampenLeftLinear(double *,int32_t);
ARB_API void            DampenLeftZero(double *,int32_t,double);
ARB_API void            DampenRight(double *,double *,double,double);
ARB_API void            DampenRightExp(double *,int32_t,double);
ARB_API void            DampenRightFit(double *,int32_t,int32_t);
ARB_API void            DampenRightGauss(double *,int32_t,double);
ARB_API void            DampenRightLinear(double *,int32_t);
ARB_API double          DeltaFunc(double);
ARB_API double          Derivative(double (*)(double),double,double);
ARB_API double        **DerivativeDCyclic(double **);
ARB_API double          DerivativeN(double (*)(double),double,int32_t,double);
ARB_API double          DerivativeP(double (*)(double *),double *,int32_t,double);
ARB_API double         *DerivativePV(double *(*)(double *),double *,int32_t,double);
ARB_API double        **DerivativeSpectral(double *,double *,double,double);
ARB_API double         *DerivativeV(double *(*)(double),double,double);
ARB_API double          DerivativeWeights(double *,double *,double);
ARB_API double        **Derivative1D(double *,double *);
ARB_API cmplx         **Derivative1DC(cmplx **);
ARB_API double          Derivative2(double (*)(double),double,double);
ARB_API double        **Derivative2D(double **);
ARB_API double        **Derivative2DCyclic(double **);
ARB_API double          Derivative2P(double (*)(double *),double *,int32_t,double);
ARB_API double         *Derivative2PV(double *(*)(double *),double *,int32_t,double);
ARB_API double         *Derivative2V(double *(*)(double),double,double);
ARB_API double          Det(double **);
ARB_API cmplx           DetC(cmplx **);
ARB_API double        **DFT(double **,double,double,int32_t,int32_t);
ARB_API double        **DiagonalMatrix(double *);
ARB_API cmplx         **DiagonalMatrixC(cmplx *);
ARB_API cmplx           DigammaFunc(cmplx, char *);
ARB_API cmplx         **Discretize1DC(cmplx (*)(double),double,double,int32_t);
ARB_API double        **DiscretizeAdaptive(double (*)(double),double,double,double);
ARB_API void            DiscretizeAdaptiveSub(double (*)(double),double ,double,double,
                                      double,double,double,double,double ***,
                                      int32_t *);
ARB_API cmplx         **DiscretizeC(cmplx (*)(cmplx),cmplx,cmplx,int32_t);
ARB_API cmplx         **DiscretizeCC(cmplx (*)(cmplx),cmplx,cmplx,int32_t,int32_t);
ARB_API double        **DiscretizeDFT(cmplx (*)(double),double,double,int32_t);
ARB_API double         *DiscretizeDomain(double,double,int32_t);
ARB_API cmplx          *DiscretizeDomainC(double,double,int32_t);
ARB_API double         *DiscretizeDomainFFT(double,double,int32_t);
ARB_API cmplx          *DiscretizeDomainFFTC(double,double,int32_t);
ARB_API void            DiscretizeDomainIP(double *,double,double);
ARB_API double        **DiscretizeDomainN(double *,double *,int32_t *);
ARB_API cmplx         **DiscretizeFFT(cmplx (*)(double),double,double,int32_t);
ARB_API double        **DiscretizeFFTN(cmplx (*)(double *),double *,double *,int32_t *);
ARB_API double        **DiscretizeN(double (*)(double *),double *,double *,int32_t *);
ARB_API double        **DiscretizeNU(double (*)(double),double,double,double *);
ARB_API cmplx         **DiscretizeNUC(cmplx (*)(double),double,double,double *);
ARB_API double        **DiscretizeN1(double (*)(double *),double,double,int32_t,int32_t,
                             double *);
ARB_API double        **DiscretizeP(double (*)(double,double *),double,double,int32_t,
                            double *);
ARB_API cmplx         **DiscretizePC(cmplx (*)(double,double *),double,double,int32_t,
                             double *);
ARB_API double        **DiscretizePN(double (*)(double *,double *),double *,double *,
                             int32_t *,double *);
ARB_API cmplx         **DiscretizePNC(cmplx (*)(double *,double *),double *,double *,
                              int32_t *,double *);
ARB_API double        **DiscretizeRungeKutta1D(void (*)(double,double *,double *),
                                       double,double);
ARB_API cmplx         **DiscretizeRungeKutta1DC(void (*)(double,cmplx *,cmplx *),
                                        double,double);
ARB_API double       ***DiscretizeSphericalCS3D(double (*)(double,double),double *,
                                        double *);
ARB_API double       ***DiscretizeSpherical3D(double (*)(double,double,double),
                                      double *,double *,double *);
ARB_API double        **DiscretizeV(double (*)(double *),double,double,int32_t,int32_t,
                            double *);
ARB_API double        **Discretize1D(double (*)(double),double,double,int32_t);
ARB_API double       ***Discretize2D(double (*)(double,double),double,double,double,
                             double,int32_t,int32_t);
ARB_API double          Distance(double *,double *);
ARB_API double          Div(double *(*)(double *),double *,double);
ARB_API cmplx           DivC(cmplx,cmplx);
ARB_API cmplx           DivCR(cmplx,double);
ARB_API double          DivCyl(double *(*)(double *),double *,double);
ARB_API int32_t            Divisible(double,double);
ARB_API double         *Divisors(double,char *);
ARB_API double          DivSph(double *(*)(double *),double *,double);
ARB_API double          DotP(double *,double *);
ARB_API char           *DoubleString(double,int32_t);
ARB_API char           *DoubleStringCleanZeros(char **);
ARB_API char           *DoubleStringDecimal(double,int32_t);
ARB_API char           *DoubleStringExponential(double,int32_t);
ARB_API char           *DoubleStringRound(char **,int32_t);
ARB_API double        **DownSampleCols(double **,int32_t);
ARB_API cmplx         **DownSampleColsC(cmplx **,int32_t);
ARB_API double         *DownSampleV(double *,int32_t);
ARB_API cmplx          *DownSampleVC(cmplx *,int32_t);
ARB_API void            EigenDecomposition(double **,double *,double **);
ARB_API cmplx          *EigenVector(double **mat,cmplx,int32_t,int32_t *);
ARB_API int32_t          **EnumerateCombinations(int32_t, int32_t, char *);
ARB_API void            EnumerateCombinationsSub(int32_t **, int32_t, int32_t, int32_t, int32_t, int32_t,
                                         char *);
ARB_API int32_t          **EnumeratePermutations(int32_t, char *);
ARB_API void            EnumeratePermutationsSub(int32_t **, int32_t, int32_t, int32_t *, char *);
ARB_API int32_t          **EnumerateTuples(int32_t *);
ARB_API void            EnumerateTuplesSub(int32_t **,int32_t,int32_t,int32_t *);
ARB_API double         *Envelope(double *,int32_t);
ARB_API int32_t         EqualMatrices(double **,double **);
ARB_API int32_t         EqualMatricesC(cmplx **,cmplx **);
ARB_API int32_t         EqualMatricesF(float **,float **);
ARB_API int32_t         EqualMatricesI(int32_t **,int32_t **);
ARB_API int32_t         EqualMatricesL(int32_t **,int32_t **);
ARB_API int32_t         EqualMatricesS(char ***,char ***);
ARB_API int32_t         EqualRows(double **,int32_t,double **,int32_t);
ARB_API int32_t         EqualVectors(double *,double *);
ARB_API int32_t         EqualVectorsC(cmplx *,cmplx *);
ARB_API int32_t         EqualVectorsS(char **,char **);
ARB_API int32_t         EqualVectorsF(float *,float *);
ARB_API int32_t         EqualVectorsI(int32_t *,int32_t *);
ARB_API int32_t         EqualVectorsL(int32_t *,int32_t *);
ARB_API double          EuclideanDistM(double **,double **);
ARB_API double          EuclideanDistV(double *,double *);
ARB_API double          EuclideanNormM(double **);
ARB_API double          EuclideanNormV(double *);
ARB_API double          EuclideanNorm2(double,double);
ARB_API double          EuclideanNorm3(double,double,double);
ARB_API int32_t         Even(double);
ARB_API cmplx           ExpC(double);
ARB_API cmplx           ExpCC(cmplx);
ARB_API void            ExtendVector(double **,int32_t);
ARB_API void            ExtendVectorC(cmplx **,int32_t);
ARB_API void            ExtendVectorF(float **,int32_t);
ARB_API void            ExtendVectorI(int32_t **,int32_t);
ARB_API void            ExtendVectorL(int32_t **,int32_t);
ARB_API void            ExtendMatrix(double ***,int32_t,int32_t);
ARB_API void            ExtendMatrixC(cmplx ***,int32_t,int32_t);
ARB_API void            ExtendMatrixF(float ***,int32_t,int32_t);
ARB_API void            ExtendMatrixI(int32_t ***,int32_t,int32_t);
ARB_API void            ExtendMatrixL(int32_t ***,int32_t,int32_t);
ARB_API double          Factorial(int32_t);
ARB_API double          FactorialLn(int32_t);
ARB_API double          FactorialProduct(int32_t *);
ARB_API double          FactorialProductLn(int32_t *);
ARB_API double          FactorialProductRatio(int32_t *,int32_t *);
ARB_API double          FactorialProductRatioLn(int32_t *,int32_t *);
ARB_API double          FactorialProduct3(int32_t,int32_t,int32_t);
ARB_API double          FactorialRatio(int32_t,int32_t);
ARB_API double          FactorialRatioLn(int32_t,int32_t);
ARB_API double          FactorialZeros(double,char *);
ARB_API void            FFTCols(cmplx **,int32_t);
ARB_API void            FFTDomainChange(double *);
ARB_API void            FFTDomainChangeC(cmplx *);
ARB_API void            FFTM(cmplx **,int32_t);
ARB_API void            FFTND(double **,int32_t);
ARB_API void            FFTNDomainChange(double **);
ARB_API int32_t           *FFTNGetNPts(double **);
ARB_API void            FFTNShift(double **);
ARB_API void            FFTRows(cmplx **,int32_t);
ARB_API void            FFTV(cmplx *,int32_t);
ARB_API void            FFTVErr(cmplx *,cmplx *,int32_t);
ARB_API void            FFT1D(cmplx **,int32_t);
ARB_API char           *FGetS(char *,int32_t *,FILE *);
ARB_API char           *Filename(char *);
ARB_API double         *FindPeaks1D(double *,double *);
ARB_API double         *FindPeaks1DC(cmplx *,double *);
ARB_API double         *FindRoots1D(double *,double *,double);
ARB_API double         *FindRoots1DC(cmplx *,double *,double);
ARB_API int32_t           *FindS(char *, char *);
ARB_API double         *FindSimpleRoots1D(double *,double *,double);
ARB_API double         *FindSimpleRoots1DC(cmplx *,double *,double);
ARB_API double          Floor(double);
ARB_API cmplx         **FormatFFT(cmplx **);
ARB_API cmplx         **FormatZeroPadFFT(cmplx **,int32_t);
ARB_API void            FourierFilter(double **,double,double,double);
ARB_API void            FourierFilterC(cmplx **,double,double,double);
ARB_API double          FractionalPart(double);
ARB_API double          FredholmInterpolation1(double **,double,double (*)(double),
                                       double (*)(double,double));
ARB_API cmplx           FredholmInterpolation1C(cmplx **,double,cmplx (*)(double),
                                        cmplx (*)(double,double));
ARB_API double        **Fredholm2(double (*)(double),double (*)(double,double),int32_t,
                          int32_t,int32_t,double);
ARB_API cmplx         **Fredholm21DC(cmplx (*)(double),cmplx (*)(double,double),
                             double,double,int32_t,double);
ARB_API void            FreeMatrixUInt32(uint32_t **t);
ARB_API void            Free(void *);
ARB_API void            FreeMatrix(double **);
ARB_API void            FreeMatrixC(cmplx **);
ARB_API void            FreeMatrixF(float **);
ARB_API void            FreeMatrixI(int32_t **);
ARB_API void            FreeMatrixL(int32_t **);
ARB_API void            FreeMatrixVector(double ***);
ARB_API void            FreeMatrixVectorC(cmplx ***);
ARB_API void            FreeMatrixVectorL(int32_t ***);
ARB_API void            FreeString(char *s);
ARB_API void            FreeStringMatrix(char ***);
ARB_API void            FreeStringMatrixVector(char ****);
ARB_API void            FreeStringVector(char **);
ARB_API void            FreeVector(double *);
ARB_API void            FreeVectorC(cmplx *);
ARB_API void            FreeVectorL(int32_t *);
ARB_API void            FreeVectorMatrix(double ***);
ARB_API void            FreeVectorMatrixC(cmplx ***);
ARB_API double        **FSeries(double (*)(double),double,double,int32_t,int32_t);
ARB_API double          FWHM(double **,int32_t,int32_t);
ARB_API double          FWHMC(cmplx **,int32_t,int32_t);
ARB_API double          FWHMIntensityC(cmplx **,int32_t,int32_t);
ARB_API double          FWHMWindow(double **, int32_t, int32_t, int32_t);
ARB_API double          GammaLn(double);
ARB_API cmplx           GammaLnC(cmplx);
ARB_API void            GaussianFit(char *,double **);
ARB_API double          GaussianFitFunction(double,double *);
ARB_API double        **GaussLaguerre(int32_t,double);
ARB_API double        **GaussLegendre(double,double,int32_t,double);
ARB_API int32_t            GreatestCommonDivisor(int32_t,int32_t);
ARB_API double        **GenerateComb(double,double,double,int32_t);
ARB_API double        **GenerateCombinations(double *, int32_t, int32_t,char *);
ARB_API int32_t          **GenerateCombinationsL(int32_t *, int32_t, int32_t,char *);
ARB_API double        **GenerateRowCombination(double **,int32_t **,int32_t);
ARB_API double        **GenerateRowPermutation(double **,int32_t **,int32_t);
ARB_API double        **GeneratePermutations(double *,char *);
ARB_API int32_t          **GeneratePermutationsL(int32_t *,char *);
ARB_API char           *GetDirectory(char *);
ARB_API double          GetMin(double *,double *);
ARB_API int32_t           *GetNPts(double **);
ARB_API double         *Grad(double (*)(double *),double *,double);
ARB_API double         *GradCyl(double (*)(double *),double *,double);
ARB_API double         *Gradient1D(double *,double);
ARB_API cmplx          *Gradient1DC(cmplx *,double);
ARB_API double       ***Gradient2D(double **,double,double);
ARB_API double         *GradSph(double (*)(double *),double *,double);
ARB_API void            GramSchmidt(double **);
ARB_API cmplx         **GramSchmidtC(cmplx **);
ARB_API double          HalfCircleFunc(double);
ARB_API double          HannFunc(double,double,double);
ARB_API char           *HashFromByteArray(MEM_FILE *,int32_t);
ARB_API char           *HashFromString(char *,int32_t);
ARB_API int32_t         HashFromStringL(char *);
ARB_API char           *HashWithSalt(char *,char *);
ARB_API double          HeavisideFunc(double);
ARB_API uint8_t         HexDigitToDecimal(char);
ARB_API uint8_t         HexByteToDecimal(char *);
ARB_API double        **Histogram(double *,int32_t);
ARB_API int32_t          **HistogramD(int32_t *);
ARB_API double         *HMSTime(double,double,double);
ARB_API void            HouseholderReduction(double **,double *,double *);
ARB_API uint32_t        HSVToint(double,double,double);
ARB_API void            HSVToRGB(double *,double *,double *,double,double,double);
ARB_API cmplx           HydrogenWaveFunc(double,double,double,int32_t,int32_t,int32_t);
ARB_API double        **IdentityMatrix(int32_t);
ARB_API double          Im(cmplx);
ARB_API double        **ImM(cmplx **);
ARB_API double         *ImV(cmplx *);
ARB_API cmplx           ImagC(double);
ARB_API void            IncM(double **,double **);
ARB_API void            IncV(double *,double *);
ARB_API double          InnerP(double *,double *);
ARB_API cmplx           InnerPC(cmplx *,cmplx *);
ARB_API char           *InsertChar(char, char**, int32_t);
ARB_API void            InsertCol(double *,double ***,int32_t);
ARB_API void            InsertColC(cmplx *,cmplx ***,int32_t);
ARB_API void            InsertElement(double,double **,int32_t);
ARB_API void            InsertElementC(cmplx,cmplx **,int32_t);
ARB_API void            InsertElementL(int32_t,int32_t **,int32_t);
ARB_API char          **InsertElementS(char *,char ***,int32_t);
ARB_API void            InsertElementSM(char ***,char *****,int32_t);
ARB_API void            InsertElementSV(char **,char ****,int32_t);
ARB_API void            InsertElementUInt32(uint32_t,uint32_t **,int32_t);
ARB_API void            InsertMatrix(double **,double ****,int32_t);
ARB_API void            InsertRow(double *,double ***,int32_t);
ARB_API void            InsertRowC(cmplx *,cmplx ***,int32_t);
ARB_API void            InsertRowS(char **,char ****,int32_t);
ARB_API char           *InsertStr(char *, char **, int32_t);
ARB_API int32_t             InsideInterval(double,double,double);
ARB_API double          Integral(double (*)(double),double,double,int32_t);
ARB_API double          Integral2(double (*)(double,double),double,double,double,
                          double,int32_t,int32_t);
ARB_API double          Integral2D(double **);
ARB_API double          IntegralD(double **,int32_t,int32_t);
ARB_API double          IntegralP(double (*)(double,double *),double,double,int32_t,
                          double *);
ARB_API double          IntegralPath(double *(*)(double *),double *(*)(double),double,
                             double,int32_t);
ARB_API cmplx           IntegralPC(cmplx (*)(double,double *),double,double,int32_t,
                           double *);
ARB_API double          IntegralSurfaceS(double (*)(double *),double *(*)(double *),
                                 double *,double *,int32_t *);
ARB_API double          IntegralSurfaceV(double *(*)(double *),double *(*)(double *),
                                 double *,double *,int32_t *);
ARB_API double         *IntegralV(double *(*)(double),double,double,int32_t);
ARB_API void            Integrator(double *,double *,double *,int32_t);
ARB_API void            IntegratorC(cmplx *,double *,cmplx *,int32_t);
ARB_API double         *IntersectionV(double *,double *);
ARB_API double        **IntersectionM(double **,double **);
ARB_API char          **IntersectionSV(char ***);
ARB_API void            InvertCols(double **);
ARB_API void            InvertColsC(cmplx **);
ARB_API void            InvertM(double **);
ARB_API void            InvertMC(cmplx **);
ARB_API void            InvertRows(double **);
ARB_API void            InvertRowsC(cmplx **);
ARB_API void            Invert2M(double **);
ARB_API char           *InvertCase(char *in);
ARB_API cmplx           InvC(cmplx);
ARB_API int32_t            IsNAN(double);
ARB_API int32_t            IsINF(double);
ARB_API double        **JacobianMatrix(double *(*)(double *),double *,double);
ARB_API double        **JoinMatrixH(double **,double **);
ARB_API int32_t          **JoinMatrixHL(int32_t **,int32_t **);
ARB_API double       ***JoinMatrixVector(double ***,double ***);
ARB_API double        **JoinMatrixV(double **,double **);
ARB_API int32_t          **JoinMatrixVL(int32_t **,int32_t **);
ARB_API double         *JoinVector(double *,double *);
ARB_API int32_t           *JoinVectorL(int32_t *,int32_t *);
ARB_API double        **JoinVectorM(double *,double *);
ARB_API int32_t            Kronecker(int32_t,int32_t);
ARB_API double        **Lagrange(double **,double,double,int32_t);
ARB_API double          LaguerreFunc(double,int32_t,double);
ARB_API double          Lapl(double (*)(double *),double *,double);
ARB_API double         *Laplacian1D(double *,double);
ARB_API cmplx          *Laplacian1DC(cmplx *,double);
ARB_API double        **Laplacian2D(double **,double,double);
ARB_API double          LaplCyl(double (*)(double *),double *,double);
ARB_API double          LaplSph(double (*)(double *),double *,double);
ARB_API char           *LeadingCharacters(char **,char,char,int32_t);
ARB_API uint32_t        LeftRotate32(uint32_t,int32_t);
ARB_API uint64_t        LeftRotate64(uint64_t,int64_t);
ARB_API double          LegendreFunc(double,int32_t,int32_t);
ARB_API double          LegendrePolynomial(double,int32_t);
ARB_API double        **LinearInterpolation1D(double **,double,double,int32_t);
ARB_API cmplx         **LinearInterpolation1DC(cmplx **,double,double,int32_t);
ARB_API double        **LinearInterpolationCols(double **,int32_t);
ARB_API cmplx           LinearInterpolation1C(cmplx *,double *,double);
ARB_API double        **LinearInterpolationM(double **,int32_t,int32_t);
ARB_API int32_t          **LinearInterpolationML(int32_t **,int32_t,int32_t);
ARB_API void            LinearInterpolationPts1D(double *,double *,double *,double *);
ARB_API void            LinearInterpolationPts1DC(cmplx *,double *,cmplx *,double *);
ARB_API void            LinearInterpolationPts2D(double **,double *,double *,double **,
                                         double *,double *);
ARB_API double        **LinearInterpolationRows(double **,int32_t);
ARB_API double         *LinearInterpolationV(double *,int32_t);
ARB_API cmplx          *LinearInterpolationVC(cmplx *,int32_t);
ARB_API double          LinearInterpolation1(double *,double *,double);
ARB_API double       ***LinearInterpolation2D(double ***,int32_t,int32_t);
ARB_API double          LinearInterpolation2D1(double **,double *,double *,double,
                                       double);
ARB_API double          LinearPhase(cmplx *);
ARB_API void            LinSolve(double **,double **);
ARB_API unsigned char  *LoadFileToByteArray(char *,int32_t *);
ARB_API char           *LoadFileToString(char *);
ARB_API double        **LoadMatrix(char *);
ARB_API double        **LoadMatrixBin(char *);
ARB_API cmplx         **LoadMatrixC(char *);
ARB_API cmplx         **LoadMatrixCBin(char *);
ARB_API int32_t          **LoadMatrixL(char *);
ARB_API int32_t          **LoadMatrixLBin(char *);
ARB_API double       ***LoadMatrixVector(char *);
ARB_API double       ***LoadMatrixVectorBin(char *);
ARB_API int32_t            LoadMatrixVectorSize(char *);
ARB_API cmplx         **LoadMatrix1DC(char *);
ARB_API double       ***LoadMV(char *);
ARB_API int32_t            LoadMVSize(char *);
ARB_API int32_t          **LoadMVSpecs(char *);
ARB_API double        **LoadOneMatrix(FILE *);
ARB_API char         ***LoadStringMatrix(char *);
ARB_API char          **LoadStringVector(char *);
ARB_API char          **LoadStringVectorN(char *,int32_t);
ARB_API double         *LoadVector(char *);
ARB_API double         *LoadVectorBin(char *);
ARB_API cmplx          *LoadVectorC(char *);
ARB_API cmplx          *LoadVectorCBin(char *);
ARB_API int32_t           *LoadVectorL(char *);
ARB_API int32_t           *LoadVectorLBin(char *);
ARB_API double       ***LoadVectorMatrix(char *);
ARB_API double       ***LoadVectorMatrixBin(char *);
ARB_API cmplx        ***LoadVectorMatrixBinC(char *);
ARB_API cmplx        ***LoadVectorMatrixC(char *);
ARB_API void            LoadVectorMatrix1D(char *,double ****,double **);
ARB_API void            LoadVectorMatrix1DC(char *,cmplx ****,double **);
ARB_API double       ***LoadVM(char *);
ARB_API int32_t            LODE1(double *,double *,double *,double,double *);
ARB_API void            LODE1C(cmplx *,cmplx *,double *,cmplx,cmplx *,int32_t);
ARB_API cmplx           LogC(cmplx);
ARB_API cmplx           Log10C(cmplx);
ARB_API char           *IntString(int32_t);
ARB_API char           *IntStringLZ(int32_t,int32_t);
ARB_API void            IntToHSV(int32_t,double *,double *,double *);
ARB_API void            IntToRGB(int32_t,unsigned char *,unsigned char *,unsigned char *);
ARB_API void            LorentzianFit(char *,double **);
ARB_API double          LorentzianFitFunction(double,double *);
ARB_API char           *LowerCase(char *);
ARB_API int32_t           *LUDecomposition(double **);
ARB_API int32_t           *LUDecompositionC(cmplx **);
ARB_API void            LUSolve(double **,double **);
ARB_API void            LUSolveC(cmplx **,cmplx **);
ARB_API double        **Matrix(int32_t,int32_t);
ARB_API cmplx         **MatrixC(int32_t,int32_t);
ARB_API void            MatrixCopy(double **,double **);
ARB_API void            MatrixCopyC(cmplx **,cmplx **);
ARB_API void            MatrixCopyF(float **,float **);
ARB_API void            MatrixCopyI(int32_t **,int32_t **);
ARB_API void            MatrixCopyL(int32_t **,int32_t **);
ARB_API cmplx         **Matrix0C(int32_t,int32_t);
ARB_API uint32_t      **MatrixUInt32(uint32_t,uint32_t);
ARB_API float         **MatrixF(int32_t,int32_t);
ARB_API double        **MatrixFunction(double (*)(double),double **);
ARB_API double        **MatrixFunctionTridag(double (*)(double),double *,double *);
ARB_API int32_t           **MatrixI(int32_t,int32_t);
ARB_API int32_t          **MatrixL(int32_t,int32_t);
ARB_API double        **MatrixV(double *);
ARB_API cmplx         **MatrixVC(cmplx *);
ARB_API double       ***MatrixVector(int32_t);
ARB_API int32_t         ***MatrixVectorL(int32_t);
ARB_API cmplx        ***MatrixVectorC(int32_t);
ARB_API double       ***MatrixVector2D(int32_t,int32_t);
ARB_API cmplx        ***MatrixVector2DC(int32_t,int32_t);
ARB_API double        **MatrixS(double);
ARB_API double        **Matrix0(int32_t,int32_t);
ARB_API int32_t          **Matrix0L(int32_t,int32_t);
ARB_API double          Max(double *);
ARB_API double          MaxAbs(double *);
ARB_API cmplx           MaxC(cmplx *);
ARB_API float           MaxF(float *);
ARB_API int32_t             MaxI(int32_t *);
ARB_API int32_t            MaxL(int32_t *);
ARB_API double          MaxM(double **);
ARB_API double          MaxMC(cmplx **);
ARB_API int32_t            MaxML(int32_t **);
ARB_API int32_t            MaxPos(double *,int32_t,int32_t);
ARB_API int32_t            MaxPosAbs(double *,int32_t,int32_t);
ARB_API int32_t            MaxPosAbsC(cmplx *,int32_t,int32_t);
ARB_API double          MaxWindow(double *,int32_t,int32_t);
ARB_API double          Max2(double,double);
ARB_API int32_t            Max2L(int32_t,int32_t);
ARB_API double          Max3(double,double,double);
ARB_API int32_t            Max3L(int32_t,int32_t,int32_t);
ARB_API double          Mean(double *,double *,double);
ARB_API double          MeanV(double *);
ARB_API double          MeanAbs(double *);
ARB_API double          MeanAbsC(cmplx *);
ARB_API double          MeanM(double **);
ARB_API double          MeanWindow(double *,int32_t,int32_t);
ARB_API double          Median(double *);
ARB_API MEM_FILE       *MemOpen(int32_t);
ARB_API void            MemClose(MEM_FILE *);
ARB_API MEM_FILE       *MemFRead(FILE *f1); 
ARB_API void            MemWrapperClose(MEM_FILE *f);
ARB_API MEM_FILE       *MemWrapperOpen(unsigned char *bytes, uint32_t size);
ARB_API void            MemFWrite(MEM_FILE *m1, FILE *f1);
ARB_API unsigned char  *MemDump(MEM_FILE *f, uint32_t startpos, uint32_t endpos);
ARB_API unsigned char  *MemGetBufHandle(MEM_FILE *f);;
ARB_API uint32_t   MemGetBufPos(MEM_FILE *f);
ARB_API uint32_t   MemGetBufSize(MEM_FILE *f);
ARB_API size_t          MemRead(void *,size_t,size_t,MEM_FILE *); 
ARB_API void            MemSetRelativeBufPos(MEM_FILE *f, int32_t rpos);
ARB_API void            MemSetBufPos(MEM_FILE *f, uint32_t pos);
ARB_API MEM_FILE       *MemWrapperOpen(unsigned char *bytes, uint32_t size);
ARB_API size_t          MemWrite(void *,size_t,size_t,MEM_FILE *);
ARB_API uint32_t        MergeBytesToInt(unsigned char *);
ARB_API double          Metropolis1(double (*)(double *,double *),
                            double (*)(double,double *),int32_t,double *,int32_t,
                            int32_t);
ARB_API double          Min(double *);
ARB_API double          MinAbs(double *);
ARB_API double          MinC(cmplx *);
ARB_API float           MinF(float *);
ARB_API int32_t             MinI(int32_t *);
ARB_API double          MinimizeChiSquare(double **,double (*)(double,double *),
                                  double *,double,double);
ARB_API int32_t            MinL(int32_t *);
ARB_API double          MinM(double **);
ARB_API double          MinMC(cmplx **);
ARB_API int32_t            MinML(int32_t **);
ARB_API int32_t            MinPos(double *);
ARB_API int32_t            MinPosAbs(double *);
ARB_API int32_t            MinPosL(int32_t *);
ARB_API double          MinWindow(double *,int32_t,int32_t);
ARB_API double          Min2(double,double);
ARB_API int32_t            Min2L(int32_t,int32_t);
ARB_API double          Min3(double,double,double);
ARB_API int32_t            Min3L(int32_t,int32_t,int32_t);
ARB_API double          ModularExponentiation(double, double, double);
ARB_API double          Moment(double *,double *,int32_t);
ARB_API double          MomentAbsC(cmplx *,double *,int32_t);
ARB_API double          MomentAbsWindowC(cmplx *,double *,int32_t,int32_t,int32_t,double);
ARB_API int32_t            MomentD(double *,int32_t);
ARB_API int32_t            MomentDC(cmplx *,int32_t);
ARB_API double          MomentWindow(double *,double *,int32_t,int32_t,int32_t,double);
ARB_API double          MomentWindowD(double *,int32_t,int32_t,int32_t,double);
ARB_API double         *MonteCarloIntegral(double (*)(double *), double *, double *,
                                   int32_t, int32_t *);
ARB_API double          MostFrequent(double *);
ARB_API cmplx           MulC(cmplx,cmplx);
ARB_API cmplx           MulCR(cmplx,double);
ARB_API void            MulIPM(double **,double **,double **);
ARB_API void            MulIPMC(cmplx **,cmplx **,cmplx **);
ARB_API double        **MulM(double **,double **);
ARB_API double         *MulMV(double **,double *);
ARB_API double          MulVMV(double *,double **,double *);
ARB_API double         *MulVM(double *,double **);
ARB_API cmplx         **MulMC(cmplx **,cmplx **);
ARB_API cmplx           Mul3C(cmplx,cmplx,cmplx);
ARB_API int32_t             MutuallyExclusive(double,double,double,double);
ARB_API int32_t            NCols(char *);
ARB_API int32_t            NextPow(int32_t,int32_t);
ARB_API double          NewtonRaphson(double (*)(double),double,double,int32_t);
ARB_API double          NewtonRaphsonN(double (*)(double *),double *,int32_t,double,int32_t);
ARB_API double        **Niederreiter(int32_t,int32_t,int32_t *);
ARB_API void            NiederreiterCalcC2(int32_t,int32_t **);
ARB_API void            NiederreiterCalcV2(int32_t,int32_t,int32_t *,int32_t **,int32_t **,int32_t **,
                                   int32_t *,int32_t *,int32_t *);
ARB_API void            NiederreiterPlyMul2(int32_t **,int32_t **,int32_t,int32_t *,int32_t,int32_t *,
                                    int32_t *,int32_t *pc);
ARB_API void            NiederreiterSetfld2(int32_t **add,int32_t **mul,int32_t **);
ARB_API void            Niederreiter1(int32_t,int32_t *,double *);
ARB_API int32_t            NOcc(double,double *);
ARB_API int32_t            NOccL(int32_t,int32_t *);
ARB_API int32_t            NOccS(char,char *);
ARB_API int32_t            NOccWindowS(char,char *,int32_t,int32_t);
ARB_API double          Norm(double *v);
ARB_API cmplx           NormalizeC(cmplx *);
ARB_API double          NormalizeD(double **);
ARB_API double          NormalizeM(double **);
ARB_API double          NormalizeMC(cmplx **);
ARB_API double          NormalizeV(double *);
ARB_API double          NormalizeVC(cmplx *);
ARB_API double          NormalizeWindowV(double *,int32_t,int32_t);
ARB_API cmplx           NormalizeWindowVC(cmplx *,int32_t,int32_t);
ARB_API double          NormalizeVMax(double *);
ARB_API double          NormalizeVMaxC(cmplx *);
ARB_API double          NormC(cmplx *);
ARB_API double          NormWindow(double *,int32_t,int32_t);
ARB_API int32_t            NRows(char *);
ARB_API void            NumerovIntegrator(double *,double *,double *,int32_t,int32_t);
ARB_API int32_t             Odd(double);
ARB_API int32_t            OrderOfMagnitude10(double);
ARB_API int32_t            OrderOfMagnitude1000(double);
ARB_API double        **OuterP(double *,double *);
ARB_API double         *OverlapInterval(double,double,double,double);
ARB_API double          ParabolicExtremum(double,double,double,double,double,double);
ARB_API double          ParabolicInterpolation1(double *,double *,double);
ARB_API double          ParabolicInterpolation11(double *,double *,int32_t,double);
ARB_API double        **ParabolicInterpolation1D(double **,double,double,int32_t);
ARB_API char           *ParentFolder(char *,int32_t);
ARB_API double        **PartialDerivativeMixed2D(double **,double,double);
ARB_API double        **PartialDerivativeX2D(double **, double);
ARB_API double        **PartialDerivativeY2D(double **, double);
ARB_API double        **PartialDerivative2X2D(double **, double);
ARB_API double        **PartialDerivative2Y2D(double **, double);
ARB_API double         *Pascal(int32_t);
ARB_API double          Perm(int32_t,int32_t);
ARB_API double          PhaC(cmplx);
ARB_API double         *Phase(double *,int32_t);
ARB_API int32_t            PoissonRandomNumber(double, int32_t *);
ARB_API int32_t           *PoissonRandomNumbers(double, int32_t, int32_t *);
ARB_API double          PolyEval(double,double *);
ARB_API double       ***PolyFit(double **,int32_t,double,double,int32_t);
ARB_API double          PolyFitFunction(double,double *);
ARB_API void            PolynomialFit(double *,double *,double *,double *,int32_t,int32_t);
ARB_API double        **PolynomialFit2(double *,double *,double *,int32_t);
ARB_API void            PolynomialFitPhase(cmplx **,double *,int32_t,int32_t);
ARB_API double          PolynomialFitFunc(double,double *);
ARB_API int32_t            Pos(double,double *);
ARB_API int32_t            PosC(cmplx,cmplx *);
ARB_API int32_t            PosS(char *,char **);
ARB_API double        **PositiveDomain(double **);
ARB_API cmplx         **PositiveDomainC(cmplx **);
ARB_API int32_t            PosL(int32_t,int32_t *);
ARB_API cmplx           PowC(cmplx,cmplx);
ARB_API cmplx           PowCR(cmplx,double);
ARB_API cmplx           PowIR(double,double);
ARB_API double          PowerMethod(double **,double *,int32_t);
ARB_API cmplx           PowerMethodC(cmplx **,cmplx *,int32_t);
ARB_API double        **PowM(double **,int32_t);
ARB_API cmplx         **PowMC(cmplx **,int32_t);
ARB_API cmplx           PowRC(double,cmplx);
ARB_API cmplx           PowRR(double,double);
ARB_API double          PrimeCount(double,int32_t);
ARB_API double        **PrimeFactorsSmall(double,double *);
ARB_API double        **PrimeFactors2(double, char *);
ARB_API int32_t            PrimeNumber(int32_t);
ARB_API double         *PrimeNumbers(double,char *);
ARB_API double         *PrimeNumbersRange(double, double, char *);
ARB_API void            PrimeNumbersSieve(double,uint64_t,uint64_t ,bit_array *,
                                  double **);
ARB_API double         *PrimeNumbersSmall(double);
ARB_API void            PrimeNumbersSub(double,uint64_t,uint64_t,bit_array *,uint64_t *,
                                double **);
ARB_API double          PrimitiveRootPrime(double, char *);
ARB_API void            Print(double);
ARB_API char           *PrintBitArray(bit_array*);
ARB_API char           *PrintBitArrayFloat(bit_array_float*);
ARB_API void            PrintC(cmplx);
ARB_API void            PrintF(float);
ARB_API void            PrintI(int32_t);
ARB_API void            PrintL(int32_t);
ARB_API void            PrintMatrix(double **);
ARB_API void            PrintMatrixC(cmplx **);
ARB_API void            PrintMatrixF(float **);
ARB_API void            PrintMatrixI(int32_t **);
ARB_API void            PrintMatrixL(int32_t **);
ARB_API void            PrintMatrixVector(double ***);
ARB_API void            PrintMatrixVectorC(cmplx ***);
ARB_API void            PrintNL(void);
ARB_API void            PrintS(char *);
ARB_API void            PrintStringMatrixVector(char ****);
ARB_API void            PrintStringVector(char **);
ARB_API void            PrintStringVectorArray(char ***);
ARB_API void            PrintVector(double *);
ARB_API void            PrintVectorC(cmplx *);
ARB_API void            PrintVectorF(float *);
ARB_API void            PrintVectorI(int32_t *);
ARB_API void            PrintVectorL(int32_t *);
ARB_API double          Product(double (*)(double),int32_t,int32_t,int32_t);
ARB_API cmplx           ProductC(cmplx (*)(double),int32_t,int32_t,int32_t);
ARB_API double          ProductP(double (*)(double *),double *,int32_t,int32_t,int32_t);
ARB_API double        **ProximalInterpolationM(double **,int32_t,int32_t);
ARB_API cmplx          *QRAlgorithm(double **);
ARB_API cmplx        ***QRAlgorithm2(double **);
ARB_API void            QRBalance(double **);
ARB_API double         *QRBalance2(double **);
ARB_API void            QRHessenberg(double **);
ARB_API int32_t           *QRHessenberg2(double **,double **);
ARB_API void            QRSortVecs(double **,cmplx *);
ARB_API double          QuarterCircleFunc(double);
ARB_API double          Ran2(int32_t *);
ARB_API double          Ran2P(int32_t *);
ARB_API double          Ran2P2(int32_t *, int32_t, int32_t, int32_t *);
ARB_API double          Ran22(int32_t *,int32_t *,int32_t *,int32_t *);
ARB_API int32_t            RandomInteger(int32_t,int32_t,int32_t *);
ARB_API int32_t         RandomIntegerP(int32_t,int32_t,int32_t *);
ARB_API int32_t            RandomInteger2(int32_t,int32_t,int32_t *,int32_t *,int32_t *,int32_t *);
ARB_API void            RandomizeMatrix(double **,double,double,int32_t *);
ARB_API void            RandomizeMatrixC(cmplx **,double,double,int32_t *);
ARB_API void            RandomizeVector(double *,double,double,int32_t *);
ARB_API void            RandomizeVectorC(cmplx *,double,double,int32_t *);
ARB_API char*           RandomPrintableString(int32_t size, int32_t* seed);
ARB_API double          RandomReal(double,double,int32_t *);
ARB_API double          RandomRealNormal(double,double,int32_t *);
ARB_API char           *RandomString(int32_t,int32_t *);
ARB_API char           *RandomStringAlphaNum(int32_t,int32_t *);
ARB_API void            RandomStringAlphaNumIP(int32_t ,int32_t *,char *);
ARB_API void            RandomStringAlphaNumIP2(int32_t,int32_t *,int32_t *,int32_t *,int32_t *,
                                        char *);
ARB_API char           *RandomStringAlphaNumP(int32_t,int32_t *);
ARB_API char           *RandomStringBracketed(char *, char *, int32_t *);
ARB_API char           *RandomStringBracketedExtASCII(char *,char *,int32_t *);
ARB_API char           *RandomStringExtASCII(int32_t,int32_t *);
ARB_API double          Range(double *);
ARB_API double          Re(cmplx);
ARB_API void           *ReadMemFile(void *f, stream_type st);
ARB_API double        **ReM(cmplx **);
ARB_API double         *ReV(cmplx *);
ARB_API cmplx           RealC(double);
ARB_API cmplx         **RealMC(double **);
ARB_API cmplx          *RealVC(double *);
ARB_API cmplx        ***RealVMC(double ***);
ARB_API double        **ReferenceDomain(double *,double *);
ARB_API char           *RemoveCharacters(char *, char **);
ARB_API char           *RemoveCharacter(char,char **);
ARB_API void            RemoveCol(int32_t,double ***);
ARB_API void            RemoveColS(int32_t,char  ****);
ARB_API double          RemoveDC(double *);
ARB_API cmplx           RemoveDCC(cmplx *);
ARB_API double          RemoveDCWindow(double *,int32_t,int32_t);
ARB_API void            RemoveDuplicateCols(double ***,char *);
ARB_API void            RemoveDuplicateColsS(char ****,char *);
ARB_API void            RemoveDuplicateRows(double ***,char *);
ARB_API void            RemoveDuplicates(double **,char *);
ARB_API void            RemoveDuplicatesSorted(double **);
ARB_API void            RemoveDuplicateStrings(char ***,char *);
ARB_API void            RemoveElement(double,double **);
ARB_API void            RemoveElements(double *,double **);
ARB_API void            RemoveElementsL(int32_t *,int32_t **);
ARB_API double          RemoveLinearPhase(cmplx *);
ARB_API double          RemovePosition(int32_t,double **);
ARB_API char           *RemovePositionCh(int32_t,char **);
ARB_API int32_t            RemovePositionL(int32_t,int32_t **);
ARB_API void            RemovePositions(int32_t *,double **);
ARB_API char           *RemovePositionS(int32_t,char ***);
ARB_API char           *RemovePositionsC(int32_t *, char **);
ARB_API char         ***RemovePositionSM(int32_t,char *****);
ARB_API void            RemovePositionsS(int32_t *,char ***);
ARB_API int32_t            RemovePositionUInt32(int32_t, uint32_t **);
ARB_API void            RemoveElementL(int32_t,int32_t **);
ARB_API double         *RemoveRow(int32_t,double ***);
ARB_API void            RemoveRows(int32_t *,double ***);
ARB_API char          **RemoveRowS(int32_t,char ****);
ARB_API void            ReorderMV(double ****,int32_t *);
ARB_API void            ReorderV(double **,int32_t *);
ARB_API void            ReverseS(char *);
ARB_API void            ReverseV(double *);
ARB_API void            ReverseVC(cmplx *);
ARB_API uint32_t        RGBToint(unsigned char,unsigned char,unsigned char);
ARB_API void            RGBToHSV(double,double,double,double *,double *,double *);
ARB_API uint32_t        RightRotate32(uint32_t,int32_t);
ARB_API uint64_t        RightRotate64(uint64_t,int64_t);
ARB_API double        **RKN(void (*)(double,double *,double *,double *),double,
                    double *,double *,double,int32_t);
ARB_API double        **RK1(double (*)(double,double),double,double,double,int32_t);
ARB_API double        **RK2(double (*)(double,double,double),double,double,double,
                    double,int32_t);
ARB_API double          Round(double);
ARB_API char           *RoundDoubleString(char **,int32_t);
ARB_API void            RoundDoubleStringWithSpacePadding(char* ds, int32_t nd);
ARB_API double         *Row(double **,int32_t);
ARB_API void            RungeKutta(double (*)(double,double,double),double,double,
                           double,double,double *,double *,int32_t);
ARB_API void            RungeKuttaN(void (*)(double,double *,double *,double *),double,
                            double *,double *,double,double *,double *,int32_t);
ARB_API double          RungeKuttaIntegral1D(void (*)(double,double *,double *),double,
                                     double);
ARB_API double        **RungeKuttaIntegrator(double *,double,double,int32_t,double,double,
                                     double,double,int32_t *,int32_t *,
                                     void (*)(double,double *,double *));
ARB_API void            RungeKuttaCashKarp(double *,double *,double,double,double *,
                                   double *,void (*)(double,double *,double *));
ARB_API void            RungeKuttaStep(double *,double *,double *,double,double,double,
                               double *,double *,double *,
                               void (*)(double,double *,double *));
ARB_API cmplx           RungeKuttaIntegral1DC(void (*)(double,cmplx *,cmplx *),double,
                                      double);
ARB_API cmplx         **RungeKuttaIntegratorC(cmplx *,double,double,int32_t,double,double,
                                      double,double,int32_t *,int32_t *,
                                      void (*)(double,cmplx *,cmplx *));
ARB_API void            RungeKuttaCashKarpC(cmplx *,cmplx *,double,double,cmplx *,
                                    cmplx *,void (*)(double,cmplx *,cmplx *));
ARB_API void            RungeKuttaStepC(cmplx *,cmplx *,double *,double,double,double,
                                double *,double *,double *,
                                void (*)(double,cmplx *,cmplx *));
ARB_API double        **RungeKuttaSampler(double *,double,double,double,double,double,
                                  double,int32_t *,int32_t *,
                                  void (*)(double,double *,double *));
ARB_API cmplx         **RungeKuttaSamplerC(cmplx *,double,double,double,double,double,
                                   double,int32_t *,int32_t *,
                                   void (*)(double,cmplx *,cmplx *));
ARB_API char           *SaltedHash(char *,int32_t *);
ARB_API char           *SaltFromHash(char *);
ARB_API double        **SavitzkyGolay(double *,double *,int32_t,int32_t,int32_t,int32_t);
ARB_API double         *SavitzkyGolayCoefficients(int32_t,int32_t,int32_t,int32_t);
ARB_API double       ***ScalarField2D(double **,double *,double *);
ARB_API int32_t            SeedFrom4Bytes(MEM_FILE *,unsigned char *,int32_t);
ARB_API int32_t            SeedFrom4String(char *,int32_t);
ARB_API int32_t            SeedFromByteArray(MEM_FILE *,int32_t,int32_t,int32_t);
ARB_API int32_t            SeedFromString(char *);
ARB_API int32_t         SeedFromStringP(char *);
ARB_API char           *SHA256(char *);
ARB_API char           *SHA512(char *);
ARB_API char           *SHA512Base64(char *, char *, char);
ARB_API char           *SHA512FromByteArray(unsigned char*, uint64_t);
ARB_API void            Shift(double *,int32_t);
ARB_API void            ShiftC(cmplx *,int32_t);
ARB_API void            ShiftCol(double **,int32_t);
ARB_API void            ShiftColC(cmplx **,int32_t);
ARB_API void            ShiftCont(double **,double);
ARB_API void            ShiftCont1DC(cmplx **,double);
ARB_API void            ShiftRow(double **,int32_t);
ARB_API void            ShiftRowC(cmplx **,int32_t);
ARB_API void            Shift0C(cmplx *,int32_t);
ARB_API double          Sign(double);
ARB_API double          SimpsonIntegralAdaptive(double (*)(double),double,double,
                                        double);
ARB_API double          SimpsonIntegralAdaptiveSub(double (*)(double),double,double,
                                           double,double,double,double,double);
ARB_API double          SimpsonIntegalSphericalCS3D(double ***,double *,double *,double,
                                            double,double,double);
ARB_API double          SimpsonIntegalSpherical3D(double ***,double *,double *,
                                          double *,double,double,double,double,
                                          double,double);
ARB_API double          SimpsonIntegral1(double, double, double, double, double);
ARB_API double          SimpsonIntegral1D(double *,double *,double,double);
ARB_API cmplx           SimpsonIntegral1DC(cmplx *,double *,double,double);
ARB_API void            SimulatedAnnealing(double (*)(double *),double *,double **,
                                   double *,int32_t *);
ARB_API cmplx           SinC(cmplx);
ARB_API double          SincFunc(double);
ARB_API cmplx           SinhC(cmplx);
ARB_API char           *SmileyHash(char **, int32_t);
ARB_API char           *SmileyHexHash(char **,int32_t);
ARB_API void            SmoothFFT(cmplx **,int32_t,int32_t);
ARB_API void            SmoothFFTV(cmplx *,int32_t,int32_t);
ARB_API void            SmoothSpline(double *,double *,int32_t);
ARB_API void            SmoothSplinePolar1DC(cmplx *,double *,int32_t);
ARB_API void            SmoothSplineRectangular1DC(cmplx *,double *,int32_t);
ARB_API double          SmoothSquareFunc(double,double,double,double);
ARB_API cmplx           SmoothSquareFuncC(double,double,double,double);
ARB_API double          SmoothSquareFunc2D(double,double,double,double,double,double,
                                   double,double);
ARB_API double          SmoothStepFunc(double);
ARB_API void            Sort(double *);
ARB_API void            SortL(int32_t *);
ARB_API void            SortMatrix(double **,int32_t,int32_t,int32_t);
ARB_API void            SortMatrixL(int32_t **,int32_t,int32_t,int32_t);
ARB_API void            SortMatrixCols(double **,double *);
ARB_API void            SortMatrixColsC(cmplx **,double *);
ARB_API void            SortMatrixRows(double **,double *);
ARB_API void            SortMatrixUInt32(uint32_t **, int32_t, int32_t, int32_t);
ARB_API void            SortMatrixVector(double ***,double *);
ARB_API void            SortMatrix1DC(cmplx **);
ARB_API void            SortStringMatrix(char ****,int32_t,int32_t,int32_t);
ARB_API void            SortStringVector(char ***);
ARB_API void            SortStringVectorRef(char ***,double *);
ARB_API char          **SortStringVectorSizes(char ***);
ARB_API double        **Spectrum(cmplx **);
ARB_API cmplx           SphericalHarmonic(double,double,int32_t,int32_t);
ARB_API double        **SplineInterpolation(double **,double,double,int32_t);
ARB_API double        **SplineInterpolationCols(double **,int32_t);
ARB_API void            SplineInterpolationPts(double *,double *,double *,double *);
ARB_API double         *SplineInterpolationV(double *,int32_t);
ARB_API cmplx         **SplineInterpolation1DC(cmplx **,double,double,int32_t);
ARB_API double       ***SplineInterpolation2D(double ***,int32_t,int32_t);
ARB_API void            SplitIntToBytes(uint32_t,unsigned char *);
ARB_API void            SplitShortToBytes(short,unsigned char *);
ARB_API double          Sqr(double);
ARB_API cmplx           SqrC(cmplx);
ARB_API double          Sqrt(double);
ARB_API cmplx           SqrtC(cmplx);
ARB_API double          SquareFunc(double);
ARB_API double          StandardDeviation(double *,double *,double);
ARB_API double          StandardDeviationV(double *);
ARB_API cmplx        ***STFT(cmplx **,double **,double,double,int32_t);
ARB_API void           *StrDup(void *);
ARB_API char           *StringChar(char);
ARB_API int32_t            StringCols(char *);
ARB_API char         ***StringCombinations(char **, int32_t, char *);
ARB_API char           *StringEncoding(int32_t,char *);
ARB_API char           *StringInit(int32_t);
ARB_API char         ***StringMatrix(int32_t,int32_t);
ARB_API int32_t            StringMatrixCols(char ***);
ARB_API int32_t            StringMatrixRows(char ***);
ARB_API char        ****StringMatrixVector(int32_t);
ARB_API int32_t            StringMatrixVectorLength(char ****);
ARB_API char         ***StringPermutations(char **, int32_t, char *);
ARB_API int32_t            StringRows(char *);
ARB_API char           *StringSV(char **);
ARB_API unsigned char  *StringToByteArray(char *,int32_t *);
ARB_API char          **StringTokens(char *, char *);
ARB_API char          **StringTokensS(char *, char *);
ARB_API int32_t           *StringToVectorL(char *);
ARB_API char          **StringVector(int32_t);
ARB_API char          **StringVectorNULL(int32_t);
ARB_API char          **StringVector2(char *, char *);
ARB_API char          **StringVector3(char *,char *,char *);
ARB_API int32_t            StringVectorLength(char **);
ARB_API char           *StrStr(char *, char *);
ARB_API char           *StrTokR(char *, const char *, char **);
ARB_API double          StudentCriticalValue(double,double);
ARB_API double          StudentPValue(double,double);
ARB_API cmplx           SubC(cmplx,cmplx);
ARB_API double        **SubM(double **,double **);
ARB_API cmplx         **SubMC(cmplx **,cmplx **);
ARB_API char           *SubstituteString(char **,char *,char *);
ARB_API char           *SubstituteStringEqualSizes(char **,char *,char *);
ARB_API double         *SubV(double *,double *);
ARB_API cmplx          *SubVC(cmplx *,cmplx *);
ARB_API double          Summation(double (*)(double),int32_t,int32_t,int32_t);
ARB_API double          SummationP(double (*)(double *),double *,int32_t,int32_t,int32_t);
ARB_API cmplx           SummationC(cmplx (*)(double),int32_t,int32_t,int32_t);
ARB_API double          SuperGaussianFilter(double,double,double,double);
ARB_API double       ***SVD(double **);
ARB_API double          SVDPythag(double,double);
ARB_API void            Swap(double *,double *);
ARB_API void            SwapC(cmplx *,cmplx *);
ARB_API void            SwapCols(double **,int32_t,int32_t);
ARB_API void            SwapColsC(cmplx **,int32_t,int32_t);
ARB_API void            SwapL(int32_t *,int32_t *);
ARB_API void            SwapRows(double **,int32_t,int32_t);
ARB_API void            SwapRowsC(cmplx **,int32_t,int32_t);
ARB_API void            SwapRowsL(int32_t **,int32_t,int32_t);
ARB_API double        **SymmetricDifferenceM(double **,double **);
ARB_API double         *SymmetricDifferenceV(double *,double *);
ARB_API double         *SymmetrizeTridiagonalMatrix(double *,double *,double *);
ARB_API cmplx           TanC(cmplx);
ARB_API cmplx           TanhC(cmplx);
ARB_API int32_t         TestAgainstSaltedHash(char *,char *);
ARB_API int32_t         TestElementS(char *,char **);
ARB_API int32_t         TestPrimeFactors(double, double **,int32_t);
ARB_API char            TestValidUTF8String(char* input);
ARB_API double          TimeBandwidthProduct(cmplx **);
ARB_API double          TimeBandwidthProductSpectrum(double **,double);
ARB_API double          ToothFunc(double);
ARB_API char           *TrailingCharacters(char **,char,char,int32_t);
ARB_API double        **Transpose(double **);
ARB_API cmplx         **TransposeC(cmplx **);
ARB_API void            TransposeIPC(cmplx **,cmplx **);
ARB_API void            TransposeIP(double **,double **);
ARB_API void            TransposeSquareIPC(cmplx **);
ARB_API void            TransposeSquareIP(double **);
ARB_API double          TrapezoidIntegral(double *,double *,int32_t,int32_t);
ARB_API cmplx           TrapezoidIntegralC(cmplx *,cmplx *,int32_t,int32_t);
ARB_API double          TrapezoidIntegral1D(double *,double *,double,double);
ARB_API double          TriangleFunc(double);
ARB_API void            TriagonalEigenDecomposition(double *,double *,double **);
ARB_API void            TriagonalEigenValues(double *,double *);
ARB_API double        **TriDiagonalMatrix(double *,double *,double *);
ARB_API cmplx         **TriDiagonalMatrixC(cmplx *,cmplx *,cmplx *);
ARB_API void            TriDiagSolve(double *,double *,double *,double *,double *);
ARB_API void            TriDiagSolveC(cmplx *,cmplx *,cmplx *,cmplx *,cmplx *);
ARB_API uint64_t        UInt64FromString(char *);
ARB_API char           *UInt64String(uint64_t);
ARB_API uint32_t        UnicodeBytesToInteger(unsigned char *);
ARB_API void            UniformScale(double **);
ARB_API double        **UnionM(double **,double **,char *);
ARB_API double         *UnionV(double *,double *,char *);
ARB_API double         *UnitV(double *);
ARB_API cmplx          *UnitVC(cmplx *);
ARB_API double          UnityFunc(double);
ARB_API cmplx           UnityFunc1DC(double);
ARB_API void            UnwrapM(double **,double);
ARB_API void            UnwrapV(double *,double);
ARB_API void            UnwrapVWindow(double *,double,int32_t,int32_t);
ARB_API char           *UpperCase(char *);
ARB_API double         *Vector(int32_t);
ARB_API cmplx          *VectorC(int32_t);
ARB_API void            VectorCopy(double *,double *);
ARB_API void            VectorCopyC(cmplx *,cmplx *);
ARB_API void            VectorCopyF(float *,float *);
ARB_API void            VectorCopyI(int32_t *,int32_t *);
ARB_API void            VectorCopyL(int32_t *,int32_t *);
ARB_API float          *VectorF(int32_t);
ARB_API int32_t            *VectorI(int32_t);
ARB_API int32_t           *VectorL(int32_t);
ARB_API double       ***VectorMatrix(int32_t,int32_t,int32_t);
ARB_API cmplx        ***VectorMatrixC(int32_t,int32_t,int32_t);
ARB_API double       ***VectorMatrix0(int32_t,int32_t,int32_t);
ARB_API double         *VectorS(double);
ARB_API void            VectorToByteArrayL(int32_t *,unsigned char *,int32_t);
ARB_API void            VectorToByteArrayUInt32(uint32_t *, unsigned char *, int32_t);
ARB_API char           *VectorToStringL(int32_t *);
ARB_API uint32_t       *VectorUInt32(int32_t );
ARB_API double         *Vector0(int32_t);
ARB_API cmplx          *Vector0C(int32_t);
ARB_API int32_t           *Vector0L(int32_t);
ARB_API int32_t           *Vector1L(int32_t);
ARB_API double         *Vector2(double,double);
ARB_API double         *Vector3(double,double,double);
ARB_API int32_t           *Vector3L(int32_t,int32_t,int32_t);
ARB_API double         *Vector6(double,double,double,double,double,double);
ARB_API int32_t           *Vector7L(int32_t,int32_t,int32_t,int32_t,int32_t,int32_t,int32_t);
ARB_API double         *VonNeumannRejection(double (*)(double), double, double, double,
                                    int32_t, int32_t *);
ARB_API double 		      WeightedMean(double *,double *);
ARB_API double 		      WeightedMeanWindow(double *,double *,int32_t,int32_t);
ARB_API double       ***WignerDistribution(cmplx **,int32_t);
ARB_API double          Wigner3J(double,double,double,double,double,double);
ARB_API double        **Wigner3JSymbols(double,double,double,double);
ARB_API double          Wigner3JSymbolSpecial1(double,double,double);
ARB_API double          Wigner3JSymbolSpecial2(double,double,double);
ARB_API void            Wigner3JSymbolsSpecial(double,double,double *,double *);
ARB_API double          Wrap(double,double);
ARB_API void            Write(char *,double);
ARB_API void            WriteByteArray(char *,unsigned char *,int32_t);
ARB_API void            WriteMemFile(void *val, void *f, stream_type st);
ARB_API void            WriteMV(char *,double ***);
ARB_API void            WriteMatrix(char *, double **);
ARB_API void            WriteMatrixUInt32(char *,uint32_t **);
ARB_API void            WriteMatrixAbsC(char *,cmplx **);
ARB_API void            WriteMatrixBin(char *,double **);
ARB_API void            WriteMatrixC(char *,cmplx **);
ARB_API void            WriteMatrixCBin(char *,cmplx **);
ARB_API void            WriteMatrixF(char *,float **);
ARB_API void            WriteMatrixI(char *,int32_t **);
ARB_API void            WriteMatrixL(char *,int32_t **);
ARB_API void            WriteMatrixLBin(char *,int32_t **);
ARB_API void            WriteMatrixVector(char *,double ***);
ARB_API void            WriteMatrixVectorBin(char *,double ***);
ARB_API void            WriteMatrixVectorC(char *,cmplx ***);
ARB_API void            WriteMatrixVectorFiles(char *,double ***);
ARB_API void            WriteMatrixVectorL(char *,int32_t ***);
ARB_API void            WriteMatrix1DC(char *,cmplx **);
ARB_API void            WriteMatrix1DCErr(char *,cmplx **,cmplx *);
ARB_API void            WriteOneMatrix(FILE *,double **);
ARB_API void            WriteS(FILE *,char *);
ARB_API void            WriteString(char *,char *);
ARB_API void            WriteStringMatrix(char *,char ***);
ARB_API void            WriteStringVector(char *,char **);
ARB_API void            WriteVector(char *,double *);
ARB_API void            WriteVectorAbsC(char *,cmplx *);
ARB_API void            WriteVectorBin(char *,double *);
ARB_API void            WriteVectorC(char *, cmplx *);
ARB_API void            WriteVectorCBin(char *,cmplx *);
ARB_API void            WriteVectorF(char *,float *);
ARB_API void            WriteVectorI(char *,int32_t *);
ARB_API void            WriteVectorL(char *,int32_t *);
ARB_API void            WriteVectorLBin(char *,int32_t *);
ARB_API void            WriteVectorMatrix(char *,double ***);
ARB_API void            WriteVectorMatrixC(char *,cmplx ***);
ARB_API void            WriteVectorMatrixBin(char *,double ***);
ARB_API void            WriteVectorMatrixBinC(char *,cmplx ***);
ARB_API void            WriteVectorMatrix1D(char *,double ***,double *);
ARB_API void            WriteVectorMatrix1DC(char *,cmplx ***,double *);
ARB_API void            WriteVM(char *,double ***);
ARB_API double          ZeroEndPoints(double **);
ARB_API double          ZeroFunc(double);
ARB_API cmplx           ZeroFunc1DC(double);
ARB_API cmplx         **ZeroPadFFT(cmplx **,int32_t);
ARB_API cmplx          *ZeroPadVC(cmplx *,int32_t);
ARB_API double        **ZeroPad1D(double **,int32_t);
ARB_API cmplx         **ZeroPad1DC(cmplx **,int32_t);

extern int32_t arb_counter;
extern int32_t prime_numbers[2048];


#endif // ARB_H
