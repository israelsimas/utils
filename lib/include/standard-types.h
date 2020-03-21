/**************************************************************************
 * standard-types.h
 *
 *  Create on: 31/08/2019
 *
 * Copyrights 2019
 *
 **************************************************************************/
#ifndef __STANDARD_TYPES_H__
#define __STANDARD_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER) && _MSC_VER < 1900
#	ifndef __cplusplus
#		define bool char
#		define true 1
#		define false 0
#	endif
#else
#	ifndef __cplusplus
#		include <stdbool.h>
#	endif
#endif

typedef unsigned char 	byte; 	// 1 byte
typedef unsigned short 	word; 	// 2 bytes
typedef unsigned long 	dword; 	// 4 bytes
typedef unsigned long 	ulong; 	// 8 bytes
typedef unsigned int	  uint; 	// 8 bytes

typedef	unsigned char * pbyte;
typedef	char *          pchar;
typedef	unsigned short *pword;
typedef	short * 		    pshort;
typedef	unsigned long *	pdword;
typedef	long *					plong;
typedef	unsigned int *	puint;
typedef	int *						pint;
typedef	void *					pvoid;
typedef	int *						pbool;

typedef unsigned char   u8;     /* unsigned int [0,255] */
typedef unsigned short  u16;    /* unsigned int [0,65535] */
typedef unsigned int    u32;    /* unsigned int [0,4294967295] */
typedef unsigned long long u64; /* unsigned int [0,1152921504606846975] */
typedef signed char     S8;     /* signed int [-128,127] */
typedef signed short    S16;    /* signed int [-32768,32767] */
typedef signed int      S32;    /* signed int [-2147483648, 2147483647] */
typedef long long       S64;    /* signed int [-576460752303423488, 576460752303423487] */

#ifndef IN
  #define IN
#endif

#ifndef OUT
  #define OUT
#endif

#ifdef __cplusplus
}
#endif

#endif 
