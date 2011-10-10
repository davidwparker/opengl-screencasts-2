#include "screencasts.h"
/*  Global descriptions on screencasts.h  */

/*  ID-used to keep screencasts separate  */
int screencastID = 0;

/*  WINDOW  */
char *windowName="OpenGL screenscasts XX: Placeholder";
int windowHeight=DEF_WINDOW_HEIGHT;
int windowWidth=DEF_WINDOW_WIDTH;

/*  TOGGLE DRAW DISPLAYS  */
int toggleAxes=DEF_AXES;
int toggleParms=DEF_PARMS;

/*  PROJECTION  */
double asp=DEF_ASP;
double dim=DEF_DIM;
int th=DEF_TH;
int ph=DEF_PH;
int fov=DEF_FOV;
double ecX=DEF_ECX;
double ecY=DEF_ECY;
double ecZ=DEF_ECZ;

/*  LIGHTING  */
int toggleLight=DEF_LIGHT;
int distance=DEF_DISTANCE;
int ambient=DEF_AMBIENT;
int diffuse=DEF_DIFFUSE;
int emission=DEF_EMISSION;
int specular=DEF_SPECULAR;
int shininess=DEF_SHININESS;
float shinyvec[1]={1};
float lightY=DEF_L_Y;
float white[]={1,1,1,1};
int lightPh=DEF_L_PH;
