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
#include "animate.h" /* animation functionality*/
#include "common.h"  /* common is just defines */
#include "display.h" /* display -> setup scene to draw */
#include "draw.h"    /* draw -> draw whatever objects in the scene */
#include "error.h"   /* error convenience */
#include "fatal.h"   /* fatal convenience */
#include "interaction.h"    /* user interactions (keyboard, mouse, etc) */
#include "initialization.h" /* initialization */
#include "models.h"  /* complex objects */
#include "print.h"   /* printing functions */
#include "shapes.h"  /* basic shapes (cube, cone, etc) */
#include "textures.h"/* texture functionality */

/*  Structs  */
#include "structs.h" /* common structs */

/*  GLOBALS (externs required here)  */
/*  Don't forget to initialize globals!  */
extern int screencastID;

/*  Window info  */
extern char *windowName;
extern int windowWidth;
extern int windowHeight;

/*  Toggle views  */
extern int toggleAxes;   /* toggle axes on and off */
extern int toggleParams; /* toggle parameters on and off */

/*  View  */
extern double asp;/* aspect ratio */
extern double dim;/* dimension of orthogonal box */
extern int th;    /* azimuth of view angle */
extern int ph;    /* elevation of view angle */
extern int fov;   /* field of view for perspective */
extern double ecX;      /* eye center position x */
extern double ecY;      /* eye center position y */
extern double ecZ;      /* eye center position z */

/*  Lighting  */
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

/*  Textures  */
extern unsigned int textures[7]; /* holds our textures */
extern int currentTexture;       /* current texture */

/*  Animation  */
extern int toggleAnimation;  /* toggle animation */

/*  Objects  */
extern cube_s cubes[1]; /* cube objects */

#endif
