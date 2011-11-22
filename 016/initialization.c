#include "screencasts.h"

void initializeGlobals(void)
{
  /* WINDOW */
  windowHeight=DEF_WINDOW_HEIGHT;
  windowWidth=DEF_WINDOW_WIDTH;

  /* TOGGLE */
  toggleAxes=DEF_AXES;
  toggleParams=DEF_PARAMS;

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

  /* TEXTURES */
  currentTexture=TEX_DEFAULT;

  /* ANIMATION */
  toggleAnimation=DEF_ANIMATE;
  cubeRotation=DEF_CUBE_ROTATION;
}

void initializeTextures(void)
{
  /*
    TEX_DEFAULT 0
    TEX_BRICK 1
    TEX_CRATE 2
    TEX_ICE 3
    TEX_FIRE 4
    TEX_EARTH 5
    TEX_WOOD 6
    TEX_VENUS 7
   */
  textures[TEX_BRICK] = loadTexBMP("txBrick14.bmp");
  textures[TEX_CRATE] = loadTexBMP("txCrate.bmp");
  textures[TEX_ICE] = loadTexBMP("txIce7.bmp");
  textures[TEX_FIRE] = loadTexBMP("txLava1.bmp");
  textures[TEX_EARTH] = loadTexBMP("txRock5.bmp");
  textures[TEX_WOOD] = loadTexBMP("txWood3.bmp");
  textures[TEX_VENUS] = loadTexBMP("txVenus.bmp");
}
