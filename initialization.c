#include "screencasts.h"

void initializeGlobals()
{
  /* WINDOW */
  windowHeight=DEF_WINDOW_HEIGHT;
  windowWidth=DEF_WINDOW_WIDTH;

  /* TOGGLE */
  toggleAxes=DEF_AXES;
  toggleParms=DEF_PARMS;

  /* PROJECTION */
  dim=DEF_DIM;
  th=DEF_TH;
  ph=DEF_PH;
  fov=DEF_FOV;
  asp=DEF_ASP;
  ecX=DEF_ECX;
  ecY=DEF_ECY;
  ecZ=DEF_ECZ;

  /* LIGHTING */
  toggleLight=DEF_LIGHT;
  distance=DEF_DISTANCE;
  ambient=DEF_AMBIENT;
  diffuse=DEF_DIFFUSE;
  emission=DEF_EMISSION;
  specular=DEF_SPECULAR;
  shininess=DEF_SHININESS;
  lightY=DEF_L_Y;
  lightPh=DEF_L_PH;

}
