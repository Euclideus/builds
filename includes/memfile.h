#ifndef MEMFILE_H
#define MEMFILE_H

#if defined(_WIN32) || defined(_WIN64)
#define MEMFILE_EXPORTS 1
#ifdef MEMFILE_EXPORTS
#define MEMFILE_API __declspec(dllexport)
#else
#define MEMFILE_API __declspec(dllimport)
#endif
#else
#define MEMFILE_API
#endif

#include <stdint.h>
#include <stdio.h>

typedef struct MEM_FILE MEM_FILE;
typedef enum stream_type{ memory_stream,file_stream } stream_type;

MEMFILE_API void* CopyMemFile(void* v);
MEMFILE_API MEM_FILE* MemOpen(int32_t);
MEMFILE_API void MemClose(MEM_FILE*);
MEMFILE_API MEM_FILE* MemFRead(FILE* f1);
MEMFILE_API void MemWrapperClose(MEM_FILE* f);
MEMFILE_API MEM_FILE* MemWrapperOpen(unsigned char* bytes,uint32_t size);
MEMFILE_API void MemFWrite(MEM_FILE* m1,FILE* f1);
MEMFILE_API unsigned char* MemDump(MEM_FILE* f,uint32_t startpos,uint32_t endpos);
MEMFILE_API unsigned char* MemGetBufHandle(MEM_FILE* f);
MEMFILE_API uint32_t MemGetBufPos(MEM_FILE* f);
MEMFILE_API uint32_t MemGetBufSize(MEM_FILE* f);
MEMFILE_API size_t MemRead(void*,size_t,size_t,MEM_FILE*);
MEMFILE_API void MemSetRelativeBufPos(MEM_FILE* f,int32_t rpos);
MEMFILE_API void MemSetBufPos(MEM_FILE* f,uint32_t pos);
MEMFILE_API MEM_FILE* MemWrapperOpen(unsigned char* bytes,uint32_t size);
MEMFILE_API size_t MemWrite(void*,size_t,size_t,MEM_FILE*);
MEMFILE_API void* ReadMemFile(void *,stream_type);
MEMFILE_API void WriteMemFile(void* val,void* f,stream_type st);

#endif
