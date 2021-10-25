#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#ifndef ARBTREE_H
#define ARBTREE_H

#include <arb.h>
#include <red_black_tree.h>

#if defined(_WIN32) || defined(_WIN64)
#define ARBTREE_EXPORTS 1
#ifdef ARBTREE_EXPORTS
#define ARBTREE_API __declspec(dllexport)
#else
#define ARBTREE_API __declspec(dllimport)
#endif
#else
#define ARBTREE_API
#endif

typedef struct generic_value generic_value;
typedef struct utility_functions utility_functions;
typedef struct generic_value generic_value;

typedef void (*free_func)(void *);
typedef void (*write_func)(void *,void *f,stream_type st);
typedef void *(*read_func)(void *f,stream_type st);
typedef void *(*copy_func)(void *);

free_func arbFree(char *type);
read_func arbRead(char *type);
write_func arbWrite(char *type);
copy_func arbCopy(char *type);

ARBTREE_API void insertArbNode(rbtree *rbt,char *key,void *val,char *type);
ARBTREE_API generic_value *initializeGenericValue(void *val, char *type);
ARBTREE_API void initializeArbTreeTypeMap(void);
ARBTREE_API void terminateArbTreeTypeMap(void);
ARBTREE_API rbtree *initializeArbTree(void);
ARBTREE_API double *getDecimal(char *key,rbtree *rbt);
ARBTREE_API cmplx *getComplex(char *key,rbtree *rbt);
ARBTREE_API int32_t *getInteger(char *key,rbtree *rbt);
ARBTREE_API int32_t getNull(char *key, rbtree *rbt);
ARBTREE_API char *getString(char *key,rbtree *rbt);
ARBTREE_API MEM_FILE *getByteArray(char *key,rbtree *rbt);
ARBTREE_API char **getStringArray(char *key,rbtree *rbt);
ARBTREE_API double **getMatrix(char *key,rbtree *rbt);
ARBTREE_API rbtree *getArbTree(char *key,rbtree *rbt);
ARBTREE_API rbtree *getStringTree(char *key,rbtree *rbt);
ARBTREE_API double *getVector(char *key,rbtree *rbt);
ARBTREE_API void writeArbTreeToFile(rbtree *rbt,char *fname);
ARBTREE_API void writeArbTreeToStream(rbtree *rbt, rbnode *current, void *fbin,
                          stream_type st);
ARBTREE_API rbtree copyArbTree(rbtree *rbt);
ARBTREE_API void freeArbTree(rbtree *rbt,rbnode *st,int32_t v);
ARBTREE_API rbtree *readArbTreeFromFile(char *fname);
ARBTREE_API rbtree *readArbTreeFromStream(void *f, stream_type st);
ARBTREE_API void registerType(char *name, void(*freeVal)(void *),
	void *(*readVal)(void *, stream_type),
	void(*writeVal)(void *, void *, stream_type),
	void *(*copyVal)(void *));
ARBTREE_API void* getVal(char *key, rbtree *rbt, char *type);
ARBTREE_API void *readRBNodeValueString(void *f, stream_type st);
ARBTREE_API void *readRBNodeValueByteArray(void *f, stream_type st);
ARBTREE_API void *readRBNodeValueStringArray(void *f, stream_type st);
ARBTREE_API void *readRBNodeValueInteger(void *f, stream_type st);
ARBTREE_API void *readRBNodeValueDecimal(void *f, stream_type st);
ARBTREE_API void *readRBNodeValueComplex(void *f, stream_type st);
ARBTREE_API void *readRBNodeValueVector(void *f, stream_type st);
ARBTREE_API void *readRBNodeValueMatrix(void *f, stream_type st);
ARBTREE_API void freeRBNodeValueArray(void *v);
ARBTREE_API void freeRBNodeValueString(void *v);
ARBTREE_API void freeRBNodeValueArbTree(void *at);
ARBTREE_API void *readRBNodeValueArbTree(void *f, stream_type st);
ARBTREE_API void writeRBNodeValueArbTree(void *v, void *f, stream_type st);
ARBTREE_API void *copyRBNodeValueArbTree(void *v);
ARBTREE_API void freeRBNodeValueTree(void *at);
ARBTREE_API void writeRBNodeValueTree(void *v, void *f, stream_type st);
ARBTREE_API void *copyRBNodeValueTree(void *v);
ARBTREE_API void *readRBNodeValueStringTree(void *f, stream_type st);
ARBTREE_API void *copyRBNodeValueByteArray(void *v);
ARBTREE_API void *copyRBNodeValueInteger(void *v);
ARBTREE_API void *copyRBNodeValueDecimal(void *v);
ARBTREE_API void *copyRBNodeValueString(void *v);
ARBTREE_API void *copyRBNodeValueMatrix(void *v);
ARBTREE_API void *copyRBNodeValueVector(void *v);
ARBTREE_API void *copyRBNodeValueComplex(void *v);
ARBTREE_API void *copyRBNodeValueStringArray(void *v);
ARBTREE_API void writeRBNodeValueString(void *val, void *f, stream_type st);
ARBTREE_API void writeRBNodeValueByteArray(void *val, void *f, stream_type st);
ARBTREE_API void writeRBNodeValueStringArray(void *val, void *f, stream_type st);
ARBTREE_API void writeRBNodeValueInteger(void *val, void *f, stream_type st);
ARBTREE_API void writeRBNodeValueDecimal(void *val, void *f, stream_type st);
ARBTREE_API void writeRBNodeValueComplex(void *val, void *f, stream_type st);
ARBTREE_API void writeRBNodeValueVector(void *val, void *f, stream_type st);
ARBTREE_API void writeRBNodeValueMatrix(void *val, void *f, stream_type st);
ARBTREE_API void freeRBNodeValueMatrix(void *val);
ARBTREE_API void freeRBNodeValueByteArray(void *val);
ARBTREE_API void freeRBNodeValueStringArray(void *val);

extern rbtree type_map;



#endif
