#ifndef OSTDLIB_H_   /* Include guard */
#define OSTDLIB_H_

#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marcos.h"


extern void* cleanloc(const unsigned int iSize);
extern void  pfree(void **ptr);
extern void  dump(const unsigned char *c_data, const unsigned int iLen);



#endif // 
