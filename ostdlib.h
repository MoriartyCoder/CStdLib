#ifndef OSTDLIB_H_   /* Include guard */
#define OSTDLIB_H_

#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================
// STANDART DEFINES
// ================
#define TRUE 1
#define FALSE 0
//#define NULL (void* 0)
#define MAXVAL(a, b) (a > b ? a : b)
#define MINVAL(a, b) (a < b ? a : b)
#define ARRAYSIZE(array) ((int)(sizeof(array) / sizeof(array[0])))

// Defines for Funktions
#define DPFREE(val) pfree((void**)&(val));
#define ZERO(val) memset(val, 0, sizeof(val));


extern void* cleanloc(const unsigned int iSize);
extern void  pfree(void **ptr);
extern void  dump(const unsigned char *c_data, const unsigned int iLen);



#endif // 