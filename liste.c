#include "liste.h"


extern LIST* listNew(const int iSize, const int iIncrement, const int iLength) {
    if(iSize > 0 && iIncrement > 0 && iLength > 0) {
        LIST *li_list = NULL;

        li_list = calloc(1, sizeof(LIST));

        li_list->iCount = 0;        // Anzahl der Elemente in der Liste
        li_list->iSize = iSize;     // Anzahl der Elemente
        li_list->iIncrement = iIncrement; // Wenn die Liste voll ist, waechst sie um diese Anzahl
        li_list->iLength = iLength; // Groesse eines Elementes

        li_list->p_data = calloc(iSize, iLength);
        return li_list;
    }

    return NULL;
}

extern int listIncrement(const LIST *li_list) {
    return li_list != NULL ? (int)li_list->iIncrement : 0;
}

extern int listLength(const LIST *li_list) {
    return li_list != NULL ? (int)li_list->iLength : 0;
}

extern int listSize(const LIST *li_list) {
    return li_list != NULL ? (int)li_list->iSize : 0;
}

extern int listCount(const LIST *li_list) {
    return li_list != NULL ? (int)li_list->iCount : 0;
}

extern void listpfree(LIST **li_list) {
    if(li_list) {
        free((*li_list)->p_data);
        free(*li_list);
        *li_list = NULL;
    }
}


// Doesn't work!!!
extern void listResize(LIST *li_list, const int iResize) {
  LIST *li_listNew = NULL;
  int iNewSize = 0;
  int iSize = 0;

  iNewSize = li_list->iSize + iResize;

  li_listNew = listNew(iNewSize, li_list->iIncrement, li_list->iLength);

  if(iNewSize > li_list->iSize) {
    iSize = li_list->iSize;
  } else {
    iSize = iNewSize;
  }

  memmove(li_listNew->p_data, li_list->p_data, iSize * li_list->iSize);

  listpfree(&li_list);

  // Because of this
  li_list = li_listNew;
}


extern void* listGet(LIST *li_list, const int iIndex) {
  if(li_list && iIndex >= 0 && (iIndex < li_list->iCount || li_list->iCount == 0)) {
    return li_list->p_data + (iIndex * li_list->iLength);
  }
  return NULL;
}

extern void* listGetFromBack(LIST *li_list, const int iIndex) {
    if(li_list && iIndex >= 0 && (iIndex < li_list->iCount || li_list->iCount == 0)) {
      return li_list->p_data + (li_list->iCount - iIndex - 1 * li_list->iLength);
    }
    return NULL;
}

extern void* listGetLast(const LIST *li_list) {
    if(li_list && li_list->iCount > 0) {
        return li_list->p_data + (li_list->iCount - 1) * li_list->iLength;
    }
    return NULL;
}

extern void* listGetFirst(const LIST *li_list) {
    if(li_list && li_list->iCount > 0) {
        return li_list->p_data;
    }
    return NULL;
}

extern void* listAdd(LIST *li_list, void *p_data) {
    if(li_list && p_data) {
        return NULL;
    }

    if(li_list->iSize - li_list->iCount > 0) {
        // RESIZE
    }
    
    return memcpy(li_list->p_data + ((li_list->iCount++) * li_list->iLength), p_data, li_list->iLength);
}
