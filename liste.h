#ifndef LISTE_H_   /* Include guard */
#define LISTE_H_

#include "ostdlib.h"

typedef struct LIST {
    unsigned int iLength;     // iCount is the amount of elements that are in the list.
    unsigned int iCapacity;      // iSize is the count of how often iLength has been allocated.
    unsigned int iIncrement; // iIncrement is how much is added when more space is needed.
    unsigned int iDataSize;    // iLength is the length of the element.
    void *p_data;
} LIST;



extern LIST* listNew(const int iSize, const int iIncrement, const int iLength);

extern int listIncrement(const LIST *li_list);

extern int listLength(const LIST *li_list);

extern int listSize(const LIST *li_list);

extern int listCount(const LIST *li_list);

extern void listpfree(LIST **li_list);

extern void listResize(LIST *li_list, const int iResize);

extern void* listGet(LIST *li_list, const int iIndex);

extern void* listGetFromBack(LIST *li_list, const int iIndex);

extern void* listGetLast(const LIST *li_list);

extern void* listGetFirst(const LIST *li_list);

extern void* listAdd(LIST *li_list, void *p_data);



#endif // 
