#include "liste.h"


extern LIST* listNew(const int iSize, const int iIncrement, const int iLength) {
  if(iSize > 0 && iIncrement > 0 && iLength > 0) {
    LIST *li_list = NULL;

    li_list = calloc(1, sizeof(LIST));

    li_list->iCount = 0;        // Anzahl der Elemente in der Liste
    li_list->iSize = iSize;     // Anzahl der maximal möglichen Elemente in der Liste
    li_list->iIncrement = iIncrement; // Wenn die Liste voll ist, waechst sie um diese Anzahl
    li_list->iLength = iLength; // Groesse eines Elementes

    li_list->p_data = calloc(iSize, iLength);
    return li_list;
  }

  return NULL;
}

extern int getlistIncrement(const LIST *li_list) {
  return li_list != NULL ? (int)li_list->iIncrement : 0;
}

extern int getListLength(const LIST *li_list) {
  return li_list != NULL ? (int)li_list->iLength : 0;
}

extern int getListSize(const LIST *li_list) {
  return li_list != NULL ? (int)li_list->iSize : 0;
}

extern int getListCount(const LIST *li_list) {
  return li_list != NULL ? (int)li_list->iCount : 0;
}

extern void listpfree(LIST **li_list) {
  if(li_list) {
    free((*li_list)->p_data);
    free(*li_list);
    *li_list = NULL;
  }
}


extern void listResize(LIST *li_list, const int iResize) {
  void *p_oldData    = NULL;
  void *p_newData    = NULL;
  int  iNewSize      = 0;
  int  iTransferSize = 0;

  p_oldData = li_list->p_data;
  iNewSize  = li_list->iSize + iResize;
  p_newData = calloc(li_list->iLength, iNewSize);

  if(iNewSize > li_list->iSize) {
    iTransferSize = li_list->iSize;
  } else {
    iTransferSize = iNewSize;
  }

  memcpy(p_newData, p_oldData, iTransferSize * li_list->iLength);
  li_list->iSize  = iNewSize; 
  li_list->p_data = p_newData;
  free(p_oldData);
}


extern void* listGet(LIST *li_list, const int iIndex) {
  if(li_list && iIndex >= 0 && (iIndex < li_list->iCount || li_list->iCount == 0)) {
    return (char*)li_list->p_data + (iIndex * li_list->iLength);
  }
  return NULL;
}

extern void* listGetFromBack(LIST *li_list, const int iIndex) {
  if(li_list && iIndex >= 0 && (iIndex < li_list->iCount || li_list->iCount == 0)) {
    return (char*)li_list->p_data + (li_list->iCount - iIndex - 1 * li_list->iLength);
  }
  return NULL;
}

extern void* listGetLast(const LIST *li_list) {
  if(li_list && li_list->iCount > 0) {
    return (char*)li_list->p_data + (li_list->iCount - 1) * li_list->iLength;
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
  void *p_tmp = NULL;

  if(li_list == NULL || p_data == NULL) {
    return NULL;
  }

  printf("S: %d  C: %d\n", li_list->iSize, li_list->iCount);
  if(li_list->iSize - li_list->iCount == 0) {
    printf("Pre resize! %p\n", li_list->p_data); 
    listResize(li_list, li_list->iSize + li_list->iIncrement);
    printf("After resize! %p\n", li_list->p_data); 
  }

  p_tmp = (char*)li_list->p_data + (li_list->iCount * li_list->iLength);
  memcpy(p_tmp, p_data, li_list->iLength);
  li_list->iCount++;

  return p_tmp;
}

extern void* listDelete(LIST *li_list, const int iIndex) {
  void *p_tmp = NULL;

  if(li_list == NULL || p_data == NULL) {
    return NULL;
  }

  printf("S: %d  C: %d\n", li_list->iSize, li_list->iCount);
  if(li_list->iSize - li_list->iCount == 0) {
    printf("Pre resize! %p\n", li_list->p_data); 
    listResize(li_list, li_list->iSize + li_list->iIncrement);
    printf("After resize! %p\n", li_list->p_data); 
  }

  p_tmp = (char*)li_list->p_data + (li_list->iCount * li_list->iLength);
  memcpy(p_tmp, p_data, li_list->iLength);
  li_list->iCount++;

  return p_tmp;
}
