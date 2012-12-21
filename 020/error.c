#include "screencasts.h"

/*
 * errCheck()
 * ------
 * Checks to see if there is an error and displays it if there was
 */
void errCheck(char* where)
{
  int err = glGetError();
  if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where);
}
