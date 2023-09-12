#ifndef SMILEY_H
#define SMILEY_H

#if defined(_WIN32) || defined(_WIN64)
#define SMILEY_EXPORTS 1
#ifdef SMILEY_EXPORTS
#define SMILEY_API __declspec(dllexport)
#else
#define SMILEY_API __declspec(dllimport)
#endif
#else
#define SMILEY_API
#endif

#include <arb.h>

SMILEY_API char* SmileyHash(char**,int32_t,char slow, char *extra_chars);
SMILEY_API char* SmileyHexHash(char**,int32_t,char,char* (*)(void**),char* (*)(void**));

#endif
