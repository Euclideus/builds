#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#ifndef ARBEVAL8_H
#define ARBEVAL8_H

#include <red_black_tree.h>
#include <doubly_linked_list.h>
#include <math.h>
#include <memfile.h>

#if defined(_WIN32) || defined(_WIN64)
#define ARBEVAL_EXPORTS 1
#ifdef ARBEVAL_EXPORTS
#define ARBEVAL_API __declspec(dllexport)
#else
#define ARBEVAL_API __declspec(dllimport)
#endif
#else
#define ARBEVAL_API
#endif

#define WINDOWS_DESKTOP_PLATFORM_CODE 65536
#define APPLE_DESKTOP_PLATFORM_CODE 65537
#define UNIX_DESKTOP_PLATFORM_CODE 65538
#define NO_PLATFORM_CODE 666666

typedef struct arbeval_globals_container arbeval_globals_container;

typedef struct arbenv arbenv;

extern arbeval_globals_container *arbeval_globals;

ARBEVAL_API char *GetLocalPath();
ARBEVAL_API char *GetLocalOutPath();
ARBEVAL_API void SetPlatformCode(int32_t platcode);
ARBEVAL_API void SetLocalPath(char *lpath);
ARBEVAL_API void SetLocalOutPath(char *lpath);
ARBEVAL_API void SetInstructions(char *init,int32_t isFile);
ARBEVAL_API void SetGraphingInstructions(char *init,int32_t isFile);
ARBEVAL_API void SetFourierInstructions(char *init,int32_t isFile);
ARBEVAL_API void SetProgrammingInstructions(char *init,int32_t isFile);
ARBEVAL_API void SetInitScript(char *init,int32_t isFile);
ARBEVAL_API char *ConstructReadObjectAssignmentFromFile(char *fname_s);
ARBEVAL_API void AddEnvironment(arbenv *state,arbenv *ae,int32_t overwrite);
ARBEVAL_API char *EnvironmentHistoryToString(arbenv *ae);
ARBEVAL_API char **EnvironmentHistoryElementsToStringVector(arbenv *ae,char io);
ARBEVAL_API void ClearEnvironmentHistoryEntry(arbenv *ae,int32_t eind);
ARBEVAL_API void ClearEnvironmentHistory(arbenv *ae);
ARBEVAL_API void WriteSettingsHeader(FILE *ff,char *hname,double version);
ARBEVAL_API void WriteSettingsHeaderToStream(void *ff,double version,stream_type st);
ARBEVAL_API rbtree *LoadFontFromStream(MEM_FILE *file);
ARBEVAL_API int32_t TestWhitespaceExpression(char *expr);
ARBEVAL_API void AppendHistoryItem(arbenv *ae,char *in,char *out);
ARBEVAL_API void SetLastHistoryItemOutput(arbenv *ae,char *out);
ARBEVAL_API unsigned char *DummyBitmap(int32_t cols,int32_t rows);
ARBEVAL_API uint32_t **LoadBitmapToRGBMatrix(char *fname);
ARBEVAL_API  uint32_t **DownSampleRGBMatrix(uint32_t **rgbmat,int32_t dsfact);
ARBEVAL_API void RemoveHistoryItem(arbenv *ae,int32_t indx);
ARBEVAL_API char SetUpdateHistoryFlag(arbenv *ae,char val);
ARBEVAL_API size_t EnvironmentSize();
ARBEVAL_API int32_t AtoL(char *nums);
ARBEVAL_API double AtoF(char *nums);
ARBEVAL_API int32_t TestNumericString(char *,double *val);
ARBEVAL_API void FreeString(void *val);
ARBEVAL_API char **GetPredefinedFunctionInfo(char *flabel);
ARBEVAL_API char **GetEnvironmentFunctionInfo(char *flabel);
ARBEVAL_API char **GetProgrammingCommandInfo(char *flabel);
ARBEVAL_API arbenv *InitializeTopLevelEnvironment(int32_t defaults);
ARBEVAL_API void SetEnvironmentSeed(int32_t seed,arbenv *ae);
ARBEVAL_API void TerminateEnvironment(arbenv *ae);
ARBEVAL_API void *copyArbenv(void *v);
ARBEVAL_API void freeArbenv(void *ae);
ARBEVAL_API void writeArbenv(void *v,void *f,stream_type st);
ARBEVAL_API char *FormatRBST(char **sin,int32_t expand,int32_t sd,arbenv *ae);
ARBEVAL_API void *readTopArbenv(void *f,stream_type st);
ARBEVAL_API char *ArbevalScript(char *script1,arbenv *ae,int32_t delete_literal_objects);
ARBEVAL_API char *RestoreDefaultAssignments(arbenv *ae,int32_t delete_lits);
ARBEVAL_API char *PrintTopLevelEnvironment(arbenv *ae,int32_t indent,int32_t print_gen);
ARBEVAL_API void TerminateGlobals(void);
ARBEVAL_API void InitializeGlobals(char *init,int32_t init_is_file);
ARBEVAL_API void ReinitializeHistory(arbenv *ae);
ARBEVAL_API void HistoryIteratorSeekEnd(arbenv *ae);
ARBEVAL_API dl_list *GetHistory(arbenv *ae);
ARBEVAL_API double SettingsFileVersionCode(char *fname,size_t offset);
ARBEVAL_API double SettingsFileVersionCodeFromStream(void *f1,stream_type st);
ARBEVAL_API char *Instructions(void);
ARBEVAL_API char *InstructionsGraphing(void);
ARBEVAL_API char *InstructionsProgramming(void);
ARBEVAL_API char *InstructionsFourier(void);
ARBEVAL_API char *About(void);
ARBEVAL_API int32_t GetSignificantDigits(arbenv *ae);
ARBEVAL_API int32_t GetCancelFlag(arbenv *ae);
ARBEVAL_API void SetSignificantDigits(arbenv *ae,int32_t nsig);
ARBEVAL_API void SetCancelFlag(arbenv *ae,char val);
ARBEVAL_API arbenv *CopyEnvironment(arbenv *source,arbenv *outer,
  int32_t cpyhist,int32_t ischild);
