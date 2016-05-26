#ifndef __OSAPI_TYPES__
#define __OSAPI_TYPES__

#if 1
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef long unsigned int uint64_t;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef long signed int int64_t;
#endif

typedef unsigned long size_t;

//TODO
typedef void *FILE;

typedef signed long ssize_t;
typedef unsigned short mode_t;

#define NULL 0

#endif
