#include "liste.h"


extern LIST *listNew(const int iDataSize, const int iCapacity, const int iIncrement) {
  LIST *li_list = NULL;
  if (iDataSize <= 0 && iIncrement <= 0 && iCapacity <= 0) {
    return NULL;
  }

  li_list = calloc(1, sizeof(LIST));

  li_list->iLength    = 0;           
  li_list->iCapacity  = iCapacity;  
  li_list->iIncrement = iIncrement;  
  li_list->iDataSize  = iDataSize;  

  li_list->p_data = calloc(iCapacity, iDataSize);
  return li_list;
}

extern unsigned int getLength(const LIST *li_list) {
  return li_list != NULL ? li_list->iLength : 0;
}

extern unsigned int getIncrement(const LIST *li_list) {
  return li_list != NULL ? li_list->iIncrement : 0;
}

extern unsigned int getCapacity(const LIST *li_list) {
  return li_list != NULL ? li_list->iCapacity : 0;
}

extern unsigned int getDataSize(const LIST *li_list) {
  return li_list != NULL ? li_list->iDataSize : 0;
}

extern void listPfree(LIST **li__list) {
  if(li__list == NULL) {
    return;
  }

  free((*li__list)->p_data);
  free(*li__list);
  *li__list = NULL;
}


extern void listResize(LIST *li_list, const int iResize) {
  void          *p_oldData    = NULL;
  void          *p_newData    = NULL;
  unsigned int  iNewSize      = 0;
  int           iTransferSize = 0;

  p_oldData = li_list->p_data;
  iNewSize  = li_list->iCapacity + iResize;
  p_newData = calloc(li_list->iLength, iNewSize);

  if(iNewSize > li_list->iCapacity) {
    iTransferSize = li_list->iCapacity;
  } else {
    iTransferSize = iNewSize;
  }

  memcpy(p_newData, p_oldData, iTransferSize * li_list->iLength);
  li_list->iCapacity = iNewSize; 
  li_list->p_data    = p_newData;
  free(p_oldData);
}


extern void* listGet(LIST *li_list, const unsigned int iIndex) {
  if(li_list == NULL || li_list->iLength == 0 || iIndex >= li_list->iLength) {
    return NULL;
  }

  return (char*)li_list->p_data + (iIndex * li_list->iLength);
}

extern void* listGetFromBack(LIST *li_list, const unsigned int iIndex) {
  if(li_list == NULL || li_list->iLength == 0 || iIndex >= li_list->iLength) {
    return NULL;
  }

  return (char*)li_list->p_data + ((li_list->iLength - iIndex - 1) * li_list->iLength);
}

extern void* listGetLast(const LIST *li_list) {
  if(li_list == NULL || li_list->iLength == 0) {
    return NULL;
  }

  return (char*)li_list->p_data + (li_list->iLength - 1) * li_list->iLength;
}

extern void* listGetFirst(const LIST *li_list) {
  if(li_list == NULL || li_list->iLength == 0) {
    return NULL;
  }

  return li_list->p_data;
}

extern void listClear(const LIST *li_list) {
  if(li_list == NULL) {
    return;
  }

  memset(li_list->p_data, 0, li_list->iCapacity * li_list->iDataSize);
}

extern void* listAdd(LIST *li_list, void *p_data) {
  void *p_tmp = NULL;

  if(li_list == NULL || p_data == NULL) {
    return NULL;
  }

  if(li_list->iCapacity - li_list->iLength == 0) {
    listResize(li_list, li_list->iCapacity + li_list->iIncrement);
  }

  p_tmp = (char*)li_list->p_data + (li_list->iLength * li_list->iLength);
  memcpy(p_tmp, p_data, li_list->iLength);
  li_list->iLength++;

  return p_tmp;
}

/*
   extern void* listDelete(LIST *li_list, const int iIndex) {
   void *p_tmp = NULL;

   if(li_list == NULL || p_data == NULL) {
   return NULL;
   }

   printf("S: %d  C: %d\n", li_list->iCapacity, li_list->iLength);
   if(li_list->iCapacity - li_list->iLength == 0) {
   printf("Pre resize! %p\n", li_list->p_data); 
   listResize(li_list, li_list->iCapacity + li_list->iIncrement);
   printf("After resize! %p\n", li_list->p_data); 
   }

   p_tmp = (char*)li_list->p_data + (li_list->iLength * li_list->iLength);
   memcpy(p_tmp, p_data, li_list->iLength);
   li_list->iLength++;

   return p_tmp;
   }
 */