ARBEVAL_API void SetSeed(arbenv *ae,int32_t val);
ARBEVAL_API char *ReadFileToString(char *path);
ARBEVAL_API double GetEnvironmentVersion();
ARBEVAL_API char **GetPredefinedFunctionLabels();
ARBEVAL_API char **GetEnvironmentFunctionLabels();
ARBEVAL_API char **GetProgrammingCommandLabels();
ARBEVAL_API int32_t GetProgrammingCommandListSize();
ARBEVAL_API int32_t GetPredefinedFunctionListSize();
ARBEVAL_API int32_t GetEnvironmentFunctionListSize();
ARBEVAL_API void ExportTopLevelEnv(arbenv *ae,MEM_FILE *m1);
ARBEVAL_API void ImportTopLevelEnvironment(MEM_FILE *m1,arbenv *ae);


ARBEVAL_API unsigned char **GeneratePlotBitmaps(char *expr,double xmin,double xmax,uint32_t nx,
  cmplx *ymin,cmplx *ymax,
  uint32_t dimx,uint32_t dimy,rbtree *font,
  arbenv *ae);
ARBEVAL_API unsigned char *GenerateParametricPlotBitmap(char *expr11,double tmin,
  double tmax,int32_t nt,cmplx ymin,
  cmplx ymax,uint32_t dimx,
  uint32_t dimy,rbtree *font,
  arbenv *ae);
ARBEVAL_API unsigned char **GenerateFourierPlotBitmaps(char *expr11,double xmin,double xmax,int32_t pow2,
  cmplx yminsig,cmplx ymaxsig,cmplx yminspec,cmplx ymaxspec,
  uint32_t dimx,uint32_t dimy,
  double ***ft,char **dnames,
  rbtree *font,arbenv *ae);
ARBEVAL_API unsigned char **GenerateSpectrallyFilteredPlotBitmaps(char *expr11,
  double **tf1d1,
  double xmin,double xmax,uint32_t dimx,
  cmplx ymin,cmplx ymax,
  uint32_t dimy,
  rbtree *font,arbenv *ae);
ARBEVAL_API unsigned char **GeneratePlotBitmaps2D(char *expr11,double xmin,double xmax,
  double ymin,double ymax,uint32_t dimx,
  uint32_t dimy,uint32_t nx,uint32_t ny,rbtree *font,
  arbenv *ae);
ARBEVAL_API unsigned char **GeneratePlotBitmapsComplex(char *expr11,double xmin,
  double xmax,double ymin,double ymax,uint32_t dimx,
  uint32_t dimy,uint32_t nx,uint32_t ny,
  rbtree *font,arbenv *ae);
ARBEVAL_API rbtree *LoadFontFromFile(char *file);
ARBEVAL_API void FreeFont(rbtree *font);
ARBEVAL_API void writeRBNodeValueBitmap(void *val,void *f,stream_type st);
ARBEVAL_API void *copyRBNodeValueBitmap(void *v);
ARBEVAL_API void *readRBNodeValueBitmap(void *f,stream_type st);
ARBEVAL_API void freeRBNodeValueBitmap(void *v);
ARBEVAL_API unsigned char *getBitmap(char *key,rbtree *rbt);


#endif // ARBEVAL8_H
