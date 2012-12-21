#ifndef SCREENCASTS
#define SCREENCASTS

/*  Standard headers  */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*  OpenGL and friends  */
#ifdef USEGLEW
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/*  Includes  */
#include "common.h"  /* common is just defines */
#include "display.h" /* display -> setup scene to draw */

/*  COMMON  */
#include "error.h"   /* error convenience */
#include "fatal.h"   /* fatal convenience */
#include "print.h"   /* printing functions */

/*  GLOBALS (externs required here)  */
/*  Don't forget to initialize globals!  */
extern int screencastID;

/*  Window info  */
extern char *windowName;
extern int windowWidth;
extern int windowHeight;

/*  View  */
extern double asp;/* aspect ratio */
extern double dim;/* dimension of orthogonal box */
extern int th;    /* azimuth of view angle */
extern int ph;    /* elevation of view angle */
extern int fov;   /* field of view for perspective */
extern double ecX;      /* eye center position x */
extern double ecY;      /* eye center position y */
extern double ecZ;      /* eye center position z */

#endif
