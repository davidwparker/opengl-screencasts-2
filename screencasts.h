#ifndef SCREENCASTS
#define SCREENCASTS

/* standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>

/* OpenGL and friends */
#ifdef USEGLEW
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/* includes */
#include "common.h" /* common is just defines */
#include "print.h"  /* printing functions */
#include "error.h"  /* error convenience */
#include "shapes.h" /* basic shapes (cube, cone, etc) */
#include "models.h" /* complex objects */
#include "interaction.h"    /* user interactions (keyboard, mouse, etc) */
#include "initialization.h" /* initialization */
#include "draw.h"    /* draw -> draw whatever objects in the scene */
#include "display.h" /* display -> setup scene to draw */

/* GLOBALS (externs required here) */
/* Don't forget to initialize globals! */
/* window info */
extern char *windowName;
extern int windowWidth;
extern int windowHeight;

/* toggle views */
extern int toggleAxes;   /* toggle axes on and off */
extern int toggleValues; /* toggle values on and off */
extern int toggleMode;   /* projection mode */

/* view */
extern double dim;/* dimension of orthogonal box */
extern int th;    /* azimuth of view angle */
extern int ph;    /* elevation of view angle */
extern int fov;   /* field of view for perspective */
extern int asp;   /* aspect ratio */

#endif
