#ifndef LISTE_H_   /* Include guard */
#define LISTE_H_

#include "ostdlib.h"

typedef struct LIST {
    unsigned int iLength;      // Amount of elements that are in the list
    unsigned int iCapacity;    // Maximal elements that the current allocated memory space can hold
    unsigned int iIncrement;   // How much is added when more space is needed
    unsigned int iDataSize;    // Size of a element
    void *p_data;
} LIST;



extern LIST *listNew(const int iDataSize, const int iCapacity, const int iIncrement);
extern unsigned int getLength(const LIST *li_list);
extern unsigned int getIncrement(const LIST *li_list);
extern unsigned int getCapacity(const LIST *li_list);
extern unsigned int getDataSize(const LIST *li_list);
extern void listPfree(LIST **li__list);
extern void listResize(LIST *li_list, const int iResize);
extern void* listGet(LIST *li_list, const int iIndex);
extern void* listGetFromBack(LIST *li_list, const int iIndex);
extern void* listGetLast(const LIST *li_list);
extern void* listGetFirst(const LIST *li_list);
extern void listClear(const LIST *li_list);
extern void* listAdd(LIST *li_list, void *p_data);


#endif // 
