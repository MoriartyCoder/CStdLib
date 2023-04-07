#include "hacking.h"

// A function to display an error message and then exit
extern void fatal(char *c_message) {
  char cErrMsg[100 + 1] = ""; 

  strcpy(cErrMsg, "[!!] Fatal Error ");

  strncat(cErrMsg, c_message, 83);

  perror(cErrMsg);

  exit(-1);
}
