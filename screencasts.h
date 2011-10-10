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
extern int screencastID;

/* window info */
extern char *windowName;
extern int windowWidth;
extern int windowHeight;

/* toggle views */
extern int toggleAxes;   /* toggle axes on and off */
extern int toggleParms; /* toggle parameters on and off */

/* view */
extern double asp;/* aspect ratio */
extern double dim;/* dimension of orthogonal box */
extern int th;    /* azimuth of view angle */
extern int ph;    /* elevation of view angle */
extern int fov;   /* field of view for perspective */
extern double ecX;      /* eye center position x */
extern double ecY;      /* eye center position y */
extern double ecZ;      /* eye center position z */

/* lighting */
extern int toggleLight;   /* toggle light */
extern int distance;      /* light distance */
extern int ambient;       /* ambient intensity % */
extern int diffuse;       /* diffuse intensity % */
extern int emission;      /* emission intensity % */
extern int specular;      /* specular intensity % */
extern int shininess;     /* shininess (power of two) */
extern float shinyvec[1]; /* shininess (value) */
extern float lightY;      /* elevation of light */
extern float white[];     /* the color white */
extern int lightPh;       /* light movement */

#endif
