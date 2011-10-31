#include "screencasts.h"

void errCheck(char* where)
{
  int err = glGetError();
  if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where);
}
