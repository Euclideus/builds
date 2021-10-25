#ifndef ARRAY_H
#define ARRAY_H

#include <arb.h>
#include <stdint.h>

typedef struct array{

  int32_t size;
  void **table;
  void (*free_value)(void *);
  void *(*read_value)(void *,stream_type);
  void (*write_value)(void *,void *,stream_type);
  void *(*copy_value)(void *);
}array;

array initializeArray(int32_t n, void (*freefunc)(void *),
                      void *(*readfunc)(void *,stream_type),
                      void (*writefunc)(void *, void *,stream_type),
                      void *(*copyfunc)(void *));
void freeArray(array *a, int32_t v);
void removePosition(array *a,int32_t pos);
void readArrayFromFile(array *a,char *fname);
void readArrayFromStream(array *a,void *fs,stream_type st);
void writeArrayToFile(array *a,int32_t start,int32_t end,char *fname);
void writeArrayToStream(array *a,int32_t start,int32_t end,void *fs,
                        stream_type st);
void resizeArray(array *a,int32_t n);
int32_t setElement(array *a,int32_t i,void *newval);
void *getElement(array *a,int32_t i);
array concatenateArrays(array *a1,array *a2);
array cropArray(array *a,int32_t start,int32_t end);
void freeElement(array *a,int32_t i);
array copyArray(array *a0);
void appendArray(array *a1,array *a2);

#endif
