#include "ostdlib.h"

extern void pfree(void **p__ptr) {
    if(p__ptr != NULL) {
        free(*p__ptr);
        *p__ptr = NULL;
    }    
}


// Our own malloc
// An error-checked malloc() wrapper function
extern void* cleanloc(const unsigned int iSize) {
  void *p_ptr = NULL;

  p_ptr = malloc(iSize);

  if(p_ptr == NULL) {
      printf("\nNicht genug Speicherplatz beim Allocieren!\n");
      // fatal("in ec_malloc() on memory allocation");
  }

  memset(p_ptr, 0, iSize);

  return (void*)p_ptr;
}


extern void dump(const unsigned char *c_data, const unsigned int iLen) {
  unsigned char cByte;
  unsigned int i = 0;
  unsigned int o = 0;

  for (i = 0; i < iLen; i++) {

    cByte = c_data[i];
    printf("%02x ", c_data[i]); // Display cByte in Hex.

    if (((i % 16) == 15) || (i == iLen - 1)) {

      for (o = 0; o < 15 - (i % 16); o++) {
        printf(" ");
      }

      printf("| ");
      
      for (o = (i - (i % 16)); o <= i; o++) { // Display printable cBytes from line.
        cByte = c_data[o];
        if ((cByte > 31) && (cByte < 127)) { // Outside printable char range
          printf("%c", cByte);
        } else {
          printf(".");
        }
      }

      printf("\n"); // End of the dump line (each line is 16 cBytes)
    }               // End if
  }                 // End for
}

