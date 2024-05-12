#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>
#include "marcro.h"

typedef struct LLIST {
    struct LLIST* p_next;
    struct LLIST* p_previous;
    void *p_data;
} LLIST;

#define LL_NO_FLAG   0
#define LL_COPY_DATA 1

extern LLIST* createLinkedListNode(void *p_new_data, _UNUSED_ unsigned int iFlags);
extern void   appendNodeAtEnd(LLIST *p_llist, void *p_new_data, unsigned int iFlag);
extern void   appendNodeAtStart(LLIST *p_llist, void *p_new_data, unsigned int iFlag);
extern LLIST* getLastNode(LLIST *p_llist);
extern LLIST* getFirstNode(LLIST *p_llist);
extern void   deleteNodeWithIndex(LLIST *p_llist, int iIndex);

#endif
